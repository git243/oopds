#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <fstream>

using namespace std;

class Login {
private:
    string username, password;
public: 
    Login();
    void setusername(string un);
    void setpassword(string pw);
    void isloggedin(string username, string password);
};

Login::Login(){
    string un;
    cout << "Please enter your username: ";
    cin >> un;
    setusername(un);
}

void Login::setusername(string un){
    username = un;
    string pw;
    cout << "Please enter your password: ";
    cin >> pw;
    setpassword(pw);
}

void Login::setpassword(string pw){
    password = pw;
    isloggedin(username, password);
}

void Login::isloggedin(string username, string password){
    string uname, pword;
    ifstream file("LOGIN.txt");
    getline(file, uname);
    getline(file, pword);
    try{
        if (username == uname && password == pword) {
            throw 1;
        }
        else {
            throw 2;
        }
    }
    catch(int &sf){
        switch(sf){
            case 1: cout << "Success!";
                    break;
            case 2: cout << "Fail!";
                    break;
        }
    }
}

#endif /* LOGIN_H */
