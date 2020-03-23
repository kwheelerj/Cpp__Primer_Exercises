#include <fstream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <sstream>
#include <string>


class QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	// map each word to the set of lines in which that word appears (alot of work!)
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			std::shared_ptr<std::set<line_no>> &lines = wm[word];
			if (!lines)	// first time we see word
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
				std::shared_ptr<std::set<TextQuery::line_no>> p,
				std::shared_ptr<std::vector<std::string>> f) :
			sought(s), lines(p), file(f) {}
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string &sought) const
{
	// return a pointer to this set if not found
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times" << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}