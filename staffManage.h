#ifndef STAFFMANAGE_H
#define STAFFMANAGE_H
#include<string>
using namespace std;
int login(string &un);
void processMessage(const string &username, int id);
void report(const string &username, int id);
int staffManage();
#endif