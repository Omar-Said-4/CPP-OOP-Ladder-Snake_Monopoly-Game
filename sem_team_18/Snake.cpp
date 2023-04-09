#include "Snake.h"
#include"Ladder.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{



	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You have reached a Snake, Click to continue ");
	pGrid->GetInput()->GetCellClicked();
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}
//Added
 bool Snake::IsOverlapping(GameObject* newobj)
{
	 int start_of_me = GetPosition().GetCellNum();
	 int end_of_me = GetEndPosition().GetCellNum();
	 if (newobj != NULL)
	 {
		 if (dynamic_cast<Snake*>(newobj))
		 {
			 int start_y_of_me = GetPosition().VCell();
			 int start_y_of_passed = dynamic_cast<Snake*>(newobj)->GetPosition().VCell();
			 int end_y_of_me = GetEndPosition().VCell();
			 int end_y_of_passed = dynamic_cast<Snake*>(newobj)->GetEndPosition().VCell();
			 int x_of_me = GetPosition().HCell();
			 int x_of_passed = dynamic_cast<Snake*>(newobj)->GetPosition().HCell();
			 if (x_of_me == x_of_passed)
			 {
				 if (start_y_of_me == start_y_of_passed || end_y_of_me == end_y_of_passed||end_y_of_me == start_y_of_passed)
					 return true;
				 if ((end_y_of_me < end_y_of_passed) && (start_y_of_me > end_y_of_me))
					 return true;
				 if ((end_y_of_passed < end_y_of_me) && (start_y_of_passed > start_y_of_me))
					 return true;
			 }
		 }
		 else if (dynamic_cast<Ladder*>(newobj))
		 {
			 int ladder_start_cell = dynamic_cast<Ladder*>(newobj)->GetPosition().GetCellNum();
			 if (ladder_start_cell == end_of_me)
				 return true;
		 }
		 return false;
	 }
}
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}
void Snake::Save(ofstream& OutFile)
{
	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;

}
void Snake::Load(ifstream& Infile)
{
	int start, end;
	Infile >> start >> end;
	CellPosition cp;
	position = cp.GetCellPositionFromNum(start);
	endCellPos = cp.GetCellPositionFromNum(end);
}

Snake::~Snake()
{
}