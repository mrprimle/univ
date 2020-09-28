#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    double a;
    double b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    cout << "Sum: " << a + b << endl;
    cout << "Substract: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b;
}