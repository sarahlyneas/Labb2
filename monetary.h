/*
 * FILNAMN:       Monetary.h
 * LABORATION:    2
 * PROGRAMMERARE: Sarah Sundberg 930906-5028 Y3.c
 *                Ebba Grundin 941222-7283 Y3.c
 * DATUM:         2015-10-07
 */

#ifndef monetary_h
#define monetary_h 

#include <iosfwd>
#include <string>
#include <stdexcept>


namespace Monetary
{

class monetary_error : public std::logic_error
  {

  public:
    explicit monetary_error(const std::string& what_arg) noexcept
      : std::logic_error{what_arg} {}

    explicit monetary_error(const char* what_arg) noexcept
      : std::logic_error{what_arg} {}

  };

  class Money
  {

  public:

    Money() = default;
    explicit Money (const std::string& valuta, int enhet=0, int hundradel=0);
    explicit Money (int enhet, int hundradel=0); 

    void print (std::ostream& os) const;

    Money& operator++ ();

    Money operator++ (int);



    std::string currency() const;


 
    friend std::ostream& operator << (std::ostream& os, const Money& other);

    bool operator == (const Money& other) const;
    bool operator != (const Money& other) const;
    bool operator >= (const Money& other) const;
    bool operator <= (const Money& other) const;
    bool operator < (const Money& other) const;
    bool operator > (const Money& other) const;
    Money& operator = (const Money& other) &;

  Money operator + (const Money& other) const;

	  

  private:
  

    void kontroll (const std::string& valuta, int enhet, int hundradel) const;
    void same_currency (const Money& other) const;
    std::string type{""}; 
    int tens{};
    int hundreds{};


  
  };



  std::ostream& operator << (std::ostream& os, const Money& other);

}
#endif
