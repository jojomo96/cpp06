
#pragma once

class Base {
public:
	virtual ~Base() = default;

	static Base *generate();

	static void identify(Base* p);

	static void identify(Base& p);
};


class A final : public Base {
};

class B final : public Base {
};

class C final : public Base {
};
