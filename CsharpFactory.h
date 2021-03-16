#ifndef CSHFACTORY_H
#define CSHFACTORY_H

#include "AbstractFactory.h"
#include "CsharpClassUnit.h"
#include "CsharpMethodUnit.h"
#include "CsharpPrintOperatorUnit.h"

class CsharpFactory: public AbstractFactory
{
public:
    shared_ptr<ClassUnit> CreateClassUnit(const string& name) const
    {
        return shared_ptr<ClassUnit>(new CsharpClassUnit(name));
    }

    shared_ptr<MethodUnit> CreateMethodUnit(const string& name, const string& returnType, Unit::Flags flags) const
    {
        return shared_ptr<MethodUnit>(new CsharpMethodUnit(name, returnType, flags));
    }

    shared_ptr<PrintOperatorUnit> CreatePrintOperator(const string& text) const
    {
        return shared_ptr<PrintOperatorUnit>(new CsharpPrintOperatorUnit(text));
    }
};

#endif // CSHFACTORY_H
