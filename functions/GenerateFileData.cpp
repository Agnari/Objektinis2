
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