
#include <stdio.h>
extern void ADD (unsigned char a[4][4],unsigned char b[4][4]);
extern void BYTE_SUBSTITUDE (unsigned char a[4][4]);
extern void COLUMNMIX(unsigned char a[4][4]);
extern void DISPLACE(unsigned char a[4][4]);
extern void KEYEXPANSION (unsigned char key[4][4],unsigned char w[4][44]);
extern void roundaction(unsigned char state[4][4],int lun);
unsigned char key_lun[4][4];
unsigned char w[4][44];
void AES (unsigned char state[4][4],unsigned char key[4][4])
{
/*unsigned char AES(unsigned char state[4][4],unsigned char key[4][4])*/
unsigned char temp,temp2,temp3;
unsigned char add_result[4][4];


	int i,j,k,g;


	KEYEXPANSION(key,w);
	
	for(k=0;k<9;k++){
		roundaction(state,k);
	/*	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%02x ",state[i][j]);
		    printf("\n");
		}
		printf("\n");*/
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			key_lun[i][j]=w[i][36+j];
	ADD(state,key_lun);
	BYTE_SUBSTITUDE(state);
	DISPLACE(state);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			key_lun[i][j]=w[i][40+j];
	ADD(state,key_lun);
}
