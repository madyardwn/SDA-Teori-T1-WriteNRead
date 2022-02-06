#include "header.h"
#include <cstdlib>

int main(){
	struct Data_a File_A;
	struct Data_b File_B;
	
	FILE *FileA;
	FILE *FileB;
	
	char var_jur[15];
	int Tot_prodi_di_jur;
	int Tot_prodi_mayo_p;
	int Tot_mhs_di_jur;
	
	FileA = fopen("FileA.dat", "rb");
	
	//rewind(FileA);
	while(fread(&File_A, sizeof(Data_a),1,FileA)){	
		strcpy(var_jur, File_A.jurusan);
		Tot_prodi_di_jur = 0;
		Tot_prodi_mayo_p = 0;
		Tot_mhs_di_jur = 0;
	
		//printf("%s \n", var_jur);
	
		FileA = fopen("FileA.dat", "rb");
		while(fread(&File_A, sizeof(Data_a),1,FileA)){
			//printf("%s \n", var_jur);
			if (strcmp(var_jur, File_A.jurusan) == 0 ){
				Tot_prodi_di_jur = Tot_prodi_di_jur + 1;
				Tot_mhs_di_jur = Tot_mhs_di_jur + File_A.JmlPria + File_A.JmlWanita;
				if (File_A.JmlWanita < File_A.JmlPria){
					Tot_prodi_mayo_p = Tot_prodi_mayo_p + 1;
				}
			}
		//	printf("%s \n", var_jur);
		}
		FileB = fopen("FileB.dat", "w");
		strcpy(File_B.jurusan, var_jur);
		File_B.TotProdi = Tot_prodi_di_jur;
		File_B.JmlMayoPria = Tot_prodi_mayo_p;
		File_B.JmlMhsJur = Tot_mhs_di_jur;
		fwrite(&File_B, sizeof(Data_b),1,FileB);
		fclose(FileB);
	}
	while(fread(&File_A, sizeof(Data_a),1,FileA)){	
		strcpy(var_jur, File_A.jurusan);
		Tot_prodi_di_jur = 0;
		Tot_prodi_mayo_p = 0;
		Tot_mhs_di_jur = 0;
	
		//printf("%s \n", var_jur);
	
		FileA = fopen("FileA.dat", "rb");
		while(fread(&File_A, sizeof(Data_a),1,FileA)){
			//printf("%s \n", var_jur);
			if (strcmp(var_jur, File_A.jurusan) == 0 ){
				Tot_prodi_di_jur = Tot_prodi_di_jur + 1;
				Tot_mhs_di_jur = Tot_mhs_di_jur + File_A.JmlPria + File_A.JmlWanita;
				if (File_A.JmlWanita < File_A.JmlPria){
					Tot_prodi_mayo_p = Tot_prodi_mayo_p + 1;
				}
			}
		//	printf("%s \n", var_jur);
		}
		FileB = fopen("FileB.dat", "w");
		strcpy(File_B.jurusan, var_jur);
		File_B.TotProdi = Tot_prodi_di_jur;
		File_B.JmlMayoPria = Tot_prodi_mayo_p;
		File_B.JmlMhsJur = Tot_mhs_di_jur;
		fwrite(&File_B, sizeof(Data_b),1,FileB);
		fclose(FileB);
	}	
	fclose(FileA);
	int nomor = 1;
	FileB = fopen("FileB.dat", "r");
	printf("				--Hasil Konversi Data Jurusan --\n");
	printf(" +---+---------+--------------------------------+-------------------------+----------------+\n");
	printf(" |No.| Jurusan |     	  Total Prodi  		|   Mayoritas Laki-Laki   | Total Mahasiswa|\n");
	printf(" +---+---------+--------------------------------+-------------------------+----------------+\n");
	while(fread(&File_B, sizeof(Data_b),1,FileB)){
		printf(" |%d  |  '%s'  | 		%d		|	     %d	    	  | 	 %d	   |\n", nomor++, File_B.jurusan, File_B.TotProdi, File_B.JmlMayoPria, File_B.JmlMhsJur);	
	}
 	printf(" +---+---------+--------------------------------+-------------------------+----------------+\n");
}
	
