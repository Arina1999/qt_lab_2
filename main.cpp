#include <QCoreApplication>
#include <iostream>

#include "CppFactory.h"
#include "CsharpFactory.h"
using namespace std;

string generateProgram()
{
    string result;
    AbstractFactory* factory;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            factory = new CppFactory(); break;
        case 1:
            factory = new CsharpFactory(); break;
        default:
            continue;
        }
        shared_ptr<ClassUnit> myClass(factory->CreateClassUnit("MyClass"));

        myClass->add(factory->CreateMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC);

        myClass->add(factory->CreateMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);

        myClass->add(factory->CreateMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

        shared_ptr<MethodUnit> method = factory->CreateMethodUnit("testFunc4", "void", MethodUnit::STATIC);

        method->add(factory->CreatePrintOperator(R"(Hello, world!\n)"));

        myClass->add(method, ClassUnit::PROTECTED);

        result += myClass->compile() + '\n';

        delete factory;
    }
    return result;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << generateProgram() << endl;

    return a.exec();
}
