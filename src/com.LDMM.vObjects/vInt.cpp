/*
 * vInt.cpp
 *
 *  Created on: 15/3/2015
 *      Author: tvlenin
 */

#include "vInt.h"
#include "../com.LDMM.MemoryManager/vHeap.h"
#include <typeinfo>

vRef* vInt::operator= (const int& s){
	vIntData = s;
	setVObjectData((void*)&vIntData);
	setVObjectType(TYPE_INT);

	return vHeap::getInstancia()->vMalloc(8,TYPE_INT);
	//return this;
}




 vInt::vInt(){
	vIntData = 0;
}

