#include<iostream>
#include<string>
#include <windows.h>

using namespace std;

class user_information
{
private:
    int Password, Money;
	string account_name;
public:
	user_information(){}
	user_information(int pass,int money,string name)
	{
	    Password=pass;
	    Money=money;
	    account_name=name;
	}

	void SetMoney(int M)
	{
		Money = M;
	}
	void SetPassword(int p)
	{
		Password = p;
	}
	void Setaccount_name(string name)
	{
		account_name = name;
	}
	int GetPassword()
	{
		return Password ;
	}
	int GetMoney()
	{
		return Money ;
	}
	string GetAccount_name()
	{
		return account_name ;
	}
};
user_information user[5]{{1234,5000,"ahmed"},{5678,6000,"mohamed"},{1478,2000,"ali"},{2589,4000,"mahmoud"},{3698,3000,"esraa"}};
int pass,num_Person=-1,choose ,enter_Try = 0;
bool check = false;
string acc_number;
class ATM
{  public:
  int check_Password()
  {

	do
	{
		++enter_Try;
		cout << "Welcome to ATM System" << endl << "Plz,Enter Your Password Of Four Digit" << endl;
		cin >> pass;

			for (int i = 0; i < (sizeof(user)/sizeof(*user)); i++)
			{
				if (user[i].GetPassword() == pass)
				{
					num_Person = i;
					check = true;
					break;
				}

			}
			if (enter_Try > 2&&check==false)
			{
				cout << "U have entered Wrong Password 3 once , you should go to office banking" << endl;
				break;
			}

	} while (!check);
	return num_Person;
  }
  void Display_Msg(int num_object)
  {
	cout << "Welcome "<<user[num_object].GetAccount_name() << endl;
	do{
	cout << "Enter number of your choose,Plz " << endl;

	cout << "1 - Deposit               2 - Withdraw money" << endl;

	cout << "3 - Account Balance       4 - Transfer money "<< endl;

   // cout << "5 - To Go to another account                 "<< endl;

    cout << "0 - To Cancel operation or Exit              "<< endl;
	cin >> choose;

	switch (choose)
	{
    case 0:
	           cout<<"thanks for visiting us"<<endl;
            break;
	case 1:

                cout << "You must Enter Integer Number,we will take integer only " << endl;
		        cin >> choose;

                Deposit_Money(abs(choose),num_object);
            break;
	case 2:
		        cout<<"You must Enter Integer Number,we will take integer only "<<endl;
		        cin >> choose;
		     	Withdraw_Money(choose,num_object);
			break;
	case 3:
               cout << "Your balance is "<<GetMoney(num_object) << endl;
		    break;
	case 4:
		       cout << "Enter Account Number, U want to transfer money to him" << endl;
		       cin >> acc_number;
		       for (int i = 0; i <(sizeof(user)/sizeof(*user)); i++)
		       {
		        	if (acc_number == user[i].GetAccount_name())
		        	{
			        	cout << "Enter Balance E.L " << endl;
			        	cin >> choose;
                        Transfer_Money(choose, num_object, acc_number);
                        break;
			        }
		       }
            break;
   /* case 5:
		      num_object=check_Password();
              Display_Msg(num_object);
            break;*/
	default:
		       cout<<"U have entered Error Order"<<endl;
		    break;
	}
   }while(choose!=0);
  }
  void Deposit_Money(int m,int numberOfObject)
  {
		user[numberOfObject].SetMoney(user[numberOfObject].GetMoney()+abs(m));
        cout << "Your Balance become " << user[numberOfObject].GetMoney() << endl;
  }
  void Withdraw_Money(int m,int numberOfObject)
	{
		if (m > user[numberOfObject].GetMoney())
		{
			cout << "Your Balance is less than your withdraw money" << endl;
		}
		else
		{
			user[numberOfObject].SetMoney(user[numberOfObject].GetMoney()-abs(m));
            cout << "Your Balance become " << user[numberOfObject].GetMoney() << endl;
		}

	}
	int GetMoney(int numberOfObject)
	{
	    return user[numberOfObject].GetMoney();
	}
    void Transfer_Money(int m, int numberOfObject, string toAnotherAccount)
    {
	     int moneyInAccount = user[numberOfObject].GetMoney();
	     if (m > user[numberOfObject].GetMoney())
	     {
		      cout << "Your Balance is less than your Transfer_money" << endl;
	     }
	     else
	     {
		     user[numberOfObject].SetMoney(user[numberOfObject].GetMoney()-abs(m));
		     cout << "U Transfer Money to Another account name(  " << toAnotherAccount << " ) ,U transfer " << m << "E.L" << endl;
		     cout << "Your Balance become " << user[numberOfObject].GetMoney() << endl;
		     for(int i=0;i<(sizeof(user)/sizeof(*user));i++)
             {
                if(toAnotherAccount == user[i].GetAccount_name())
                {
                   user[i].SetMoney(user[i].GetMoney()+abs(m));
                   break;
                }
             }
	     }
    }
};
int main()
{
	ATM atm;
	int numOfObject;
    numOfObject=atm.check_Password();
    if( numOfObject!=-1)
    {
       atm.Display_Msg(numOfObject);
    }
	return 0;
}
