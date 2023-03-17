
int CountRows(string filename)
{
	ifstream readf(filename);
	string line;
	int r = 0;

	while (getline(readf, line))
	{
		r++;
	}

	readf.close();
	return r;
}