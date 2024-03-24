#pragma once
#include "Transport.h"

class Plane 
    : public Transport
{
private:
    std::string planeAirCompany = "";
    double planePricePerTicket = 0;
public:
	virtual ~Plane();
	Plane() = default;
	Plane(std::string& airCompany, double pricePerTicket);
	Plane(const Plane& P);
	Plane& operator=(const Plane& P);

	virtual Transport* Clone() const override;
	virtual void PrintTo(std::ostream& os = std::cout) const override;
	virtual void ReadFrom(std::istream& is = std::cin) override;
	virtual double CostOfUse() const override;
	double PlaneActualCostOfUse(int tickets) const;
};