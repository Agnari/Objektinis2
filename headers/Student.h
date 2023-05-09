#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

//----------------BASE----------------
class Human
{
protected:
	string name, surname;

public:
	Human(string _name, string _surname)
	{
		name = _name;
		surname = _surname;
	}

	Human()
	{
		name = "";
		surname = "";
	}

	virtual ~Human()
	{
		name.clear();
		surname.clear();
	}

	virtual void introduce() = 0;
};

//----------------DERIVED----------------
class Student : public Human
{
private:
	vector<int> grades;
	int exam;
	float finalM;
	float finalA;

	void CalcData()
	{
		float avg = 0;
		if (!grades.empty())
		{
			int sum = 0;
			for (int grade : grades)
			{
				sum += grade;
			}
			avg = (float)(sum / grades.size());
		}

		finalA = (float)((0.4 * avg) + (0.6 * exam));

		float median = 0;
		if (!grades.empty())
		{
			sort(grades.begin(), grades.end());
			if (grades.size() % 2 == 0)
			{
				median = (float)((grades[grades.size() / 2 - 1] + grades[grades.size() / 2]) / 2.0);
			}
			else
			{
				median = (float)(grades[grades.size() / 2]);
			}
		}
		else
		{
			median = 0;
		}

		finalM = (float)((0.4 * median) + (0.6 * exam));
	}

public:
	// Rule of five: constructor, copy constructor, copy assignment operator, move constructor, move assignment operator

	// Default constructor
	Student() = default;

	// Constructor with arguments
	 Student(string _name, string _surname, vector<int> _grades, int _exam)
        : Human(move(_name), move(_surname)), grades{move(_grades)}, exam{_exam}
    {
        CalcData();
    }

	// Copy constructor
	Student(const Student &other)
		: Human(other.name, other.surname), grades{other.grades}, exam{other.exam}, finalM{other.finalM}, finalA{other.finalA}
	{
	}

	// Copy assignment operator
	Student &operator=(const Student &other)
	{
		if (this != &other)
		{
			Human::operator=(other);
			grades = other.grades;
			exam = other.exam;
			finalM = other.finalM;
			finalA = other.finalA;
		}

		return *this;
	}

	// Move constructor
	Student(Student &&other) noexcept
		: Human(move(other)), grades{move(other.grades)}, exam{other.exam}, finalM{other.finalM}, finalA{other.finalA}
	{
	}

	// Move assignment operator
	Student &operator=(Student &&other) noexcept
	{
		if (this != &other)
		{
			Human::operator=(std::move(other));
			grades = move(other.grades);
			exam = other.exam;
			finalM = other.finalM;
			finalA = other.finalA;
		}

		return *this;
	}

	~Student() = default;

	float getFinalM() const { return finalM; }
	float getFinalA() const { return finalA; }

	bool operator<(const Student &other) const
	{
		if (finalA != other.finalA)
		{
			return finalA < other.finalA;
		}
		else
		{
			return finalM < other.finalM;
		}
	}

	void introduce() override {
        cout << "My name is " << name << " " << surname << ", and I'm a student." << endl;
    }

	friend void FillStudentStruct(std::istringstream &line, std::vector<Student> &Group);
	friend void OneNewGroup(std::vector<Student> &Group, std::vector<Student> &Stupid);
	friend void NewStupidSmartTxt();
	friend void StupidSmartTxt();
};

vector<Student> Group;
vector<Student> Stupid;