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
    MyBase(string n) : name(n) {  // Конструктор с параметром для инициализации имени (Здесь происходит инициализация поля name)
        // Тело конструктора пустое
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

// ======= main() =======
int main() {
    setlocale(LC_ALL, "Rus");

    while (true) {
        cout << "\n=============================" << endl;
        cout << "МЕНЮ:" << endl;
        cout << "1. Статически создаваемые объекты" << endl;
        cout << "2. Динамически создаваемые объекты" << endl;
        cout << "3. Создание объектов с помощью различных конструкторов" << endl;
        cout << "4. Инициализация полей класса в списке инициализации конструктора" << endl;
        cout << "5. Помещение объектов в переменные различных типов" << endl;
        cout << "6. Объекты классов-наследников" << endl;
        cout << "7. Композиция объектов: атрибутом является объект другого класса" << endl;
        cout << "8. Композиция объектов: атрибутом является указатель на объект другого класса" << endl;
        cout << "9. Выход" << endl;
        cout << "Выберите действие: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\n=============================" << endl;
            cout << "СТАТИЧЕСКИ СОЗДАВАЕМЫЕ ОБЪЕКТЫ" << endl;
            cout << "Пример: Создание статических объектов Point с использованием различных конструкторов." << endl;

            Point p1;  // Создание статического объекта точки (конструктор по умолчанию)
            Point p2(3, 4);  // Создание статического объекта точки с координатами (3, 4) (конструктор с параметрами)
            Point p3 = p2;  // Копирование объекта p2 в p3 (конструктор копирования)
            p1.show();  // Вывод координат p1
            p2.show();  // Вывод координат p2
            p3.show();  // Вывод координат p3

            break;
        }
        case 2: {
            cout << "\n=============================" << endl;
            cout << "ДИНАМИЧЕСКИ СОЗДАВАЕМЫЕ ОБЪЕКТЫ" << endl;
            cout << "Пример: Создание динамического объекта Point и Circle." << endl;

            Point* p4 = new Point(5, 6);  // Создание динамического объекта Point через оператор new
            cout << "Динамический объект Point создан." << endl;
            p4->show();  // Вывод координат точки через оператор ->
            delete p4;  // Освобождение памяти, выделенной под динамический объект
            cout << "Динамический объект Point удален." << endl;

            cout << "\nДИНАМИЧЕСКИЙ ОБЪЕКТ CIRCLE" << endl;
            Circle* cPtr = new Circle(20, 20, 10);  // Создание динамического объекта Circle
            cout << "Динамический объект Circle создан." << endl;
            cPtr->draw();  // Вызов метода draw для объекта Circle
            delete cPtr;  // Освобождение памяти, выделенной под динамический объект
            cout << "Динамический объект Circle удален." << endl;

            break;
        }
        case 3: {
            cout << "\n=============================" << endl;
            cout << "СОЗДАНИЕ ОБЪЕКТОВ С ПОМОЩЬЮ РАЗЛИЧНЫХ КОНСТРУКТОРОВ" << endl;
            cout << "Пример: Использование конструкторов по умолчанию, с параметрами и копирования для класса Circle." << endl;

            Circle c1;  // Конструктор по умолчанию
            Circle c2(10, 10, 5);  // Конструктор с параметрами
            Circle c3 = c2;  // Конструктор копирования
            c1.draw();  // Рисование первого круга
            c2.draw();  // Рисование второго круга
            c3.draw();  // Рисование копии второго круга

            break;
        }
        case 4: {
            // Это инициализация, а не присваивание, потому что поле name получает свое значение до выполнения тела конструктора.
            cout << "\n=============================" << endl;
            cout << "ИНИЦИАЛИЗАЦИЯ ПОЛЕЙ КЛАССА В СПИСКЕ ИНИЦИАЛИЗАЦИИ КОНСТРУКТОРА" << endl;
            cout << "Пример: Создание объекта MyBase с использованием списка инициализации конструктора." << endl;

            MyBase* baseObj = new MyBase("BaseObj");  // Конструктор инициализирует поле name значением "BaseObj" через список инициализации.
            baseObj->hello();  // Этот метод выводит значение поля name, которое было инициализировано через список инициализации.
            delete baseObj;  // Освобождение памяти, выделенной под объект

            break;
        }
        case 5: {
            cout << "\n=============================" << endl;
            cout << "ПОМЕЩЕНИЕ ОБЪЕКТОВ В ПЕРЕМЕННЫЕ РАЗЛИЧНЫХ ТИПОВ" << endl;
            cout << "Пример: Полиморфизм через базовый класс MyBase и производный класс MyDeriv." << endl;

            MyBase* obj1 = new MyBase("BaseObj");  // Создание объекта базового класса
            cout << "Объект MyBase создан." << endl;
            obj1->hello();  // Вызов метода hello для obj1
            delete obj1;  // Освобождение памяти
            cout << "Объект MyBase удален." << endl;

            MyBase* obj2 = new MyDeriv("DerivedObj", 42);  // Создание объекта производного класса
            cout << "Объект MyDeriv создан." << endl;
            obj2->hello();  // Вызов метода hello для obj2 (полиморфизм)
            delete obj2;  // Освобождение памяти
            cout << "Объект MyDeriv удален." << endl;

            cout << "\nРазница:\n"
                << "MyBase* baseObj = new MyBase(); — объект базового типа, вызывает методы MyBase.\n"
                << "MyBase* derivedAsBase = new MyDeriv(); — объект производного типа,\nно вызываются переопределенные методы (если виртуальные).\n" << endl;

            Shape* shapes[3];  // Массив указателей на базовый класс Shape
            shapes[0] = new Circle(10, 10, 5);  // Создание объекта Circle
            shapes[1] = new Rectangle(Point(2, 3), Point(8, 6));  // Создание объекта Rectangle
            shapes[2] = new Shape("Фигура");  // Создание объекта Shape

            cout << "\nПример: Полиморфизм через базовый класс Shape." << endl;
            for (int i = 0; i < 3; ++i) {
                shapes[i]->draw();  // Вызов метода draw для каждого объекта (полиморфизм)
            }

            for (int i = 0; i < 3; ++i) {
                delete shapes[i];  // Освобождение памяти для каждого объекта
            }

            break;
        }
        case 6: {
            cout << "\n=============================" << endl;
            cout << "ОБЪЕКТЫ КЛАССОВ-НАСЛЕДНИКОВ" << endl;
            cout << "Пример: Использование класса MyDeriv, наследующего от MyBase." << endl;

            MyDeriv derivObj("DerivedObj", 100);  // Создание объекта производного класса
            derivObj.hello();  // Вызов переопределенного метода hello

            cout << "\nПример: Использование класса ColoredPoint, наследующего от Point." << endl;
            ColoredPoint cp(7, 8, "синий");  // Создание объекта ColoredPoint
            cp.print();  // Вывод информации о цветной точке

            break;
        }
        case 7: {
            cout << "\n=============================" << endl;
            cout << "КОМПОЗИЦИЯ ОБЪЕКТОВ: АТРИБУТОМ ЯВЛЯЕТСЯ ОБЪЕКТ ДРУГОГО КЛАССА" << endl;
            cout << "Пример: Класс Container содержит объекты Point и Circle." << endl;

            Container container;  // Создание объекта Container, который содержит объекты Point и Circle

            cout << "\nПример: Класс Rectangle, содержащий два объекта Point." << endl;
            Rectangle rect(Point(2, 3), Point(8, 6));  // Создание объекта Rectangle с двумя объектами Point
            rect.draw();  // Вызов метода draw для объекта Rectangle

            break;
        }
        case 8: {
            cout << "\n=============================" << endl;
            cout << "КОМПОЗИЦИЯ ОБЪЕКТОВ: АТРИБУТОМ ЯВЛЯЕТСЯ УКАЗАТЕЛЬ НА ОБЪЕКТ ДРУГОГО КЛАССА" << endl;
            cout << "Пример: Класс DynamicRectangle содержит указатели на объекты Point." << endl;

            DynamicRectangle* drect = new DynamicRectangle();  // Создание динамического объекта DynamicRectangle
            drect->print();  // Вывод информации о прямоугольнике
            delete drect;  // Освобождение памяти, выделенной под объект

            break;
        }
        case 9: {
            cout << "\n=============================" << endl;
            cout << "КОНЕЦ ПРОГРАММЫ" << endl;  // Сообщение о завершении программы
            return 0;  // Завершение программы
        }
        default: {
            cout << "\n=============================" << endl;
            cout << "Неверный выбор. Попробуйте снова." << endl;  // Обработка неверного выбора
        }
        }
    }
    return 0;  // Завершение программы (формальность, так как выход из цикла возможен только через return в case 9)
}