#include <stdio.h> // Standard Input/Output Header
#include <stdlib.h> // Standard Library Header ( rand , srand )
#include <string.h> // String Header (strlen, strcmp)
#include <time.h> // Time Header (time for seeding rand)
#include <ctype.h> // Character Type Header (toupper)
#include <stdbool.h> // Boolean Header (true, false)

// #define - These values do not change during program execution
#define MAX_ATTEMPTS   7 
#define MAX_MOVIE_LEN 50
#define MAX_MOVIES    50


// const char * - pointer to constant character data
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
// const char *masked_word - A string representing the masked movie.Example: "__G_A_"
void print_status(const char *masked_word,int attempts_left,
    const bool guessed_letters[26]) {

    printf("\n=====================================\n");
    printf("          Movie Guessing Game        \n");
    printf("=====================================\n");

    printf("Current Movie: ");
    for (int i = 0; masked_word[i] != '\0'; i++) { // * Stops when it reaches the end of the string ('\0')
        printf("%c ", masked_word[i]);
    }
    printf("\n");

    // Show attempts lefts 
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

int main() {
    srand((unsigned int)time(NULL)); // srand - random no. generator 
    int random_index = rand() % MAX_MOVIES;  // rand() gives a large random number.
                                             //number from 0 to MAX_MOVIES-1
    const char *secret_movie = movies[random_index]; // randomly selected movie

    int movie_len = (int)strlen(secret_movie);// length of the selected movie

    char masked_word[MAX_MOVIE_LEN + 1];// +1 for null terminator
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
    while (!game_over){ // Loop until game_over is true
        char guess;

        print_status(masked_word, attempts_left, guessed_letters); // Show current game status

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
        if (scanf(" %c", &guess) != 1) { // input failed, clear buffer and retry
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { } // clear input buffer
            printf("Invalid input, please enter a letter.\n");
            continue;// go back to start of while loop
        }

        // clear extra characters on the same line
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }

        guess = (char)toupper((unsigned char)guess);// convert to uppercase

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

        guessed_letters[index] = true; // mark this letter as guessed

        // 5. Check if guess is in the movie
        bool correct = false; 
        // If found → reveal the letter
        // If not → reduce attempts
        for (int i = 0; i < movie_len; i++) {
            if (secret_movie[i] == guess) {
                masked_word[i] = guess;
                correct = true;
            }
        }

        if (correct) { // guess was correct
            printf("Good job! '%c' is in the movie.\n", guess);
        } else { // guess was incorrect
            attempts_left--;
            printf("Sorry, '%c' is not in the movie.\n", guess);
        }
    }

    return 0;
}
