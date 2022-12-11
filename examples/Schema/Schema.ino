#include <NGMemoryObserver.h>
#include <NGExampleDatabaseSchema.h>
#include <NGSDDataStorage.h>

#define SDCSPIN 53

#define DELAY 3000

NGExampleDatabaseSchema eds = NGExampleDatabaseSchema("EXAMPLE", new NGSDDataStorage(SDCSPIN));

void setup() {
  observeMemory(0);
  eds.setLogging(true);
  eds.initialize();
  observeMemory(0);
  eds.store();
  observeMemory(0);
}

void loop() {
  observeMemory(DELAY);
}
