// In Tae Chung
// itchung@myseneca.ca
// 128 958 220
// Finish Date: July 21, 2023 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "LibApp.h"

using namespace std;
namespace sdds {

    bool LibApp::confirm(const char* message) {
        bool result = false;
        Menu menu(message);
        menu << "Yes";

        int returnValue = menu.run(cin);
        if (returnValue == 1) {
            result = true;
        }
        return result;
    }

    //simple private functions:
    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl << endl;
        m_changed = true;
    }

    //methods with confirmation:
    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        bool confirmed = confirm("Add this publication to library?");
        if (confirmed) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
        cout << endl;
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        bool confirmed = confirm("Remove this publication from the library?");
        if (confirmed) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
        cout << endl;
    }

    void LibApp::checkOutPub() {
        search();
        bool confirmed = confirm("Check out publication");
        if (confirmed) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        cout << endl;
    }

    //constructor
    LibApp::LibApp() : m_mainMenu(""), m_exitMenu("Changes have been made to the data, what would you like to do?") {
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

    void LibApp::run()
    {
        int inputMenu, inputExit;

        do
        {
            inputMenu = m_mainMenu.run(cin);
            switch (inputMenu)
            {
            case 0:
                if (m_changed == true)
                {
                    inputExit = m_exitMenu.run(cin);
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
}