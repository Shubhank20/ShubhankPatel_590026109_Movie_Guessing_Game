#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void print_status(const char *masked_word, int attempts_left, const bool guessed_letters[26]);
void initializeMaskedWord(char *masked_word, const char *secret_movie, int movie_len);
char getValidatedInput();
bool updateMaskedWord(char *masked_word, const char *secret_movie, char guess, int movie_len);
const char* selectRandomMovie();

#endif