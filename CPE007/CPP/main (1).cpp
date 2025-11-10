#include <iostream>
using namespace std;

// Main Function
int calculator();
int fcconvert();
int pdconvert();

int main() {
    int choice;
    while (true) {
        cout << "MAIN MENU\n";
        cout << "1. Calculator\n";
        cout << "2. Fahrenheit-Celsius Converter\n";
        cout << "3. Peso-Dollar Converter\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                calculator();
                break;
            case 2:
                fcconvert();
                break;
            case 3:
                pdconvert();
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please select 1-4 only.\n";
        }
    }
}

// Functions
int calculator (){
    char oper;
    double a, b;

    // Input operator
    while (true) {
        cout << "Enter an operator (+, -, *, /): ";
        cin >> oper;

        if (oper == '+' || oper == '-' || oper == '*' || oper == '/')
            break;
        else
            cout << "Error! Operator is not correct. Please try again.\n";
    }

    // Input two numbers
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // switch case for processing operators
    switch (oper) {
        case '+':
            cout<<a<<" + "<<b<<" = "<<a+b<<endl;
            break;
        case '-':
            cout<<a<<" - "<<b<<" = "<<a-b<<endl;
            break;
        case '*':
            cout<<a<<" * "<<b<<" = "<<a*b<<endl;
            break;
        case '/':
            cout<<a<<" / "<<b<<" = "<<a/b<<endl;
            break;
    }
    return 0;
}

int fcconvert() {
    int num;
    double fahrenheit, celsius;
    while (true) {
        cout << "TEMPERATURE CONVERTER\n";
        cout << "1. Fahrenheit-Celsius\n";
        cout << "2. Celsius-Fahrenheit\n";
        cout << "Enter your choice (1-2): ";
        cin >> num;

        if (num == 1 || num == 2)
            break;
        else
            cout << "Invalid Choice. Please select 1-2 only.\n";
    }

    // switch case for converters
    switch (num) {
        case 1:
            cout<<"Enter fahrenheit: ";
            cin>>fahrenheit;
            cout<<"Celsius: "<<(fahrenheit-32)/1.8<<endl;
            break;
        case 2:
            cout<<"Enter celsius: ";
            cin>>celsius;
            cout<<"Fahrenheit: "<<(celsius*1.8)+32<<endl;
            break;
    }
    return 0;
}

int pdconvert() {
    int val;
    double peso, dollar;
    while (true) {
        cout << "PESO AND DOLLAR CONVERTER\n";
        cout << "1. DOLLAR-PESO\n";
        cout << "2. PESO-DOLLAR\n";
        cout << "Enter your choice (1-2): ";
        cin >> val;

        if (val == 1 || val == 2)
            break;
        else
            cout << "Invalid Choice. Please select 1-2 only.\n";
    }

    // switch case for converters
    switch (val) {
        case 1:
            cout<<"Enter dollar: ";
            cin>>dollar;
            cout<<"Peso: PHP"<<dollar*58.13<<endl;
            break;
        case 2:
            cout<<"Enter peso: ";
            cin>>peso;
            cout<<"Dollar: USD"<<peso*.017<<endl;
            break;
    }
    return 0;
}