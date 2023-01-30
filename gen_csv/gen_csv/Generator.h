#pragma once
#include "Argument.h"
#include <vector>


class Generator
{
public:
	Generator();
	~Generator();

	void FillFile(const Argument&);
private:
	void GetData(std::vector<std::string>& data, const std::string& filepath, int sizeLimit);
};

