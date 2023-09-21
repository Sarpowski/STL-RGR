#ifndef DICTIONARY_H
#define DICTIONARY_H


#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<locale>
#include<set>
#include<ostream>
#include <sstream> 
#include <fstream>

#include"sarp.h"
#include"myException.h"

class Dictionary
{

public:
    Dictionary() = default;
    ~Dictionary() = default;
    
    Dictionary(const Dictionary& other) = default;
    Dictionary& operator=(const Dictionary& other) = default;

    Dictionary(Dictionary&&) = default;
    Dictionary& operator=(Dictionary&&) = default;

    bool insert(const std::string& key, const std::string& meaning, std::ostream& out);
    
    void deleteKey(const std::string& key, const std::string& meaning);//delete just one 
    
    void deleteSubDictionary(const std::string& key); //delete all the keys 
    
    bool deleteDictionary();
    
    std::string translate(const std::string& sentence);
    
    void insertFromFile(const std::string& in, std::ostream& out);
  
    bool isItexist() const ;
  
    void print(const std::string& key ,std::ostream& out) const;
    
    void printDictionary(std::ostream& out) const ;
    
    void search(const std::string& key ,std::ostream& out) const;
    
private:

    std::map<std::string, std::set<std::string>> items;

};




#endif // !DICTIONARY_H
