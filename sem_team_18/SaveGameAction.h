#pragma once

#include "Action.h"
//Added class

class SaveGameAction : public Action
{
	string FileName;
public:

	SaveGameAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads SaveGameAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Snake Object 
							// then Sets this Snake object to the GameObject Pointer of its Cell


	virtual ~SaveGameAction(); // Virtual Destructor

};

