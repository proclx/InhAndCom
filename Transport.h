#pragma once
#include <iostream>
#include <string>

class Transport
{
public:
	virtual ~Transport();

	virtual Transport* Clone() const abstract;
	virtual void PrintTo(std::ostream& os = std::cout) const abstract;
	virtual void ReadFrom(std::istream& is = std::cin) abstract;
	// CostOfUse for auto - fuel price per 100km,
	// for plane - price of one ticket
	virtual double CostOfUse() const abstract;
};

std::istream& operator>>(std::istream& is, Transport& T);
std::ostream& operator<<(std::ostream& os, const Transport& T);