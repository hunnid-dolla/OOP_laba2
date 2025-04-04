#include <iostream>
#include <string>

using namespace std;

class Point {
protected:
    int x, y;
public:
    Point() : x(0), y(0) { cout << "Вызван конструктор Point()" << endl; }
    Point(int x, int y) : x(x), y(y) { cout << "Вызван конструктор Point(int, int)" << endl; }
    Point(const Point& p) : x(p.x), y(p.y) { cout << "Вызван конструктор копирования Point(const Point&)" << endl; }
    ~Point() { cout << "Вызван деструктор ~Point()" << endl; }
    void show() { cout << "Точка: (" << x << ", " << y << ")" << endl; }
};

class Shape {
protected:
    string name;
public:
    Shape() : name("Фигура") { cout << "Вызван конструктор Shape()" << endl; }
    Shape(string name) : name(name) { cout << "Вызван конструктор Shape(string)" << endl; }
    virtual ~Shape() { cout << "Вызван деструктор ~Shape()" << endl; }
    virtual void draw() { cout << "Рисуем фигуру: " << name << endl; }
};

class Circle : public Shape {
private:
    Point center;
    int radius;
public:
    Circle() : Shape("Круг"), center(Point()), radius(1) { cout << "Вызван конструктор Circle()" << endl; }
    Circle(int x, int y, int r) : Shape("Круг"), center(Point(x, y)), radius(r) { cout << "Вызван конструктор Circle(int, int, int)" << endl; }
    Circle(const Circle& c) : Shape(c.name), center(c.center), radius(c.radius) { cout << "Вызван конструктор копирования Circle(const Circle&)" << endl; }
    ~Circle() { cout << "Вызван деструктор ~Circle()" << endl; }
    void draw() override {
        cout << "Рисуем круг с радиусом " << radius << endl;
    }
};

class Container {
private:
    Point point;
    Circle* circle;
public:
    Container() : point(0, 0), circle(new Circle(5, 5, 3)) { cout << "Вызван конструктор Container()" << endl; }
    ~Container() {
        delete circle;
        cout << "Вызван деструктор ~Container()" << endl;
    }
};


// ColoredPoint — наследник Point с цветом
class ColoredPoint : public Point {
private:
    string color;
public:
    ColoredPoint(int x, int y, string c) : Point(x, y), color(c) {
        cout << "Конструктор ColoredPoint(int, int, string)" << endl;
    }
    ~ColoredPoint() {
        cout << "Деструктор ~ColoredPoint()" << endl;
    }
    void print() {
        cout << "Точка: (" << x << ", " << y << "), Цвет: " << color << endl;
    }
};

// Rectangle — с двумя Point
class Rectangle {
private:
    Point p1, p2;
public:
    Rectangle(Point a, Point b) : p1(a), p2(b) {
        cout << "Конструктор Rectangle(Point, Point)" << endl;
    }
    ~Rectangle() {
        cout << "Деструктор ~Rectangle()" << endl;
    }
    void print() {
        cout << "Прямоугольник:\n";
        p1.show();
        p2.show();
    }
};

// DynamicRectangle — с Point в динамической памяти
class DynamicRectangle {
private:
    Point* p1;
    Point* p2;
public:
    DynamicRectangle() {
        p1 = new Point(1, 2);
        p2 = new Point(5, 6);
        cout << "Конструктор DynamicRectangle()" << endl;
    }
    ~DynamicRectangle() {
        delete p1;
        delete p2;
        cout << "Деструктор ~DynamicRectangle()" << endl;
    }
    void print() {
        cout << "Прямоугольник (динамический):\n";
        p1->show();
        p2->show();
    }
};

int main() {

    cout << "=============================" << endl;
    cout << "СТАТИЧЕСКИЕ ОБЪЕКТЫ" << endl;
    Point p1;
    Point p2(3, 4);
    Point p3 = p2;
    p1.show();
    p2.show();
    p3.show();

    cout << "\n=============================" << endl;
    cout << "ДИНАМИЧЕСКИЕ ОБЪЕКТЫ" << endl;
    Point* p4 = new Point(5, 6);
    p4->show();
    delete p4;

    cout << "\n=============================" << endl;
    cout << "КОНСТРУКТОРЫ И КОПИРОВАНИЕ" << endl;
    Circle c1;
    Circle c2(10, 10, 5);
    Circle c3 = c2;
    c1.draw();
    c2.draw();
    c3.draw();

    cout << "\n=============================" << endl;
    cout << "ДИНАМИЧЕСКИЙ ОБЪЕКТ CIRCLE" << endl;
    Circle* cPtr = new Circle(20, 20, 10);
    cPtr->draw();
    delete cPtr;

    cout << "\n=============================" << endl;
    cout << "ОБЪЕКТЫ БАЗОВЫХ И ПРОИЗВОДНЫХ КЛАССОВ" << endl;
    Shape s;
    s.draw();
    Shape* sPtr = new Circle(15, 15, 7);
    sPtr->draw();
    delete sPtr;

    cout << "\n=============================" << endl;
    cout << "КОМПОЗИЦИЯ ОБЪЕКТОВ (Point как член)" << endl;
    Container container;

    cout << "\n=============================" << endl;
    cout << "НАСЛЕДОВАНИЕ С ДОПОЛНЕНИЕМ (ColoredPoint)" << endl;
    ColoredPoint cp(7, 8, "синий");
    cp.print();

    cout << "\n=============================" << endl;
    cout << "КОМПОЗИЦИЯ ДВУХ ТОЧЕК В RECTANGLE" << endl;
    Rectangle rect(Point(2, 3), Point(8, 6));
    rect.print();

    cout << "\n=============================" << endl;
    cout << "КОМПОЗИЦИЯ С ДИНАМИЧЕСКОЙ ПАМЯТЬЮ (DynamicRectangle)" << endl;
    DynamicRectangle* drect = new DynamicRectangle();
    drect->print();
    delete drect;

    cout << "\n=============================" << endl;
    cout << "КОНЕЦ ПРОГРАММЫ" << endl;
    return 0;
}
