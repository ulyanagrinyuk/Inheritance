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

	std::ofstream fout_wol("201 ready.txt");
	std::ofstream fout_dhcpd("201dhcpd.txt");
	std::ifstream fin("201 RAW.txt");
	if (fin.is_open())
	{
		const int MAC_SIZE = 18;
		const int IP_SIZE = 16;
		char sz_mac_buffer[MAC_SIZE]{};
		char sz_ip_buffer[IP_SIZE]{};
		//WOL:
		while (!fin.eof())
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
		}
		//DHCP:
		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;
		for (int i = 0; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (strlen(sz_ip_buffer) == 0)continue;
			for (int i = 0; sz_mac_buffer[i]; i++)
				if(sz_mac_buffer[i] == '-')
					sz_mac_buffer[i] == ':';

			cout << "host-" << i + 1 << endl;
			cout << "{\n";
			cout << "\thardware-ethernet:" << sz_mac_buffer << ";\n";
			cout << "\tfixed-address:" << sz_mac_buffer << ";\n";
			cout << "}\n";

			fout_dhcpd << "host-" << i + 1 << endl;
			fout_dhcpd << "{\n";
			fout_dhcpd << "\thardware-ethernet:" << sz_mac_buffer << ";\n";
			fout_dhcpd << "\tfixed-address:" << sz_mac_buffer << ";\n";
			fout_dhcpd << "}\n";
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error file not found" << endl;
	}
	fout_wol.close();
	fout_dhcpd.close();
	system("start notepad 201 ready.txt");
	system("start notepad 201dhcpd.txt");
}