#include <iostream>
#include <string>
#include <algorithm> // ��� std::gcd � ������� ������ � �������

// ��������� ��� �������� ����� � ��������� ������� ���������
struct Point {
    double x;
    double y;
};

// ��������� ��� �������� ��������������
struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

// ��������� ��� �������� ��������
struct Person {
    std::string name;
    int age;
    std::string address;
};

// ��������� ��� �������� �����
struct Fraction {
    int numerator;
    int denominator;
};

// ������� ��� ��������, ����������� �� ������, ���������� ����� ��� �����, ����
void check_parallel(const Point& p1, const Point& p2) {
    if (p1.x == p2.x) {
        std::cout << "������ ����������� ��� ������� (y-���)." << std::endl;
    }
    else if (p1.y == p2.y) {
        std::cout << "������ ����������� ��� ������� (x-���)." << std::endl;
    }
    else {
        std::cout << "������ �� ����������� �� ����� �� ����." << std::endl;
    }
}

// ������� ��� �������� ��������� ����� � �������������
bool is_point_in_rectangle(const Rectangle& rect, const Point& pt) {
    return (pt.x >= rect.topLeft.x && pt.x <= rect.bottomRight.x &&
        pt.y <= rect.topLeft.y && pt.y >= rect.bottomRight.y);
}

// ������� ��� ���������� ������ � ��������
void fill_person(Person& person, const std::string& name, int age, const std::string& address) {
    person.name = name;
    person.age = age;
    person.address = address;
}

// ������� ��� ������ ������ � ��������
void print_person(const Person& person) {
    std::cout << "���: " << person.name << "\n�������: " << person.age << "\n�����: " << person.address << std::endl;
}

// ������������ ��������������
void normalize_rectangle(Rectangle& rect) {
    if (rect.topLeft.x > rect.bottomRight.x) {
        std::swap(rect.topLeft.x, rect.bottomRight.x);
    }
    if (rect.topLeft.y < rect.bottomRight.y) {
        std::swap(rect.topLeft.y, rect.bottomRight.y);
    }
}

// ����������� ��������������
void move_rectangle(Rectangle& rect, double dx, double dy) {
    rect.topLeft.x += dx;
    rect.bottomRight.x += dx;
    rect.topLeft.y += dy;
    rect.bottomRight.y += dy;
}

// ��������� ������� ��������������
void resize_rectangle(Rectangle& rect, double dw, double dh) {
    rect.bottomRight.x += dw;
    rect.bottomRight.y -= dh;
}

//���������� �����
void reduce_fraction(Fraction& frac) {
    int gcd = std::gcd(frac.numerator, frac.denominator);
    frac.numerator /= gcd;
    frac.denominator /= gcd;
}

//��������
Fraction add_fractions(const Fraction& f1, const Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    reduce_fraction(result);
    return result;
}

//���������
Fraction subtract_fractions(const Fraction& f1, const Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    reduce_fraction(result);
    return result;
}

//��������� ������
Fraction multiply_fractions(const Fraction& f1, const Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    reduce_fraction(result);
    return result;
}

//������� ������
Fraction divide_fractions(const Fraction& f1, const Fraction& f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    reduce_fraction(result);
    return result;
}

//������� ��� ������ �����
void print_fraction(const Fraction& frac) {
    std::cout << frac.numerator << "/" << frac.denominator << std::endl;
}

int main() {
    //1
    Point p1 = { 1.0, 2.0 };
    Point p2 = { 1.0, 5.0 };
    check_parallel(p1, p2);

    //2
    Rectangle rect = { {0.0, 5.0}, {5.0, 0.0} };
    Point pt = { 3.0, 3.0 };
    if (is_point_in_rectangle(rect, pt)) {
        std::cout << "����� ������ ��������������." << std::endl;
    }
    else {
        std::cout << "����� ��� ��������������." << std::endl;
    }

    //3
    Person person;
    fill_person(person, "���� ������", 30, "��. �������, �. 1");
    print_person(person);

    //4
    Rectangle rect2 = { {2.0, 4.0}, {5.0, 1.0} };
    normalize_rectangle(rect2);
    std::cout << "��������������� �������������: (" << rect2.topLeft.x << ", " << rect2.topLeft.y
        << ") - (" << rect2.bottomRight.x << ", " << rect2.bottomRight.y << ")" << std::endl;

    move_rectangle(rect2, 1.0, -1.0);
    std::cout << "������������ �������������: (" << rect2.topLeft.x << ", " << rect2.topLeft.y
        << ") - (" << rect2.bottomRight.x << ", " << rect2.bottomRight.y << ")" << std::endl;

    resize_rectangle(rect2, 2.0, 1.0);
    std::cout << "��������� ������ ��������������: (" << rect2.topLeft.x << ", " << rect2.topLeft.y
        << ") - (" << rect2.bottomRight.x << ", " << rect2.bottomRight.y << ")" << std::endl;

    //5
    Fraction f1 = { 3, 4 };
    Fraction f2 = { 2, 5 };

    Fraction sum = add_fractions(f1, f2);
    Fraction difference = subtract_fractions(f1, f2);
    Fraction product = multiply_fractions(f1, f2);
    Fraction quotient = divide_fractions(f1, f2);

    std::cout << "�����: "; print_fraction(sum);
    std::cout << "��������: "; print_fraction(difference);
    std::cout << "������������: "; print_fraction(product);
    std::cout << "�������: "; print_fraction(quotient);

    return 0;
