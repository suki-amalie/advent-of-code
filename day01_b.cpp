
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <numeric>
#include <string>
using namespace std;
int cal(string line);

map <string, int> m  {
          {"one" ,   1}
        ,{"two" ,  2}
        ,{"three" , 3}
        ,{"four" , 4}
        ,{"five" , 5}
        ,{"six" , 6}
        ,{"seven" , 7}
        ,{"eight" , 8}
        , {"nine" , 9 }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string line;
    ifstream myfile ("input.txt");
    int total =0;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            vector<int> digits;
            int i = 0;
            while(i <= line.size() - 1) {
                if (isdigit(line[i])) {
                    digits.push_back(line[i] - '0');
                }
                for (auto pair: m) {
                    if (line.substr(i, pair.first.size()) == pair.first) {
                        digits.push_back(pair.second);
                        i += pair.first.size() - 2;
                        break;
                    }
                }
                i ++;

            }
            int num = digits[0]*10 + digits.back();
            int n2 = cal(line);
            if (num != n2) {
                cout << num << " " << n2 << endl;
            }
            total += num;

        }
        myfile.close();
        cout << total;
    } else cout << "Unable to open file";
    return 0;
}

int cal(string line) {

    std::vector<std::string> numbers  {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<int> digits;


    for (int i = 0; i < line.size(); i++) {
            const auto c = line[i];
            if (c >= '0' && c <= '9') {
                digits.push_back(c - '0');
            }
            for (int j = 0; j < numbers.size(); j++) {
                const auto& n = numbers[j];
                if (line.size() >= i + n.size()) {
                    if (line.substr(i, n.size()) == n) {
                        digits.push_back(j+1);
                    }
                }
            }
        }
        return digits[0] * 10 + digits.back();
}


