#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

class Sales_data
{
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
	// Sales_data() = default;
	/* with the default argument, this becomes the default constructor */
	Sales_data(std::istream &is = std::cin) { read(is, *this); }

	std::string isbn() const { return bookNo; }

private:
	double avg_price() const { return units_sold ? revenue / units_sold : 0; }	// implicitly inline

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

#endif