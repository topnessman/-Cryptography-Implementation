#include <stdio.h>

/*unsigned char AES(unsigned char state[4][4],unsigned char key[4][4])*/
extern void ADD (unsigned char a[4][4],unsigned char b[4][4]);
extern void BYTE_SUBSTITUDE_VERSE (unsigned char a[4][4]);
extern void COLUMNMIX_VERSE(unsigned char a[4][4]);
extern void DISPLACE_VERSE(unsigned char a[4][4]);
extern void KEYEXPANSION (unsigned char key[4][4],unsigned char w[4][44]);
extern void roundaction(unsigned char state[4][4],int lun);
static unsigned char state[4][4],key[4][4];
unsigned char temp,temp2,temp3;
unsigned char add_result[4][4];
unsigned char w[4][44];
unsigned char key_lun[4][4];
int i,j,k,g;

int main(void)
{
	
		printf("请输入密钥：\n");
		for(k=0;k<4;k++)
		for(g=0;g<4;g++)
			scanf("%x",&key[k][g]);/*输入密钥*/
	
	
	for(k=0;k<4;k++)
		for(g=0;g<4;g++)
		if(k<=g){
		temp2=key[k][g];
		key[k][g]=key[g][k];
		key[g][k]=temp2;
		}
		KEYEXPANSION(key,w);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%02x ",key[i][j]);
		printf("\n");}
	
	
	printf("请输入密文:\n");
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%x",&state[i][j]);/*输入密文*/
	
	
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		if(i<=j){
		temp=state[i][j];
		state[i][j]=state[j][i]; 
		state[j][i]=temp;
		}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%02x ",state[i][j]);
		printf("\n");}
	printf("\n");
	printf("\n");
	/*
	for(j=0;j<44;j++){
		for(i=0;i<4;i++)
			printf("%02x ",w[i][j]);
		printf("\n");}
		*/
	/*
	BYTE_SUBSTITUDE_VERSE(state);*/
	

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			key_lun[i][j]=w[i][40+j];
	ADD(state,key_lun);
	for(k=9;k>0;k--){
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
			key_lun[i][j]=w[i][j];
	DISPLACE_VERSE(state);
	BYTE_SUBSTITUDE_VERSE(state);
	ADD(state,key_lun);
	

/*打印结果*/
	printf("解密结果如下:\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%02x ",state[i][j]);
		    printf("\n");
		}
	return 0;
}
