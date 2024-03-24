#include "Plane.h"

Plane::~Plane()
{
}

Plane::Plane(std::string& airCompany, double pricePerTicket)
	: planeAirCompany(airCompany), planePricePerTicket(pricePerTicket)
{
}

Plane::Plane(const Plane& P)
	: planeAirCompany(P.planeAirCompany), planePricePerTicket(P.planePricePerTicket)
{
}

Plane& Plane::operator=(const Plane& P)
{
	if (this != &P)
	{
		planeAirCompany = P.planeAirCompany;
		planePricePerTicket = P.planePricePerTicket;
	}
	return *this;
}

Transport* Plane::Clone() const
{
	return new Plane(*this);
}

void Plane::PrintTo(std::ostream& os) const
{
	os << "Plane " << planeAirCompany << " price per ticker " << planePricePerTicket;
}

void Plane::ReadFrom(std::istream& is)
{
	is >> planeAirCompany >> planePricePerTicket;
}

double Plane::CostOfUse() const
{
	return planePricePerTicket;
}

double Plane::PlaneActualCostOfUse(int tickets) const
{
	return planePricePerTicket * tickets;
}
