#include "Auto.h"

Auto::~Auto()
{
}

Auto::Auto(std::string& brand, double litersPer100Km)
	: autoBrand(brand), autoLitersPer100Km(litersPer100Km)
{
}

Auto::Auto(const Auto& A)
	:autoBrand(A.autoBrand), autoLitersPer100Km(A.autoLitersPer100Km)
{
}

Auto& Auto::operator=(const Auto& A)
{
	if (this != &A)
	{
		autoBrand = A.autoBrand;
		autoLitersPer100Km = A.autoLitersPer100Km;
	}
	return *this;
}

Transport* Auto::Clone() const
{
	return new Auto(*this);
}

void Auto::PrintTo(std::ostream& os) const
{
	os << "Auto " << autoBrand << " requires " << autoLitersPer100Km <<
		" liters per 100km ";
}

void Auto::ReadFrom(std::istream& is)
{
	is >> autoBrand >> autoLitersPer100Km;
}

double Auto::CostOfUse() const
{
	return AutoSpace::FUEL_PRICE * 100;
}

double Auto::AutoActualCostOfUse(double distance) const
{
	return AutoSpace::FUEL_PRICE * distance;
}

std::string Auto::GetBrand() const
{
	return autoBrand;
}
