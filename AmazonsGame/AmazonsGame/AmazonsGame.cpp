#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include "MoveClass.h"
using namespace std;


//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


//we will use this to validate a player's move
int ValidateMove(Move suggested_move)
{
	if (suggested_move.before_move[suggested_move.x0][suggested_move.y0] == suggested_move.player_id)
	{
		int tempx1, tempy1;
		tempx1 = suggested_move.x0;
		tempy1 = suggested_move.y0;
		while (tempx1 != suggested_move.x1 || tempy1 != suggested_move.y1)
		{
			if (tempx1 < suggested_move.x1)
			{
				++tempx1;
			}
			if (tempx1 > suggested_move.x1)
			{
				--tempx1;
			}
			if (tempy1 < suggested_move.y1)
			{
				++tempy1;
			}
			if (tempy1 > suggested_move.y1)
			{
				--tempy1;
			}

			if (suggested_move.before_move[tempx1][tempy1] != 0)
			{
				break;
			}
		}
		if (tempx1 == suggested_move.x1 || tempy1 == suggested_move.y1)
		{
			if (suggested_move.x2 == suggested_move.x0 && suggested_move.y2 == suggested_move.y0)
			{
				return 1;
			}
			while (tempx1 != suggested_move.x2 || tempy1 != suggested_move.y2)
			{
				if (tempx1 < suggested_move.x2)
				{
					++tempx1;
				}
				if (tempx1 > suggested_move.x2)
				{
					--tempx1;
				}
				if (tempy1 < suggested_move.y2)
				{
					++tempy1;
				}
				if (tempy1 > suggested_move.y2)
				{
					--tempy1;
				}

				if (suggested_move.before_move[tempx1][tempy1] != 0)
				{
					break;
				}
			}
			if (tempx1 == suggested_move.x2 && tempy1 == suggested_move.y2)
			{
				return 1;
			}
			else
			{
				return 0;
			}

		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}



//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------

int checkifmovespossible(int curr_player, int curr_board[10][10])
{
	int resultant = 0;
	for (int counter1 = 0; counter1 < 10; ++counter1)
	{
		for (int counter2 = 0; counter2 < 10; ++counter2)
		{
			if (curr_board[counter1][counter2] == curr_player)
			{
				int xtrav, ytrav;
				xtrav = counter1-1; 
				ytrav = counter2;
				while (curr_board[xtrav][ytrav] == 0 && xtrav >= 0)
				{
					--xtrav;
					++resultant;
				}


				xtrav = counter1;
				ytrav = counter2 - 1;
				while (curr_board[xtrav][ytrav] == 0 && ytrav >= 0 )
				{
					--ytrav;
					++resultant;
				}


				xtrav = counter1;
				ytrav = counter2 + 1;
				while (curr_board[xtrav][ytrav] == 0 && ytrav < 10)
				{
					++ytrav;
					++resultant;
				}


				xtrav = counter1 + 1;
				ytrav = counter2;
				while (curr_board[xtrav][ytrav] == 0 && xtrav < 10)
				{
					++xtrav;
					++resultant;
				}

				xtrav = counter1 + 1;
				ytrav = counter2 - 1;
				while (curr_board[xtrav][ytrav] == 0 && xtrav < 10 && ytrav >= 0)
				{
					++xtrav;
					--ytrav;
					++resultant;
				}

				xtrav = counter1 - 1;
				ytrav = counter2 - 1;
				while (curr_board[xtrav][ytrav] == 0 && xtrav >= 0 && ytrav >= 0)
				{
					--xtrav;
					--ytrav;
					++resultant;
				}

				xtrav = counter1 + 1;
				ytrav = counter2 + 1;
				while (curr_board[xtrav][ytrav] == 0 && xtrav < 10 && ytrav < 10)
				{
					++xtrav;
					++ytrav;
					++resultant;
				}

				xtrav = counter1 - 1;
				ytrav = counter2 + 1;
				while (curr_board[xtrav][ytrav] == 0 && xtrav >= 0 && ytrav < 10)
				{
					--xtrav;
					++ytrav;
					++resultant;
				}
			}
		}
	}
	return resultant;
}


//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------

vector<Move> listMoves(int board[10][10], int player)
{
	vector<Move> moveList;
	for (int counter1 = 0; counter1 < 10; ++counter1)
	{
		for (int counter2 = 0; counter2 < 10; ++counter2)
		{
			if (board[counter1][counter2] == player)
			{
				int xtrav, ytrav, xtrav2, ytrav2;
				xtrav = counter1 - 1;
				ytrav = counter2;
				while (board[xtrav][ytrav] == 0 && xtrav >= 0)
				{
					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}


					--xtrav;
				}

				xtrav = counter1 + 1;
				ytrav = counter2;
				while (board[xtrav][ytrav] == 0 && xtrav < 10)
				{
					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}


					++xtrav;
				}

				xtrav = counter1;
				ytrav = counter2 - 1;
				while (board[xtrav][ytrav] == 0 && ytrav >= 0)
				{
					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}


					--ytrav;
				}

				xtrav = counter1;
				ytrav = counter2 + 1;
				while (board[xtrav][ytrav] == 0 && ytrav < 10)
				{
					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}


					++ytrav;
				}

				xtrav = counter1 + 1;
				ytrav = counter2 - 1;
				while (board[xtrav][ytrav] == 0 && xtrav < 10 && ytrav >= 0)
				{
					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}


					++xtrav;
					--ytrav;
				}

				xtrav = counter1 - 1;
				ytrav = counter2 - 1;
				while (board[xtrav][ytrav] == 0 && xtrav >= 0 && ytrav >= 0)
				{
					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}


					--xtrav;
					--ytrav;
				}
				
				xtrav = counter1 - 1;
				ytrav = counter2 + 1;
				while (board[xtrav][ytrav] == 0 && xtrav >= 0 && ytrav < 10)
				{

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}

					--xtrav;
					++ytrav;
				}

				xtrav = counter1 + 1;
				ytrav = counter2 + 1;
				while (board[xtrav][ytrav] == 0 && xtrav < 10 && ytrav < 10)
				{
					xtrav2 = xtrav - 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--ytrav2;
					}

					xtrav2 = xtrav;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav - 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 >= 0)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						--ytrav2;
					}

					xtrav2 = xtrav - 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 >= 0 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						--xtrav2;
						++ytrav2;
					}

					xtrav2 = xtrav + 1;
					ytrav2 = ytrav + 1;
					while ((board[xtrav2][ytrav2] == 0 || (xtrav2 == counter1 && ytrav2 == counter2)) && xtrav2 < 10 && ytrav2 < 10)
					{
						moveList.push_back(Move(board, counter1, counter2, xtrav, ytrav, xtrav2, ytrav2, player));
						++xtrav2;
						++ytrav2;
					}


					++xtrav;
					++ytrav;
				}
			}
		}
	}
	return moveList;
}
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------

Move nextMove(int board[10][10], int player)
{
	vector<int> scopeVec;
	vector<Move> MoveList = listMoves(board, player);
	int sizer = MoveList.size();
	int minval, maxval;
	for (int counter = 0; counter < sizer; ++counter)
	{
		int temp, player2;
		if (player == 1)
		{
			player2 = 2;
		}
		else
		{
			player2 = 1;
		}
		Move tempMove = MoveList[counter];
		temp = checkifmovespossible(player2, tempMove.after_move);
		scopeVec.push_back(temp);
	}

	minval = INT_MAX;
	for (int counter = 0; counter < sizer; ++counter)
	{
		if (scopeVec[counter] < minval)
		{
			minval = scopeVec[counter];
		}
	}

	vector<Move> minMoves;
	for (int counter = 0; counter < sizer; ++counter)
	{
		if (scopeVec[counter] == minval)
		{
			minMoves.push_back(MoveList[counter]);
		}
	}
	scopeVec.clear();
	sizer = minMoves.size();
	maxval = -1;
	for (int counter = 0; counter < sizer; ++counter)
	{
		Move tempMove = minMoves[counter];
		int temp = checkifmovespossible(player, tempMove.after_move);
		scopeVec.push_back(temp);
	}

	for (int counter = 0; counter < sizer; ++counter)
	{
		if (scopeVec[counter] > maxval)
		{
			maxval = scopeVec[counter];
		}
	}
	for (int counter = 0; counter < sizer; counter++)
	{
		if (scopeVec[counter] == maxval)
		{
			Move next = minMoves[counter];
			return next;
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
Move nextMove2(int board[10][10], int player)
{
	vector<int> scopeVec;
	vector<Move> MoveList = listMoves(board, player);
	int sizer = MoveList.size();
	for (int counter = 0; counter < sizer; ++counter)
	{
		int temp, temp2, player2;
		if (player == 1)
		{
			player2 = 2;
		}
		else
		{
			player2 = 1;
		}
		Move tempMove = MoveList[counter];
		temp = checkifmovespossible(player2, tempMove.after_move);
		temp2 = checkifmovespossible(player, tempMove.after_move);
		scopeVec.push_back(temp2 - temp);
	}

	int maxval = -1;

	for (int counter = 0; counter < sizer; ++counter)
	{
		if (scopeVec[counter] > maxval)
		{
			maxval = scopeVec[counter];
		}
	}
	for (int counter = 0; counter < sizer; counter++)
	{
		if (scopeVec[counter] == maxval)
		{
			Move next = MoveList[counter];
			return next;
		}
	}
}


//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------

int main()
{
	char filename[256];
	int	 curr_board[10][10];
	FILE *inFile = NULL, *outFile = NULL;
	bool isPlayer;

	//-------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------
	do
	{
		//Intitializing the file pointer for the input file
		cout << "\n Enter the name of the file containing the starting board: ";
		cin.getline(filename, 256);
		fopen_s(&inFile, filename, "r");
		if (inFile == NULL)
		{
			cout << "\nEnter a valid filename\n";
		}
	} while (inFile == NULL);

	fopen_s(&outFile, "OutputFile.txt", "w+");
	if (outFile == NULL)
	{
		//Error handling for output file
		cout << "\nFailed to create an output file ";
	}

	for (int counter1 = 0; counter1 < 10; ++counter1)
	{
		for (int counter2 = 0; counter2 < 10; ++counter2)
		{
			//initialize the starting board
			fscanf_s(inFile, "%i", &curr_board[counter1][counter2]);
		}
	}

	for (int counter1 = 0; counter1 < 10; ++counter1)
	{
		for (int counter2 = 0; counter2 < 10; ++counter2)
		{
			fprintf_s(outFile, "%i ", curr_board[counter1][counter2]);
		}
		fprintf_s(outFile, "\n");
	}

	char player_answer;
	cout << "\nWill you be playing on the board? (Y/N): ";
	cin >>player_answer;
	if (player_answer == 'Y' || player_answer == 'y')
	{
		isPlayer = true;
	}
	else
	{
		isPlayer = false;
	}


	//-------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------

	int player_turn = 1;			//Turn number
	int GameState = 0;              //0 if ongoing, 1 if player 1 wins, 2 if player 2 wins
	int curr_player = player_turn;	//defining the current player, game starts with player 1
	int en_player = 2;
	vector<Move> moveList;

	while ( GameState == 0)
	{

		//-------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------
		cout << "\nThe current turn is: "<<player_turn;
		cout << "\n The current board state is : \n";
		for (int counter1 = 0; counter1 < 10; ++counter1)
		{
			for (int counter2 = 0; counter2 < 10; counter2++)
			{
				switch (curr_board[counter1][counter2])
				{
				case 0:
					cout << "_ ";
					break;
				
				case 1:
					cout << "B ";
					break;

				case 2:
					cout << "W ";
					break;

				case 3:
					cout << "X ";
					break;

				default:
					break;
				}
			}
			cout << endl;
		}

		//-------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------

		int gameCheck = checkifmovespossible(curr_player, curr_board);
		int gameCheck2 = checkifmovespossible(en_player, curr_board);
		if (gameCheck != 0)
		{
			int movex, movey, movex1, movey1, movex2, movey2, moveValidity;
			if (isPlayer && curr_player == 1)
			{
				
				do
				{

					do
					{
						cout << "\nEnter the row of the piece you want to move: (0-9)";
						cin >> movex;
						if (movex > 9 || movex < 0)
						{
							cout << "\nEnter a value between 0 and 9";
						}
					} while (movex > 9 || movex < 0);
					do
					{
						cout << "\nEnter the column of the piece you want to move: (0-9)";
						cin >> movey;
						if (movey > 9 || movey < 0)
						{
							cout << "\nEnter a value between 0 and 9";
						}
					} while (movey > 9 || movey < 0);

					do
					{
						cout << "\nEnter the row you want to move to: (0-9)";
						cin >> movex1;
						if (movex1 > 9 || movex1 < 0)
						{
							cout << "\nEnter a value between 0 and 9";
						}
					} while (movex1 > 9 || movex1 < 0);
					do
					{
						cout << "\nEnter the column you want to move to: (0-9)";
						cin >> movey1;
						if (movey1 > 9 || movey1 < 0)
						{
							cout << "\nEnter a value between 0 and 9";
						}
					} while (movey1 > 9 || movey1 < 0);


					do
					{
						cout << "\nEnter the row you want to shoot to: (0-9)";
						cin >> movex2;
						if (movex2 > 9 || movex2 < 0)
						{
							cout << "\nEnter a value between 0 and 9";
						}
					} while (movex2 > 9 || movex2 < 0);
					do
					{
						cout << "\nEnter the column you want to shoot to: (0-9)";
						cin >> movey2;
						if (movey2 > 9 || movey2 < 0)
						{
							cout << "\nEnter a value between 0 and 9";
						}
					} while (movey2 > 9 || movey2 < 0);

					Move  pMove(curr_board, movex, movey, movex1, movey1, movex2, movey2, 1);
					moveValidity = ValidateMove(pMove);
					if (moveValidity == 0)
					{
						cout << "\n Please make a valid move. ";
					}
					else
					{
						curr_board[movex][movey] = 0;
						curr_board[movex1][movey1] = curr_player;
						curr_board[movex2][movey2] = 3;
					}
				} while (moveValidity == 0);
			}
			/*else if (gameCheck <= 3 || gameCheck2 <= 3)
			{
				nextMove2(curr_board, curr_player);
			}*/
			else
			{
				Move next = nextMove(curr_board, curr_player);
				curr_board[next.x0][next.y0] = 0;
				curr_board[next.x1][next.y1] = curr_player;
				curr_board[next.x2][next.y2] = 3;
			}
		}
		else
		{
			char val;
			cout << "\nPlayer " << curr_player << " has no moves left";
			cout << "\nPlayer " << en_player << " has won";
			GameState = en_player;
			cout << "\nPress Any key to exit";
			cin >> val;
		}




		
		++player_turn;
		curr_player = player_turn % 2;
		en_player = 2;
		if (curr_player == 0)
		{
			curr_player = 2;
			en_player = 1;
		}
		
	}


	for (int counter1 = 0; counter1 < 10; ++counter1)
	{
		for (int counter2 = 0; counter2 < 10; ++counter2)
		{
			fprintf_s(outFile, "%i ", curr_board[counter1][counter2]);
		}
		fprintf_s(outFile, "\n");
	}
	fclose(inFile);
	fclose(outFile);

}
