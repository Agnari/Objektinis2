
void GatherFileData(string filename)
{
	int r = CountRows(filename);
	int c = CountColumns(filename);
	int grade = 0;

	string header;
	ifstream readf(filename);
	getline(readf, header);

	for (int i = 0; i < r - 1; i++)
	{
		FillStudentStruct1(c, readf, grade);

		Group.push_back(temp);
		temp.exam = NULL;
		temp.grades.clear();
	}

	readf.close();
}
