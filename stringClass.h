#pragma once
#ifndef STRINGCLASS_STRINGCLASS_H
#define STRINGCLASS_STRINGCLASS_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string.h>

class MyString
{
private:
	char* str;
	int str_size;
	int str_cap;
public:
	MyString();
	MyString(const char* str);
	MyString(const std::string& str);
	MyString(const char* str, int count);
	MyString(int count, char chr);
	MyString(const MyString& str);
	~MyString();

	void MakeNewString(const char* str, int len);

	MyString operator +(const MyString& str);
	MyString operator +(const char* str);
	MyString operator +(const std::string& str);

	MyString MyConcat(const char* str);
	void ReplaceStr(const char* str);
	void CapSizeUpd(const char* str);

	void operator +=(const std::string& str);
	void operator +=(const MyString& str);
	void operator +=(const char* str);

	void operator =(const char* str);
	void operator =(const std::string& str);
	void operator =(const char chr);
	void operator =(const MyString& str);

	char& operator[](int ind);

	bool operator >(const MyString& str);
	bool operator <(const MyString& str);

	bool operator ==(const MyString& str);
	bool operator !=(const MyString& str);

	bool operator >=(const MyString& str);
	bool operator <=(const MyString& str);

	const char* c_str();
	const char* data();
	const int length();
	const int size();
	const int capacity();
	bool empty();
	void shrink_to_fit();
	void clear();
	void erase(int index, int count);

	void insert(int index, int count, char chr);
	void insert(int index, const char* str);
	void insert(int index, const char* str, int count);
	void insert(int index, const std::string& str);
	void insert(int index, const std::string& str, int count);

	void append(int count, char chr);
	void append(const char* str);
	void append(const char* str, int index, int count);
	void append(const std::string& str);
	void append(const std::string& str, int index, int count);

	MyString substr(int index);
	MyString substr(int index, int count);

	int find(const char* str);
	int find(const char* str, int index);
	int find(const std::string& str);
	int find(const std::string& str, int index);

	void replace(int index, int count, const char* str);
	void replace(int index, int count, const std::string& str);

	friend std::ostream& operator <<(std::ostream& out, const MyString& str);
	friend std::istream& operator >>(std::istream& in, MyString& str);
};

#endif