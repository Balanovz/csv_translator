#pragma once
#include <iostream>
#include <string>
#include <fstream>


class Argument
{
public:
	Argument();
	Argument(const std::string& row, 
		const std::string& col, 
		const std::string& len, 
		const std::string& _enc, 
		const std::string& _out);
	~Argument();

	// геттеры и сеттеры для полей аргументов
	int GetRow() const;
	void SetRow(const std::string&);

	int GetCol() const;
	void SetCol(const std::string&);

	int GetLength() const;
	void SetLength(const std::string&);

	const std::string& GetEnc() const;
	void SetEnc(const std::string&);

	const std::string& GetOut() const;
	void SetOut(const std::string&);

private:
	int _row;
	int _col;
	int _len;
	std::string _enc;
	std::string _out;
};

