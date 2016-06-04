#pragma execution_character_set("utf-8")
#include "convert.h"
using namespace std;

#pragma warning(disable:4996)

strutf8 GToU(const string &str)
{
    strutf8 ret;
    int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

    if (len > 0)
    {
        wchar_t* wstr = new wchar_t[len + 1];
        MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
        len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
        if (len > 0)
        {
            char* buff = new char[len + 1];
            WideCharToMultiByte(CP_UTF8, 0, wstr, -1, buff, len, NULL, NULL);
            ret = buff;
            delete[] buff;
        }

        delete[] wstr;
    }

    return str;
}

strutf8 ToUtf8A(const string &str)
{
    return ToUtf8W(ToWideChar(str));
}

strutf8 ToUtf8W(const wstring &str)
{
    strutf8 ret;

    int count = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL);

    if (count > 0)
    {
        char *buffer = new char[count];

        if (buffer != 0)
        {
            WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, buffer, count, NULL, NULL);
            ret = buffer;

            delete []buffer;
        }
    }

    return ret;
}

string ToCommonA(const strutf8 &str)
{
    return ToMultiByte(ToCommonW(str));
}

wstring ToCommonW(const strutf8 &str)
{
    wstring ret;

    int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

    if (count > 0)
    {
        wchar_t *buffer = new wchar_t[count];

        if (buffer != 0)
        {
            MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, buffer, count);
            ret = buffer;

            delete []buffer;
        }
    }

    return ret;
}

string ToMultiByte(const wstring &str)
{
    string ret;

    int count = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);

    if (count > 0)
    {
        char *buffer = new char[count];

        if (buffer != 0)
        {
            WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, buffer, count, NULL, NULL);
            ret = buffer;

            delete []buffer;
        }
    }

    return ret;
}

wstring ToWideChar(const string &str)
{
    wstring ret;

    int count = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

    if (count > 0)
    {
        wchar_t *buffer = new wchar_t[count];

        if (buffer != 0)
        {
            MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buffer, count);
            ret = buffer;

            delete []buffer;
        }
    }

    return ret;
}

