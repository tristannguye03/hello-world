
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STUDENT MANAGEMENT PROGRAM

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Headers inclusion
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//Structure defining
struct student
{
    string fname;//for student first name
    string lname;//for student last name
    string studentID;//for studentID
}studentData;//Variable of student type

void addNewStudent();
void deleteAStudent();
void findAStudent();
void disPlayMenu();

///////////////////////////////////////////////////
//Main function

int main()
{
    char choice;//for getting choice
    string find;//for sorting
    string srch;
    
    //Level 1-Display process
    disPlayMenu();
    cin>>choice;
    while (choice != '1' && choice != '2' && choice != '3')
    {
        std::cout << "Invalid number: " << choice << " Select '1' or '2' or '3' " << std::endl;
        std::cin >> choice;
    }
    
    switch(choice)//First switch
    {
        case '1': //Student
        {
            addNewStudent();
            break;
        }
        case '2': //Delete a Student
        {
            deleteAStudent();
            break;
        }
        case '3': //Find A Student
        {
            findAStudent();
            break;
        }
        default:
            cout << "Invalid choice\n";
            choice = 0;
    }
    
    return 0;
}

/*****************************************************************************
 ** Functions implementations
 ******************************************************************************/

void addNewStudent()
{
    cout <<"Enter the ID:" << endl;
    cin >> studentData.studentID;
    cout <<"Enter First Name:" << endl;
    cin >> studentData.fname;
    cout <<"Enter Last Name:" << endl;
    cin >> studentData.lname;
    fstream myfile;
    myfile.open("dataStudent.txt", ios::app | ios::out);
    myfile << studentData.studentID << ' ' << studentData.fname << ' ' << studentData.lname << '\n'; // <--
    myfile.close();
    cout <<"The Student Updated"<< endl;
    //closing the file
    myfile.close();
}//addStudent

void findAStudent()
{
    string search;
    ifstream myFile;
    string line;
    
    myFile.open("dataStudent.txt");
    
    if(!myFile){
        cout << "Unable to open file" << endl;
        exit(1);
    }
    cout << "Enter ID or student name to search for: ";
    cin >>search;
    
    size_t pos;
    while(myFile.good())
    {
        getline(myFile,line); // get line from file
        pos=line.find(search); // search
        if(pos!=string::npos) // string::npos is returned if string is not found
        {
            cout <<"ID and student full name :" << " " << line << '\n';
        }
        else
            cout <<"Can't find this student in data" << '\n';
        break;
    }
    myFile.close();
    
}

void deleteAStudent()
{
    string line, name;
    cout << "Please Enter the name of record you want to delete: ";
    cin >> name;
    ifstream myfile;
    myfile.open("dataStudent.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(myfile, line))
    {
        if (line.substr(0, name.size()) != name)
            temp << line << endl;
    }
    cout << "The record with the name " << name << " has been deleted" << endl;
    myfile.close();
    temp.close();
    remove("dataStudent.txt");
    rename("temp.txt", "dataStudent.txt");
}
void disPlayMenu()
{
    //Level 1-Display process
    cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
    cout<<"\n\n\t\t\tSTUDENT MANAGEMENT PROGRAM\n\n";
    cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
    cout<<"\n\n\t\t\t\t\tMAIN SCREEN\n\n";
    cout<<"Enter your choice: "<<endl;
    cout<<"1.Add New Student "<<endl;
    cout<<"2.Delete A Student"<<endl;
    cout<<"3.Find A Student"<<endl;
    
}
