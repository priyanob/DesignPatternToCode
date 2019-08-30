#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class CodeGenerator
{
public:
    enum eFunction_Visibility
    {
        eFunction_Visibility_Public,
        eFunction_Visibility_Private,
        eFunction_Visibility_Protected
    };

    CodeGenerator();

    void generate();
    class Function;
    class Class
    {
    public:

        Class(const std::string & ClassName)
        {
            mClassName = ClassName;
        }

        ~Class();

        weak_ptr<CodeGenerator::Function> addPrivateFunction( std::string  FunctionName);
        weak_ptr<CodeGenerator::Function> addPublicFunction( std::string  FunctionName);
        weak_ptr<CodeGenerator::Function> addProtectedFunction( std::string  FunctionName);

        std::string getClassName();
        std::vector<string> getAllPrivateFunctionsAsString();
        std::vector<shared_ptr<CodeGenerator::Function>> getAllPrivateFunctions();

        std::vector<string> getAllPublicFunctionsAsString();
        std::vector<shared_ptr<CodeGenerator::Function>> getAllPublicFunctions();

        std::vector<string> getAllProtectedFunctionsAsString();
        std::vector<shared_ptr<CodeGenerator::Function>> getAllProtectedFunctions();

        void addBaseClasses(std::vector<shared_ptr<Class>> BaseClasses);
        void addBaseClass(shared_ptr<Class> BaseClass);
        std::vector<string> getAllBaseClasses();
    private:
        void setFunctionToClass(eFunction_Visibility visibility, shared_ptr<Function> fnc);
        void addFunction(eFunction_Visibility visibility, shared_ptr<Function> fnc)
        {
            switch (visibility) {
            case eFunction_Visibility_Private:
                mPvtFunctionVector.push_back(fnc);
                break;

            case eFunction_Visibility_Protected:
                mProtFunctionVector.push_back(fnc);
                break;

            case eFunction_Visibility_Public:
                mPubFunctionVector.push_back(fnc);
                break;
            default:
                break;
            }
        }

        std::string mClassName;
        std::vector<shared_ptr<CodeGenerator::Function>> mPvtFunctionVector;
        std::vector<shared_ptr<CodeGenerator::Function>> mPubFunctionVector;
        std::vector<shared_ptr<CodeGenerator::Function>> mProtFunctionVector;
        std::vector<shared_ptr<Class>> mBaseClasses;
    };

    class Function
    {
    public:
        Function(std::string & FunctionName)
        {
            mFunctionName = FunctionName;
        }

        ~Function()
        {
            cout<<"Called Function Destructor of function : "<<getFunctionName()<<endl;
        }

        void addArgument(std::string type, std::string arg);
        void addReturnType(std::string RetType);
        string getFunctionName();
        string getFunctionNameForDefinitionFormat();
        string getReturnType();
    private:
        std::string mFunctionName;
        std::string mReturnType;
        std::vector<std::pair<std::string, std::string>> mArgs;
    };

    shared_ptr<Class> addClass(string ClassName);
    void setMainClass(shared_ptr<Class> MainClass);
    void setPath(std::string Path);
private:
    std::string OutPath;
    shared_ptr<Class> mMasterClass;
    void generateHeader();
    void generateSource();
};

#endif // CODEGENERATOR_H
