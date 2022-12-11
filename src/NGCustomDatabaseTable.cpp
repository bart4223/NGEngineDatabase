//
//  NGCustomDatabaseTable.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 24.11.22.
//

#include "NGCustomDatabaseTable.h"

void NGCustomDatabaseTable::_create(char* name){
    _name = name;
}

void NGCustomDatabaseTable::_raiseException(int id) {
    char info[100];
    _exceptionCount++;
    sprintf(info, "Ex %d(%d)", id, _exceptionCount);
    Serial.println(info);
}

char* NGCustomDatabaseTable::getName() {
    return _name;
}

int NGCustomDatabaseTable::getRecordCount() {
    return _recordCount;
}

int NGCustomDatabaseTable::getMaxRecordCount() {
    return _maxRecordCount;
}
