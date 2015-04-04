#include <QCoreApplication>
#include <iostream>
#include "PolishNotationConverter.h"
#include "fstream"
#include "list.h"
void convertFileToFile(std::ifstream & input, std::ofstream &output);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout <<"Type filename with expressions\n";

    std::string inputFile, outputFile;
    std::cin>>inputFile;
    std::cout << "Type output filename\n";
    std::cin>> outputFile;
    std::ifstream ifs;
    std::ofstream ofs;

    ifs.open(inputFile, std::ios_base::in);
    ofs.open(outputFile, std::ios_base::out);
    convertFileToFile(ifs,ofs);
    ifs.close();
    ofs.close();



    return 0;
}

void convertFileToFile(std::ifstream & input, std::ofstream &output)
{
     std::string str;
     PolishNotationConverter conv;
    while (!input.eof())
    {
        std::getline(input, str);
        if (str!="")
        {
            std::cout<<"input: " <<str<<"\n";
            str=conv.convert(str);
            std::cout<<"output: " <<str<<"\n";
            output<< str<<"\n";
        }
    }

}
