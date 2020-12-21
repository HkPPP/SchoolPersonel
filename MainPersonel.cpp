#include "ListOfPersonel.h"

// To compile: g++ -g MainPersonel.cpp
// To run: ./a.out

int main(){
    std::string Name, Title, MajorOrDeparment, Minor, Activity;
    date_s Date;
    list_c FullList;
    int choice = 1;

    do{
    // Menu to ask if the person wants to continue or which function to do.
    std::cout << " 1 to print\n 2 to add a student\n 3 to add a faculty\n 4 to search person\n 5 to remove\n 0 to exit\n";
    std::cin >> choice;

        switch(choice){
            /*Print the entire list*/
            case 1: FullList.printAll(); break;

            /*Add Student*/
            case 2: {
                std::cin.ignore(); // this is necessary to make sure the cin works properly
                std::cout << "Full name of student? ";
                getline(std::cin, Name);
                std::cout << "What is the title? ";
                getline(std::cin, Title);
                std::cout << "Major? ";
                getline(std::cin, MajorOrDeparment);
                std::cout << "Minor? ";
                getline(std::cin, Minor);
                std::cout << "Activity? (Seperate by a comma): ";
                getline(std::cin, Activity);
                std::cout << "Graduate day? ";
                std::cin >> Date.day;
                std::cout << "Graduation month? ";
                std::cin >> Date.month;
                std::cout << "Graduation year? ";
                std::cin >> Date.year;
                FullList.addHead(Name, Title, MajorOrDeparment, Minor, Date, Activity);
                break;
            }

            /*Add Faculty*/
            case 3: {
                std::cin.ignore();
                std::cout << "Name of faculty? ";
                getline(std::cin, Name);
                std::cout << "What is the title? ";
                getline(std::cin, Title);
                std::cout << "Major? ";
                getline(std::cin, MajorOrDeparment);
                std::cout << "Start day? ";
                std::cin >> Date.day;
                std::cout << "Start month? ";
                std::cin >> Date.month;
                std::cout << "Start year? ";
                std::cin >> Date.year;
                FullList.addTail(Name, Title, MajorOrDeparment, Date);
                break;
            }

            /*Search for a person*/
            case 4: {
                std::cin.ignore();
                std::cout << "Search for? ";
                getline(std::cin, Name);
                FullList.search(Name);
                break;
            }

            /*Remove a person*/
            case 5: {
                std::cin.ignore();
                std::cout << "Remove: ";
                getline(std::cin, Name);
                FullList.remove(Name);
                break;
            }
        }

    }while(choice);

    return 0;
}
