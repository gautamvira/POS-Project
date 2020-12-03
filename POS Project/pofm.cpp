#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile() {
	fstream file;
	string fileName;
	cout << "Enter file name to be created: ";
	getline(cin, fileName);
	int cmp = fileName.compare("\h");
	if (cmp == 0) {
		cout << "Help: " << endl;
		createFile();
	}
	file.open(fileName + ".txt");
	if (!file) {
		cout << "File could not be created." << endl;
		return;
	}
	return;
}

void removeFile() {
	string fileName;
	cout << "Enter file name to be created: ";
	getline(cin, fileName);
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
	createFile();
	removeFile();

	return 0;

}