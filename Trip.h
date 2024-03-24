#pragma once
#include "Transport.h"
#include "Auto.h"
class Trip
{
protected:
	Transport* tripTransport = nullptr;
	std::string tripDestination = "";
public:
	virtual ~Trip();
	Trip() = default;
	Trip(const Trip& T);
	Trip& operator=(const Trip& T);
	Trip(Transport* transport, std::string destination);

	virtual double CalculateTripCost() const abstract;
	const Transport* GetTransport() const;
	virtual void PrintTo(std::ostream& os = std::cout) const abstract;
	virtual void ReadFrom(std::istream& is = std::cin) abstract;
	virtual Trip* Clone() const abstract;
};

std::istream& operator>>(std::istream& is, Trip& T);
std::ostream& operator<<(std::ostream& os, const Trip& T);