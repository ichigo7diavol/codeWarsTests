/*
This kata is the first of a sequence of four about "Squared Strings".

You are given a string of n lines, each substring being n characters long: For example:

s = "abcd\nefgh\nijkl\nmnop"

We will study some transformations of this square of strings.

Vertical mirror: vert_mirror (or vertMirror or vert-mirror)
vert_mirror(s) => "dcba\nhgfe\nlkji\nponm"
Horizontal mirror: hor_mirror (or horMirror or hor-mirror)
hor_mirror(s) => "mnop\nijkl\nefgh\nabcd"
or printed:

vertical mirror   |horizontal mirror   
abcd --> dcba     |abcd --> mnop 
efgh     hgfe     |efgh     ijkl 
ijkl     lkji     |ijkl     efgh 
mnop     ponm     |mnop     abcd
#Task:

Write these two functions
and

high-order function oper(fct, s) where

fct is the function of one variable f to apply to the string s (fct will be one of vertMirror, horMirror)
#Examples:

s = "abcd\nefgh\nijkl\nmnop"
oper(vert_mirror, s) => "dcba\nhgfe\nlkji\nponm"
oper(hor_mirror, s) => "mnop\nijkl\nefgh\nabcd"
Note:
The form of the parameter fct in oper changes according to the language. You can see each form according to the language in "Sample Tests".

Bash Note:
The input strings are separated by , instead of \n. The ouput strings should be separated by \r instead of \n. See "Sample Tests".

Forthcoming katas will study other tranformations.
*/

#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>

class Opstrings
{
public:
    static std::string vertMirror(const std::string &input) 
    {
      std::stringstream str(input);
      std::string result;
      std::string buf;
      
      if (!std::getline(str, buf)) 
        return "";
      else {
        std::reverse(buf.begin(), buf.end());
        result.append(buf);
      }
      
      for (; std::getline(str, buf);)
      {
        std::reverse(buf.begin(), buf.end());
        result.append("\n").append(buf);
      }    
      
      return result;
    }
    
	  static std::string horMirror(const std::string &input) 
    {
      std::stringstream str(input);
      std::string result;
      std::string buf;
      
      if (!std::getline(str, buf)) 
        return "";
      else 
        result.insert(0, buf);
      
      for (; std::getline(str, buf);)
        result.insert(0, "\n").insert(0, buf);   
    
      return result;    
    }
    
    // your high order function oper
    //... oper(...);
    template <typename Func>
    static std::string oper(Func f, const std::string &s) 
    {
      return f(s);
    }

};