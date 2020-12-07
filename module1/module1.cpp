#include <iostream>
using namespace std;

double funcD(double a, double b, double c, double x) {
    if (c < 0 && x != 0) {
        return -a * x - c;
    }
    else if (c > 0 && x == 0) {
        return (x - a) / (-c);
    }
    else if (a != 0) {
        return (b * x) / (c - a);
    }
    else {
        return -INFINITY;
    }
}

double funcI(int a, int b, int c, double x) {
    if (c < 0 && x != 0) {
        return -a * x - c;
    }
    else if (c > 0 && x == 0) {
        return (x - a) / (-c);
    }
    else if (a != 0) {
        return (b * x) / (c - a);
    }
    else {
        return -INFINITY;
    }
}






int main()
{
    double a, b, c, lx, rx, dx;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter start x: ";
    cin >> lx;
    cout << "Enter end x: ";
    cin >> rx;
    cout << "Enter dx: ";
    cin >> dx;

    if ((int(a) | int(b) | int(c)) != 0) {
        for (double x = lx; x <= rx; x += dx) {
            cout << funcD(a, b, c, x) << endl;
        }
    }
    else {
        a = int(a);
        b = int(b);
        c = int(c);

        for (double x = lx; x <= rx; x += dx) {
            cout << funcI(a, b, c, x) << endl;
        }
    }


    return 0;
}


