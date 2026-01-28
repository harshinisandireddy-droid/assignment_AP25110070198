#include <stdio.h>
struct Car {
    int carID;
    char model[20];
    float ratePerDay;
};
int main() {
    struct Car c[3];
    int days, i;
    for (i = 0; i < 3; i++) {
        printf("\nEnter details of Car %d\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &c[i].carID);
        printf("Model: ");
        scanf("%s", c[i].model);
        printf("Rental rate per day: ");
        scanf("%f", &c[i].ratePerDay);
    }
    printf("\nEnter number of days: ");
    scanf("%d", &days);
    for (i = 0; i < 3; i++) {
        printf("\nCar ID: %d", c[i].carID);
        printf("\nModel: %s", c[i].model);
        printf("\nTotal Rental Cost: %.2f\n", c[i].ratePerDay * days);
    }
    return 0;
}
