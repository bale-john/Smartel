#ifndef ROW_H
#define ROW_H
#include<string>
using namespace std;

class Row{
public:
	Row(string k, int t, int v):key(k), times(t), value(v) {};
	string getKey();
	int getTimes();
	int getValue();
private:
	string key;
	int times;
	int value;
};
#endif
