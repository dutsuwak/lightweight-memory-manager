/*
 * Constants.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: fabian
 */
#include "../src/Constants.h"
#include "../src/com.LDMM.DataAccess/XMLReader.h"

Constants* Constants::_Constants = 0;
int Constants::SIZE = 214748364 ;
int Constants::OVERWEIGHT = 0;
int Constants::DUMP_FRECUENCY = 0;
std::string Constants::DUMP_PATH;
std::string Constants::vDEBUG;
std::string Constants::vDEBUG_PATH;
int Constants::GC_FRECUENCY = 0;
int Constants::cuartoDeSegundoMili = 0;
int Constants::medioDeSegundoMili = 0;
int Constants::SegundoMili = 0;
std::string Constants::TYPE_INT;
std::string Constants::TYPE_STRING;
std::string Constants::TYPE_CHAR;
std::string Constants::TYPE_LONG;
std::string Constants::TYPE_FLOAT;
std::string Constants::TYPE_ARRAY;
std::string Constants::TYPE_BOOL;
std::string Constants::TARGET_IP;
int Constants::TARGET_PORT;

Constants* Constants::getInstance(){
	if(_Constants == 0){
		_Constants = new Constants();
	}
	return _Constants;
}

Constants::Constants(){
	//XML Reader
	XMLReader* reader = new XMLReader();
	reader->loadXMLFile();

	//General Constants
	SIZE = atoi(reader->getParameter("SIZE"));
	OVERWEIGHT = atoi(reader->getParameter("OVERWEIGHT"));
	DUMP_FRECUENCY = atoi(reader->getParameter("DUMP_FRECUENCY"));
	DUMP_PATH = reader->getParameter("DUMP_PATH");
	vDEBUG = reader->getParameter("vDEBUG");
	vDEBUG_PATH = reader->getParameter("vDEBUG_PATH");
	GC_FRECUENCY = atoi(reader->getParameter("GC_FRECUENCY"));
	cuartoDeSegundoMili = atoi(reader->getParameter("cuartoDeSegundoMili"));
	medioDeSegundoMili = atoi(reader->getParameter("medioDeSegundoMili"));
	SegundoMili = atoi(reader->getParameter("SegundoMili"));

	//vObjects Constants
	TYPE_INT = "Int";
	TYPE_STRING = "String";
	TYPE_CHAR = "Char";
	TYPE_LONG = "Long";
	TYPE_FLOAT = "Float";
	TYPE_ARRAY = "Array";
	TYPE_BOOL = "Bool";

	TARGET_IP = reader->getParameter("TARGET_IP");
	TARGET_PORT = atoi(reader->getParameter("TARGET_PORT"));
}
