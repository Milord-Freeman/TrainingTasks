//https://www.codewars.com/kata/529bf0e9bdf7657179000008/train/cpp

bool validSolution(unsigned int board[9][9])
{
	bool numsRow[9][9] = { {false} };
	bool numsCol[9][9] = { {false} };
	bool numsNine[9][9] = { {false} };

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] < 1 || board[i][j] > 9)
			{
				return false;
			}
			else
			{
				if (numsRow[i][board[i][j] - 1] && numsCol[j][board[i][j] - 1] && numsNine[i / 3 + j / 3 * 3][board[i][j] - 1])
				{
					return false;
				}
				else
				{
					numsRow[i][board[i][j] - 1] = true;
					numsCol[j][board[i][j] - 1] = true;
					numsNine[i / 3 + j / 3 * 3][board[i][j] - 1] = true;
				}
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (!numsRow[i][j] || !numsCol[i][j] || !numsNine[i][j])
			{
				return false;
			}
		}
	}

	return true;
}