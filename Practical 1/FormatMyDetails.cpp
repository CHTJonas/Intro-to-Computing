#include <iostream>

#include "textStrings.cpp"
#include "functions.cpp"
#include "exceptions.cpp"
#include "contactImporter.cpp"
#include "contactExporter.cpp"

#define PROGRAM_NAME "FormatMyDetails"
#define PROGRAM_VERSION "2"
#define REVISION_DATE "20161020"

using namespace std;

int main() {
    // print the program metadata
    print(PROGRAM_NAME);
    print("Version: " + string(PROGRAM_VERSION));
    print("Last revised " + string(REVISION_DATE));
    print();

    // ask the user where the spreadsheet is and crunch datastructures
    print(READPATH_ENTRY_MESSAGE);
    contactImporter importer(read());

    print();

    // print out the data to the user
	importer.iread();

    print();

    // ask user if there is a header row
    bool omitFirst;
    string input;
    while (input.compare("yes") != 0 && input.compare("no") != 0) {
        print(OMIT_FIRSTROW_MESSAGE);
        input = read();
    }
    if (input.compare("yes") == 0) {
        omitFirst = true;
    }
    if (input.compare("no") == 0) {
        omitFirst = false;
    }

    // establish which columns have the stuff in
	print(NAMES_ENTRY_MESSAGE);
	int namesCol = stoi(read());
    print(CRSID_ENTRY_MESSAGE);
	int crsidCol = stoi(read());
    print(MOBILE_ENTRY_MESSAGE);
	int mobileCol = stoi(read());

    // initialise arrays
	vector<string> fullNames = importer.getColumn(namesCol, omitFirst);
	vector<string> crsids = importer.getColumn(crsidCol, omitFirst);
	vector<string> mobileNumbers = importer.getColumn(mobileCol, omitFirst);
	vector<string> firstNames;
	vector<string> lastNames;
	for (int i = 0 ; i < fullNames.size() ; i++) {
        vector<string> splitPart = split(fullNames[i], ' ');
        firstNames.push_back(splitPart[0]);
        // exclude any middle names, so just take the last word
        lastNames.push_back(splitPart[splitPart.size() - 1]);
	}
	vector<string> emails;
	for (int i = 0 ; i < crsids.size() ; i++) {
        string emailAddress = crsids[i];
        emailAddress.append("@cam.ac.uk");
        emails.push_back(emailAddress);
	}

    print();

    // ask user where to save data and crunch datastructures
    print(SAVEPATH_ENTRY_MESSAGE);
    contactExporter exporter(read(), firstNames, lastNames, mobileNumbers, crsids, emails);

    print();

    // actually save the data
	exporter.write();

    // exit successfully
    return 0;
}