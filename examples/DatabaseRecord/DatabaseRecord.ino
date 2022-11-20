#include <UUID.h>
#include <NGMemoryObserver.h>
#include <NGExampleDatabaseRecord.h>

#define DBRECORDCOUNT 3

#define DELAY 3000

UUID uuid;

NGExampleDatabaseRecord *records[DBRECORDCOUNT];

void setup() {
  observeMemory(0);
  for (int i = 0; i < DBRECORDCOUNT; i++) {
    uuid.generate();
    records[i] = new NGExampleDatabaseRecord(uuid.toCharArray());
  }
}

void loop() {
  for (int i = 0; i < DBRECORDCOUNT; i++) {
    records[i]->serialize(&Serial);
  }
  observeMemory(DELAY);
}
