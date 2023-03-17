
int CountColumns(string filename)
{
	ifstream readf(filename);

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
