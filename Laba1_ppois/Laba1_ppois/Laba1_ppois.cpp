#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
   void  Show_coordinates() {
       cout << '(' << x << ", " << y << ')' << endl;
    }
   int GetX() {
       return x;
   }
   int GetY() {
       return y;
   }
   void Set_coordinates(int coord_x, int coord_y) {
       x = coord_x;
       y = coord_y;
   }
   void Up(int number) {
       y += number;
   }
   void Right(int number) {
       x += number;
   }
   void Down(int number) {
       y -= number;
   }
   void Left(int number) {
       x -= number;
   }
};

class rectangle {
private:
    Point point[4];
public:
    void Show_rectangle_coordinates() {
        for (auto _point : point) {
            _point.Show_coordinates(); }
        cout << endl;
    }
    void Set_rectangle_coordinates(int X1, int X2, int Y1, int Y2) {
        point[0].Set_coordinates(X1, Y1);
        point[2].Set_coordinates(X2, Y2);
        point[1].Set_coordinates(X1, Y2);
        point[3].Set_coordinates(X2, Y1);
    }
    void MoveRectangle(int direction, int number) {
        switch (direction) {
        case 1: {for (auto& _point : point) { _point.Up(number); }break; }       //X0=X1   Высоту по ним(Чек У)
        case 2: {for (auto& _point : point) { _point.Right(number); }break; }    //X2=X3
        case 3: {for (auto& _point : point) { _point.Down(number); }break; }     //Y0=Y3   Длину по ним(Чек Х)
        case 4: {for (auto& _point : point) { _point.Left(number); }break; }     //Y2=Y1
        }
    }
    void MoveUp(int number) {
        if (point[0].GetY() > point[1].GetY()) { point[0].Up(number); point[3].Up(number); }
        else { point[1].Up(number); point[2].Up(number); }
    }
    void MoveRight(int number) {
        if (point[0].GetX() > point[3].GetX()) { point[0].Right(number); point[1].Right(number); }
        else { point[3].Right(number); point[2].Right(number); }
    }
    void MoveDown(int number) {
        if (point[0].GetY() > point[1].GetY()) { point[1].Down(number); point[2].Down(number); }
        else { point[0].Down(number); point[3].Down(number); }
    }
    void MoveLeft(int number) {
        if (point[0].GetX() > point[3].GetX()) { point[3].Left(number); point[2].Left(number); }
        else { point[0].Left(number); point[1].Left(number); }
    }
    void operator ++ () {
        MoveUp(1);
        MoveRight(1);
    }



};

int main()
{
    int x1, x2, y1, y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        rectangle ABCD;
        ABCD.Set_rectangle_coordinates(x1, x2, y1, y2);
        ABCD.Show_rectangle_coordinates();
        ABCD.MoveRectangle(3, 10);
        ABCD.Show_rectangle_coordinates();
        ABCD.MoveUp(3);
        ABCD.Show_rectangle_coordinates();
        ABCD.MoveLeft(3);
        ABCD.Show_rectangle_coordinates();
        ABCD.MoveRight(3);
        ABCD.Show_rectangle_coordinates();
        ABCD.MoveDown(3);
        ABCD.Show_rectangle_coordinates();
        ++ABCD;
        ABCD.Show_rectangle_coordinates();


}
