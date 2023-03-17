
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