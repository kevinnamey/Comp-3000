/*Kevin Namey
 *Homework 4
 *hw4.cpp
 *kan0010
 *
 */

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void press_any_key(void);

void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

bool A_alive;
bool B_alive;
bool C_alive;
int round;
const int MAX_SIM_NUM = 10000;
const int AARON_PERCENTAGE = 33;
const int BOB_PERCENTAGE = 50;
int A_win1, B_win1, C_win1;
int A_win2, B_win2, C_win2;

int main() {
	srand(time(0));
	cout << "*** Welcome to Kevin Namey's Duel Simulator\n";
	test_at_least_two_alive();
	test_Aaron_shoots1();
	test_Bob_shoots();
	test_Bob_shoots();
	test_Charlie_shoots();
	test_Aaron_shoots2();

	cout << "Ready to test Strategy 1 (run 10000 times) :\n";
	press_any_key();

	//Strategy 1.
	A_win1 = 0, B_win1 = 0, C_win1 = 0;
	for (int i = 0; i < MAX_SIM_NUM; i++) {
		A_alive = true, B_alive = true, C_alive = true;
		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
			if (A_alive) Aaron_shoots1(B_alive, C_alive);
			if (B_alive) Bob_shoots(A_alive, C_alive);
			if (C_alive) Charlie_shoots(A_alive, B_alive);
		}
	if (A_alive) A_win1++;
	if (B_alive) B_win1++;
	if (C_alive) C_win1++;
	}
	
	cout << "Aaron won " << A_win1 << "/10000 duels or "
		<< A_win1 * 100 / 10000.00 << "%\n";
	cout << "Bob won " << B_win1 << "/10000 duels or "
		<< B_win1 * 100 / 10000.00 << "%\n";
	cout << "Charlie won " << C_win1 << "/10000 duels or "
		<< C_win1 * 100 / 10000.00 << "%\n\n";

	cout << "Ready to test Strategy 2 (run 10000 times)\n";
	press_any_key();

	//Strategy 2.
	for (int i = 0; i < MAX_SIM_NUM; i++) {
		round = 1;
		A_alive = true, B_alive = true, C_alive = true;
		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
			if (A_alive) Aaron_shoots2(B_alive, C_alive);
			if (B_alive) Bob_shoots(A_alive, C_alive);
			if (C_alive) Charlie_shoots(A_alive, B_alive);
			round++;
		}
		if (A_alive) A_win2++;
		if (B_alive) B_win2++;
		if (C_alive) C_win2++;
	}
	
	cout << "Aaron won " << A_win2 << "/10000 duels or "
		<< A_win2 * 100 / 10000.00 << "%\n";
	cout << "Bob won " << B_win2 << "/10000 duels or "
		<< B_win2 * 100 / 10000.00 << "%\n";
	cout << "Charlie won " << C_win2 << "/10000 duels or "
		<< C_win2 * 100 / 10000.00 << "%\n";

	if (A_win1 > A_win2) {
		cout << "Strategy 1 is better than strategy 2.";
	}
	else {
		cout << "Strategy 2 is better than strategy 1.";
	}
	return 0;
}

bool at_least_two_alive(bool a_alive, bool b_alive, bool c_alive) {
	int i = 0;
	if (a_alive == true) i++;
	if (b_alive == true) i++;
	if (c_alive == true) i++;
	if (i > 1) return true;
	else return false;
}

void Aaron_shoots1(bool& b_alive, bool& c_alive) {
	int shot = rand() % 100;
	if (c_alive == true) {
		if (shot <= AARON_PERCENTAGE) C_alive = false;
	}
	else {
		if (shot <= AARON_PERCENTAGE) B_alive = false;
	}
}

void Bob_shoots(bool& a_alive, bool& c_alive) {
	int shot = rand() % 100;
	if (c_alive == true) {
		if (shot <= BOB_PERCENTAGE) C_alive = false;
	}
	else {
		if (shot <= BOB_PERCENTAGE) A_alive = false;
	}
}

void Charlie_shoots(bool& a_alive, bool& b_alive) {
	if (b_alive == true) {
		B_alive = false;
	}
	else A_alive = false;
}

void Aaron_shoots2(bool& b_alive, bool& c_alive) {
	if (round > 1) {
		Aaron_shoots1(b_alive, c_alive);
	}
}

void press_any_key(void) {
	cout << "Press any key to continue...";
	cin.ignore().get();
} 

void test_at_least_two_alive(void) {
	cout << "Unit testing 1: : Function - at_least_two_alive()\n";

	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";

	press_any_key();
}

void test_Aaron_shoots1(void) {
	cout << "Unit Testing 2: Function - Aaron_shoots1()\n";

	cout << "\tCase 1: Bob alive, Charlie alive\n"
		<< "\t\tAaron is shooting at Charlie\n";

	cout << "\tCase 2: Bob dead, Charlie alive\n"
		<< "\t\tAaron is shooting at Charlie\n";
	
	cout << "\tCase 3: Bob alive, Charlie dead\n"
		<< "\t\tAaron is shooting at Bob\n";
	press_any_key();
}

void test_Bob_shoots(void) {
	cout << "Unit Testing 3: Function - Bob_shoots()\n";
	
	cout << "\tCase 1: Aaron alive, Charlie alive\n"
		<< "\t\tBob is shooting at Charlie\n";

	cout << "\tCase 2: Aaron dead, Charlie alive\n"
		<< "\t\tBob is shooting at Charlie\n";

	cout << "\tCase 3: Aaron alive, Bob dead\n"
		<< "\t\tBob is shooting at Aaron\n";
	press_any_key();
}

void test_Charlie_shoots(void) {
	cout << "Unit Testing 4: Function - Charlie_shoots()\n";

	cout << "\tCase 1: Aaron alive, Charlie alive\n"
		<< "\t\tBob is shooting at Charlie\n";

	cout << "\tCase 2: Aaron dead, Charlie alive\n"
		<< "\t\tBob is shooting at Charlie\n";

	cout << "\tCase 3: Aaron alive, Charlie dead\n"
		<< "\t\tBob is shooting at Aaron\n";
	press_any_key();
}

void test_Aaron_shoots2(void) {
	cout << "Unit Testing 5: Function - Aaron_shoots2()\n";
	
	cout << "\tCase 1: Aaron's first shot\n"
		<< "\t\tAaron missed intentionally\n";

	cout << "\tCase 2: Bob's alive, Charlie dead\n"
		<< "\t\tAaron shoots at Bob\n";

	cout << "\tCase 3: Bob dead, Charlie alive\n"
		<< "\t\tAaron shoots at Charlie\n";
	press_any_key();
}
