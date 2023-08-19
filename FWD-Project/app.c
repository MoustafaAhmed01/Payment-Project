#include <stdio.h>
#include "app.h"
#include "card.h"
#include "server.h"
#include "terminal.h"
//#include "server.c"

ST_cardData_t User;
ST_terminalData_t Tuser;

void appStart(void)
{
	

repeat:

	if (getCardHolderName(&User) == WRONG_NAME)
	{
		puts(" \nPlease enter a correct name, Try again! \n");
		goto repeat;
	}

repeat2:

	if (getCardExpiryDate(&User) == WRONG_EXP_DATE)
	{
		puts(" \nInvalied date, TRY AGAIN! \n");
		goto repeat2;
	}

repeat3:

	if (getCardPAN(&User) == WRONG_PAN)
	{
		puts(" \nInvalied card number, TRY AGAIN! \n");
		goto repeat3;
	}
repeat4:
	if (getTransactionDate(&Tuser) == WRONG_DATE)
	{
		printf(" Wrong date, TRY AGAIN!\n");
		goto repeat4;
	}
	if (isCardExpired(User, Tuser)==EXPIRED_CARD)
	{
		printf(" Declined, Expired Card! \n");
		exit(1);
	}
repeat5:
	if (getTransactionAmount(&Tuser) == INVALID_AMOUNT)
	{
		printf(" Wrong Amout, TRY AGAIN! \n");
		goto repeat5;
	}
repeat6:
	if (setMaxAmount(&Tuser) == INVALID_MAX_AMOUNT)
	{
		printf(" Wrong amount, TRY AGAIN! \n");
		goto repeat6;
	}
	if (isBelowMaxAmount(&Tuser) == EXCEED_MAX_AMOUNT)
	{
		printf("Declined Amount Exceeding limit\n");
		exit(1);
	}
	if (isValidAccount(User) == ACCOUNT_NOT_FOUND)
	{
		printf(" Declined, Invalid account ");
		exit(1);
	}
	if (isAmountAvailable(&Tuser)==LOW_BALANCE)
	{
		printf("Declined, Insuffecient funds\n");
		exit(1);
	}
	if (isBlockedAccount() == BLOCKED_ACCOUNT)
	{
		printf("Declined, Blocked Account! \n");
		exit(1);
	}
	if (saveTransaction(&Tuser) == SAVING_FAILED)
	{
		printf(" Failed to save \n");
	}

	return;
	
}

int main()
{
	IntializingFun();
	appStart();

	printf(" Thanks for using our system!\n\n");

	return 0;
}