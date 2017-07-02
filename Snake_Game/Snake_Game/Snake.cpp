#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Snake.h"

bool GameOver;
int * SnakeTailPosXArr;
int * SnakeTailPosYArr;
int SnakeHeadPosX, SnakeHeadPosY;
int FruitPosX, FruitPosY;
int Score = 0;
int Size;

eDirection Dir;

void Setup()
{
	GameOver = false;
	Dir = STOP;

	SnakeHeadPosX = Width / 2;
	SnakeHeadPosY = Height / 2;

	SnakeTailPosXArr = new int[Score];
	SnakeTailPosYArr = new int[Score];

	FruitPosX = 1 + rand() % (Width - 2);
	FruitPosY = 1 + rand() % (Height - 2);
	Score = 0;
}

void Draw()
{
	using std::cout;
	using std::endl;

	bool flag = false;

	system("cls");

	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			flag = false;
			if ((i == 0) ||
				(i == Height - 1)) {
				cout << "#";
				continue;
			}
			else if (j == 0 && i != 0 ||
				j == Width - 1) {
				cout << "#";
				continue;
			}

			if (i == SnakeHeadPosY && j == SnakeHeadPosX) {
				cout << "O";
				continue;
			}
			else if (i == FruitPosY && j == FruitPosX) {
				cout << "F";
				continue;
			}
			else {
				for (int k = 0; k < Size; ++k) {
					if (i == SnakeTailPosYArr[k] &&
						j == SnakeTailPosXArr[k]) {
						flag = true;
						cout << "o";
					}
				}
				/*if (flag) {
					continue;
				}*/
			}

			if (!flag) {
				cout << " ";
			}
		}
		cout << endl;

	}

	cout << SnakeHeadPosY;
}

void Input()
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
		case 'W':
			if (Dir == DOWN && Score > 0) {
				break;
			}
			Dir = UP;
			break;
		case 's':
		case 'S':
			if (Dir == UP && Score > 0) {
				break;
			}
			Dir = DOWN;
			break;
		case 'a':
		case 'A':
			if (Dir == RIGHT && Score > 0) {
				break;
			}
			Dir = LEFT;
			break;
		case 'd':
		case 'D':
			if (Dir == LEFT && Score > 0) {
				break;
			}
			Dir = RIGHT;
			break;
		case 'x':
		case 'X':
			GameOver = true;
			break;
		}
	}
}

void Logic()
{
	int tempX1, tempX2, tempY1, tempY2;

	tempX1 = SnakeHeadPosX;
	tempY1 = SnakeHeadPosY;

	switch (Dir)
	{
	case LEFT:
		--SnakeHeadPosX;
		break;
	case RIGHT:
		++SnakeHeadPosX;
		break;
	case UP:
		--SnakeHeadPosY;
		break;
	case DOWN:
		++SnakeHeadPosY;
		break;
	default:
		break;
	}

	if (SnakeHeadPosX == FruitPosX && SnakeHeadPosY == FruitPosY) {
		FruitPosX = 1 + rand() % (Width - 2);
		FruitPosY = 1 + rand() % (Height - 2);

		++Score;

		Size = Score * 2;

		SnakeTailPosXArr = (int *)realloc(SnakeTailPosXArr, sizeof(int) * Size);
		SnakeTailPosYArr = (int *)realloc(SnakeTailPosYArr, sizeof(int) * Size);
	}

	if (Score > 0) {
		for (int i = 0; i < Size; ++i) {
			tempX2 = SnakeTailPosXArr[i];
			tempY2 = SnakeTailPosYArr[i];

			SnakeTailPosXArr[i] = tempX1;
			SnakeTailPosYArr[i] = tempY1;

			tempX1 = tempX2;
			tempY1 = tempY2;
		}
	}

	if (Score > 0) {
		for (int i = 0; i < Size; ++i) {
			if (SnakeHeadPosX == SnakeTailPosXArr[i] &&
				SnakeHeadPosY == SnakeTailPosYArr[i]) {
				GameOver = true;
				break;
			}
		}
	}

	if (SnakeHeadPosY == 0) {
		SnakeHeadPosY = Height - 2;
		Dir = UP;
	}
	else if (SnakeHeadPosX == 0) {
		SnakeHeadPosX = Width - 2;
		Dir = LEFT;
	}
	else if (SnakeHeadPosX == Width - 1) {
		SnakeHeadPosX = 1;
		Dir = RIGHT;
	}
	else if (SnakeHeadPosY == Height - 1) {
		SnakeHeadPosY = 1;
		Dir = DOWN;
	}
}