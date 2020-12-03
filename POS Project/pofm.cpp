#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

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
	cout << "Enter file name to be created: ";
	cin >> fileName;
	check.open(fileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
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
	ifstream check;
	cout << "Enter old file name: ";
	cin >> oldFileName;
	check.open(oldFileName);
	if (!check.is_open()) {
		cout << "File does not exist." << endl;
		return;
	}
	cout << "Enter new file name: ";
	cin >> newFileName;

	const char * o = oldFileName.c_str();
	const char * n = newFileName.c_str();

	try {
		rename(o, n);
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return;
	}

	cout << "File renamed." << endl;
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

void moveFile() {
	string oldPath, newPath;
	cout << "Enter old path of the file: ";
	cin >> oldPath;
	cout << "Enter new path of the file: ";
	cin >> newPath;

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

int main() {
	int ch;
	while (1) {
		cout << "Enter a choice: " << endl;
		cout << "1. Create file\n2. Delete file\n3. Rename file\n4. Copy file\n5. Move file\n";
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

		default:
			cout << "Invalid option." << endl;
			break;
		}
		
	}
	return 0;
}