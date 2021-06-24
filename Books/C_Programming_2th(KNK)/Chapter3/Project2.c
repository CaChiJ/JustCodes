#include <stdio.h>

int main(void)
{
    int itemNumber = 0;
    float unitPrice = 0.0f;
    int year = 0;
    int month = 0;
    int day = 0;

    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    
    printf("Enter unit price: ");
    scanf("%f", &unitPrice);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$  %.2f\t%d/%d/%d\n", itemNumber, unitPrice, month, day, year);

    return 0;
}