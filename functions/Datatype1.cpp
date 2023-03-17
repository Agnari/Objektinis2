
void Datatype1()
{
    do
    {
        GatherUserData(temp);
        Group.push_back(temp);
        temp.exam = NULL;
        temp.grades.clear();

        cout << "Add new student? (y/n)" << endl;
        cin >> answ.answer;
        while ((answ.answer != 'y' && answ.answer != 'Y') && (answ.answer != 'n' && answ.answer != 'N'))
        {
            cout << "There is no such answer. Y/y - add student, N/n - continue." << endl;
            cin >> answ.answer;
        };
    } while (answ.answer == 'y' || answ.answer == 'Y');
    sort(Group.begin(), Group.end(), Compare);
    Coutput();
    Group.clear();
}