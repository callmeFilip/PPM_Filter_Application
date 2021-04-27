#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

/**
 * ConsoleInterface.h
 * Console interface responsible for user interaction.
*/

#include "Runner.h"

#include <string>

class ConsoleInterface
{
private:
    static ConsoleInterface m_instance;

    Runner m_runner;

    std::string m_command;
    std::string m_inputFile;
    std::string m_outputFile;
    int m_filterID;

    ConsoleInterface() : m_runner(), m_command(""), m_inputFile(""), m_outputFile(""), m_filterID(0) {}
    ConsoleInterface(const ConsoleInterface &);
    void operator=(ConsoleInterface const &);

    void printMenu() const;
    void printFilterCatalog() const;
    void clearInput();
    void run(std::string &inputFile, std::string &outputFile, int &filterID) const;

public:
    ~ConsoleInterface();

    static ConsoleInterface *getInstance() { return &m_instance; }
    void listen();
};

#endif // CONSOLEINTERFACE_H
