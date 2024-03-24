#include "TripContainer.h"

TripContainer::~TripContainer()
{
    for (unsigned i = 0; i < size; ++i)
    {
        delete container[i];
    }
    delete[] container;
}

TripContainer::TripContainer(unsigned size)
    : container(new Trip* [size]), size(size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        container[i] = nullptr;
    }
}

Trip& TripContainer::operator[](unsigned index)
{
    if (index >= size)
    {
        throw(std::out_of_range{ "Container index out of range" });
    }
    return *container[index];
}

const Trip& TripContainer::operator[](unsigned index) const
{
    if (index >= size)
    {
        throw(std::out_of_range{ "Container index out of range" });
    }
    return *container[index];
}

// to simplify computations I copy only pointers
void TripContainer::AllocateMemory()
{
    unsigned newSize = size * 2;
    Trip** newContainer = new Trip * [newSize];
    // I use int same int in two differend for loops
    int i = 0;
    for (; i < size; ++i)
    {
        newContainer[i] = container[i];
    }
    for (; i < newSize; ++i)
    {
        newContainer[i] = nullptr;
    }
    delete container;
    container = newContainer;
    size = newSize;
    std::cout << "Memory allocated (" << newSize << ")\n";
}

void TripContainer::ReadFromFile(std::istream& is)
{
    unsigned index = 0;
    while (not is.eof())
    {
        try
        {
            if (index >= size)
            {
                AllocateMemory();
            }
            std::string type;
            is >> type;
            if (type == "AutoTrip")
            {
                container[index] = new AutoTrip();
                is >> *container[index];
                ++index;
            }
            else if (type == "PlaneTrip")
            {
                container[index] = new PlaneTrip();
                is >> *container[index];
                ++index;
            }
            else
            {
                while (is.get() != '\n')
                {
                    continue;
                }
            }
        }
        catch (std::out_of_range)
        {
            std::cout << "Container size changed\n";
        }
    }
}

void TripContainer::PrintAll(std::ostream& os)
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (container[i] != nullptr)
        {
            os << *container[i] << std::endl;
        }
    }
}

double TripContainer::PriceOfAllTrips() const
{
    double result = 0;
    for (unsigned i = 0; i < size; ++i)
    {
        if (container[i] != nullptr)
        {
            result += container[i]->CalculateTripCost();
        }
    }
    return result;
}

const Trip& TripContainer::FindMax(bool(*func)(const Trip&)) const
{
    unsigned maxIndex = -1;
    // find first in container
    for (unsigned i = 0; i < size; ++i)
    {
        if ((container[i] != nullptr) && func(*container[i]))
        {
            maxIndex = i;
            break;
        }
    }
    if (maxIndex == -1)
    {
        throw(std::runtime_error("Container is empty"));
    }
    for (unsigned i = maxIndex + 1; i < size; ++i)
    {
        if ((container[i] != nullptr) && func(*container[i]))
        {
            if (container[maxIndex]->CalculateTripCost() < container[i]->CalculateTripCost())
            {
                maxIndex = i;
            }
        }
    }
    return (*this)[maxIndex];
}

TripContainer* TripContainer::Filter(bool(*func)(const Trip&)) const
{
    TripContainer* result = new TripContainer();
    unsigned index = 0;
    for (unsigned i = 0; i < size; ++i)
    {
        if (container[i] != nullptr && func(*container[i]))
        {
            if (index > result->size)
            {
                result->AllocateMemory();
            }
            result->container[index++] = container[i]->Clone();
        }
    }
    return result;
}

unsigned TripContainer::GetSize() const
{
    return size;
}

bool TripContainer::IsValid(unsigned index) const
{
    if (index > size)
    {
        throw(std::out_of_range("Container index out of range"));
    }
    return container[index] != nullptr;
}
