#include <string>
#include <set>

class Folder;

class Message
{
friend class Folder;
friend void swap(Message&, Message&);

public:
	// default ctor implicitly initializes folders to the empty set
	explicit Message(const std::string &str = "") : contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder
{
public:
	explicit Folder(const std::string &str) : name(str) {}
	Folder(const Folder&) = delete;
	Folder& operator=(const Folder&) = delete;

	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::string name;
	std::set<Message*> messages;

};

void Message::save(Folder &f)
{
	folders.insert(&f);		// add given Folder* &f to set of Folders this Message belongs to
	f.addMsg(this);			// add this Message to Folder f's set of Messages
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

/* This is our first example of a copy control not allocating resources - bookkeeping */
Message::Message(const Message &orig) :
	contents(orig.contents),
	folders(orig.folders)
{
	add_to_Folders(orig);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
	folders.clear();
}

Message::~Message()
{
	remove_from_Folders();
}

/* Recall, copy-assignment (usually) must do both destructor and copy work (in that order) */
Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
/* Had we called remove_from_Folders after callsing add_to_Folders, we would have removed
this message from all of its corresponding Folders. */


void swap(Message &lhs, Message &rhs)
{
	using std::swap;	// not strictly needed in this case, but a good habit
	// remove pointers to each Message from their (original) respective Folders
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	
	// swap the contents and Folder pointer sets
	swap(lhs.folders, rhs.folders);			// use swap(set&, set&);
	swap(lhs.contents, rhs.contents);		// use swap(string&, string&);

	// add pointers to each Message to their (new) respective Folders
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}