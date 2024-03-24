#include "AutoTrip.h"

AutoTrip::~AutoTrip()
{
}

AutoTrip::AutoTrip(const AutoTrip& A)
	: Trip(A.GetTransport()->Clone(), A.tripDestination), distance(A.distance)
{
}

AutoTrip::AutoTrip(std::string brand, double litersPer100Km, std::string destination, double d)
	: Trip(new Auto(brand, litersPer100Km), destination), distance(d)
{
}

AutoTrip::AutoTrip(Transport* T, std::string destination, double d)
	: Trip(T, destination), distance(d)
{
}

AutoTrip& AutoTrip::operator=(const AutoTrip& AT)
{
	if (this == &AT)
	{
		
	}
	else
	{
		delete tripTransport;
		tripTransport = AT.GetTransport()->Clone();
		tripDestination = AT.tripDestination;
		distance = AT.distance;
	}
	return *this;
}

double AutoTrip::CalculateTripCost() const
{
	return dynamic_cast<Auto*>(tripTransport)->AutoActualCostOfUse(distance);
}

void AutoTrip::PrintTo(std::ostream& os) const
{
	os << "Auto trip destination: " << tripDestination << " brand: " << dynamic_cast<Auto*>(tripTransport)->GetBrand() << " price: "
		<< CalculateTripCost();
}

void AutoTrip::ReadFrom(std::istream& is)
{
	std::string brand;
	double fuel;
	is >> brand >> fuel;
	tripTransport = new Auto(brand, fuel);
	is >> tripDestination >> distance;
}

Trip* AutoTrip::Clone() const
{
	return new AutoTrip{ *this };
}
