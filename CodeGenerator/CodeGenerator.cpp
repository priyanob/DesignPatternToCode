#include "CodeGenerator.h"


CodeGenerator::CodeGenerator()
{
}

void CodeGenerator::generate()
{
    generateHeader();

    cout<<endl<<endl;

    generateSource();
}

void CodeGenerator::generateHeader()
{
    ostringstream  hfile_contents;
    string FPath = OutPath.append("/");
    FPath.append(mMasterClass->getClassName());
    FPath.append(".h");

    cout<<"Header file:"<<FPath<<endl;
    ofstream HeaderFile(FPath);

    if (HeaderFile.is_open())
    {
        cout<<"Header file is created"<<endl;
    }

    hfile_contents<<"class "<<mMasterClass->getClassName();
    vector<string> baseClasslist = mMasterClass->getAllBaseClasses();
    if( baseClasslist.size() > 0 )
    {
        hfile_contents<<" :";
    }
    for(int i=0; i<baseClasslist.size(); i++)
    {
        hfile_contents<<" public "<<baseClasslist[i];
        if( i != baseClasslist.size() -1 )
        {
            hfile_contents<<", ";
        }
    }
    hfile_contents<<endl;
    hfile_contents<<"{"<<endl;
    hfile_contents<<" private:"<<endl;
    vector<string> privateFunctions = mMasterClass->getAllPrivateFunctionsAsString();
    for(int i=0; i< privateFunctions.size(); i++)
    {
        hfile_contents<<"    "<<privateFunctions[i]<<endl;
    }

    hfile_contents<<endl;
    hfile_contents<<" public:"<<endl;
    vector<string> publicFunctions = mMasterClass->getAllPublicFunctionsAsString();
    for(int i=0; i< publicFunctions.size(); i++)
    {
        hfile_contents<<"    "<<publicFunctions[i]<<endl;
    }

    hfile_contents<<endl;
    hfile_contents<<" protected:"<<endl;
    vector<string> protectedFunctions = mMasterClass->getAllProtectedFunctionsAsString();
    for(int i=0; i< protectedFunctions.size(); i++)
    {
        hfile_contents<<"    "<<protectedFunctions[i]<<endl;
    }

    hfile_contents<<"};"<<endl;

    HeaderFile<<hfile_contents.str();
    HeaderFile.close();
}

void CodeGenerator::generateSource()
{
    ostringstream  cfile_contents;
    string FPath = OutPath.append("/");
    FPath.append(mMasterClass->getClassName());
    FPath.append(".cpp");
    cout<<"Source file:"<<FPath<<endl;

    ofstream SourceFile(FPath);

    vector<shared_ptr<Function>> privateFunctions = mMasterClass->getAllPrivateFunctions();
    for(int i=0; i< privateFunctions.size(); i++)
    {
        cfile_contents<<privateFunctions[i]->getReturnType()<<" "<<mMasterClass->getClassName()
            <<"::"<<privateFunctions[i]->getFunctionNameForDefinitionFormat()<<endl;
        cfile_contents<<"{"<<endl;
        cfile_contents<<"}"<<endl;
        cfile_contents<<endl;
    }

    vector<shared_ptr<Function>> publicFunctions = mMasterClass->getAllPublicFunctions();
    for(int i=0; i< publicFunctions.size(); i++)
    {
        cfile_contents<<publicFunctions[i]->getReturnType()<<" "<<mMasterClass->getClassName()
            <<"::"<<publicFunctions[i]->getFunctionNameForDefinitionFormat()<<endl;
        cfile_contents<<"{"<<endl;
        cfile_contents<<"}"<<endl;
        cfile_contents<<endl;
    }


    vector<shared_ptr<Function>> protectedFunctions = mMasterClass->getAllProtectedFunctions();
    for(int i=0; i< protectedFunctions.size(); i++)
    {
        cfile_contents<<protectedFunctions[i]->getReturnType()<<" "<<mMasterClass->getClassName()
            <<"::"<<protectedFunctions[i]->getFunctionNameForDefinitionFormat()<<endl;
        cfile_contents<<"{"<<endl;
        cfile_contents<<"}"<<endl;
        cfile_contents<<endl;
    }

    SourceFile<<cfile_contents.str();
    SourceFile.close();
}

shared_ptr<CodeGenerator::Class> CodeGenerator::addClass(string ClassName)
{
    shared_ptr<Class> cls;
    cls.reset(new Class(ClassName));

    return cls;
}

void CodeGenerator::setMainClass(shared_ptr<CodeGenerator::Class> MainClass)
{
    mMasterClass = MainClass;
}

void CodeGenerator::setPath(string Path)
{
    OutPath = Path;
}

CodeGenerator::Class::~Class()
{
    cout<<"Called Class Destructor of Class : "<< getClassName()<<endl;
}

weak_ptr<CodeGenerator::Function>
                CodeGenerator::Class::addPrivateFunction( string FunctionName )
{
    shared_ptr<Function> fnc;

    fnc.reset(new Function(FunctionName));

    setFunctionToClass(eFunction_Visibility_Private, fnc);

    return fnc;
}

weak_ptr<CodeGenerator::Function>
                CodeGenerator::Class::addPublicFunction( string FunctionName )
{
    shared_ptr<Function> fnc;

    fnc.reset(new Function(FunctionName));

    setFunctionToClass(eFunction_Visibility_Public, fnc);

    return fnc;
}

weak_ptr<CodeGenerator::Function>
                CodeGenerator::Class::addProtectedFunction(string FunctionName )
{
    shared_ptr<Function> fnc;

    fnc.reset(new Function(FunctionName));

    setFunctionToClass(eFunction_Visibility_Protected, fnc);

    return fnc;
}

string CodeGenerator::Class::getClassName()
{
    return mClassName;
}

std::vector<string> CodeGenerator::Class::getAllPrivateFunctionsAsString()
{
    std::vector<string> AllPrivateFunctions;
    for(auto item: mPvtFunctionVector)
    {
        AllPrivateFunctions.push_back(item->getFunctionName());
    }

    return AllPrivateFunctions;
}

std::vector<shared_ptr<CodeGenerator::Function> > CodeGenerator::Class::getAllPrivateFunctions()
{
    return mPvtFunctionVector;
}

std::vector<string> CodeGenerator::Class::getAllPublicFunctionsAsString()
{
    std::vector<string> AllPublicFunctions;
    for(auto item: mPubFunctionVector)
    {
        AllPublicFunctions.push_back(item->getFunctionName());
    }

    return AllPublicFunctions;
}

std::vector<shared_ptr<CodeGenerator::Function> > CodeGenerator::Class::getAllPublicFunctions()
{
    return mPubFunctionVector;
}


std::vector<string> CodeGenerator::Class::getAllProtectedFunctionsAsString()
{
    std::vector<string> AllProtectedFunctions;
    for(auto item: mProtFunctionVector)
    {
        AllProtectedFunctions.push_back(item->getFunctionName());
    }

    return AllProtectedFunctions;
}

std::vector<shared_ptr<CodeGenerator::Function> > CodeGenerator::Class::getAllProtectedFunctions()
{
    return mProtFunctionVector;
}


void CodeGenerator::Class::addBaseClasses(std::vector<shared_ptr<Class>> BaseClasses)
{
    mBaseClasses = BaseClasses;
}

void CodeGenerator::Class::addBaseClass(shared_ptr<CodeGenerator::Class> BaseClass)
{
    mBaseClasses.push_back(BaseClass);
}

std::vector<string> CodeGenerator::Class::getAllBaseClasses()
{
    std::vector<string> BaseClasses;
    for(int i=0; i<mBaseClasses.size(); i++)
    {
        BaseClasses.push_back(mBaseClasses[i]->getClassName());
    }

    return BaseClasses;
}

void CodeGenerator::Class::setFunctionToClass(eFunction_Visibility visibility,
                                              shared_ptr<CodeGenerator::Function> fnc)
{
    addFunction(visibility, fnc);
}

void CodeGenerator::Function::addArgument(string type, string arg)
{
    mArgs.push_back(make_pair(type,arg));
}

void CodeGenerator::Function::addReturnType(string RetType)
{
    mReturnType = RetType;
}

string CodeGenerator::Function::getFunctionName()
{
    ostringstream  function_name;

    function_name <<mReturnType;
    function_name <<" ";
    function_name <<mFunctionName;
    function_name <<"( ";

    for(int i=0; i<mArgs.size(); i++)
    {
        string arg_signature;
        arg_signature.append( mArgs[i].first);
        arg_signature.append( " ");
        arg_signature.append( mArgs[i].second);

        if( i != mArgs.size() - 1)
            arg_signature.append( ", ");

        function_name<<arg_signature;
        arg_signature.clear();
    }

    function_name<<");";

    return function_name.str();
}

string CodeGenerator::Function::getFunctionNameForDefinitionFormat()
{
    ostringstream  function_name;

    function_name <<mFunctionName;
    function_name <<"( ";

    for(int i=0; i<mArgs.size(); i++)
    {
        string arg_signature;
        arg_signature.append( mArgs[i].first);
        arg_signature.append( " ");
        arg_signature.append( mArgs[i].second);

        if( i != mArgs.size() - 1)
            arg_signature.append( ", ");

        function_name<<arg_signature;
        arg_signature.clear();
    }

    function_name<<");";

    return function_name.str();
}

string CodeGenerator::Function::getReturnType()
{
    return mReturnType;
}
