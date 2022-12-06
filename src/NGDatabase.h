//
//  NGDatabase.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 27.11.22.
//

#ifndef NGDatabase_h
#define NGDatabase_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <NGCustomDataStorage.h>
#include <NGCustomDatabaseTable.h>

#define CMAXDATABASETABLECOUNT 5

struct databaseTableStruct
{
    NGCustomDatabaseTable* table;
    char* dataStorageName;
    long loaded;
    long lastStored;
};
typedef struct databaseTableStruct databaseTable;

class NGDatabase {
    
private:
    NGCustomDataStorage* _storage;
    databaseTable _tables[CMAXDATABASETABLECOUNT];
    int _tableCount = 0;
    bool _logging = false;
    int _exceptionCount = 0;
    char* _location;

protected:
    void _create(char* location, NGCustomDataStorage* storage);
    
    void _raiseException(int id);
    
public:
    NGDatabase(NGCustomDataStorage* storage);
    
    NGDatabase(char* location, NGCustomDataStorage* storage);
    
    void initialize();
    
    void initialize(bool withload);
    
    void setLogging(bool logging);
    
    bool getLogging();
    
    void registerTable(char* dataStorageName, NGCustomDatabaseTable* table);
    
    void load();
    
    void store();
};

#endif /* NGDatabase_h */
