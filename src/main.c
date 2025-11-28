#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ATTEMPTS   7
#define MAX_MOVIE_LEN 50
#define MAX_MOVIES    50

// List of movies
// List of 50 popular one-word Bollywood movies (all uppercase)
const char *movies[MAX_MOVIES] = {
    "GUNDAY",
    "KICK",
    "SHOLAY",
    "MOHOBBATEIN",
    "SULTAN",
    "TIGER",
    "WAR",
    "PATHAN",
    "JAWAN",
    "DANGAL",
    "BAAGHI",
    "DRISHYAM",
    "AGNEEPATH",
    "DON",
    "BADSHAH",
    "BAGHBAN",
    "URI",
    "PARMANU",
    "TANHAJI",
    "CHHAAVA",
    "CHICHORE",
    "KEDARNATH",
    "DILWALE",
    "WELCOME",
    "BROTHERS",
    "SINGHAM",
    "KABIR",
    "ABCD",
    "BADLA",
    "GOLMAAL",
    "DHAMAAL",
    "CHEHRE",
    "GAJNI",
    "VIVAH",
    "BHOOTHNATH",
    "GADAR",
    "DEVDAS",
    "STREE",
    "LAXMII",
    "HOUSEFULL",
    "KESARI",
    "BABY",
    "LAGAAN",
    "ROCKSTAR",
    "BARFI",
    "VARANASI",
    "DISHOOM",
    "RAJNEETI",
    "SWADES",
    "HUMGAMA"
};

void print_status(const char *masked_word,int attempts_left,
    const bool guessed_letters[26]) {

    printf("\n=====================================\n");
    printf("          Movie Guessing Game        \n");
    printf("=====================================\n");

    // Show the movie with underscores
    printf("Current Movie: ");
    for (int i = 0; masked_word[i] != '\0'; i++) {
        printf("%c ", masked_word[i]);
    }
    printf("\n");

    // Show attempts
    printf("Attempts left: %d / %d\n", attempts_left, MAX_ATTEMPTS);

    // Show used letters
    printf("Used letters: ");
    int used_any = 0;
    for (int i = 0; i < 26; i++) {
        if (guessed_letters[i]) {
            printf("%c ", 'A' + i);
            used_any = 1;
        }
    }
    if (!used_any) {
        printf("none");
    }
    printf("\n");
}

int main(void) {
    // 1. Choose a random movie
    srand((unsigned int)time(NULL));        // seed random
    int random_index = rand() % MAX_MOVIES; // number from 0 to MAX_MOVIES-1
    const char *secret_movie = movies[random_index];

    int movie_len = (int)strlen(secret_movie);

    // 2. Prepare game state
    char masked_word[MAX_MOVIE_LEN + 1];
    bool guessed_letters[26] = { false };
    int attempts_left = MAX_ATTEMPTS;
    bool game_over = false;

    // Build the masked word: letters -> '_', spaces/hyphens stay
    for (int i = 0; i < movie_len; i++) {
        if (secret_movie[i] == ' ' || secret_movie[i] == '-') {
            masked_word[i] = secret_movie[i];
        } else {
            masked_word[i] = '_';
        }
    }
    masked_word[movie_len] = '\0';

    // 3. Main loop
    while (!game_over) {
        char guess;

        // Show current status
        print_status(masked_word, attempts_left, guessed_letters);

        // Check win
        if (strcmp(masked_word, secret_movie) == 0) {
            printf("\nYou guessed the movie! 🎉\n");
            printf("Movie was: %s\n", secret_movie);
            break;
        }

        // Check loss
        if (attempts_left <= 0) {
            printf("\nNo attempts left. Game Over. ❌\n");
            printf("The movie was: %s\n", secret_movie);
            break;
        }

        // 4. Take input
        printf("\nEnter your guess (A-Z): ");
        if (scanf(" %c", &guess) != 1) {
            // input failed, clear buffer and retry
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            printf("Invalid input, please enter a letter.\n");
            continue;
        }

        // clear extra characters on the same line
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }

        // convert to uppercase
        guess = (char)toupper((unsigned char)guess);

        // validate A-Z
        if (guess < 'A' || guess > 'Z') {
            printf("Please enter a letter between A and Z.\n");
            continue;
        }

        int index = guess - 'A';

        // check if already guessed
        if (guessed_letters[index]) {
            printf("You already guessed '%c'. Try another letter.\n", guess);
            continue;
        }

        // mark as guessed
        guessed_letters[index] = true;

        // 5. Check if guess is in the movie
        bool correct = false;
        for (int i = 0; i < movie_len; i++) {
            if (secret_movie[i] == guess) {
                masked_word[i] = guess;
                correct = true;
            }
        }

        if (correct) {
            printf("Good job! '%c' is in the movie.\n", guess);
        } else {
            attempts_left--;
            printf("Sorry, '%c' is not in the movie.\n", guess);
        }
    }

    return 0;
}
