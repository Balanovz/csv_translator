/*
Пример вызова:
gen_csv.exe –col <входной_файл> –кол-во_колонок> –row <входной_файл> –кол-ко_строк> -len
<входной_файл> –макс_длина_значения> -enc <входной_файл> –кодировка> –out
<входной_файл> –имя_выходного_файла>

Например:

gen_csv.exe –col 543 –row 987654 –len 300 -enc UTF-8 –out in_file.csv

В результате выполнения программы по указанному пути должен сформироваться файл в
формате CSV (в соответствии с требованиями изложенными выше). Имена колонок и их
типы система должна генерировать случайным образом, а затем формировать строки из
случайных символов. Максимальную длину значения типа String можно ограничивать
параметром –len.
Программы «Поиск по CSV файлу» должна уметь обрабатывать файлы сгенерированные
данным генератором
*/
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Argument.h"
#include "Generator.h"


void Init(const std::vector<std::string>& commands, Argument& arg)
{

    if (commands[0] == "-col")
        arg.SetCol(commands[1]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[0] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[2] == "-row")
        arg.SetRow(commands[3]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[2] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[4] == "-len")
        arg.SetLength(commands[5]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[4] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[6] == "-enc")
        arg.SetEnc(commands[7]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[6] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[8] == "-out")
        arg.SetOut(commands[9]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[9] << std::endl;
        exit(EXIT_FAILURE);
    }
}



int main(int argc, char* argv[])
{
    const int countOfCommand = 11;
    setlocale(LC_ALL, "Russian");

    if (argc != countOfCommand) {
        std::cout << "Неверное количество команд:\t(" << argc << ")\n";
        exit(EXIT_FAILURE);
    }
    std::vector<std::string> commands(argv + 1, argv + argc);
    Argument arg;
    Init(commands, arg);
    
    Generator gen;
    gen.FillFile(arg);
    
    std::system("pause");
}
