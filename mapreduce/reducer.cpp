#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include"row.h"
#include"../csv_parser/csv_reader.h"
#include"../csv_parser/csv_writer.h"
using namespace std;

//compare function for sort
bool mycompare(shared_ptr<Row> i, shared_ptr<Row> j){
	if (i->getValue() > j->getValue()){
		return true;
	}
	else {
		return false;
	}
}

void outputToFile(const vector<vector<string>> &output){
	ofstream ocout;
	ocout.open("../../output/result_MapReduce.csv");
	CSVWriter mywriter(ocout);
	mywriter.write_all(output);
	ocout.close();
	return;
}

string itoa(int number){
	stringstream ss;
	ss << number;
	return ss.str();
}

int main(){
	string key = "", newKey = "", sValue = "";
	int times = 0;
	int value = 0;
	string line = "";
	vector<shared_ptr<Row>> myrow;
	//compute all people's consumption
	while (getline(cin, line)){
		istringstream record(line);
		record >> newKey;
		if (newKey != key){
			if (!key.empty()){
				shared_ptr<Row> r(new Row(key, times, value));
				myrow.push_back(r);
//				cout << key << "\t" << times << "\t" << value << endl;
			}
			key = newKey;
			times = 1;
			record >> sValue; 
			value = atoi(&sValue[0]);
		}
		else {
			times++;
			record >> sValue;
			value += atoi(&sValue[0]);
		}

	}
	shared_ptr<Row> r(new Row(key, times, value));
	myrow.push_back(r);
	sort(myrow.begin(), myrow.end(), mycompare);
	vector<vector<string>> output;
	vector<shared_ptr<Row>>::iterator it;
	cout << "names" << "\t" << "times" << "\t" << "amount" << endl;
	output.push_back(vector<string>{"Name", "Times", "Amounts"});
	for (it = myrow.begin(); it != myrow.end(); it++){
		cout << (*it)->getKey() << "\t" << (*it)->getTimes() << "\t" << (*it)->getValue() << endl;
		output.push_back({(*it)->getKey(), itoa((*it)->getTimes()), itoa((*it)->getValue())});
	}
	outputToFile(output);
	return 0;
}
