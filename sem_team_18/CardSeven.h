#pragma once

#include "Card.h"

// [ CardSeven ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardSeven :	public Card
{
	
public:
	CardSeven(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardSeven which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	virtual void Copy(Card* source);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual ~CardSeven(); // A Virtual Destructor
};

