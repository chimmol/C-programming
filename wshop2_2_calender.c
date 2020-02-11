#include <stdio.h>

int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int get_weekday (int days ); 
int get_days(int year, int month);
void disp_calendar(int year, int month , int start );
int leap_check(int year);

int main(void ) {

	int year, month;
	int start;  		// 1일이 출력되는 시작위치를 맞추기 위한 변수  ( 0 ~ 6이 될 수 있으며, 0의 경우 일요일)
	int days ;		    // 각 월의 일 수를 저장할 변수
	
	
	// 입력 부분
	printf("# Input Year, Month : "); 
	scanf("%d%d", &year, &month);


	// 출력할 달의 일수 계산
	days = get_days(year, month);	
	
	// 출력할 년, 월에 해당하는 1일의 요일 계산
	start = get_weekday(days) ; 
	
	// 달력 출력
	disp_calender(year, month, start);
	
	return 0;
}


// 윤년 검사 함수
int leap_check(int year)
{
	if(year%4!=0) return 0;
	else if(year%100!=0) return 1;
	else if(year%400==0) return 1;
	else return 0;
}

// 출력할 달의 일수 계산
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


// 출력할 년, 월에 해당하는 1일의 요일 계산
int get_weekday(int days)
{
	int start;
	start = days % 7 ; 
	return start ; 
}

// 달력 출력
void  disp_calender(int year, int month, int start){

	printf("=====================< %d . %d >==================\n\n", year, month );
	printf("---------------------------------------------------\n" ); 
	printf("SUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
   	printf("---------------------------------------------------\n" ); 
 
    //시작 요일에 맞춰 정렬
    for (int i = 0;i < start ;i++) {
        printf("\t");     // 요일 맡큼 공백 탭  
    }
 
    for (int j = 1 ; j<= mdays[month - 1] ; j++) {  
        printf("%d\t", j);
        if (start == 6) {
            printf("\n");  //한주가 끝나면 다음줄에 출력  
			start = -1;    // 요일을 일요일 부터 시작하도록 다시 초기화     
        }
        start++;
    }
}
	
