#include <fstream>
#include "Trip.h"
#include "TripContainer.h"

bool IsAutoTrip(const Trip& T)
{
	return (std::string(typeid(T).name()) == "class AutoTrip");
}

bool IsPlaneTrip(const Trip& T)
{
	return (std::string(typeid(T).name()) == "class PlaneTrip");
}

const Transport* AutoWithHighestCostOfUse(const TripContainer& T);

unsigned FamilyMembersInTheCheapestTrip(TripContainer& T);

int main()
{
	TripContainer TC;
	std::ifstream fin("TripData.txt");
	if (fin.is_open() && fin.good())
	{
		TC.ReadFromFile(fin);
	}
	fin.close();
	TC.PrintAll();

	std::cout << "All trips price: " << TC.PriceOfAllTrips() << std::endl;
	std::cout << "Max AutoTrip: " << TC.FindMax(&IsAutoTrip) << std::endl;
	std::cout << "Max PlaneTrip: " << TC.FindMax(&IsPlaneTrip) << std::endl;

	std::cout << "   Collection of AutoTrips created based on prev collection:\n";
	TripContainer* onlyAutoTrips = TC.Filter(&IsAutoTrip);
	onlyAutoTrips->PrintAll();

	std::cout << "   Collection of PlaneTrips created based on prev collection:\n";
	TripContainer* onlyPlaneTrips = TC.Filter(&IsPlaneTrip);
	onlyPlaneTrips->PrintAll();

	std::cout << "Auto with the highest cost of use: " << *AutoWithHighestCostOfUse(*onlyAutoTrips) << std::endl;
	std::cout << "Family members in the cheapest PlaneTrip: " << FamilyMembersInTheCheapestTrip(*onlyPlaneTrips) << std::endl;

	// onlyAutoTrips and onlyPlaneTrips are deep copy, and are located in heap, so we need to free memory
	onlyAutoTrips->~TripContainer();
	onlyPlaneTrips->~TripContainer();
	return 0;
}

unsigned FamilyMembersInTheCheapestTrip(TripContainer& T)
{
	unsigned minIndex = -1;
	for (unsigned i = 0; i < T.GetSize(); ++i)
	{
		// is not nullptr and definitely is AutoTrip
		if (T.IsValid(i) && IsPlaneTrip(T[i]))
		{
			minIndex = i;
			break;
		}
	}
	if (minIndex == -1)
	{
		throw(std::runtime_error("Container has no PlaneTrips"));
	}
	for (unsigned i = minIndex + 1; i < T.GetSize(); ++i)
	{
		if (T.IsValid(i) && IsPlaneTrip(T[i]))
		{
			if (T[i].CalculateTripCost() < T[minIndex].CalculateTripCost())
			{
				minIndex = i;
			}
		}
	}
	return dynamic_cast<PlaneTrip*>(&T[minIndex])->GetFamilyMembers();
}

const Transport* AutoWithHighestCostOfUse(const TripContainer& T)
{
	unsigned maxIndex = -1;
	for (unsigned i = 0; i < T.GetSize(); ++i)
	{
		// is not nullptr and definitely is AutoTrip
		if (T.IsValid(i) && IsAutoTrip(T[i]))
		{
			maxIndex = i;
			break;
		}
	}
	if (maxIndex == -1)
	{
		throw(std::runtime_error("Container has no AutoTrips"));
	}
	for (unsigned i = maxIndex + 1; i < T.GetSize(); ++i)
	{
		if (T.IsValid(i) && IsAutoTrip(T[i]))
		{
			if (T[i].GetTransport()->CostOfUse() > T[maxIndex].GetTransport()->CostOfUse())
			{
				maxIndex = i;
			}
		}
	}
	return T[maxIndex].GetTransport();
}