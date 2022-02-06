#include "header.h"

void membaca(){
	struct Data_a File_A;
	//struct Data_b File_B;
	FILE *FileA;
	int nomor = 1;
	// membuka file
	FileA = fopen("FileA.dat","rb");
	// membaca struct dalam file hingga match dengan yang diketikan
	printf("				-- Data Jurusan --\n");
	printf(" +---+---------+--------------------------------+---------------+----------------+\n");
	printf(" |No.| Jurusan |     	     Prodi  		|   Laki-Laki   |    Perempuan   |\n");
	printf(" +---+---------+--------------------------------+---------------+----------------+\n");
	while(fread(&File_A,sizeof(struct Data_a),1,FileA)){
	// system("cls");
		if(strlen(File_A.prodi) >= 21){
			if(nomor > 9){
				printf(" |%d |  '%s'  | '%s'	|      %d   	| 	%d 	 |\n", nomor++, File_A.jurusan, File_A.prodi, File_A.JmlPria, File_A.JmlWanita);
		  	}else{
		  		printf(" |%d  |  '%s'  | '%s'	|      %d   	| 	%d 	 |\n", nomor++, File_A.jurusan, File_A.prodi, File_A.JmlPria, File_A.JmlWanita);
		  }
		}else{
			if(nomor > 9){
				printf(" |%d |  '%s'  | '%s'		|      %d   	| 	%d 	 |\n", nomor++, File_A.jurusan, File_A.prodi, File_A.JmlPria, File_A.JmlWanita);
			}else{
				printf(" |%d  |  '%s'  | '%s'		|      %d   	| 	%d 	 |\n", nomor++, File_A.jurusan, File_A.prodi, File_A.JmlPria, File_A.JmlWanita);				
			}		
		}
	}
	printf(" +---+---------+--------------------------------+---------------+----------------+\n");
	fclose(FileA);
}
