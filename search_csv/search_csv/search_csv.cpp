/*
Пример файла:
ФИО String;              Дата_рождения Date; Кол-во_проектов Integer; Рейтинг Float; Комментарий String
Иванов Иван Иванович;    18.06.1983;         34;                      6,45;          "Работал над проектами: ""АБС""; ""КВД"""


Запуск приложения
Приложение запускается из командной строки:
search_csv.exe –in <входной_файл> –входной_файл> –out <входной_файл> –выходной_файл> -enc
<входной_файл> –кодировка> -col <входной_файл> –имя_столбца> -exp <входной_файл> –выражение_для_поиска>
Параметры должны проверяться на корректность, в том числе параметр –exp, который
зависит от типа колонки указанной в –col.
Входной файл должен проверяться на корректность формата (в том числе типов данных в
колонках)
Пример запуска приложения:

search_csv.exe –in in_file.csv –out out_file.csv -enc UTF-8 -col Дата_рождения -exp 18.06.1983

*/

#include <iostream>
#include "Argument.h"
#include "Finder.h"

void Init(const std::vector<std::string>& commands, Argument& arg)
{

    if (commands[0] == "-in")
        arg.SetIn(commands[1]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[0] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[2] == "-out")
        arg.SetOut(commands[3]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[2] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[4] == "-enc")
        arg.SetEnc(commands[5]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[4] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[6] == "-col")
        arg.SetCol(commands[7]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[6] << std::endl;
        exit(EXIT_FAILURE);
    }

    if (commands[8] == "-exp")
        arg.SetExp(commands[9]);
    else {
        std::cout << "Неверно введена команда:\t" << commands[9] << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    const int commandsCount = 11;
    if (argc != 11) 
    {
        std::cout << "Неверное количество команд:\t" << argc << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> commands(argv + 1, argv + argc);

    /*std::vector<std::string> commands = { "-in", "D:\\test_task\\search_samples\\file2.csv", "-out", "D:\\test_task\\search_csv\\out_file2.csv",
        "-enc", "UTF-8", "-col", "Рейтинг", "-exp", "6,49" };*/
    Argument arg;
    Init(commands, arg);
    Finder finder;
    finder.FindTo(arg);

    std::system("pause");
}
