#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Function prototypes
int Menu();
void Bus();
void Cycle();
void Riksha();
void ShowDetail();
void deleteData();
void deleteBus();
void deleteCycle();
void deleteRiksha();
void deleteAll();
void deleteAllBuses();
void deleteAllCycles();
void deleteAllRikshas();

// Global variables
int nor = 0, nob = 0, noc = 0, amount = 0, count = 0;
int amountChange = 0;
int addedAmount = 0; // New field to keep track of added/increasing values

int main() {
    while (1) {
        system("cls");
        printf("\n===================================================================");
        printf("\n| %-15s | %-15s | %-15s | %-15s | %-15s |", "Vehicle Type", "Number of Vehicles", "Amount Change", "Added Amount", "Total Amount");
        printf("\n===================================================================");
        ShowDetail();
        printf("\n===================================================================");
        switch (Menu()) {
            case 1:
                ShowDetail();
                break;
            case 2:
                Bus();
                break;
            case 3:
                Cycle();
                break;
            case 4:
                Riksha();
                break;
            case 5:
                deleteData();
                break;
            case 6:
                deleteBus();
                break;
            case 7:
                deleteCycle();
                break;
            case 8:
                deleteRiksha();
                break;
            case 9:
                deleteAll();
                break;
            case 10:
                deleteAllBuses();
                break;
            case 11:
                deleteAllCycles();
                break;
            case 12:
                deleteAllRikshas();
                break;
            case 13:
                exit(0);
            default:
                printf("\nSorry, Invalid Choice.");
        }
        getch();
    }

    return 0;
}

int Menu() {
    int ch;
    printf("\n1. Show Status");
    printf("\n2. Enter entry for Bus");
    printf("\n3. Enter entry for Cycle");
    printf("\n4. Enter entry for Riksha");
    printf("\n5. Delete All Data");
    printf("\n6. Delete the record for one Bus");
    printf("\n7. Delete the record for one Cycle");
    printf("\n8. Delete the record for one Riksha");
    printf("\n9. Delete the record for All Vehicles");
    printf("\n10. Delete  the record for All Buses");
    printf("\n11. Delete the record for All Cycles");
    printf("\n12. Delete the record for All Rikshas");
    printf("\n13. Exit");
    printf("\n\nEnter your choice:\n");
    scanf("%d", &ch);
    return ch;
}

void ShowDetail() {
    int totalAmount = amount + addedAmount;
    printf("\n| %-15s | %-15d | %-15d | %-15d | %-15d |", "Bus", nob, nob * 100, addedAmount, totalAmount);
    printf("\n| %-15s | %-15d | %-15d | %-15s | %-15s |", "Cycle", noc, noc * 20, "", "");
    printf("\n| %-15s | %-15d | %-15d | %-15s | %-15s |", "Riksha", nor, nor * 50, "", "");
    printf("\n| %-15s | %-15d | %-15d | %-15s | %-15s |", "Total", count, amountChange, "", "");
    printf("\n| %-15s | %-15d | %-15d | %-15s | %-15d |", "Amount", amount, amountChange, "", "");
}

void deleteData() {
    amountChange -= amount;
    addedAmount -= amount;
    nob = 0;
    noc = 0;
    nor = 0;
    amount = 0;
    count = 0;
}

void deleteBus() {
    if (nob > 0) {
        amountChange -= nob * 100;
        addedAmount -= nob * 100;
        nob--;
        count--;
        printf("\nentry for bus is deleted successfully.");
    } else {
        printf("\nNo Bus is in the queue to be deleted");
    }
}

void deleteCycle() {
    if (noc > 0) {
        amountChange -= noc * 20;
        noc--;
        count--;
        printf("\nentry for Cycle is deleted successfully");
    } else {
        printf("\nNo Cycle is in the queue to be deleted");
    }
}

void deleteRiksha() {
    if (nor > 0) {
        amountChange -= nor * 50;
        nor--;
        count--;
        printf("\nentry for Riksha is deleted successfully");
    } else {
        printf("\nNo Riksha is in the queue to be deleted.");
    }
}

void deleteAll() {
    amountChange -= amount;
    addedAmount -= amount;
    nob = 0;
    noc = 0;
    nor = 0;
    amount = 0;
    count = 0;
    printf("\nAll data deleted successfully.");
}

void deleteAllBuses() {
    amountChange -= nob * 100;
    addedAmount -= nob * 100;
    nob = 0;
    printf("\nAll bus data deleted successfully.");
}

void deleteAllCycles() {
    amountChange -= noc * 20;
    noc = 0;
    printf("\nAll cycles data deleted successfully.");
}

void deleteAllRikshas() {
    amountChange -= nor * 50;
    nor = 0;
    printf("\nAll rikshas data deleted successfully.");
}

void Riksha() {
    amountChange += 50;
    addedAmount += 50;
    nor++;
    count++;
    printf("\nEntry Successful");
}

void Cycle() {
    amountChange += 20;
    addedAmount += 20;
    noc++;
    count++;
    printf("\nEntry Successful");
}

void Bus() {
    amountChange += 100;
    addedAmount += 100;
    nob++;
    count++;
    printf("\nEntry Successful");
}

