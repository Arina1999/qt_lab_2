#ifndef JFACTORY_H
#define JFACTORY_H

#include "AbstractFactory.h"
#include "JavaClassUnit.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"

using namespace std;

class JavaFactory: public AbstractFactory
{
public:
    shared_ptr<ClassUnit> CreateClassUnit(const string& name) const
    {
        return shared_ptr<ClassUnit>(new JavaClassUnit(name));
    }

    shared_ptr<MethodUnit> CreateMethodUnit(const string& name, const string& returnType, Unit::Flags flags) const
    {
        return shared_ptr<MethodUnit>(new JavaMethodUnit(name, returnType, flags));
    }

    shared_ptr<PrintOperatorUnit> CreatePrintOperator(const string& text) const
    {
        return shared_ptr<PrintOperatorUnit>(new JavaPrintOperatorUnit(text));
    }
};
#endif // JFACTORY_H
