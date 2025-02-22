/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Xml
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "Xml_Lexer.h"

namespace vl::glr::xml
{
	bool XmlTokenDeleter(vl::vint token)
	{
		switch((XmlTokens)token)
		{
		case XmlTokens::SPACE:
			return true;
		default:
			return false;
		}
	}

	const wchar_t* XmlTokenId(XmlTokens token)
	{
		static const wchar_t* results[] = {
			L"INSTRUCTION_OPEN",
			L"INSTRUCTION_CLOSE",
			L"COMPLEX_ELEMENT_OPEN",
			L"SINGLE_ELEMENT_CLOSE",
			L"ELEMENT_OPEN",
			L"ELEMENT_CLOSE",
			L"EQUAL",
			L"NAME",
			L"ATTVALUE",
			L"COMMENT",
			L"CDATA",
			L"TEXT",
			L"SPACE",
		};
		vl::vint index = (vl::vint)token;
		return 0 <= index && index < XmlTokenCount ? results[index] : nullptr;
	}

	const wchar_t* XmlTokenDisplayText(XmlTokens token)
	{
		static const wchar_t* results[] = {
			L"<?",
			L"?>",
			L"</",
			L"/>",
			L"<",
			L">",
			L"=",
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
		};
		vl::vint index = (vl::vint)token;
		return 0 <= index && index < XmlTokenCount ? results[index] : nullptr;
	}

	const wchar_t* XmlTokenRegex(XmlTokens token)
	{
		static const wchar_t* results[] = {
			L"/</?",
			L"/?/>",
			L"/<//",
			L"///>",
			L"/<",
			L"/>",
			L"/=",
			L"[a-zA-Z0-9:._/-]+",
			L"\"[^<>\"]*\"|\'[^<>\']*\'",
			L"/</!--([^/-]|-[^/-]|--[^>])*--/>",
			L"/</!/[CDATA/[([^/]]|/][^/]]|/]/]+[^/]>])*/]/]+/>",
			L"([^<>=\"\' /r/n/ta-zA-Z0-9:._/-])+|\"|\'",
			L"/s+",
		};
		vl::vint index = (vl::vint)token;
		return 0 <= index && index < XmlTokenCount ? results[index] : nullptr;
	}

	void XmlLexerData(vl::stream::IStream& outputStream)
	{
		static const vl::vint dataLength = 1105; // 7530 bytes before compressing
		static const vl::vint dataBlock = 256;
		static const vl::vint dataRemain = 81;
		static const vl::vint dataSolidRows = 4;
		static const vl::vint dataRows = 5;
		static const char* compressed[] = {
			"\x6A\x1D\x00\x00\x49\x04\x00\x00\x2D\x00\x01\xA7\x01\x84\x81\x82\x12\x82\x01\x04\x88\x04\x89\x04\x84\x82\x05\x0F\x84\x8B\x04\x8C\x04\x81\x06\x8B\x04\x8E\x04\x9F\x04\x80\x11\x8E\x82\x21\x20\x84\x82\x13\x94\x83\x10\x82\x07\x82\x84\x83\x81\x80\x14\x82\x16\x04\x80\x81\x92\x90\x06\x14\x82\x9B\x01\xAF\x04\x9A\x91\x80\x18\x83\x1C\x04\xBA\x01\xA4\x8B\x1C\xA0\x82\x1E\x47\x84\xBD\x0A\xA4\x86\x1D\xA6\x82\x3F\x50\x84\x80\x23\xAC\x81\x20\xAB\x04\xC2\x19\xA4\x83\x24\xAC\x82\x22\x5F\x84\x85\x24\x83\x2C\x80\x2A\xB3\x04\xD5\x04\x9A\x24\x83\x2D\xB6\x82\x5C\x70\x84\x9D\x23\xBC\x82\x2E\xBB\x04\xDF\x39\xA4\x80\x34\xBC\x83\x30\x04\xFA\x04\x9B\x34\x87\x7F\x7E\x08\x00\x0D\x81\x90\x8B\xC6\x85\xC7\x80\x8A\x80\x0C\xC9\xC4\x87\x02\xC6\x00\x0B\x90\xC4\x86\x0B\xCC\x83\x01\xCE\x01\x9C\xDA\xC1\x89\x81\x81\x02\x82\x04\x04\x82\x17\xC2\xD0\x01\xD7\xD7\xA0\xAE\xF1\xD1\xC4\xDC\xD6\xDB\xD1\x00\x06\xFA\xDB\xDC\xDD\xDE\xDE\xDE\x17\x81\xBF\xC3\xEE\xDD\x8A\xE0\xE2\xC8\x86\xD3\x87\xE9\xE5\xE6\xE7\xE7\xC9\x8F\x05\xDE\xD2\xEC\xE7\x7F\xEA\xB9\xBA\xD8\xFB",
			"\xDB\xEA\xEF\xE9\xDE\xDD\xE0\xDF\xFC\xDA\x89\x80\xED\xF0\xD0\xC3\xE7\xE4\x8B\xF6\xE8\xF5\xF7\xE3\xDC\xE3\xF0\xFE\xF3\xF9\xF8\xEF\xD6\xF2\xF9\xFA\xD8\xC6\xF0\xF7\xFB\xE9\x7C\x6D\x78\x00\x03\xBA\x79\x76\x61\xE8\x41\x8A\x83\x82\x0C\x8D\x8E\x83\x83\x10\x91\x82\x87\x84\x14\x95\x86\x85\x7A\x11\x04\x49\x86\x75\x1B\x80\x0D\x87\x83\x1D\xA1\x8A\x87\x88\x01\x62\x8B\x7C\x71\x1F\xBA\x69\x89\x6F\x12\x04\x4D\x89\x40\x2F\x80\x01\x8F\x8C\x2E\xB5\x81\x43\x04\x36\xB2\x89\x8C\x8D\x30\xBB\x89\x8F\x6E\x31\x80\x9E\x8D\x8F\x44\xBA\x85\x90\x8F\x46\x89\x98\x93\x92\x3F\xBA\x64\x04\x41\x4F\x81\x41\x94\x00\x53\x95\x90\x97\x95\x52\x98\x90\x01\x05\x5A\x96\x99\x97\x97\x54\x9A\x9B\x6F\x94\x63\x9D\x96\x98\x98\x5E\xA1\x98\x9B\x99\x6A\xAD\x99\x9A\x81\xBF\x74\x77\x83\x75\xF6\x75\x77\x88\x9D\x77\x89\x84\x77\x7F\x77\x8B\x83\x81\x81\xF8\x73\x9A\x9E\x61\x16\x04\x45\xA2\x75\x87\xB3\x99\xA3\x85\x8C\x8D\xAE\xA3\xA3\x90\x91\xA2\xA7\xA4\x94\x95\xA6\xA5\xA4\x17\x00\x87\xA5\x7A\x18\x1A\xAB\xA7\xA7\xA0\x95\xA3\xA0\x9E\x82\xB5\x95\xAA\x9D\x73\xB0\x9B\x9D\x9F",
			"\x81\xA3\xAE\x9C\x9F\x04\xB0\xAA\xA8\x82\x9E\xA1\xA6\xAF\xAD\xB8\xBF\x36\x8B\x9C\xBB\xA0\x84\x8A\x87\xBF\xBB\xAB\x89\x73\xC3\x83\xB2\x93\x91\x43\x8A\x99\x8C\x8E\xC8\x8D\xBA\xB2\xB3\x41\xBA\x61\xB6\x61\x4C\x90\xB9\xB1\xB5\xCF\x99\xB8\x91\xAE\xDC\x9D\xBF\x3D\x9A\xE0\xAC\x91\xB9\x40\x5C\xAB\x96\xBA\x9B\x62\x8E\x93\x7B\xB8\xE8\xA7\xBC\xBB\xBB\xE2\xB5\xAE\xB7\xBC\x96\x89\xAB\xA2\x6E\xF7\x84\xA2\xBC\xBD\xFC\xB7\xA9\x07\xBE\xFD\x81\xC2\xC1\x72\x1A\x00\xC2\xA7\x06\x04\x48\xC1\x42\xC2\x00\x0C\xCE\xC1\xC2\x10\xCB\xC1\xC5\xC3\x13\xDC\x03\xC7\xC3\x12\xD9\xC4\xC6\xC6\x18\xDB\xCE\xC5\xC7\x20\xD7\xC2\xC8\xC7\x23\xDE\xC3\xC3\xA7\x1D\x06\xCD\xA1\xC8\x24\xED\xCF\xC5\xC9\x0C\xD6\xCE\xC8\xCB\x2F\xF3\xC0\xCF\xCD\x36\xF9\xC5\xCE\xC9\xBA\x5E\x04\x42\xCF\x01\x40\xD0\x02\xD0\x44\xFF\xC6\xD1\xD0\x47\xC3\xD9\xD0\x47\x48\xCD\xDA\xD2\xD3\x45\xD0\xD9\xD1\xD4\x4F\xD5\xD4\xD7\xD5\x53\xD9\xD2\xD6\xD3\x27\xCC\xAE\x44\xAB\xB7\xB4\xC2\xD8\xCE\x3B\xF2\xCB\xCF\xD8\x3A\xE8\xD7\xD8\xD9\x6A\xDD\xCB\x6D\x48\x01\x70\xD0\x02\xDC\x74\xE2\x41\xDE\xDD\x73",
			"\xF8\xD5\xDF\xDD\x7C\xF9\xDD\xDF\xDE\x7E\xC1\xE4\x4B\xDF\x7A\xC5\xE4\xE3\xE1\x81\xC0\xEA\xE0\xDE\x5D\xF9\xA7\x48\xD8\x14\xAD\xDC\xD8\xD9\x66\xD2\xE9\xDB\xE4\x97\xD9\xEB\xDA\xC6\x8D\xDD\xEE\xE5\xB7\x24\x2A\xCF\xE7\xE8\x13\xA5\x02\xE8\x74\x29\x40\x09\xEB\xEA\x28\x6D\xE6\x42\xEB\xAA\xF0\xEC\xEB\xEB\xB4\xF1\xE5\xEF\xEC\xB6\xF9\xE8\xEF\xEE\xB2\xFD\xE7\xEC\xEC\x2C\x7A\xEE\xED\xEE\xBB\x7C\xEF\xEF\xF1\xC2\xC8\xF6\xF1\xF2\xCC\xCB\xFE\xF3\xF0\xCF\xF5\xE1\xF1\xF4\xC4\xFA\x6E\x49\x4B\x04\x57\xF0\x02\xF6\xDC\xD9\xFE\xF4\xF6\xE0\xDB\xFF\xF6\xF8\xE1\xDD\xF5\xFB\xF8\xE6\xE4\xFA\xF9\xFA\xEC\xE8\xFE\xF9\x40\x29\x2F\xFB\xFB\xF8\xC5\xD0\xF6\xFE\xF2\xF7\xCD\xF9\xFC\xF5\xFC\xFB\xFB\x4A\xFF\xB5\x7B\x37\x0A\x04\x23\x81\x80\x05\x80\x00\x07\x89\x80\x01\x8B\x86\x80\x06\x88\x86\x81\x0A\x8D\x82\x04\x8F\x83\x83\x08\x80\x00\x26\x15\x90\x82\x06\x99\x8C\x82\x0A\x80\x02\x05\x1B\x9E\x82\x05\x82\x81\x84\x0B\xA6\x85\x84\x28\x9D\x83\x09\x93\x88\x82\x11\xA9\x86\x85\x2A\x8E\x80\x08\xB1\x8D\x83\xFA\x78\x7F\x86\xFA\x78\x85\xFF\x3A\x80\x81\x1C\xBE\x83",
			"\x7A\x3D\x84\x76\x10\x8A\x4E\x1F\x6F\x2B\x08\x00\x04\x10\x00\x4D\x05\x29\x35\x80\x0B\x38\x00\x4F\x87\x35\x68\x15\x32\x23\x2A\x8E\x8C\x22\x05\x2A\x34\x46\x24\x36\x8A\x00\x1F\x31\x20\x96\x21\x21\x70\x18\x3B\x8A\x32\x81\x26\x38\x00\x03\x8E\x1A\xE5\x8B\x8C\x31\xAC\x8F\x8D\xB8\x2D\x8D\x1A\xF0\x83\x8E\x37\xB6\x8D\x8E\x92\x24\x20",
		};
		vl::glr::DecompressSerializedData(compressed, true, dataSolidRows, dataRows, dataBlock, dataRemain, outputStream);
	}
}
