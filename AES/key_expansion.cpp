#include <stdio.h>
extern void g (unsigned char w[4],unsigned char w_a[4],int lun);
void KEYEXPANSION (unsigned char key[4][4],unsigned char w[4][44])
{
	int i,j;
	for(j=0;j<4;j++)
		for(i=0;i<4;i++)
			w[i][j]=key[i][j];
		/*ÐÐÁÐ×ª»»*/
	unsigned char w_temp[4],w_a_temp[4];
	int lun;
	for(lun=1;lun<=10;lun++){

	for(i=0;i<4;i++)
		w_temp[i]=w[i][4*lun-1];
	g(w_temp,w_a_temp,lun);
	for(i=0;i<4;i++){
		w[i][4*lun]=w[i][4*lun-4]^w_a_temp[i];
		w[i][4*lun+1]=w[i][4*lun-3]^w[i][4*lun];
		w[i][4*lun+2]=w[i][4*lun-2]^w[i][4*lun+1];
		w[i][4*lun+3]=w[i][4*lun-1]^w[i][4*lun+2];}

	}
}
