
#include <iostream> 
using namespace std;
int main() {
	int total = 0;
	int gradecounter = 1; int grade;
	double classaverage;
	
	while (gradecounter <= 10) {
		cout << "Enter grade " << gradecounter << ": ";
		cin >> grade;
		if (grade < 0 || grade > 100) {
			cout << "Invalid grade! Please enter a value between 0 and 100." << endl; 
			continue;
		}

		total += grade;
		gradecounter++;
	}
	classaverage = total / 10.0;
	
	cout<<"\nClass average:" << classaverage << endl;
	
	return 0;
}
