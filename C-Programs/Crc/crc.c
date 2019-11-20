#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[200],cs[100],g[] = "100010000001000001";
int a, e, c;

void xor()
{
	for(c=1;c<N;c++)
	{
		cs[c] = ((cs[c] == g[c]) ? '0' : '1');
	}
}

void crc()
{
	for(e=0;e<N;e++)
	{
		cs[e] = t[e];
	}
	do{
		if(cs[0] == '1')
		{
			xor();
		}
		for(c=0;c<N-1;c++)
		{
			cs[c] = cs[c+1];
		}
		cs[c] = t[e++];
	}while(e<=a+N-1);
}

void main()
{
	int i,j;
	printf("\nEnter the Polynomial: ");
	scanf("%s",&t);
	a = strlen(t);
	printf("\nGenerating Polynomial is : %s",g);
	for(i=a;i<=a+N-1;i++)
	{
		t[i] = '0';
	}
	printf("\nModified t[u] is : %s",t);
	crc();
	printf("\nChecksum is : %s",cs);
	for(e=a;e<a+N-1;e++)
	{
		t[e] = cs[e-a];
	}
	printf("\nFinal CodeWord is : %s",t);
	printf("\nTest Error Detection 0(Yes) / 1(No) : ");
	scanf("%d",&e);
	if(e == 0)
	{
		printf("\nEnter the position where error is inserted : ");
		scanf("%d",&e);
		t[e] = (t[e] == '0') ? '1':'0';
		printf("\nErroneous data : %s",t);
	}
	crc();
	for(e = 0; (e<N-1) && (cs[e] != '1') ; e++);
	if(e<N-1)
	{
		printf("\nError Detected\n");
	}
	else
	{
		printf("\nNo Error Detected\n");
	}

}
