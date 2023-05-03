class Student
{
private:
	string name, surname;
	vector<int> grades;
	int exam = 0;
	float finalM = 0;
	float finalA = 0;

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
	Student(string _name, string _surname, vector<int> &_grades, int _exam)
	{
		name = _name;
		surname = _surname;
		grades = move(_grades);
		exam = _exam;
	}

	// Student(string _name = "name", string _surname = "surname")
	// {
	// 	name = _name;
	// 	surname = _surname;
	// }

	void editNameSurname(string name, string surname)
	{
		this->name = name;
		this->surname = surname;
	}

	void editGrades(vector<int> grades)
	{
		this->grades = grades;
	}

	void editExam(int exam)
	{
		this->exam = exam;
	}

	float getFinalM() const { return finalM; }
	float getFinalA() const { return finalA; }

	bool operator<(const Student &other) const
	{
		return finalA < other.finalA;
	}

	friend void FillStudentStruct(istringstream &line, vector<Student> &Group);
	friend void OneNewGroup(vector<Student> &Group, vector<Student> &Stupid);

	
};
vector<Student> Group;
vector<Student> Stupid;