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

char* NGCustomDatabaseTable::getName() {
    return _name;
}

int NGCustomDatabaseTable::getRecordCount() {
    return _recordCount;
}

int NGCustomDatabaseTable::getMaxRecordCount() {
    return _maxRecordCount;
}
