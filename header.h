#ifndef header_H
#define header_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>


struct Data_a{
	//int nomor;
	char jurusan[15];
	char prodi[30];
	int JmlWanita;
	int JmlPria;
};

struct Data_b{
	char jurusan[15];
	int TotProdi, JmlMayoPria, JmlMhsJur;
};

int main();
void input(char ch[50]);
void membaca();
void menulis();

#endif