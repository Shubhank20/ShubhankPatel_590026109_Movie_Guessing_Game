#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#if defined(_WIN32)
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>

    int getch(void) {
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        int ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

#define MAX_ATTEMPTS 7
#define MAX_MOVIE_LEN 50

void print_status(const char *masked_word, int attempts_left, const bool guessed_letters[26]) {

    printf("\n=====================================\n");
    printf("          Movie Guessing Game        \n");
    printf("=====================================\n");

    printf("Current Movie: ");
    for (int i = 0; masked_word[i] != '\0'; i++) {
        printf("%c ", masked_word[i]);
    }
    printf("\n");

    printf("Attempts left: %d / %d\n", attempts_left, MAX_ATTEMPTS);

    printf("Used letters: ");
    bool used_any = false;
    for (int i = 0; i < 26; i++) {
        if (guessed_letters[i]) {
            printf("%c ", 'A' + i);
            used_any = true;
        }
    }
    if (!used_any) {
        printf("none");
    }
    printf("\n");
}

int main(void) {
    char secret_movie[MAX_MOVIE_LEN + 1];

    printf("PLAYER 1, ENTER THE MOVIE NAME (HIDDEN INPUT):\n");

    int pos = 0;
    char ch;


    while (pos < MAX_MOVIE_LEN - 1) {
        ch = getch(); 

        if (ch == '\n' || ch == '\r') 
            break;

        if (ch == 127 || ch == 8) {  
            if (pos > 0) pos--;
            continue;
        }

        secret_movie[pos++] = ch;
    }
    secret_movie[pos] = '\0';


    for (int i = 0; secret_movie[i]; i++) {
        secret_movie[i] = toupper(secret_movie[i]);
    }

    printf("\nMovie saved secretly! Player 2, get ready...\n\n");

    int movie_len = strlen(secret_movie);
    char masked_word[MAX_MOVIE_LEN];
    bool guessed_letters[26] = { false };
    int attempts_left = MAX_ATTEMPTS;


    for (int i = 0; i < movie_len; i++) {
        if (secret_movie[i] == ' ' || secret_movie[i] == '-')
            masked_word[i] = secret_movie[i];
        else
            masked_word[i] = '_';
    }
    masked_word[movie_len] = '\0';

    while (1) {
        print_status(masked_word, attempts_left, guessed_letters);

        if (strcmp(masked_word, secret_movie) == 0) {
            printf("\n🎉 Player 2 guessed the movie!\nMovie was: %s\n", secret_movie);
            break;
        }

        if (attempts_left <= 0) {
            printf("\n❌ No attempts left.\nThe movie was: %s\n", secret_movie);
            break;
        }

        char guess;
        printf("\nEnter your guess (A-Z): ");
        scanf(" %c", &guess);
        while (getchar() != '\n');

        guess = toupper(guess);

        if (guess < 'A' || guess > 'Z') {
            printf("Please enter a valid letter.\n");
            continue;
        }

        int index = guess - 'A';
        if (guessed_letters[index]) {
            printf("Already guessed. Try another.\n");
            continue;
        }

        guessed_letters[index] = true;

        bool correct = false;
        for (int i = 0; i < movie_len; i++) {
            if (secret_movie[i] == guess) {
                masked_word[i] = guess;
                correct = true;
            }
        }

        if (!correct) attempts_left--;
    }

    return 0;
}
