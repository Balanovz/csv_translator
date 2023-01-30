#pragma once
#include "Argument.h"
#include <sstream>


class Finder
{
public:
	Finder();
	~Finder();

	void FindTo(const Argument&);
private:
	std::vector<std::string> Split(const std::string& str, char delim);
};

