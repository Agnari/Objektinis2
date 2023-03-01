
int CountRows()
{
	ifstream readf("kursiokai.txt");
	string line;
	int r = 0;

	while (getline(readf, line))
	{
		r++;
	}

	readf.close();
	return r;
}