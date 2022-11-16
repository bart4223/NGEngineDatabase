#include <NGMemoryObserver.h>
#include <NGSDDataStorage.h>

#define DELAY 3000

NGSDDataStorage sdds = NGSDDataStorage();

void setup() {
  observeMemory(0);
  sdds.setLogging(true);
  sdds.initialize();
  observeMemory(0);
}

void loop() {
  sdds.open("test.txt");
  observeMemory(DELAY);
  sdds.close();
  observeMemory(DELAY);
}
