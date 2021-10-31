#include <stdio.h>

int matrix[10][10]; //adjacency matrix
int visited[10];	//array to keep track of visited nodes
int n;				//no of cities (max 10)
int cost = 0;

void input()
{
	int i, j;

	printf("Enter the number of cities: ");
	scanf("%d", &n);

	printf("\nEnter the cost matrix row by row. Seperate the elements by spaces.\n\n");

	for (i = 0; i < n; i++)
	{
		printf("Enter elements of row %d:", i + 1);

		for (j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
		printf("\n");
		visited[i] = 0;
	}

	printf("\nYour cost matrix is:");

	for (i = 0; i < n; i++)
	{
		printf("\n");

		for (j = 0; j < n; j++)
			printf("%d\t", matrix[i][j]);
	}
	printf("\n");
}

int least(int city)
{
	int i, ncity = 999;
	int min = 999, kmin;

	//T (i , s) = min ( ( i , j) + T ( j , S – { j }) )

	for (i = 0; i < n; i++) // iterating over each city i to find min cost and next city
	{
		if ((matrix[city][i] != 0) && (visited[i] == 0))
			// if there is a path from current city to i && i is not visited
			if (matrix[city][i] + matrix[i][city] < min)
			{
				//finding min cost
				min = matrix[i][city] + matrix[city][i];
				kmin = matrix[city][i]; //cost of going from current city to i
				ncity = i;				//next city is set to i
			}
	}

	if (min != 999)
		cost += kmin; //cost is updated

	return ncity;
}

void mincost(int city)
{
	int i;
	int ncity; //next city to be visited

	visited[city] = 1;			//current city set to visited
	printf("%d--->", city + 1); //add this city to path

	ncity = least(city); //using least method to find next city

	if (ncity == 999) //will happen if all cities visited
	{
		ncity = 0;					 //then we're back to source
		printf("%d", ncity + 1);	 //adding to path
		cost += matrix[city][ncity]; //adding cost of going from current city to 0

		return;
	}

	mincost(ncity); //if more cities are remaining
}

int main()
{
	input();

	printf("\nYour shortest path is: ");
	mincost(0); //passing 0 because starting vertex

	printf("\n\nMinimum cost is %d.\n ", cost);

	return 0;
}