#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <filesystem>

using namespace std;

void createFile(char para[]) {
	ofstream file;
	ifstream check;
	string fileName;
	fileName = para;
	
	check.open(fileName);
	if (check.is_open()) {
		cout << "File already exists." << endl;
		return;
	}
	fileName;
	try {
		file.open(fileName);
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	cout << "File Created." << endl;
	file.close();
	return;
}

void removeFile(char para[]) {
	string fileName;
	ifstream check;
	fileName = para;
	check.open(fileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	check.close();
	const char* c = fileName.c_str();
	try {
		remove(c);
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	cout << "File deleted." << endl;
	return;
}

void renameFile(char para[], char para1[]) {
	int  result;
	/* Attempt to rename file: */
	result = rename(para, para1);
	if (result != 0)
		printf("Could not rename '%s'\n", para);
	else
		printf("File '%s' renamed to '%s'\n", para, para1);
}

void copyFile(char para[], char para1[]) {
	string oldFileName, newFileName, text;
	ifstream oldFile;
	ofstream newFile;
	ifstream check;
	oldFileName = para;
	newFileName = para1;
	check.open(oldFileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	const char * o = oldFileName.c_str();
	const char * n = newFileName.c_str();
	oldFile.open(o);
	newFile.open(n);
	try {
		while (getline(oldFile, text))
			newFile << text << endl;
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	cout << "File copied." << endl;
	return;
}

void moveFile(char para[], char para1[]) {
	string oldPath, newPath;
	oldPath = para;
	newPath = para1;
	const char * o = oldPath.c_str();
	const char * n = newPath.c_str();

	try {
		rename(o, n);
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}

	cout << "File moved." << endl;
	return;

}
void appendText(char para[], char para1[]) {
	ofstream file;
	ifstream check;
	string fileName;
	string text;
	fileName = para;
	text = para1;
	check.open(fileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	check.close();
	file.open(fileName, ios::app);
	file << text;
	cout << "Text added to the end." << endl;
	return;
}

void clearFile(char para[]) {
	ofstream clear;
	ifstream check;
	string fileName;
	fileName = para;
	check.open(fileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	check.close();
	clear.open(fileName);
	if (clear.is_open())
		cout << "File cleared." << endl;
	else
		cout << "File not cleared." << endl;
	return;
}
int main() {
	
	while (1) {
		char input[256];
		char para[256];
		char para1[256];
		cout << "pofm> ";
		cin.getline(input, 256);
		if (!strcmp(input, "exit")) {
			break;
		}
		char cmd[10];
		bool cm = 1, pa = 0,pa1 = 0, end = 0;
		
		for (int i = 0, j = 0, k = 0; end != 1; i++) {
			if (cm == 1) {

				cmd[i] = input[i];

				if (input[i + 1] == ' ') {
					cmd[i + 1] = '\0';
					i += 2;
					cm = 0;
					pa = 1;
				}
			}
			if (pa == 1) {

				para[j] = input[i];

				if (input[i + 1] == ' ') {
					para[j + 1] = '\0';
					i += 2;
					pa = 0;
					pa1 = 1;
				}
				else if (input[i + 1] == '\0') {
					para[j + 1] = '\0';
					break;
				}
				j++;
			}
			if (pa1 == 1) {

				para1[k] = input[i];

				if (input[i + 1] == '\0') {
					para1[k + 1] = '\0';
					cm = 0;
					pa1 = 0;
					end = 1;
					break;
				}
				k++;
			}
		}

		if (!strcmp(cmd, "mkdir\0")) {
			createFile(para);
		}
		else if (!strcmp(cmd, "rm\0")) {
			removeFile(para);
		}
		else if (!strcmp(cmd, "rename\0")) {
			renameFile(para,para1);
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
	}
}