//
//  NGExampleDatabaseTable.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 24.11.22.
//

#include "NGExampleDatabaseTable.h"

NGExampleDatabaseTable::NGExampleDatabaseTable(char* name) {
    _create(name);
}

void NGExampleDatabaseTable::_create(char* name) {
    NGCustomDatabaseTable::_create(name);
    _maxRecordCount = MAXNGEXAMPLEDATABASERECORDS;
}

void NGExampleDatabaseTable::serialize(Stream *s) {
    for (int i = 0; i < _recordCount; i++) {
        _records[i]->serialize(s);
    }
}

NGCustomDatabaseRecord* NGExampleDatabaseTable::newRecord() {
    _uuid.generate();
    NGCustomDatabaseRecord* res = new NGExampleDatabaseRecord(_uuid.toCharArray());
    _records[_recordCount] = res;
    _recordCount++;
    return res;
}
