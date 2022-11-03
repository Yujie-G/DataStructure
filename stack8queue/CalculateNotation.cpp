// Version 2.0 ��׺���ʽ��������ֵ
// Full Version

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

stack<char> Operator;
queue<char> Postfix;
vector<string> ANS; // �����Ҫ����Ľ��string

void Quit(bool Type = 0)
{
    // stack<char>().swap(Operator);
    // queue<char>().swap(Postfix);
    while (!Operator.empty())
    {
        Operator.pop();
    }
    while (!Postfix.empty())
    {
        Postfix.pop();
    }
    // if (!Type)cout << "ERROR IN INFIX NOTATION\n";
    if (!Type)
        ANS.push_back("ERROR IN INFIX NOTATION");
}

bool Convert2PostfixNotation(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
        {
            Postfix.push(s[i]); // 0-9 ֱ��ѹ��ջ��
        }

        else
        {
            if (!Postfix.empty())
                Postfix.push('$');

            if (s[i] == ')')
            { // �������������ε�ջ��ֱ������������
                bool flag = 0;
                while (true)
                {
                    if (Operator.empty())
                    {
                        return 0;
                    }

                    if (Operator.top() == '(')
                    {
                        Operator.pop();
                        break;
                    }
                    Postfix.push('$');
                    Postfix.push(Operator.top()); // ջ�е������ż�������������������ȫ������
                    Operator.pop();
                }
            }
            else
            {
                if (!Operator.empty() && (s[i] == '+' || s[i] == '-')) //&&
                                                                       //(Operator.top() == '*' || Operator.top() == '/' || Operator.top() == '%' || Operator.top() == '^'))
                { // �����ϼӼ�����ʱ�������������1�����ջΪ�գ���ֱ��ѹ��ջ�У�
                    while (!Operator.empty())
                    { //                               2�����ջ��Ϊ�գ�����Ҫ�ж���ջ�����ŵ����ȼ�
                        if (Operator.top() == '(')
                            break; // ��1�����ջ���ķ������ȼ������ε�ջֱ��ջ�ջ�������������
                        Postfix.push('$');
                        Postfix.push(Operator.top()); // ��2������ֱ��ѹ��ջ��
                        Operator.pop();
                    }
                    Operator.push(s[i]); // ��ջ������ɺ��ٰ����ϵķ���ѹ��ջ��
                }
                else // ����* /����ʱ
                    if (!Operator.empty() && (s[i] == '*' || s[i] == '/' || s[i] == '%') &&
                        (Operator.top() == '^' || Operator.top() == '*' || Operator.top() == '/' || Operator.top() == '%'))
                    {
                        while (!Operator.empty())
                        { //
                            if (Operator.top() == '(' || Operator.top() == '+' || Operator.top() == '-')
                                break;
                            Postfix.push('$');
                            Postfix.push(Operator.top());
                            Operator.pop();
                        }
                        Operator.push(s[i]);
                    }
                    else
                        Operator.push(s[i]);
            }
        }
    }
    while (!Operator.empty())
    {
        Postfix.push('$');
        Postfix.push(Operator.top());
        // cout << Operator.top();
        Operator.pop();
    }
    return 1;
}

bool Calculate()
{ // ����׺���ʽ��ֵ
    stack<double> result;

    double curNum = 0;
    bool isDec = 0;
    int pos = 0;

    while (!Postfix.empty())
    {
        // cout << Postfix.front();
        // Postfix.pop();
        char tmp = Postfix.front();

        // ������(С����)���
        if ((tmp >= '0' && tmp <= '9') || tmp == '.')
        {
            if (tmp == '.')
            {
                isDec = 1;
                Postfix.pop();
                continue;
            }
            if (!isDec)
            {
                curNum *= 10;
                curNum += (double)tmp - '0';
            }
            else
            {
                curNum += pow(10, --pos) * ((double)tmp - '0');
            }
        }

        else if (tmp == '$') // �Ƿָ������
        {
            result.push(curNum);
            curNum = 0;
            isDec = 0;
            pos = 0;
            // ����һ����$�ַ�
            while (!Postfix.empty() && Postfix.front() == '$')
            {
                Postfix.pop();
            }
            continue;
        }
        else // ����������
        {
            if (result.size() < 2)
            {
                return 0;
            }
            double a = result.top();
            result.pop();
            double b = result.top();
            result.pop();
            switch (tmp)
            {
            case '+':
                result.push(a + b);
                break;
            case '-':
                result.push(b - a);
                break;
            case '*':
                result.push(a * b);
                break;
            case '/':
                if (a < 1e-4)
                    return 0; // aΪ0ʱ����
                result.push(b / a);
                break;
            case '%':
                if (a < 1e-4)
                    return 0; // aΪ0ʱ����
                result.push((int)b % (int)a);
                break;
            case '^':
                result.push(pow(b, a));
                break;
            default:
                return 0;
                break;
            }

            Postfix.pop();
            // ����һ����$�ַ�
            while (!Postfix.empty() && Postfix.front() == '$')
            {
                Postfix.pop();
            }
            continue;
        }
        Postfix.pop();
    }
    if (result.size() == 1) // ��ʣһ������Ϊ������
    {
        // תΪstring����
        stringstream ss;
        string num;
        ss << fixed << setprecision(2) << result.top();
        ss >> num;
        ANS.push_back(num);
        return 1;
    }
    return 0;
}

void showPostfixNotation()
{
    queue<char> Temp{Postfix};
    // show the Postfix notation
    while (!Temp.empty())
    {
        cout << Temp.front();
        Temp.pop();
    }
    cout << endl;
}

void test()
{
    //"2-5+8*2" "20+7*3*(21+3)-15"
    string s = "1";
    Convert2PostfixNotation(s);
    showPostfixNotation();
    Calculate();
    cout << ANS[0];
}

int main()
{
    // test(); return 0;
    string s;
    while (!cin.eof())
    {
        getline(cin, s);
        if (s.length() == 0)
            break; // �������룬��������
        bool flag1 = Convert2PostfixNotation(s);
        // showPostfixNotation();
        bool flag2 = 0;
        if (flag1)
            flag2 = Calculate();
        Quit(flag1 && flag2);
        s.clear();
    }

    bool flag = 1;
    for (auto &j : ANS)
    {
        if (flag)
        {
            cout << j;
            flag = 0;
        }
        else
        {
            cout << endl << j;
        }
    }

    return 0;
}
