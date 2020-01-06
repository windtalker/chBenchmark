#include <iostream>
#include <fstream>
#include <sstream>
#include "DialectStrategy.h"
using namespace std;

int main(int argc, char* argv[]){
	Dialect *d = DialectStrategy::getInstance();
	std::vector<const char*>& queries = d->getTpchQueryStrings();
	ofstream outfile;
	for(int i = 0; i < queries.size(); i++)
	{
		stringstream ss;
		ss << "/tmp/tpcch/query" << (i+1) << ".sql";
		outfile.open(ss.str(), ios::out|ios::trunc);
		outfile<<queries[i] << ";";
		outfile.close();
	}
	return 0;
}
