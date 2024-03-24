#include "Transport.h"

Transport::~Transport()
{
}

std::istream& operator>>(std::istream& is, Transport& T)
{
	T.ReadFrom(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Transport& T)
{
	T.PrintTo(os);
	return os;
}
