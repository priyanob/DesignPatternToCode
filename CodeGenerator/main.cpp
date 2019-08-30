#include <CodeGenerator.h>

int main()
{
    CodeGenerator G;

    std::string s("Calculator");
    shared_ptr<CodeGenerator::Class> MainClass;

    MainClass =  G.addClass(s);

    shared_ptr<CodeGenerator::Function> f1;
    if( f1 = MainClass->addPrivateFunction("doSum").lock())
    {
        f1->addArgument("int","a");
        f1->addArgument("int","b");
        f1->addReturnType("int");
    }

    shared_ptr<CodeGenerator::Function> f2;
    if( f2 = MainClass->addPrivateFunction("doSubtract").lock())
    {
        f2->addArgument("int","a");
        f2->addArgument("int","b");
        f2->addReturnType("int");
    }
}
