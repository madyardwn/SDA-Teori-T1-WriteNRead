#include "header.h"

void input(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch)-1] = 0; 
}

void menulis(){
	membaca();
	
	struct Data_a File_A;
	FILE *FileA;
	int nomor;
	
	while(1){
		
		FileA = fopen("FileA.dat","ab+");
		/*
		rewind(FileA);
        while(fread(&File_A, sizeof(Data_a), 1, FileA)){
          	nomor = File_A.nomor;
        }
        
        if (nomor < 1 or nomor == NULL){
          File_A.nomor = 1;
        }
        
        if (nomor >= 1){
          File_A.nomor = nomor + 1;
        }
        fflush(stdin);
		
		printf("%d %d", nomor, File_A.nomor);
		*/
		
		//system("cls");
		printf("\n	Jurusan			: ");
		input(File_A.jurusan);
		
		
		printf("	Prodi			: ");
		input(File_A.prodi);
		
		printf("	Jumlah laki-laki	: ");
		scanf("%d", &File_A.JmlPria);
		fflush(stdin);
		
		printf("	Jumlah perempuan	: ");
		scanf("%d", &File_A.JmlWanita);
		fflush(stdin);	
		
		// membuka file
		//FileA = fopen("FileA.dat","a+");
		fwrite(&File_A,sizeof(struct Data_a),1,FileA);
		fclose(FileA);
		
		system("cls");
		membaca();
		
		printf("\n	Ingin mengulangi pengimputan data lagi? (Y/N): ");
		char ulang = toupper(getche());
		switch (ulang){
			case 'Y' : 	system("cls"); 
						menulis(); 
						break;
			default : exit(1); 
		}
	}
}
