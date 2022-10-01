#pragma once
#ifndef Header.h
class Point;
void  Show_coordinates();
int GetX();
int GetY();
void Set_coordinates(int, int);
void Up(int);
void Right(int);

struct Cell;
class Rectangle;
Cell GetDistanceCell(Rectangle, Rectangle);
void Show_rectangle_coordinates();
void Set_rectangle_coordinates(int, int, int, int);
void MoveRectangle(int, int);
void MoveUpSide(int);
void MoveRightSide(int);
void MoveDownSide(int);
void MoveLeftSide(int);
int FindRight();
int FindLeft();
int FindDown();
int FindUp();
Rectangle FindBetween(Rectangle&, Rectangle&);
double GetDistance(Point&, Point& );
#endif // !Header.h
