//
//  NGSDDataStorage.h
//  NGEngineControl
//
//  Created by Nils Grimmer on 13.11.22.
//

#ifndef NGSDDataStorage_h
#define NGSDDataStorage_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <SPI.h>
#include <SD.h>
#include <NGCustomDataStorage.h>

#define DEFSDCSPIN 5

class NGSDDataStorage  : public NGCustomDataStorage  {
  
private:
    byte _pinCS;
    File _file;
    
protected:
    void _create(byte pinCS);
    
public:
    NGSDDataStorage();
    
    NGSDDataStorage(byte pinCS);
    
    void initialize();
    
    void open(char* name);
    
    void open(char* name, dataStorageOpenMode mode);
    
    bool isOpen();
    
    void close();
    
    bool isAvailable();
    
    int read();
};

#endif /* NGSDDataStorage_h */