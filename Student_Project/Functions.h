#pragma once

#include <iostream>
#include "Entities.h"
using namespace std;


void ShowMenu() {
	cout << endl;
	cout << "         - Choose -                " << endl;
	cout << "  _________________________" << endl;
	cout << endl;
	cout << " |                         |" << endl;
	cout << " | 1 --> Sign In (Press 1) |" << endl;
	cout << " | 2 --> Sign Up (Press 2) |" << endl;
	cout << " |                         |" << endl;
	cout << "  _________________________" << endl;
	cout << endl;
}


int student_count = 3;

Student** students = new Student * [student_count] {
	new Student{
		new char[] {"john12"},
		new char[] {"password1"},
		new char[] {"John Johnlu"},
		23,
		__DATE__
	},
		new Student{
			new char[] {"akif23"},
			new char[] {"password2"},
			new char[] {"Akif Akifli"},
			21,
			__DATE__
	},
		new Student{
			new char[] {"rick34"},
			new char[] {"password3"},
			new char[] {"Rick Rickli"},
			22,
			__DATE__
	}

};



bool isUserExist(Student** students, char* username) {
	for (size_t i = 0; i < student_count; i++)
	{
		if (strcmp(students[i]->username, username) == 0) {
			return true;
		}
	}
	return false;
}


bool isPasswordExist(Student** students, char* password) {
	for (size_t i = 0; i < student_count; i++)
	{
		if (strcmp(students[i]->password, password) == 0) {
			return true;
		}
	}
	return false;
}


FILE* file;

void AddStudent(Student** students, char* username, char* password, char* fullname, int age, const char* date) {
	Student** newstudent = new Student * [student_count + 1]{};
	for (size_t i = 0; i < student_count; i++)
	{
		newstudent[i] = students[i];
	}
	newstudent[student_count] = new Student{ username,password,fullname,age,date };
	students = newstudent;
	newstudent = nullptr;
	student_count++;




	fopen_s(&file, "students.bin", "wb");
	fwrite(&student_count, sizeof(int), 1, file);
	//  Write.
	for (size_t i = 0; i < student_count; i++)
	{
		int l1 = strlen(students[i]->username);
		fwrite(&l1, sizeof(char), 1, file);
		fwrite(students[i]->username, sizeof(char), l1, file);

		int l2 = strlen(students[i]->password);
		fwrite(&l2, sizeof(char), 1, file);
		fwrite(students[i]->password, sizeof(char), l2, file);

		int l3 = strlen(students[i]->fullname);
		fwrite(&l3, sizeof(char), 1, file);
		fwrite(students[i]->fullname, sizeof(char), l3, file);


		fwrite(&students[i]->age, sizeof(int), 1, file);

		int l4 = strlen(students[i]->date);
		fwrite(&l4, sizeof(char), 1, file);
		fwrite(students[i]->date, sizeof(char), l4, file);
	}
	fclose(file);




}

void ShowAllStudents(Student**students) {
	Student** students2 = new Student * [student_count] {};
	for (size_t i = 0; i < student_count; i++)
	{
		cout << "  Student's Id {" << i + 1 << "}" << endl << endl;
		cout << "  Student's Username--> " << students2[i]->username << endl;
		cout << "  Student's Fullname--> " << students2[i]->fullname << endl;
		cout << "  Student's Age--> " << students2[i]->age << endl;
		cout << "  Student's Date--> " << students2[i]->date << endl << endl;
		cout << "  -----------------------------------------------" << endl << endl;;
		cout << endl;
	}
}


void WriteFile() {
	fopen_s(&file, "students.bin", "wb");
	fwrite(&student_count, sizeof(int), 1, file);
	//  Write.
	for (size_t i = 0; i < student_count; i++)
	{
		int l1 = strlen(students[i]->username);
		fwrite(&l1, sizeof(char), 1, file);
		fwrite(students[i]->username, sizeof(char), l1, file);

		int l2 = strlen(students[i]->password);
		fwrite(&l2, sizeof(char), 1, file);
		fwrite(students[i]->password, sizeof(char), l2, file);

		int l3 = strlen(students[i]->fullname);
		fwrite(&l3, sizeof(char), 1, file);
		fwrite(students[i]->fullname, sizeof(char), l3, file);


		fwrite(&students[i]->age, sizeof(int), 1, file);

		int l4 = strlen(students[i]->date);
		fwrite(&l4, sizeof(char), 1, file);
		fwrite(students[i]->date, sizeof(char), l4, file);
	}
	fclose(file);

}

void WriteAndReadFile()
{
	fopen_s(&file, "students.bin", "wb");
	fwrite(&student_count, sizeof(int), 1, file);
	//  Write.
	for (size_t i = 0; i < student_count; i++)
	{
		int l1 = strlen(students[i]->username);
		fwrite(&l1, sizeof(char), 1, file);
		fwrite(students[i]->username, sizeof(char), l1, file);

		int l2 = strlen(students[i]->password);
		fwrite(&l2, sizeof(char), 1, file);
		fwrite(students[i]->password, sizeof(char), l2, file);

		int l3 = strlen(students[i]->fullname);
		fwrite(&l3, sizeof(char), 1, file);
		fwrite(students[i]->fullname, sizeof(char), l3, file);


		fwrite(&students[i]->age, sizeof(int), 1, file);

		int l4 = strlen(students[i]->date);
		fwrite(&l4, sizeof(char), 1, file);
		fwrite(students[i]->date, sizeof(char), l4, file);
	}
	fclose(file);




	fopen_s(&file, "students.bin", "rb");
	fread_s(&student_count, sizeof(int), sizeof(int), 1, file);


	Student** students2 = new Student * [student_count] {};

	for (size_t i = 0; i < student_count; i++)
	{
		int l1 = 0;
		fread_s(&l1, sizeof(char), sizeof(char), 1, file);
		char* username = new char[l1 + 1]{};
		fread_s(username, l1, sizeof(char), l1, file);


		int l2 = 0;
		fread_s(&l2, sizeof(char), sizeof(char), 1, file);
		char* password = new char[l2 + 1]{};
		fread_s(password, l2, sizeof(char), l2, file);


		int l3 = 0;
		fread_s(&l3, sizeof(char), sizeof(char), 1, file);
		char* fullname = new char[l3 + 1]{};
		fread_s(fullname, l3, sizeof(char), l3, file);


		int age = 0;
		fread_s(&age, sizeof(int), sizeof(int), 1, file);

		int l4 = 0;
		fread_s(&l4, sizeof(char), sizeof(char), 1, file);
		char* date = new char[l4 + 1]{};
		fread_s(date, l4, sizeof(char), l4, file);


		students2[i] = new Student{ username,password,fullname,age,date };
	}
	fclose(file);
	for (size_t i = 0; i < student_count; i++)
	{
		cout << "  Student's Id {" << i + 1 << "}" << endl << endl;
		cout << "  Student's Username--> " << students2[i]->username << endl;
		cout << "  Student's Fullname--> " << students2[i]->fullname << endl;
		cout << "  Student's Age--> " << students2[i]->age << endl;
		cout << "  Student's Date--> " << students2[i]->date << endl << endl;
		cout << "  -----------------------------------------------" << endl << endl;;
		cout << endl;
	}

}


void ReadFile() {

	fopen_s(&file, "students.bin", "rb");
	fread_s(&student_count, sizeof(int), sizeof(int), 1, file);


	Student** students2 = new Student * [student_count] {};

	for (size_t i = 0; i < student_count; i++)
	{
		int l1 = 0;
		fread_s(&l1, sizeof(char), sizeof(char), 1, file);
		char* username = new char[l1 + 1]{};
		fread_s(username, l1, sizeof(char), l1, file);


		int l2 = 0;
		fread_s(&l2, sizeof(char), sizeof(char), 1, file);
		char* password = new char[l2 + 1]{};
		fread_s(password, l2, sizeof(char), l2, file);


		int l3 = 0;
		fread_s(&l3, sizeof(char), sizeof(char), 1, file);
		char* fullname = new char[l3 + 1]{};
		fread_s(fullname, l3, sizeof(char), l3, file);


		int age = 0;
		fread_s(&age, sizeof(int), sizeof(int), 1, file);

		int l4 = 0;
		fread_s(&l4, sizeof(char), sizeof(char), 1, file);
		char* date = new char[l4 + 1]{};
		fread_s(date, l4, sizeof(char), l4, file);


		students2[i] = new Student{ username,password,fullname,age,date };
	}
	fclose(file);
	for (size_t i = 0; i < student_count; i++)
	{
		cout << "  Student's Id {" << i + 1 << "}" << endl << endl;
		cout << "  Student's Username--> " << students2[i]->username << endl;
		cout << "  Student's Fullname--> " << students2[i]->fullname << endl;
		cout << "  Student's Age--> " << students2[i]->age << endl;
		cout << "  Student's Date--> " << students2[i]->date << endl<<endl;
		cout << "  -----------------------------------------------" << endl << endl;;
		cout << endl;
	}
}

