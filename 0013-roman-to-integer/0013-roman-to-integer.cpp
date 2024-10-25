class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int length = s.size();
        
        for (int i = 0; i < length; i++) {
            if (s.at(i) == 'M') {
                result += 1000;
            }
            else if (s.at(i) == 'D') {
                result += 500;
            }
            else if (s.at(i) == 'C') {
                if (length - i > 1) {
                    if (s.at(i + 1) == 'M') {
                        result += 900;
                        i += 1;
                        continue;
                    }
                    if (s.at(i + 1) == 'D') {
                        result += 400;
                        i += 1;
                        continue;
                    }
                }
                result += 100;
            }
            else if (s.at(i) == 'L') {
                result += 50;
            }
            else if (s.at(i) == 'X') {
                if (length - i > 1) {
                    if (s.at(i + 1) == 'C') {
                        result += 90;
                        i += 1;
                        continue;
                    }
                    if (s.at(i + 1) == 'L') {
                        result += 40;
                        i += 1;
                        continue;
                    }
                }
                result += 10;
            }
            else if (s.at(i) == 'V') {
                result += 5;
            }
            else if (s.at(i) == 'I') {
                if (length - i > 1) {
                    if (s.at(i + 1) == 'X') {
                        result += 9;
                        i += 1;
                        continue;
                    }
                    if (s.at(i + 1) == 'V') {
                        result += 4;
                        i += 1;
                        continue;
                    }
                }
                result += 1;
            }
        }

        return result;
    }
};