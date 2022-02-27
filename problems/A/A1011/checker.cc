#include <cstdio>
#include <cmath>
using namespace std;

#define AC 0
#define WA 1
#define ERROR -1

int spj(FILE* input, FILE* user_output);

void close_file(FILE* f) {
    if (f != NULL) {
        fclose(f);
    }
}

int main(int argc, char* args[]) {
    FILE *input = NULL, *user_output = NULL;
    int result;
    if (argc != 3) {
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if (input == NULL || user_output == NULL) {
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("result: %d\n", result);

    close_file(input);
    close_file(user_output);
    return result;
}

long long judge(long double n, long double p1, long double p2, long double p3, long double p4) {
    return (long long)(floor(n * (100 - p1) / 100)) +
           (long long)(floor(n * 0.85l * (100 - p2) / 100)) +
           (long long)(floor(n * 0.7225l * (100 - p3) / 100)) +
           (long long)(floor(n * 0.614125l * (100 - p4) / 100));
}

int spj(FILE* input, FILE* user_output) {
    int cases = -1;
    fscanf(input, "%d", &cases);

    while (cases--) {
        long long n, p1, p2, p3, p4;
        fscanf(input, "%lld%lld%lld%lld%lld", &n, &p1, &p2, &p3, &p4);

        long long ans = judge(n, p1, p2, p3, p4);

        long long user_ans;
        if (!~fscanf(user_output, "%lld", &user_ans)) return WA;
        if (abs(user_ans - ans) > 2) {
            // cerr << n << " " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
            // cerr << ans << " " << user_ans << endl;
            return WA;
        }
    }
    return AC;
}