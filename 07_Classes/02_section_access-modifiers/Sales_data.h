#ifndef SALES_DATA_H
#define SALES_DATA_H

class Sales_data
{
// friend declarations for nonmember Sales_data operations
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
/* Note: friends are not members of the class - must be re-declared outside as well */

public:
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(std::istream&);

	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);

private:
	double avg_price() const { return units_sold ? revenue / units_sold : 0; }	// implicitly inline

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// declarations for nonmember parts of the Sales_data interface:
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

#endif