
#include "Serializer.hpp"
#include <iostream>

int main() {
	// Create a Data object
	Data data{};
	std::strcpy(data.data, "test123");

	// Serialize the Data object
	const uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data: " << raw << std::endl;

	// Deserialize the raw data back to a Data object
	const Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data: " << deserializedData->data << std::endl;

	// Check if the deserialized data is the same as the original
	if (deserializedData == &data) {
		std::cout << "Deserialization successful, pointers match." << std::endl;
	} else {
		std::cout << "Deserialization failed, pointers do not match." << std::endl;
	}

	// Test with different data
	Data data2{};
	std::strcpy(data2.data, "data456");

	// Serialize the new Data object
	const uintptr_t raw2 = Serializer::serialize(&data2);
	std::cout << "Serialized data2: " << raw2 << std::endl;

	// Deserialize the raw data back to a Data object
	const Data* deserializedData2 = Serializer::deserialize(raw2);
	std::cout << "Deserialized data2: " << deserializedData2->data << std::endl;

	// Check if the deserialized data is the same as the original
	if (deserializedData2 == &data2) {
		std::cout << "Deserialization successful, pointers match." << std::endl;
	} else {
		std::cout << "Deserialization failed, pointers do not match." << std::endl;
	}

	return 0;
}
