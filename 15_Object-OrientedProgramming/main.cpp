#include <iostream>


class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {}	
	std::string isbn() const { return bookNo; }
	
	virtual double net_price(std::size_t n) const
		{ return n * price; }
	virtual ~Quote() = default;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	double net_price(std::size_t n) const override;
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc) {}



double print_total(std::ostream &os, const Quote &item, size_t n)
{
	// depending on the type of Quote (could be Bulk_quote), call corresponding definition
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}