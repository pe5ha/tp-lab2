#include <iostream>
#include <string>
#include "fileStr.h"

using namespace std;

fileStr::fileStr() : pth(""), txt("") {}
fileStr::fileStr(string pth_) : pth(pth_), txt("") {
	file.open(pth, ios::in);
	try {
		if (!file.is_open())
			throw exception("file not found");
	}
	catch (exception& exp) { cout << exp.what() << "\n"; system("pause > nul"); }
}
fileStr::~fileStr() { file.close(); }

void fileStr::open(string pth) {
	file.open(pth, ios::in);
	try {
		if (!file.is_open())
			throw exception("file not found");
	}
	catch (exception& exp) { cout << exp.what() << "\n"; system("pause > nul"); }
}

bool fileStr::read() {
	string sent;
	bool er = 0;
	while (!file.eof()) {
		getline(file, sent);
		txt += sent;
	}
	file.seekg(0);
	
	return (txt.length() > 0 ? false : true);
}

void fileStr::analysis() {
	int cursor_beg = 0; //������ �� ������ �����������
	int cursor_end = 0; //������ �� ����� �����������
	std::string sent;

	for (int i = 0; i < txt.length(); i++) { //��������� �����
		if (txt[i] == '!' || txt[i] == '?' || txt[i] == '.') { //������� ��������� �����������
			cursor_end = i; 

			for (int cur = cursor_beg; cur <= cursor_end; cur++) //������������ �����������
				sent.push_back(txt[cur]);
			cursor_beg = cursor_end + 1;

			if (sent[0] == ' ') //������� ������ ������, ���� �� ����
				sent.erase(0, 1);

			/*������������ �����������*/
			if (txt[i] == '?')  
				interrogative_sent.push_back(sent);
			else if (txt[i] == '!')
				exclamation_sent.push_back(sent);
			sent.clear();
		}
	}
	
	//�����
	for (int i = 0; i < interrogative_sent.size(); i++)
		cout << interrogative_sent.at(i) << endl;
	for (int i = 0; i < exclamation_sent.size(); i++)
		cout << exclamation_sent.at(i) << endl;
}
