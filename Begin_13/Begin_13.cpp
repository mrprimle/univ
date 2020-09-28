#include <iostream>
using namespace std;


int main()
{
    double r1;
    double r2;
    cin >> r1 >> r2;
    double pi = 3.14;
    double s1 = pi * r1 * r1;
    double s2 = pi * r2 * r2;
    double s3 = s1 - s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3;

}