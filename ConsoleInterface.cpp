#include "ConsoleInterface.h"
#include "AllFilters.h"

#include <iostream>

ConsoleInterface ConsoleInterface::m_instance;

ConsoleInterface::~ConsoleInterface()
{
    std::cout << "Exiting..." << std::endl;
}

void ConsoleInterface::printMenu() const
{
    std::cout << "Avalable Commands: \n"
              << "RUN -> Activates the run sequence. \n"
              << "END -> Exits the program. \n"
              << "DISPLAY -> Activates file opening sequence. ( Unavailable )"
              << std::endl;
}

void ConsoleInterface::printFilterCatalog() const
{
    std::cout << "Filter Catalog: \n"
              << "[1] Sharpen \n"
              << "[2] Gaussian blur 3x3 \n"
              << "[3] Gaussian blur 5x5"
              << std::endl;
}

void ConsoleInterface::clearInput()
{
    m_command = "";
    m_inputFile = "";
    m_outputFile = "";
    m_filterID = 0;
    std::cin.clear();
}

void ConsoleInterface::run(std::string &inputFile, std::string &outputFile, int &filterID) const
{
    switch (filterID)
    {
    case 1:
        m_runner.run(inputFile, outputFile, Filter_Sharpen::getInstance());
        break;
    case 2:
        m_runner.run(inputFile, outputFile, Filter_Gaussian_Blur_3x3::getInstance());
        break;
    case 3:
        m_runner.run(inputFile, outputFile, Filter_Gaussian_Blur_5x5::getInstance());
        break;
    default:
        std::cout << "Invalid filter!" << std::endl;
        break;
    }
}

void ConsoleInterface::listen()
{
    std::cout << "Program initialized..." << std::endl;
    do
    {
        printMenu();

        std::cin >> m_command;

        if (!m_command.compare("END"))
        {
            break;
        }
        else if (!m_command.compare("RUN"))
        {
            std::cout << "Input: \n{InputFile.ppm} {OutputFile.ppm}" << std::endl;

            std::cin >> m_inputFile >> m_outputFile;

            std::cout << "Choose FilterID: " << std::endl; // ! If int and string input is in one line the std::cin bugs
            std::cin >> m_filterID;

            run(m_inputFile, m_outputFile, m_filterID);
        }

        clearInput();

    } while (true);
}
