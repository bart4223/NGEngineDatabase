//
//  NGExampleDatabaseTable.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 24.11.22.
//

#include "NGDatabaseExceptions.h"
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

void NGExampleDatabaseTable::deserialize(char* line) {
    if (_recordCount < _maxRecordCount) {
        NGExampleDatabaseRecord* rec = new NGExampleDatabaseRecord();
        _records[_recordCount] = rec;
        _recordCount++;
        rec->deserialize(line);
    } else {
        _raiseException(ExceptionDatabaseTooMuchRecordCount);
    }
}

NGCustomDatabaseRecord* NGExampleDatabaseTable::newRecord() {
    NGCustomDatabaseRecord* res = nullptr;
    if (_recordCount < _maxRecordCount) {
        _uuid.generate();
        res = new NGExampleDatabaseRecord(_uuid.toCharArray());
        _records[_recordCount] = res;
        _recordCount++;
    } else {
        _raiseException(ExceptionDatabaseTooMuchRecordCount);
    }
    return res;
}
