#include <stdio.h>
int main()
{
	int k[2] = {0xff,13};
	
	int n = printf("%hhhki\n",k[0]);
	printf("%d",n);
}
