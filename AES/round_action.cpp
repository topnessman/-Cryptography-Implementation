#include <stdio.h>
extern void ADD (unsigned char a[4][4],unsigned char b[4][4]);
extern void BYTE_SUBSTITUDE (unsigned char a[4][4]);
extern void COLUMNMIX(unsigned char a[4][4]);
extern void DISPLACE(unsigned char a[4][4]);
extern unsigned char w[4][44];
void roundaction(unsigned char state[4][4],int lun)
{
	int i,j;
	unsigned char key_lun[4][4];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			key_lun[i][j]=w[i][4*lun+j];
		ADD(state,key_lun);
		BYTE_SUBSTITUDE(state);
		DISPLACE(state);
		COLUMNMIX(state);
	    
	
	
	
}