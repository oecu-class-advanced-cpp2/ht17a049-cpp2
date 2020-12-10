#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/*    --------------------------------------------------------------- */
/*
*  nth_prime  *
*  与えられた正整数a と d と n に対して、この等差数列に含まれる n 番目の
*素数を返す。
*
*  TODO: このnth_prime 関数を実装せよ。必要であれば他に関数や
*  ファイルを作成せよ。
*/
/*    -------------------------------------------------------------- */
int is_prime(int a) {
	if (a < 2) return false;
	if (a == 2) return true;
	for (int i = 2; i <= a / 2; i++) {
		if (a%i == 0) {
			return false;
		}
	}
	return true;
};
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int num = a;
	int count = 0;
	for (;;) {
		count += is_prime(num);
		if (count == n) {
			return num;
		}
		num += d;
	}
};
int main() {
	std::cout << "答え92809：出力値" << nth_prime(367, 186, 151) << std::endl;
	std::cout << "答え6709：出力値" << nth_prime(179, 10, 203) << std::endl;
	std::cout << "答え12037：出力値" << nth_prime(271, 37, 39) << std::endl;
	std::cout << "答え103：出力値" << nth_prime(103, 230, 1) << std::endl;
	std::cout << "答え93523：出力値" << nth_prime(27, 104, 185) << std::endl;
	std::cout << "答え14503：出力値" << nth_prime(253, 50, 85) << std::endl;
	std::cout << "答え2：出力値" << nth_prime(1, 1, 1) << std::endl;
	std::cout << "答え899429：出力値" << nth_prime(9075, 337, 210) << std::endl;
	std::cout << "答え5107：出力値" << nth_prime(307, 24, 79) << std::endl;
	std::cout << "答え412717：出力値" << nth_prime(331, 221, 177) << std::endl;
	std::cout << "答え22699：出力値" << nth_prime(259, 170, 40) << std::endl;
	std::cout << "答え25673：出力値" << nth_prime(269, 58, 102) << std::endl;
	// 以下、同様に、入出力例通りになるか確認せよ。
	std::cin.get();
	return 0;
}