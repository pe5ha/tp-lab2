#pragma once
#include <fstream>
#include "sign.h"

enum gr {
	less_ = 0, //� ������� ����������
	great_ = 1 //� ������� ����������
};

class stack {
	SIGN* data;
	int size_;

public:
	stack();
	stack(int);
	stack(const stack&);
	~stack();

	stack& operator=(const stack&);
	stack operator+(const stack&); //stack = stack1 + stack2
	stack operator+(const SIGN&); //push_back(SIGN)
	stack operator-(int); //stack.pop(int) //�������� ��������� int ���������

	friend stack& operator+=(stack&, const stack&); // stack += stak1
	friend stack& operator+=(stack&, const SIGN); //stack += SIGN
	friend stack& operator-=(stack&, int); //stack.erase(ID) //�������� �������� �� index

	void info_id(int);		//����� �������� ����� �� id
	void save_to_file(std::string);
	void extract_from_file(std::string);

	void sort_by_birth(gr);
	void out_by_sign(std::string);	


	friend std::ostream& operator << (std::ostream& out, stack& tmp);

	int SIZE();
};