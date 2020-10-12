#include <iostream>
#include <conio.h>
using namespace std;


void spaces(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

void triangle() {
    cout << "*" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "*";
        spaces(i);
        cout << "*" << endl;
    }
    for (int i = 0; i < 12; i++) {
        cout << "*";
    }
}

void rectangle() {
    cout << "*****************" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "*               *" << endl;
    }
    cout << "*****************" << endl;
}

void equal_triangle() {
    for (int i = 4; i > 0; i--) {
        spaces(i);
        cout << "*";
        spaces((4 - i) * 2);
        cout << "*" << endl;
    }
    cout << "**********";
}

void romb() {
    for (int i = 4; i > 0; i--) {
        spaces(i);
        cout << "*";
        spaces((4 - i) * 2);
        cout << "*" << endl;
    }
    for (int i = 0; i < 5; i++) {
        spaces(i);
        cout << "*";
        spaces((4 - i) * 2);
        cout << "*" << endl;
    }
}




int menu();
int main()
{
    setlocale(LC_ALL, "Russian");
    int answer = menu();
    switch (answer)
    {
    case 0: triangle(); break;
    case 1: rectangle(); break;
    case 2: romb(); break;
    case 3: equal_triangle(); return 0;
    }
    system("pause");
    return 0;
}

int menu() {
    int key = 0;
    int code;
    do {
        system("cls");
        key = (key + 4) % 4;
        if (key == 0) cout << "-> прямоугольный треугольник" << endl;
        else  cout << "   прямоугольный треугольник" << endl;
        if (key == 1) cout << "-> прямоугольник" << endl;
        else  cout << "   прямоугольник" << endl;
        if (key == 2) cout << "-> ромб" << endl;
        else  cout << "   ромб" << endl;
        if (key == 3) cout << "-> равносторонний треугольник" << endl;
        else  cout << "   равносторонний треугольник" << endl;
        code = _getch();
        if (code == 224)
        {
            code = _getch();
            if (code == 80) key++;
            if (code == 72) key--;
        }
    } while (code != 13);
    system("cls");
    return key;
}