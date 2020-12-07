
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
 /* <lihf>����ע�ʹ򿪣������ƹ��캯��������Ϊ˽��ʱ��ct2��ct4������ʾ����
 ԭ�����:
    ֱ�ӳ�ʼ��ֱ�ӵ�����ʵ��ƥ��Ĺ��캯�������Ƴ�ʼ�����ǵ��ø��ƹ��캯�������Ƴ�ʼ������ʹ��ָ�����캯������һ����ʱ����
Ȼ���ø��ƹ��캯�����Ǹ���ʱ�����Ƶ����ڴ����Ķ������Ե����ƹ��캯��������Ϊ˽��ʱ�����еĸ��Ƴ�ʼ��������ʹ�á�
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
    ClassTest ct1("ab");//ֱ�ӳ�ʼ��
    cout << "ct2: ";
    ClassTest ct2 = "ab";//���Ƴ�ʼ��
    cout << "ct3: ";
    ClassTest ct3 = ct1;//���Ƴ�ʼ��
    cout << "ct4: ";
    ClassTest ct4(ct1);//ֱ�ӳ�ʼ��
    cout << "ct5: ";
    ClassTest ct5 = ClassTest();//���Ƴ�ʼ��
	cout << "ct4 cpy ct5: ";
	ct4 = ct5;
    /*�������н����
    ct1: ClassTest (const char *pc)
    ct2: ClassTest (const char *pc)
    ct3: ClassTest(const ClassTest& ct)
    ct4: ClassTest(const ClassTest& ct)
    ct5: ClassTest()
	ct4 cpy ct5: ClassTest& operator=(const ClassTest &ct)
    */
    
    return 0;
}
