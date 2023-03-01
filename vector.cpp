#include "./headers/Mylib.h"
#include "./headers/Student.h"
#include "./headers/Functions.h"
char finaltype;

void CalcData(Student &temp);
void GatherUserData(Student &temp);
int CountRows();
int CountColumns();
void GatherFileData();
bool Compare(const Student &a, const Student &b);
void PrintData(Student &temp, char finaltype);

int main()
{
	try
	{
		char answer;

		cout << "Do you want to read from file? (y/n)" << endl;
		cin >> answer;
		while ((answer != 'y' && answer != 'Y') && (answer != 'n' && answer != 'N'))
		{
			cout << "There is no such answer. Y/y - add student, N/n - continue." << endl;
			cin >> answer;
		};

		cout << "Do you want average, median or both as final grade? (a/m/b)";
		cin >> finaltype;
		while ((finaltype != 'a' && finaltype != 'A') && (finaltype != 'm' && finaltype != 'M') && (finaltype != 'b' && finaltype != 'B'))
		{
			cout << "There is no such answer. A/a - for average, M/m - for median, B/b - for both." << endl;
			cin >> finaltype;
		};

		if (answer == 'y' || answer == 'Y')
		{
			GatherFileData();
		}
		else
		{
			do
			{
				GatherUserData(temp);
				Group.push_back(temp);
				temp.exam = NULL;
				temp.grades.clear();

				cout << "Add new student? (y/n)" << endl;
				cin >> answer;
				while ((answer != 'y' && answer != 'Y') && (answer != 'n' && answer != 'N'))
				{
					cout << "There is no such answer. Y/y - add student, N/n - continue." << endl;
					cin >> answer;
				};
			} while (answer == 'y' || answer == 'Y');
		}

		sort(Group.begin(), Group.end(), Compare);

		cout << left << setw(20) << "Name" << left << setw(20) << "Surname" << left << setw(15) << "Final(avg)" << left << setw(15) << "Final(med)" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		for (int i = 0; i < Group.size(); i++)
		{
			PrintData(Group[i], finaltype);
		}
		Group.clear();
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}
