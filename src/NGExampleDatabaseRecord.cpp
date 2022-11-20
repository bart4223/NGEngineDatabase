//
//  NGExampleDatabaseRecord.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 20.11.22.
//

#include "NGExampleDatabaseRecord.h"

NGExampleDatabaseRecord::NGExampleDatabaseRecord(char* pkey) {
    _create(pkey);
}

void NGExampleDatabaseRecord::_create(char* pkey) {
    NGCustomDatabaseRecord::_create(pkey);
    _field1 = random(0, 10);
    _field2 = random(11, 20);
}

void NGExampleDatabaseRecord::serialize(Stream *s) {
    NGCustomDatabaseRecord::serialize(s);
    DBRECORDPRINTSEPARATOR;
    s->print(_field1);
    DBRECORDPRINTSEPARATOR;
    s->println(_field2);
}

void NGExampleDatabaseRecord::setField1(int value) {
    _field1 = value;
}

int NGExampleDatabaseRecord::getField1() {
    return _field1;
}

void NGExampleDatabaseRecord::setField2(byte value) {
    _field2 = value;
}

byte NGExampleDatabaseRecord::getField2() {
    return _field2;
}
