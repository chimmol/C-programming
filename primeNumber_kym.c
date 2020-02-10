#include <stdio.h>
void main(void) {
	int num;	
	int check ; 
	
	
	while(1){	
		check=0 ; 
		printf("숫자를 입력하세요:");
		scanf("%d",&num );
			if (num==1 ){
				printf("소수\n");
			}
			else {
				for( int i=2 ; i<=num ; i++){			
					if(num%i==0) 
						check++; 	
					}
				if (check==1)
					printf("소수\n");
				else 
					printf("소수아님\n"); 
				}
	
		
		if(num==0){		
				printf("bye~"); 
				break  ; 
				}
	}
}
