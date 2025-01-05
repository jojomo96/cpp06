
#include "Serializer.hpp"
#include <iostream>

int main() {
	// Create a Data object
	Data data{};
	std::strcpy(data.data, "test123");
	std::cout << "Original data: " << data.data << std::endl;

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

	std::cout << std::endl;
	// Test with different data
	Data data2{};
	std::strcpy(data2.data, "data456");
	std::cout << "Original data2: " << data2.data << std::endl;

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


	// testcase 3 is broken on purpose
	std::cout << std::endl;
	// Create a Data object on the heap
	const auto data3 = new Data{};
	std::strcpy(data3->data, "test123");
	std::cout << "Original data: " << data3->data << std::endl;

	// Serialize the Data object
	const uintptr_t raw3 = Serializer::serialize(data3);
	std::cout << "Serialized data: " << raw3 << std::endl;

	// Delete the original Data object to simulate deallocation
	delete data3;

	// Override the raw pointer to simulate corruption
	uintptr_t corruptedRaw = raw3 + 1;

	// Deserialize the corrupted raw data back to a Data object
	const Data* deserializedData3 = Serializer::deserialize(corruptedRaw);
	std::cout << "Deserialized data: " << deserializedData3->data << std::endl;

	// Check if the deserialized data is the same as the original
	if (deserializedData3 == data3) {
		std::cout << "Deserialization successful, pointers match." << std::endl;
	} else {
		std::cout << "Deserialization failed, pointers do not match." << std::endl;
	}


	return 0;
}
