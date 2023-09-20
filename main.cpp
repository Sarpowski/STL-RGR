#include <sstream> 
#include <fstream>
#include <iostream>
#include "dictionary.h"
#include <locale.h>

#include "sarp.h"
#include "myException.h"

void commands()
{
    Dictionary UserTestTree;
    int command;
    std::string key;
    std::string meaning;
    std::string sentence;

    bool userWantsToDoSomeTests = true;
    
    sarp::information(std::cout);
    
    while (userWantsToDoSomeTests)
    {
        try
        {

            std::cin >> command;
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "try again Wrong type of input " << std::endl;
                continue;
            }


            if (command == 1)
            {
                std::cout << "You choose insert" << std::endl;
                std::cout << "Enter your English word: ";
                std::cin >> key;
                if (!std::cin || !sarp::isLatin(key))
                {

                    
                    throw InvalidInput();
                }
                std::cout << "Enter the Russian translation: ";
                std::cin.ignore();  
                std::getline(std::cin, meaning);
               // if (!std::cin || !sarp::isCyrillic(meaning)) // TR-US windows 10  problem
                if (sarp::isInteger(meaning))
                {
                    throw RussianInput();
                }
                UserTestTree.insert(key, meaning, std::cout);

            }
            else if (command == 2)
            {
                std::cout << "You choose delete" << std::endl;
                std::cout << "Enter the English word to delete: ";
                std::cin >> key;
                if (!std::cin || !sarp::isLatin(key))
                {
                   
                    throw EnglishInput();

                }
                std::cout << "Enter the Russian word to delete: ";
                std::cin >> meaning;
                if (!std::cin || !sarp::isCyrillic(meaning))
                {
                  
                    throw EnglishInput();
                }
                UserTestTree.deleteKey(key, meaning);

            }
            else if (command == 3)
            {
                std::cout << "You choose delete subdictionary" << std::endl;
                std::cout << "Enter the English word to Delete all the meanings: ";
                std::cin >> key;
                if (!std::cin || !sarp::isLatin(key))
                {

                    throw EnglishInput();
                }
                UserTestTree.deleteSubDictionary(key);
                UserTestTree.print(key, std::cout);


            }
            else if (command == 4)
            {
                std::cout << "You choose search" << std::endl;
                std::cout << "Enter the English word to search: ";
                std::cin >> key;
                if (!std::cin || !sarp::isLatin(key))
                {
                   
                    throw EnglishInput();
                }
                UserTestTree.search(key, std::cout);

            }
            else if (command == 5)
            {
                std::cout << "You choose translate" << std::endl;
                std::cout << "Enter the English sentence to translate: ";
                std::cin.ignore();  
                std::getline(std::cin, sentence);

                if (!sarp::isLatin(sentence))
                {
                    std::cout << "And  ";
                    std::cerr << "Invalid input. English sentence expected. here " << std::endl;
                    continue;
                }
                std::string translation = UserTestTree.translate(sentence);
                if (!translation.empty())
                {
                    std::cout << "Translation: " << translation << std::endl;
                }
                else
                {
                    std::cout << "Translation not found." << std::endl;
                }
            }

            else if (command == 6)
            {
                std::cout << "You choose print word" << std::endl;
                std::cout << "Enter the English word to print: ";
                std::cin >> key;
                if (!std::cin || !sarp::isLatin(key))
                {
                    
                    throw EnglishInput();
                }
                UserTestTree.print(key, std::cout);
            }
            else if (command == 7)
            {
                std::cout << "You choose print dictionary" << std::endl;
                UserTestTree.printDictionary(std::cout);
            }
            else if (command == 8)
            {

                sarp::information(std::cout);
            }
            else if (command == 9)
            {

                UserTestTree.insertFromFile("input.txt", std::cout);

                sarp::information(std::cout);


            }
            else if (command == 10)
            {
                std::cout << "You choose Delete Dictionary \n";
                UserTestTree.deleteDictionary(std::cout);

            }
            else if (command == 11)
            {
                std::cout << "Exiting the program." << std::endl;
                userWantsToDoSomeTests = false;
            }
            else
            {
                throw InvalidChoice();
                
            }
        }
        catch (const std::exception& a)
        {
            std::cerr << a.what() << std::endl;
        }
    }


}



void test()
{
    Dictionary dictionary;

    dictionary.insertFromFile("input.txt", std::cout);
    
     const std::string hello = "hello world hello";




    dictionary.printDictionary(std::cout);


    std::cout << "translate \n \n";
    std::cout << dictionary.translate(hello)<<std::endl;

    dictionary.deleteDictionary(std::cout);
    dictionary.printDictionary(std::cout);
    std::cout<< std::endl;
}





int main()
{
    std::setlocale(LC_ALL, "rusça");

    bool UserTEST = true;
    std::string command = "";
    Dictionary UserTestTree;
    

        while (UserTEST)
        {
            try
            {

                std::cout << "Test condition or User Test \n";
                std::cout << "Test 1 \n";
                std::cout << "User Test 2 \n";
                std::cout << "Exit 3 \n";
                std::cin >> command;
                if (command == "1")
                {
                    test();
                }
                else if (command == "2")
                {
                    commands();
                }
                else if (command == "3")
                {
                    UserTEST = false;
                    continue;
                }
                else
                {
                    throw UnkownCommand();
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }

        }



   


    return 0;

}