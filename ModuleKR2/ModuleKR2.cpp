#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void firstTask() {
    string line;
    ifstream myfile("in.txt");
    ofstream myfileOut("out.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line[0] == '/' && line[1] == '/') {
                cout << line << '\n';
            }
            else if (myfileOut.is_open()) {
                myfileOut << line << '\n';
            }
            else {
                cout << "Unable to open out file";
            }

        }
        myfile.close();
        myfileOut.close();
    }

    else cout << "Unable to open file";
}

int fourthTask(int n, int k)
{
    // Base Cases 
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    // Recur 
    return fourthTask(n - 1, k - 1)
        + fourthTask(n - 1, k);
}


void secondTask() {
    struct Vector {
        int arr[100];
    };

    {
        void print(Vector vector) {
            for (int i = 0; i < 100; i++)
            {
                cout << vector[i];
            }

        }
    }
}






int main() {
    //firstTask();
    //cout << fourthTask(5, 2);

    return 0;
}

