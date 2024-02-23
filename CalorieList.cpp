// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 7th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>

#include "cstring.h"
//#include "Food.h"
#include "CalorieList.h"

using namespace std;

namespace sdds
{
    
    
    int CalorieList::totalNumOfCal() const
    {
        int TotalNum = 0;
        int x;

        for (x = 0; x < m_noOfItems; x++)
        {
            TotalNum += m_items[x].calories();
        } return TotalNum;
    }

    
    void CalorieList::Title() const 
    {
        cout << "+----------------------------------------------------+" << endl;

        if (isValid()) 
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }

        else 
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    
    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;

        if (isValid())
        {
            cout << "|    Total Calories for today:";

            cout.width(9);
            cout << right << totalNumOfCal();

            cout << " | ";

            cout.width(12);
            cout << setfill(' ');

            cout << " |" << endl;
        }

        else 
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    
    void CalorieList::setEmpty() 
    {
        m_items = nullptr;
    }

    
    bool CalorieList::isValid() const 
    {
        bool valid = true;
        int x;

        valid = m_items != nullptr;

        for (x = 0; valid == true && x < m_noOfItems; x++)
        {
            valid = valid && m_items[x].isValid();
        } return valid;
    }

    
    void CalorieList::init(int size)
    {
        if (size < 1)
        {
            m_noOfItems = 0;
            m_itemsAdded = 0;
        }

        else 
        {
            m_noOfItems = size;
            m_itemsAdded = 0;
            m_items = new Food[m_noOfItems];

            int x;

            for (x = 0; x < m_noOfItems; x++)
            {
                m_items[x].setEmpty();
            }
        }
    }

    
    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        if (m_itemsAdded < m_noOfItems) 
        {
            m_items[m_itemsAdded].set(item_name, calories, when);
            m_itemsAdded++;

            return true;
        } return false;
    }

    
    void CalorieList::display() const
    {
        Title();

        int x;

        for (x = 0; x < m_noOfItems; x++)
        {
            m_items[x].display();
        }

        footer();
    }

    
    void CalorieList::deallocate()
    {
        delete[] m_items;
        //m_items = nullptr;
    }
}
