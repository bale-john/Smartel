#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<iomanip>
#include"./csv_parser/csv_reader.h"
#include"./csv_parser/csv_writer.h"
using namespace std;

//get history data
void getHistoryData(vector<pair<int, int>> &priceQuantity, map<int, int> &pr){
	ifstream icin;
	icin.open("../files/HOTEL_SALES.csv");
	vector<string> result;
	CSVReader myreader(icin);
	string price = "";
	string quantity = "";
	int p = 0, q = 0, tr = 0;
	myreader.read_next(result);
	cout << "choose the type of room: 1.Single\t2.Double\t3.Triple" << endl;
	int type = 0;
	cin >> type;
	if (type > 3 || type < 1){
		cout << "wrong input" << endl;
		return;
	}
	vector<string> roomType = {"Single", "Double", "Triple"};
	while (!result.empty()){
		myreader.read_next(result);
		if (result.size() >= 2 && roomType[type-1] != result[2]){
			continue;
		}
		price = result[0];
		p = atoi(&(price[0]));
		quantity = result[1];
		q = atoi(&(quantity[0]));
		tr = p*q;
		priceQuantity.push_back(make_pair(p, q));
		pr[p] = tr;
	}
	icin.close();
	return;
}

//computer the elasticity in the price elasticity of demand.
double getElasticity(int currentPrice, map<int, int> &pr){
	double elasticity = 0;
	int pre = currentPrice;
	int nex = currentPrice;
	while (pr.find(pre) != pr.end() && (pr[pre] / pre) == pr[currentPrice] / currentPrice){
		pre--;
	}
	while (pr.find(nex) != pr.end() && (pr[nex] / nex) == (pr[currentPrice] / currentPrice)){
		nex++;
	}
	double deltaQuantity = 0;
	double deltaPrice = 0;
	/*
	if (pr.find(nex) != pr.end()){
		deltaQuantity = (double)(pr[nex] / nex - pr[currentPrice] / currentPrice) / (pr[currentPrice] / currentPrice);
		deltaPrice = (double)(nex - currentPrice) / currentPrice;
	}
	else {
		deltaQuantity = (double)(pr[currentPrice] / currentPrice - pr[pre] / pre) / (pr[pre] / pre);
		deltaPrice = (double)(currentPrice - pre) / pre;
	}
	*/
	deltaQuantity = (double)(pr[nex] / nex - pr[pre] / pre) / (pr[currentPrice] / currentPrice);
	deltaPrice = (double)(nex - pre) / currentPrice;
	return -deltaQuantity / deltaPrice;
}

//get the maxprice and maxrevenue
pair<int, int> getMax(const vector<pair<int, int>> &priceQuantity, map<int, int> &pr){
	//get the relationship between price and quantity
	for (int i = 1; i < priceQuantity.size(); ++i){
		double k = ((double)(priceQuantity[i].second - priceQuantity[i-1].second)) / (priceQuantity[i].first - priceQuantity[i-1].first);
		double b = priceQuantity[i].second - (double)k * (priceQuantity[i].first);
		for (int num = priceQuantity[i-1].first + 1; num < priceQuantity[i].first; ++num){
			pr[num] = num * (k * num + b);
		}
	}
	//get the maxprice and max revenue
	int maxrevenue = 0;
	int maxprice = 0;
	for (map<int, int>::iterator it = pr.begin(); it != pr.end(); it++){
		if (it->second > maxrevenue){
			maxrevenue = it->second;
			maxprice = it->first;
		}
	}
	return make_pair(maxprice, maxrevenue);
}

//recommend the price and tell out the reason
void interactive(vector<vector<string>> &output, const vector<pair<int, int>> &priceQuantity, map<int, int> &pr, int maxprice, int maxrevenue){
	cout << "input current price from " << priceQuantity[0].first << " to " << priceQuantity[priceQuantity.size()-1].first << endl;
	int currentPrice = 0;
	cin >> currentPrice;
	double elasticity = getElasticity(currentPrice, pr);
	ostringstream oss;
	cout << "Current price: " << currentPrice <<" The elasticity: " << setprecision(2) << elasticity << endl;
	oss << "Current price: " << currentPrice <<" The elasticity: " << setprecision(2) << elasticity;
	output.push_back(vector<string>{oss.str()});
	oss.str("");
	if (elasticity > 1) {
		cout << "The demand is elastic and the price should be cut" << endl;
		output.push_back(vector<string>{"The demand is elastic and the price should be cut"});
	}
	else if (elasticity < 1) {
		cout << "The demand lack of elasticity and the price should be raised" << endl;
		output.push_back(vector<string>{"The demand lack of elasticity and the price should be raised"});
	}
	else {
		cout << "The demand neither elastic nor lack of elasticity and the price should be kept" << endl;
		output.push_back(vector<string>{"The demand neither elastic nor lack of elasticity and the price should be kept"});
	}
	cout << "recommened price: " << maxprice << endl;
	oss << "recommened price: " << maxprice;
	output.push_back(vector<string>{oss.str()});
	oss.str("");
	cout << "predicted revenue: " << maxrevenue << endl;
	oss << "predicted revenue: " << maxrevenue;
	output.push_back(vector<string>{oss.str()});
	oss.str("");
	return;
}

//write to the result.csv
void outputToFile(const vector<vector<string>> &output){
	ofstream ocout;
	ocout.open("../output/result.csv");
	CSVWriter mywriter(ocout);
	mywriter.write_all(output);
	ocout.close();
	return;
}

int main(int argc, char** argv){
	//store the price and quantity
	vector<pair<int, int>> priceQuantity;
	//store price and revenue
	map<int, int> pr;
	getHistoryData(priceQuantity, pr);
	sort(priceQuantity.begin(), priceQuantity.end());
	pair<int, int> mymax = getMax(priceQuantity, pr);
	int maxprice = mymax.first;
	int maxrevenue = mymax.second;
	vector<vector<string>> output;
	interactive(output, priceQuantity, pr, maxprice, maxrevenue);
	outputToFile(output);
	return 0;
}
