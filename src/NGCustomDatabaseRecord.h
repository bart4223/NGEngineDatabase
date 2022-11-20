//
//  NGCustomDatabaseRecord.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 20.11.22.
//

#ifndef NGCustomDatabaseRecord_h
#define NGCustomDatabaseRecord_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define DBRECORDPRINTSEPARATOR s->print(_separator)

class NGCustomDatabaseRecord {

private:
    char* _pkey;

protected:
    char _separator = ';';

    void _create(char* pkey);
    
public:
    void serialize(Stream *s);
};

#endif /* NGCustomDatabaseRecord_h */
