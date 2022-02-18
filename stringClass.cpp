#include "stringClass.h"

MyString::MyString() {
	this->str = nullptr;
	str_size = 0;
	str_cap = 0;
}
MyString::MyString(const char* str) {
	MakeNewString(str, strlen(str));
}
MyString::MyString(const std::string& str) {
	MakeNewString(str.c_str(), str.size());
}
MyString::MyString(const char* str, int count) {
	MakeNewString(str, count);
}
MyString::MyString(int count, char chr) {
	str_size = count;
	str_cap = count + 1;
	if (count > 0) {
		str = new char[str_cap];
		for (int i = 0; i < count; i++)
			str[i] = chr;
		str[count] = 0;
	}
	else
		this->str = nullptr;
}
MyString::MyString(const MyString& str) {
	MakeNewString(str.str, str.str_size);
}
MyString::~MyString() {
	delete[] str;
}
void MyString::MakeNewString(const char* str, int len) {
	str_size = len;
	str_cap = str_size + 1;
	this->str = new char[str_size + 1];
	strncpy(this->str, str, str_size);
	this->str[str_size] = 0;
}

///TO DO
MyString MyString::operator +(const MyString& str) {
	MyString s(MyConcat(str.str));
	return s;
}
MyString MyString::operator +(const char* str) {
	MyString s(MyConcat(str));
	return s;
}
MyString MyString::operator +(const std::string& str) {
	MyString s(MyConcat(str.c_str()));
	return s;
}

void MyString::operator +=(const std::string& str) {
	ReplaceStr(MyConcat(str.c_str()).c_str());

}
void MyString::operator +=(const MyString& str) {
	ReplaceStr(MyConcat(str.str).c_str());
}
void MyString::operator +=(const char* str) {
	ReplaceStr(MyConcat(str).c_str());
}


void MyString::operator =(const char* str) {
	ReplaceStr(str);
}
void MyString::operator =(const std::string& str) {
	ReplaceStr(str.c_str());
}
void MyString::operator =(const char chr) {
	ReplaceStr(&chr);
}
void MyString::operator =(const MyString& str) {
	ReplaceStr(str.str);
}

void MyString::ReplaceStr(const char* str) {
	if (str == NULL)
		return;
	delete[] this->str;
	CapSizeUpd(str);
	this->str = new char[str_cap];
	strcpy(this->str, str);
	this->str[str_size] = 0;
}
MyString MyString::MyConcat(const char* str) {
	MyString tmp;

	int len2 = 0, len1 = str_size;
	if (str != nullptr)
		len2 = strlen(str);
	int len = len1 + len2;

	tmp.str = new char[len + 1];
	tmp.str_size = len;
	tmp.str_cap = len + 1;

	if (this->str != nullptr && str != nullptr) {
		strcpy(tmp.str, this->str);
		strcat(tmp.str, str);
	}
	else if (this->str != nullptr)
		strcpy(tmp.str, this->str);
	else if (str != nullptr)
		strcpy(tmp.str, str);
	tmp[len] = 0;

	return tmp;
}
void MyString::CapSizeUpd(const char* str) {
	str_size = strlen(str);
	if (str_size + 1 > str_cap)
		str_cap = str_size + 1;
}
///

char& MyString::operator [](int ind) {
	return str[ind];
}

bool MyString::operator >(const MyString& str) {
	return !(*this <= str);
}
bool MyString::operator <(const MyString& str) {
	return !(*this >= str);
}

bool MyString::operator ==(const MyString& str) {
	if (this->str_size != str.str_size) return 0;
	for (int i = 0; i < str_size; i++) {
		if (this->str[i] != str.str[i]) return 0;
	}
	return 1;
}
bool MyString::operator !=(const MyString& str) {
	return !(*this == str);
}

bool MyString::operator >=(const MyString& str) {
	if (this->str == nullptr && str.str == nullptr) return 0;
	for (int i = 0; i < str_size && i < str.str_size; i++) {
		if (this->str[i] < str.str[i]) return 0;
	}
	return 1;
}
bool MyString::operator <=(const MyString& str) {
	if (this->str == nullptr && str.str == nullptr) return 0;
	for (int i = 0; i < str_size && i < str.str_size; i++) {
		if (this->str[i] > str.str[i]) return 0;
	}
	return 1;
}

const char* MyString::c_str() {
	return str;
}
const char* MyString::data() {
	return str;
}
const int  MyString::length() {
	return str_size;
}
const int  MyString::size() {
	return str_size;
}
const int  MyString::capacity() {
	return str_cap;
}
bool  MyString::empty() {
	return (str_size == 0);
}
void MyString::clear() {
	for (int i = 0; i < str_size; i++)
		str[i] = 0;
	str_size = 0;
}
void MyString::shrink_to_fit() {
	MyString str(this->str);
	delete[] this->str;
	this->str = new  char[str.size() + 1];
	str_size = str.size();
	str_cap = str_size + 1;
	strcpy(this->str, str.str);
	this->str[str_size] = 0;
}
void MyString::erase(int index, int count) {
	if (index > str_size) return;
	if (str_size < count || str_size < index + count) count = str_size - index;

	if (str_size != count) {
		char* new_str = new char[str_size - count + 1];
		if (index + count < str_size) {
			for (int i = index + count, j = index; i < str_size; i++, j++)
				new_str[j] = this->str[i];
		}
		strncpy(new_str, this->str, index);
		new_str[str_size - count] = 0;
		clear();
		str_size = strlen(new_str);
		strncpy(this->str, new_str, str_size);
		this->str[str_size] = 0;
		delete[] new_str;
	}
	else clear();

}

void MyString::insert(int index, int count, char chr)
{
	char* new_str = new char[count + 1];
	for (int i = 0; i < count; i++)
		new_str[i] = chr;
	new_str[count] = 0;
	insert(index, new_str);
	delete[] new_str;
}
void MyString::insert(int index, const char* str) {
	if (index > this->str_size) return;
	int str_len = strlen(str);
	int len = this->str_size + str_len;

	if (this->str != nullptr) {
		char* new_str = new char[str_size - index + 1];
		strcpy(new_str, substr(index).c_str());
		erase(index, str_size - index);
		*this += str;
		*this += new_str;
		delete[] new_str;
	}
	else
		*this += str;

	this->str[len] = 0;
}
void MyString::insert(int index, const char* str, int count) {
	char* buf = new char[count + 1];
	strncpy(buf, str, count);
	buf[count] = 0;
	insert(index, buf);
	delete[] buf;
}
void MyString::insert(int index, const std::string& str) {
	insert(index, str.c_str());
}
void MyString::insert(int index, const std::string& str, int count) {
	insert(index, str.c_str(), count);
}

void MyString::append(int count, char chr) {
	MyString tmp(count, chr);
	*this += tmp;
}
void MyString::append(const char* str) {
	*this += str;
}
void MyString::append(const char* str, int index, int count) {
	MyString tmp(str + index, count);
	*this += tmp;
}
void MyString::append(const std::string& str) {
	*this += str.c_str();
}
void MyString::append(const std::string& str, int index, int count) {
	MyString tmp((str.c_str()) + index, count);
	*this += tmp;
}

MyString MyString::substr(int index) {
	return substr(index, str_size - index);
}
MyString MyString::substr(int index, int count) {
	if (index > str_size) index = str_size;
	if (index < 0)  return this->str;
	MyString tmp(((this->str) + index), count);
	return tmp;
}

int MyString::find(const char* str, int index) {
	if (index > str_size || index < 0) return -1;
	int len = strlen(str);
	for (int i = index; i < str_size; i++) {
		for (int j = 0, k = i; j < len; j++, k++) {
			if (this->str[k] != str[j]) break;
			if (j == len - 1) return i;
		}
	}
	return -1;
}
int MyString::find(const char* str) {
	return find(str, 0);
}
int MyString::find(const std::string& str) {
	return find(str.c_str(), 0);
}
int MyString::find(const std::string& str, int ind) {
	return find(str.c_str(), ind);
}

void MyString::replace(int index, int count, const char* str) {
	int len = strlen(str);
	if (index > str_size || count < 0) return;
	if (count > str_size - index) count = str_size - index + 1;
	erase(index, count);
	insert(index, str, len);
}
void MyString::replace(int index, int count, const std::string& str) {
	replace(index, count, str.c_str());
}

std::ostream& operator <<(std::ostream& out, const MyString& str) {
	if (str.str != nullptr)
		return out << str.str;
	else
		return out << "";
}
std::istream& operator >>(std::istream& in, MyString& str) {

	int index = 0;
	char chr = 0;
	while ((chr = in.get()) != '\n') {
		str.insert(index++, 1, chr);
	}
	return in;
}
