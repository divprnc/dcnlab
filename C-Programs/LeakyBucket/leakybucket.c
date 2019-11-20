#include<stdio.h>
#define capacity 700
#include<stdlib.h>
int initial = 0;
int count = 0;
void bucket(int insert,int flowrate,int i)
{
	if(insert>capacity - initial)
	{
		printf("\nBucket Overflow");
	}
	else
	{
		//sleep(1);
		while(insert > flowrate)
		{
			printf("\n%d bytes outputed",insert);
			insert = insert - flowrate;
			//sleep(1);
			count++;
		}
		if(insert > 0)
		{
			initial = initial + insert;
			if(count == 0)
			{
				printf("\nLast bytes are Outputed %d ",initial);
				initial = 0;
				printf("\n%d Bytes Stored ",initial);
			} 
			else
			{
				if(initial == flowrate)		
				{
					printf("\n%d bytes are Outputed  ",flowrate);
					initial = 0;
				}
				if(initial > flowrate)
				{	
					printf("\nLast bytes are Outputed %d ",initial);
					initial = initial - flowrate;	
					printf("\n%d Bytes Stored ",initial);			
				}
				else
				{
					printf("\n%d Bytes Stored ",initial);
					
				}
					
			}
			printf("\nConforming Packets \n");
		}
	}
	if(i == 5 && initial != 0)
	{
		printf("\n%d Bytes stored is oupputted");
	}
}

void main()
{
	int i,flowrate,insert;
	printf("\nEnter the Output Rate: ");
	scanf("%d",&flowrate);
	for(i=0;i<=5;i++)
	{
		printf("\nEnter the Packet Size : ");
		scanf("%d",&insert);	
		printf("\nPacket Number is %d and Packet Size is %d",i,insert);
		bucket(insert,flowrate,i);
	}
}
