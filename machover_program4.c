#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#pragma warning(disable:6031)


void Greeting();
int RunBankChoices();
void DisplayBalance(double accountBalance, char account);
double DepositMoney(double accountBalance, char account);
double WithdrawMoney(double accountBalance, char account);

int main()
{
	double checkingBalance = 276.20, savingsBalance = 124.61;
	char C, S;
	int selection;

// test
Greeting();
DisplayBalance(checkingBalance, 'C');
DisplayBalance(savingsBalance, 'S');
selection = RunBankChoices();
//printf("\nYou selected %d\n", selection);

while (selection != -1)
{
	if (selection == 1)
	{
		checkingBalance = DepositMoney(checkingBalance, 'C');
	}
	else if (selection == 2)
	{
		checkingBalance = WithdrawMoney(checkingBalance, 'C');
	}
	else if (selection == 3)
	{
		savingsBalance = DepositMoney(savingsBalance, 'S');
	}
	else if (selection == 4)
	{
		savingsBalance = WithdrawMoney(savingsBalance, 'S');
	}
	else if (selection == 5)
	{
		DisplayBalance(checkingBalance, 'C');
	}
	else if (selection == 6)
	{
		DisplayBalance(savingsBalance, 'S');
	}
	else
	{
		printf("\nYou must select a number from the menu");
	}
	selection = RunBankChoices(); //update
	printf("\nYou selected %d\n", selection);
}
return 0;
}

void Greeting()
{

	printf("******************************************************\n");
	printf("Welcome to the Bank of COP 2220\n");
	printf("It is a pleasure to manage your checking and savings accounts\n");
	printf("******************************************************\n");

}

int RunBankChoices()
{
	int choice;

	printf("*******************************************\n");
	printf("(1) to DEPOSIT to CHECKING ACCOUNT\n");
	printf("(2) to WITHDRAW from CHECKING ACCOUNT\n");
	printf("(3) to DEPOSIT to SAVINGS ACCOUNT\n");
	printf("(4) to WITHDRAW from SAVINGS ACCOUNT\n");
	printf("(5) to display CHECKING ACCOUNT BALANCE\n");
	printf("(6) to display SAVINGS ACCOUNT BALANCE\n");
	printf("(-1) to QUIT\n");

	
	printf("\nSelect an option: ");
	
	scanf("\n%d", &choice);
	printf("\nYou selected %d\n", choice);

	return choice;
}



void DisplayBalance(double accountBalance, char account)
{
	if (account == 'C' || account == 'c')
	{
		printf("Your Checking Balance is $%.2f\n", accountBalance);
	}
	if (account == 'S' || account == 's')
	{
		printf("\nYour Savings Balance is $%.2f\n", accountBalance);
	}

}

double DepositMoney(double accountBalance, char account)
{
	double deposit;

	if (account == 'C' || account == 'c')
	{
		printf("\nThe checking balance is $%.2f\n", accountBalance);
		printf("\nPlease enter an amount you with to add: ");
		scanf("%lf", &deposit);
		accountBalance = accountBalance + deposit;
		printf("\nYour balance is $%.2f\n", accountBalance);
		
	}
	else if (account == 'S' || account == 's')
	{
		printf("\nThe savings balance is $%.2f\n", accountBalance);
		printf("\nPlease enter an amount to deposit\n");
		scanf("%lf", &deposit);
		accountBalance = accountBalance + deposit;
		printf("\nYour balance is $%.2f\n", accountBalance);
		
	}
	return accountBalance;
}
double WithdrawMoney(double accountBalance, char account)
{
	double withdraw;
	if (account == 'C' || account == 'c')
	{
		printf("\nThe checking balance is $%.2f\n", accountBalance);
		printf("\nPlease enter an amount to withdraw: ");
		scanf("%lf", &withdraw);
		if (withdraw <= accountBalance)
		{
			accountBalance = accountBalance - withdraw;
			printf("\nThe checking balance is $%.2f\n", accountBalance);
		}
		else
		{
			printf("\nYou must enter an amount less than your current balance\n");

		}
		
	}
	if (account == 'S' || account == 's')
	{
		printf("\nThe savings balance is $%.2f\n", accountBalance);
		printf("\nPlease enter an amount to withdraw: ");
		scanf("%lf", &withdraw);
		if (withdraw <= accountBalance)
		{
			accountBalance = accountBalance - withdraw;
			printf("\nThe savings balance is $%.2f\n", accountBalance);
		}
		else
		{
			printf("\nYou must enter an amount less than your current balance\n");
		}
	
	}
	return accountBalance;
}