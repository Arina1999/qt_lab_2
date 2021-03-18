#include <QCoreApplication>
#include <iostream>

#include "CppFactory.h"
#include "CsharpFactory.h"
#include "JavaFactory.h"

using namespace std;

string generateProgram(AbstractFactory* factory)
{
    string result;

    shared_ptr<ClassUnit> myClass(factory->CreateClassUnit("MyClass"));

    myClass->add(factory->CreateMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC);
    myClass->add(factory->CreateMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
    myClass->add(factory->CreateMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

    shared_ptr<MethodUnit> method = factory->CreateMethodUnit("testFunc4", "void", MethodUnit::STATIC);
    method->add(factory->CreatePrintOperator(R"(Hello, world!\n)"));
    myClass->add(method, ClassUnit::PROTECTED);

    result += myClass->compile() + '\n';
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            cout << generateProgram(make_shared<CppFactory>().get()) << endl;
            break;

        case 1:
            cout << generateProgram(make_shared<CsharpFactory>().get()) << endl;
            break;

        case 2:
            cout << generateProgram(make_shared<JavaFactory>().get()) << endl;
            break;

        default:
            continue;
        }
    }
    return a.exec();
}
