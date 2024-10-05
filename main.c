#include <stdio.h>
#include <stdlib.h> 
#include <time.h>     
#include <ctype.h>    

#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SYMBOLS "!@#$%^&*()-_=+<>?"

// functions

void generate_password(int length, int upper, int lower, int digits, int symbols);

int main() {
    int length, use_upper, use_lower, use_digits, use_symbols;

    // Ask the user for password length and character types
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    printf("Include uppercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &use_upper);

    printf("Include lowercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &use_lower);

    printf("Include digits? (1 for Yes, 0 for No): ");
    scanf("%d", &use_digits);

    printf("Include symbols? (1 for Yes, 0 for No): ");
    scanf("%d", &use_symbols);

    // Generate the password based on user input
    generate_password(length, use_upper, use_lower, use_digits, use_symbols);

    return 0;
}

void generate_password(int length, int use_upper, int use_lower, int use_digits, int use_symbols) {
    char character_pool[100] = "";        

    // Seed the random number generator with the current time
    srand(time(0));

    // Append characters based on user preferences
    if (use_upper) {
        strcat(character_pool, UPPER);
    }
    if (use_lower) {
        strcat(character_pool, LOWER);
    }
    if (use_digits) {
        strcat(character_pool, DIGITS);
    }
    if (use_symbols) {
        strcat(character_pool, SYMBOLS);
    }

    // Dynamically allocate memory for the password
    char *password = (char *)malloc((length + 1) * sizeof(char));  // +1 for the null-terminator

    if (password == NULL) {
        printf("Memory allocation failed!\n");
        return;  // Exit if memory allocation fails
    }

    // Randomly pick characters from the pool
    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(character_pool);  // Get a random index from the pool
        password[i] = character_pool[index];          // Pick a character from the pool
    }
    password[length] = '\0';  // Null-terminate the string

    // Output the generated password
    printf("Generated Password: %s\n", password);
    free(password);
}