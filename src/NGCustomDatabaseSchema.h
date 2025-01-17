//
//  NGCustomDatabaseSchema.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 11.12.22.
//

#ifndef NGCustomDatabaseSchema_h
#define NGCustomDatabaseSchema_h

#include <Arduino.h>
#include <NGDatabase.h>

class NGCustomDatabaseSchema {
    
protected:
    NGDatabase *_db;
    
    void _create(char* location, NGCustomDataStorage* storage);
    
public:
    void setLogging(bool logging);
    
    void initialize();
    
    void initialize(bool withload);
    
    void load();
    
    void store();
};

#endif /* NGCustomDatabaseSchema_h */
