//
//  NGExampleDatabaseSchema.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 11.12.22.
//

#ifndef NGExampleDatabaseSchema_h
#define NGExampleDatabaseSchema_h

#include <Arduino.h>
#include <NGCustomDatabaseSchema.h>
#include <NGExampleDatabaseTable.h>

class NGExampleDatabaseSchema : public NGCustomDatabaseSchema {
    
private:
    NGExampleDatabaseTable *tabOne;
    NGExampleDatabaseTable *tabTwo;
    
protected:
    void _create(char* location, NGCustomDataStorage* storage);
    
public:
    NGExampleDatabaseSchema(char* location, NGCustomDataStorage* storage);
    
};

#endif /* NGExampleDatabaseSchema_h */
