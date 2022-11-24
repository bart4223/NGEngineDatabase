//
//  NGExampleDatabaseTable.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 24.11.22.
//

#ifndef NGExampleDatabaseTable_h
#define NGExampleDatabaseTable_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

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
    
    NGCustomDatabaseRecord* newRecord();
};

#endif /* NGExampleDatabaseTable_h */
