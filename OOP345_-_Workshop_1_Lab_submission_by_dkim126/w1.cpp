//Doyeon Kim
//139766166
//2019/01/17
#include <iostream>
#include "String.h"
#include "process.h"

using namespace std;
using namespace sict;

int main(int argc, char *argv[]) {
	int i;
	
	cout << "Command Line : ";
	for (i = 0; i < argc; i++){
		cout << argv[i] << " ";
		}
	cout << endl;
	
	if (argc > 1){
		for (i = 1; i < argc; i++){
			process(argv[i]);
			
		}
		
	}
	else{
		cout << endl << "***Insufficient number of arguments***" << endl;
		return 1;
	}

	return 0;
}




