#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<sstream>


using namespace std;


void signUp()
        {
	    bool check_valid = false;
            string id;
            string pass;

		 do
        {
   // string id;
    cout << "enter id pass" << endl;
   getline(cin,id);
   // cin.ignore();
   // string pass;
    getline(cin,pass);
   // cin.ignore();

    cout << id << endl << pass << endl; 
    if(!id.empty() && id.find(',') == string::npos && !pass.empty() && pass.find(',') == string::npos)

        {
        check_valid = true;
            
            }
        }

    while(check_valid == false);        

    ofstream out("user.txt" , ios::app);

    if(out.is_open() == true)
            {
                out << id << "," << pass << "\n";
                out.close();
            }
    else
            {
                cout << "File not opened" << endl;
            }


        }   


//check for user account if provided valid input or not

bool authenticate(string* f2login_Id , string* f2login_Pass)

        {
         
            map <string , string> userData;
            
            ifstream file("user.txt");
            
            if(!file.is_open())
                    {
                        cout << "Error while opening the backend file" << endl;
                        return false;

                    }
            
                  
        string line;
        while(getline(file , line))
        {
          stringstream store(line);
          string username , password;

          if(getline(store , username , ',') && getline(store , password))
                {
                userData[username] = password;

                }
                        
        }
        file.close();

        auto it = userData.find(*f2login_Id);
        

        if(it != userData.end() && it->second == *f2login_Pass)
                {
                    cout << "Log in successful." << endl;
                    return true;
                }
                
        else
                {
                    cout << "Invalid username or password" << endl;
                    return false;
                }






                   



        }




// converting to function later
    
void logInput(string* f_loginId , string* f_loginPass , bool* f_loginValid)
    
    {
        *f_loginValid = false;

        int attemptCount = 0;

    do  
    {   
        cout << "Enter Log in ID" << endl;
        cin.ignore();
        getline(cin , *f_loginId);
        
        cout << "Enter Log in PASS" << endl;
   //     cin.ignore();
        getline(cin , *f_loginPass);

      if(!f_loginId->empty() && !f_loginPass->empty() && f_loginId->find(',') == std::string::npos && f_loginPass->find(',') == std::string::npos)
                {
                    *f_loginValid = true;
                    

                }

       else
            {
             cout << "Invalid Input Try again!!" << endl;
             attemptCount++;
            }
        if(attemptCount >= 5)
                {
                 cout << "You entered invalid input too many times :)!! try again when your mind is in right place" << endl;
                 
                }

    }
        while(*f_loginValid == false && attemptCount < 5);        
                
      
      }







    int main()
        {


            string login_id;
            string login_pass;
            bool login_valid = false;


         


            cout << "E-Flight Reservation System" << endl;
            cout << "1--> SignUp" << endl;
            cout << "2--> LogIn" << endl;

            int ask_user_choice;
            cin >> ask_user_choice;
            

        if(ask_user_choice == 1)
            {
              signUp();
            }
        else if(ask_user_choice == 2)
            {
              logInput(&login_id , &login_pass , &login_valid);
              cout << login_id << endl << login_pass << endl;
              authenticate(&login_id , &login_pass);

            }   


	
    // 	logInput(&login_id, &login_pass , &login_valid);
    //   authenticate(&login_id , &login_pass);




    }
