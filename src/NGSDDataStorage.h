//
//  NGSDDataStorage.h
//  NGEngineControl
//
//  Created by Nils Grimmer on 13.11.22.
//

#ifndef NGSDDataStorage_h
#define NGSDDataStorage_h

#include <Arduino.h>
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
    
    bool open(char* name);
    
    bool open(char* name, dataStorageOpenMode mode);
    
    bool isOpen();
    
    void close();
    
    bool isAvailable();
    
    int read();
    
    String readLine();
    
    Stream* getStream();
    
    bool exists(char* name);
    
    bool mkdir(char* name);
};

#endif /* NGSDDataStorage_h */
