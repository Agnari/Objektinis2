#include "./headers/Mylib.h"
#include "./headers/Student.h"
#include "./functions.cpp"

int main()
{
    // Options-------------------------------------------------
    int answ = 0;
    cout << "Choose option (1-2):" << endl;
    cout << "1. Generate new files for work." << endl;
    cout << "2. Work with existing files." << endl;
    cin >> answ;
    while (answ != 1 && answ != 2 && answ != 3 && answ != 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "There is no such answer." << endl;
        cout << "----------------------------------------" << endl;
        cout << "Choose option (1-3):" << endl;
        cout << "1. Generate new files for work." << endl;
        cout << "2. Work with existing files." << endl;
        cin >> answ;
    };

    // New files-----------------------------------------------
    if (answ == 1)
    {
        int f = 1000;
        for (int i = 0; i < 2; i++)
        {
            GenerateFileData(f);
            f = f * 10;
            cout << "." << endl;
        }
    }

    int k = 1000;
    for (int i = 0; i < 2; i++)
    {
        auto start1 = high_resolution_clock::now();
        Read(k, Group);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        cout << "File " << k << ".txt read in: " << fixed << setprecision(4) << duration1.count() / 1000000.0 << " seconds" << endl;
        cout << endl;

        auto start2 = high_resolution_clock::now();
        sort(Group.begin(), Group.end());
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout << "File " << k << ".txt sorted by grade: " << fixed << setprecision(7) << duration2.count() / 1000000.0 << " seconds" << endl;
        cout << endl;

        auto start4 = high_resolution_clock::now();
        OneNewGroup(Group, Stupid);
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(stop4 - start4);
        cout << "File " << k << ".txt sorted into stupid in: " << fixed << setprecision(4) << duration4.count() / 1000000.0 << " seconds" << endl;

        if(i == 0){
            NewStupidSmartTxt();
        }
        else{
            StupidSmartTxt();
        }

        Group.clear();

        cout << endl;
        cout << "====================================================================================================" << endl;

        k = k * 10;
    }
}