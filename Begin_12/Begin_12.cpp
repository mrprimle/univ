#include <iostream>
using namespace std;


int main()
{
    double a;
    double b;
    cin >> a >> b;
    double c = sqrt(a * a + b * b);
    cout << "Hipothenusa: " << c << endl;
    cout << "Perimetr: " << a + b + c;

}