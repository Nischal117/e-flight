#include <iostream>
using namespace std;
#include <string>


int wincondition(char logicboard[3][3] , int i , bool* gamefinish)
    {
        
    
if(logicboard[0][0] == 'O' && logicboard[0][1] == 'O' && logicboard[0][2]== 'O')
    {
        cout << "P1 won 1" << endl;
        *gamefinish = true;
        return 0;
    }
    
else if(logicboard[1][0] == 'O' && logicboard[1][1] == 'O' && logicboard[1][2] == 'O')
    {
         cout << "P1 won 2" << endl;
        *gamefinish = true;
        return 0;
    }

else if(logicboard[2][0] == 'O' && logicboard[2][1] == 'O' && logicboard[2][2] == 'O')
    {
         cout << "P1 won 3" << endl;
        *gamefinish = true;
        return 0;
    }
else if(logicboard[0][0] == 'O' && logicboard[1][0] == 'O' && logicboard[2][0] == 'O')
    {
         cout << "P1 won 4" << endl;
        *gamefinish = true;
        return 0;
    }
    
    else if(logicboard[0][1] == 'O' && logicboard[1][1] == 'O' && logicboard[2][1] == 'O')
    {
         cout << "P1 won 5" << endl;
        *gamefinish = true;
        return 0;
    }
    
    else if(logicboard[0][2] == 'O' && logicboard[1][2] == 'O' && logicboard[2][2] == 'O')
    {
         cout << "P1 won 6" << endl;
        *gamefinish = true;
        return 0;
    }
    
else if(logicboard[0][0] == 'O' && logicboard[1][1] == 'O' && logicboard[2][2] == 'O')
    {
         cout << "P1 won 7" << endl;
        *gamefinish = true;
        return 0;
    }
    
    else if(logicboard[0][2] == 'O'&& logicboard[1][1] == 'O' && logicboard[2][0] == 'O')
    {
         cout << "P1 won 8" << endl;
        *gamefinish = true;
        return 0;
    }
    
//player 2 win condition


if(logicboard[0][0] == 'X' && logicboard[0][1] == 'X' && logicboard[0][2]== 'X')
    {
        cout << "P2 won 1" << endl;
        *gamefinish = true;
        return 0;
    }
    
else if(logicboard[1][0] == 'X' && logicboard[1][1] == 'X' && logicboard[1][2] == 'X')
    {
         cout << "P2 won 2" << endl;
        *gamefinish = true;
        return 0;
    }

else if(logicboard[2][0] == 'X' && logicboard[2][1] == 'X' && logicboard[2][2] == 'X')
    {
         cout << "P2 won 3" << endl;
        *gamefinish = true;
        return 0;
    }
else if(logicboard[0][0] == 'X' && logicboard[1][0] == 'X' && logicboard[2][0] == 'X')
    {
         cout << "P2 won 4" << endl;
        *gamefinish = true;
        return 0;
    }
    
    else if(logicboard[0][1] == 'X' && logicboard[1][1] == 'X' && logicboard[2][1] == 'X')
    {
         cout << "P2 won 5" << endl;
        *gamefinish = true;
        return 0;
    }
    
    else if(logicboard[0][2] == 'X' && logicboard[1][2] == 'X' && logicboard[2][2] == 'X')
    {
         cout << "P2 won 6" << endl;
        *gamefinish = true;
        return 0;
    }
    
else if(logicboard[0][0] == 'X' && logicboard[1][1] == 'X' && logicboard[2][2] == 'X')
    {
         cout << "P2 won 7" << endl;
        *gamefinish = true;
        return 0;
    }
    
    else if(logicboard[0][2] == 'X' && logicboard[1][1] == 'X' && logicboard[2][0] == 'X')
    {
         cout << "P2 won 8" << endl;
        *gamefinish = true;
        return 0;
    }    
    
   
 
    return 0;
}
    


/*
       int wincondition(char logicboard[3][3] , int i , bool* gamefinish)
            {
                int count = 0 , count2 = 0;
                int countp = 0 , countp2=0;
                
                
                for(int i = 0 ; i < 3 ; i++)
                    {
                     for(int j = 0 ; j < 3 ; j++)
                        {
                            
                    //p1 win condition
                           if(logicboard[i][j]=='O')
                            {
                              count++;
                              if(count == 3)
                                {
                                    cout << "P1 won" << endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                            }
                            else if(logicboard[j][i] == 'O')
                            {
                                count2++;
                                 if(count2 == 3)
                                {
                                    cout << "P1 won" << endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                            }
                            else if(logicboard[0][0] == 'O' && logicboard[1][1] == 'O' && logicboard[2][2] == 'O')
                                {
                                    cout << "P1 won" << endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                            else if(logicboard[0][2] == 'O' && logicboard[1][1] == 'O' && logicboard[2][0] == 'O')
                                {
                                    cout << "P1 won" << endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                                
                        //p2 win condition
                           else if(logicboard[i][j]=='X')
                            {
                              countp++;
                              if(countp == 3)
                                {
                                    cout << "P2 won" << endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                            }
                            else if(logicboard[j][i] == 'X')
                            {
                                countp2++;
                                 if(countp2 == 3)
                                {
                                    cout << "P2 won" << endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                            }
                            else if(logicboard[0][0] == 'X' && logicboard[1][1] == 'X' && logicboard[2][2] == 'X')
                                {
                                    cout << "P2 won" <<endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                            else if(logicboard[0][2] == 'X' && logicboard[1][1] == 'X' && logicboard[2][0] == 'X')
                                {
                                    cout << "P2 won" << endl;
                                    *gamefinish = true;
                                    return 0;
                                }
                            else
                            {
                                if(i == 9) 
                                    {
                                        cout << "Game ended in a draw." << endl;
                                        *gamefinish = true;;
                                        return 0;
                                    }
                        //        cout << "Next move" ;
                            }
                            
                        }
                            count = 0;
                            count2 = 0;
                            countp = 0;
                            countp2=0;
                        
                    }
                   
               return 0;
            }

*/




       void updatelogic(int move , char logicboard[3][3] , int i)
        {
        int x;
        int y;
        x = (move - 1)/3;
        y = (move - 1)%3;
        if(i%2 == 1)
            {
                logicboard[x][y] = 'O';
            }
        else
            {
                logicboard[x][y] = 'X';
            }
           
           
        }
       
        void showlogic(char logicboard[3][3])
        {
              for(int i = 0 ; i < 3 ; i++)
                {
                for(int j = 0 ; j < 3; j++)
                    {
                     cout << logicboard[i][j];    
                    }
                cout << endl;
                }
        }
       
       
       


    void logic(char logicboard[3][3] , int* label2)
        {
               for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 3; j++)
                    {
                       
                     logicboard[i][j] = *label2 + '0' ;
                     (*label2)++;
                           
                     
                    }
            }
        }



   void updateDisplay(char showboard[3][5])
         {
            for(int i = 0 ; i < 3 ; i++)
                {
                for(int j = 0 ; j < 5; j++)
                    {
                     cout << showboard[i][j];    
                    }
                cout << endl;
                }
         }
         
         
         

void update(int move ,char showboard[3][5] , int i)
    {
        int x;
        int y;
        x = (move - 1)/3;
        y = (move - 1)%3;
        if(y == 2) y = 4;
        if(y%2 == 1) y++;
        if(i%2 == 1)
            {
                showboard[x][y] = 'O';
            }
        else
            {
                showboard[x][y] = 'X';
            }
       
    }


void display(char showboard[3][5] , int* label)
    {
    //    cout << *label;
        for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 5; j++)
                    {
                        if(j%2 == 0)
                            {
                                showboard[i][j] = *label + '0' ;
                                (*label)++;
                            }
                        else
                            {
                                showboard[i][j] = '|';
                            }
                    }
            }
       
    }

int main() {
    
        bool gamefinish = false;
    
        char showboard[3][5];
        char logicboard[3][3];
        
       
        int label = 1;
        int label2 = 1;
       
        display(showboard , &label);
        logic(logicboard , &label2);

        string p1;
        string p2;
        
        cout << "Enter First Player Name : ";
        cin >> p1;
        cout << "Enter Second Player Name : ";
        cin >> p2;

        for(int i = 0 ; i < 3 ; i++)
                {
                for(int j = 0 ; j < 5; j++)
                    {
                     cout << showboard[i][j];    
                    }
                cout << endl;
                }

 
        int move;
        for(int i = 0 ; i < 9 ; i++)
            {
                
                
          
        if(i%2 == 0)
                {
                cout << p1 << " move : ";
                }
                else
                {
                cout << p2 << " move : ";
                }
                
                
                cin >> move ;
                
         
            
            
                update(move , showboard , i+1);
                updatelogic(move , logicboard , i+1);
               
               
                updateDisplay(showboard);
  //            cout << endl << "---" << endl;
   //           showlogic(logicboard);
                
               if (i >= 4)
               {
                   wincondition(logicboard , i+1 , &gamefinish);
               }
               
                if(gamefinish == true)
                {
                    
                    return 0;
                }
                
               
            }
            
        if(gamefinish == false) cout << "Game is Draw :)" << endl;
            


        return 0;
            }            

   
