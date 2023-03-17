
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