#include <stdio.h>
int main()
{
	int k[2] = {0xfffffffff,13};
	
	int n = printf("%lhi\n",k[0],k[1]);
}
