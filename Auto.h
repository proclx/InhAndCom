#pragma once
#include "Transport.h"

namespace AutoSpace
{
	const double FUEL_PRICE = 42.45;
}

class Auto 
	: public Transport
{
private:
	std::string autoBrand = "";
	double autoLitersPer100Km = 0;
public:
	virtual ~Auto();
	Auto() = default;
	Auto(std::string& brand, double litersPer100Km);
	Auto(const Auto& A);
	Auto& operator=(const Auto& A);

	virtual Transport* Clone() const override;
	virtual void PrintTo(std::ostream& os = std::cout) const override;
	virtual void ReadFrom(std::istream& is = std::cin) override;
	// price per 100km
	virtual double CostOfUse() const override;
	// price for custom distance
	double AutoActualCostOfUse(double distance) const;
	std::string GetBrand() const;
};

