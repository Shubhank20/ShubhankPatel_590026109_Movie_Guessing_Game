#ifndef MOVIE_GAME_H
#define MOVIE_GAME_H

#define MAX_ATTEMPTS   7
#define MAX_MOVIE_LEN  50
#define MAX_MOVIES     10

extern const char *movies[MAX_MOVIES];

void print_status(const char *masked_word,
                  int attempts_left,
                  const bool guessed_letters[26]);

#endif