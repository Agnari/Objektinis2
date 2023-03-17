void DataSort(Student &temp, stringstream &stupid, stringstream &smart)
{
    if (answ.finaltype == 'a' || answ.finaltype == 'A')
    {
        if (temp.finalA < 5)
        {
            stupid << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            stupid << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << "-----" << endl;
        }
        else
        {
            smart << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            smart << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << "-----" << endl;
        }
    }
    else if (answ.finaltype == 'm' || answ.finaltype == 'M')
    {
        if (temp.finalA < 5)
        {
            stupid << left << setw(20) << temp.name << left << setw(20) << temp.surname;
             smart << left << setw(15) << fixed << setprecision(2) << "-----" << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
        else
        {
            smart << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            smart << left << setw(15) << fixed << setprecision(2) << "-----" << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
    }
    else if (answ.finaltype == 'b' || answ.finaltype == 'B')
    {
        if (temp.finalA < 5)
        {
            stupid << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            stupid << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
        else
        {
            smart << left << setw(20) << temp.name << left << setw(20) << temp.surname;
            smart << left << setw(15) << fixed << setprecision(2) << temp.finalA << left << setw(15) << fixed << setprecision(2) << temp.finalM << endl;
        }
    }

}
