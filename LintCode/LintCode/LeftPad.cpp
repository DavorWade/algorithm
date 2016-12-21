#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class StringUtils {
public:
    /**
    * @param originalStr the string we want to append to
    * @param size the target length of the string
    * @param padChar the character to pad to the left side of the string
    * @return a string
    */
    static string leftPad(string& originalStr, int size, char padChar = ' ') {
        // Write your code here
        if (originalStr.size() >= size) return originalStr;

        return string(size - originalStr.size(), padChar) + originalStr;
    }
};
