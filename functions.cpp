/**
 * @file functions.cpp
 * @author Agnari
 * @brief
 * @date 2023-05-10
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 *@brief Fills a Student struct with information from a string stream and adds it to a vector of Student structs.
 *@param line A reference to an istringstream object containing the information to fill the Student struct.
 *@param Group A reference to a vector of Student structs to add the filled Student struct to.
 *@param grades A reference to a vector of integers to store the homework grades of the Student struct.
 *@throws std::string An exception is thrown if the exam grade is not within the range [1, 10] or if the homework grades are not in the correct format.
 */

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

/**
*@brief Reads student information from a file and stores it in a vector of Student objects.
*@param k The identifier of the file to be read.
*@param Group A reference to the vector of Student objects where the information will be stored.
*@return void
        This function reads the student information from a file with the given identifier and stores it in a vector of Student objects.
        The file should be in the format where the first line contains the header and the subsequent lines contain the data.
        Each line of data should contain the student's name, ID number, and a list of grades separated by whitespace.
        Example usage:
        vector<Student> group;
        int k = 1;
        Read(k, group);
*/

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

/**
*@brief Fills a buffer with a student's name, surname, grades, and exam score.
        This function generates a student's name and surname by concatenating "Name"
        and "Surname" with a given integer index. It also generates 10 random grades
        between 1 and 10, and a random exam score between 1 and 10. The resulting
        string is formatted and stored in the provided buffer.
*@param i The integer index used to generate the student's name and surname.
*@param BUFFER_SIZE The size of the buffer provided to store the resulting string.
*@param buffer The buffer to store the resulting string.
*/

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

/**
 *@brief Generates data file with student information
 *@param f Number of students to generate
 */

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

/**
*@brief This function takes a vector of Student objects as input and separates them into two groups:
        a group of students with final grades less than 5, and a group of students with final grades greater
        than or equal to 5. The first group is moved to a new vector called Stupid, and the second group
        remains in the original vector called Group.
*@param[in,out] Group A vector of Student objects containing all the students.
*@param[out] Stupid A vector of Student objects to which the "stupid" students are moved.
*@details This function uses a lambda function called is_stupid to check whether a given student's final grade
          is less than 5. It then uses the partition algorithm from the STL to separate the students into two
          groups: those that satisfy the is_stupid condition and those that do not. The "stupid" students are
          moved to a new vector called new_stupid using move iterators, and then inserted into the Stupid vector
          using the insert function from the STL. Finally, the function erases the original "stupid" students
          from the Group vector using the erase function from the STL.
*/

void OneNewGroup(vector<Student> &Group, vector<Student> &Stupid)
{
    auto is_stupid = [](const Student &s)
    {
        return s.getFinalA() < 5;
    };

    auto middle = partition(Group.begin(), Group.end(), is_stupid);

    vector<Student> new_stupid(make_move_iterator(Group.begin()), make_move_iterator(middle));
    Stupid.insert(Stupid.end(), make_move_iterator(new_stupid.begin()), make_move_iterator(new_stupid.end()));

    Group.erase(Group.begin(), middle);
}

/**
*@brief Creates two text files, "stupid.txt" and "smart.txt", with student data in table format.
        This function takes a vector of Student objects and outputs their data in table format to two text files.
        The "stupid.txt" file is sorted by the order in which the students were read, while the "smart.txt" file is sorted
        by the average final grade of each student, from highest to lowest. Each line in the table contains the student's
        name, surname, and final grades (both average and median).
*@param Group A vector of Student objects to be output to the text files.
*/

void NewStupidSmartTxt()
{
    stringstream stupid(stringstream::out | stringstream::binary);
    stringstream smart(stringstream::out | stringstream::binary);
    //------------------------------------------HEADERS---------------------------------------------------------------------------------------------------
    stupid << left << setw(20) << "Name" << left << setw(20) << "Surname" << left << setw(15) << "Final(avg)" << left << setw(15) << "Final(med)" << endl;
    stupid << "-------------------------------------------------------------------" << endl;

    smart << left << setw(20) << "Name" << left << setw(20) << "Surname" << left << setw(15) << "Final(avg)" << left << setw(15) << "Final(med)" << endl;
    smart << "-------------------------------------------------------------------" << endl;
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    for (const auto &student : Group)
    {
        smart << left << setw(20) << student.name << left << setw(20) << student.surname << left << setw(15) << student.finalA << left << setw(15) << student.finalM << endl;
    }
    for (const auto &student : Stupid)
    {
        stupid << left << setw(20) << student.name << left << setw(20) << student.surname << left << setw(15) << student.finalA << left << setw(15) << student.finalM << endl;
    }

    ofstream txtFile;
    txtFile.open("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis2\\data\\stupid.txt", ofstream::binary);
    txtFile.write(stupid.str().c_str(), stupid.str().length());
    txtFile.close();

    txtFile.open("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis2\\data\\smart.txt", ofstream::binary);
    txtFile.write(smart.str().c_str(), smart.str().length());
    txtFile.close();
}

/**
*@brief Writes the student data to two text files, one for the smart group and one for the stupid group.
        This function takes the data from a vector of students and writes it to two text files, one for the smart group
        and one for the stupid group. The student data is formatted using iomanip and written to stringstream objects
        before being written to the text files using ofstream. The location of the text files are hardcoded and need
        to be changed manually if the files need to be saved to a different location.
*@param Group The vector of students to write to the smart group file.
*@param Stupid The vector of students to write to the stupid group file.
*/

void StupidSmartTxt()
{
    stringstream stupid(stringstream::out | stringstream::binary);
    stringstream smart(stringstream::out | stringstream::binary);

    for (const auto &student : Group)
    {
        smart << left << setw(20) << student.name << left << setw(20) << student.surname << left << setw(15) << student.finalA << left << setw(15) << student.finalM << endl;
    }
    for (const auto &student : Stupid)
    {
        stupid << left << setw(20) << student.name << left << setw(20) << student.surname << left << setw(15) << student.finalA << left << setw(15) << student.finalM << endl;
    }

    ofstream txtFile;
    txtFile.open("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis2\\data\\stupid.txt", ofstream::binary);
    txtFile.write(stupid.str().c_str(), stupid.str().length());
    txtFile.close();

    txtFile.open("C:\\Users\\Home\\OneDrive\\Documents\\GitHub\\Objektinis2\\data\\smart.txt", ofstream::binary);
    txtFile.write(smart.str().c_str(), smart.str().length());
    txtFile.close();
}
