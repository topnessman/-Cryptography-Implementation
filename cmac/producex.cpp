#include <stdio.h>
extern void ADD (unsigned char a[4][4],unsigned char b[4][4]);
void PRODUCEX (unsigned char a[4][4])
{
	int i,j;
	unsigned char temp[4][4];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			temp[i][j]=a[i][j];
	a[3][3]=temp[3][3]<<1;
	a[2][3]=(temp[2][3]<<1)^(temp[3][3]/128);
	a[1][3]=(temp[1][3]<<1)^(temp[2][3]/128);
	a[0][3]=(temp[0][3]<<1)^(temp[1][3]/128);
	a[3][2]=(temp[3][2]<<1)^(temp[0][3]/128);
	a[2][2]=(temp[2][2]<<1)^(temp[3][2]/128);
	a[1][2]=(temp[1][2]<<1)^(temp[2][2]/128);
	a[0][2]=(temp[0][2]<<1)^(temp[1][2]/128);
	a[3][1]=(temp[3][1]<<1)^(temp[0][2]/128);
	a[2][1]=(temp[2][1]<<1)^(temp[3][1]/128);
	a[1][1]=(temp[1][1]<<1)^(temp[2][1]/128);
	a[0][1]=(temp[0][1]<<1)^(temp[1][1]/128);
	a[3][0]=(temp[3][0]<<1)^(temp[0][1]/128);
	a[2][0]=(temp[2][0]<<1)^(temp[3][0]/128);
	a[1][0]=(temp[1][0]<<1)^(temp[2][0]/128);
	a[0][0]=(temp[0][0]<<1)^(temp[1][0]/128);

	unsigned char f[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0x07}};

	if(temp[0][0]/128)
		ADD(a,f);
}