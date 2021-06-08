#pragma once

using namespace System;
using namespace System::Xml;

ref class ElemList
{
private:
	int id;
	int sringNum;
	int elemNum;
	String^ value;
	String^ effect;

public: ElemList(String^ _value, String^ _effect) {
	setValue(_value);
	setEffect(_effect);
}

public: void setId(int _id) {
	id = _id;
}

public: int getId() {
	return id;
}

public: void setStringNum(int _sringNum) {
	sringNum = _sringNum;
}

public: int getSringNumd() {
	return sringNum;
}

public: void setElemNum(int _elemNum) {
	elemNum = _elemNum;
}

public: int getElemNum() {
	return elemNum;
}

public: void setValue(String^ _value) {
	value = _value;
}

public: String^ getValue() {
	return value;
}

public: void setEffect(String^ _effect) {
	effect = _effect;
}

public: String^ getEffect() {
	return effect;
}

public:	  void CreateXML(array<ElemList^>^ elemList, int maxId);

	  //public:	  void OpenXML(array<ElemList^>^ elemList);

};



