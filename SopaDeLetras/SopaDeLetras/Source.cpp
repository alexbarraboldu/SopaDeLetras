#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

typedef std::vector<char> char_vector;

void abrirVolcarVector(std::string _file)
{
	std::fstream file;
	file.open(_file, std::ios::in);

	if (!file.is_open()) { file.close();  return; };

	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		for (size_t i = 0; i < line.size(); i++)
		{
			char letter = line[i];
			std::cout << letter;
		}
		std::cout << std::endl;
	}
	file.close();
}

//void abrirLeerImprimir(std::string _file)
//{
//	std::fstream file;
//	file.open(_file, std::ios::in);
//
//	if (!file.is_open()) { file.close();  return; };
//
//	std::string line;
//	while (!file.eof())
//	{
//		std::getline(file, line);
//		for (size_t i = 0; i < line.size(); i++)
//		{
//			char letter = line[i];
//			std::cout << letter;
//		}
//		std::cout << std::endl;
//	}
//	file.close();
//}


int main()
{
	/*std::fstream palabras;
	palabras.open("words.txt", std::ios::in);*/
	std::string fileName;
	std::cin >> fileName;
	abrirVolcarVector(fileName);

	std::getchar();
	std::cin.get();
	system("pause");
}