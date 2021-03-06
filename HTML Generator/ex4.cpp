#include <iostream>
#include <ctime>
#include <cstdlib> 

using namespace std;

// Function Declarations
void tophalf ();
void bottomhalf();
string hexgen();
void middlehalf();

// Main Function

int main ()
{
   
   srand(time(0)); 
   
   tophalf();
   
   middlehalf();
   
   bottomhalf();

}

// Function Definitions

// Generates top half of HTML skeleton.

void tophalf ()
{
   cout << "<html>" << endl;
   cout << "   <head>" << endl;
   cout << "      <title>Assignment 1 Exercise 2</title>" << endl;
   cout << "   </head>" << endl;
   cout << "   <body>" << endl;
   cout << "   <ol>" << endl;
}

// Generates bottom half of HTML skeleton.

void bottomhalf()
{
   cout << "   </ol>" << endl;
   cout << "   </body>" << endl;
   cout << "</html>" << endl;
}

// string hexgen() randomly generates a hex code containing 6 characters, which are either 0 through 9 or A through F. It stores this data in a string, which is what is returned when the function is called. 

string hexgen()
{        
         string hex;
         string randomchar;
         
         for (int x =0; x < 6; ++x) 
         { 
            int n = rand() % 16;
      
            if (n == 15) 
            {
               hex = "F";
            }
      
            else if (n == 14) 
            {  
               hex = "E";
            }
      
            else if (n == 13) 
            {
               hex = "D";
            }
           
            else if (n == 12) 
            {
               hex = "C";
            }      
      
            else if (n == 11) 
            {
               hex = "B";
            }      
      
            else if (n == 10) 
            {
               hex = "A";
            }
                  
            else if (n == 9)
            {
               hex = "9";
            }
                 
            else if (n == 8)
            {
               hex = "8";
            }            
            
            else if (n == 7)
            {
               hex = "7";
            }            
            
            else if (n == 6)
            {
               hex = "6";
            }
            
            else if (n == 5)
            {
               hex = "5";
            }            
            
            else if (n == 4)
            {
               hex = "4";
            }            
            
            else if (n == 3)
            {
               hex = "3";
            }         
            
            else if (n == 2)
            {
               hex = "2";
            }            
            
            else if (n == 1)
            {
               hex = "1";
            }

            else if (n == 0)
            {
               hex = "0";
            }           
            
            randomchar = randomchar + hex;
         
         }
         
         return randomchar;
        
}
      
// middlehalf() generates each row of the HTML ordered list, including the hexcodes, which are generated by calling hexgen(). 

void middlehalf()
{
   string hexcode;
   
   for(int i = 0; i < 100; ++i)
      {      
         hexcode = hexgen(); 
      
         cout << "      <li style=\"color: #";
         cout << hexcode; 
         cout << "\">";
         cout << hexcode; 
         cout << "</li>" << endl;
      }
}
