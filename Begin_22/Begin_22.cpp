#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a;
    int b;
    cin >> a >> b;
    Swap(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b;

}