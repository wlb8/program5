#include <iostream>
#include "Media.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    Media* list[200];
    char type;
    string id;
    string account;
    int time;
    ifstream fin;
    ofstream fout;
    int count=0;

    fin.open("input.txt");
    fout.open("output.txt");

    while (fin.good())
    {
        fin >> type;
        if (type == 'A')
        {
            Audio* temp;
            temp->ReadData(fin);
            list[count] = temp;
            count += 1;

        }
        else if (type == 'V')
        {
            Video* temp;
            temp->ReadData(fin);
            list[count] = temp;
            count += 1;
        }

        for (int i = 0; i < 200; ++i)
        {
            cout << list[i]->GetAccount() << endl;
            cout << "HELLO";
            list[i]->WriteData(fout);
        }
    }
    fin.close();
    fout.close();


    return 0;
}
