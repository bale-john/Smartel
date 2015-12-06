#include<vector>
#include<string>
#include<fstream>
#include"./csv_parser/csv_reader.h"
#include"./csv_parser/csv_writer.h"
#include"outputToFile.h"
using namespace std;

void outputToFile(const vector<vector<string>> &output, const string path){
	ofstream ocout;
	ocout.open(path);
	CSVWriter mywriter(ocout);
	mywriter.write_all(output);
	ocout.close();
	return;
}