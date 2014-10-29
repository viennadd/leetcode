class Solution {
public:
    int atoi(const char *str) {
        long long value = 0;
        int mul = 1;

        bool meet_first_non_zero = false;

        for (int i = 0; str[i]; ++i) {

            if (!meet_first_non_zero && (str[i] == '0' || str[i] == ' ')) {
                continue;
            }

            if (!meet_first_non_zero && (str[i] != '0' || str[i] != ' ')) {
                meet_first_non_zero = true;

                if (str[i] == '-') {
                    mul = -1;
                    continue;

                } else if (str[i] == '+') {
                    continue;

                }

                if (str[i] < '0' || str[i] > '9') {
                    break;

                } else {
                    value *= 10;
                    value += (str[i] - '0');
                }

                continue;
            }

            if (meet_first_non_zero) {
                if (str[i] >= '0' && str[i] <= '9') {
                    value *= 10;
                    value += (str[i] - '0');

                } else {
                    break;

                }
            }

        }
        value *= mul;
        value = value > 2147483647 ? 2147483647 : value;
        value = value < -2147483648 ? -2147483648 : value;
        return value;
    }
};