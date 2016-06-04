#ifndef _XLIB_H_CONVERT
#define _XLIB_H_CONVERT

#include <string>
#include <windows.h>

#define FREE_BUFF(a) FreeBuffer((void*)a)

/*
#ifdef UNICODE
#  define UToT UToW
#  define TToU WToU
#  define AToT AToW
#  define TToA WToA
#  define WToT WToW
#  define TToW WToW
#  define TToT WToW
#else
#  define UToT UToA
#  define TToU AToU
#  define AToT AToA
#  define TToA AToA
#  define WToT WToA
#  define TToW AToW
#  define TToT AToA
#endif

// ANSI ת�� UTF-8
const char* AToU(LPCSTR);
// ANSI ת�ɿ��ַ�
const wchar_t* AToW(LPCSTR);
// UTF-8 ת�� ANSI
const char* UToA(LPCSTR);
// UTF-8 ת�ɿ��ַ�
const wchar_t* UToW(LPCSTR);
// ���ַ�ת�� ANSI
const char* WToA(LPCWSTR);
// ���ַ�ת�� UTF-8
const char* WToU(LPCWSTR);
// ��������ֻ�ǽ��м򵥵ķ����ڴ沢COPY�ִ�
const char* AToA(LPCSTR);
const char* UToU(LPCSTR);
const wchar_t* WToW(LPCWSTR);
// ���Ϻ�������ֵȫ�ɴ˺����ͷ�
void FreeBuffer(void*);
*/
// �������ͣ����ּ�д���£�
// A: string   mbcs�ַ���
// W: wstring  unicode�ַ���
// T: tstring  ������_UNICODEʱ��unicode�ַ����������������mbcs�ַ���
// U: strutf8  utf-8�ַ���
// tstring��strutf8����std�����ռ��е�����
// 
// ʮ���ֱ任�������£������ڵ�Ϊ��������
// AtoA                string  -> string 
// WtoW                wstring -> wstring
// TtoT                tstring -> tstring
// UtoU                strutf8 -> strutf8
// AtoU (ToUtf8A    )  string  -> strutf8
// UtoA (ToCommonA  )  strutf8 -> string 
// WtoU (ToUtf8W    )  wstring -> strutf8
// UtoW (ToCommonW  )  strutf8 -> wstring
// AtoW (ToWideChar )  string  -> wstring
// WtoA (ToMultiByte)  wstring -> string 
// AtoT                string  -> tstring
// TtoA                tstring -> string 
// WtoT                wstring -> tstring
// TtoW                tstring -> wstring
// UtoT (ToCommon   )  strutf8 -> tstring
// TtoU (ToUtf8     )  tstring -> strutf8

_STD_BEGIN
//strutf8���Ͷ��壬ͬstringͬ����
typedef string strutf8;
//tstring���Ͷ���
#ifdef _UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif
_STD_END

// 
template <class _Self> _Self _StoS(const _Self &_self)
{
    return _self;
}

/*
//string -> string
bool ToUtf8A(const string &str, string &dst);
#define AtoU ToUtf8A

//wstring -> string
bool ToUtf8W(const wstring &str, string &dst);
#define WtoU ToUtf8W

//string -> string
bool ToCommonA(const string &str, string &dst);
#define UtoA ToCommonA

//string -> wstring
bool ToCommonW(const string &str, wstring &dst);
#define UtoW ToCommonW

//string -> wstring 
bool ToWideChar(const string &str, wstring &dst);
#define AtoW ToWideChar

//wstring -> string
bool ToMultiByte(const wstring &str, string &dst);
#define WtoA ToMultiByte
*/

// string -> string
#define AtoA _StoS<std::string>

// wstring -> wstring
#define WtoW _StoS<std::wstring>

// tstring -> tstring
#define TtoT _StoS<std::tstring>

// strutf8 -> strutf8
#define UtoU _StoS<std::strutf8>

std::strutf8 GToU(const std::string &str);

//string -> strutf8
std::strutf8 ToUtf8A(const std::string &str);
#define AtoU ToUtf8A

//strutf8 -> string
std::string ToCommonA(const std::strutf8 &str);
#define UtoA ToCommonA

//wstring -> strutf8
std::strutf8 ToUtf8W(const std::wstring &str);
#define WtoU ToUtf8W

//strutf8 -> wstring
std::wstring ToCommonW(const std::strutf8 &str);
#define UtoW ToCommonW

//string -> wstring 
std::wstring ToWideChar(const std::string &str);
#define AtoW ToWideChar

//wstring -> string
std::string ToMultiByte(const std::wstring &str);
#define WtoA ToMultiByte

// string -> tstring
#ifdef _UNICODE
#  define AtoT AtoW
#else
#  define AtoT AtoA
#endif

// tstring -> string
#ifdef _UNICODE
#  define TtoA WtoA
#else
#  define TtoA AtoA
#endif

// wstring -> tstring
#ifdef _UNICODE
#  define WtoT WtoW
#else
#  define WtoT WtoA
#endif

// tstring -> wstring
#ifdef _UNICODE
#  define TtoW WtoW
#else
#  define TtoW AtoW
#endif

// strutf8 - > tstring
#ifdef _UNICODE
#  define UtoT UtoW
#else
#  define UtoT UtoA
#endif
#define ToCommon UtoT

// tstring - > strutf8
#ifdef _UNICODE
#  define TtoU WtoU
#else
#  define TtoU AtoU
#endif
#define ToUtf8 TtoU

#endif
