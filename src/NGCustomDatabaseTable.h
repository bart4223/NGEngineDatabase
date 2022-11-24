//
//  NGCustomDatabaseTable.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 24.11.22.
//

#ifndef NGCustomDatabaseTable_h
#define NGCustomDatabaseTable_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <NGCustomDatabaseRecord.h>

class NGCustomDatabaseTable {
    
protected:
    char* _name;
    int _recordCount = 0;
    int _maxRecordCount = 0;
    
    void _create(char* name);
    
public:
    virtual void serialize(Stream *s);
    
    char* getName();

    int getRecordCount();
    
    int getMaxRecordCount();    
    
    virtual NGCustomDatabaseRecord* newRecord();
};

#endif /* NGCustomDatabaseTable_h */
