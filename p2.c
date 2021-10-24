#include<stdio.h>
int main()
{
	int temperature, humidity;

	scanf("%d", &temperature);
	scanf("%d", &humidity);

	if((temperature >= 20 && temperature <= 35) && (humidity >= 20 && humidity <= 75))
	{
		printf("breezy casuals");
	}

	else if(temperature < 20)
	{
		printf("woolly woolens");
	}

	else if(temperature > 35)
	{
		printf("summery stuff");
	}

	return(0);

}
