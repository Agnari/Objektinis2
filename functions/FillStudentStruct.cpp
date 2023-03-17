
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

