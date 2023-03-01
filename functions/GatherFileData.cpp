
void GatherFileData()
{
	int r = CountRows();
	int c = CountColumns();
	int grade;

	string header;
	ifstream readf("kursiokai.txt");
	getline(readf, header);

	for (int i = 0; i < r - 1; i++)
	{
		readf >> temp.name >> temp.surname;
		for (int j = 0; j < c - 3; j++)
		{
			readf >> grade;
			if (grade >= 1 && grade <= 10)
			{
				temp.grades.push_back(grade);
			}
			else
			{
				throw "Bad Data Format";
			}
		}
	}

	int exam;
	readf >> exam;
	if (exam >= 1 && exam <= 10)
	{
		temp.exam = exam;
	}
	else
	{
		throw "Data in file must contain name, surname, homework grades and exam grade. Please, check your file.";
	}

	CalcData(temp);
	Group.push_back(temp);
	temp.exam = NULL;
	temp.grades.clear();

	readf.close();
}
