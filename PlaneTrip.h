#pragma once
#include "Trip.h"
#include "Plane.h"

class PlaneTrip 
	: public Trip
{
private:
	unsigned familyMembers = 0;
public:
	virtual ~PlaneTrip();
	PlaneTrip() = default;
	PlaneTrip(const PlaneTrip& P);
	PlaneTrip(std::string airCompany, double ticketPrice, std::string destination, double family);
	PlaneTrip(Transport* T, std::string destination, double family);
	PlaneTrip& operator=(const PlaneTrip& PT);

	virtual double CalculateTripCost() const override;
	virtual void PrintTo(std::ostream& os = std::cout) const override;
	virtual void ReadFrom(std::istream& is = std::cin) override;
	virtual Trip* Clone() const override;
	unsigned GetFamilyMembers() const;
};

