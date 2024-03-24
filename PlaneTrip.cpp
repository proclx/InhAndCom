#include "PlaneTrip.h"

PlaneTrip::~PlaneTrip()
{
}

PlaneTrip::PlaneTrip(const PlaneTrip& P)
	: Trip(P.tripTransport->Clone(), P.tripDestination), familyMembers(P.familyMembers)
{
}

PlaneTrip::PlaneTrip(std::string airCompany, double ticketPrice, std::string destination, double family)
	: Trip(new Plane(airCompany, ticketPrice), destination), familyMembers(family)
{
}

PlaneTrip::PlaneTrip(Transport* T, std::string destination, double family)
	:Trip(T, destination), familyMembers(family)
{
}

PlaneTrip& PlaneTrip::operator=(const PlaneTrip& PT)
{
	if (this == &PT)
	{

	}
	else
	{
		delete tripTransport;
		tripTransport = PT.GetTransport()->Clone();
		tripDestination = PT.tripDestination;
		familyMembers = PT.familyMembers;
	}
	return *this;
}

double PlaneTrip::CalculateTripCost() const
{
	return dynamic_cast<Plane*>(tripTransport)->PlaneActualCostOfUse(familyMembers);
}

void PlaneTrip::PrintTo(std::ostream& os) const
{
	os << "Plane trip destination: " << tripDestination << " price: " << CalculateTripCost();
}

void PlaneTrip::ReadFrom(std::istream& is)
{
	std::string airCompany;
	unsigned tickets;
	is >> airCompany >> tickets;
	delete tripTransport;
	tripTransport = new Plane(airCompany, tickets);
	is >> tripDestination >> familyMembers;
}

Trip* PlaneTrip::Clone() const
{
	return new PlaneTrip{ *this };
}

unsigned PlaneTrip::GetFamilyMembers() const
{
	return familyMembers;
}
