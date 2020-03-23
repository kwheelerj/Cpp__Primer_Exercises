#ifndef SALES_DATA_H
#define SALES_DATA_H

struct Sales_data
{
	// constructors
	Sales_data() = default;	/* c++11 standard */
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);	/* Defined outside the class (struct) body */
	// Sales_data(std::istream &is)
	// {
	// 	read(is, *this);
	// }
	// new members: operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine (const Sales_data&);
	double avg_price() const;
	// data members are unchanged
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif