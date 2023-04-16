
void CalcData(Student &temp)
{
	float avg = 0;
	if (temp.grades.size() != 0)
	{ 
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
	} 

	temp.finalA = (float)(0.4 * avg) + (float)(0.6 * temp.exam);

	float median = 0;
	if (temp.grades.size() != 0)
	{
		sort(temp.grades.begin(), temp.grades.end());
		if (temp.grades.size() % 2 == 0)
		{
			median = (float)((temp.grades[temp.grades.size() / 2] + temp.grades[temp.grades.size() / 2 - 1]) / 2.0);
		}
		else
		{
			median = (float)(temp.grades[temp.grades.size() / 2]);
		};
	}
	else
		(median = 0);

	temp.finalM = (float)((0.4 * median) + (0.6 * temp.exam));
}
