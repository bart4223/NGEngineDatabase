//
//  NGDatabase.cpp
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 27.11.22.
//

#include "NGDatabase.h"
#include "NGDatabaseExceptions.h"

NGDatabase::NGDatabase(NGCustomDataStorage* storage) {
    _create("", storage);
}

NGDatabase::NGDatabase(char* location, NGCustomDataStorage* storage) {
    _create(location, storage);
}

void NGDatabase::_create(char* location, NGCustomDataStorage* storage) {
    _storage = storage;
    _location = location;
}

void NGDatabase::_raiseException(int id) {
    char info[100];
    _exceptionCount++;
    sprintf(info, "Ex %d(%d)", id, _exceptionCount);
    Serial.println(info);
}

void NGDatabase::initialize() {
    initialize(true);
}

void NGDatabase::initialize(bool withload) {
    if (_logging) {
        Serial.println("DB init...");
    }
    _storage->initialize();
    if (_logging) {
        Serial.println("DB initialized");
    }
    if (withload) {
        load();
    }
}

void NGDatabase::setLogging(bool logging) {
    _logging = logging;
    _storage->setLogging(logging);
}

bool NGDatabase::getLogging() {
    return _logging;
}

void NGDatabase::registerTable(char* dataStorageName, NGCustomDatabaseTable* table) {
    if (_tableCount < CMAXDATABASETABLECOUNT) {
        databaseTable dt;
        dt.table = table;
        dt.dataStorageName = dataStorageName;
        dt.loaded = 0;
        dt.lastStored = 0;
        _tables[_tableCount] = dt;
        _tableCount++;
        if (_logging) {
            char log[100];
            sprintf(log, "Table %s registered", table->getName());
            Serial.println(log);
        }
    } else {
        _raiseException(ExceptionDatabaseTooMuchTableCount);
    }
}

void NGDatabase::load() {
    for (int i = 0; i < _tableCount; i++) {
        char name[100];
        if (_location == "") {
            sprintf(name, "%s", _tables[i].dataStorageName);
        } else {
            sprintf(name, "%s/%s", _location, _tables[i].dataStorageName);
        }
        if (_logging) {
            char log[100];
            sprintf(log, "Load table %s...", _tables[i].table->getName());
            Serial.println(log);
        }
        _storage->open(name, dsomRead);
        while (_storage->isAvailable()) {
            String line = _storage->readLine();
            _tables[i].table->deserialize(line.c_str());
        }
        _storage->close();
        _tables[i].loaded = millis();
    }
    if (_logging) {
        Serial.println("DB loaded");
    }
}

void NGDatabase::store() {
    for (int i = 0; i < _tableCount; i++) {
        char name[100];
        if (_location == "") {
            sprintf(name, "%s", _tables[i].dataStorageName);
        } else {
            sprintf(name, "%s/%s", _location, _tables[i].dataStorageName);
        }
        if (_logging) {
            char log[100];
            sprintf(log, "Store table %s...", _tables[i].table->getName());
            Serial.println(log);
        }
        if (!_storage->exists(_location)) {
            _storage->mkdir(_location);
        }
        _storage->open(name, dsomTruncate);
        _tables[i].table->serialize(_storage->getStream());
        _storage->close();
        _tables[i].lastStored = millis();
    }
    if (_logging) {
        Serial.println("DB stored");
    }
}
