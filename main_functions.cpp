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

void CalcData(Student &temp)
{
	float avg = 0;
	if (temp.grades.size() != 0)
	{ 
		float sum = 0;
		for (int i = 0; i < temp.grades.size(); i++)
		{
			sum += temp.grades[i];
		}
		avg = (float)sum / temp.grades.size();
	}
	else
	{
		avg = 0;
	} 

	temp.finalA = (float)(0.4 * avg) + (float)(0.6 * temp.exam);

	float median = 0;
	if (temp.grades.size() != 0)
	{
		sort(temp.grades.begin(), temp.grades.end());
		if (temp.grades.size() % 2 == 0)
		{
			median = (float)((temp.grades[temp.grades.size() / 2] + temp.grades[temp.grades.size() / 2 - 1]) / 2.0);
		}
		else
		{
			median = (float)(temp.grades[temp.grades.size() / 2]);
		};
	}
	else
		(median = 0);

	temp.finalM = (float)((0.4 * median) + (0.6 * temp.exam));
}

bool Compare(const Student &a, const Student &b)
{
	return a.name < b.name;
}

void FillStudentStruct1(int c, ifstream &readf, int grade)
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
            throw "Bad data format in file";
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
}

void FillStudentStruct(istringstream &line)
{
    line >> temp.name >> temp.surname;
    int grade = 0;
    for (int j = 0; j < 10; j++)
    {
        line >> grade;
        if (grade >= 1 && grade <= 10)
        {
            temp.grades.push_back(grade);
        }
        else
        {
            throw "Bad data format in file";
        }
    }

    int exam;
    line >> exam;
    if (exam >= 1 && exam <= 10)
    {
        temp.exam = exam;
    }
    else
    {
        throw "Data in file must contain name, surname, homework grades and exam grade. Please, check your file.";
    }

    CalcData(temp);
    temp.exam = NULL;
    temp.grades.clear();
}

void DataSort(Student &temp, stringstream &stupid, stringstream &smart)
{
    if (answ.finaltype == 'a' || answ.finaltype == 'A')
    {
        if (temp.finalA < 5)
        {
            stupid << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            stupid << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << "-----" << endl;
        }
        else
        {
            smart << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            smart << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << "-----" << endl;
        }
    }
    else if (answ.finaltype == 'm' || answ.finaltype == 'M')
    {
        if (temp.finalA < 5)
        {
            stupid << left << setw(20) << temp.name << left << setw(20) << temp.surname;
             smart << left << setw(15) << fixed << setprecision(2) << "-----" << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
        else
        {
            smart << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            smart << left << setw(15) << fixed << setprecision(2) << "-----" << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
    }
    else if (answ.finaltype == 'b' || answ.finaltype == 'B')
    {
        if (temp.finalA < 5)
        {
            stupid << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            stupid << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
        else
        {
            smart << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            smart << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
    }
}

void BufferData(int i, const int BUFFER_SIZE, char *buffer)
{
    string name = "Name" + to_string(i + 1);
    string surname = "Surname" + to_string(i + 1);

    // Generate numbers
    int grades[10];
    for (int j = 0; j < 10; j++)
    {
        grades[j] = (rand() % 10) + 1;
    }

    int exam = (rand() % 10) + 1;

    snprintf(buffer, BUFFER_SIZE, "%-20s%-20s%-15d%-15d%-15d%-15d%-15d%-15d%-15d%-15d%-15d%-15d%-15d\n", name.c_str(), surname.c_str(), grades[0], grades[1], grades[2], grades[3], grades[4], grades[5], grades[6], grades[7], grades[8], grades[9], exam);
}

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
			srand(static_cast<unsigned int>(time(NULL)));

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

void GenerateFileData(int k)
{
    srand(static_cast<unsigned int>(time(NULL)));

    // Open file for writing
    ofstream NewFile("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis\\data\\" + to_string(k) + ".txt");

    //--------------------------------HEADER-------------------------------------
    NewFile << left << setw(20) << "NAME" << left << setw(20) << "SURNAME";
    for (int i = 0; i < 10; i++)
    {
        NewFile << left << setw(15) << "HW" + to_string(i);
    }
    NewFile << left << setw(15) << "EXAM" << endl;
    //---------------------------------------------------------------------------

    // Define buffer size
    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];

    // Generate members and write to file using buffer
    for (int i = 0; i < k; i++)
    {
        BufferData(i, BUFFER_SIZE, buffer);

        // Write buffer to file
        NewFile << buffer;
    }

    // Close file
    NewFile.close();
}

void GeneratedFileSort()
{
	auto start1 = high_resolution_clock::now();
	stringstream stupid(stringstream::out | stringstream::binary);
	stringstream smart(stringstream::out | stringstream::binary);
	//------------------------------------------HEADERS---------------------------------------------------------------------------------------------------
	stupid << left << setw(20) << "Name" << left << setw(20) << "Surname" << left << setw(15) << "Final(avg)" << left << setw(15) << "Final(med)" << endl;
	stupid << "-------------------------------------------------------------------" << endl;

	smart << left << setw(20) << "Name" << left << setw(20) << "Surname" << left << setw(15) << "Final(avg)" << left << setw(15) << "Final(med)" << endl;
	smart << "-------------------------------------------------------------------" << endl;
	//---------------------------------------------------------------------------------------------------------------------------------------------------

	int k = 1000;
	for (int f = 0; f < 5; f++)
	{
		string filename = "C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis\\data\\" + to_string(k) + ".txt";

		int r = k; // rows

		string header;
		ifstream readf(filename);
		getline(readf, header);
		string line;

		auto start2 = high_resolution_clock::now();
		while (getline(readf, line))
		{
			istringstream x(line);
			FillStudentStruct(x);
			DataSort(temp, stupid, smart);
		}
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<microseconds>(stop2 - start2);
		cout << "File " << k << ".txt read and sorted in: " << fixed << setprecision(4) << duration2.count() / 1000000.0 << " seconds" << endl;

		readf.close();
		k = k * 10;
	}

	ofstream txtFile;
	txtFile.open("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis\\data\\stupid.txt", ofstream::binary);
	txtFile.write(stupid.str().c_str(), stupid.str().length());
	txtFile.close();

	txtFile.open("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis\\data\\smart.txt", ofstream::binary);
	txtFile.write(smart.str().c_str(), smart.str().length());
	txtFile.close();

	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "Files smart.txt and stupid.txt created in: " << fixed << setprecision(4) << duration1.count() / 1000000.0 << " seconds" << endl;
}

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

void Coutput()
{
	cout << left << setw(20) << "Name" << left << setw(20) << "Surname" << left << setw(15) << "Final(avg)" << left << setw(15) << "Final(med)" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < Group.size(); i++)
	{
		PrintData(Group[i], answ.finaltype);
	}
}

void Datatype1()
{
    do
    {
        GatherUserData(temp);
        Group.push_back(temp);
        temp.exam = NULL;
        temp.grades.clear();

        cout << "Add new student? (y/n)" << endl;
        cin >> answ.answer;
        while ((answ.answer != 'y' && answ.answer != 'Y') && (answ.answer != 'n' && answ.answer != 'N'))
        {
            cout << "There is no such answer. Y/y - add student, N/n - continue." << endl;
            cin >> answ.answer;
        };
    } while (answ.answer == 'y' || answ.answer == 'Y');
    sort(Group.begin(), Group.end(), Compare);
    Coutput();
    Group.clear();
}

void Datatype2()
{
    string filename = "kursiokai.txt";
    GatherFileData(filename);
    sort(Group.begin(), Group.end(), Compare);
    Coutput();
    Group.clear();
}

void Datatype3()
{
	int k = 1000; // how many members in file
	for (int i = 0; i < 5; i++)
	{
		auto start = high_resolution_clock::now();
		GenerateFileData(k);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "File " << k << ".txt created in: " << fixed << setprecision(4) << duration.count() / 1000000.0 << " seconds" << endl;

		k = k * 10;
	}

	GeneratedFileSort();
}