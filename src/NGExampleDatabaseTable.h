//
//  NGExampleDatabaseTable.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 24.11.22.
//

#ifndef NGExampleDatabaseTable_h
#define NGExampleDatabaseTable_h

#include <Arduino.h>
#include <UUID.h>
#include <NGCustomDatabaseTable.h>
#include <NGExampleDatabaseRecord.h>

#define MAXNGEXAMPLEDATABASERECORDS 3

class NGExampleDatabaseTable : public NGCustomDatabaseTable {
  
private:
    UUID _uuid;
    NGExampleDatabaseRecord *_records[MAXNGEXAMPLEDATABASERECORDS];
    
public:
    NGExampleDatabaseTable(char* name);
    
    void _create(char* name);
    
    void serialize(Stream *s);
    
    void deserialize(char* line);
    
    NGCustomDatabaseRecord* newRecord();
};

#endif /* NGExampleDatabaseTable_h */
