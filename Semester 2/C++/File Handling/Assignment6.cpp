#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the source file for reading
    ifstream sourceFile("source.txt");
    if (!sourceFile) {
        cerr << "Error opening source file." << endl;
        return 1;
    }

    // Open the destination file for writing
    ofstream destFile("destination.txt");
    if (!destFile) {
        cerr << "Error opening destination file." << endl;
        return 1;
    }

    // Read from the source file and write to the destination file
    string line;
    while (getline(sourceFile, line)) {
        destFile << line << endl;
    }

    // Close the files
    sourceFile.close();
    destFile.close();

    cout << "File copy completed." << endl;
    return 0;
}
