// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
#include <iomanip>
using namespace std;
/*


class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Конструктори
    Time() : hour(0), minute(0), second(0) {}
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Функції-члени встановлення години, хвилини та секунди з перевіркою на коректність
    void setHour(int h) {
        if (h >= 0 && h <= 23)
            hour = h;
        else
            cerr << "Некоректна година!" << endl;
    }

    void setMinute(int m) {
        if (m >= 0 && m <= 59)
            minute = m;
        else
            cerr << "Некоректні хвилини!" << endl;
    }

    void setSecond(int s) {
        if (s >= 0 && s <= 59)
            second = s;
        else
            cerr << "Некоректні секунди!" << endl;
    }

    // Функції-члени отримання години, хвилини та секунди
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    // Функція для введення даних
    void inputTime() {
        int h, m, s;
        cout << "Введіть години, хвилини та секунди через пробіл: ";
        cin >> h >> m >> s;
        setHour(h);
        setMinute(m);
        setSecond(s);
    }

    // Функції-члени друку за шаблоном
    void printStandardFormat() const {
        cout << hour << " годин " << minute << " хвилин " << second << " секунд" << endl;
    }

    void printAMPMFormat() const {
        int displayHour = (hour > 12) ? (hour - 12) : ((hour == 0) ? 12 : hour);
        string period = (hour >= 12) ? "p.m." : "a.m.";
        cout << displayHour << " " << period << " " << minute << " хвилин " << second << " секунд" << endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    // Тестування класу Time
    Time time1; // викликається конструктор за замовчуванням
    Time time2(16, 18, 3); // викликається конструктор з параметрами

    // Встановлення нових значень через функцію введення
    time1.inputTime();

    // Виведення значень у двох форматах
    cout << "Час 1 у стандартному форматі: ";
    time1.printStandardFormat();
    cout << "Час 1 у форматі p.m./a.m.: ";
    time1.printAMPMFormat();

    cout << "Час 2 у стандартному форматі: ";
    time2.printStandardFormat();
    cout << "Час 2 у форматі p.m./a.m.: ";
    time2.printAMPMFormat();

    return 0;
}

/////////////////////////
*/



class Vector {
private:
    float* data;
    int size;
    int state; // 0 - ok, 1 - memory allocation error, 2 - out of bounds

public:
    // Конструктор без параметрів
    Vector() : size(1), state(0) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else
            data[0] = 0.0f;
    }

    // Конструктор з одним параметром - розміром вектора
    Vector(int s) : size(s), state(0) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = 0.0f;
        }
    }

    // Конструктор із двома параметрами - розміром вектора та значенням ініціалізації
    Vector(int s, float init_value) : size(s), state(0) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = init_value;
        }
    }

    // Конструктор копії
    Vector(const Vector& other) : size(other.size), state(other.state) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            state = other.state;
            data = new float[size];
            if (data == nullptr)
                state = 1;
            else {
                for (int i = 0; i < size; ++i)
                    data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Функція, яка присвоює елементу масиву деяке значення
    void setElement(int index, float value = 0.0f) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            state = 2;
            throw std::out_of_range("Index out of bounds");
        }
    }

    // Функція, яка повертає деякий елемент масиву
    float getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            int state = 2;
            throw std::out_of_range("Index out of bounds");
        }
    }

    // Функція друку
    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Функція додавання
    Vector operator+(const Vector& other) const {
        if (size != other.size) {
            int state = 2;
            throw std::invalid_argument("Vector sizes don't match");
        }
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Функція віднімання
    Vector operator-(const Vector& other) const {
        if (size != other.size) {
            int state = 2;
            throw std::invalid_argument("Vector sizes don't match");
        }
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Функція множення на ціле число
    Vector operator*(long scalar) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // Функції порівняння
    bool operator==(const Vector& other) const {
        if (size != other.size)
            return false;
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Vector sizes don't match for comparison");
        for (int i = 0; i < size; ++i) {
            if (data[i] >= other.data[i])
                return false;
        }
        return true;
    }

    bool operator>(const Vector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Vector sizes don't match for comparison");
        for (int i = 0; i < size; ++i) {
            if (data[i] <= other.data[i])
                return false;
        }
        return true;
    }

    bool operator<=(const Vector& other) const {
        return (*this == other || *this < other);
    }

    bool operator>=(const Vector& other) const {
        return (*this == other || *this > other);
    }

    // Функція для отримання стану вектора
    int getState() const {
        return state;
    }

    // Функція для отримання кількості об'єктів даного типу
    static int getCount() {
        // Реалізуйте потрібний код для підрахунку об'єктів
    }
};

int main() {
    try {
        Vector v1(3, 1.5f);
        Vector v2(3, 2.5f);

        // Перевірка функції додавання
        Vector sum = v1 + v2;
        sum.print();

        // Перевірка функції віднімання
        Vector diff = v1 - v2;
        diff.print();

        // Перевірка функції множення на ціле число
        Vector mult = v1 * 2;
        mult.print();

        // Перевірка функцій порівняння
        std::cout << (v1 == v2) << std::endl;
        std::cout << (v1 != v2) << std::endl;
        std::cout << (v1 < v2) << std::endl;
        std::cout << (v1 > v2) << std::endl;
        std::cout << (v1 <= v2) << std::endl;
        std::cout << (v1 >= v2) << std::endl;

        // Перевірка вибросу виключення при виході за межі масиву
        std::cout << v1.getElement(5) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

