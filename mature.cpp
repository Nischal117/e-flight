#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <limits>


using namespace std;

 class User {
 private: 
    string username;
    string password;

 public:
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
    cout << username << "," << password << "\n";
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




int main() {
    while (true) {
        cout << "\nE-Flight Reservation System" << endl;
        cout << "1--> SignUp" << endl;
        cout << "2--> LogIn" << endl;
        cout << "3--> Exit" << endl;

        int ask_user_choice;
        cout << "Enter your choice (1-3): ";
        while (!(cin >> ask_user_choice) || ask_user_choice < 1 || ask_user_choice > 3) {
            cout << "Invalid choice. Enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
