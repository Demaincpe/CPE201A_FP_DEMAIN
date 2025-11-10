#include <iostream>
using namespace std;
struct Size {
    double length;
    double width;
};
int compute(const Size rectangle) {
    double area = rectangle.width * rectangle.length;
    double perimeter = 2 * (rectangle.width + rectangle.length);
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
}
int main() {
    Size myRectangle;
    cout << "Enter length of rectangle: ";
    cin >> myRectangle.length;
    cout << "Enter width of rectangle: ";
    cin >> myRectangle.width;
    compute(myRectangle);
    return 0;
}
