

#include <stdlib.h>
#include <stdio.h>

int main(int narg, char *argv[]) {
	int n, cont=0,  num=2, divs;

	printf("Entre N: ");
	scanf("%d", &n);

	while ( cont<n ) {
		divs=0;
		for ( int i=1; i<num+1; i++ )
			if ( num%i == 0 ) {
				divs++;
			}
		if ( divs==2 ) {
			printf("%d ", num);
			cont++;
		}
		num++;
	}

	printf("\n");

	return EXIT_SUCCESS;
}
