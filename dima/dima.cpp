#include <bits/stdc++.h>

using namespace std;

struct TLinktwo
{
    int data;
    TLinktwo* left;
    TLinktwo* right;
};


void add_element(TLinktwo*& head, TLinktwo*& tail, int data, int place)
{
    TLinktwo* temp = new TLinktwo;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (head == NULL)// is_empty
    {
        tail = temp;
        head = tail;
        return;
    }
    if (place == 1) // add_right
    {
        head->right = temp;
        temp->left = head;
        head = temp;
    }
    else // add_left
    {
        tail->left = temp;
        temp->right = tail;
        tail = temp;
    }
}

bool remove_element(TLinktwo*& head, TLinktwo*& tail, int& data, int place)
{
    TLinktwo* temp = new TLinktwo;
    if (head == NULL)// is_empty
    {
        return false;
    }
    if (head == tail) // one element
    {
        data = head->data;
        delete head;
        delete tail;
        head = NULL;
        tail = NULL;
        return true;
    }
    if (place == 1) // remove_right
    {
        data = head->data;
        temp = head;
        head = head->left;
        delete temp;
        temp = NULL;
        head->right = NULL;
    }
    else // remove_left
    {
        data = tail->data;
        temp = tail;
        tail = tail->right;
        delete temp;
        temp = NULL;
        tail->left = NULL;
    }
    return true;
}

bool view_element(TLinktwo*& head, TLinktwo*& tail, int place)
{
    TLinktwo* temp = new TLinktwo;
    temp = tail;
    if (head == NULL)
    {
        cout << "Empty\n";
        return false;
    }
    if (place == 3) cout << head->data << "\n"; // view_right
    else cout << tail->data << "\n"; // view_left
    return true;
}


bool view_all(TLinktwo*& head, TLinktwo*& tail)
{
    TLinktwo* temp = new TLinktwo;
    temp = tail;
    if (head == NULL)
    {
        cout << "Empty\n";
        return false;
    }
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << temp->data << "\n";
    return true;
}

void interface_display()
{
    cout << "What do u need?\n";
    cout << "[ADD_R] ";
    cout << "[ADD_L] ";
    cout << "[REM_R] ";
    cout << "[REM_L] ";
    cout << "[VIEW_R] ";
    cout << "[VIEW_L] ";
    cout << "[ALL] ";
    cout << "[EXIT]\n";
}

int listener()
{
    string input;
    cin >> input;
    if (input == "ADD_R") return 1;
    if (input == "ADD_L") return 2;
    if (input == "REM_R") return -1;
    if (input == "REM_L") return -2;
    if (input == "VIEW_R") return 3;
    if (input == "VIEW_L") return 4;
    if (input == "EXIT") return 0;
    else return 9;
}

void interface(TLinktwo* head, TLinktwo* tail)
{
    bool execute = true;
    int data, ch;
    while (execute)
    {
        interface_display();
        ch = listener();
        if (ch == 0) execute = false;
        else
        {
            if (ch == 1 || ch == 2)
            {
                cout << "DATA = ";
                cin >> data;
                add_element(head, tail, data, ch);
            }
            else
            {
                if (ch == 9)
                {
                    view_all(head, tail);
                }
                else
                {
                    if (ch == 3 || ch == 4)
                    {
                        view_element(head, tail, ch);
                    }
                    else
                    {
                        ch = abs(ch);
                        if (remove_element(head, tail, data, ch)) cout << "DATA: " << data << "\n";
                        else cout << "Empty\n";
                    }
                }
            }
        }
    }
}

int main()
{
    TLinktwo* head = NULL;
    TLinktwo* tail = NULL;
    interface(head, tail);
    return 0;
}