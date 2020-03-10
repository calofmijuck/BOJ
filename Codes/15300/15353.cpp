#include <iostream>

using namespace std;

const int EXPONENT = 10010;

class BigInteger{
	public:
        short int num[EXPONENT];
		BigInteger(string s);

		BigInteger operator+(BigInteger a);
        void print();
};

BigInteger::BigInteger(string s) {
    int i = 0;
    for(; i < s.length(); i++)
        num[s.length() - 1 - i] = s.at(i) - '0';
    for(; i < EXPONENT; i++)
        num[i] = 0;
}

BigInteger BigInteger::operator+(BigInteger a) {
	BigInteger temp("0");
	int curr = 0;
	int carry = 0;
	for(int i = 0; i < EXPONENT; i++) {
		curr = num[i] + a.num[i] + carry;
        carry = curr / 10;
        curr %= 10;
		temp.num[i] = curr;
	}
	return temp;
}

void BigInteger::print() {
    int i = EXPONENT - 1;
    while(num[i] == 0) {
        i--;
        if(i == -1) {
            cout << 0;
            break;
        }
    }
    for(; i >= 0; i--)
        cout << num[i];
}

int main() {
    string a, b;
    cin >> a >> b;
    BigInteger num1(a), num2(b);
    BigInteger c = num1 + num2;
    c.print();
}