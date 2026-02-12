#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *p)
{
	return reinterpret_cast<uintptr_t>(p);
}

Data *Serializer::deserialize(uintptr_t value)
{
	return reinterpret_cast<Data*>(value);
}
