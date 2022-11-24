#include <NGMemoryObserver.h>
#include <NGExampleDatabaseTable.h>

#define DELAY 3000

NGExampleDatabaseTable *testTable = new NGExampleDatabaseTable("test");

void setup() {
  observeMemory(0);
  Serial.println(testTable->getName());
  for (int i = 0; i < testTable->getMaxRecordCount(); i++) {
    NGExampleDatabaseRecord *testRecord = testTable->newRecord();
    testRecord->setField1(42);
    testRecord->setField2(0x17);
  }
  Serial.println(testTable->getRecordCount());
}

void loop() {
  testTable->serialize(&Serial);
  observeMemory(DELAY);
}
