#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validate_ip_address(const char *ip_address);
int contains_multiple_dots(const char *str);
int contains_indents(const char *str);

int main() {
    // тесты на корректность адресов
    printf("Test 1: %d\n", validate_ip_address("127.0.0.1")); // ожидается 1
    printf("Test 2: %d\n", validate_ip_address("192.168.0.1")); // ожидается 1
    printf("Test 3: %d\n", validate_ip_address("10.0.0.1")); // ожидается 1
    printf("Test 4: %d\n", validate_ip_address("255.255.255.255")); // ожидается 1
    printf("Test 5: %d\n", validate_ip_address("0.0.0.0")); // ожидается 1

    // тесты на ошибки
    printf("Test 6: %d\n", validate_ip_address("256.0.0.1")); // ожидается 0
    printf("Test 7: %d\n", validate_ip_address("192.168.1")); // ожидается 0
    printf("Test 8: %d\n", validate_ip_address("")); // ожидается 0
    printf("Test 9: %d\n", validate_ip_address("192.168..1")); // ожидается 0
    printf("Test 10: %d\n", validate_ip_address("192..168.1...1")); // ожидается 0
    printf("Test 11: %d\n", validate_ip_address("192. 168.1.1")); // ожидается 0
    printf("Test 12: %d\n", validate_ip_address("192,168,1.1")); // ожидается 0
    printf("Test 13: %d\n", validate_ip_address("192./168.1.1")); // ожидается 0
    printf("Test 14: %d\n", validate_ip_address("192.l168.1.1")); // ожидается 0
    printf("Test 15: %d\n", validate_ip_address("112312312392.123123123123168.11231231231231.1231231231.123123123123123")); // ожидается 0

    return 0;
}

int validate_ip_address(const char *ip_address) {
    char *temp = strdup(ip_address);
    if (contains_multiple_dots(ip_address) || contains_indents(ip_address)) {
        free(temp);
        return 0;
    }
    int dots_count = 0;
    const char *token = strtok(temp, ".");
    while (token != NULL) {
        dots_count++;
        int len = strlen(token);
        if (len == 0) {
            free(temp);
            return 0;
        }
        for (int i = 0; i < len; i++) {
            if (!isdigit(token[i])) {
                free(temp);
                return 0;
            }
        }
        char *endptr;
        long num = strtol(token, &endptr, 10);
        if (endptr != token + len || num < 0 || num > 255) {
            free(temp);
            return 0;
        }
        token = strtok(NULL, ".");
    }
    free(temp);
    if (dots_count != 4) {
        return 0;
    }
    return 1;
}

int contains_multiple_dots(const char *str) {
    size_t len = strlen(str);
    int dot_count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count >= 2) {
                return 1;
            }
        } else {
            dot_count = 0;
        }
    }
    return 0;
}

int contains_indents(const char *str) {
    size_t len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            return 1;
        }
    }
    return 0;
}