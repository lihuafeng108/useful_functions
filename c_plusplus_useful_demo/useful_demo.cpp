
#include <iostream>
#include <cstring>
using namespace std;

class ClassTest
{
public:
    ClassTest()
    {
        c[0] = '\0';
        cout << "ClassTest()" << endl;
    }
    ClassTest& operator=(const ClassTest& ct)
    {
        strcpy(c, ct.c);
        cout << "ClassTest& operator=(const ClassTest &ct)" << endl;
        return *this;
    }
    ClassTest(const char* pc)
    {
        strcpy(c, pc);
        cout << "ClassTest (const char *pc)" << endl;
    }

 //private:  
 /* <lihf>这里注释打开，即复制构造函数被声明为私有时。ct2至ct4都会提示错误。
 原因分析:
    直接初始化直接调用与实参匹配的构造函数，复制初始化总是调用复制构造函数。复制初始化首先使用指定构造函数创建一个临时对象，
然后用复制构造函数将那个临时对象复制到正在创建的对象。所以当复制构造函数被声明为私有时，所有的复制初始化都不能使用。
 */
    ClassTest(const ClassTest& ct)
    {
        strcpy(c, ct.c);
        cout << "ClassTest(const ClassTest& ct)" << endl;
    }
private:
    char c[256];
};

int main()
{
    cout << "ct1: ";
    ClassTest ct1("ab");//直接初始化
    cout << "ct2: ";
    ClassTest ct2 = "ab";//复制初始化
    cout << "ct3: ";
    ClassTest ct3 = ct1;//复制初始化
    cout << "ct4: ";
    ClassTest ct4(ct1);//直接初始化
    cout << "ct5: ";
    ClassTest ct5 = ClassTest();//复制初始化
	cout << "ct4 cpy ct5: ";
	ct4 = ct5;
    /*程序运行结果：
    ct1: ClassTest (const char *pc)
    ct2: ClassTest (const char *pc)
    ct3: ClassTest(const ClassTest& ct)
    ct4: ClassTest(const ClassTest& ct)
    ct5: ClassTest()
	ct4 cpy ct5: ClassTest& operator=(const ClassTest &ct)
    */
    
    return 0;
}
