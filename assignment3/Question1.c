#include <stdio.h>
#include <math.h>

double calculateRepayment(double loan, double interestRate, int years, double installment, double extraPayment, int yearCounter) {
    if (loan <= 0.0 || years <= 0) {
        if (loan < 0.0) loan = 0.0;
        return 0.0;
    }

    double payment = installment + extraPayment;
    if (payment > loan) payment = loan;

    loan -= payment;

    loan += loan * (interestRate / 100.0);

    printf("Year %d: Remaining loan = %.2f\n", yearCounter, loan);

    double futurePaid = calculateRepayment(loan, interestRate, years - 1, installment, extraPayment, yearCounter + 1);

    return payment + futurePaid;
}

int main() {
    double loan = 100000.0;
    double rate = 5.0;
    int years = 3;
    double installment = loan / years; 
    double extraPayment = 0.0; 

    printf("Tracing repayment for loan=%.2f rate=%.2f%% years=%d\n", loan, rate, years);
    printf("Using fixed installment = %.2f per year \n\n", installment);

    printf("Year 0: Remaining loan = %.2f\n", loan);

    double totalPaid = calculateRepayment(loan, rate, years, installment, extraPayment, 1);

    printf("\nTotal paid over %d years = %.2f\n", years, totalPaid);
    printf("\nDemo with extra yearly payment of 5000 added each year:\n");
    printf("Year 0: Remaining loan = %.2f\n", 100000.0);
    totalPaid = calculateRepayment(100000.0, rate, years, installment, 5000.0, 1);
    printf("Total paid (with extra 5000/year) = %.2f\n", totalPaid);

    return 0;
}
