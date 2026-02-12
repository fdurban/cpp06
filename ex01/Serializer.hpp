#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer();
	public:
		static	uintptr_t serialize(Data *p);
		static	Data* deserialize(uintptr_t);
};

