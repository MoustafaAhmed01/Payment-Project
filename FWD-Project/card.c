#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include "card.h"
/*--------------------=----*/
#define true 1
#define false 0
/*------------------------*/

int CharLen(char* cardData)
{
	char NameLen = 0;

	while (*(cardData + NameLen) != NULL)
	{
		NameLen++;
	}
	return NameLen;
}

int OnlyINT(char* cardData, int Len)
{
	for (int i = 0; i < Len; i++)
	{
		if (*(cardData+i) < 48 || *(cardData+i) >57)
		{
			return false;
		}
	}
	
}

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf(" Enter the Cardholder's Name: ");
	gets(cardData->cardHolderName);

	if (cardData->cardHolderName == NULL || CharLen(cardData->cardHolderName) < 20 || CharLen(cardData->cardHolderName) > 24)
	{
		return WRONG_NAME;
	}
	else
	{
		return OK;
	}
	
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf(" Enter the expiry date: ");
	gets(cardData->cardExpirationDate);
	if (CharLen(cardData->cardExpirationDate) == 5)
	{
		if (cardData->cardExpirationDate[0] <= 57 && cardData->cardExpirationDate[1] <= 57 && cardData->cardExpirationDate[2] == 47 && cardData->cardExpirationDate[3] <= 57 && cardData->cardExpirationDate[4] <= 57 && cardData->cardExpirationDate[2] != NULL)
		{
			if (cardData->cardExpirationDate[0] >= 48 && cardData->cardExpirationDate[1] >= 48 && cardData->cardExpirationDate[3] >= 48 && cardData->cardExpirationDate[4] >= 48)
			{
				return OK;
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


	return WRONG_EXP_DATE;

}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf(" Enter the card number: ");
	gets(cardData->primaryAccountNumber);

	if (!OnlyINT(cardData->primaryAccountNumber, CharLen(cardData->primaryAccountNumber)))
	{
		return WRONG_PAN;
	}

	if ((CharLen(cardData->primaryAccountNumber) < 19 && CharLen(cardData->primaryAccountNumber) > 16) && cardData->primaryAccountNumber != NULL)
	{
		return OK;
		
	}
	else
	{
		// Do nothing
	}

	return WRONG_PAN;
}
