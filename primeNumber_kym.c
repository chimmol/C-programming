#include <stdio.h>
void main(void) {
	int num;	
	int check ; 
	
	
	while(1){	
		check=0 ; 
		printf("���ڸ� �Է��ϼ���:");
		scanf("%d",&num );
			if (num==1 ){
				printf("�Ҽ�\n");
			}
			else {
				for( int i=2 ; i<=num ; i++){			
					if(num%i==0) 
						check++; 	
					}
				if (check==1)
					printf("�Ҽ�\n");
				else 
					printf("�Ҽ��ƴ�\n"); 
				}
	
		
		if(num==0){		
				printf("bye~"); 
				break  ; 
				}
	}
}
