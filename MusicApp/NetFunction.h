#pragma once
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Text;
using namespace System::Net;
using namespace System::IO;

public ref class NetFunction
{
public:
	inline NetFunction();
	inline ~NetFunction();

	inline String^ createRequest(String^ link) {
		WebRequest^ request = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(link));

		try {
			WebResponse^ response = request->GetResponse();

			Stream^ data = response->GetResponseStream();
			StreamReader^ reader = gcnew StreamReader(data);
			String^ data_result = reader->ReadToEnd();

			response->Close();

			return data_result;
		}
		catch (Exception^ e) {
			Console::Write(e->Message);
			return "0";
		}
	}

	inline std::string convertstringToString(String^ data) {
		array<Byte>^ managedBytesUTF8 = Encoding::UTF8->GetBytes(data);
		pin_ptr<Byte> nativeByteUTF8 = &managedBytesUTF8[0];
		std::string utf8((char*)nativeByteUTF8, managedBytesUTF8->Length);

		return utf8;
	}

	inline std::string UTF8ToANSI(std::string s)
	{
		BSTR    bstrWide;
		char* pszAnsi;
		int     nLength;
		const char* pszCode = s.c_str();

		nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, NULL, NULL);
		bstrWide = SysAllocStringLen(NULL, nLength);

		MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);

		nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
		pszAnsi = new char[nLength];

		WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
		SysFreeString(bstrWide);

		std::string r(pszAnsi);
		delete[] pszAnsi;
		return r;
	}
};

inline NetFunction::NetFunction() {
}

inline NetFunction::~NetFunction() {
}