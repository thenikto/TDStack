#pragma once  
#include <iostream>
#include <string>
#include <fstream>
#include<clocale>
using namespace std;

template <class T >
class TDStack {
	T* mas;
	int SIZE;
	int pos1;
	int pos2;
public:
	//конструктор
	TDStack(int _SIZE = 10) 
	{
		if (_SIZE <= 0) throw "exep. size of double stack is negative";
		SIZE = _SIZE;
		
		mas = new T[_SIZE];
		pos1 = -1;
		pos2 = SIZE;
	}
	//деструктор
	~TDStack()
	{
		delete[]mas;
	}
	//конструктор копирования
	TDStack(const TDStack& a)
	{
		SIZE = a.SIZE;
		pos1 = a.pos1;
		pos2 = a.pos2;
		mas = new T[SIZE];
		for (int i = 0; i <= pos1; i++) {
			mas[i] = a.mas[i];
		}
		for (int i = SIZE-1; i >= pos2; i--) {
			mas[i] = a.mas[i];
		}
	}
	//присваивание
	TDStack& operator=(const TDStack& s)
	{
		if (SIZE != s.SIZE) {
			delete[]mas;
			SIZE = s.SIZE;
			mas = new T[SIZE];
		}
		
		pos1 = s.pos1;
		pos2 = s.pos2;
		for (int i = 0; i <= pos1; i++) {
			mas[i] = s.mas[i];
		}
		for (int i = SIZE-1; i >= pos2; i--) {
			mas[i] = s.mas[i];
		}
	}
    //проверка на пустоту 1
	bool is_empty_1() 
	{

		if (pos1 == -1) return 1;
		else return 0;
	}
	//проверка на пустоту 2
	bool is_empty_2()
	{
		if (pos2 == SIZE) return 1;
		else return 0;
	}
	//проверка на полноту
	bool is_full()
	{
		if ((pos2-pos1)==1) return 1;
		else return 0;
	}
	//записываем новый элемент в 1 стек
	void Push_1(T elem)
	{
		if (is_full())throw "error with func Push_1, no more memory";
		pos1++;
		mas[pos1] = elem;
	}
	//записываем новый элемент вo 2 стек
	void Push_2(T elem)
	{
		if (is_full())throw "error with func Push_2, no more memory";
		pos2--;
		mas[pos2] = elem;
	}
	T Pop_1()
	{
		if (is_empty_1())throw "error with func Pop_1,empty stack";
		T elem = mas[pos1];
		pos1--;
		return elem;
	}
	T Pop_2()
	{
		if (is_empty_2())throw "error with func Pop_2,empty stack";
		T elem = mas[pos2];
		pos2++;
		return elem;
	}
	//очистить стек 1
	void clear_1() {
		pos1 = -1;
	}
	//очистить стек 2
	void clear_2() {
		pos2 = SIZE ;
	}
	//очистить оба стека
	void clear_all() {
		pos1 = -1;
		pos2 = SIZE;
	}
	//вывод
	friend ostream& operator<<(ostream& out, const TDStack& st) {
		out << "{ ";
		for (int i = 0; i <= st.pos1; i++) {
			out << st.mas[i] <<' ';
		}
		out << "| ";
		for (int i = st.pos2; i <= st.SIZE-1; i++) {
			out << st.mas[i] << ' ';
		}
		out << "} ";
		return out;
	}

};
