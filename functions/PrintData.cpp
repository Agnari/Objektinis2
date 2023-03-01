
void PrintData(Student &temp, char finaltype)
{
	cout << left << setw(20) << temp.name << left << setw(20) << temp.surname;
	if (finaltype == 'a' || finaltype == 'A')
	{
		cout << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << "-----" << endl;
	}
	else if (finaltype == 'm' || finaltype == 'M')
	{
		cout << left << setw(15) << fixed << setprecision(2) << "-----" << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
	}
	else
	{
		cout << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
	}
}
