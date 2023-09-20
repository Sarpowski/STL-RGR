#ifndef SARP_H
#define SARP_H


#include<map>
#include<list>
#include<string>
#include<iostream>
#include<algorithm>
#include<locale>

#include<ostream>
#include <sstream> 
#include <fstream>




namespace sarp
{

   static void information(std::ostream& out)
   {
       out << "\n";
       out << "You choose info" << std::endl;
       out << "insert: 1" << std::endl;
       out << "delete: 2" << std::endl;
       out << "delete sub dictionary: 3" << std::endl;
       out << "search: 4" << std::endl;
       out << "translate: 5" << std::endl;
       out << "print word: 6" << std::endl;
       out << "print dictionary: 7" << std::endl;
       out << "info: 8" << std::endl;
       out << "Take Dictionary From file: 9" << std::endl;
       out << "Delete Dictionary : 10" << std::endl;
       out << "exit: 11" << std::endl;
       out << "\n";
    }

    static bool isLatin(const std::string& str)
    {
        for (char c : str)
        {
            
            if (!isalpha(c) && c !=' ')
            {
                return false;
            }
        }
        return true;
    }

    static bool isCyrillic(const std::string& str)
    {
        std::locale loc("ru");
        for (char c : str)
        {

            if (!iswalpha(c) && !isalnum(c))
            {
                return false;
            }
        }
        return true;
    }

    static bool isInteger(const std::string& s)
    {
        try
        {
            std::stoi(s);
            return true;
        }
        catch (const std::invalid_argument& e)
        {
            return false;
        }
        catch (const std::out_of_range& e)
        {
            return false;
        }
    }

    struct input
    {
        std::string key , meaning;
        
        friend std::istream& operator>>(std::istream& in, input& input)
        {
            in >> std::ws;
            if (in.get() != '(')
            {
                in.setstate(std::ios::failbit);
                return in;
            }

            in >> std::ws;
            if (in.peek() == '\n')
            {
                in.setstate(std::ios::failbit);
                return in;
            }

            std::getline(in, input.key, '=');
            if (in.fail() || !isLatin(input.key))
            {
                in.setstate(std::ios::failbit);
                return in;
            }

            in >> std::ws;
            if (in.peek() == '\n')
            {
                in.setstate(std::ios::failbit);
                return in;
            }

            std::getline(in, input.meaning, ')');
            if (in.fail() || isCyrillic(input.meaning))
            {
                in.setstate(std::ios::failbit);
                return in;
            }

            return in;
        }

        friend std::ostream& operator<<(std::ostream& out, const input& data)
        {
            out << '(' << data.key << "; " << data.meaning << ')';
            return out;
        }
      
    };

  


}





#endif // !SARP_H

