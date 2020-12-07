#include <stdio.h>
#include <string.h>
#include "myBank.h"
#define MAX 50

int counter = 0;
float account[2][50] = {{0},{0}}; 

void openAccount(double n) //opens an account.
{
	
	if (counter == MAX) //checks for 50 accounts.
	{
		printf("Can't open account, 50 accounts already exist\n");
		return;
	}
	if (n < 0) //cant deposit a negative amount.
	{
		printf("Cannot deposit a negative amount\n");
		return;
	}
	
	for (int i = 0; i < 50; i++) //find the first closed account
	{
		if(account[0][i] != 1) 
		{
			account[0][i] = 1; //open it
			account[1][i] = n;//deposit
			printf("new account number is: %d\n", i + 901);	
			counter++;//add closed accounts.
			return;        
		}
	}
	
	
}

void checkBalance(int n) 
{
	if((account[0][n-901]) != 1) //if value isn't 1 than the account is closed.
	{
		printf("This account is closed\n");
		return;
	}
	printf("The balance of account number %d is: %.2f\n", n, account[1][n-901]);
	return;
}

void deposit(int n, double w)
{
	if((account[0][n-901]) != 1)//same as before
	{
		printf("This account is closed\n");
		return;
	}
	if(n < 0 )//same as before
	{
		printf("Cannot deposit, not a valid number\n");
		return;
	}
	else
	{
		account[1][n-901] += w;//add the deposit to the balance
		printf("The new balance: %.2f\n", account[1][n-901]);
		return;
	}
}

void withdraw(int n, double w)
{
	if((account[0][n-901]) != 1)//same as before
	{
		printf("This account is closed\n");
		return;
	}
	
	if( w < 0)// same as before
	{
		printf("Cannot withdraw a negative amount\n");
		return;
	}		
	
	
	if (account[1][n-901] - w < 0)//self explanitory
	{
		printf("Cannot withdraw more than the balance\n");
		return;
	}
	else
	{
		account[1][n-901] -= w; //withdraw the amount
		printf("The new balance is: %.2f\n", account[1][n-901]);
		return;
	}
}

void close(int n)
{
	if((account[0][n-901]) != 1)//same as before
	{
		printf("This account is already closed\n");
		return;
	}
	else
	{
		account[0][n-901] = 0;//set to close
		account[1][n-901] = 0;//reset account
		counter--;//reduce by 1 the amount of open accounts
		printf("Closed account number %d 901\n", n);
		return;
		
	}
	
}

void interest(double n)
{
	if(n > 0) //if positive interest
	{
		for(int i = 0; i < 50; i++)//for every open account
		{
			if (account[0][i] == 1)
			{ 
				account[1][i] = account[1][i]*(1+(n/100));//add the interest
			}
		}	
			return;
	} 
	else if(n < 0) //if negative interest
	{
		printf("Invalid interest rate\n");
			return;
	}
	else
	{
		return;
	}
}

void print()
{
	for(int i = 0; i < 50; i++) //prints every open account's balance
	{
		if (account[0][i] == 1)
		{ 
			printf("The balance of account number %d is: %.2f\n", 901+i, account[1][i]);
		}
	}
	return;
		
}

void exitProg()//exits the program completely.
{
	bzero(account[0],50); //resets accounts
	bzero(account[1],50);
	counter = 0;
	exit(0);
}

void menu(){ //the function that enables the entire program. dispalys the menu constantly after an operation completes or fails, unless we exited the program, then it stops.
while(1)
 {
char c1; 
char t;
if(c1 != 10)
{
printf("\nPlease choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
 //dispalys the menu
 
 if (scanf("%c",&c1) != 0 && (c1 != 10))//if we scanned a char
 { 
 	
		if(c1 == 'O' || c1 == 'o') //find the correct operation
	{
		float n;
		printf("Please enter amount for deposit: ");
		if(!(scanf("%f",&n) == 1))//if we didn't scan a double
		{
			printf("Failed to read the amount\n");
			
		}
		else //if all is well
		{
		openAccount(n); //complete operation
		
		
		}
		t = getchar();
	}
 
	else if(c1 == 'B' || c1 == 'b')
	{
		int n; 
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number");
			
		}
		else
		{
		checkBalance(n);
		
		
		}
		t = getchar();
	}
 
	else if(c1 == 'D' || c1 == 'd')
	{
		int n;
		float a;
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number\n");
		}
		
		if((account[0][n-901]) != 1)//same as before
		{
		printf("This account is closed\n");
		}
		
		printf("Please enter the amount to deposit: ");
		if(!(scanf("%f",&a) == 1))
		{
			printf("Failed to read the amount\n");
			
			
		}
		else 
		{
			deposit(n,a);
		}
		t = getchar();
	}
 
	else if(c1 == 'W' || c1 == 'w')
	{
		int n;
		float a;
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number\n");
			;
	
		}
		
		if((account[0][n-901]) != 1)//same as before
		{
			printf("This account is closed\n");
			
		}
		
		printf("Please enter the amount to withdraw: ");
		if(!(scanf("%f",&a) == 1))
		{
			printf("Failed to read the amount\n");
			
		}
		else 
		{
			withdraw(n,a);
			
		}
		t = getchar();
	}
 
	else if(c1 == 'C' || c1 == 'c')
	{
		int n;
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number\n");
			
		
		}
		else 
		{
			close(n);

		}
		t = getchar();	
	}
 
	else if(c1 == 'I'|| c1 == 'i')
	{
		float n;
		printf("Please enter interest rate: ");
		if(!(scanf("%f",&n) == 1))
		{
			printf("Failed to read the interest rate\n");
			
			
		}
		else
		{
		interest(n);
		
		
		}
		t = getchar();
	}
 
	else if(c1 == 'P' || c1 == 'p')
	{
		print();
		t = getchar();
	
	}
 
	else if(c1 == 'E' || c1 == 'e')
	{
		exitProg(); //exits program
	}
	else if(c1  == '\n' || c1==10)
	{
		t = getchar();
	}
	
	else 
	{
		printf("Invalid transaction type\n"); //if invalid operation
		t = getchar();
	
	}
	}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else //in case a user enters a new line, wait for the next input that's not a new line and don't print menu 
	{
if (scanf("%c",&c1) != 0 && (c1 != 10))//if we scanned a char
 { 
 	
		if(c1 == 'O' || c1 == 'o') //find the correct operation
	{
		float n;
		printf("Please enter amount for deposit: ");
		if(!(scanf("%f",&n) == 1))//if we didn't scan a double
		{
			printf("Failed to read the amount\n");
			
		}
		else //if all is well
		{
		openAccount(n); //complete operation
		
		
		}
		t = getchar();
	}
 
	else if(c1 == 'B' || c1 == 'b')
	{
		int n; 
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number");
			
		}
		else
		{
		checkBalance(n);
		
		
		}
		t = getchar();
	}
 
	else if(c1 == 'D' || c1 == 'd')
	{
		int n;
		float a;
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number\n");
		}
		
		if((account[0][n-901]) != 1)//same as before
		{
		printf("This account is closed\n");
		}
		
		printf("Please enter the amount to deposit: ");
		if(!(scanf("%f",&a) == 1))
		{
			printf("Failed to read the amount\n");
			
			
		}
		else 
		{
			deposit(n,a);
		}
		t = getchar();
	}
 
	else if(c1 == 'W' || c1 == 'w')
	{
		int n;
		float a;
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number\n");
			;
	
		}
		
		if((account[0][n-901]) != 1)//same as before
		{
			printf("This account is closed\n");
			
		}
		
		printf("Please enter the amount to withdraw: ");
		if(!(scanf("%f",&a) == 1))
		{
			printf("Failed to read the amount\n");
			
		}
		else 
		{
			withdraw(n,a);
			
		}
		t = getchar();
	}
 
	else if(c1 == 'C' || c1 == 'c')
	{
		int n;
		printf("Please enter account number: ");
		if(!(scanf("%d",&n) == 1))
		{
			printf("Failed to read account number\n");
			
		
		}
		else 
		{
			close(n);

		}
		t = getchar();	
	}
 
	else if(c1 == 'I'|| c1 == 'i')
	{
		float n;
		printf("Please enter interest rate: ");
		if(!(scanf("%f",&n) == 1))
		{
			printf("Failed to read the interest rate\n");
			
			
		}
		else
		{
		interest(n);
		
		
		}
		t = getchar();
	}
 
	else if(c1 == 'P' || c1 == 'p')
	{
		print();
		t = getchar();
	
	}
 
	else if(c1 == 'E' || c1 == 'e')
	{
		exitProg(); //exits program
	}
	else if(c1  == '\n' || c1==10)
	{
		t = getchar();
	}
	
	else 
	{
		printf("Invalid transaction type\n"); //if invalid operation
		t = getchar();
	
	}
	}
	}
}
}




















