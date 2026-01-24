#include<stdio.h>
int main(){
	int i, j;
	//Upper Part
	for(i = 0; i < 9; i++){
		for(j = 0; j<=i; j++){
			if(j % 2 == 1){
				printf("%d ", j);
			}
			else{
				printf("* ");	
			}
		}
		printf("\n");
	}
	
	//TEXT
	printf("T E C H W A R 2 0 2 6\n");   
	
	//Lower Part
	for(i=11; i>2; i--){
		for(j=3; j<=i; j++){
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}
