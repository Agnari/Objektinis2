
void Settings()
{
	cout << "Choose option (1-3):" << endl;
	cout << "1. Manual input" << endl;
	cout << "2. Read from file" << endl;
	cout << "3. Work with random generated files" << endl;
	cout << "4. Only generate files" << endl;

	cin >> answ.datatype;
	while (answ.datatype != 1 && answ.datatype != 2 && answ.datatype != 3 && answ.datatype != 4)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "There is no such answer." << endl;
		cout << "----------------------------------------" << endl;
		cout << "Choose option (1-3):" << endl;
		cout << "1. Manual input" << endl;
		cout << "2. Read from file" << endl;
		cout << "3. Work with random generated files" << endl;
		cout << "4. Only generate files" << endl;
		cin >> answ.datatype;
	};

	cout << "Do you want average, median or both as final grade? (a/m/b)";
	cin >> answ.finaltype;
	while ((answ.finaltype != 'a' && answ.finaltype != 'A') && (answ.finaltype != 'm' && answ.finaltype != 'M') && (answ.finaltype != 'b' && answ.finaltype != 'B'))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "There is no such answer. A/a - for average, M/m - for median, B/b - for both." << endl;
		cin >> answ.finaltype;
	};
}
