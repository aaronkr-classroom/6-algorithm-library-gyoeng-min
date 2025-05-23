//Student_info.cpp
#include "student_info.h"

bool compare(const Student_info& x, const Student_info& y){
	return x.name < y.name;// A < Z일때 참 반환,  Z < A일때 거짓 반환
}

std::istream& read(std::istream& is, Student_info& s) {
	//학생의 이름, 중간고사 점수, 기말고사 점수 읽고 저장
	is >> s.name >> s.midterm >> s.final;
	//과제 점수를 읽음
	read_hw(is, s.homework);
	return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
	if (in) {
		//이전 내용을 제거
		hw.clear();

		//입력을 위한 변수 
		double x;//cin에서 사용하기

		//입력받은 점수의 합은 sum
		while (in >> x) {
			hw.push_back(x);
		}

		//다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();

		
	}
	return in;
}
