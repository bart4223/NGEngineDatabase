//
//  NGSDDataStorage.cpp
//  NGEngineControl
//
//  Created by Nils Grimmer on 13.11.22.
//

#include "NGSDDataStorage.h"

NGSDDataStorage::NGSDDataStorage() {
    _create(DEFSDCSPIN);
}

NGSDDataStorage::NGSDDataStorage(byte pinCS) {
    _create(pinCS);
}

void NGSDDataStorage::_create(byte pinCS) {
    _pinCS = pinCS;
}

void NGSDDataStorage::initialize() {
    if (!_initialized) {
        _initialized = SD.begin(_pinCS);
        if (_logging) {
            if (_initialized) {
                Serial.println("SD Card initialized");
            } else {
                Serial.println("SD Card not initialized");
            }
        }
    }
}

bool NGSDDataStorage::open(char* name) {
    return open(name, DEFDATASTORAGEOPENMODE);
}

bool NGSDDataStorage::open(char* name, dataStorageOpenMode mode) {
    bool res = false;
    if (isInitialized()) {
        switch(mode) {
            case dsomRead:
                _file = SD.open(name, FILE_READ);
                break;
            case dsomWrite:
                _file = SD.open(name, FILE_WRITE);
                break;
            case dsomTruncate:
                _file = SD.open(name, FILE_WRITE | O_TRUNC);
                break;
        }
        res = isOpen();
        if (_logging) {
            char log[100];
            if (res) {
                sprintf(log, "File %s opened", name);
            } else {
                sprintf(log, "File %s cant open", name);
            }
            Serial.println(log);
        }
    } else if (_logging) {
        Serial.println("SD Card not initialized");
    }
    return res;
}

bool NGSDDataStorage::isOpen() {
    return _file;
}

void NGSDDataStorage::close() {
    if (isInitialized()) {
        if (isOpen()) {
            _file.close();
            if (_logging) {
                char log[100];
                sprintf(log, "File %s closed", _file.name());
                Serial.println(log);
            }
        } else if (_logging) {
            Serial.println("No file open");
        }
    } else if (_logging) {
        Serial.println("SD Card not initialized");
    }
}

bool NGSDDataStorage::isAvailable() {
    bool res = isOpen();
    if (res) {
        res = _file.available();
    }
    return res;
}

int NGSDDataStorage::read() {
    return _file.read();
}

Stream* NGSDDataStorage::getStream() {
    return &_file;
}
