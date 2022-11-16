//
//  NGCustomDataStorage.h
//  NGEngineControl
//
//  Created by Nils Grimmer on 13.11.22.
//

#ifndef NGCustomDataStorage_h
#define NGCustomDataStorage_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

enum dataStorageOpenMode { dsomRead, dsomWrite, dsomTruncate };

#define DEFDATASTORAGEOPENMODE dsomRead

class NGCustomDataStorage {
  
protected:
    bool _initialized = false;
    bool _logging = false;
    
public:
    void setLogging(bool logging);
    
    bool getLogging();
    
    bool isInitialized();
    
    virtual void initialize();
    
    virtual void open(char* name);
    
    virtual void open(char* name, dataStorageOpenMode mode);
    
    virtual bool isOpen();
    
    virtual void close();
};

#endif /* NGCustomDataStorage_h */
