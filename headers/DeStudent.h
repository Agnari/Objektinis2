struct Student
{
	string name, surname;
	deque<int> grades;
	int exam = 0;
	float finalM = 0;
	float finalA = 0;
};
deque<Student> Group;
deque<Student> Smart;
deque<Student> Stupid;
Student tempDe;