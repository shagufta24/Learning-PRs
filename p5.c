#include<stdio.h>
int main()
{
	char ch;

	scanf("%c", &ch);
	
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		printf("ALPHABET");
	}

	else if (ch >= '0' && ch <= '9')
	{
		printf("NUMBER");
	}

	else 
	{
		printf("SYMBOL");
	}

	return(0);
}