#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    printf ("Amorio, Marc Dave R. Section M-1L\n");  
    
    double total_cost = 0.0;

    char product_name[100];
    int quantity;
    double price;
    int status_choice;
    printf("WELCOME TO MARC'S KAHIT ANO MERON STORE!\n");
    printf("=== MALUPITANG POINT OF SALE PROGRAM ===\n\n");

        // Loop repeatedly until all items are accounted for
    while (1) {
        printf("Enter product name (or 'done' to finish): ");
        if (scanf(" %[^\n]", product_name) != 1) {
            break;
        }

        // Convert input string to lowercase for safe comparison
        char temp_name[100];
        int i;
        for (i = 0; product_name[i] != '\0'; i++) {
            temp_name[i] = (char)tolower((unsigned char)product_name[i]);
        }
        temp_name[i] = '\0';

        // Check if cashier is done entering items
        if (strcmp(temp_name, "done") == 0) {
            if (total_cost == 0.0) {
                printf("No items entered yet. Please enter at least one product.\n\n");
                continue;
            }
            break;
        }

        // Error handling for product quantity
        while (1) {
            printf("Enter quantity for '%s': ", product_name);
            if (scanf("%d", &quantity) == 1 && quantity > 0) {
                break;
            } else {
                printf("Invalid input! Quantity must be a positive integer.\n");
                while (getchar() != '\n'); // clear input buffer
            }
        }

        // Error handling for product price
        while (1) {
            printf("Enter price for '%s': ₱", product_name);
            if (scanf("%lf", &price) == 1 && price >= 0.0) {
                break;
            } else {
                printf("Invalid input! Price must be a non-negative number.\n");
                while (getchar() != '\n'); // clear input buffer
            }
        }

        // Update total cost based on price and quantity
        double item_total = price * quantity;
        total_cost += item_total;

        printf("Added: %d x %s @ ₱%.2f = ₱%.2f\n", quantity, product_name, price, item_total);
        printf("Current Subtotal: ₱%.2f\n\n", total_cost);
    }

        // Ask user for customer category
        printf("\nSelect Customer Category:\n");
        printf("1. PWD (5%% discount)\n");
        printf("2. Senior Citizen (20%% discount)\n");
        printf("3. Pregnant Person (₱30.00 discount)\n");
        printf("4. None of the above (No discount)\n");

        // Error handling for menu option selection
    while (1) {
        printf("Enter choice (1-4): ");
        if (scanf("%d", &status_choice) == 1 && status_choice >= 1 && status_choice <= 4) {
            break;
        } else {
            printf("Invalid selection! Please enter a number between 1 and 4.\n");
            while (getchar() != '\n'); // clear input buffer
        }
    }

    char status_label[50];
    double discount = 0.0;

    // Apply specific discount per customer state
    switch (status_choice) {
        case 1:
            strcpy(status_label, "PWD");
            discount = total_cost * 0.05;
            break;
        case 2:
            strcpy(status_label, "Senior Citizen");
            discount = total_cost * 0.20;
            break;
        case 3:
            strcpy(status_label, "Pregnant Person");
            discount = 30.00;
            break;
        case 4:
            strcpy(status_label, "None of the above");
            discount = 0.00;
            break;
    }

    // Adjust total cost after applying discount
    double final_total = total_cost - discount;
    if (final_total < 0.0) {
        final_total = 0.0; // Prevent total from becoming negative
    }

    // Output customer status and final total cost
    printf("\n===================================\n");
    printf("        TRANSACTION RECEIPT        \n");
    printf("===================================\n");
    printf("Subtotal:         ₱%.2f\n", total_cost);
    printf("Customer Status:  %s\n", status_label);
    printf("Discount Applied: ₱%.2f\n", discount);
    printf("Total Cost Due:   ₱%.2f\n", final_total);
    printf("===================================\n");

    return 0;
}