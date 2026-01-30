#include <iostream>
using namespace std;

int balance = 1000;

void Welcome()
{
    cout<<"///////////////////////////////Welcome foolish one To el gayar bank///////////////////////////////"<<endl;

    cout<<"Enter Your Pin"<<endl;

    int pin;

    cin>>pin;
    int att=1;
    bool isinvalid = true;

    while (isinvalid)
    {

        if (att>=3 && ((cin.rdstate() & ios::failbit) || pin<1000 || pin>9999))
        {
            cout<<"Attempts " << att << " of 3 Your Card has been blocked, tezak 7mra"; 
            break;
        }
        

        if (cin.fail())
        {
           cout<<"Invalid! This is either not a number or way too long, Attempts " << att << " of 3"<<endl;
           cin.clear();
           cin.ignore(1000,'\n');

           cout<<"Enter Your Pin"<<endl;
           att++;
           cin>>pin;
        }

        else if (pin<1000 || pin>9999 )
        {
            cout<<"Sike, that's the wrong number only 4 numbers, try again, Attempts " << att << " of 3"<<endl;
            cout<<"Enter Your Pin"<<endl;
            att++;
            cin>>pin;
        }
    
         else
        {
            isinvalid = false;
            cout<<"///////////////////////////////Welcome to the System///////////////////////////////"<<endl;
            
     
        }

        
    }

   
}
void viewbalance() 

{
    cout<<" Your Balacne is : "<< balance <<endl;
}
void deposit() //ايداع
{
    int deposit;

    cout<<"How much do you wish to deposit?"<<endl;
    cin>>deposit;

    while ( cin.fail() || deposit<=0 )
    {

        if (cin.fail())
        {
           cout<<"Invalid entry. Letters and decimals are not permitted. Please enter a whole number"; 
           cin.clear();
           cin.ignore(1000,'\n');
        }
        else
        {
        cout << "Invalid amount! Please enter a positive number: "<<endl;
        }
        cout<<"Enter number: "<<endl;
        cin>>deposit;
    }

    balance = deposit + balance;

    cout<<"The operation was successful."<<endl;
    
}
void withdraw()  //سحب
{
    int withdraw;

    cout<<"How much do you wish to withdraw?"<<endl;
    cin>>withdraw;

    while ( cin.fail() || withdraw > balance || withdraw <= 0 )
    {

         if (cin.fail())
        {
           cout<<"Invalid entry. Letters and decimals are not permitted. Please enter a whole number"; 
           cin.clear();
           cin.ignore(1000,'\n');
           
        }
        else if (withdraw > balance)
        {
            cout<<"You cannot withdraw more money than your balance."<<endl;
        }
        else 
        {
            cout<<"Invalid amount! Please enter a positive number:"<<endl;
        }
       

        cout<<"Enter number: "<<endl;
        cin>>withdraw;
    }

    balance= balance - withdraw;

    cout<<"The operation was successful."<<endl;


}
void mainmenu()
{
    cout<<"///1- View Balance"<<endl;
    cout<<"///2- Deposit"<<endl;     //ايداع
    cout<<"///3- Withdraw"<<endl;   //سحب
    cout<<"///4- Exit "<<endl;
}


int main()

{
    Welcome();

    int choice;

do
{
    mainmenu();

    cin>>choice;

    if (cin.fail())
        {
           cout<<"Invalid! only numbers from 1 to 4"<<endl;
           cin.clear();
           cin.ignore(1000,'\n');
           
    
        }
    switch (choice)
    {
     case 1 : viewbalance(); break;
     case 2 : deposit(); break;
     case 3 : withdraw(); break;
     case 4 : cout<<"Goodbye,Have a nice day/night"<<endl; break;
     default: cout << "Please select 1, 2, 3, or 4 only." << endl;
    }
    
    } while (choice != 4);

   return 0;
}
