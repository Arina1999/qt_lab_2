#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "AbstractFactory.h"
#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

class CppFactory: public AbstractFactory
{
public:
    shared_ptr<ClassUnit> CreateClassUnit(const string& name) const
    {
        return shared_ptr<ClassUnit>(new CppClassUnit(name));
    }

    shared_ptr<MethodUnit> CreateMethodUnit(const string& name, const string& returnType, Unit::Flags flags) const
    {
        return shared_ptr<MethodUnit>(new CppMethodUnit(name, returnType, flags));
    }

    shared_ptr<PrintOperatorUnit> CreatePrintOperator(const string& text) const
    {
        return shared_ptr<PrintOperatorUnit>(new CppPrintOperatorUnit(text));
    }
};

#endif // CPPFACTORY_H
