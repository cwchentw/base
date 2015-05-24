#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

int digit2i(char);

char i2digit(long long int);

static char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                      'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                      'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                      'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s number from_base to_base\n", argv[0]);
        fprintf(stderr, "  from_base is optional, default to 10\n");
        exit(EXIT_FAILURE);
    }

    long long int from_base = 0;
    long long int to_base = 0;
    char *fromBasePtr;
    char *toBasePtr;
    if (argc == 3) {
        from_base = 10;
        to_base = strtoll(argv[2], &toBasePtr, 10);
        if (*toBasePtr) {
            fprintf(stderr, "Invalid to_base number %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }
    else if (argc == 4) {
        from_base = strtoll(argv[2], &fromBasePtr, 10);
        if (*fromBasePtr) {
            fprintf(stderr, "Invalid from_base number %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        to_base = strtoll(argv[3], &toBasePtr, 10);
        if (*toBasePtr) {
            fprintf(stderr, "Invalid to_base number %s\n", argv[3]);
            exit(EXIT_FAILURE);
        }
    }

    if (from_base < 2 || from_base > 36) {
        fprintf(stderr, "Invalid from_base number %lli\n", from_base);
        exit(EXIT_FAILURE);
    }

    if (to_base < 2 || to_base > 36) {
        fprintf(stderr, "Invalid to_base number %lli\n", to_base);
        exit(EXIT_FAILURE);
    }

    gchar *number = argv[1];
    long long int temp = 0;
    int carry = (int)strlen(number);
    long long int _num = 1;

    for (int i =  carry - 1; i >= 0; i--) {
        int n = digit2i(number[i]);
        if (n < 0) {
            fprintf(stderr, "Error on digit2i\n");
            exit(EXIT_FAILURE);
        }
        temp += n * _num;
        _num = _num * from_base;
    }

    gchar *output = NULL;
    // If temp is zero, do conversion one time.
    do {
        char c = i2digit(temp % to_base);
        char str[] = {c, '\0'};
        if (c == '\0') {
            fprintf(stderr, "Error on i2digit\n");
            g_free(output);
            exit(EXIT_FAILURE);
        }

        output = NULL == output ? g_strconcat(str, NULL) : g_strconcat(str, output, NULL);
        temp = temp / to_base;
    } while (temp);

    g_print("%s\n", output);
    g_free(output);
    return 0;
}

int digit2i(char d) {
    for (int i = 0; i < 36; i++) {
        if (nums[i] == d) {
            return i;
        }
    }
    return -1;
}

char i2digit(long long int i) {
    if (i < 0 || i > 36 - 1) {
        return '\0';
    }
    return nums[i];
}