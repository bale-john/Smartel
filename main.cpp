#include<string>
#include<iostream>
#include"./csv_parser/csv_reader.h"
#include"./csv_parser/csv_writer.h"
#include"priceRecommendation.h"
#include"buildCreditSystem.h"
using namespace std;

int main(int argc, char** argv) {
	priceRecommendation();
	buildCreditSystem();
	return 0;
}




