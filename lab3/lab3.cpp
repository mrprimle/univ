#include <iostream>
using namespace std;

double integral(double(*)(double), double, double, int);
double f(double);

int main()
{
    double a, b;
    const double pi = 3.1415926;

    cout << "Enter 'from': ";
    cin >> a;
    cout << "Enter 'to': ";
    cin >> b;
    
    cout << integral(f, a, b, 50000);

    return 0;
}


double f(double x)
{
    const double pi = 3.1415926;
    double y;
    //y = x * x;
    y = sin(x);
    return y;
}
double integral(double(*f)(double), double a, double b, int n)
{
    double r, x, u, e;
    e = 0.0;

    for (int i = 1; i <= n; i++)
    {
        u = 1.0 * rand() / (RAND_MAX + 1);
        x = a + (b - a) * u;
        e += f(x);
    }

    r = e * (b - a) / n;
    return r;
}