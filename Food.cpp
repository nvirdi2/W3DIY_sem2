// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 7th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>

#include "cstring.h"
#include "Food.h"

using namespace std;

namespace sdds
{

  
  int Food::calories() const 
  {
    return calNUM;
  }


  void Food::display() const
  {

    if (isValid()) 
    {
        cout << "| ";
        
      cout.width(30);
      cout << left << setfill('.') << FoodName;
      
        cout << " | ";
        
      cout.width(4);
      cout << left << setfill(' ');
      cout << right << calNUM;
      
        cout << " | ";
        
      cout.width(10);

      if (Consumetime == 1)
      {
        cout << left << "Breakfast";
      }

        else if (Consumetime == 2)
        {
          cout << left << "Lunch";
        }

          else if (Consumetime == 3)
          {
            cout << left << "Dinner";
          }

            else if (Consumetime == 4)
            {
              cout << left << "Snack";
            }

        cout << right << setfill(' ');
        
        cout << " |" << endl;

    }
      else 
      {
        cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
      }
  }


  bool Food::isValid() const
  {
    return (FoodName[0] != '\0' &&
               Consumetime >= 1 && Consumetime <= 4);
  }


  void Food::set(const char* Fname, int calories, int time){
   
        if (calories < 0 || Fname == nullptr)
        {
            setEmpty();
        }

        else
        {
          setName(Fname);
          
          calNUM = calories;
          
          Consumetime = time;
        }
    }


  void Food::setEmpty() 
    {
      FoodName[0] = '\0';
      
      calNUM = 0;
      
      Consumetime = 0;
    }


  void Food::setName(const char* name)
  {
    strCpy(FoodName, name);
    
    FoodName[30] = '\0';
  }
}

