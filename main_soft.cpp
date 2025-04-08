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
	cout << "姓名：" << name << " " << "成绩：" << score << endl;
}
//文件导入信息
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
		cout << "加载成功！一共：" << stu.size() << "名学生" << endl;
	}
}
//自动保存信息
void save_inf(vector<student>&stu) {
	fstream file;
	file.open("student_score.txt", ios::out);
	if (!file) {
		cerr << "文件保存失败" << endl;
		return ;
	}
	for (auto& c : stu) {
		file << c.get_name() << " " << c.get_score() << endl;
	}
	file.close();
	cout << "文件保存成功" << endl;
}
//用户手动输入导入数据
void add_info(vector<student>&stu) {
		string temp;
	do {
		cout << "请输入姓名成绩（格式：姓名 成绩）：" << endl;
		string name;
		int score;
		string name_score;
		getline(cin, name_score);
		istringstream iss(name_score);
		if (iss >> name >> score) {
			stu.emplace_back(name, score);
			cout << "导入成功" << name << " " << score << endl;
		}
		else {
			cerr << "fail load" << endl;
		}
		cout << "是否继续输入，#号退出" << endl;
		getline(cin, temp);
	} while (temp != "#");
}
int main() {
	//批量从文件导入信息
	vector<student>stu;
	load_inf(stu);
	add_info(stu);
	for (auto& c : stu) {
		cout << c.get_name() << c.get_score() << endl;
	}
	
	save_inf(stu);
}
