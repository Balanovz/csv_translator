#include "Finder.h"

Finder::Finder()
{
}

Finder::~Finder()
{
}

void Finder::FindTo(const Argument& arg)
{
	std::ifstream is(arg.GetIn());
	if (is.is_open())
	{
		std::string line, word;
		std::getline(is, line);
		std::istringstream iss(line, std::istringstream::in);
		std::vector<std::string> wordsVector;
		bool columnIsExist = false;
		int colIndex = -1;
		while (iss >> word)
		{
			colIndex++;
			if (word == arg.GetCol()) {
				columnIsExist = true;
				break;
			}
			iss >> word;
		}
		if (columnIsExist)
		{
			std::ofstream os(arg.GetOut());
			os << line << '\n';

			while (std::getline(is, line))
			{
				wordsVector = Split(line, ';');
				if (arg.GetType() == "String") 
				{
					if (wordsVector[colIndex].find(arg.GetExp()) != std::string::npos)
						os << line << '\n';
				}
				else
				{
					if (wordsVector[colIndex] == arg.GetExp())
						os << line << '\n';
				}
					
			}
			os.close();
		}
		else
		{
			std::cout << "Данного столбца нет в файле:\t" << arg.GetCol() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		std::cout << "Неверный путь к файлу:\t" << arg.GetIn() << std::endl;
		exit(EXIT_FAILURE);
	}
}

std::vector<std::string> Finder::Split(const std::string& str, char delim)
{
	std::vector<std::string> res;
	int lastLetterIndex = 0;
	char brackets = '"';
	for (int i = 0; i < str.size(); ++i) 
	{
		if (str[i] == delim)
		{
			res.push_back(str.substr(lastLetterIndex, i - lastLetterIndex));
			lastLetterIndex = i + 2;
		}

	}
	return res;
}
