#include <stdio.h>

int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int get_weekday (int days ); 
int get_days(int year, int month);
void disp_calendar(int year, int month , int start );
int leap_check(int year);

int main(void ) {

	int year, month;
	int start;  		// 1���� ��µǴ� ������ġ�� ���߱� ���� ����  ( 0 ~ 6�� �� �� ������, 0�� ��� �Ͽ���)
	int days ;		    // �� ���� �� ���� ������ ����
	
	
	// �Է� �κ�
	printf("# Input Year, Month : "); 
	scanf("%d%d", &year, &month);


	// ����� ���� �ϼ� ���
	days = get_days(year, month);	
	
	// ����� ��, ���� �ش��ϴ� 1���� ���� ���
	start = get_weekday(days) ; 
	
	// �޷� ���
	disp_calender(year, month, start);
	
	return 0;
}


// ���� �˻� �Լ�
int leap_check(int year)
{
	if(year%4!=0) return 0;
	else if(year%100!=0) return 1;
	else if(year%400==0) return 1;
	else return 0;
}

// ����� ���� �ϼ� ���
int get_days(int year, int month  )	{
    int days=365 ; 
	for (int i=1 ; i<year; i++){		
		if(leap_check(i)==1) 
			days += 366 ; 
		else 
			days += 365 ; 
	}
	
	if (leap_check(year)==1){
		mdays[1]=29 ; 
		for(int j=0 ; j<month-1 ; j++)
			days += mdays[j];
		}
	else {
	    mdays[1]=28 ; 
		for(int j=0 ; j <month-1 ; j++)
			days += mdays[j];
		}
	return days ; 
}


// ����� ��, ���� �ش��ϴ� 1���� ���� ���
int get_weekday(int days)
{
	int start;
	start = days % 7 ; 
	return start ; 
}

// �޷� ���
void  disp_calender(int year, int month, int start){

	printf("=====================< %d . %d >==================\n\n", year, month );
	printf("---------------------------------------------------\n" ); 
	printf("SUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
   	printf("---------------------------------------------------\n" ); 
 
    //���� ���Ͽ� ���� ����
    for (int i = 0;i < start ;i++) {
        printf("\t");     // ���� ��ŭ ���� ��  
    }
 
    for (int j = 1 ; j<= mdays[month - 1] ; j++) {  
        printf("%d\t", j);
        if (start == 6) {
            printf("\n");  //���ְ� ������ �����ٿ� ���  
			start = -1;    // ������ �Ͽ��� ���� �����ϵ��� �ٽ� �ʱ�ȭ     
        }
        start++;
    }
}
	
