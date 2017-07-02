#include<iostream>
#include<Windows.h>
#include<ctime>
#include"Snake.h"

extern bool GameOver;

extern int * SnakeTailPosXArr;
extern int * SnakeTailPosYArr;
extern int Score;

int main()
{
	using namespace std;

	HANDLE DrawThrd;
	HANDLE InputThrd;
	HANDLE LogicThrd;

	DWORD dwThrdID1, dwThrdID2, dwThrdID3;

	srand(time(NULL));

	Setup();

	while (!GameOver) {


		Draw();
		Input();
		Logic();

		cout << "\n\nScore: " << Score * 10;

		Sleep(75);
	}

	system("cls");

	Draw();

	cout << "\n\nGAME OVER!!"
		<< "\nYOUR SCORE: " << Score * 10 << endl;

	delete SnakeTailPosXArr;
	delete SnakeTailPosYArr;

	system("pause");
}