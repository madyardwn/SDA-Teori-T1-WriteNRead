#include "header.h"

int main(){
	char input;
	
	membaca();
	printf("\n	Ingin Menginput Data?(Y/N):");
	input = toupper(getche());
	if (input == 'Y'){
		system("cls");
		menulis();
	}
	return 0;
}
