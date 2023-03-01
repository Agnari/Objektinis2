
void CalcData(Student &temp)
{
	// Calculates final grade with average result
	float avg = 0;
	if (temp.grades.size() != 0)
	{ // checks if there are values in "grades"
		float sum = 0;
		for (int i = 0; i < temp.grades.size(); i++)
		{
			sum += temp.grades[i];
		}
		avg = (float)sum / temp.grades.size();
	}
	else
	{
		avg = 0;
	} // if there are no grades, average is equal 0

	temp.finalA = (float)(0.4 * avg) + (0.6 * temp.exam);

	// Calculates final grade with median result
	float median = 0;
	if (temp.grades.size() != 0)
	{ // checks if there are values in "grades"
		sort(temp.grades.begin(), temp.grades.end());
		if (temp.grades.size() % 2 == 0)
		{
			median = (float)(temp.grades[temp.grades.size() / 2] + temp.grades[temp.grades.size() / 2 - 1]) / 2.0;
		}
		else
		{
			median = temp.grades[temp.grades.size() / 2];
		};
	}
	else
		(median = 0); // if there are no grades, median is equal 0

	temp.finalM = (0.4 * median) + (0.6 * temp.exam);
}
