/*
 * FILNAMN:       Monetary.cc
 * LABORATION:    2
 * PROGRAMMERARE: Sarah Sundberg 930906-5028 Y3.c
 *                Ebba Grundin 941222-7283 Y3.c
 * DATUM:         2015-10-07
 */

#include "monetary.h"
#include <iostream>

using namespace std;
using namespace Monetary;

int main()
{
  
  Money ebba{"FFR", 100, 50};                     
  Money sarah{"SEK", 100, 50};    
  Money ebbacopy{ebba};
  Money empty;           


  cout << "Ebba och Sarahs bankkonton utskrivet med operator << :" << endl;
  cout << "Ebba: " << ebba << endl;
  cout << "Sarah: " << sarah << endl;
  cout << "Tomma kontot utskrivet med print:" << endl;
  empty.print(cout);
 

  try
    { 
      cout << "Kollar om Ebba och Sarah har lika mycket pengar." << endl;
      if (ebba == sarah)
	{
	  cout << "Lika mycket pengar!" << endl;
	}
      else 
	{
	  cout << "Ej lika mycket pengar!" << endl;
	}
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }

  try
    { 
      cout << "Kollar om Ebba och Ebbas kopia är lika efter postfix stegning" << endl;
      if (ebba == ebbacopy++)
	{
	  cout << "Bankkontona är lika" << endl;
	}
      else
	{
	  cout << "Bankkontona är olika" << endl;
	}
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }

  try
    { 
      cout << "Kollar om Ebba och Ebbas kopia är lika efter prefix stegning" << endl;
      if (ebba == ++ebbacopy)
	{
	  cout << "Bankkontona är lika" << endl;
	}
      else
	{
	  cout << "Bankkontona är olika" << endl;
	}
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }
   
 try
    { 
      cout << "Har Ebba mer pengar än Sarah? " << endl;
      if (ebba <= sarah)
	{
	  cout << "Ebba har inte mer pengar än Sarah" << endl;
	}
      else 
	{
	  cout << "Ebba har mer pengar än Sarah" << endl;
	}
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }

 try
    { 
      cout << "Har Ebba mindre pengar än Sarah? " << endl;
      if (ebba >= sarah)
	{
      cout << "Ebba har inte mindre pengar än Sarah" << endl;
	}
      else 
	{
      cout << "Ebba har mindre pengar än Sarah" << endl;
	}
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    } 

try
    { 
      cout << "Adderar Ebbas konto med Ebbas kopiakonto " << endl;
      ebba = ebba + ebbacopy;
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }

 try
    { 
      cout << "Har Ebba mer pengar än Ebbas kopiakonto? " << endl;
      if (ebba <= ebbacopy)
	{
	  cout << "Ebba har inte mer pengar än kopiakontot" << endl;
	}
      else 
	{
	  cout << "Ebba har mer pengar än kopiakontot" << endl;
	}
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }

 cout << "Skapar några objekt med fel: " << endl;
 try
    { 
      Money fel1{"SWEFR", 0, 0};
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }
 try
    { 
      Money fel2{"SWE", -1, 0};
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }
 try
    { 
      Money fel3{"SWE", 0, 100};
    }
  catch (const monetary_error& error)
    {
      cout << error.what() << endl;
    }

  return 0;

}
 
