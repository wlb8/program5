//
// Created by Will Lawerence on 4/23/22.
//
#include "Media.h"
#include <iostream>
#include <fstream>
#include <string>

void Media::ReadData(istream &fin)
{
    fin >> Type >> account >> runTimeSeconds;
}

void Media::WriteData(ostream &fout)
{
    fout << account << endl;
}

Media::Media(string id, string acc, int time)
{
    Type = id;
    account = acc;
    runTimeSeconds = time;
}

void Audio::ReadData(istream& fin)
{
    ReadData(fin);
    getline(fin, formatDescriptor);
    getline(fin, quality);
}

void Audio::WriteData(ostream& fout)
{
    WriteData(fout);
    fout << formatDescriptor << endl;
    fout << quality << endl;
}

void Video::ReadData(istream &fin)
{
    ReadData(fin);
    getline(fin, formatDescriptor);
    getline(fin, quality);
}

void Video::WriteData(ostream &fout)
{
    WriteData(fout);
    fout << formatDescriptor << endl;
    fout << quality << endl;
}
