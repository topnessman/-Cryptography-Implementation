#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
extern void PRODUCEX (unsigned char a[4][4]);
extern void ADD (unsigned char a[4][4],unsigned char b[4][4]);
extern void AES (unsigned char state[4][4],unsigned char key[4][4]);
int main(void)
{
	int i,j,k,g,n,lun;
	int TLen;
	char r;
	unsigned char key[4][4],key_temp[4][4],state[4][4];
	unsigned char temp2;
	unsigned char zeros[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned char k1[4][4],k2[4][4];
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
			/*for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				key_temp[i][j]=key[i][j];*/
	AES(zeros,key);
	PRODUCEX(zeros);
	for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				k1[i][j]=zeros[i][j];
/*
		for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%02x ",k1[i][j]);
		printf("\n");}
*/
	PRODUCEX(zeros);
	for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				k2[i][j]=zeros[i][j];
/*
		for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%02x ",k2[i][j]);
		printf("\n");}
*/
	printf("请输入n(n>1):\n");
	scanf("%d",&n);

	printf("请输入M1:\n");
		for(k=0;k<4;k++)
			for(g=0;g<4;g++)
				scanf("%x",&state[k][g]);
		for(k=0;k<4;k++)
			for(g=0;g<4;g++)
			if(k<=g){
			temp2=state[k][g];
			state[k][g]=state[g][k];
			state[g][k]=temp2;
			}
		AES(state,key);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			key_temp[i][j]=state[i][j];

	for(i=2;i<n;i++){
	printf("请输入M%d:\n",i);
	for(k=0;k<4;k++)
			for(g=0;g<4;g++)
				scanf("%x",&state[k][g]);
		for(k=0;k<4;k++)
			for(g=0;g<4;g++)
			if(k<=g){
			temp2=state[k][g];
			state[k][g]=state[g][k];
			state[g][k]=temp2;
			}
		ADD(state,key_temp);
		AES(state,key);
		for(k=0;k<4;k++)
			for(g=0;g<4;g++)
				key_temp[k][g]=state[k][g];
	}	


	printf("请输入M%d:\n",n);
	for(k=0;k<4;k++)
			for(g=0;g<4;g++)
				scanf("%x",&state[k][g]);

			printf("消息是否是分组大小的整数倍？1=是,0=否\n");
			scanf("%d",&r);
			if(r==1) ADD(state,k1);
			else if(r==0) ADD(state,k2);
				ADD(state,key_temp);
				AES(state,key);
	for(k=0;k<4;k++)
		for(g=0;g<4;g++)
			if(k<=g){
			temp2=state[k][g];
			state[k][g]=state[g][k];
			state[g][k]=temp2;
			}
	printf("Cn=\n");
for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%02x ",state[i][j]);
}
	printf("\n");
	printf("请输入TLen:\n");
	scanf("%d",&TLen);
	char s[8];
	lun=1;
	while(lun<ceil(TLen/8)+5){
	for(i=0;i<4;i++)
		for(j=0;j<4;j++){
		itoa(state[i][j] , s, 2); 
		sprintf(s , "%08d" , atoi(s));
		if(TLen-8*lun>=0) {printf("%08s ",s);lun=lun+1;}
		else { for(k=0;k<(TLen-8*(lun-1));k++) printf("%c",s[k]);lun=lun+1;}
	}//输出
	}
	printf("\n");
}