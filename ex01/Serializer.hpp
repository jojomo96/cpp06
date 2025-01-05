
#pragma once
#include <cstdint>

struct Data {
	char data[8];
};

class Serializer {
public:
	Serializer() = delete;
	~Serializer() = delete;
	Serializer(const Serializer &other) = delete;
	Serializer &operator=(const Serializer &other) = delete;

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
