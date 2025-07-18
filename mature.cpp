#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <limits>
#include <flight.h>

#define ACODE 117

using namespace std;




 class User {
 private: 
    string username;
    string password;

 public:
 /*same as
    User(string uname , string pwd)
        {
        username = uname;
        password = pwd;
        }

 */
    User(string uname , string pwd):username(uname) , password(pwd){}
  

// Sign up a new user and save to file
 bool signUp()
   {
    bool check_valid = false;
    string id , pass;

         
    if(!validateInput(username , password))
     {
                  cout << "Invalid Input for signup" << endl;
                  return false;
     }
 
 //check for duplicate value 
              
 map <string , string> userData;
 ifstream file("user.txt");
            
 if(file.is_open())
   {
    string line;

    while(getline(file,line))
    {
    stringstream store(line);
    string uname , pwd;

    if(getline(store , uname , ',') && getline(store , pwd))
     {
       userData[uname] = pwd;

     }     

   }

   file.close();
    
  if(userData.find(username) != userData.end())
    {
     cout << "Username already exists." << endl;
     return false;
    }    
   }

  else
    {
     cout << "Error while opening file" << endl;
     return false;
    } 

   
  ofstream out("user.txt" , ios::app);
  if(out.is_open())
  {
    out << username << "," << password << "\n";
    out.close();
    return true;
  }
  
    cout << "Error while opening file.(inserting)" << endl;
    return false;
 }   


//Authenticate user credentials against file

 bool authenticate()
  {
   map<string , string> userData;
   
   ifstream file("user.txt");
   
 if(!file.is_open())
   {
    cout << "Error opening file" << endl;
    return false;
   }
   
   string line;

  while(getline(file , line))
   {
    stringstream store(line);
    string uname , pwd;
  
  if(getline(store , uname , ',') && getline(store , pwd))
   {
    userData[uname] = pwd;
   }

   }

   file.close();
 
 auto it = userData.find(username);
 if(it != userData.end() && it->second == password)
   {
    cout << "Log in Successfull" << endl;
    return true;
   }    
 cout << "Incorrect Username or Password" << endl;
 return false;


 }    



// Validate input (no empty strings or commas)
  static bool validateInput(string uname , string pwd)
     {
     return  uname.find(',') == string::npos  && !uname.empty() && pwd.find(',') == string::npos && !pwd.empty();
     }

// Collect and validate login input

  static bool logInput(string* f_loginId , string* f_loginPass)
    {
     bool loginValid = false;
     int attemptCount = 0;

  do
  {
      cout << "Enter Log in ID" << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin, *f_loginId);
        
     cout << "Enter Log in PASS" << endl;
     getline(cin, *f_loginPass);

     if(validateInput(*f_loginId, *f_loginPass)) {
       loginValid = true;
       }
     else {
       cout << "Invalid Input Try again!! (No empty inputs or commas allowed)"        << endl;
       attemptCount++;
       }
     if (attemptCount >= 5) {
        cout << "You entered invalid input too many times :)!! Try again when y        our mind is in the right place" << endl;
        return false;
       }

   } 
   while (!loginValid);

   return true;

  }

  };


class Admin {
    private: 
    string adminName;
   
   public:
    Admin(string a_name):adminName(a_name){};


 
// check the authentication of admin
    static bool adminLogin(string* admin_name){
       //   *admin_name;
          int attempt = 0;
    //    map <string> adminData;
        ifstream adminFile("adminUser.txt");

        if(!adminFile.is_open())
          {
            cout << "Error Openning Admin file" << endl;
            return false; 
          }
        
        string line;
        while(getline(adminFile , line))
         {
          if(line == (*admin_name))
          {
              return true;
          }
          attempt++;

          if(attempt > 2) return false;

         }

        adminFile.close();

      return false;  

            
    }


    };





int main() {
    while (true) {
        cout << "\nE-Flight Reservation System" << endl;
        cout << "1--> SignUp" << endl;
        cout << "2--> LogIn" << endl;
        cout << "3--> Exit" << endl;
        cout << "4--> Admin Panel" << endl;


        int ask_user_choice;
        cout << "Enter your choice (1-4): ";
        while (!(cin >> ask_user_choice) || ask_user_choice < 1 || ask_user_choice > 4) {
            cout << "Invalid choice. Enter 1, 2, 3 or 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    if(ask_user_choice == 4) {
        bool isAuthenticated = false;
        string Admin_ID;
        cout << "Enter admin Id : " ;
        cin >> Admin_ID;
        cin.ignore();

        

        if(Admin::adminLogin(&Admin_ID))
        {
      int code;
     
     
      cout << "Your name is in admin DataBase." << endl;
   cout << "Enter the final verification code : " << endl;
   cin >> code; 
   if(code == ACODE)
       {
        cout << "Login Successful" << endl;
        isAuthenticated = true;
       } 
       else
        {
         cout << "Login Unsuccessful" << endl;
        }
  // cout << (code == ACODE ? "Login Successful" : "Login Unsuccessful") << endl;
       }
   else
   cout << "Login unsuccessful." << endl;

  

  // Reexamine this carefully..
    if(isAuthenticated == true)
      {
        int adminChoice;
        cout << "1--> ADD Flight" << endl;
        cout << "2--> REMOVE Flight" << endl;
        cin >> adminChoice;
        cin.ignore();
        
        



      }    
       
   

    }


        if (ask_user_choice == 3) {
            cout << "Exiting system." << endl;
            break;
        }

        if (ask_user_choice == 1) {
            string id, pass;
            cout << "Enter ID and password:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, id);
            getline(cin, pass);
            User user(id, pass);
            user.signUp();
        } else if (ask_user_choice == 2) {
            string login_id, login_pass;
            if (User::logInput(&login_id, &login_pass)) {
                cout << "Entered ID: " << login_id << endl;
                cout << "Entered PASS: " << login_pass << endl;
                User user(login_id, login_pass);
                user.authenticate();
            }
        }
    }
    return 0;
}
