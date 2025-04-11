//main_analysis.cpp
#include<vector>
#include<iostream>

#include"Student_info.h"
#include"analysis.h"

using namespace std;

int main() {
	vector<Student_info>did, didnt;

	Student_info record;
	while (read(cin, record)) {
		if (did_all_hw(record))
			did.push_back(record);
		else
			didnt.push_back(record);
	
	}
	if (did.empty()) {
		cout << "No student did HW!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did HW!" << endl;
		return 1;
	}
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of HW turned in", optimistic_mdeian_analysis, did, didnt);

	return 0;

}

