#include<string>
#include<iostream>
#include"./csv_parser/csv_reader.h"
#include"./csv_parser/csv_writer.h"
#include"priceRecommendation.h"
#include"buildCreditSystem.h"
using namespace std;

void codeInformation(){
	cout << "************************************" << endl;
	cout << "Please choose what you want to do:" <<endl;
	cout << "(1).Prise analysis" << endl;
	cout << "(2).Build customer credit system" << endl;
	cout << "(0).Quit" << endl;
	cout << "************************************" << endl;
	return;
}

void welcome(){
	cout << "welcome to Smartel!" << endl;
	codeInformation();
	return;
}

int main(int argc, char** argv) {
	welcome(); 
	int code = 0;
	cin >> code;
	if (code < 0 || code >2){
		cout << "wrong input" << endl;
		cin >> code;
	}
	while (code != 0){
		if (code == 1){
			priceRecommendation();	
		}
		if (code == 2){
			buildCreditSystem();
		}
		codeInformation();
		cin >> code;
	}
	return 0;
}




