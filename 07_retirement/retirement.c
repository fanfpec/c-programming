#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double balance_new (retire_info info, double balance, int age){
  int month_count = 0;
  //  printf ( "Age %3d month %2d you have $%.2lf\n", ( age + month_count ) / 12, ( age + month_count ) % 12, balance );
  while ( month_count < info.months){
    printf ( "Age %3d month %2d you have $%.2lf\n", ( age + month_count ) / 12, ( age + month_count ) % 12, balance );
    balance *= ( 1 + info.rate_of_return * .01 / 12 ); //adding returns
    balance += info.contribution; // adding contribution
    month_count += 1; // next month
  }
  return balance;
}

void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired) //info about being retired
{
  double balance = balance_new( working, initial, startAge); 
  balance_new( retired, balance, startAge + working.months);
}

int main (void){
  retire_info working;
  retire_info retired;
  working.months = 489;
  working.rate_of_return = 4.5;
  working.contribution = 1000;
  retired.months = 384;
  retired.rate_of_return = 1;
  retired.contribution = -4000;
  
  retirement( 327, 21345, working, retired);
  
  return EXIT_SUCCESS;
}
 
  
