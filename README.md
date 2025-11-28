🎬 Movie Guessing Game (C Project)

Description

This project is a terminal-based guessing game written in C.
Features include:
Random movie selection from a list of 50 Bollywood movie titles
Automatic masking of movie names
Validation of alphabet input
Display of:
Attempts left
Used letters
Current masked movie state
Win/Lose result message

Repository Structure

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
│   └── Output_3.png
│
├── sample_outputs/
│   ├── input1.txt
│   ├── input2.txt
│   ├── input3.txt
|   ├── input4.txt
|   ├── input5.txt
|   ├── input6.txt
|   └── input7.txt
└── README.md

Getting Started

A C compiler (GCC recommended)
Any text editor (VS Code, Notepad++, etc.)

Build Instruction

Clone or download the repository
Navigate to the source directory
Compile the program
Run the program

 Usage

Run the game executable
The game will randomly select a Bollywood movie
You will see:
A masked version of the movie (_ _ _ _)
Number of attempts left
Used letters
Enter letters (A–Z) to guess
The program will:
Reveal letters if your guess is correct
Deduct attempts if wrong
Game ends when:
You guess the full movie 🎉
Attempts reach zero 
