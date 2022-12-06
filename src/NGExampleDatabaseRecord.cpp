//
//  NGExampleDatabaseRecord.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 20.11.22.
//

#include "NGExampleDatabaseRecord.h"

NGExampleDatabaseRecord::NGExampleDatabaseRecord() {
    _create(DBEMPTYPKEY);
}

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

void NGExampleDatabaseRecord::deserialize(char* line) {
    NGCustomDatabaseRecord::deserialize(line);
    String s = String(line);
    int xS = 0;
    int xE = s.indexOf(_separator, xS);
    //_field1
    xS = xE + 1;
    xE = s.indexOf(_separator, xS);
    String value = s.substring(xS, xE);
    _field1 = value.toInt();
    //_field2
    xS = xE + 1;
    xE = s.length();
    value = s.substring(xS, xE);
    _field2 = value.toInt();
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
