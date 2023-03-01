
void GatherUserData(Student &temp)
{
	cout << "Enter name and surname: " << endl;
	cin >> temp.name >> temp.surname;

	char answer;
	cout << "Manual input or random values? (m/r)" << endl;
	cin >> answer;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (true)
	{
		if (answer == 'm' || answer == 'M')
		{
			cout << "Enter homework grades (0-10) or symbol to continue:" << endl;
			int grade = 0;

			while (cin >> grade)
			{
				if (grade > 0 && grade <= 10)
				{
					temp.grades.push_back(grade);
				}
				else
				{
					while (grade <= 0 || grade > 10)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Wrong value. Please enter number from 1 to 10" << endl;
						cin >> grade;
					}
					temp.grades.push_back(grade);
				};
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			int exam = 0;
			cout << "Enter exam grade: " << endl;
			cin >> exam;
			while (exam < 0 || exam > 10)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Re-enter your value. It must be from 1 to 10." << endl;
				cin >> exam;
			}
			temp.exam = exam;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else if (answer == 'r' || answer == 'R')
		{
			srand(time(NULL));

			int g = 0;
			cout << "Enter how many values you want to generate or symbol to continue" << endl;
			cin >> g;
			for (int i = 0; i < g; i++)
			{
				temp.grades.push_back((rand() % 10) + 1);
			} // filling array with random values

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			char answer;
			cout << "Do you want to generate exam grade? (y/n)" << endl;
			cin >> answer;
			if ((answer != 'y' && answer != 'Y') && (answer != 'n' && answer != 'N'))
			{
				cout << "There is no such answer. Y/y - generate exam grade, N/n - continue." << endl;
				cin >> answer;
			}
			else if (answer == 'y' || answer == 'Y')
			{
				temp.exam = (rand() % 10) + 1;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else
		{
			cout << "There is no such answer. Choose manual or random input. (m/r)" << endl;
			cin >> answer;
		}
	};

	cout << "Grades: ";
	for (int i = 0; i < temp.grades.size(); i++)
	{
		cout << temp.grades[i] << " ";
	}
	cout << endl
		 << "Exam: " << temp.exam << endl;
	CalcData(temp);
}
