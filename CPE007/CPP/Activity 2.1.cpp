#include <iostream>
using namespace std;

int main(void)
{
int xValue=5;
int yValue=9;
int result;
int bigResult;
	
xValue += 3;
yValue -= xValue;
result = xValue * yValue;
result += result;
result--;
yValue = result % result;
result += result + xValue;
bigResult = result * result * result;
result += xValue * yValue;
	
cout<<"result: "<<result<<endl;
cout<<"big result: "<< bigResult;

return 0;
}
