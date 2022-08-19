//============================================================================
// Name        : SA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <boost/regex.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Bayes.h"
#include <cmath>
#include <iomanip>
#include <limits>


int main(int argc, char const *argv[]) {
	char path[100];
	bool unlabeled;
	if (argc == 2){
		unlabeled = true;
		strcpy_s(path, "outBayes.csv");
	} else {
		unlabeled = false;
		strcpy_s(path, "OnlyBayes.csv");
	}
	

	Bayes myBayes(unlabeled);
	puts("I'm done learning");
	std::vector<long double>* preds = myBayes.Predicciones();
	puts("Label Completed");

	std::ofstream myfile (path, std::ofstream::trunc);
	if (!myfile) {
		fprintf(stderr,"Failed to open \n");
	}

	myfile << "\"id\",\"sentiment\"";
	myfile << "\n";

	std::vector<std::string> ids = myBayes.ids;
		for (unsigned int i = 0; i < ids.size(); i++){
		myfile << ids[i];
		if (unlabeled){
			myfile << "\t";
		} else {
			myfile << ",";
		}
		myfile << std::fixed << std::setprecision(53) << (*preds)[i];
		if (unlabeled){
			myfile << "\t";
			myfile << myBayes.rows[i][1];
		}
		myfile << "\n";
		//std::cout << std::fixed << std::cout.precision(190) << preds[i] << std::endl;
	}

	myfile.close();

	return 0;
	
}
