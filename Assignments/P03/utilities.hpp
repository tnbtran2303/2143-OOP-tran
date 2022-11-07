#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;

string Black = "0";
string Red = "1";
string Green = "2";
string Yellow = "3";
string Blue = "4";
string Purple = "5";
string Cyan = "6";
string White = "7";
string Default = "9";

void printColor(string out, int fg, int bg = 9) {
	cout << "\033[0;3" << fg << ";4" << bg << "m" << out << "\033[0;39;49m";
}

void gotoXY(int row, int col) {
	cout << "\033[" << row << ";" << col << "H";
}

struct winsize w;
struct WindowSize {
	int rows;
	int cols;

	/**
	 * Uses some built in libraries to get a terminal window size.
	 *      stdio.h, sys/ioctl.h, unistd.h
	 */
	WindowSize() {
		// magic happens here
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

		// place values in more readable
		// vars here ...
		rows = w.ws_row;
		cols = w.ws_col;
	}

	/**
	 * Guess
	 */
	int termWidth() {
		return cols;
	}

	/**
	 * Guess
	 */
	int termHeight() {
		return rows;
	}

	/**
	 * Random int between 0 and width of terminal window
	 */
	int randCol() {
		return rand() % cols;
	}

	/**
	 * Random int between 0 and height of terminal window
	 */
	int randRow() {
		return rand() % rows;
	}
};