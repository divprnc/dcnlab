 #include<stdio.h>

struct node 
{
	unsigned from[20];
	unsigned dist[20];
}rt[10];


int main()
{
	int count = 0;
	int i,j,k,n,dmat[20][20];
	printf("\nEnter the number of nodes: ");
	scanf("%d",&n);
	printf("\n\nEnter the cost matrix...........\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j<n; j++)
		{
			scanf("%d",&dmat[i][j]);
			dmat[i][i] = 0;
			rt[i].dist[j] = dmat[i][j];	
			rt[i].from[j] = j;
		}
	}

	do{
		count =0;
		for(i = 0; i<n;i++)
		{
			for(j = 0;j<n;j++)
			{
				for(k = 0;k<n;k++)
				{
					if(rt[i].dist[j] > dmat[i][k] + rt[k].dist[j])
					{
						rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
						rt[i].from[j] = k;
						count++;
					}
				}
			}
		}
	}while(count != 0);

	//Printing the values
	for(i = 0;i<n;i++)
	{
		printf("\nState value of the Router :  %d",i+1);
		for(j=0;j<n;j++)
		{
			printf("\t\nTo Node %d to %d , Distance = %d\n",j+1,rt[i].from[j] + 1,rt[i].dist[j]);
		}
	}
}
