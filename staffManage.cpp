#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include"./csv_parser/csv_reader.h"
#include"./csv_parser/csv_writer.h"
#include"outputToFile.h"
using namespace std;

//login module
int login(string &un){
	cout << "please input your user name" << endl;
	string username = "";
	cin >> username;
	cout << "please input your password" << endl;
	string password = "";
	cin >> password;
	
	ifstream manager;
	manager.open("../files/MANAGER_PASS.csv");
	vector<string> managerResult; 
	CSVReader managerReader(manager);
	managerReader.read_next(managerResult);
	if (username == managerResult[0] && password == managerResult[1]){
		un = username;
		return 0;
	}

	ifstream staff;
	staff.open("../files/STAFF_PASS.csv");
	vector<string> staffResult;
	CSVReader staffReader(staff);
	staffReader.read_next(staffResult);
	if (username == staffResult[0] && password == staffResult[1]){
		un = username;
		return 1;
	}
	return -1;

}

void processMessage(const string &username, int id){
	cout << "welcome, " << username << endl;
	ifstream message;
	string file = "";
	if (id == 0){
		file = "../output/toHR.csv";
	}
	if (id == 1){
		file = "../output/toStaff.csv";
	}
	message.open(file);
	CSVReader myReader(message);
	vector<string> result;
	myReader.read_next(result);
	string reply = "no";
	if (!result.empty()){
		string otherUser = "";
		otherUser = ((id == 0) ? "Mike" : "Bale");
		cout << "you have a message from " << otherUser << ": " << endl;
		cout << result[0] << endl;
		cout << "want to reply? yes or no" << endl;
		cin >> reply;
	}
	if (reply == "yes"){
		cout << "please enter your reply:" << endl;
		string content = "";
		getline(cin, content, '#');
		vector<vector<string>> output;
		output.push_back(vector<string>{content});
		string outputFile = "";
		if (id == 0){
			outputFile = "../output/toStaff.csv";
		}
		if (id == 1){
			outputFile = "../output/toHR.csv";
		}
		outputToFile(output, outputFile);
	}
	return;
}

void report(const string &username, int id){
	cout << "Do you have something to report? yes or no" << endl;
	string reply = "";
	cin >> reply;
	if (reply == "yes"){
		cout << "please enter your message" << endl;
		string content = "";
		getline(cin, content, '#');
		vector<vector<string>> output;
		output.push_back(vector<string>{content});
		string outputFile = "";
		if (id == 0){
			outputFile = "../output/toStaff.csv";
		}
		if (id == 1){
			outputFile = "../output/toHR.csv";
		}
		outputToFile(output, outputFile);
	}
	return;
}

int staffManage(){
	int id = -1;
	string username = "";
	id = login(username);
	if (id == -1){
		cout << "illegal username or password" << endl;
		return -1;
	}
	processMessage(username, id);
	report(username, id);
	return id;
}