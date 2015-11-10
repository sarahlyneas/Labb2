/*
 * FILNAMN:       Monetary.cc
 * LABORATION:    2
 * PROGRAMMERARE: Sarah Sundberg 930906-5028 Y3.c
 *                Ebba Grundin 941222-7283 Y3.c
 * DATUM:         2015-10-07
 */

#include <utility>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "monetary.h"

using namespace std;

namespace Monetary
{

  Money:: Money(const std::string& valuta, int enhet, int hundradel) : type{valuta}, tens{enhet}, hundreds{hundradel} 
    {
      kontroll(valuta, enhet, hundradel);
    }

  Money:: Money(int enhet, int hundradel) : Money{"", enhet, hundradel}  {}


  void Money::kontroll (const string& valuta, int enhet, int hundradel) const
  {
    if (valuta.length() != 3)
      {
	if (valuta != "")
	  {
	    throw monetary_error {"Ej rätt längd på valutanamn"};
	  }
      }
 
    if (enhet < 0)
      { 
	throw monetary_error {"Ogiltigt värde på enhetsvärdet"};
      }
 
    if ((hundradel < 0) || (hundradel > 99))
      {
	throw monetary_error {"Ogiltigt värde på hundradelen"};
      }
  }

 
  void Money:: print (ostream& os) const 
  {
    os << type;

    if (hundreds < 10)
      {
	os << ' ' << tens << "." << "0"  << hundreds;
      }
  
    else 
      {
	os << ' ' << tens << "."  << hundreds;
      }
  }

  Money& Money:: operator ++ ()
  {
    hundreds = hundreds + 1;
    if (hundreds > 99)
      {
	tens = tens + 1;
	hundreds = hundreds - 100;
      }
    return *this;
  }
 
  Money Money:: operator ++ (int)
  {
    Money temp (*this);
    ++(*this);
    return temp;
  }
 


  string Money:: currency() const {return type;}

  Money& Money:: operator = (const Money& other) &
  {
    same_currency (other);   
    if (type == "")
      {
	type = other.currency();
	tens = other.tens;
	hundreds = other.hundreds;
      }
    else
      {
	tens = other.tens;
	hundreds = other.hundreds;
      }
    return *this;
  } 

  void Money ::same_currency (const Money& other) const
  {
    if ((type != "") && (other.currency() != ""))
      {      
	if (type != other.currency())
	  {
	    throw monetary_error {"Olika valutor"};
	  }
      }
  }


  bool Money:: operator == (const Money& other) const
  {
    same_currency(other);
    return ((tens == other.tens) && (hundreds == other.hundreds));
  }

  bool Money:: operator != (const Money& other) const
  {
    return not(*this == other);
  }

  bool Money:: operator >= (const Money& other) const
  {
    return not ((*this < other) || (*this == other));
  }

  bool Money:: operator <= (const Money& other) const
  {
    return ((*this < other) || (*this == other));
  }

  bool Money:: operator < (const Money& other) const
  {
    same_currency(other);
    if (tens < other.tens)
      {
	return true;
      }
    return ((tens == other.tens) && (hundreds < other.hundreds));
  }

  bool Money:: operator > (const Money& other) const
  {
    same_currency(other);
    if (tens < other.tens)
      {
	return false;
      }
    else if (not ((tens == other.tens) && (hundreds < other.hundreds))) 
      {
	return true;
      }
    else
      {
	return false;
      }
  }



  Money Money:: operator + (const Money& other) const
  {
    Money temp{};
    string temp1;
    int temp2;
    int temp3;

    same_currency(other);
    
    if (currency() == "")
      {
	temp1 = other.currency();
        temp2 = tens + other.tens;
        temp3 = hundreds + other.hundreds;
      }
    else
      {
        temp1 = currency();
	temp2 = tens + other.tens;
        temp3 = hundreds + other.hundreds;
      }

    if (temp3 > 99)
      {
        temp2 = temp2 + 1;
        temp3 = temp3 - 100;
      }

    return Money{temp1, temp2, temp3};

  } 
	

  ostream& operator << (ostream& os, const Money& other)
  {
    other.print(os);
    return os;
  }
}


