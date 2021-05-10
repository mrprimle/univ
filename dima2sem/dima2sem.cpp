#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void fill(int amount) {
    for (amount; amount > 0; amount--) {
        cout << " *";
    }
}

void space(int amount) {
    for (amount; amount > 0; amount--) {
        cout << ' ';
    }
}


int main()
{

    for (int i = 0; i < 6; i++) {
        space(i * 2);
        cout << '*';  
        if (i % 2 == 0) {
            space(18 - i * 2 - i + 1 - i);
            cout << '*';
        }
        else {
            fill(9 - 2 * i - i / 2 + 1 + i / 3);
        }
        cout << endl;
    }
    


    return 0;
}
