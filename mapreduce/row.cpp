#include"row.h"
#include<stdlib.h>
#include<string>

std::string Row::getKey(){
	return key;
}

int Row::getTimes(){
	return times;
}

int Row::getValue(){
	return value;
}