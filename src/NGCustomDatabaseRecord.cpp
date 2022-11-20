//
//  NGCustomDatabaseRecord.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 20.11.22.
//

#include "NGCustomDatabaseRecord.h"

void NGCustomDatabaseRecord::_create(char* pkey) {
    _pkey = malloc(strlen(pkey) + 1);
    memcpy(_pkey,pkey,strlen(pkey));
    _pkey[strlen(pkey)] = '\0';
}

void NGCustomDatabaseRecord::serialize(Stream *s) {
    s->print(_pkey);
}
