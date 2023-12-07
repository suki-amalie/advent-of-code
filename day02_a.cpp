#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

const int RED = 12;
const int GREEN = 13;
const int BLUE = 14;

map<string, int> m = {{"red", RED}, {"green", GREEN}, {"blue", BLUE}};

int main() {
    ifstream readFile("input_02.txt");
    string line;
    if (readFile.is_open()) {
        int total = 0;
        while (getline(readFile, line)) {
            bool valid = true;
            stringstream ss;
            ss << line;
            string str, color;
            int id, num;
            ss >> str >> id >> str;
            while (ss) {
                ss >> num >> color;
                if (color.back() == ',' or color.back() == ';') {
                    color = color.substr(0, color.size()-1);
                }
                if (num > m[color]){
                    valid = false;
                }
            }
            if (valid) {
                total += id;
            }
        }
        cout << total;
    }else {cout << "Unable to open file\n";}
    return 0;
}