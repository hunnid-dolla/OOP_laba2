﻿#include <iostream>  
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

// ======= Класс ColoredPoint =======
class ColoredPoint : public Point {  // Класс ColoredPoint, наследующий от Point
private:
    string color;  // Цвет точки
public:
    ColoredPoint(int x, int y, string c) : Point(x, y), color(c) {  // Конструктор с параметрами
        cout << "Конструктор ColoredPoint(int, int, string)" << endl;
    }

    ~ColoredPoint() {  // Деструктор
        cout << "Деструктор ~ColoredPoint()" << endl;
    }

    void print() {  // Метод для вывода информации о цветной точке
        cout << "Точка: (" << this->x << ", " << this->y << "), Цвет: " << this->color << endl;
    }
};

// ======= Класс Container =======
class Container {  // Класс Container
private:
    Point point;  // Точка
    Circle* circle;  // Указатель на объект Circle
public:
    Container() : point(0, 0), circle(new Circle(5, 5, 3)) {  // Конструктор
        cout << "Вызван конструктор Container()" << endl;
    }

    ~Container() {  // Деструктор
        delete this->circle;  // Удаление объекта Circle
        cout << "Вызван деструктор ~Container()" << endl;
    }
};

// ======= Класс DynamicRectangle =======
class DynamicRectangle {  // Класс DynamicRectangle
private:
    Point* p1;  // Указатель на первую точку
    Point* p2;  // Указатель на вторую точку
public:
    DynamicRectangle() {  // Конструктор
        this->p1 = new Point(1, 2);  // Выделение памяти для p1
        this->p2 = new Point(5, 6);  // Выделение памяти для p2
        cout << "Конструктор DynamicRectangle()" << endl;
    }

    ~DynamicRectangle() {  // Деструктор
        delete this->p1;  // Освобождение памяти для p1
        delete this->p2;  // Освобождение памяти для p2
        cout << "Деструктор ~DynamicRectangle()" << endl;
    }

    void print() {  // Метод для отображения прямоугольника
        cout << "Прямоугольник (динамический):\n";
        this->p1->show();  // Отображение первой точки
        this->p2->show();  // Отображение второй точки
    }
};

// ======= Класс MyBase =======
class MyBase {  // Базовый класс MyBase
protected:
    string name;  // Имя
public:
    MyBase(string n) : name(n) {  // Конструктор с параметром для инициализации имени
        cout << "MyBase(string) — name: " << name << endl;
    }

    // Объявление виртуальной функции hello()
    virtual void hello() {  // Виртуальная функция для вывода приветствия
        cout << "Привет из MyBase!" << endl;
    }

    virtual ~MyBase() {  // Виртуальный деструктор
        cout << "Деструктор ~MyBase()" << endl;
    }
};

// ======= Класс MyDeriv =======
class MyDeriv : public MyBase {  // Класс MyDeriv, наследующий от MyBase
private:
    int value;  // Значение
public:
    MyDeriv(string n, int v) : MyBase(n), value(v) {  // Конструктор с параметрами
        cout << "MyDeriv(string, int) — value: " << value << endl;
    }

    // Переопределение виртуальной функции hello()
    void hello() override {  // Переопределение функции для вывода приветствия с дополнительными данными
        cout << "Привет из MyDeriv! name: " << this->name << ", value: " << this->value << endl;
    }

    ~MyDeriv() {  // Деструктор
        cout << "Деструктор ~MyDeriv()" << endl;
    }
};