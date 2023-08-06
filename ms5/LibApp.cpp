// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: Aug 6, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;
namespace sdds {

    bool LibApp::confirm(const char* message) {
        bool result = false;
        Menu menu(message);
        menu << "Yes";

        int returnValue = menu.run();
        if (returnValue == 1) {
            result = true;
        }
        return result;
    }

    //simple private functions:
    void LibApp::load() {
        cout << "Loading Data" << endl;
        //open data file for reading
        ifstream file(m_fileName);

        char type{};
        int i;
        for (i = 0; file && i < SDDS_LIBRARY_CAPACITY; i++) {
            //read a single char for type of pub
            file >> type;
            file.ignore();

            //dynamically instantiating based on type
            if (file) {
                if (type == 'P') m_PPA[i] = new Publication;
                else if (type == 'B') m_PPA[i] = new Book;

                //extract object from file stream
                if (m_PPA[i]) {
                    file >> *m_PPA[i];
                    //adding one to the NOLP
                    m_NOLP++;
                    //set LLRN to ref# of last pub read
                    m_LLRN = m_PPA[i]->getRef();
                }
            }
        }
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
        //open data file for overwriting
        ofstream file(m_fileName);
        int i;
        for (i = 0; i < m_NOLP; i++) {
            if (m_PPA[i]->getRef() != 0) {
                //go through elements of PPA up to NOLP
                //insert all elements into ofstream, except those with 0
                file << *m_PPA[i] << endl;
            }
        }
        file.close();
    }

    int LibApp::search(int searchType) {
        cout << "Searching for publication" << endl;
        char title[256]{};
        int selectedType = 0, i = 0, libRef = 0;
        char typeChar;
        //instance for collecting search matches and user selection
        PublicationSelector pubSelect("Select one of the following found matches:", 15);

        selectedType = m_publicationTypeMenu.run();
        if (selectedType == 1) {
            typeChar = 'B';
        }
        else if (selectedType == 2) {
            typeChar = 'P';
        }
        cin.ignore(1000, '\n');
        //print title up to 256 characters
        cout << "Publication Title: ";
        cin.getline(title, 256);

        for (i = 0; i < m_NOLP; i++) {
            //check if title, type, and ref num match criteria
            bool titleMatch = m_PPA[i]->operator==(title);
            bool typeMatch = (typeChar == m_PPA[i]->type());
            bool refNumMatch = (m_PPA[i]->getRef() != 0);

            if (searchType == 1 && titleMatch && typeMatch && refNumMatch) {
                pubSelect << m_PPA[i];
            } else if (searchType == 2 && titleMatch && m_PPA[i]->onLoan() && typeMatch && refNumMatch) {
                pubSelect << m_PPA[i];
            } else if (searchType == 3 && titleMatch && !m_PPA[i]->onLoan() && typeMatch && refNumMatch) {
                pubSelect << m_PPA[i];
            }
        }

        //if matches are found, sort the result and get the user's selection and return LibRef
        if (pubSelect) {
            pubSelect.sort();
            libRef = pubSelect.run();
            if (libRef > 0) {
                cout << *getPub(libRef) << endl;
            }
            else {
                cout << "Aborted!" << endl;
            }
        }
        else {
            cout << "No marches found!" << endl;
        }
        return libRef;
    }

    void LibApp::returnPub() {
        bool abort = false;
        cout << "Return publication to the library" << endl;
        int libRef = search(2);
        if (!(libRef > 0)) abort = true;

        if (!abort) {
            bool confirmed = confirm("Return Publication?");

            if (confirmed) {
                int daysLoaned = Date() - getPub(libRef)->checkoutDate();
                
                if (daysLoaned > SDDS_MAX_LOAN_DAYS) {
                    int penaltyCents = (daysLoaned - SDDS_MAX_LOAN_DAYS) * 50;
                    int penaltyDollars = penaltyCents / 100;
                    int penaltyCentsRemainder = penaltyCents % 100;

                    cout << "Please pay $";
                    cout.width(2);
                    cout.fill('0');
                    cout << penaltyDollars << '.';
                    cout.width(2);
                    cout << penaltyCentsRemainder;
                    cout.fill(' ');
                    cout << " penalty for being " << (daysLoaned - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
            }

                getPub(libRef)->set(0);
                m_changed = true;
            }

            cout << "Publication returned" << endl;
        }
        cout << endl;
    }

//methods with confirmation:

    void LibApp::newPublication() {
        bool abort = false;
        if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
            abort = true;
        }

        if (!abort) {
            cout << "Adding new publication to the library" << endl;
            int pubType = m_publicationTypeMenu.run();
            cin.ignore(1000, '\n');
            Publication* p = nullptr;
            if (pubType == 0) {
                cout << "Aborted!" << endl;
                abort = true;
            }
            else if (pubType == 1) {
                p = new Book;
                cin >> *p;
            }
            else if (pubType == 2) {
                p = new Publication;
                cin >> *p;
            }

            while (cin.fail()) {
                cin.ignore(1000,'\n');
                cin.clear();
                cout << "Aborted!" << endl;
                cin >> *p;
            }
            
            if (!abort && confirm("Add this publication to the library?")) {
                if (!*p) {
                    cout << "Failed to add publication!" << endl;
                    delete p;
                }
                else {
                    m_LLRN++;
                    p->setRef(m_LLRN);
                    m_PPA[m_NOLP] = p;
                    m_NOLP++;
                    m_changed = true;

                    cout << "Publication added" << endl;
                }
            }
        }
        cout << endl;
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        int libRef = search(1);
        if (libRef && confirm("Remove this publication from the library?")) {
            m_PPA[libRef-1]->setRef(0);
            m_changed = true;
            cout << "Publication removed" << endl;
        }
        cout << endl;
    }

    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;
        int libRef = search(3);

        if (libRef > 0) {
            bool confirmed = confirm("Check out publication?");

            if (confirmed) {
                int inputMembership;
                bool validInput = false;
                while (!validInput) {
                    cout << "Enter Membership number: ";

                    if (!(cin >> inputMembership) || inputMembership < 10000 || inputMembership > 99999) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid membership number, try again: ";
                    } else {
                        cin.ignore(1000, '\n');
                        validInput = true;
                    }
                }

                getPub(libRef)->set(inputMembership);
                m_changed = true;
                cout << "Publication checked out" << endl;
            }
        }
        cout << endl;
    }

//constructor
    LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_changed = false;

        //populating mainMenu + exitMenu with 'operator<<'
        m_mainMenu 
            << "Add New Publication" 
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";

        m_exitMenu 
            << "Save changes and exit"
            << "Cancel and go back to the main menu";

        load();
    }

    LibApp::LibApp(const char* filename) : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_publicationTypeMenu("Choose the type of publication:") {
            if (filename) {
                strcpy(m_fileName, filename);
            }
            m_changed = false;
            m_NOLP = 0;
            m_mainMenu << "Add New Publication"
                       << "Remove Publication"
                       << "Checkout publication from library"
                       << "Return publication to library";
            m_exitMenu << "Save changes and exit"
                       << "Cancel and go back to the main menu";
            m_publicationTypeMenu << "Book"
                                  << "Publication";
            load();
        }

    LibApp::~LibApp() {
        for (int i = 0; i < m_NOLP; i++) {
            delete m_PPA[i];
        }
    }

    void LibApp::run() {
        int inputMenu, inputExit;
        //start of do-while loop
        do {
            //Menu::run() function used here
            inputMenu = m_mainMenu.run();
            switch (inputMenu)
            {
            case 0:
                if (m_changed == true)
                {
                    inputExit = m_exitMenu.run();
                    switch (inputExit)
                    {
                    case 0:
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            m_changed = false;
                        }
                    break;

                    case 1:
                        save();
                    break;
                    
                    case 2:
                        inputMenu = 1;
                    break;
                    }
                }
                cout << endl;
            break;

            case 1:
                newPublication();
            break;
            
            case 2:
                removePublication();
            break;
            
            case 3:
                checkOutPub();
            break;
            
            case 4:
                returnPub();
            break;
            }
        } while (inputMenu != 0);

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

    Publication* LibApp::getPub(int libRef) {
        Publication* result = nullptr;
        for (int i = 0; i < m_NOLP; i++) {
            if(m_PPA[i]->getRef() == libRef) {
                result = m_PPA[i];
            }
        }
        return result;
    }

}