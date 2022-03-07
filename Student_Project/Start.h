#pragma once
#include <iostream>
#include <windows.h>
#include "Entities.h"
#include "Functions.h"
using namespace std;





void Start() {
	while (true) {
		ShowMenu();
		cout << endl;
		int select = 0;
		cout << "  Please, select--> ";
		cin >> select;
		if (select == 1) {
			// Sign In
			system("cls");
			cin.ignore();
			cin.clear();
			char* username = new char[100]{};
			cout << endl;
			cout << "         - Sign In -                " << endl << endl;
			cout << "  Enter username--> ";
			cin.getline(username, 100);
			cout << endl;
			char* password = new char[100]{};
			cout << "  Enter password--> ";
			cin.getline(password, 100);
			cout << endl;
			if (isUserExist(students, username) && isPasswordExist(students, password) == true) {
				cout << "  Loading..." << endl;
				Sleep(800);
				system("cls");
				cout << endl;
				cout << endl;
				cout << "  - Your Choice (Press 1) -                " << endl << endl;
				cout << "  | 1 --> Show All Students" << endl;
				int s = 0;
				cout << endl;
				cout << " Select--> ";
				cin >> s;
				cout << endl;
				if (s == 1) {
					// Show All Students
					system("cls");
					cout << endl;
					cout << "         - Show All Students -                " << endl << endl;
					WriteFile();
					ReadFile();
				}
			}
			else {
				cout << "  Loading..." << endl;
				cout << endl;
				cout << "  This student does not exist in our University!" << endl << endl << endl;

			}
			cout << "  Press (enter) to go to menu." << endl << endl;
			system("pause");
			system("cls");
		}
		else if (select == 2) {
			// Sign Up
			system("cls");
			cin.ignore();
			cin.clear();
			cout << endl;
			cout << "         - Sign Up -                " << endl << endl;
			char* username = new char[100]{};
			cout << "  Enter username--> ";
			cin.getline(username, 100);
			if (isUserExist(students, username) == true) {
				system("cls");
				Sleep(400);
				cout << endl;
				cout << "  Loading..." << endl;
				cout << endl;
				cout << "  Use another username!" << endl << endl;;
				break;
			}

			cout << endl;
			char* password = new char[100]{};
			cout << "  Enter password--> ";
			cin.getline(password, 100);
			cout << endl;
			char* fullname = new char[100]{};
			cout << "  Enter fullname--> ";
			cin.getline(fullname, 100);
			cout << endl;
			int age = 0;
			cout << "  Enter age--> ";
			cin >> age;
			system("cls");
			cout << endl;
			cout << "         - Added New Student -                " << endl << endl;
			AddStudent(students, username, password, fullname, age, __DATE__);
			ReadFile();
			cout << "  Press (enter) to go to menu." << endl << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << endl;
			cout << " Try Again! (Reason :: It is Wrong Number Or Letter).." << endl << endl;
			Sleep(800);
			cout << "  Press (enter) to go to menu." << endl << endl;
			system("pause");
			system("cls");
		}
	}

}