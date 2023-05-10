/**
 * @file Student.h
 * @author Agnari
 * @brief
 * @date 2023-05-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

//----------------BASE----------------
/**
 *@class Human
 *@brief The base class representing a human.
 */

class Human
{
protected:
	string name, surname;

public:
	/**
	 * @brief The constructor that initializes the name and surname of the human.
	 *
	 * @param _name The name of the human.
	 * @param _surname The surname of the human.
	 */
	Human(string _name, string _surname)
	{
		name = _name;
		surname = _surname;
	}

	/**
	 * @brief The default constructor.
	 */
	Human()
	{
		name = "";
		surname = "";
	}

	/**
	 * @brief The virtual destructor.
	 */
	virtual ~Human()
	{
		name.clear();
		surname.clear();
	}

	/**
	 * @brief An abstract method to introduce the human.
	 */
	virtual void introduce() = 0;
};

//----------------DERIVED----------------
/**
 *@class Student
 *@brief The derived class representing a student.
 */
class Student : public Human
{
private:
	vector<int> grades;
	int exam;
	float finalM;
	float finalA;

	/**
	 *@brief A private method to calculate the final grades of the student.
	 */
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

	/**
	 * @brief The default constructor.
	 */
	Student() = default;

	/**
	 * @brief The constructor that initializes the name, surname, grades and exam of the student.
	 *
	 * @param _name The name of the student.
	 * @param _surname The surname of the student.
	 * @param _grades The grades of the student.
	 * @param _exam The exam grade of the student.
	 */
	Student(string _name, string _surname, vector<int> _grades, int _exam)
		: Human(move(_name), move(_surname)), grades{move(_grades)}, exam{_exam}
	{
		CalcData();
	}

	/**
	 * @brief The copy constructor.
	 * @param other The student to be copied.
	 */
	Student(const Student &other)
		: Human(other.name, other.surname), grades{other.grades}, exam{other.exam}, finalM{other.finalM}, finalA{other.finalA}
	{
	}

	/**
	 * @brief The copy assignment operator.
	 * @param other The student to be assigned.
	 * @return The reference to the assigned student.
	 */
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

	/**
	 * @brief The move constructor.
	 * @param other The student to be moved.
	 */
	Student(Student &&other) noexcept
		: Human(move(other)), grades{move(other.grades)}, exam{other.exam}, finalM{other.finalM}, finalA{other.finalA}
	{
	}

	/**
	 * @brief The move assignment operator.
	 * @param other The student to be assigned by moving.
	 * @return The reference to the assigned student.
	 */
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

	/**
	 * @brief The default destructor.
	 */
	~Student() = default;

	/**
	 * @brief A getter method to get the final grade of the student calculated using the median.
	 * @return The final grade of the student calculated using the median.
	 */
	float getFinalM() const { return finalM; }

	/**
	 * @brief A getter method to get the final grade of the student calculated using the average.
	 * @return The final grade of the student calculated using the average.
	 */
	float getFinalA() const { return finalA; }

	/**
	 *@brief A comparison operator to compare the final grades of two students.
	 *@param other The student to be compared with.
	 *@return true if the final grade of this student is less than the final grade of the other student, false otherwise.
	 */
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

	/**
	 *@brief An override of the introduce() method from the base class Human.
	 *Prints the introduction of the student.
	 */
	void introduce() override
	{
		cout << "My name is " << name << " " << surname << ", and I'm a student." << endl;
	}

	/**
	*@brief A friend function to fill the Student struct with data from a string stream.
	*@param line The string stream containing the data.
	*@param Group The vector of students to be filled.
	*/
	friend void FillStudentStruct(std::istringstream &line, std::vector<Student> &Group);
	
	/**
	*@brief A friend function to move students from the Group vector to the Stupid vector based on their final grades.
	*@param Group The vector of students.
	*@param Stupid The vector of students with low final grades.
	*/
	friend void OneNewGroup(std::vector<Student> &Group, std::vector<Student> &Stupid);
	
	/**
	*@brief A friend function to create a new file and store the information of students with low final grades.
	*/
	friend void NewStupidSmartTxt();
	
	/**
	*@brief A friend function to update the existing file with the information of students with low final grades.
	*/
	friend void StupidSmartTxt();

};

/**
 * @brief The vector of students representing the group.
 * 
 */
vector<Student> Group;

/**
 * @brief he vector of students with low final grades.
 * 
 */
vector<Student> Stupid;