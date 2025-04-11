//Student_info.cpp
#include "student_info.h"

bool compare(const Student_info& x, const Student_info& y){
	return x.name < y.name;// A < Z�϶� �� ��ȯ,  Z < A�϶� ���� ��ȯ
}

std::istream& read(std::istream& is, Student_info& s) {
	//�л��� �̸�, �߰���� ����, �⸻��� ���� �а� ����
	is >> s.name >> s.midterm >> s.final;
	//���� ������ ����
	read_hw(is, s.homework);
	return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
	if (in) {
		//���� ������ ����
		hw.clear();

		//�Է��� ���� ���� 
		double x;//cin���� ����ϱ�

		//�Է¹��� ������ ���� sum
		while (in >> x) {
			hw.push_back(x);
		}

		//���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
		in.clear();

		
	}
	return in;
}
