#include <NGMemoryObserver.h>
#include <NGSDDataStorage.h>
#include <NGDatabase.h>
#include <NGExampleDatabaseTable.h>

#define SDCSPIN 53

#define DELAY 3000

NGDatabase db = NGDatabase("TEST",new NGSDDataStorage(SDCSPIN));
NGExampleDatabaseTable *tabOne = new NGExampleDatabaseTable("One");
NGExampleDatabaseTable *tabTwo = new NGExampleDatabaseTable("Two");

void setup() {
  observeMemory(0);
  db.setLogging(true);
  db.registerTable("One.csv",tabOne);
  db.registerTable("Two.csv",tabTwo);
  db.initialize();
  observeMemory(0);
  NGExampleDatabaseRecord *recOneOne = tabOne->newRecord();
  NGExampleDatabaseRecord *recTwoOne = tabTwo->newRecord();
  observeMemory(0);
  db.store();
  observeMemory(0);
}

void loop() {
  observeMemory(DELAY);
}
