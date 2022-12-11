#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
void login();
void sign_up();
void forgot_password();

int main(){
    int c;
    cout<<"\n\n\n";
    cout<<"\t\t\t_____________________WELCOME TO THE HOME PAGE________________________\n";
    cout<<"\t\t\t______________________________MENU___________________________________\n";
    cout<<"\n\n\n";

    cout<<"\t\t\t PRESS 1 TO LOGIN                   "<<endl;
    cout<<"\t\t\t PRESS 2 TO SIGN UP                "<<endl;
    cout<<"\t\t\t PRESS 3 IF YOU FORGOT YOUR PASSWORD"<<endl;
    cout<<"\t\t\t PRESS 4 TO EXIT                   "<<endl;
    cout<<"\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    cout<<"\n\n\t\t\t Please choose your option-> ";

    cin>>c;

    switch(c)
    {
    case 1:
        login();
        break;

    case 2:
        sign_up();
        break;

    case 3:
        forgot_password();
        break;
    case 4:
        cout<<"\t\t\t Thank YOU!!!";

    default:
        system("cls");
        cout<<"Please enter a digit form the no's given above";
        main();
    }
}

void login(){
    int count=0;
string userID,password,id,pass;
cout<<" \t\t USERNAME-> ";
cin>>userID;

cout<<endl;

cout<<"\t\t PASSWORD-> ";
cin>>password;

cout<<endl;

ifstream input("records.txt");

while(input>>id>>pass){
    //entering the id and password in a file
    //input is the command to take anything input in a string
    if(id==userID && pass== password){
        count=1;
        system("cls");
    }
   }
input.close();
if(count==1){
    cout<<"YOUR LOGIN IS SUCCESFULL \nTHANKS FOR LOGGING IN \n";
    main();
    }
else{
        cout<<"Please enter correct username and password \n";
        main();
    }
}

void sign_up(){
string ruserID,rpassword,rid,rpass;
system("cls");
cout<<"Enter the username-> ";
cin>>ruserID;

cout<<endl;

cout<<"Enter the password-> ";
cin>>rpassword;

cout<<endl;

ofstream f1("records.txt",ios::app);//app->append mode in file handling
f1<<ruserID<<' ' <<rpassword<<endl;

system("cls");

cout<<"your registration is succesful!"<<endl;

//now after registration return back to the main function to login or new registration.
main();
}


void forgot_password()
{
cout<<"if you forgot the password no worries"<<endl;
cout<<"Press 1 to enter your userId "<<endl;
cout<<"Press 2 to return to main menu"<<endl;
cout<<"Enter your choice-> ";

int option;
cin>>option;

cout<<endl;

switch(option){
case 1:
    {
    int count=0;
    string suserID,sID,spass;
    cout<<"\n\n ENTER THE USER ID YOU REMEMBER-> ";
    cin>>suserID;

    cout<<endl;

    ifstream f2("records.txt" );
     while(f2>>sID>>spass)
    {
        if(sID==suserID)
        {
            count=1;
        }
        f2.close();

        if(count==1)
        {

            cout<<"Sigh!!, We have found your account"<<endl;
            cout<<"Your username is-> "<<suserID<<endl;
            cout<<"Your password is-> "<<spass<<endl;

        }

        else{
            cout<<"Sorry!, Your account is not found"<<endl;
              main();
            }

          break;
    }
    }
case 2:
    {
        main();
    }
default:
    cout<<"You have entered a wrong number, kindly enter either 1 or 2"<<endl;

    }
}
