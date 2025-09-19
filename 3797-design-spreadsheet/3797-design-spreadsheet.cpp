#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    map<pair<char,int>, int> mpp; // key = (column, row), value = cell value
    int rows;

public:
    Spreadsheet(int r) {
        rows = r;
    }
    
    void setCell(string cell, int value) {
        char col = cell[0]; // e.g. 'A'
        int row = stoi(cell.substr(1)); // e.g. "12" -> 12
        mpp[{col, row}] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        int row = stoi(cell.substr(1));
        mpp[{col, row}] = 0;
    }
    
    int getValue(string formula) {
        // formula like "=A1+B2" or "=5+10"
        if (formula[0] == '=') formula = formula.substr(1);
        
        size_t plusPos = formula.find('+');
        string str1 = formula.substr(0, plusPos);
        string str2 = formula.substr(plusPos + 1);

        auto getVal = [&](string s) -> int {
            if (isalpha(s[0])) { 
                char col = s[0];
                int row = stoi(s.substr(1));
                return mpp[{col, row}];
            } else {
                return stoi(s);
            }
        };

        return getVal(str1) + getVal(str2);
    }
};

/**
 * Example usage:
 * Spreadsheet* obj = new Spreadsheet(10);
 * obj->setCell("A1", 5);
 * obj->setCell("B2", 10);
 * cout << obj->getValue("=A1+B2"); // 15
 * cout << obj->getValue("=5+10");  // 15
 */
