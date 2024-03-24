#pragma once
#include "Trip.h"
class AutoTrip 
	: public Trip
{
private:
	double distance = 0;
public:
	virtual ~AutoTrip();
	AutoTrip() = default;
	AutoTrip(const AutoTrip& A);
	AutoTrip(std::string brand, double litersPer100Km, std::string destination, double d);
	AutoTrip(Transport* T, std::string destination, double d);
	AutoTrip& operator=(const AutoTrip& AT);

	virtual double CalculateTripCost() const override;
	virtual void PrintTo(std::ostream& os = std::cout) const override;
	virtual void ReadFrom(std::istream& is = std::cin) override;
	virtual Trip* Clone() const override;
};

