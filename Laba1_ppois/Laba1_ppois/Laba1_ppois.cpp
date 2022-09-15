// Laba1_ppois.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class point {
private:
    int x, y;
public:
    /*point(int coord_x, int coord_y) {
        x = coord_x;
        y = coord_y;
    }*/
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
};

class rectangle {
private:
    point point1, point2, point3, point4;
public:
   /* rectangle() {
         point2.Set_coordinates(point3.GetX(), point1.GetY());
         point4.Set_coordinates(point1.GetX(), point3.GetY());
    }*/
    void Show_rectangle_coordinates() {
        point1.Show_coordinates();
        point2.Show_coordinates();
        point3.Show_coordinates();
        point4.Show_coordinates();
    }
    void Set_rectangle_coordinates(int X1, int X2, int Y1, int Y2) {
        point1.Set_coordinates(X1, Y1);
        point3.Set_coordinates(X2, Y2);
        point2.Set_coordinates(point3.GetX(), point1.GetY());
        point4.Set_coordinates(point1.GetX(), point3.GetY());
    }

};

int main()
{
    int x1, x2, y1, y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        //point A/*(x1, y1)*/;
        //point B/*(x2, y2)*/;
        rectangle ABCD/*(A, B)*/;
        ABCD.Set_rectangle_coordinates(x1, x2, y1, y2);
        ABCD.Show_rectangle_coordinates();
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
