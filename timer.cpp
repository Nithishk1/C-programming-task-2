#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>

void display_time(int hours, int minutes, int seconds) {
    printf("\rTime: %02d:%02d:%02d", hours, minutes, seconds);
    fflush(stdout);
}

int main() {
    int hours = 0, minutes = 0, seconds = 0;
    bool running = false;
    char command;

    printf("Stopwatch - Press 's' to start, 'p' to pause, 'r' to reset, 'q' to quit.\n");

    while (1) {
        if (running) {
            seconds++;
            if (seconds == 60) {
                seconds = 0;
                minutes++;
                if (minutes == 60) {
                    minutes = 0;
                    hours++;
                }
            }
            display_time(hours, minutes, seconds);
            sleep(1);
        }

        if (kbhit()) {
            command = getchar();
            if (command == 's') {
                running = true;
            } else if (command == 'p') {
                running = false;
            } else if (command == 'r') {
                hours = 0;
                minutes = 0;
                seconds = 0;
                running = false;
                display_time(hours, minutes, seconds);
            } else if (command == 'q') {
                break;
            }
        }
    }

    return 0;
}

