#include<string>
#include<iostream>
#include"./csv_parser/csv_reader.h"
#include"./csv_parser/csv_writer.h"
using namespace std;

int main(int argc, char** argv) {
	ifstream icin;
	icin.open("../files/HOTEL_SALES.csv");
	vector<string> result = {"start"};
	CSVReader input(icin);
	vector<vector<string>> output;
	while (!result.empty()){
		input.read_next(result);
		output.push_back(result);
	}
	icin.close();
	ofstream icout;
	icout.open("../output/result.csv");
	CSVWriter mywriter(icout);
	mywriter.write_all(output);
	icout.close();
	return 0;
}




