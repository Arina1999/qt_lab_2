#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "Unit.h"

#include <memory>
#include <string>
using namespace std;

class ClassUnit;
class MethodUnit;
class PrintOperatorUnit;

class AbstractFactory
{
public:
    virtual shared_ptr<ClassUnit> CreateClassUnit(const string& name) const = 0;

    virtual shared_ptr<MethodUnit> CreateMethodUnit(const string& name, const string& returnType, Unit::Flags flags) const = 0;

    virtual shared_ptr<PrintOperatorUnit> CreatePrintOperator(const string& text) const = 0;

    virtual ~AbstractFactory() {}
};

#endif // ABSTRACTFACTORY_H
