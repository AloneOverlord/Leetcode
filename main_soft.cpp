#include"student.h"
#include<fstream>
#include<sstream>

using namespace std;
string student::get_name()const{
	return name;
}
int student::get_score()const{
	return score;
}
void student::show_score()const {
	cout << "������" << name << " " << "�ɼ���" << score << endl;
}
//�ļ�������Ϣ
void load_inf(vector<student>&stu) {
	fstream file;
	file.open("student_score.txt", ios::in);
	if (!file) {
		cerr << "file open fail" << endl;
		return ;
	}
	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		string name;
		int score;
		if (iss >> name >> score) {
			stu.emplace_back(name, score);
		}
		
	}
	file.close();
	if (!stu.empty()) {
		cout << "���سɹ���һ����" << stu.size() << "��ѧ��" << endl;
	}
}
//�Զ�������Ϣ
void save_inf(vector<student>&stu) {
	fstream file;
	file.open("student_score.txt", ios::out);
	if (!file) {
		cerr << "�ļ�����ʧ��" << endl;
		return ;
	}
	for (auto& c : stu) {
		file << c.get_name() << " " << c.get_score() << endl;
	}
	file.close();
	cout << "�ļ�����ɹ�" << endl;
}
//�û��ֶ����뵼������
void add_info(vector<student>&stu) {
		string temp;
	do {
		cout << "�����������ɼ�����ʽ������ �ɼ�����" << endl;
		string name;
		int score;
		string name_score;
		getline(cin, name_score);
		istringstream iss(name_score);
		if (iss >> name >> score) {
			stu.emplace_back(name, score);
			cout << "����ɹ�" << name << " " << score << endl;
		}
		else {
			cerr << "fail load" << endl;
		}
		cout << "�Ƿ�������룬#���˳�" << endl;
		getline(cin, temp);
	} while (temp != "#");
}
int main() {
	//�������ļ�������Ϣ
	vector<student>stu;
	load_inf(stu);
	add_info(stu);
	for (auto& c : stu) {
		cout << c.get_name() << c.get_score() << endl;
	}
	
	save_inf(stu);
}
