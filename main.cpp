#include <iostream>
#include <string>

using namespace std;

// linked list node to represent a file in the file system
struct File {
    string name;
    File* next; // points to the nezt file

    File(const string& name) : name(name), next(nullptr) {} // constructor
};


class Directory {
public:
    string name;
    File* files; //linked list
    Directory* subdirectories; 
    Directory* next; // points to the next directory

    Directory(const string& name) : name(name), files(nullptr), subdirectories(nullptr), next(nullptr) {}

    // function to add a file to the directory
    // pass in file name as a parameter

    void addFile(const string& filename) {
	// create new file
        File* newFile = new File(filename);
	// if there is no file, then set the new file as the first file
        if (!files) {
            files = newFile;
        } else {
	    // if there alredy is a file, walk through the linked list and then insert the new file at the end
            File* current = files; // pointer to the current file of the linked list
            while (current->next) {
                current = current->next; // move to next node
            }
            current->next = newFile; // insert the new file at the end of the linked list
        }
    }

    // function to add a sub directory	
    void addSubdirectory(const string& dirname) {
	// create a new directory
        Directory* newDir = new Directory(dirname);
	// if there is no zubdirectory, then set the new directory as the first subdirectory
        if (!subdirectories) {
            subdirectories = newDir; 
	// same as add file, if there is already a subdirectory, then walk through the linked list and insert the 		new directory at the end
        } else {
            Directory* current = subdirectories;
            while (current->next) {
                current = current->next;
            }
            current->next = newDir;
        }
    }

    // Function to list contents of the directory
    void printDirectory() const {
        cout << "directory: " << name << endl; // these are just to show the directory name
        cout << "files:" << endl;
        File* filePtr = files;
        while (filePtr) { //while there are files, walk through and print them all
            cout << "- " << filePtr->name << endl;
            filePtr = filePtr->next;
        }
        cout << "subdirectories:" << endl; // same process for subdirectories
        Directory* dirPtr = subdirectories;
        while (dirPtr) {
            cout << "- " << dirPtr->name << endl;
            dirPtr = dirPtr->next;
        }
    }
};

int main() {
    // create a new directory
    Directory* root = new Directory("root");
    // add new subdirectories through calling the addSubdirectory function
    root->addSubdirectory("testdir1");
    root->addSubdirectory("testdir2");

    root->addFile("test1.txt");
    root->addFile("test2.txt");

    root->printDirectory();


    return 0;
}

