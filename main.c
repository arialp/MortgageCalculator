#include <stdio.h>

int main(void){
  //Mortgage Calculator
  double amount = 0;
  int term = 0;
  double interest = 0;
  double pow_interest = 0;
  double monthly_payment = 0;

  printf("%s", "Enter mortgage amount: $");
  scanf("%lf", &amount);
  printf("%s", "Enter mortgage term in years:");
  scanf("%d", &term);
  printf("%s", "Enter interest rate (%):");
  scanf("%lf", &interest);

  interest /= 1200; // Monthly interest rate [0..1]

  // Loop to calculate (interest + 1)^(term * 12)
  int i = 1;
  double power = 1;

  while(i <= term * 12){
    power *= interest + 1;
    i++;
  }

  pow_interest = power;
  // End loop to calculate (interest + 1)^(term * 12)

  monthly_payment = amount * interest * pow_interest / (pow_interest - 1);

  printf("The monthly payable interest is: $%.2lf\n", monthly_payment);

  return 0;
}
