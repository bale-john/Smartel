#include<string>
#include<iostream>
#include<fstream>
#include<unordered_set>
#include<cstdlib>
#include"./csv_parser/csv_reader.h"
#include"./csv_parser/csv_writer.h"
#include"outputToFile.h"
using namespace std;


int buildCreditSystem(){
	ifstream icin;
	icin.open("../output/result_MapReduce.csv");
	vector<string> result;
	CSVReader myreader(icin);
	myreader.read_next(result);
	vector<vector<string>> output;
	cout << "set the minimum standard of VIP (amount of consumption):" << endl;
	int vip = 0;
	cin >> vip;
	cout << "set the minimum standard of attractive customer (average amount of each consumption):" << endl;
	int attractive = 0;
	cin >> attractive;
	while (!result.empty()){
		myreader.read_next(result);
		string name = result[0];
		int times = atoi(&result[1][0]);
		int amount = atoi(&result[2][0]);
		if (amount >= vip){
			cout << name << "\tVIP" << endl;
			output.push_back(vector<string>{name, "VIP"});
		}
		else if (amount / times >= attractive){
			cout << name << "\tattractive customer" << endl;
			output.push_back(vector<string>{name, "attractive customer"});
		}
		else {
			cout << name << "\tgeneral customer" << endl;
			output.push_back(vector<string>{name, "general customer"});
		}
	}
	cout << "want to set blacklist? yes or no?" << endl;
	string answer = "";
	cin >> answer;
	if (answer != "yes" && answer != "no"){
		cout << "wrong input" << endl;
	}
	else if (answer == "yes"){
		cout << "input the name you want to put into blacklist" << endl;
		cout << "enter (q) to quit" << endl;
		string blackName = "";
		unordered_set<string> blacklist;
		while (cin >> blackName){
			if (blackName == "q"){
				break;
			}
			blacklist.insert(blackName);
		}
		cout << "set blacklist...Done" << endl;
		for (int i = 0; i < output.size(); ++i){
			if (blacklist.find(output[i][0]) != blacklist.end()){
				output[i][1] = "blacklist";
			}
		}
		for (int i = 0; i < output.size(); ++i){
			cout << output[i][0] << "\t" << output[i][1] << endl;
		}
	}
	cout << "want the software deliver ads automatically? yes or no" << endl;
	string ads = "";
	cin >> ads;
	if (ads == "yes"){
		cout << "delivering ads...Done" << endl; 
	}
	outputToFile(output, "../output/creditSystem.csv");
	return 0;
}