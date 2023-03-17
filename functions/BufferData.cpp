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