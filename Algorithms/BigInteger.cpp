#include <iostream>
using namespace std;

const int EXPONENT = 10001;

class BigInteger{
	short int num[EXPONENT];
	public:
		BigInteger();
		BigInteger(int n);
		BigInteger(string s);
		BigInteger mul2();

		BigInteger operator+(BigInteger a);
	//	BigInteger operator*(BigInteger a);
	//	BigInteger operator=(BigInteger a);
		friend ostream& operator<<(ostream& out, BigInteger a);
		friend istream& operator>>(istream& in, BigInteger a)
};

BigInteger::BigInteger() {
	for(int i = 0; i < EXPONENT; i++) {
		num[i] = 0;
	}
}

BigInteger::BigInteger(int n) {
	int i = 0;
	while(n > 0) {
		num[i] = n % 10;
		n /= 10;
		i++;
	}
	for(; i < EXPONENT; i++) {
		num[i] = 0;
	}
}

BigInteger::BigInteger(string s) {
    for(int i = 0; i < s.length(); i++) {
        num[s.length() - 1 - i] = s.at(i)-'0';
    }
}

BigInteger BigInteger::mul2() {
	BigInteger temp;
	int curr = 0;
	int carry = 0;
	for(int i = 0; i < EXPONENT; i++) {
		curr = num[i] * 2 + carry;
		if(curr >= 10) {
			carry = curr / 10;
			curr %= 10;
		} else {
			carry = 0;
		}
		temp.num[i] = curr;
	}
	return temp;
}


BigInteger BigInteger::operator+(BigInteger a) {
	BigInteger temp;
	int curr = 0;
	int carry = 0;
	for(int i = 0; i < EXPONENT; i++) {
		curr = num[i] + a.num[i] + carry;
		if(curr >= 10) {
			carry = curr / 10;
			curr %= 10;
		} else {
			carry = 0;
		}
		temp.num[i] = curr;
	}
	return temp;
}

/*BigInteger BigInteger::operator=(BigInteger a) {
	BigInteger temp;
	for(int i = 0; i < EXPONENT; i++) {
		temp.num[i] = a.num[i];
	}
	return temp;
}*/

ostream& operator<<(ostream& out, BigInteger a) {
	int i = EXPONENT - 1;
	while(a.num[i] == 0) {
		i--;
	}
	for(; i >= 0; i--) {
		out << a.num[i];
	}
}


int main() {

}
