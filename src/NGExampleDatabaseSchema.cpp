//
//  NGExampleDatabaseSchema.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 11.12.22.
//

#include "NGExampleDatabaseSchema.h"

NGExampleDatabaseSchema::NGExampleDatabaseSchema(char* location, NGCustomDataStorage* storage) {
    _create(location, storage);
    tabOne = new NGExampleDatabaseTable("One");
    _db->registerTable("One.csv",tabOne);
    tabTwo = new NGExampleDatabaseTable("Two");
    _db->registerTable("Two.csv",tabTwo);
}

void NGExampleDatabaseSchema::_create(char* location, NGCustomDataStorage* storage) {
    NGCustomDatabaseSchema::_create(location, storage);
}
