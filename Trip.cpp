#include "Trip.h"

Trip::~Trip()
{
	delete tripTransport;
}

Trip::Trip(const Trip& T)
	: tripDestination(T.tripDestination)
{
	tripTransport = T.tripTransport->Clone();
}

Trip& Trip::operator=(const Trip& T)
{
	if (this != &T)
	{
		delete tripTransport;
		tripTransport = T.tripTransport->Clone();
	}
	else
	{

	}
	tripDestination = T.tripDestination;
	return *this;
}

// Trip is owner of transport
Trip::Trip(Transport* transport, std::string destination)
	: tripTransport(transport), tripDestination(destination)
{
}

const Transport* Trip::GetTransport() const
{
	return tripTransport;
}

std::istream& operator>>(std::istream& is, Trip& T)
{
	T.ReadFrom(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Trip& T)
{
	T.PrintTo(os);
	return os;
}
