//
// Created by Will Lawerence on 4/23/22.
//
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Media
{
protected:
    string Type;
    string account;
    int runTimeSeconds;

public:
    Media(){Type = ""; account = ""; runTimeSeconds = 0;}
    Media(string id, string acc, int runTimeSeconds);
    void SetType(string id) {Type = id;}
    void SetAccount(string acc) {account = acc;}
    void SetRunTime(int time) {runTimeSeconds = time;}
    string GetType() {return Type;}
    string GetAccount() {return account;}
    int GetRunTime() {return runTimeSeconds;}
    virtual void ReadData(istream& fin);
    virtual void WriteData(ostream& fout);

};

class Audio :public Media
{
private:
    string formatDescriptor;
    string quality;
public:
    Audio(){Type = ""; account = ""; runTimeSeconds = 0; formatDescriptor=""; quality="";}
    Audio(string id, string acc, int time, string format, string qlty) {Media(id, acc, time); formatDescriptor = format; quality = qlty; }
    void ReadData(istream& fin);
    void WriteData(ostream& fout);
    string GetType() {return "Audio";}

};

class Video : public Media
{
private:
    string res;
    string formatDescriptor;
    string quality;
public:
    Video(){Type = ""; account = ""; runTimeSeconds = 0; formatDescriptor=""; quality="";}
    Video(string id, string acc, int time, string resolution, string format, string qlty) {Media(id, acc, time); res = resolution; formatDescriptor = format; res = resolution;}
    void ReadData(istream& fin);
    void WriteData(ostream& fout);
    string GetType() {return "Video";}
};
