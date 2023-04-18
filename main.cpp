#include "./headers/Mylib.h"
#include "./headers/Student.h"
#include "./headers/Answers.h"
#include "./main_functions.cpp"

int main()
{
	try
	{
		Settings();

		if (answ.datatype == 1) // Uses user interface
		{
			Datatype1();
		}
		else if (answ.datatype == 2) // Reads created file "kursiokai.txt"
		{
			Datatype2();
		}
		else if (answ.datatype == 3) // Generates and sorts 5 files into two groups smart/stupid
		{
			auto start = high_resolution_clock::now();
			Datatype3();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Program duration: " << fixed << setprecision(4) << duration.count() / 1000000.0 << " seconds" << endl;
		}
		else if(answ.datatype == 4)
		{
			int k = 1000;
			for (int i = 0; i < 5; i++)
			{
				GenerateFileData(k);
				k = k * 10;
				cout << "..." << endl;
			}
		}
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}
