#include<iostream>
#include <windows.h>
#include<cctype> // To check pin have only Digits
using namespace std;

// Password

const int MP = 1234;

// max customer

const int Max = 15;

// When there are no account

bool accounts_exist = false;

// How many accounts are there

int acc_created = 0;

class Customer{
	
	protected:
		
		string Mother_name[Max];
		long int CNIC[Max];
		int Account_Number[Max];
		string Pin[Max];
		
	public:
		
		string Father_name[Max], Address[Max], Signature[Max], Name[Max];
		int balance[Max] , withdraw, deposit;
		long int DOB[Max], Contact[Max];
		
		Customer(){ // Constructor
			
			for( int i = 0; i < Max; i++ ){
				
				Account_Number[i] = 0;	
			}
			
			for( int i = 0; i <= Max; i++ ){
				
				balance[i] = 0;	
			}
		}
		
		void Deposit(int i){
			
			cout<< "How much money you want to deposit: ";
			cin>> deposit;
			
			balance[i] = balance[i] + deposit;
			cout<< deposit << "is Deposited to your Account" << endl;
			Sleep(2500);
		}
		
		void Withdraw(int i){
			
			while(1){
				
				cout<< "How much money you want to withdraw: ";
				cin>> withdraw;
				
				if( withdraw > balance[i] ){
					
					cout<< "Insuficient Balance." << endl;
					continue;
				}
				else{
					
					cout<< "Thanks for Withdrawal";
					balance[i] = balance[i] - withdraw;
					cout<< "The Remaining Balance is: " << balance[i] << endl;
					break;
				}
			}			
		}
		
		void Check_Balance(int i){
			
			if( balance[i] == 0 ){
				
				cout<< "Your Balance is Zero" << endl;
				Sleep(1500);
				system("cls"); // Clear Screen Funtion
			}
			else{
				
				cout<< "Your balence is: " << balance[i] << endl;
			}
		}
		
		int Transfer_Money(int i){
			
			int tran_acc, tran_mon;
			char check;
			
			cout<< "Enter Account No.: ";
			cin>> tran_acc;
			
			for(int j = 0; j < Max; j++){
				
				if( tran_acc == Account_Number[j] ){
					
					check:
					cout<< "Y for Yes\nN for No"<< endl;
					cout<< "Do you want to transfer:";
					cin>> check;
					
					if( check == 'y' || check == 'Y' ){
					
						cout<< "How much you want to transfer: ";
						cin>> tran_mon;
						
						if( tran_mon > balance[i] ){
							
							cout<< "Insuficient Balance." << endl;
							goto check;
						}
						else{
							
							cout<< "Money Tansfered" << endl;
							balance[i] = balance[i] - tran_mon;
							balance[j] = balance[j] + tran_mon;
							cout<< "The Remaining Balance is: " << balance[i] << endl;
							break;
						}
					}
					else if( check == 'n' || check == 'N' ){
						
						return 0;
					}
					else{
						
						cout<< "Invaild Option." << endl;
					}
				}
				else{
					
					cout<< "Account not Found." << endl;
				}
			}
		}
		
		void Alerts(int i){
			
			if( balance[i] < 100 ){
				
				cout<< "Low Balance!" << endl;
			}
		}
		
		int Customer_Menu(){
	
			int choice, p_count = 0, check, AccountNo;
			string pin;
			bool acc_found = false;
			
			while(true){
				
				cout<<"1.Proceed: "<< endl;
				cout<<"2.Go Back: "<< endl;
				cout<<"Enter the choice(1-2)."<< endl;
				cin>> choice;
				
				switch(choice){
					
					case 1:
						if( !accounts_exist ){
							
							cout<< "There are no Accounts Created." << endl;
						}
						else{
							
							cout<< "Enter Your Account Number: ";
							cin>> AccountNo;
							
							for( int i = 0; i < Max ; i++ ){
								
								if( AccountNo == Account_Number[i] ){
									
									acc_found = true;
									pin:
									cout<<"Enter the pin: ";
									cin>> pin;
									if( pin == Pin[i] ){
										
										while(1){
											
											cout<< "1.Deposit" << endl;
											cout<< "2.Withdraw" << endl;
											cout<< "3.Check Balance" << endl;
											cout<< "4.Transfer Money" << endl;
											cout<< "5.Alerts" << endl;
											cout<< "6.Go Back" << endl;
											cout<< "Enter Choice: " ;
											cin>> check;
											if( check == 1 ){
												
												system("cls"); // Clear Screen Funtion
												Deposit(i);
											}
											else if( check == 2 ){
												
												system("cls"); // Clear Screen Funtion
												Withdraw(i);
											}
											else if( check == 3 ){
												
												system("cls"); // Clear Screen Funtion
												Check_Balance(i);
											}
											else if( check == 4 ){
												
												system("cls"); // Clear Screen Funtion
												Transfer_Money(i);
											}
											else if( check == 5 ){
												
												system("cls"); // Clear Screen Funtion
												Alerts(i);
											}
											else if( check == 6 ){
												
												return 0;
											}
											else{
												
												cout<< "Invalid Input!" << endl;
											}
										}
									}
									else{
										
										cout<<"Invaild Pin!"<< endl;
										p_count++;
										if( p_count == 3 ){
											
											cout<< "You have Entered Wrong Pin Multiple Times!"<< endl;
											Sleep(2000);
											return 0;
										}
										else{
											
											goto pin;
										}
									}
								}
							}
							if( !acc_found ){
								
								cout<< "Entered Account is not Found." << endl;
							}
						}
						break;
					case 2:
						return 0;
					default:
						cout<< "Invalid Choice"<< endl;		
				}
			}
		}
};

class Manager : public Customer{
	
    public:
    	
    	int choice, i ; 
		string pin;
    	char check;
    	
    	int New_Acc(){
    		
    		i = acc_created;
    		
			while(i < Max){
     		
				cout<<"Enter your Name: ";
	    		cin>>Name[i];
	    		cout<<"Enter your Father Name: ";
				cin>>Father_name[i];
				cout<<"Enter your Mother Name: ";
				cin>>Mother_name[i];
				cout<<"Enter your CNIC: ";
				cin>>CNIC[i];
				cout<<"Enter your Date of Birth: ";
				cin>>DOB[i];
				cout<<"Enter your Address: ";
				cin>>Address[i];
				cout<<"Enter your Contact: ";
				cin>>Contact[i];
				cout<<"Enter your Signature: ";
				cin>>Signature[i];
				pin:
    			bool isValid = true;
				cout << "Enter your 4-digit PIN: ";
			    cin >> pin;
				
				if ( pin.length() != 4 ){
					
			        isValid = false;
			    }
				else{
					
			        for( int j = 0; j < 4; j++ ){
			        	
			            if( !isdigit( pin[j] ) ){
			            	
			                isValid = false;
			                break;
			            }
			        }
			    }
			
			    if( isValid ){
			    	
			        cout << "Valid 4-digit PIN." << endl;
			        Pin[i] = pin;
			    }
				else{
					
			        cout << "Invalid PIN. Make sure it's exactly 4 digits" << endl;
					Sleep(2000);
					system("cls"); // Clear Screen Funtion
					goto pin; 
			    }
				
				Account_Number[i] = i + 1;
				acc_created++;
				cout<< "Account Number is: " << Account_Number[i] << endl;
				cout<< "Customer is Added Successfully." << endl;
				i++;
				accounts_exist = 1;
				Sleep(2000);
				system("cls"); // Clear Screen Funtion
				check:
				cout<< "Y for Yes\nN for No"<< endl;
				cout<< "Do you want to add another customer: ";
				cin>> check;
				
				if( check == 'y' || check == 'Y' ){
				
					continue;
				}
				else if( check == 'n' || check == 'N' ){
					
					return 0;
				}
				else{
					
					cout<< "Invalid Option!" << endl;
					goto check;
				}
			}
		}
		
		int Del_Acc(){
			
			int AccountNo;
			
			if( !accounts_exist ){
				
				cout<< "There are no Accounts Created." << endl;
				Sleep(1500);
				return 0;
			}
			else{
				
				cout<< "Enter Your Account Number: ";
				cin>> AccountNo;
							
				for( int i = 0; i < Max ; i++ ){
					
					if( AccountNo == Account_Number[i] ){
						
						cout << "\n========== Customer Detail ==========\n";
						cout << "Customer Name : " << Name[i] << endl;
						cout << "Contact       : " << Contact[i] << endl;
						cout << "CNIC          : " << CNIC[i] << endl;
						cout << "Signature     : " << Signature[i] << endl;
						cout << "=====================================\n";
						while(1){
							
							cout<<"Press 1 for YES."<<endl;
							cout<<"Press 2 for NO."<<endl;
							cout<< "Do you want To Remove Customer: ";
							cin>> choice;
							
						    if( choice == 1 ){
						    	
						    	Name[i] = "";
								Father_name[i] = "";
								Mother_name[i] = "";
								CNIC[i] = 0;
								DOB[i] = 0;
								Address[i] = "";
								Contact[i] = 0;
								Signature[i] = "";
								Account_Number[i] = 0;
						    	
						    	cout<<"The Account is Deleted. ";
						    	Sleep(1500);
						    	acc_created --;
								system("cls"); // Clear Screen Funtion
								return 0;
							}
							else if( choice == 2 ){
								
								return 0;
							}
							else{
								cout<<"Invalid Input.";
							}	
						}
					}
				}
				if( acc_created == 0 ){
					
    				accounts_exist = false;
				}
			}
		}
		
		int Get_Acc_detail(){
			
			system("cls"); // Clear Screen Funtion
			for( int i = 0; i <= Max; i++ ){
				
				if( Account_Number[i] != 0 ){
					
				cout << "\n========== Customer Detail ==========\n";
				cout << "Account Number : " << Account_Number[i] << endl;
				cout << "Name\t       : " << Name[i] << endl;
				cout << "Father Name    : " << Father_name[i] << endl;
				cout << "Mother Name    : " << Mother_name[i] << endl;
				cout << "Date Of Birth  : " << DOB[i] << endl;
				cout << "CNIC\t       : " << CNIC[i] << endl;
				cout << "Contact\t       : " << Contact[i] << endl;
				cout << "Address\t       : " << Address[i] << endl;
				cout << "Signaturen     : " << Signature[i] << endl;
				cout << "=====================================\n";
				Sleep(500);
				}
				else{
					
					return 0;
				}
			}
			Sleep(1500);
		}
		
		int Manager_Menu(){
			
			while(1){
				
				int pin, p_count, choice;
				pin:
				cout<<"Enter PIN: ";
				cin>>pin; 
		
				if( pin == MP ){
				
					while(1){
						
						cout<<"1. Create New Acocunt "<<endl;
						cout<<"2. Delete Acocunt "<<endl;
						cout<<"3. View Acocunts "<<endl;
						cout<<"4. Exit "<<endl;
						cout<< "Choose: ";
						cin>>choice;
						switch(choice){
							case 1:
								system("cls"); // Clear Screen Funtion
								New_Acc();
								system("cls"); // Clear Screen Funtion
								continue;
							case 2:
								system("cls"); // Clear Screen Funtion
								Del_Acc();
								system("cls"); // Clear Screen Funtion
								continue;
							case 3:
								system("cls"); // Clear Screen Funtion
								Get_Acc_detail();
								break;
							case 4:
							   return 0;
							default:
								cout<<"Invalid Choice! "<<endl;	
						}
					}
				}
				else{
					
					cout<<"Invaild Pin!"<< endl;
					p_count++;
					if( p_count == 3 ){
						
						cout<< "You have Entered Wrong Pin Multiple Times!"<< endl;
						Sleep(2000);
						return 0;
					}
					else{
						
						goto pin;
					}
				}
			}
		}
};

int main(){

	Manager m;
	int choice;
	
	while(true){
		system("cls"); // Clear Screen Funtion
		cout<<"Main Menu: "<< endl;
		cout<<"1. Manager" << endl;
		cout<<"2. Customer" << endl;
		cout<<"3. Exit Program"<< endl;
		cout<< "Enter the choice(1-3):";
		cin>> choice;
			
		switch(choice){
			
			case 1:
				system("cls"); // Clear Screen Funtion
				m.Manager_Menu();
				break;
			case 2:
				system("cls"); // Clear Screen Funtion
				m.Customer_Menu();
				break;
			case 3:
				cout<<"Exiting program.";
				return 0;
					
			default:
			    cout<<"Invalid choice." << endl;
			}
	}
}
