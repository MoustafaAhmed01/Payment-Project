#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "server.h"
//-----------------------
ST_accountsDB_t Account[5];
ST_transaction_t TransAcc[5] = { 0 };
int AccountNumber;
#pragma warning(disable : 4996)
_CRT_SECURE_NO_WARNINGS;
//------------------------
void IntializingFun()
{
	FILE* Fptr;
		if ((Fptr = fopen("Accounts_DB.txt", "r")) == NULL)
		{
			printf(" Can't open the file! \n");
			exit(1);
		}
	
		for (int i = 0; i < 4; i++)
		{
			fscanf(Fptr, "%f", &Account[i].balance);
			fscanf(Fptr, "%d", &Account[i].state);
			fscanf(Fptr, "%s", &Account[i].primaryAccountNumber);
		}
		Fptr = fclose(Fptr);
}
 
//------------------------


EN_serverError_t isValidAccount(ST_cardData_t cardData)
{
	for (int i=0; i < 4; i++)
	{
		if (!strcmp(cardData.primaryAccountNumber, Account[i].primaryAccountNumber))
		{
			AccountNumber = i;
			return SERVER_OK;
		}
		else
		{
			// Do nothing
		}
	}
	return ACCOUNT_NOT_FOUND;

}
EN_serverError_t isBlockedAccount()
{
	if (Account[AccountNumber].state == BLOCKED)
	{
		return BLOCKED_ACCOUNT;
	}
	else
	{
		return SERVER_OK;
	}
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	if (termData->transAmount > Account[AccountNumber].balance)
	{
		return LOW_BALANCE;
	}
	return SERVER_OK;
}
EN_serverError_t saveTransaction(ST_terminalData_t* termData)
{
	Account[AccountNumber].balance -= termData->transAmount;

	printf(" Your New balance = %f", Account[AccountNumber].balance);
	return SERVER_OK;
}


