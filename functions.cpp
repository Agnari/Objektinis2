void FillStudentStruct(istringstream &line, vector<Student> &Group, vector<int> &grades)
{
    string name, surname;
    int exam;

    line >> name >> surname;

    int grade;
    for (int j = 0; j < 10; j++)
    {
        line >> grade;
        if (grade >= 1 && grade <= 10)
        {
            grades.push_back(grade);
        }
        else
        {
            throw "Bad data format in file";
        }
    }

    line >> exam;
    if (exam >= 1 && exam <= 10)
    {
        Student student(name, surname, grades, exam);
        Group.push_back(student);
    }
    else
    {
        throw "Data in file must contain name, surname, homework grades and exam grade. Please, check your file.";
    }
}

void Read(int k, vector<Student> &Group)
{

    string filename = "C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis2\\data\\" + to_string(k) + ".txt";
    string header;
    ifstream readf(filename);
    getline(readf, header);
    string line;

    vector<int> grades;
    while (getline(readf, line))
    {
        istringstream x(line);
        FillStudentStruct(x, Group, grades);
        grades.clear();
    }

    readf.close();
}

void BufferData(int i, const int BUFFER_SIZE, char *buffer)
{
    string name = "Name" + to_string(i + 1);
    string surname = "Surname" + to_string(i + 1);

    vector<int> grades;
    for (int j = 0; j < 10; j++)
    {
        grades.push_back((rand() % 10) + 1);
    }

    int exam = (rand() % 10) + 1;

    snprintf(buffer, BUFFER_SIZE, "%-20s%-20s", name.c_str(), surname.c_str());
    for (int grade : grades)
    {
        snprintf(buffer + strlen(buffer), BUFFER_SIZE - strlen(buffer), "%-15d", grade);
    }
    snprintf(buffer + strlen(buffer), BUFFER_SIZE - strlen(buffer), "%-15d\n", exam);
}

void GenerateFileData(int f)
{
    srand(static_cast<unsigned int>(time(NULL)));

    // Open file for writing
    ofstream newFile("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis2\\data\\" + to_string(f) + ".txt");

    //--------------------------------HEADER-------------------------------------
    newFile << left << setw(20) << "NAME" << left << setw(20) << "SURNAME";
    for (int i = 0; i < 10; i++)
    {
        newFile << left << setw(15) << "HW" + to_string(i);
    }
    newFile << left << setw(15) << "EXAM" << endl;
    //---------------------------------------------------------------------------

    // Define buffer size
    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];

    // Generate students and write to file using buffer
    for (int i = 0; i < f; i++)
    {
        BufferData(i, BUFFER_SIZE, buffer);

        // Write buffer to file
        newFile << buffer;
    }

    // Close file
    newFile.close();
}

void OneNewGroup(vector<Student> &Group, vector<Student> &Stupid)
{
    auto is_stupid = [](const Student &s)
    { return s.finalA < 5; };
    auto middle = partition(Group.begin(), Group.end(), is_stupid);

    vector<Student> new_stupid(Group.begin(), middle);
    Stupid.insert(Stupid.end(), new_stupid.begin(), new_stupid.end());

    Group.erase(Group.begin(), middle);
}
