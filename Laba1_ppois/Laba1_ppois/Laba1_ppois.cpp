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
        for (auto& _point : point) {
            _point.Show_coordinates();
            cout << endl;
        }
    }
    void Set_rectangle_coordinates(int X1, int X2, int Y1, int Y2) {
        point[0].Set_coordinates(X1, Y1);
        point[2].Set_coordinates(X2, Y2);
        point[1].Set_coordinates(point[0].GetX(), point[2].GetY());
        point[3].Set_coordinates(point[2].GetX(), point[0].GetY());
    }
    void MoveRectangle(int direction, int number) {
        switch (direction) {
        case 1: {for (auto& _point : point) { _point.Up(number); }break; }
        case 2: {for (auto& _point : point) { _point.Right(number); }break; }
        case 3: {for (auto& _point : point) { _point.Down(number); }break; }
        case 4: {for (auto& _point : point) { _point.Left(number); }break; }
        }

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

}
