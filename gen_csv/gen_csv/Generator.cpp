#include "Generator.h"

Generator::Generator()
{
}

Generator::~Generator()
{
}

void Generator::GetData(std::vector<std::string>& data, const std::string& filepath, int sizeLimit)
{
	setlocale(LC_ALL, "rus");
	std::ifstream is(filepath);
	std::string temp;
	bool makeLimit = data[0].find("String") != std::string::npos;
	if (is.is_open()) 
	{
		while (!is.eof())
		{
			temp = "";
			std::getline(is, temp);
			if (makeLimit)
				data.push_back(temp.substr(0, sizeLimit));
			else
				data.push_back(temp);
		}
	}
	is.close();
}


void Generator::FillFile(const Argument& arg)
{
	srand(time(nullptr));
	std::vector<std::string> fullNames{ "ФИО String" },
		dates{ "Дата_рождения Date" },
		projectCounts{ "Кол-во_проектов Integer" },
		ratings{ "Рейтинг Float" },
		comments{ "Комментарий String" };

	GetData(fullNames, "\\test_task\\gen_csv\\data\\fullnames.txt", arg.GetLength());
	GetData(dates, "\\test_task\\gen_csv\\data\\dates.txt", arg.GetLength());
	GetData(projectCounts, "\\test_task\\gen_csv\\data\\projectcounts.txt", arg.GetLength());
	GetData(ratings, "\\test_task\\gen_csv\\data\\ratings.txt", arg.GetLength());
	GetData(comments, "\\test_task\\gen_csv\\data\\comments.txt", arg.GetLength());

	std::vector<std::vector<std::string>> datas = { fullNames, dates, projectCounts, ratings, comments };
	std::vector<std::vector<std::string>> randomDatas;
	for (int i = 0; i < arg.GetCol(); ++i)
		randomDatas.push_back(datas[rand() % datas.size()]);

	// запись заголовков и их типов
	std::ofstream os(arg.GetOut());
	if (os.is_open()) 
	{
		for (auto data : randomDatas)
			os << data[0] << "; ";
		os << '\n';

		for (int i = 1; i < arg.GetRow(); ++i)
		{
			for (auto data : randomDatas)
				os << data[1 + rand() % (data.size() - 1)] << "; ";
			os << '\n';
		}
	}

	os.close();
}
//gen_csv.exe -col 543 -row 987654 -len 300 -enc UTF-8 -out D:\test_task\gen_csv\in_file.csv