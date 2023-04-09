#include "SaveGameAction.h"
#include"Grid.h"
#include<fstream>
SaveGameAction::SaveGameAction (ApplicationManager* pApp): Action(pApp)
{

}

void SaveGameAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please, Enter FileName");
	FileName = pIn->GetSrting(pOut);
	FileName += ".txt";
}

 void SaveGameAction::Execute()
{
	 ReadActionParameters();
	 Grid* pGrid = pManager->GetGrid();
	 Output* pOut = pGrid->GetOutput();
	 Input* pIn = pGrid->GetInput();
	 ofstream outputFile;
	 outputFile.open(FileName, ios::out);
	 pOut->PrintMessage("Saving File, Click to continue");
	 pIn->GetCellClicked();
	 pOut->ClearStatusBar();
	 pGrid->SaveAll(outputFile);
	 outputFile.close();
}
						

 SaveGameAction::~SaveGameAction()
{

}