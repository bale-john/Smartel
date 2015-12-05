#!/bin/bash

g++ mapper.cpp ../csv_parser/csv_reader.cpp -o mapper -std=c++11

g++ reducer.cpp ../csv_parser/csv_writer.cpp row.cpp -o reducer -std=c++11


