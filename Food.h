// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 7th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds
{
  class Food 
  {
    char FoodName[31];
    int calNUM;
    int Consumetime;
    
    void setName(const char* name);

    public:
        void setEmpty();
        void set(const char* Fname, int calories, int time);
        void display()const;
    
        bool isValid()const;
        int calories()const;
  };
}
#endif //!SDDS_FOOD_H_
