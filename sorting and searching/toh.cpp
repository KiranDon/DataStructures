#include <stdio.h>
#include <string.h>
void toh(int discs, char s, char a, char d)
{
	if(discs==1)
	{
		printf("\nDisc %d moves from %c to %c", discs, s, d);
		return;
	}
	toh(discs-1, s, d, a);
	printf("\nDisc %d moves from %c to %c", discs, s, d);
	toh(discs-1, a, s, d);
}
int main()
{
	int discs;
	char s = 'S', d = 'D', a = 'A';
	printf("ENter nmber of discs: ");
	scanf("%d", &discs);
	toh(discs, s, a, d);
	return 0;
}
