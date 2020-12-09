#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <filesystem>
#include <sstream>

using namespace std;

void createFile(char para[]) {																	// function to create a file
	ofstream file;
	ifstream check;
	string fileName;
	fileName = para;
	if (!strcmp(para, "/h")) {																	// if "/h" help command used
		cout << "mkdir: Its use to create a file\nUsage: mkdir Filename " << endl;
		return;
	}
	else if (!strcmp(para, "\0")) {																// if file name empty
		cout << "Invalid directory." << endl;
		return;																					// display error and return
	}
	check.open(fileName);
	if (check.is_open()) {																		// check if file already exists
		cout << "File already exists." << endl;
		return;																					// display error and return
	}

	try {
		file.open(fileName);																	// try creating file
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	cout << "File Created." << endl;
	file.close();
	return;																						// return after creating file
}

void removeFile(char para[]) {																	// function to delete a file
	string fileName;
	ifstream check;
	fileName = para;
	if (!strcmp(para, "/h")) {																	// if "/h" help command used
		cout << "rm: Its use to remove/delete a file\nUsage: rm Filename " << endl;
		return;
	}
	else if (!strcmp(para, "\0")) {																// if file name empty
		cout << "Invalid directory." << endl;
		return;																					// display error and return
	}
	check.open(fileName);																		// check if file does not exist
	if (!check.is_open()) {
		cout << "File does not exist." << endl;													// display error and return
		return;
	}
	check.close();
	const char* c = fileName.c_str();															// convert string to constant char *
	try {
		remove(c);																				// try deleting file
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	cout << "File deleted." << endl;
	return;																						// return if file deleted successfully
}

void renameFile(char para[], char para1[]) {																// function to rename file
	if (!strcmp(para, "/h")) {
		cout << "rename: It's used to rename a file\nUsage: rename oldFilename newFilename " << endl;		// if "/h" help command used
		return;
	}
	else if (!strcmp(para1, "\0") || !strcmp(para, "\0")) {													// if old or new file name is empty
		cout << "Invalid directory." << endl;
		return;																					// display error and return
	}
	int  result;

	result = rename(para, para1);																// attempt to rename file
	if (result != 0)
		printf("Could not rename '%s'\n", para);												// if could not rename file
	else
		printf("File '%s' renamed to '%s'\n", para, para1);										// if file renamed
}

void copyFile(char para[], char para1[]) {																	// function to make a copy of a file
	if (!strcmp(para, "/h")) {																				// if "/h" help command used
		cout << "copy: It's used to copy a file\nUsage: copy orignalFileName copyFileName " << endl;
		return;
	}
	else if (!strcmp(para1, "\0") || !strcmp(para, "\0")) {										// if old or new file name is empty
		cout << "Invalid directory." << endl;
		return;																					// display error and return
	}
	string oldFileName, newFileName, text;
	ifstream oldFile;
	ofstream newFile;
	ifstream check;
	oldFileName = para;
	newFileName = para1;
	check.open(oldFileName);																	// check if file exists
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;																					// display error and return if file does not exist
	}
	check.close();
	const char* o = oldFileName.c_str();														// convert string to constant char *
	const char* n = newFileName.c_str();
	oldFile.open(o);																			// open old file to read
	newFile.open(n);																			// open new file to write
	try {
		while (getline(oldFile, text))															// reading from new file
			newFile << text << endl;															// writing to copy file
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	cout << "File copied." << endl;
	return;
}

void moveFile(char para[], char para1[]) {														// function to move file from one directory to another
	ifstream check;
	if (!strcmp(para, "/h")) {																					// if "/h" help command used
		cout << "move: It's used to move a file\nUsage: move oldpath//filename newpath//filename " << endl;
		return;
	}

	string oldPath, newPath;
	oldPath = para;
	newPath = para1;
	if (newPath.empty()) {																		// if new path parameter empty
		cout << "Invalid directory." << endl;
		return;																					// display error and return
	}
	check.open(oldPath);
	if (!check.is_open()) {																		// check if old path parameter is correct
		cout << "Invalid Directory." << endl;
		return;																					// display error and return if not
	}
	check.close();
	const char* o = oldPath.c_str();															// convert string to constant char *
	const char* n = newPath.c_str();

	try {
		rename(o, n);																			// attempting to move file
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}

	cout << "File moved." << endl;
	return;																						// return after successfully moved

}
void appendText(char para[], char para1[]) {													// function to append text to a file
	if (!strcmp(para, "/h")) {																	// if help command is used
		cout << "txtapp: It's used to append a textfile\nUsage: textapp Filename \"text\" " << endl;
		return;
	}
	ofstream file;
	ifstream check;
	string fileName;
	string text;
	fileName = para;
	text = para1;
	check.open(fileName);																		// check if file exists
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;																					// display error and return if does not
	}
	check.close();
	file.open(fileName, ios::app);																// open file to write in append mode
	file << text;
	cout << "Text added to the end." << endl;													// write text to the file and return
	return;
}
void showFile(char para[],char para1[]) {																	// function to show contents of a file
	int count = 4;                                                                              //to count lines
	int pos = 0;
	stringstream position(para1);																// converting char position to int
	position >> pos;
	if (!strcmp(para, "/h")) {																	// if help command is used
		cout << "txtshow: It's used to show contents of a txt file\nUsage: txtshow Filename " << endl;
		return;
	}
	string oldFileName, newFileName, text;
	ifstream oldFile;
	ifstream check;
	oldFileName = para;
	check.open(oldFileName);
	if (!check.is_open()) {																		// check if file exists
		cout << "File does not exist." << endl;
		return;																					// display error and return if does not exist
	}

	try {	
		
												                                                 // print line by line
		cout << "Press Enter to Contiue:: \n";
		for (int i = 3; (getline(check, text)); i++) {                                          //for each line
		if (i % pos == 0) {
			_getch();
		}
		cout << text<<endl;                                                                      //show text
	}
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;													// display error and return if any exception
		return;
	}
	
	return;
}


void clearFile(char para[]) {																	// function to clear contents of a file
	if (!strcmp(para, "/h")) {																	// if help command is used
		cout << "txtclr: It's used to clear contents of a txt file\nUsage: txtclr Filename " << endl;
		return;
	}
	ofstream clear;
	ifstream check;
	string fileName;
	fileName = para;
	check.open(fileName);
	if (!check.is_open()) {																		// check if file does not exist
		cout << "File does not exist." << endl;													// display error and return
		return;
	}
	check.close();
	clear.open(fileName);																		// open file to clear
	if (clear.is_open())
		cout << "File cleared." << endl;														// if cleared
	else
		cout << "File not cleared." << endl;
	return;
}

void insertText(char para[], char para1[]) {													// function to insert text at a specific position in file
	if (!strcmp(para, "/h")) {																	// if help command is used
		cout << "txtinsert: It's used to insert text at a specific position in a txt file\nUsage: txtinsert Filename position" << endl;
		cout << "\tFileName> 'input text'" << endl;
		return;
	}
	string text, data, read;
	int pos;
	ifstream check;
	ofstream add;
	string fileName;
	fileName = para;
	check.open(fileName);																		// open file to read
	if (!check.is_open()) {																		// check if file exists
		cout << "File does not exist." << endl;													//display error and return if does not exist
		return;
	}
	while (getline(check, read)) {																// read from file line by line
		read += '\n';
		data += read;																			// store file contents in a string
	}
	check.close();
	add.open(fileName);																			// open file to write
	cout << "pofm> " << para << "> ";
	getline(cin, text);																			// user input for text to be added
	stringstream position(para1);																// converting char position to int
	position >> pos;
	data.insert(pos, text);																		// inserting text into the position
	if (!add.is_open()) {
		cout << "Error." << endl;
		return;																					// if file not open, display error and return
	}
	add << data;																				// writing modified string to the file
	cout << "Text inserted." << endl;
	return;
}

int main() {
	while (1) {
		char input[256];
		char para[256];
		char para1[256];
		cout << "pofm> ";
		cin.getline(input, 255);																// get user input
		if (!strcmp(input, "exit")) {															// if input is 'exit'
			break;
		}
		char cmd[10];
		bool cm = 1, pa = 0, pa1 = 0, end = 0;													// initializing variables

		for (int i = 0, j = 0, k = 0; end != 1; i++) {
			if (cm == 1) {																		// if command entered

				cmd[i] = input[i];

				if (input[i + 1] == ' ') {														// if command over
					cmd[i + 1] = '\0';
					i += 2;
					cm = 0;
					pa = 1;
				}
				else if (input[i + 1] == '\0') {												// if only command entered
					strcpy_s(para, "/h");														// default parameter for command is help
					cmd[i + 1] = '\0';
					break;
				}
			}
			if (pa == 1) {																		// if parameter entered

				para[j] = input[i];

				if (input[i + 1] == ' ') {														// if parameter over
					para[j + 1] = '\0';
					i += 2;
					pa = 0;
					pa1 = 1;
				}
				else if (input[i + 1] == '\0') {												// if only one parameter entered
					para[j + 1] = '\0';
					break;
				}
				j++;
			}
			if (pa1 == 1) {																		// if second parameter entered

				para1[k] = input[i];

				if (input[i + 1] == '\0') {														// second parameter over
					para1[k + 1] = '\0';
					cm = 0;
					pa1 = 0;
					end = 1;
					break;
				}
				k++;
			}
		}

		if (!strcmp(cmd, "mkdir\0")) {															// if else to identify which cmd was entered
			createFile(para);
		}
		else if (!strcmp(cmd, "rm\0")) {
			removeFile(para);
		}
		else if (!strcmp(cmd, "rename\0")) {
			renameFile(para, para1);
		}
		else if (!strcmp(cmd, "copy\0")) {
			copyFile(para, para1);
		}
		else if (!strcmp(cmd, "move\0")) {
			moveFile(para, para1);
		}
		else if (!strcmp(cmd, "txtapp\0")) {
			appendText(para, para1);
		}
		else if (!strcmp(cmd, "txtclr\0")) {
			clearFile(para);
		}
		else if (!strcmp(cmd, "txtshow\0")) {
			showFile(para, para1);
		}
		else if (!strcmp(cmd, "txtinsert\0")) {
			insertText(para, para1);
		}
		else {																					// if incorrect command was entered
			cout << "Invalid command." << endl;
		}
	}
}