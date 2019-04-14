#include<iostream>
using namespace std;
const int MAX = (int)2e8;
int n;
int count = 0;
void bitRepresentation(int x) {
	for (int i = 31; i >= 0; i--) {
		if (x&(1 << i))
			cout << "1";
		else
			cout << "0";
	}
	cout << "\n";
}

int bit_on(int x, int pos) {	// pos = position to set 1
	return x | (1 << pos);
}

int bit_off(int x, int pos) {	// pos = position to set 0
	return x & ~(1 << pos);
}

int bit_invert(int x, int pos) {	// pos = position to invert bit
	return x ^ (1 << pos);
}

int bit_off_last_one_bit(int x) {	// sets the last one bit of x to zero
	return x & (x - 1);
}

int bit_off_all_one_except_last(int x) {
	return x & -x;	// sets all the one bits to zero, except for the last one bit
}

int bit_invert_all_bit(int x){
	return x | (x - 1);		//inverts all the bits after the last one bit
}
bool is_form_of_power_of_two_based(int x) {
	return (x&(x - 1)) == 0;	// is positive number x of the form 2^k
}

void display() {
	cout << "choose: \n";
	cout << "0\tbit_on\n1\tbit_off\n2\tbit_invert\n";
	cout << "3\tset the last one bit of x to zero\n";
	cout << "4\tset all the one bits to zero, except for the last one bit\n";
	cout << "5\tinvert all the bits after the last one bit\n";
	cout << "6\tis positive number x of the form 2^k?\n";
	cout << "7\texit\n";
	int choice, pos;
	cin >> choice;

	switch (choice)
	{
	case 0:
		cout << "pos : ";
		cin >> pos;
		n = bit_on(n, pos);
		bitRepresentation(n);
		break;
	case 1:
		cout << "pos : ";
		cin >> pos;
		n = bit_off(n, pos);
		bitRepresentation(n);
		break;
	case 2:
		cout << "pos : ";
		cin >> pos;
		n = bit_invert(n, pos);
		bitRepresentation(n);
		break;
	case 3:
		n = bit_off_last_one_bit(n);
		bitRepresentation(n);
		break;
	case 4:
		n = bit_off_all_one_except_last(n);
		bitRepresentation(n);
		break;
	case 5:
		n = bit_invert_all_bit(n);
		bitRepresentation(n);
		break;
	case 6:
		if (is_form_of_power_of_two_based(n))
			cout << "2^k based\n";
		else
			cout << "not 2^k based\n";
		bitRepresentation(n);
		break;
	case 7:
		return;
	default:
		break;
	}
	display();
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	//n = 1 << n;
	bitRepresentation(n);
	display();
	//count = 0;
	return 0;
}