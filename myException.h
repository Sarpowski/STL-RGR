#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <exception>

class UnkownCommand : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "Unkown Command";
    }
};

class InvalidInput  : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "Invalid input: ";
    }
};


class InvalidChoice : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "Invalid choice: ";
    }
};


class EnglishInput : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "Invalid input. English word expected: ";
    }
};


class RussianInput : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "Invalid input. Russian input expected: ";
    }
};

class FailedToOpenFile : public std::exception
{
public:
    virtual const char* what() const throw() {
        return "Failed to open file ";
    }
};

#endif // !MYEXCEPTIONS_H
