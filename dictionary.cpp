#include"dictionary.h"



bool Dictionary::insert(const std::string& key, const std::string& meaning , std::ostream& out)
{
    if (meaning.empty())
    {
       
        return false;
    }

    auto& meanings = items[key];
    auto result = meanings.insert(meaning);

    if (!result.second)
    {

        return false;
    }
    return true;
}


void Dictionary::search(const std::string& key, std::ostream& out) const
{

    auto it = items.find(key);
    if (it != items.end()) 
    {
        out << "Meanings of " << key << "':\n";
        const auto& meanings = it->second;
        for (const auto& meaning : meanings) 
        {
            out << "- " << meaning << '\n';
        }
    }
    else 
    {
        out << "No meanings found for '" << key << "'.\n";
    }
}


std::string Dictionary::translate(const std::string& sentence)
{
    std::string translation;
    std::string word;
    size_t sentenceLength = sentence.length();

    for (size_t i = 0; i < sentenceLength; i++)
    {
        char c = sentence[i];
        if (c == ' ' || i == sentenceLength - 1)
        {
            if (i == sentenceLength - 1)
            {

                word += c;
            }

            
            if (word == "is" || word == "the" || word == "to" || word == "a" || word == "am" || word == "are")
            {
                word.clear();
            }
           std::map<std::string, std::set<std::string>>::iterator it = items.find(word);
          // auto it = items.find(word);
            if (it != items.end())
            {
               translation += *(it->second.begin())+ ' ';
            }
            else
            {

                translation += word + ' ';
            }
            word.clear();
        }
        else 
        {
            word += c;
        }
    }

    return translation;
}



void Dictionary::deleteKey(const std::string& key, const std::string& meaning)
{
    auto it = items.find(key);
    if (it != items.end()) 
    {
        auto& meanings = it->second;
        meanings.erase(meaning);
        if (meanings.empty()) 
        {
            items.erase(it);
        }
    }
}

void Dictionary::deleteSubDictionary(const std::string& key)
{

    auto it = items.find(key);
    if (it != items.end()) 
    {
        items.erase(it);
    }   

}

bool Dictionary::deleteDictionary()
{
    if (!items.empty())
    {
        for (auto& item : items)
        {
            item.second.clear(); // std::set
        }
        items.clear(); // std::map
    
    }
    if (isItexist())
    {
        return false;
    }
    else
    {   
        return true;
    }
}

bool Dictionary::isItexist() const
{
    if (items.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}



void Dictionary::print(const std::string& key , std::ostream& out) const
{
    auto it = items.find(key);
    if (it != items.end())
    {
        out << "Meanings  '" << key << "':\n";
        const auto& meanings = it->second;
        for (const auto& meaning : meanings) {
            out << "- " << meaning << '\n';
        }
    }
    else 
    {
        out << "No meanings find for '" << key << "'.\n";
    }
}

void Dictionary::printDictionary(std::ostream& out) const
{

    if (items.empty())
    {
        out << "Dictionary is empty \n";
    }
    else
    {
        out << "Dictionary records: \n" << std::endl;
        for (const auto& entry : items) 
        {           
            out << "Key: \n  " << entry.first << "\n\nMeaning: \n ";
            for (const auto& value : entry.second) 
            {
                out << "->  " << value << "\n";
            }
            out << "\n" << std::endl;
        }

    }
}



void Dictionary::insertFromFile(const std::string& in , std::ostream& out)
{

    std::ifstream inputFile(in);
    if (!inputFile)
    {
        throw FailedToOpenFile();
    }

    std::istream_iterator<std::string> inputIter(inputFile);
    std::istream_iterator<std::string> endIter;

    while (inputIter != endIter)
    {
        sarp::input input;
        std::istringstream iss(*inputIter);
        if (!(iss >> input))
        {
           out << "Invalid input: " << *inputIter << std::endl;
            ++inputIter;
            continue;
        }
        insert(input.key, input.meaning, std::cout);
        
            
            ++inputIter;
    }


    inputFile.close();
}

