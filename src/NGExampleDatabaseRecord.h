//
//  NGExampleDatabaseRecord.h
//  NGEngineDatabase
//
//  Created by Nils Grimmer on 20.11.22.
//

#ifndef NGExampleDatabaseRecord_h
#define NGExampleDatabaseRecord_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <NGCustomDatabaseRecord.h>

class NGExampleDatabaseRecord : public NGCustomDatabaseRecord {
    
private:
    int _field1;
    byte _field2;

protected:
    void _create(char* pkey);
    
public:
    NGExampleDatabaseRecord(char* pkey);
    
    void serialize(Stream *s);
    
    void setField1(int value);
    
    int getField1();
    
    void setField2(byte value);
    
    byte getField2();
};

#endif /* NGExampleDatabaseRecord_h */
