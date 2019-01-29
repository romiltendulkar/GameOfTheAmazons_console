#ifndef MOVE_CLASS_H
#define MOVE_CLASS_H

class Move
{
public:
	Move(int curr_board[10][10], int mx0, int my0, int mx1, int my1, int mx2, int my2, int player)
	{

		for (int xtrav = 0; xtrav < 10; ++xtrav)
		{
			for (int ytrav = 0; ytrav < 10; ++ytrav)
			{
				before_move[xtrav][ytrav] = curr_board[xtrav][ytrav];
			}
		}
		for (int xtrav = 0; xtrav < 10; ++xtrav)
		{
			for (int ytrav = 0; ytrav < 10; ++ytrav)
			{
				after_move[xtrav][ytrav] = curr_board[xtrav][ytrav];
			}
		}
		x0 = mx0;
		y0 = my0;
		x1 = mx1;
		y1 = my1;
		x2 = mx2;
		y2 = my2;
		after_move[x0][y0] = 0;
		after_move[x1][y1] = player;
		after_move[x2][y2] = 3;
		player_id = player;
		
	}



public:
	int player_id, x0, y0, x1, y1, x2, y2;
	int before_move[10][10], after_move[10][10];
};

#endif // !MOVE_CLASS_H
