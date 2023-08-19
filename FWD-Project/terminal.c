#include <stdio.h>
#include"terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf(" Enter the Transaction date: ");
	gets(termData->transactionDate);
	if (CharLen(termData->transactionDate) == 10)
	{
		if (termData->transactionDate[0] <= 57 && termData->transactionDate[1] <= 57 && termData->transactionDate[2] == 47 && termData->transactionDate[3] <= 57 && termData->transactionDate[4] <= 57 && termData->transactionDate[5] <= 47 && termData->transactionDate[6] <= 57 && termData->transactionDate[7] <= 57 && termData->transactionDate[8] <= 57&& termData->transactionDate[9] <= 57 &&termData->transactionDate[2] != NULL)
		{
			if (termData->transactionDate[0] >= 48 && termData->transactionDate[1] >= 48 && termData->transactionDate[3] >= 48 && termData->transactionDate[4] >= 48 && termData->transactionDate[6] >= 48 && termData->transactionDate[7] >= 48 && termData->transactionDate[8] >= 48 && termData->transactionDate[9] >= 48)
			{
				return TERMINAL_OK;
			}
			else
			{
				// Do nothing
			}
		}
		else
		{
			// Do nothing
		}
	}
	else
	{
		// Do nothing
	}
	return WRONG_DATE;
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	if (cardData.cardExpirationDate[3] > termData.transactionDate[8])
	{
		return TERMINAL_OK;
	}
	if (cardData.cardExpirationDate[3] < termData.transactionDate[8])
	{
		return EXPIRED_CARD;
	}
	if (cardData.cardExpirationDate[4] > termData.transactionDate[9])
	{
		return TERMINAL_OK;
	}
	if (cardData.cardExpirationDate[4] < termData.transactionDate[9])
	{
		return EXPIRED_CARD;
	}
	if (cardData.cardExpirationDate[0] > termData.transactionDate[3])
	{
		return TERMINAL_OK;
	}
	if (cardData.cardExpirationDate[0] < termData.transactionDate[3])
	{
		return EXPIRED_CARD;
	}
	if (cardData.cardExpirationDate[1] > termData.transactionDate[4])
	{
		return TERMINAL_OK;
	}
	else
	{
		return EXPIRED_CARD;
	}
	
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf(" The transaction amount : ");
	scanf_s("%f", &termData->transAmount);
	if ((int)termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	printf(" Set the MaxAmount : ");
	scanf_s("%f", &termData->maxTransAmount);

	if (termData->maxTransAmount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
	
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}
