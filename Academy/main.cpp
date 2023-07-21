#include<iostream>
#include<string>
using namespace std;

class Human
{
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
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age;
	}
};

//std::ostream& operator<<(std::ostream& os, const Human& obj)
//{
//	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
//}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

class Student :public Human
{
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
};

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	return os << (Human&)obj << obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance();
}

class Teacher :public Human
{
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
};

//#define INHERITANCE 

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

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 95, 98),
		new Teacher("Burke", "Matilda", 49, "Literature", 30),
		new Graduate("Stretch", "Mia", 29, "Journalist", "VKR", 50, 50, "On the topic The work of John Donne")
	};
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
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}