//
//  NGCustomDatabaseTable.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 24.11.22.
//

#ifndef NGCustomDatabaseTable_h
#define NGCustomDatabaseTable_h

#include <Arduino.h>
#include <NGCustomDatabaseRecord.h>

class NGCustomDatabaseTable {
    
protected:
    char* _name;
    int _recordCount = 0;
    int _maxRecordCount = 0;
    int _exceptionCount = 0;
    
    void _create(char* name);
    
    void _raiseException(int id);
public:
    virtual void serialize(Stream *s);
    
    virtual void deserialize(char* line);
    
    char* getName();

    int getRecordCount();
    
    int getMaxRecordCount();
    
    virtual NGCustomDatabaseRecord* newRecord();
};

#endif /* NGCustomDatabaseTable_h */
