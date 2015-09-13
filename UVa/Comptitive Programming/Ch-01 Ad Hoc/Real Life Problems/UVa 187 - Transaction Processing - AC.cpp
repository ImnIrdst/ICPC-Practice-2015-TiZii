#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

string space30(string s) {
	for (int i = s.size(); i < 30; i++) {
		s += " ";
	}
	return s;
}

int main() {
	string line;
	vector<string> input_order;
	map<string, string> account_name;
	map<string, double> account_balance;

	while (true) {
		getline(cin, line);
		if (line.substr(0, 3) == "000")
			break;
		if (line.substr(0, 3) != "000") {
			account_name[line.substr(0, 3)] = line.substr(3);
		}
		input_order.push_back(line.substr(0, 3));
	}

	double total = 0.0;
	double curr_amount = 0.0;
	string curr_tran_id = "";
	string prev_tran_id = "";
	string curr_account = "";
	while (true) {
		cin >> line >> curr_amount; 
		
		curr_tran_id = line.substr(0, 3);
		curr_account = line.substr(3, 6);
		if (prev_tran_id != "" && prev_tran_id != curr_tran_id && fabs(total - 0) > 1e-9) {
			// imbalance
			printf("*** Transaction %s is out of balance ***\n", prev_tran_id.c_str());
			for (int i = 0; i < input_order.size(); i++) {
				if (account_balance.count(input_order[i])) {
					printf("%s %s %10.2lf\n", input_order[i].c_str(), 
						space30(account_name[input_order[i]]).c_str(), account_balance[input_order[i]]/100);
				}
			}
			printf("999 %s %10.2lf\n\n", space30("Out of Balance").c_str(), total/100);
			
			total = 0.0;
			account_balance.clear();
			//continue;
		}
		if (prev_tran_id != "" && prev_tran_id != curr_tran_id && fabs(total - 0) < 1e-9) {
			// balance 
			account_balance.clear(); total = 0;
		}
		if (line.substr(0, 3) == "000") break;
		total -= curr_amount;
		prev_tran_id = curr_tran_id;

		if (account_balance.count(curr_account)) {
			account_balance[curr_account] += curr_amount;
		}
		else {
			account_balance[curr_account]  = curr_amount;
		}

	}
}