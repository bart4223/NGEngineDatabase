#include <NGMemoryObserver.h>
#include <NGSDDataStorage.h>
#include <NGDatabase.h>
#include <NGExampleDatabaseTable.h>

#define SDCSPIN 53

#define DELAY 3000
//#define CREATE

NGDatabase db = NGDatabase("TEST",new NGSDDataStorage(SDCSPIN));
NGExampleDatabaseTable *tabOne = new NGExampleDatabaseTable("One");
NGExampleDatabaseTable *tabTwo = new NGExampleDatabaseTable("Two");

void setup() {
  observeMemory(0);
  db.setLogging(true);
  db.registerTable("One.csv",tabOne);
  db.registerTable("Two.csv",tabTwo);
  #ifdef CREATE
  db.initialize(false);
  #else
  db.initialize();
  #endif
  observeMemory(0);
  #ifdef CREATE
  NGExampleDatabaseRecord *recOneOne = tabOne->newRecord();
  NGExampleDatabaseRecord *recTwoOne = tabTwo->newRecord();
  NGExampleDatabaseRecord *recTwoTwo = tabTwo->newRecord();
  #endif
  observeMemory(0);
  db.store();
  observeMemory(0);
}

void loop() {
  observeMemory(DELAY);
}
