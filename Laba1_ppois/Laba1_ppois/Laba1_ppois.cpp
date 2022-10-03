#include <iostream>
#include <list>
#include "Header.h"
using namespace std;

class Point {
private:
    int x, y;
public:
    Point() {
        x = 0;
        y = 0;
    };
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
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
};

struct Cell {
    double value=0;
    Point first_point;
    Point second_point;
    Cell(double val, Point f, Point s) {
        value = val;
        first_point = f;
        second_point  = s;
    }
    Cell() {}
};


class Rectangle {
private:
    Point point[4];
    string name;
public:
    Rectangle() {}
    Rectangle(int X1, int Y1, int X2, int Y2) {
        point[0].Set_coordinates(X1, Y1);
        point[2].Set_coordinates(X2, Y2);
        point[1].Set_coordinates(X1, Y2);
        point[3].Set_coordinates(X2, Y1);
    }
    void SetName(string name) {
        this->name = name;
    }
    string GetName() {
        return name;
    }
    void Show_rectangle_coordinates() {
        for (auto _point : point) {
            _point.Show_coordinates(); }
        cout << endl;
    }
    void Set_rectangle_coordinates(int X1, int Y1, int X2, int Y2) {
        point[0].Set_coordinates(X1, Y1);
        point[2].Set_coordinates(X2, Y2);
        point[1].Set_coordinates(X1, Y2);
        point[3].Set_coordinates(X2, Y1);
    }
    void MoveRectangle(int direction, int number) {
        switch (direction) {
        case 1: {for (auto& _point : point) { _point.Up(number); }break; }       
        case 2: {for (auto& _point : point) { _point.Right(number); }break; }    
        case 3: {for (auto& _point : point) { _point.Up(-number); }break; }     
        case 4: {for (auto& _point : point) { _point.Right(-number); }break; }     
        }
    }
    void MoveUpSide(int number) {
        if (point[0].GetY() > point[1].GetY()) { point[0].Up(number); point[3].Up(number); }
        else { point[1].Up(number); point[2].Up(number); }
    }
    void MoveRightSide(int number) {
        if (point[0].GetX() > point[3].GetX()) { point[0].Right(number); point[1].Right(number); }
        else { point[3].Right(number); point[2].Right(number); }
    }
    void MoveDownSide(int number) {
        if (point[0].GetY() > point[1].GetY()) { point[1].Up(number); point[2].Up(number); }
        else { point[0].Up(number); point[3].Up(number); }
    }
    void MoveLeftSide(int number) {
        if (point[0].GetX() > point[3].GetX()) { point[3].Right(number); point[2].Right(number); }
        else { point[0].Right(number); point[1].Right(number); }
    }
    Rectangle& operator ++ () {
        MoveUpSide(1);
        MoveRightSide(1);
        return *this;
    }
    Rectangle operator ++(int rect) {
        Rectangle temp(*this);
        this->MoveUpSide(1);
        this->MoveRightSide(1);
        return temp;
    }
    Rectangle& operator -- () {
        MoveUpSide(-1);
        MoveRightSide(-1);
        return *this;
    }
    Rectangle operator --(int rect) {
        Rectangle temp(*this);
        this->MoveUpSide(-1);
        this->MoveRightSide(-1);
        return temp;
    }
    Point& GetPoint(int value) {
        return  point[value];
    }
    Rectangle operator+= (Rectangle& second) {
        Cell dist = GetDistanceCell(*this, second);
        this->Set_rectangle_coordinates(dist.first_point.GetX(), dist.first_point.GetY(), dist.second_point.GetX(), dist.second_point.GetY());
        return *this;
    }
    Rectangle operator+( Rectangle& second) {
        Cell dist = GetDistanceCell(*this, second);
        return Rectangle(dist.first_point.GetX(), dist.first_point.GetY(), dist.second_point.GetX(), dist.second_point.GetY());
    }
    int FindRight() {
        if (point[0].GetX() > point[3].GetX()) {
            return point[0].GetX();
        }
        else return point[3].GetX();
    }
    int FindLeft() {
        if (point[0].GetX() < point[3].GetX()) {
            return point[0].GetX();
        }
        else return point[3].GetX();
    }
    int FindDown() {
        if (point[0].GetY() < point[1].GetY()) {
            return point[0].GetY();
        }
        else return point[1].GetY();
    }
    int FindUp() {
        if (point[0].GetY() > point[1].GetY()) {
            return point[0].GetY();
        }
        else return point[1].GetY();
    }
    Rectangle FindBetween(Rectangle& first, Rectangle& second) {
        int upper = 0, lower = 0, right = 0, left = 0;
        if ((first.FindRight() > second.FindLeft()) && ((first.FindUp() > second.FindDown()) || (first.FindDown() < second.FindUp()))) {
            if (first.FindUp() > second.FindUp()) { lower = second.FindUp(); }
            else { lower = first.FindUp(); }
            if (first.FindDown() < second.FindDown()) { upper = second.FindDown(); }
            else { upper = first.FindDown(); }
            if (first.FindRight() > second.FindRight()) { left = second.FindRight(); }
            else { left = first.FindRight(); }
            if (first.FindLeft() < second.FindLeft()) { right = second.FindLeft(); }
            else { right = first.FindLeft(); }
            return Rectangle(left, lower, right, upper);
        }
        else return first;
    }
    Rectangle operator-(Rectangle& second) {
        if (this->FindLeft() < second.FindLeft()) return FindBetween(*this, second);
        else return FindBetween(second, *this);
    }
    Rectangle operator-=(Rectangle& second) {
        if (this->FindLeft() < second.FindLeft()) *this = FindBetween(*this, second);
        else *this =  FindBetween(second, *this);
        return *this;
    }

};


double GetDistance(Point& first,Point& second){
    return (pow((first.GetX() - second.GetX()),2) + pow((first.GetY() - second.GetY()),2));
}

 Cell GetDistanceCell(Rectangle first, Rectangle second) {
    list<Cell> distance;
    int f_num = 0, s_num = 0;
    Point* point_1 = new Point;
    Point* point_2 = new Point;
    for (int i=0; i<16; i++){
        *point_1 = first.GetPoint(f_num);
        *point_2 = second.GetPoint(s_num);
        distance.push_back(Cell(GetDistance(*point_1, *point_2), *point_1, *point_2));
        s_num++;
        if (s_num == 4) { s_num = 0; f_num++; }
    }
  double  max = distance.begin()->value;
    Cell max_i;
    for (auto num = distance.begin(); num!=distance.end(); num++) {
        if (max < num->value) {
            max = num->value;
            max_i = *num;
        }
    }
    return max_i;
}

 int menu() {
     cout << "Create a rectangle\n" << "Enter coordinates of diagonas points\n";
     int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
     cin >> x1 >> y1 >> x2 >> y2;
     Rectangle ABCD(x1, y1, x2, y2);
     cout << "Enter name\n";
     string name;
     cin >> name;
     ABCD.SetName(name);
     int key = 0;
     cout << endl;
     while (1) {
         cout << endl << "Select an action:\n" << "0:Exit\n" << "1:Change rectangle\n" << "2:Get Coordinates and name\n" << "3:Move rectangle\n" << "4:Switch size\n" << "5:Increase preincrementaly\n" << "6:Increase postincrementaly\n"
             << "7:Decrease preincrementaly\n" << "8:Decrease postincrementaly\n" << "9:Build with +\n" << "10:Build with +=\n" << "11:Build with -\n" << "12:Build with -=\n";
         cin >> key;
         switch (key) {
         default: return 0;
         case 1: {cout << "Enter coordinates of diagonas points\n";
             cin >> x1 >> y1 >> x2 >> y2;
             ABCD.Set_rectangle_coordinates(x1, y1, x2, y2);
             cout << "Enter name\n";
             cin >> name;
             ABCD.SetName(name);
             ABCD.Show_rectangle_coordinates();
             cout << endl << ABCD.GetName() << endl;
             break; }
         case 2: {cout << endl;  ABCD.Show_rectangle_coordinates(); cout << ABCD.GetName() << endl; break; }
         case 3: {cout << endl << "Move in which direction?\n" << "1:Up\n" << "2:Right\n" << "3:Down\n" << "4:Left\n";
             int direction_id = 0;
             cin >> direction_id;
             cout << "How much to move?\n";
             int num = 0;
             cin >> num;
             ABCD.MoveRectangle(direction_id, num);
             break; }
         case 4: {cout << endl  << "Which side to move?\n" << "1:Up\n" << "2:Right\n" << "3:Down\n" << "4:Left\n";
             int direction_id = 0;
             cin >> direction_id;
             cout << "How much to move?\n" << "Positive number to increase, negative to decrease\n";
             int num = 0;
             cin >> num;
             switch (direction_id)
             {
             case 1: {ABCD.MoveUpSide(num); break; }
             case 2: {ABCD.MoveRightSide(num); break; }
             case 3: {ABCD.MoveDownSide(num); break; }
             case 4: {ABCD.MoveLeftSide(num); break; }
             default:
                 break;
             }
             break; }
         case 5: {++ABCD; break; }
         case 6: {ABCD++; break; }
         case 7: {--ABCD; break; }
         case 8: {ABCD--; break; }
         case 9: {cout << endl << "Create the second rectangle\n" << "Enter coordinates of diagonas points\n";
             int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
             cin >> X1 >> Y1 >> X2 >> Y2;
             Rectangle abcd(X1, Y1, X2, Y2);
             Rectangle NEWRECT = ABCD + abcd;
             ABCD = NEWRECT; break; }
         case 10: {cout << endl << "Create the second rectangle\n" << "Enter coordinates of diagonas points\n";
             int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
             cin >> X1 >> Y1 >> X2 >> Y2;
             Rectangle abcd(X1, Y1, X2, Y2);
             ABCD += abcd; break; }
         case 11: {cout << endl << "Create the second rectangle\n" << "Enter coordinates of diagonas points\n";
             int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
             cin >> X1 >> Y1 >> X2 >> Y2;
             Rectangle abcd(X1, Y1, X2, Y2);
             Rectangle NEWRECT = ABCD - abcd;
             ABCD = NEWRECT; break; }
         case 12: {cout << endl << "Create the second rectangle\n" << "Enter coordinates of diagonas points\n";
             int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
             cin >> X1 >> Y1 >> X2 >> Y2;
             Rectangle abcd(X1, Y1, X2, Y2);
             ABCD -= abcd; break; }
         }
     }
 }

 int main()
 {
     menu();
     return 0;
 }