#include "Serializer.hpp"

int main()
{
	Data information;
	
	information.id = 42;
	information.name = "name";
	information.value = 3.14356;

	Data	*pointerAddress = &information;
	std::cout<<"Original data: "<<std::endl;
	std::cout<<"Address: "<<&information<<std::endl;
	std::cout<<"ID: "<<information.id<<std::endl;
	std::cout<<"Name: "<<information.name<<std::endl;
	std::cout<<"Value: "<<information.value<<std::endl;

	uintptr_t serializedata = Serializer::serialize(&information);

	std::cout<<"Original pointer: "<<pointerAddress<<std::endl;
	std::cout<<"Serialized value: "<<std::hex<<serializedata<<std::endl;

	Data *finalPointer = Serializer::deserialize(serializedata);

	std::cout<<"Deserialized data: "<<std::endl;
	std::cout<<"Address: "<<&finalPointer<<std::endl;
	std::cout<<"ID: "<<finalPointer->id<<std::endl;
	std::cout<<"Name: "<<finalPointer->name<<std::endl;
	std::cout<<"Value: "<<finalPointer->value<<std::endl;

	if (finalPointer == pointerAddress)
		std::cout<<"Success!"<<std::endl;
	else
		std::cout<<"Error!"<<std::endl;
	if (finalPointer->id == information.id && finalPointer->name == information.name && finalPointer->value == information.value)
{
	std::cout<<"All values are the same. Congrats!"<<std::endl;
}
else
{
	std::cout<<"Error. Check the values again and make sure they are the same"<<std::endl;
}
}
