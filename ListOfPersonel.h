#ifndef DATA_H
#define DATA_H

#include "schoolPersonel.h"

class list_c{
	protected:
		person_c *Head, *Tail;
	public:
		void addHead(std::string studentName = "Unknown", std::string Title = "Unknown", std::string Major = "Unknown", 
        std::string Minor = "Unknown", date_s Graduation = {31,8,2022}, std::string Activity = "Unknown");
		void addTail(std::string facultyName = "Unknown", std::string Title = "Unknown", std::string Department = "Unknown", date_s StartDate = {1,1,2020});
		void remove(std::string name);
		void deleteAll();
		void search(std::string name);
		void printAll();

        /*Set Head and Tail to NULL upon construction
        Only NULL when the list is empty*/
        list_c(){
            Head = NULL;    
            Tail = NULL;    
        }

        /*Delete list when the list is destructed*/
        ~list_c(){
            deleteAll();
        }


};

/*Add student to the head of the list*/
void list_c::addHead(std::string studentName, std::string Title, std::string Major, 
    std::string Minor, date_s Graduation, std::string Activity){

    person_c *NewStudent = new student_c(studentName, Title, Major, Minor, Graduation, Activity);

    if(Head == NULL){   //If the list is empty, Head and Tail points to the same student
        Head = NewStudent;
        NewStudent->next = NULL;        // both next and previous pointers are NULL 
        Tail = NewStudent;              // on first entry
        NewStudent->previous = NULL;
    }
    else{       // Add student to the Head
        Head->previous = NewStudent;
        NewStudent->next = Head;
        NewStudent->previous = NULL;
        Head = NewStudent;              // NewStudent becomes the new Head
    }
}

/*Add faculty to the tail of the list*/
void list_c::addTail(std::string facultyName, std::string Title, std::string Department, date_s StartDate){
    person_c *NewFaculty = new faculty_c(facultyName, Title, Department, StartDate);
    if(Tail == NULL){ //If the list is empty, Head and Tail points to the same faculty
        Head = NewFaculty;
        NewFaculty->next = NULL;        // both next and previous pointers are NULL 
        Tail = NewFaculty;              // on first entry
        NewFaculty->previous = NULL;    
    }
    else{       // Add faculty to the Tail
        Tail->next = NewFaculty;
        NewFaculty->previous = Tail;
        NewFaculty->next = NULL;
        Tail = NewFaculty;              // NewFaculty becomes the new Tail
    }
    std::cout << "Tail: " << Tail->getName() << std::endl;
    std::cout << "Head: " << Head->getName() << std::endl;
    
}


void list_c::remove(std::string name){
    bool found = 0;
    person_c *deleteThisOne;

    if(Head == NULL){
        std::cout << "List is empty!\n\n";
    }
    else if(name == Head->getName()){
        deleteThisOne = Head;
        Head->next->previous = NULL;
        Head = Head->next;
        delete deleteThisOne;
        deleteThisOne = NULL;
        found = 1;
    }
    else if(name == Tail->getName()){
        deleteThisOne = Tail;
        Tail->previous->next = NULL;
        Tail = Tail->previous;
        delete deleteThisOne;
        deleteThisOne = NULL;
        found = 1;
    }
    else{
        /*Only delete the first matching name it found going from Head to Tail*/
        for(deleteThisOne = Head; deleteThisOne->next != NULL; deleteThisOne = deleteThisOne->next){
            if(deleteThisOne->getName() == name){
                deleteThisOne->previous->next = deleteThisOne->next;
                deleteThisOne->next->previous = deleteThisOne->previous;
                delete deleteThisOne;
                deleteThisOne = NULL;
                found = 1;
                break;
            }
        }
    }

    if(!found){
        std::cout << "Can't find the name in list!\n";
    }

}

/*Delete everything in the list and set their pointers to NULL*/
void list_c::deleteAll(){
    person_c *temp = Head;      // Temporary pointer
    person_c *deleteThisOne;    // Hold the object that needs to be deleted
    while(temp != NULL){
        deleteThisOne = temp;
        temp = temp->next;
        delete deleteThisOne;
        deleteThisOne = NULL;
    }
    Tail = NULL;                
}


void list_c::search(std::string name){
    bool found = 0;
    for(person_c *temp = Head; temp != NULL; temp = temp->next){
        if(temp->getName() == name){
            temp->printAll();
            found = 1;
        }
    }

    if(!found){
        std::cout << "Can't find the name in list!\n";
    }
}
void list_c::printAll(){
    person_c *temp = Head;
    if(Head == NULL){
        std::cout << "List is empty!\n\n";
    }
    else{
        do{
            temp->printAll();
            temp = temp->next;
        }while(temp != NULL);
    }
}

#endif