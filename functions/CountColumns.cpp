
int CountColumns()
{
	ifstream readf("kursiokai.txt");

	string line;
	getline(readf, line);
	stringstream s(line);
	string row;
	int c = 0;

	while (s >> row)
	{
		c++;
	}

	readf.close();
	return c;
}
