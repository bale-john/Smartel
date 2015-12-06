#!/bin/bash

g++ main.cpp priceRecommendation.cpp buildCreditSystem.cpp outputToFile.cpp\
	./csv_parser/csv_reader.cpp ./csv_parser/csv_writer.cpp staffManage.cpp -std=c++11\
	-o main

