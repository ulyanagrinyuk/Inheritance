#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	cout << "Hello Files" << endl;
	std::ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	fout << "Hello Files" << endl;
	fout << "Ну привет" << endl;
	fout.close();

	system("start notepad File.txt");
#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE
	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			const int SIZE = 256;
			char sz_buffer[SIZE] = {};
			/*fin >> sz_buffer;*/
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}

		fin.close();
	}
	else
	{
	std::cerr << "Error file not found" << endl;
	}
#endif // READ_FROM_FILE

}