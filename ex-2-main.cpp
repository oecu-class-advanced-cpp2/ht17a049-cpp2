#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

namespace cpp2 {
	/* ---------------------------------------------------------------------
	mcxi

	mcxi 記法を解析するクラスです。
	--------------------------------------------------------------------- */
	class mcxi {
	public:
		/* -----------------------------------------------------------------
		mcxi

		指定された文字列を解析して、オブジェクトを初期化します。
		以下の場合には例外が創出されます。

		1. [2-9,m,c,x,i] 以外の文字が出現した場合
		2. 2 文字続けて数字 (2-9) が出現した場合
		3. m, c, x, i がこの順序で出現しなかった場合
		ただし、例えば mx のように、特定の文字をスキップする事は許容
		されます。
		----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {
			int digit = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					digit = *pos - '0';
				}
				else {
					auto u = unit(*pos);
					value_ += std::max(digit, 1) * u;
					digit = 0;
				}
			}
		}
		mcxi() {}
		/* ----------------------------------------------------------------- 
		operator+

		2 つのオブジェクトの加算結果を取得します。
		 ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) {
			mcxi i;
			i.value_ = value_ + rhs.value_;
			return i;
		}

		/* -----------------------------------------------------------------
		to_string

		現在の値を mcxi 記法に変換します。
		 ----------------------------------------------------------------- */
		std::string to_string() const {
			std::stringstream outstrings;
			int i = value_;
			int j = 0;

			//1000の位の変換
			j = i / 1000;
			if (j == 1) {
				outstrings << "m";
			}
			if (j > 1) {
				outstrings << j;
				outstrings << "m";
			}

			//100の位の変換
			j = i / 100;
			j = j % 10;
			if (j == 1) {
				outstrings << "c";
			}
			if (j > 1) {
				outstrings << j;
				outstrings << "c";
			}

			//10の位の変換
			j = i / 10;
			j = j % 10;
			if (j == 1) {
				outstrings << "x";
			}
			if (j > 1) {
				outstrings << j;
				outstrings << "x";
			}

			//1の位の変換
			j = i % 10;
			if (j == 1) {
				outstrings << "i";
			}
			if (j > 1) {
				outstrings << j;
				outstrings << "i";
			}
			return outstrings.str();
		}

	private:

		/* ----------------------------------------------------------------- 
		unit

		単位に対応する値を取得します。
		 ----------------------------------------------------------------- */
		int unit(char c) {
			if (c == 'm')return 1000;
			if (c == 'c')return 100;
			if (c == 'x')return 10;
			if (c == 'i')return 1;

			return 0;
		}


	private:
		int value_;
	};
}

int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}