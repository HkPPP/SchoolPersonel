#ifndef PERSON_H
#define PERSON_H

#include <iostream>

//Base class
class person_c{
    //Attributes: Name, job title, division/department/major
    protected: 
        std::string name, title, department;
        
    public:
        person_c  *next, *previous;
        
        //Virtual print that prints out Name, Job Titles, and Department
        virtual void printAll(){
            std::cout << "----------------&&&----------------\n";
            std::cout << "Information: \n";
            std::cout << "  Name: " << name << std::endl;
            std::cout << "  Job Title: " << title << std::endl;
            std::cout << "  Departmment: " << department << std::endl; 
        }

        //Get function
        std::string getName() { return name; }
        std::string getTile() { return title; }
        std::string getDepartment() { return department; }

        //Set attributes through constructors
        //Empty constructor
        person_c():name("Empty"), title("Empty"), department("Empty"){
            std::cout << "\nAn empty person has been created\n";
        }

        //Contructor with inputs
        person_c(std::string Name, std::string Title, std::string Department):name(Name), title(Title), department(Department){
            std::cout << "-------------------------------------------\n";
            std::cout << "Person object " << name << " has been created.\n";
            next = NULL;
            previous = NULL;
        }

        //Destructor
        ~person_c(){
            std::cout << name << " has been destructed.\n";
        }

};

//Create a date struct with day, month and year
struct date_s{
    int month, day, year;
};

//Student class, derived from person_c
class student_c:public person_c{
    protected:
        std::string minor, actitvity;
        date_s graduation;
    public:
        //Set functions
        void setGraduation(int Month, int Day, int Year){
            graduation.day = Day;
            graduation.month = Month;
            graduation.year = Year;
        }
        void setMinor(std::string Minor) { minor = Minor; }
        void setActivity(std::string Activity) { actitvity = Activity; }

        //Get functions
        date_s getGraduation() { return graduation; }
        std::string getMinor() { return minor; }
        std::string getActivity() { return actitvity; }

        //Time until graduation
        void timeUntilGraduation(date_s Today){
            int monthLeft = graduation.month - Today.month;
            if(monthLeft < 0){ monthLeft = (-1)*monthLeft; }
            int yearLeft = graduation.year - Today.year;
            std::cout << "---> It is " << monthLeft << " months and " << yearLeft << " years until Graduation! <---\n";
        }

        //Print all student attributes (including inherited ones)
        void printAll(){
            person_c::printAll();
            std::cout << "  Minor: " << minor << std::endl;
            std::cout << "  Activity: " << actitvity << std::endl;
            std::cout << "  Graduationd date: " << graduation.month << "/" << graduation.day << "/" << graduation.year << std::endl;
            std::cout << "----------------&&&----------------\n";
        }

        //Constructor
        student_c(std::string Name = "Unknown", std::string Title = "Unknown", std::string Major = "Unknown", 
        std::string Minor = "Unknown", date_s Graduation = {31,8,2022}, std::string Activity = "Unknown")
        :person_c(Name, Title, Major), minor(Minor), graduation(Graduation), actitvity(Activity){
            std::cout << "Student object " << name << " has been created.\n";
            std::cout << "-------------------------------------------\n";
        }

        //Destructor
        ~student_c(){
            std::cout << "Student object " << name << " has been destructed.\n";
        }
};

//Faculty class, derived from person_c
class faculty_c:public person_c{
    protected:
        date_s startDate;
    public:
        //Print all faculty attributes (including inherited ones from person_c)
        void printAll(){
            person_c::printAll();
            std::cout << "  Start date: " << startDate.month << "/" << startDate.day << "/" << startDate.year << std::endl;
            std::cout << "----------------&&&----------------\n"; 
        }

        //Constructor
        faculty_c(std::string Name = "Unknown", std::string Title = "Unknown", std::string Department = "Unknown", date_s StartDate = {1,1,2020})
        :person_c(Name, Title, Department), startDate(StartDate){
            std::cout << "Faculty object " << name << " has been created.\n";
            std::cout << "-------------------------------------------\n";
        }

        //Destrcutor
        ~faculty_c(){
            std::cout << "Faculty object " << name << " has been destrcuted.\n";
        }    
};

#endif