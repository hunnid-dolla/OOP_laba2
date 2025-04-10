#include <iostream>  
#include <string>    

using namespace std;

// ======= Класс Point =======
class Point {  // Определение класса Point
protected:
    int x, y;  // Защищенные члены данных для координат точки
public:
    Point() : x(0), y(0) {  // Конструктор по умолчанию, инициализирует точку (0, 0)
        cout << "Вызван конструктор Point()" << endl;
    }

    Point(int x, int y) : x(x), y(y) {  // Конструктор с параметрами для инициализации точек
        cout << "Вызван конструктор Point(int, int)" << endl;
    }

    Point(const Point& p) : x(p.x), y(p.y) {  // Конструктор копирования
        cout << "Вызван конструктор копирования Point(const Point&)" << endl;
    }

    ~Point() {  // Деструктор класса Point
        cout << "Вызван деструктор ~Point()" << endl;
    }

    void show() {  // Метод для отображения координат точки
        cout << "Точка: (" << this->x << ", " << this->y << ")" << endl;
    }
};

// ======= Класс Shape =======
class Shape {  // Определение базового класса Shape
protected:
    string name;  // Защищенное имя фигуры
public:
    Shape() : name("Фигура") {  // Конструктор по умолчанию
        cout << "Вызван конструктор Shape()" << endl;
    }

    Shape(string name) : name(name) {  // Конструктор с параметром для задания имени
        cout << "Вызван конструктор Shape(string)" << endl;
    }

    virtual ~Shape() {  // Виртуальный деструктор
        cout << "Вызван деструктор ~Shape()" << endl;
    }

    virtual void draw() {  // Виртуальная функция для рисования фигуры
        cout << "Рисуем фигуру: " << this->name << endl;
    }
};

// ======= Класс Circle =======
class Circle : public Shape {  // Класс Circle, наследующий от Shape
private:
    Point center;  // Центр круга
    int radius;  // Радиус круга
public:
    Circle() : Shape("Круг"), center(Point()), radius(1) {  // Конструктор по умолчанию
        cout << "Вызван конструктор Circle()" << endl;
    }

    Circle(int x, int y, int r) : Shape("Круг"), center(Point(x, y)), radius(r) {  // Конструктор с параметрами
        cout << "Вызван конструктор Circle(int, int, int)" << endl;
    }

    Circle(const Circle& c) : Shape(c.name), center(c.center), radius(c.radius) {  // Конструктор копирования
        cout << "Вызван конструктор копирования Circle(const Circle&)" << endl;
    }

    ~Circle() {  // Деструктор
        cout << "Вызван деструктор ~Circle()" << endl;
    }

    void draw() override {  // Переопределенная функция для рисования круга
        cout << "Рисуем круг с радиусом " << this->radius << endl;
    }
};

// ======= Класс Rectangle =======
class Rectangle : public Shape {  // Класс Rectangle, наследующий от Shape
private:
    Point p1, p2;  // Два угла прямоугольника
public:
    Rectangle(Point a, Point b) : Shape("Прямоугольник"), p1(a), p2(b) {  // Конструктор с параметрами
        cout << "Конструктор Rectangle(Point, Point)" << endl;
    }

    ~Rectangle() {  // Деструктор
        cout << "Деструктор ~Rectangle()" << endl;
    }

    void draw() override {  // Переопределенная функция для рисования прямоугольника
        cout << "Рисуем прямоугольник:\n";
        this->p1.show();
        this->p2.show();
    }
};