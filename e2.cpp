
#include <iostream>

int fib(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}

	return fib(n-1) + fib(n-2);
}

int main()
{
	int sum = 0;
	int i = 2;
	while (true)
	{
		int f = fib(i);
		if (f > 4000000)
		{
			break;
		}
		
		if (f % 2 == 0)
		{
			sum += f;
		}
	
		i++;
	}
	
	printf("%d\n", sum);

	return 0;
}
