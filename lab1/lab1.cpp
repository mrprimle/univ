#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool in(int elem, vector<int> arr) {
    for (auto i : arr) {
        if (i == elem) {
            return true;
        }
    }
    return false;
}


vector<int> prime_div(int n) {
    vector<int> ret = {};
    if (n <= 2)  return { 0 };
    vector<bool>  check(n + 1, false);
    vector<int> primes = {2};
    int upper = sqrt(n);
    for (int i = 3; i <= n; i += 2) {
        if (!check[i]) {
            primes.push_back(i);
            if (i > upper) continue;
            for (int j = i * i; j <= n; j += i) {
                check[j] = true;
            }
        }
    }
    //copy(primes.begin(),   
    //    primes.end(),     
    //    ostream_iterator<int>(cout, " ")   
    //);
    int i = 0;
    while (!in(n, primes) && (i < primes.size())) {
        while (n % primes[i] == 0) {
            ret.push_back(primes[i]);
            n /= primes[i];
        }
        i++;
    }
    if (i < primes.size()) {
        ret.push_back(n);
    }

    return ret;
}



bool first_cond(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % (i * i) == 0) {
            return false;
        }
    }
    return true;
}
bool second_cond(int n) {
    for (auto i : prime_div(n)) {
        if ((n - 1) % (i - 1) != 0)
            return false;
    }
    return true;
}


bool lab11(int n) {
    return first_cond(n) && second_cond(n);
}

void lab3(int dec, int p) {
    int bin = 0;

    for (int i = 0; dec > 0; i++) {
        bin += (dec % p) * pow(10, i);
        dec /= p;
    }

    cout << bin;
}

int main()
{
    for (int i = 1; i < 1000; i++) {
        cout << lab11(i);
    }

    //lab3(10, 8);
}


