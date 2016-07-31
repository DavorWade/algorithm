#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <locale>
#include <algorithm>

using namespace std;

/*
Description:
To prepare for the English exam Little Ho collected many digital reading materials. Unfortunately the materials are messed up by a malware.

It is known that the original text contains only English letters (a-zA-Z), spaces, commas, periods and newlines, conforming to the following format:

1. Each sentence contains at least one word, begins with a letter and ends with a period.

2. In a sentence the only capitalized letter is the first letter.

3. In a sentence the words are separated by a single space or a comma and a space.

4. The sentences are separated by a single space or a single newline.

It is also known the malware changes the text in the following ways:

1. Changing the cases of letters.

2. Adding spaces between words and punctuations.

Given the messed text, can you help Little Ho restore the original text?

Input:
A string containing no more than 8192 English letters (a-zA-Z), spaces, commas, periods and newlines which is the messed text.

Output:
The original text.

Sample input:
my Name  is Little   Hi.
His   name IS Little ho  ,  We are   friends.

Sample output:
My name is little hi.
His name is little ho, we are friends.
*/

class Solution {
private:
    vector<string> &split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }

public:
    string process(const string s) {
        string originSen;
        bool isCapital = false;
        vector<string> rs;
        char delim = ' ';

        rs = split(s, delim);

        for (int i = 0; i < rs.size(); i++) {
            if (rs[i] != "") {
                //cout << "rs[" << i << "]:" << rs[i] << endl;
                if (rs[i] == ","){
                    originSen.append(",");
                }
                else if (rs[i] == "."){
                    originSen.append(".");
                    isCapital = true;
                }
                else {
                    transform(rs[i].begin(), rs[i].end(), rs[i].begin(), ::tolower);
                    if (isCapital || i == 0) {
                        locale loc;
                        rs[i][0] = toupper(rs[i][0], loc);
                        if (i != 0) originSen.append(" ");
                        originSen.append(rs[i]);
                    }
                    else {
                        originSen.append(" ");
                        originSen.append(rs[i]);
                    }

                    if (rs[i].find('.') != string::npos)
                        isCapital = true;
                    else
                        isCapital = false;
                }
            }
        }

        return originSen;
    }
};

/*
int main() {
    vector<string> data;
    string tem;
    Solution s;

    getline(cin, tem);
    while (tem != "") {
        data.push_back(tem);
        getline(cin, tem);
    }

    for (int i = 0; i < data.size(); i++) {
        string rs = s.process(data[i]);
        cout << rs << endl;
    }

    system("pause");
    return 0;
}*/
