/*
*   @file   Konverter Bilangan.c
*
*   @brief  Program ini melakukan konversi bilangan desimal, biner, dan heksadesimal melalui menu utama
*           yang memungkinkan pengguna memilih operasi mana yang diinginkan.
*
*   @authors    Alfiki Diastama Afan Firdaus (M0521009)
*               
*
*   @date 18-10-2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PILIHAN_MINIMUM 0
#define PILIHAN_MAKSIMUM 6
#define KELUAR PILIHAN_MINIMUM
#define KAPASITAS_BINER 32
#define KAPASITAS_HEX 8
#define HEKSA 17

/* Mencetak pilihan menu utama program. */
void menuPilihan(void){
	printf("\n        PROGRAM KONVERTER BILANGAN        \n");
	printf("_________________________________________");
	printf("\n\n");
	printf("Menu Program:\n");
	printf("\n");
	printf("1 - Konversi dari biner ke desimal\n");
	printf("2 - Konversi dari heksadesimal ke desimal\n");
	printf("3 - Konversi dari desimal ke biner\n");
	printf("4 - Konversi dari desimal ke heksadesimal\n");
	printf("5 - Konversi dari biner ke heksadesimal\n");
	printf("6 - Konversi dari heksadesimal ke biner\n");
	printf("0 - Keluar dari program\n\n");
    printf("    Mengetikkan karakter selain angka akan mengeluarkan program\n");
} // end menuPilihan

/*
	Membaca pilihan yang dimasukkan oleh pengguna.
    Fungsi ini mengembalikan nilai integer hasil pilihan pengguna.
*/
unsigned int cetakMenuPilihan(void){
	unsigned int pilihan = 0;

	fflush(stdin); //agar tidak looping terus menerus 

    printf("Ketik menu pilihan kamu: ");
	scanf(" %u", &pilihan);

	while( !(PILIHAN_MINIMUM <= pilihan && PILIHAN_MAKSIMUM >= pilihan)){
        fflush(stdin);
		printf("Pilihan tidak valid! Masukkan menu yang valid!.\n");
		scanf(" %u", &pilihan);
	} //end while

	return(pilihan);

} // end cetakMenuPilihan

/* Mengonversikan bilangan biner ke bilangan desimal */
void BinerKeDesimal(void) {
    
	char biner[KAPASITAS_BINER] = {'\0'};
	int posisi = 0;
	int eksponen = 0;
	int ukuran = 0;
	int desimal = 0;
	int bilangan = 0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nMasukkan bilangan biner: ");
	scanf("%s", biner);
    
    // Loop ini menentukan ukuran string
    while(biner[ukuran] != '\0') {
        ukuran++;
    } // end while
    
    /*  Dalam loop ini, string dilalui dari belakang. Setiap karakter dikonversi ke dalam 
        bilangan bulat, dikalikan dengan basis yang dipangkatkan ke eksponen (0..String length)
        dan ditambahkan ke nilai variabel 'desimal' yang menerima jumlah secara berturut-turut. */
    for(eksponen, posisi=(ukuran-1); eksponen < ukuran; eksponen++, posisi--) {

        bilangan = (int)biner[posisi] - (int)'0';

        // Memeriksa apakah pengguna telah memasukkan biner yang valid
        if(bilangan > 1 || bilangan < 0) {
            printf("Angka yang kamu masukkan tidak valid!\n");
            return;
        }
        desimal += bilangan * pow(2, eksponen);
    }// end for

    printf("%s_(biner) = %d_(desimal)", biner, desimal);
    printf ("\n\n_______________________________________\n\n");//40 underline

} // end BinerKeDesimal

/* Mengubah bilangan heksadesimal menjadi bilangan desimal */
void HeksaKeDesimal(void) {

	char heksadesimal[KAPASITAS_HEX] = {'\0'};	
	unsigned int posisi = 0;
	unsigned int eksponen = 0;
	unsigned int ukuran = 0;
	unsigned int desimal = 0;
	unsigned int bilangan = 0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nMasukkan bilangan heksadesimal: ");
	scanf("%s", heksadesimal);

	while(heksadesimal[ukuran] != '\0') {
        ukuran++;
    } // end while

	// Untuk menerjemahkan huruf-huruf heksadesimal menjadi angka desimal.
	for(eksponen, posisi = ukuran - 1; eksponen < ukuran; eksponen++, posisi--){
		switch (heksadesimal[posisi]){
			
			case 'a': case 'A':
				bilangan = 10; break;
			
			case 'b': case 'B':
				bilangan = 11; break;

			case 'c': case 'C':
				bilangan = 12; break;

			case 'd': case 'D':
				bilangan = 13; break;

			case 'e': case 'E':
				bilangan = 14; break;

			case 'f': case 'F':
				bilangan = 15; break;

			default:
				bilangan = heksadesimal[posisi] - '0'; break;
		
		} //end switch

		desimal += bilangan * pow(16, eksponen);
		bilangan = 0;

	}//end for

	printf("%s_(heksadesimal) = %u_(desimal)", heksadesimal, desimal);
    printf ("\n\n_______________________________________\n\n");//40 underline

}// end HeksaKeDesimal

/* Mengonversi bilangan desimal ke biner. */
unsigned int DesimalKeBiner(void) {
    char biner[KAPASITAS_BINER] = {'\0'};
    unsigned int bilangan = 0;
    unsigned int bits = KAPASITAS_BINER;
    unsigned int i = bits -1;
    unsigned int j = i;

    printf ("_______________________________________");//40 underline
    printf ("\n\nMasukkan bilangan desimal: ");
    scanf ("%u" , &bilangan);

        if (bilangan >= 2) {
            while (bilangan/2 > 0) {
                biner [i] = bilangan % 2;
                bilangan /= 2;
                i--;
                j--;
            } //end while

            for (i = 0; i < j; i++){
                biner [i] = 0;
            } //end for

            biner[j] = 1;

            for (i = 0; i < bits; i++){
                printf ("%u", biner[i]);
            } //end for
        } //end if

        else if (bilangan == 1) {
            for (i = 0; i < j; i++){
                printf("%u", biner[i] = 0);          
            } //end for

            printf("%u",biner[i] = 1);
        } //end else if

        else if (bilangan == 0) {
            for (i = 0; i < bits; i++){
                printf ("%u", biner[i] = 0);
            } //end for
        } else {
            printf ("\n Masukkan nilai yang valid!");
        } //end else

        printf("\n\n_______________________________________\n\n");

}// end DesimalKeBiner

/* Mengonversi bilangan desimal ke heksadesimal. */
void DesimalKeHeksa(void) {

	char nilai[HEKSA] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	char heksadesimal[KAPASITAS_HEX] = {'\0'};
	char temp[KAPASITAS_HEX] = {'\0'};
	int posisi = 0;
	unsigned int desimal = 0;
	unsigned int i = 0;
    unsigned int bilangan = 0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nMasukkan bilangan desimal: ");
	scanf("%u", &desimal);
    bilangan = desimal; //hanya untuk mencetak angka.

	// Melakukan operasi pembagian. Sisa pembagian nanti akan disimpan dalam variabel 'heksadesimal'
	while(desimal > 0) {
       temp[posisi] = nilai[desimal % 16];
       desimal /= 16;
       posisi++;
	}// end while
   
	// Menghapus karakter khusus '\0' dari akhir string
	posisi -= 1;
    
	// Membalikkan string yang terdapat dalam vektor bilangan
	for(i, posisi; posisi >= 0; posisi--, i++){
		heksadesimal[i] = temp[posisi];

	}//end for

	printf("%u_(desimal) = %s_(heksadesimal)", bilangan, heksadesimal);
    printf("\n\n_______________________________________\n\n");

}// end DesimalKeHeksa

/* Mengonversi bilangan heksadesimal ke biner. */
void HeksaKeBiner(void){

    char heksadesimal[KAPASITAS_HEX] = {'\0'};
    char biner[KAPASITAS_BINER] = {'\0'};    

    printf ("_______________________________________");//40 underline
    printf ("\n\nMasukkan bilangan heksadesimal: ");
    scanf("%s", heksadesimal);

    for(int i = 0; i < KAPASITAS_HEX && heksadesimal[i] != '\0'; i++){

        switch (heksadesimal[i]){

            case '0':
				strcat(biner, "0000"); break;

            case '1':
				strcat(biner, "0001"); break;
            
            case '2':
				strcat(biner, "0010"); break;

            case '3':
				strcat(biner, "0011"); break;

            case '4':
				strcat(biner, "0100"); break;

            case '5':
				strcat(biner, "0101"); break;
            
            case '6':
				strcat(biner, "0110"); break;
            
            case '7':
				strcat(biner, "0111"); break;

            case '8':
				strcat(biner, "1000"); break;

            case '9':
				strcat(biner, "1001"); break;

            case 'a': case 'A':
				strcat(biner, "1010"); break;
			
			case 'b': case 'B':
				strcat(biner, "1011"); break;

			case 'c': case 'C':
				strcat(biner, "1100"); break;

			case 'd': case 'D':
				strcat(biner, "1101"); break;

			case 'e': case 'E':
				strcat(biner, "1110"); break;

			case 'f': case 'F':
				strcat(biner, "1111"); break;
  
        }// end switch

    }// end for

    printf("%s_(heksadesimal) = %s_(biner)", heksadesimal, biner);
    printf("\n\n_______________________________________\n\n");

}// end HeksaKeBiner

/* Fungsi untuk membuat interaksi kepada pengguna ketika menjalankan program */
void menu(unsigned int pilihan){

    char mengulangi = '\0';

    while(pilihan != KELUAR) {

        fflush(stdin);

		menuPilihan();
		pilihan = cetakMenuPilihan();

		if(pilihan == 1) { //BinerKeDesimal

            BinerKeDesimal();

            printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
                scanf (" %c", &mengulangi);

                while(mengulangi != 't'){
                    BinerKeDesimal();
                    printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
                    scanf (" %c", &mengulangi);

                } //end while
                
                mengulangi = '\0';
		}    
		else if(pilihan == 2){ // HeksaKeDesimal
            
            HeksaKeDesimal();

            printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
            scanf (" %c", &mengulangi);

            while(mengulangi != 't'){
                HeksaKeDesimal();
                printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
                scanf (" %c", &mengulangi);

            } //end while
            
            mengulangi = '\0';
        }
		else if(pilihan == 3){ // DesimalKeBiner
            
            DesimalKeBiner();

            printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
            scanf (" %c", &mengulangi);

            while(mengulangi != 't'){
                DesimalKeBiner();
                printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
                scanf (" %c", &mengulangi);

            } //end while
            
            mengulangi = '\0';
        }
		else if(pilihan == 4){ // DesimalKeHeksa

            DesimalKeHeksa();

            printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
            scanf (" %c", &mengulangi);

            while(mengulangi != 't'){
                DesimalKeHeksa();
                printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
                scanf (" %c", &mengulangi);

            } // end while
            
            mengulangi = '\0';
        }
		else if(pilihan == 5){

            printf("\nFitur ini belum tersedia. \n\nNantikan update selanjutnya.\n");
        }
		else if(pilihan == 6){ // HeksaKeBiner

            HeksaKeBiner();

            printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
            scanf (" %c", &mengulangi);

            while(mengulangi != 't'){
                HeksaKeBiner();
                printf("Apakah kamu ingin melakukan konversi lagi? (y/t) \n");
                scanf (" %c", &mengulangi);

            } //end while
            
            mengulangi = '\0';
        } 
        else if(pilihan == 0){ // untuk keluar dari program
            exit(1);
        }

	} // end while

} // end menu

/* Fungsi main */
int main (void) {

    unsigned int pilihan = 10;

    menu(pilihan);

    return 0;

} // end main