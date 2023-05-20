#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

using namespace std;

class program
{
          char program_number[30];
          char program_name[50];
          char accessor_name[20];
          int duration;
          int fee;

  public:
          void get_program_details()
          {
			cout<<"\nENTER DETAILS ABOUT THE PROGRAM\n";
                    cout<<"\nEnter The Program Number: ";
                    cin>>program_number;
                    cout<<"\nEnter The Name of The Program: ";
                     cin.ignore();
                    cin.getline(program_name,50);
                    cout<<"\nEnter The Assessor's Name: ";
                    cin.ignore();
                    cin.getline(accessor_name,50);
                    fflush(stdin);
                    cout<<"\nEnter The Fee : ";
				cin>>fee;
			cout<<"\nEnter The Duration (years) : ";
				cin>>duration;
          }

          void display_program()
          {
                    cout<<"\nProgram Number: "<<program_number;
                    cout<<"\nProgram Name: "<<program_name;
                    cout<<"\nAssessor's Name: "<<accessor_name;
                    cout<<"\nDuration (years) : "<<duration;
                    cout<<"\nFee : "<<fee;
          }
          void update_program()
          {
                    cout<<"\nProgram number : "<<program_number;
                    cout<<"\nUpdate Program Name : ";
                    cin.ignore();
                    cin.getline(program_name,50);
                    cout<<"\nUpdate Assessor's Name: ";
                    cin.ignore();
                    cin.getline(accessor_name,50);
                    fflush(stdin);
				cout<<"\nEnter Duration (years) : ";
				cin>>duration;
                                                          
          }
          char* getprogramnumber()
          {
                    return program_number;
          }
          void report()
          {cout<<program_number<<setw(30)<<program_name<<setw(30)<<accessor_name<<setw(30)<<duration<<setw(30)<<fee<<endl;}

};        



fstream fp;
program pro;
void add_program()
{
          system("cls");
          int more_or_main;
          fp.open("program.dat",ios::out|ios::app);
          do
          {
                    pro.get_program_details();
                    fp.write((char*)&pro,sizeof(program));
                    cout<<"\nPress 1 to add more programs.";
                    cout<<"\nPress 2 to return to main menu.\n";
                    cout<<"Enter: ";
                    cin>>more_or_main;
          }while(more_or_main == 1);
          fp.close();
}

void display_a_program(char n[])
{
          system("cls");
          cout<<"\nPROGRAM DETAILS\n";
          int check=0;
          fp.open("program.dat",ios::in);
          while(fp.read((char*)&pro,sizeof(program)))
          {
                    if(strcmpi(pro.getprogramnumber(),n)==0)
                    {
                               pro.display_program();
                              check=1;
                    }
          }
          fp.close();
          if(check==0)
                    cout<<"\n\nProgram does not exist";
        getch();
}

void update_program()
{
          system("cls");
          char n[20];
          int found=0;
          cout<<"\n\n\tUPDATE PROGRAM";
          cout<<"\n\n\tEnter The Program Number: ";
          cin>>n;
          fp.open("program.dat",ios::in|ios::out);
          while(fp.read((char*)&pro,sizeof(program)) && found==0)
          {
                    if(strcmpi(pro.getprogramnumber(),n)==0)
                    {
                               pro.display_program();
                               cout<<"\nEnter The New Details of The Program"<<endl;
                               pro.update_program();
                               int pos=1*sizeof(pro);
                              fp.seekp(pos,ios::cur);
                              fp.write((char*)&pro,sizeof(program));
                              cout<<"\n\n\t Record Updated Successfully...";
                              found=1;
                    }
          }
          fp.close();
          if(found==0)
                    cout<<"\n\n Record Not Found ";
          getch();
}

void delete_program()
{
          system("cls");
          char n[20];
          int flag=0;
          cout<<"\n\n\n\tDELETE PROGRAM";
          cout<<"\n\nEnter The Program's number You Want To Delete: ";
          cin>>n;
          fp.open("program.dat",ios::in|ios::out);
          fstream fp2;
          fp2.open("Temp.dat",ios::out);
          fp.seekg(0,ios::beg);
          while(fp.read((char*)&pro,sizeof(program)))
          {
                    if(strcmpi(pro.getprogramnumber(),n)!=0)  
                    {
                               fp2.write((char*)&pro,sizeof(program));
                    }
                    else
                              flag=1;
          }
          fp2.close();
          fp.close();
          remove("program.dat");
          rename("Temp.dat","program.dat");
          if(flag==1)
                    cout<<"\n\n\tRecord Deleted ..";
          else
                    cout<<"\n\nRecord not found";
          getch();
}

 void View_institute()
{
          system("cls");
          char n[20];
          int flag=0;
          cout<<"\n\n\n\tInstitution Details";
          cout<<"\n\nMASTER MIND INSTITUTE";
          cout<<"\n\nNO 83 Katugastota road Kandy";
          cout<<"\n\0758760924";
          getch();
}
void display_all_program()
{
          system("cls");
          fp.open("program.dat",ios::in);
          if(!fp)
          {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                    getch();
                    return;
          }
          cout<<"\n\n\t\tPROGRAM LIST\n\n";
         cout<<"=======================================================================================================================\n";
          cout<<"Program Number"<<setw(20)<<"Program Name"<<setw(27)<<"Assessor"<<setw(27)<<"Duration"<<setw(27)<<"Fee"<<endl;
          cout<<"=======================================================================================================================\n";
          while(fp.read((char*)&pro,sizeof(program)))
          {
                    pro.report();
          }
          fp.close();
          getch();
}

void intro()
{
     system("color 03");
     system("cls");
}
class student {
	     char student_number[30];
          char student_name[50];
          char program_name[20];
          

  public:
          void get_student_details()
          {
			cout<<"\nENTER DETAILS ABOUT STUDENTS\n";
                    cout<<"\nEnter The Student Number: ";
                    cin>>student_number;
                    cout<<"\nEnter The Name of The Student: ";
                     cin.ignore();
                    cin.getline(student_name,50);
                    cout<<"\nEnter The Program : ";
                    cin.ignore();
                    cin.getline(program_name,50);
                    fflush(stdin);
                    
          }
          
           void display_student()
          {
                    cout<<"\nStudent Number: "<<student_number;
                    cout<<"\nStudent Name: "<<student_name;
                    cout<<"\nProgram: "<<program_name;
                    
          }
          
          char* getstudentnumber()
          {
                    return student_number;
          }
          void report()
          {cout<<student_number<<setw(30)<<student_name<<setw(30)<<program_name<<endl;}
};

fstream ffp;
student sstd;
void add_student()
{
          system("cls");
          int more_or_main;
          ffp.open("student.dat",ios::out|ios::app);
          do
          {
                    sstd.get_student_details();
                    ffp.write((char*)&sstd,sizeof(student));
                    cout<<"\nPress 1 to add more students.";
                    cout<<"\nPress 2 to return to main menu.\n";
                    cout<<"Enter: ";
                    cin>>more_or_main;
          }while(more_or_main == 1);
          ffp.close();
}

void display_all_student()
{
          system("cls");
          ffp.open("student.dat",ios::in);
          if(!ffp)
          {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                    getch();
                    return;
          }
          cout<<"\n\n\t\tSTUDENT LIST\n\n";
         cout<<"===========================================================================\n";
          cout<<"Student Number"<<setw(20)<<"Student Name"<<setw(27)<<"Program"<<endl;
          cout<<"===========================================================================\n";
          while(ffp.read((char*)&sstd,sizeof(student)))
          {
                    sstd.report();
          }
          ffp.close();
          getch();
}


int main()
{
	{
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "admin" && userPassword == "admin123")
        {
            cout << "Welcome admin!\n";
            break;
        }
        else if (userName == "user" && userPassword == "user123")
        {
            cout << "Welcome user!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    cout << "Thank you for logging in.\n";
}
          int option = 0;
          for(;;)
          {
               intro();
            cout<<"\t\tMaster Mind Institue";
            cout<<"\n\t\tMAIN MENU";
            cout<<"\n\t\t-------------------------------------------------\n";
            cout<<"\n\t\tPlease select the option";
                cout<<"\n\t\tPress 1 to ADD PROGRAM";
                cout<<"\n\t\tPress 2 to DISPLAY ALL PROGRAMS";
                cout<<"\n\t\tPress 3 to SEARCH PROGRAM";
                cout<<"\n\t\tPress 4 to UPDATE PROGRAM";
                cout<<"\n\t\tPress 5 to DELETE PROGRAM";
                cout<<"\n\t\tPress 6 to REGISTER STUDENT";
                cout<<"\n\t\tPress 7 to VIEW STUDENT";
                cout<<"\n\t\tPress 8 to INSTITUTE DETAILS";
                cout<<"\n\t\tPress 9 to EXIT";
			cout<<"\n\t\t-------------------------------------------------\n";
			cout<<"\n\t\tPress ENTER in every unit to go back to main menu";
			cout<<"\n\t\tOption: ";
			cin>>option;
			switch(option)
	{
                    case 1:  system("cls");
                                         add_program();
                                                   break;
                               case 2: display_all_program();
                                 break;
                    case 3:
                              char num[20];
                               system("cls");
                              cout<<"\n\n\tPlease Enter The Program No. ";
                              cin>>num;
                              display_a_program(num);
                              break;
                    case 4: update_program();break;
                    case 5: delete_program();break;
                    case 6: add_student();break;
					case 7: display_all_student();break;
					case 8: View_institute();break;
                    case 9: exit(0);
                               break;
                    default:cout<<"\a";
          }     

          }
}

