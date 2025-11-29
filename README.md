# Movie Guessing Game (C Project)

#Description

1.This project is a terminal-based guessing game written in C.
2.Features include:
3.Random movie selection from a list of 50 Bollywood movie titles
4.Automatic masking of movie names
5.Validation of alphabet input
6.Display of:
7.Attempts left
8.Used letters
9.Current masked movie state
10.Win/Lose result message

#Repository Structure
'''
movie-guessing-game/
│
├── src/
│   └── main.c
│
├── include/
│   ├── game_utils.h
│   └── display_utils.h
│
├── docs/
│   ├── Algorithm.txt
│   ├── Flowchart.txt
│   └── ProjectReport.pdf
│
├── assets/
│   ├── Flowchart.png
│   ├── Output_1.png
│   ├── Output_2.png
│   ├── Output_3.png
│   ├── Output_4.png
│   └── Output_5.png
|
├── sample_outputs/
│   ├── input1.txt
│   ├── input2.txt
│   ├── input3.txt
|   ├── input4.txt
|   ├── input5.txt
|   ├── input6.txt
|   └── input7.txt
└── README.md
'''
# Getting Started

1. A C compiler (GCC recommended)
2. Any text editor (VS Code, Notepad++, etc.)

# Build Instruction

1.Clone or download the repository
2.Navigate to the source directory
3.Compile the program
4.Run the program

# Usage

1.Run the game executable
2.The game will randomly select a Bollywood movie
3.You will see:
4.A masked version of the movie (_ _ _ _)
5.Number of attempts left
6.Used letters
7.Enter letters (A–Z) to guess
8.The program will:
9.Reveal letters if your guess is correct
10.Deduct attempts if wrong
11.Game ends when:
12.You guess the full movie 🎉
13.Attempts reach zero
