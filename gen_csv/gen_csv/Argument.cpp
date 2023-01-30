#include "Argument.h"


Argument::Argument()
{
}

Argument::Argument(const std::string& row,
    const std::string& col, 
    const std::string& len, 
    const std::string& enc, 
    const std::string& out)
{
    SetRow(row);
    SetCol(col);
    SetLength(len);
    SetEnc(enc);
    SetOut(out);
}

Argument::~Argument()
{
}

int Argument::GetRow() const
{
	return _row;
}

void Argument::SetRow(const std::string& row)
{
    try {
        _row = std::stoi(row);
    }
    catch (const std::exception& ex) {
        std::cout << "Неверно введены данные для поля row:\t" << row << std::endl;
        exit(EXIT_FAILURE);
    }
}

int Argument::GetCol() const
{
    return _col;
}

void Argument::SetCol(const std::string& col)
{
    try {
        _col = std::stoi(col);
    }
    catch (const std::exception& ex) {
        std::cout << "Неверно введены данные для поля column:\t" << col << std::endl;
        exit(EXIT_FAILURE);
    }
}

int Argument::GetLength() const
{
    return _len;
}

void Argument::SetLength(const std::string& len)
{
    try {
        _len = std::stoi(len);
        if (_len < 0)
        {
            std::cout << "Длина строки должна быть больше нуля:\t" << len << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    catch (const std::exception& ex) {
        std::cout << "Неверный параметр для длины:\t" << len << std::endl;
        exit(EXIT_FAILURE);
    }
}

const std::string& Argument::GetEnc() const
{
    return _enc;
}

void Argument::SetEnc(const std::string& enc)
{
    // можно расширить список возможных кодировок
    std::string encryptions = "UTF-8";
    if(enc == encryptions)
    {
        _enc = enc;
    }
    else
    {
        std::cout << "Неверный выбор кодировки:\t" << enc << std::endl;
        exit(EXIT_FAILURE);
    }
}

const std::string& Argument::GetOut() const
{
    return _out;
}

void Argument::SetOut(const std::string& out)
{
    std::ofstream os(out);
    if(os.is_open())
        _out = out;
    else {
        std::cout << "Неверный путь к файлу:\t" << out << std::endl;
        exit(EXIT_FAILURE);
    }
    os.close();
}
