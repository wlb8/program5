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
    int countAudio = 0;
    int countVideo = 0;

    fin.open("input.txt");
    fout.open("output.txt");

    if (!fin.open())
    {
        cout << "Bad";
    }

    while (!fin.eof)
    {
        fin >> type;
        if (type == 'A') {
            Audio *temp;
            temp->ReadData(fin);
            list[count] = temp;
            countAudio += 1;

        } else if (type == 'V') {
            Video *temp;
            temp->ReadData(fin);
            list[count] = temp;
            countVideo += 1;
        }
        count++;
    }
    fin.close();

    for (int i = 0; i < count; ++i)
    {
        if (list[i]->GetType() == "Audio")
        {
            list[i]->WriteData(fout);
        }
    }
    for (int i = 0; i < count; ++i)
    {
        if (list[i]->GetType() == "Video")
        {
            list[i]->WriteData(fout);
        }
    }
    fout.close();

    return 0;
}
