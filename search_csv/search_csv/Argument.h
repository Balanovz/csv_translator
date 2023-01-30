#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class Argument
{
public:
	Argument();
	~Argument();

	// геттеры и сеттеры для полей аргументов

	const std::string& GetCol() const;
	void SetCol(const std::string&);

	const std::string& GetEnc() const;
	void SetEnc(const std::string&);

	const std::string& GetOut() const;
	void SetOut(const std::string&);

	const std::string& GetIn() const;
	void SetIn(const std::string&);

	const std::string& GetExp() const;
	void SetExp(const std::string&);

	const std::string& GetType()const;

private:
	std::string _col;
	std::string _enc;
	std::string _in;
	std::string _out;
	std::string _exp;
	std::string _type;
};

