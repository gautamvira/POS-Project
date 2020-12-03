#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>

using namespace std;

void createFile() {
	ofstream file;
	ifstream check;
	string fileName;
	cout << "Enter file name to be created: ";
	cin >> fileName;
	int cmp = fileName.compare("\\h");

	if (cmp == 0) {
		cout << "Help: " << endl;
		createFile();
	}
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

void removeFile() {
	string fileName;
	ifstream check;
	cout << "Enter file name to be deleted: ";
	cin >> fileName;
	check.open(fileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	check.close();
	const char * c = fileName.c_str();
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

void renameFile() {
	string oldFileName, newFileName;
	fstream check;
	cout << "Enter old file name: ";
	cin >> oldFileName;
	const char * o = oldFileName.c_str();
	check.open(oldFileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	check.close();
	cout << "Enter new file name: ";
	cin >> newFileName;
	const char * n = newFileName.c_str();


	try {
		if (rename(o, n) != 0)
			cout << "File not renamed." << endl;
		else
			cout << "File renamed." << endl;
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	return;
}

void copyFile() {
	string oldFileName, newFileName, text;
	ifstream oldFile;
	ofstream newFile;
	ifstream check;
	cout << "Enter name of existing file: ";
	cin >> oldFileName;
	check.open(oldFileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	cout << "Enter name of the copied file: ";
	cin >> newFileName;
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

void clearFile() {
	ofstream clear;
	ifstream check;
	string fileName;
	cout << "Enter file name to clear: " << endl;
	cin >> fileName;
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

void moveFile() {
	string oldPath, newPath;
	ifstream check;
	cout << "Enter old path of the file: ";
	cin >> oldPath;
	const char * o = oldPath.c_str();
	check.open(oldPath);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	check.close();
	cout << "Enter new path of the file: ";
	cin >> newPath;

	const char * n = newPath.c_str();

	try {
		if (rename(o, n) != 0)
			cout << "File not moved." << endl;
		else
			cout << "File moved." << endl;
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}
	return;

}

void appendText() {
	ofstream file;
	ifstream check;
	string fileName;
	string text;
	cout << "Enter file name to be appended: ";
	cin >> fileName;
	check.open(fileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	check.close();
	file.open(fileName, ios::app);
	cout << "Enter text to enter: ";
	cin >> text;
	file << text;
	cout << "Text added to the end." << endl;
	return;
}

int main() {
	int ch;
	while (1) {
		cout << "Enter a choice: " << endl;
		cout << "1. Create file\n2. Delete file\n3. Rename file\n4. Copy file\n5. Move file\n6. Clear File\n7. Append text\n";
		cin >> ch;
		switch (ch) {
		case 1:
			createFile();
			break;

		case 2:
			removeFile();
			break;
			
		case 3:
			renameFile();
			break;

		case 4:
			copyFile();
			break;

		case 5:
			moveFile();
			break;

		case 6:
			clearFile();
			break;

		case 7:
			appendText();
				break;

		default:
			cout << "Invalid option." << endl;
			break;
		}
		
	}
	return 0;
}