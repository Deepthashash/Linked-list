#include<stdio.h>
#include<stdlib.h>


int main()
{
	int num, *ptr, i, sum = 0;
	printf("Enter the number of elments\n");
	scanf("%d",&num);
	ptr = (num*) malloc(num * sizeof(int));

	if (ptr == NULL)
	{
		printf("Error! memory not allocated");
		exit(0);
	}
	printf("Enter the elemets of the array\n");

	for (int i = 0; i < num; ++i)
	{
		scanf("%d",ptr + i);
		sum += *(ptr + i);
	}

	printf("Sum is %d\n",sum);
	free(ptr);
	return 0;
}
