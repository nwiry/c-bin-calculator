#include <stdio.h>
#include <stdbool.h>

void sum(char, char);
void mult(char, char);

int main(int argc, char const *argv[])
{
    printf("Welcome to BIN 8 Bits Calculator.\n\n");

MENU_CALCULATOR:
    printf("Select the valid math operator to get a result:\n");
    printf("1 - Addition\n");
    printf("2 - Multiplication\n\n");

    char o;

    char n1[9], n2[9];
    bool getOK = false;
    scanf("%s", &o);

SET_OPERATION:
    switch (o)
    {
    case '1':
        if (!getOK)
            goto GET_NUMBERS;
        sum(n1, n2);
        break;
    case '2':
        if (!getOK)
            goto GET_NUMBERS;
        mult(n1, n2);
        break;

    default:
        printf("Invalid operation! Please, ");
        goto MENU_CALCULATOR;
        break;
    }

    return 0;

GET_NUMBERS:
    printf("Enter the first binary number: ");
    scanf("%s", &n1);
GET_SECONDARY_NUMBER:
    printf("\nEnter the second binary number: ");
    scanf("%s", &n2);

    if (!valid_binary(n1))
    {
        printf("Invalid binary number! Please, ");
        goto GET_NUMBERS;
    }
    if (!valid_binary(n2))
    {
        printf("Invalid binary number! Please, ");
        goto GET_SECONDARY_NUMBER;
    }

    getOK = true;

    goto SET_OPERATION;
}

void sum(char n1, char n2)
{
}

void mult(char n1, char n2)
{
}

int parse_num(char n)
{
}

bool valid_binary(char n[])
{
    int i;
    size_t size = sizeof(n);
    for (i = 0; i < size; i++)
        if (n[i] != "-" && n != "1" && n != "0")
            return false;

    return true;
}

bool is_valid_int(const char *str)
{
    // Handle negative numbers.
    //
    if (*str == '-')
        ++str;

    // Handle empty string or just "-".
    //
    if (!*str)
        return false;

    // Check for non-digit chars in the rest of the stirng.
    //
    while (*str)
    {
        if (!isdigit(*str))
            return false;
        else
            ++str;
    }

    return true;
}