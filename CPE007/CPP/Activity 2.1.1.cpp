#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
float startValue = 100;
float interestRate = 0.015;
float firstYearValue;
float secondYearValue;
float thirdYearValue;


firstYearValue = startValue + (startValue * interestRate);
secondYearValue = firstYearValue + (firstYearValue * interestRate); 
thirdYearValue = secondYearValue + (firstYearValue * interestRate);

cout<< fixed << setprecision(6);
cout<<"After first year: "<<firstYearValue<<endl;
cout<<"After second year: "<<secondYearValue<<endl; 
cout<<"After third year: "<<thirdYearValue;

return 0;
}
