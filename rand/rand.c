#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	int x = atoi(argv[1]);
	srand(time(NULL));
	printf("%d %d 11\n", x, x);
	int i, j;
	for(i = 0; i < x; i++){
		for(j = 0; j < x; j++){
			int rand_number = rand()%x;
			printf("%d ", rand_number);
		}
		printf("\n");
	}
	for(i = 0; i < 11; i++){
		int posx = rand()%x;
		int posy = rand()%x;
		printf("%d %d\n", posx, posy);
	}
	return 0;
}