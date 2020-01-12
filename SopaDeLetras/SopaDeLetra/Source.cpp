#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

typedef std::vector<std::vector<char>> char_matrix;
typedef std::vector<std::string> string_vector;

struct Msize
{
	int vtr1;
	int vtr2;
};

Msize returnSizeMatrix(std::string _file)
{
	std::fstream file;
	file.open(_file, std::ios::in);

	std::string line;
	int fileSize = 0;
	while (!file.eof()) { std::getline(file, line); fileSize++;	}

	file.close();

	Msize matrixSize;
	matrixSize.vtr1 = fileSize;
	matrixSize.vtr2 = line.size();

	return matrixSize;
}

string_vector abrirVolcarVector()
{
	std::fstream file;
	file.open("words.txt", std::ios::in);

	int VectorSize = returnSizeMatrix("words.txt").vtr1;
	string_vector words(VectorSize);
	std::string line;
	size_t i = 0;
	while (!file.eof())
	{
		std::getline(file, line);
		words.at(i) = line;
		i++;
	}
	file.close();
	return words;
}

char_matrix abrirVolcarMatriz(std::string _file)
{
	std::fstream file;
	file.open(_file, std::ios::in);

	Msize MatrixSize = returnSizeMatrix(_file);
	char_matrix vtr1(MatrixSize.vtr1, std::vector<char>(MatrixSize.vtr2));

	if (!file.is_open()) { file.close();  return vtr1; };

	size_t it = 0;
	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		char letter = line[0];
		for (size_t i = 0; i < line.length(); i++)
		{
			letter = line[i];
			vtr1.at(it).at(i) = letter;
		}
		it++;
	}
	file.close();
	return vtr1;
}

void checkNames(std::string _input, string_vector _toSearch)
{
	for (size_t i = 0; i < _toSearch.size(); i++)
	{
		int pos = _input.find(_toSearch[i].data());
		if (pos < 0) { continue; };
		std::string aux = _input.substr(pos);
		std::cout << "\tMatch";
	}
}

void checkMatrix(char_matrix _matrix, string_vector _lineD)
{
	// DEL DERECHO Y DEL REVÉS (SOLO COLUMNAS)
	for (size_t k = 0; k < 2; k++)
	{
		std::string filaD;
		for (size_t i = 0; i < _matrix.size(); i++)
		{
			filaD = "";
			char AuxfilaD;
			for (size_t j = 0; j < _matrix[i].size(); j++)
			{
				switch (k)
				{
				case 0:
					AuxfilaD = _matrix.at(i).at(j);	//	MATRIZ DEL DERECHO
					filaD += AuxfilaD;
					continue;
				case 1:
					AuxfilaD = _matrix.at(i).at((_matrix[i].size() - 1) - j);	//	MATRIZ DEL REVÉS (SOLO COLUMNAS)
					filaD += AuxfilaD;
					continue;
				default:
					std::cout << "Error: yo que se bro sos estupido";
					continue;
				}
			}
			std::cout << filaD;
			checkNames(filaD, _lineD);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	// DEL DERECHO Y DEL REVÉS (DIAGONALMENTE)
	for (size_t kk = 0; kk < 2; kk++)
	{
		int damn = 0;
		for (size_t oo = 0; oo < _matrix[0].size(); oo++)
		{
			if (oo > 5) { damn -= 1; };
			std::string filaD2;
			for (size_t ii = 0 ; ii < _matrix.size() + damn; ii++)
			{
				char AuxfilaD;
				for (size_t jj = ii + oo; jj <= ii + oo; jj++)
				{
					switch (kk)
					{
					case 0:
						AuxfilaD = _matrix.at(ii).at(jj);	//	MATRIZ DEL DERECHO
						filaD2 += AuxfilaD;
						continue;
					case 1:
						AuxfilaD = _matrix.at(ii).at((_matrix[ii].size() - 1) - jj);	//	MATRIZ DEL REVÉS (SOLO COLUMNAS)
						filaD2 += AuxfilaD;
						continue;
					default:
						std::cout << "Error: yo que se bro sos estupido";
						continue;
					}
				}
			}
			std::cout << filaD2;
			checkNames(filaD2, _lineD);
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
	//	DEL DERECHO Y DEL REVÉS (SOLO FILAS)
	for (size_t k = 0; k < 2; k++)
	{
		std::string filaD;
		for (size_t i = 0; i < _matrix[0].size(); i++)
		{
			filaD = "";
			char AuxfilaD;
			for (size_t j = 0; j < _matrix.size(); j++)
			{
				switch (k)
				{
				case 0:
					AuxfilaD = _matrix.at(j).at(i);	//	MATRIZ DEL DERECHO
					filaD += AuxfilaD;
					continue;
				case 1:
					AuxfilaD = _matrix.at(_matrix.size() - 1 - j).at(i); //	MATRIZ DEL REVÉS (SOLO FILAS)
					filaD += AuxfilaD;
					continue;
				default:
					std::cout << "Error: yo que se bro sos estupido";
					continue;
				}
			}
			std::cout << filaD;
			checkNames(filaD, _lineD);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::string fileName;
	std::cin >> fileName;

	char_matrix vtr2 = abrirVolcarMatriz(fileName);
	string_vector lineD = abrirVolcarVector();
	std::cout << '\n';
	checkMatrix(vtr2, lineD);

	std::cin.get();
	system("pause");
}



























//void readMatrix(char_matrix _matrix) {
//	for (size_t i = 0; i < _matrix.size(); i++)
//	{
//		for (size_t j = 0; j < _matrix[i].size(); j++)
//		{
//			std::cout << _matrix.at(i).at(j);
//		}
//		std::cout << std::endl;
//	}
//}
//
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
//		for (size_t i = 0; i < line.size(); i++) std::cout << line[i];
//		std::cout << std::endl;
//	}
//	file.close();
//}