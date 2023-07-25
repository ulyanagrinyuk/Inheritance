#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Human
{
	static const int LAST_NAME_WIDTH = 12;
	static const int FIRST_NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static int count;
protected:
	string last_name;
	string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}

	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		count++;
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		count--;
		cout << "HDestructor:\t" << this << endl;
	}

	virtual std::ostream& print(std::ostream& ofs)const
	{
		ofs << typeid(*this).name() << ":\t";
		ofs.width(LAST_NAME_WIDTH);
		ofs << std::left;
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << std::left;
		ofs << first_name; 
		ofs.width(AGE_WIDTH);
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

int Human::count = 0;

//std::ostream& operator<<(std::ostream& os, const Human& obj)
//{
//	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
//}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	 obj.print(ofs);
	 return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	obj.scan(ifs);
	return ifs;
}

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 7;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//								Constructors:
	Student
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os) << " ";
		return os << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
	std::ofstream& preint(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(GROUP_WIDTH);
		ofs << group;
		ofs.width(RATING_WIDTH);
		ofs << rating;
		ofs.width(ATTENDANCE_WIDTH);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char sz_speciality[SPECIALITY_WIDTH + 1] = {};
		ifs.read(sz_speciality, SPECIALITY_WIDTH);
		this->speciality = sz_speciality;
		ifs >> group >> rating >> attendance;
		return ifs;
	}
};

//std::ostream& operator<<(std::ostream& os, const Student& obj)
//{
//	return os << (Human&)obj << obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance();
//}

class Teacher :public Human
{
	static const int TACT_WIDTH = 22;
	static const int CREATIVITY_WIDTH = 5;
	std::string tact;
	int creativity;
public:
	const std::string& get_tact()const
	{
		return tact;
	}
	int get_experience()const
	{
		return creativity;
	}
	void set_tact(const std::string& tact)
	{
		this->tact = tact;
	}
	void set_creativity(int creativity)
	{
		this->creativity = creativity;
	}
	Teacher
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& tact, int creativity
	) :Human(last_name, first_name, age)
	{
		set_tact(tact);
		set_creativity(creativity);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os) << " ";
		return os << tact << " " << creativity << endl;
	}
	std::ofstream print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(TACT_WIDTH);
		ofs << tact;
		ofs.width(CREATIVITY_WIDTH);
		ofs << creativity;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char sz_tact[TACT_WIDTH + 1] = {};
		ifs.read(sz_tact, TACT_WIDTH);
		this->tact = sz_tact;
		ifs >> creativity;
		return ifs;
	}
};


class Graduate :public Student
{
	
	std::string subject;
	double disciplined;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	double get_disciplined()const
	{
		return disciplined;
	}
	Graduate
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{

		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDenstructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		Student::print(os);
		return os << subject << endl;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Student::print(ofs);
		ofs << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};

void print(Human** group, const int n)
{
	cout << "\n---------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		/*cout << typeid(*group[i]).name() << ":\n";
		group[i]->print();*/
		/*if(typeid(*group[i]) == typeid(Student))
		cout << *dynamic_cast<Student*>(group[i]) << endl;*/
		cout << *group[i] << endl;
		cout << "\n---------------------------------------------\n";

	}
		
}
void save(Human** group, const int size, const char filename[])
{
	std::ofstream fout(filename);
	for (int i = 0; i < size; i++)fout << *group[i] << endl;
	fout.close();
	std::string command = "start notepad ";
	command += filename;
	system(command.c_str());
}
Human* HumanFactory(const std::string& type)
{
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "", "",0, 0, "");

}
Human** load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		for (n = 0; !fin.eof(); n++)
		{
			std::string buffer;
			std::getline(fin, buffer);
		}
		fin.close();
		group = new Human * [--n] {};
		fin.clear();
		fin.seekg(0);
		for (int i = 0; !fin.eof(); i++)
		{
			std::string type;
			std::getline(fin, type, ':');
			fin.ignore();
			group[i] = HumanFactory(type);
			group[i] = HumanFactory(type);
			fin >> *group[i];
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	return group;
}


//#define INHERITANCE 
//#define STORE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE 
	Human human("Montana", "Antonio", 30);
	human.print();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 95, 98);
	stud.print();

	Teacher T("Burke", "Matilda", 49, "Literature", 30);
	T.print();

	Graduate G("Stretch", "Mia", 29, "Journalist", "VKR", 50, 50, "On the topic The work of John Donne");
	G.print();
#endif // INHERITANCE 
#ifdef STORE_TO_FILE
	Human* group[] =
	/*Human** group = new Human*[5]*/
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 95, 98),
		new Teacher("Burke", "Matilda", 49, "Literature", 30),
		new Graduate("Stretch", "Mia", 29, "Journalist", "VKR", 50, 50, "On the topic The work of John Donne")
	};
	//cout << "\n---------------------------------------------\n";
	//for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	//{
	//	/*cout << typeid(*group[i]).name() << ":\n";
	//	group[i]->print();*/
	//	/*if(typeid(*group[i]) == typeid(Student))
	//	cout << *dynamic_cast<Student*>(group[i]) << endl;*/
	//	cout << *group[i] << endl;
	//	cout << "\n---------------------------------------------\n";
	//}
	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");
#endif // STORE_TO_FILE

	int n = 0;
	Human** group = load("group.txt", n);	
	print(group, n);
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}