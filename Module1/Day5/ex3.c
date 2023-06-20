#include <stdio.h>

// Structure to represent time
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time t1, struct Time t2) {
    struct Time difference;

    // Convert everything to seconds
    int t1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int t2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the difference in seconds
    int secondsDifference = t2Seconds - t1Seconds;

    // Convert back to hours, minutes, and seconds
    difference.hours = secondsDifference / 3600;
    secondsDifference %= 3600;
    difference.minutes = secondsDifference / 60;
    difference.seconds = secondsDifference % 60;

    return difference;
}

int main() {
    struct Time startTime, endTime, difference;

    // Reading the start time
    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    // Reading the end time
    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    // Calculating the difference
    difference = calculateTimeDifference(startTime, endTime);

    // Displaying the difference
    printf("Time difference: %d hours, %d minutes, %d seconds\n",
           difference.hours, difference.minutes, difference.seconds);

    return 0;
}
