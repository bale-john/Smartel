#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include"../csv_parser/csv_reader.h"
#include"../csv_parser/csv_writer.h"
using namespace std;

int main(){
	string key;
	string value;
	ifstream filenames;
	filenames.open("customerBehaviorFiles");
	string filename = "";
	//process all files
	while (getline(filenames, filename)){
		filename = "./data/" + filename;
		ifstream icin;
		icin.open(filename);
		CSVReader myreader(icin);
		vector<string> result;
		myreader.read_next(result);
		//find the data we need and emit it
		while (!result.empty()){
			myreader.read_next(result);
			key = result[0]; 
			value = result[2]; 
			cout << key << "\t" << value << endl;
		}
		icin.close();
	}
	filenames.close();
	return 0;
}
