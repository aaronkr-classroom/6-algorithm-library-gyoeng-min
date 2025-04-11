//split_iter.cpp
#include<algorithm>// find_if()
#include<cctype>// isspace()
#include <iostream>
#include<string>
#include<vector>

using namespace std;


//�μ��� ������ ���� true, �׷��� ���� ���� false
 bool space(char c) {
	return isspace(c);
}//�μ��� ������ ���� false, �׷��� ���� ���� true
 bool not_space(char c) {
	return !isspace(c);
}

 typedef string::size_type str_sz;
 typedef string::const_iterator iter;


vector <std::string> split(const string& s) {
	vector<string> ret;
	iter i = s.begin();

	//�Һ��� : ���ݱ��� [������ i, ������ i )������ �ִ�
	//���ڿ��� ó��
	while (i != s.end()) {
		cout << "String begin pos:" <<
			distance(s.begin(), i) << endl;

		//���� ������ ����
		//���� i��ġ���� ù ��° ���� �ƴ� ���� ã��
		i = find_if(i, s.end(), not_space);
		cout << "String find pos: " <<
			distance(s.begin(), i) << endl;

		//���� �ܾ��� ���� ã��
		//while �ݺ��� �� �׻� ���ο� �ݺ��� j�� ����
		//���� i ��ġ ���� ù ��° ���� ���� ã��
		iter j = find_if(i, s.end(), space);
		cout << "j pos :" <<
			distance(s.begin(), j) << endl;

		//[i,j) ���� ���ڸ� ����
		if (i != s.end()) {
			ret.push_back(string(i, j));//substr() �ε��� ���� ��
		}

		//i�ݺ��� ��ġ�� j�ݺ����� ��ġ�� ����(�̵�)�ϱ�
		i = j;
		cout << "i �̵� pos : " <<
			distance(s.begin(), i) << endl;

	}
	return ret;
}

int main() {
	string s;

	//���ڿ��� �� �྿ �Է¹޾� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		//����v�� ������ �ܾ ���� ���
		for (str_sz i = 0; i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}
	return 0;
}