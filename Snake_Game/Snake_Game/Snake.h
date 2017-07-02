#ifndef SNAKE_H_
#define SNAKE_H_

const int Width = 25;
const int Height = 25;

enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };

void Setup();
void Draw();
void Input();
void Logic();

#endif // !SNAKE_H_
