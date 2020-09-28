#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int i = 1; i < 4; i++) {
        num *= num;
        cout << num << endl;
    }
}