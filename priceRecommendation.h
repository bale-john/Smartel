#ifndef PRICERECOMMENDATION_H
#define PRICERECOMMENDATION_H
#include<vector>
#include<map>
#include<string>
using namespace std;

void getHistoryData(vector<pair<int, int>> &priceQuantity, map<int, int> &pr);
double getElasticity(int currentPrice, map<int, int> &pr);
pair<int, int> getMax(const vector<pair<int, int>> &priceQuantity, map<int, int> &pr);
void interactive(vector<vector<string>> &output, const vector<pair<int, int>> &priceQuantity, map<int, int> &pr, int maxprice, int maxrevenue);
void outputToFile(const vector<vector<string>> &output);
int priceRecommendation();
#endif