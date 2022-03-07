#pragma once



struct Student {
	char* username;
	char* password;
	char* fullname;
	int age;
	const char* date;
	int count = 0;
	Student** students;
};