#pragma once
#include "Trip.h"
#include "AutoTrip.h"
#include "PlaneTrip.h"
#include <exception>
#include <iostream>

class TripContainer
{
private:
	Trip** container;
	unsigned size;
public:
	~TripContainer();
	TripContainer(unsigned size = 10);
	TripContainer(const TripContainer& TC) = delete;
	// Trip& because if we want to change Trip in container it will be acording to Trip::operator=
	Trip& operator[](unsigned index);
	const Trip& operator[](unsigned index) const;

	void AllocateMemory();
	void ReadFromFile(std::istream& is);
	void PrintAll(std::ostream& os = std::cout);
	double PriceOfAllTrips() const;
	const Trip& FindMax(bool(*func)(const Trip&)) const;
	TripContainer* Filter(bool(*func)(const Trip&)) const;
	unsigned GetSize() const;
	bool IsValid(unsigned index) const;
};