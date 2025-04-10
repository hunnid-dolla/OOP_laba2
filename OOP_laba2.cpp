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
