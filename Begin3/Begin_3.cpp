#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void ban(int banned[]) {
    ifstream infile("test.txt");
    ofstream outfile("test2.txt");
    outfile.open("test2.txt", std::ios_base::app);
    for (int i = 0; i < 1; i++) {
        cout << "Do ban " << banned[i] << " user\n";
        int counter = 0;
        for (string line; getline(infile, line); ) {
            counter++;
            //cout << counter << " ";
            //cout << banned[i] + 6 << endl;
            if (counter == banned[i] + 6) {
                //cout << "triggered";
                line.replace(line.size() - 1, 1, "1");
            }
            outfile << line << "\n";
        }
        infile.close();
        outfile.close();
    }


}

void buy(int stored[]) {
    for (int i = 0; i < 2; i++) {
        //cout << "Do buy " << stored[i] << " product\n";
        ifstream infile("test.txt");
        int counter = 0;
        for (string line; getline(infile, line); ) {
            counter++;
            if (counter == stored[i]) {
                ofstream outfile;
                outfile.open("bill.txt", std::ios_base::app);
                outfile << line << "\n";
                outfile.close();
            }
        }
    }
}







void adminMenu() {
    cout << "Users to ban: " << endl;
    ifstream infile("test.txt");
    int counter = 0;
    for (string line; getline(infile, line); ) {
        counter++;
        if (counter > 6) {
            cout << counter - 6 << ". " << line << endl;
        }
    }

    // CHOSING AND STORING (repeat), then ban()
    int banned[10];
    for (int i = 0; i < 10; i++) {
        int banId;
        cout << "Enter user's id to ban OR -1 to quit: ";
        cin >> banId;
        if (banId == -1) {
            ban(banned);
            break;
        } 
        banned[i] = banId;
    }




    infile.close();
}

void userMenu() {
    cout << "Products to buy: " << endl;
    ifstream infile("test.txt");
    int counter = 0;
    for (string line; getline(infile, line); ) {
        counter++;
        if (counter < 6) {
            cout << counter << ". " << line << endl;
        }
    }

    // CHOSING AND STORING (repeat), then check.txt()
    int stored[10];
    for (int i = 0; i < 6; i++) {
        int prodId;
        cout << "Enter product's id to buy OR -1 to quit: ";
        cin >> prodId;
        if (prodId == -1) {
            buy(stored);
            break;
        }
        stored[i] = prodId;
    }


    infile.close();
}





void new_user(bool isAdmin) {
    char login[100];
    char pass[100];

    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> pass;

    // write new user in file with (login, pass, isAdmin, 0)
    ofstream outfile;
    outfile.open("test.txt", std::ios_base::app);
    outfile << login << ", " << pass << ", " << isAdmin << ", " << "0" << "\n";
    outfile.close();

    // show user/admin menu
    if (isAdmin) {
        adminMenu();
    }
    else {
        userMenu();
    }


}

void sign_up() {
    int signupChoise;
    cout << "Admin (1)/User (2) \n";
    cin >> signupChoise;

    switch (signupChoise) {
    case 1:
        new_user(true);
        break;
    case 2:
        new_user(false);
        break;
    default:
        printf("[EXEPTION]: You should enter 1/2! \n");
        break;
    }

}







void log_in() {
    string login;
    string pass;

    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> pass;

    // search for user in file and call either admin or user menu
    ifstream infile("test.txt");
    int userIdLen = login.size() + 2 + pass.size();
    int counter = 0;
    for (string line; getline(infile, line); ) {
        counter++;
        if (counter > 6) {
            string userId = line.substr(0, userIdLen);
            string foundUser = login + ", " + pass;
            if (userId == foundUser) {
                bool isadmin = line.at(line.size() - 4) == '1';
                bool isbaned = line.at(line.size() - 1) == '1';
                if (isadmin && !isbaned) {
                    adminMenu();
                }
                else if (!isadmin && !isbaned) {
                    userMenu();
                }
                else {
                    cout << "You got banned ; (";
                }
            }
            
        }
        
    }

    infile.close();

}



int main() {
    cout << "Welcome to the terminal! To make choises type the num for the choise in parenthesis \n";

    int startChoise;
    cout << "SIGN-UP (1)/LOG-IN (2) \n";
    cin >> startChoise;

    switch (startChoise) {
    case 1:
        sign_up();
        break;
    case 2:
        log_in();
        break;
    default:
        printf("[EXEPTION]: You should enter 1/2!");
        break;
    }

    /*
    ofstream outfile;

    outfile.open("test.txt", std::ios_base::app);
    outfile << "Data";
    return 0;
    */
}