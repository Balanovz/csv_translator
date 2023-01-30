#include "Argument.h"

Argument::Argument()
{
}

Argument::~Argument()
{
}

const std::string& Argument::GetCol() const
{
    return _col;
}

void Argument::SetCol(const std::string& col)
{
    std::vector<std::string> columnNames = { "ФИО", "Дата_рождения",
    "Кол-во_проектов", "Рейтинг", "Комментарий" };
    bool contains = false;

    for (auto name : columnNames)
        if (name == col) 
        {
            contains = true;
            if (col == "ФИО" || col == "Комментарий")
                _type = "String";
            else if (col == "Дата_рождения")
                _type = "Date";
            else if (col == "Кол-во_проектов")
                _type = "Integer";
            else
                _type = "Float";
            break;
        }
    if (contains)
        _col = col;
    else 
    {
        std::cout << "Неверное название столбца:\t" << col << std::endl;
        exit(EXIT_FAILURE);
    }
}

const std::string& Argument::GetEnc() const
{
    return _enc;
}

void Argument::SetEnc(const std::string& enc)
{
    if (enc != "UTF-8")
    {
        std::cout << "Неверная кодировка:\t" << enc << std::endl;
        exit(EXIT_FAILURE);
    }
    _enc = enc;
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
    else
    {
        std::cout << "Неверный путь:\t" << out << std::endl;
        exit(EXIT_FAILURE);
    }
    os.close();
}

const std::string& Argument::GetIn() const
{
    return _in;
}

void Argument::SetIn(const std::string& in)
{
    std::ifstream is(in);
    if (is.is_open())
        _in = in;
    else
    {
        std::cout << "Неверный путь:\t" << in << std::endl;
        exit(EXIT_FAILURE);
    }
    is.close();
}

const std::string& Argument::GetExp() const
{
    return _exp;
}

void Argument::SetExp(const std::string& exp)
{
    if (_type == "String"){
        _exp = exp;
    }
    else if (_type == "Date"){
        try 
        {
            int d1 = exp[0] - '0';
            int d2 = exp[1] - '0';
            int m1 = exp[3] - '0';
            int m2 = exp[4] - '0';
            int y1 = exp[6] - '0';
            int y2 = exp[7] - '0';
            int y3 = exp[8] - '0';
            int y4 = exp[9] - '0';

            if (d1 * 10 + d2 <= 0 || d1 * 10 + d2 > 31)
            {
                std::cout << "Неверный день у даты:\t" << exp << std::endl;
                exit(EXIT_FAILURE);
            }
            if (m1 * 10 + m2 <= 0 || m1 * 10 + m2 > 12)
            {
                std::cout << "Неверный месяц у даты:\t" << exp << std::endl;
                exit(EXIT_FAILURE);
            }
            if (y1 * 1000 + y2*100 + y3*10 + y4 < 1900 || y1 * 1000 + y2 * 100 + y3 * 10 + y4 > 2023)
            {
                std::cout << "Неверный день у даты:\t" << exp << std::endl;
                exit(EXIT_FAILURE);
            }
            _exp = exp;
        }
        catch (std::exception& ex)
        {
            std::cout << "Неправильные данные для даты:\t" << exp << std::endl;
            exit(EXIT_FAILURE);
        }

    }
    else if (_type == "Integer") {
        try 
        {
            std::stoi(exp);
            _exp = exp;
        }
        catch (std::exception& ex)
        {
            std::cout << "Неверные данные для выражения:\t" << exp << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (_type == "Float") 
    {
        try
        {
            std::stof(exp);
            _exp = exp;
        }
        catch (std::exception& ex)
        {
            std::cout << "Неверные данные для выражения:\t" << exp << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cout << "Не установлена колонка" << std::endl;
        exit(EXIT_FAILURE);
    }
}

const std::string& Argument::GetType() const
{
    return _type;
}
