//
//  NGCustomDatabaseSchema.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 11.12.22.
//

#include "NGCustomDatabaseSchema.h"

void NGCustomDatabaseSchema::_create(char* location, NGCustomDataStorage* storage) {
    _db = new NGDatabase(location, storage);
}

void NGCustomDatabaseSchema::setLogging(bool logging) {
    _db->setLogging(logging);
}

void NGCustomDatabaseSchema::initialize() {
    initialize(true);
}

void NGCustomDatabaseSchema::initialize(bool withload) {
    _db->initialize(withload);
}

void NGCustomDatabaseSchema::load() {
    _db->load();
}

void NGCustomDatabaseSchema::store() {
    _db->store();
}
