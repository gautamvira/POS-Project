#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile() {
	ofstream file;
	string fileName;
	cout << "Enter file name to be created: ";
	cin >> fileName;
	int cmp = fileName.compare("\\h");
	cout << cmp << fileName << endl;

	if (cmp == 0) {
		cout << "Help: " << endl;
		createFile();
	}
	fileName += ".txt";
	file.open(fileName);
	if (!file) {
		cout << "File could not be created." << endl;
		return;
	}
	file.close();
	return;
}

void removeFile() {
	string fileName;
	cout << "Enter file name to be created: ";
	cin >> fileName;
	const char * c = fileName.c_str();
	if (remove(c) != 0) {
		cout << "File not deleted." << endl;	
		return;
	}
	else {
		cout << "File deleted successfully." << endl;
			return;
	}
}

int main() {
	int ch;
	while (1) {
		cout << "Enter a choice: ";
		cin >> ch;
		switch (ch) {
		case 1:
			createFile();
			break;

		case 2:
			removeFile();
			break;

		default:
			cout << "Invalid option." << endl;
		}
		
	}
	return 0;
}