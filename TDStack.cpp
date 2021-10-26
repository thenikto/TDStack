
#include <iostream>
#include"TDStack.h"

#include<clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    TDStack<int>a(10);
    cout << "был создан массив размера 10\n";
    for (int i = 0; i < 5; i++) {
        a.Push_1(i);
    }
    for (int i = 5; i < 10; i++) {
        a.Push_2(i);
    }
    cout << a << endl;
    
    cout << "Попробуем добавить еще один элемент во 2 стек";
    try {
        a.Push_2(1000);
    }
    catch (...) {
        cout << "\nНевозможно.Массив переполнен.\n";
    }
   
    cout << "Вернем верхний элемент первого стека: " << a.Pop_1()<<'\n';
    cout << a << '\n';
    cout << "Добавим еще один элемент (10) во второй стек:\n";
    a.Push_2(10);
    cout << a << '\n';
    cout << "Удалим все элементы из второго стека\n";
    a.clear_2();
    cout << a << '\n';
    cout << "Теперь удалим все элементы из первого стека\n";
    a.clear_1();
    cout << a << '\n';
    cout << "Попробуем обратиться к пустому первому стеку и взять из него вершину";
    try {
        a.Pop_1();
    }
    catch (...) {
        cout << "\nНевозможно.Стек пуст\n";
    }
    cout << "создадим еще один массив:\n";
    TDStack<int>b(10);
    for (int i = 0; i < 8; i++) {
        b.Push_1(1);
    }
    for (int i = 8; i < 10; i++) {
        b.Push_2(2);
    }
    cout << b << endl;
    cout << "копируем его\n";
    TDStack<int>c(b);
    cout << c << endl;

    cout << "(успешно)\n";
    b.clear_all();
    c.clear_all();
    cout << "очистим оба массива\n";
    cout << b << endl;
    cout << c << endl;
    return 0;
}

