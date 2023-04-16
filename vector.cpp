#include "./headers/Mylib.h"
#include "./headers/Student.h"

bool Compare(const Student &a, const Student &b)
{
    return a.finalA < b.finalA;
}

void CalcData(Student &temp)
{
    float avg = 0;
    if (!temp.grades.empty())
    {
        int sum = 0;
        for (int grade : temp.grades)
        {
            sum += grade;
        }
        avg = (float)(sum / temp.grades.size());
    }

    temp.finalA = (float)((0.4 * avg) + (0.6 * temp.exam));

    float median = 0;
    if (!temp.grades.empty())
    {
        sort(temp.grades.begin(), temp.grades.end());
        if (temp.grades.size() % 2 == 0)
        {
            median = (float)((temp.grades[temp.grades.size() / 2 - 1] + temp.grades[temp.grades.size() / 2]) / 2.0);
        }
        else
        {
            median = (float)(temp.grades[temp.grades.size() / 2]);
        }
    }
    else
    {
        median = 0;
    }

    temp.finalM = (float)((0.4 * median) + (0.6 * temp.exam));
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
    Group.push_back(temp);
    temp.exam = NULL;
    temp.grades.clear();
}

void Read(int k)
{

    string filename = "C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis\\data\\" + to_string(k) + ".txt";
    string header;
    ifstream readf(filename);
    getline(readf, header);
    string line;

    while (getline(readf, line))
    {
        istringstream x(line);
        FillStudentStruct(x);
    }

    readf.close();
}

void TwoGroups()
{

    for (const auto &temp : Group)
    {
        if (temp.finalA > 5)
        {
            Smart.push_back(temp);
        }
        else
        {
            Stupid.push_back(temp);
        }
    }
}

void OneNewGroup()
{
    for (auto it = Group.begin(); it != Group.end();)
    {
        if (it->finalA < 5)
        {
            // Move the element to the Stupid vector
            Stupid.push_back(move(*it));
            // Erase the element from the Group vector and update the iterator
            it = Group.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    int str = 0;
    cout << "Choose strategy (1-2):" << endl;
    cout << "Strategy 1: split list of students into two groups 'smart' and 'stupid" << endl;
    cout << "Strategy 2: sort stupid students into new list 'stupid'." << endl;
    cin >> str;
    while (str != 1 && str != 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong answer." << endl;
        cout << "Choose strategy (1-2):" << endl;
        cout << "Strategy 1: split list of students into two groups 'smart' and 'stupid" << endl;
        cout << "Strategy 2: sort stupid students into new list 'stupid'." << endl;
        cin >> str;
    };

    int k = 1000;
    for (int i = 0; i < 5; i++)
    {
        auto start1 = high_resolution_clock::now();
        Read(k);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        cout << "File " << k << ".txt read in: " << fixed << setprecision(4) << duration1.count() / 1000000.0 << " seconds" << endl;
        cout << endl;

        auto start2 = high_resolution_clock::now();
        sort(Group.begin(), Group.end(), Compare);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout << "File " << k << ".txt sorted by grade: " << fixed << setprecision(4) << duration2.count() / 1000000.0 << " seconds" << endl;
        cout << endl;

        if (str == 1)
        {
            cout << "Strategy 1:" << endl;
            auto start3 = high_resolution_clock::now();
            TwoGroups();
            auto stop3 = high_resolution_clock::now();
            auto duration3 = duration_cast<microseconds>(stop3 - start3);
            cout << "File " << k << ".txt sorted into smart and stupid in: " << fixed << setprecision(4) << duration3.count() / 1000000.0 << " seconds" << endl;
            cout << endl;
        }
        else if (str == 2)
        {
            cout << "Strategy 2:" << endl;
            auto start4 = high_resolution_clock::now();
            OneNewGroup();
            auto stop4 = high_resolution_clock::now();
            auto duration4 = duration_cast<microseconds>(stop4 - start4);
            cout << "File " << k << ".txt sorted into stupid in: " << fixed << setprecision(4) << duration4.count() / 1000000.0 << " seconds" << endl;
        }

        Group.clear();

        cout << endl;
        cout << "====================================================================================================" << endl;

        k = k * 10;
    }
}