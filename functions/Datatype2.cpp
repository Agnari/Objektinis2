
void Datatype2()
{
    string filename = "kursiokai.txt";
    GatherFileData(filename);
    sort(Group.begin(), Group.end(), Compare);
    Coutput();
    Group.clear();
}