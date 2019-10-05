// Shop simulator
// Author: Andrzej Kocielski
// Created: 05-10-2019
// Multi-Paredigm Programming, GMIT 2019
// Lecturer: Dominic Carr

// ===== ===== =====
// Importing external libraries

#include <stdio.h>
#include <string.h>

// ----- ----- -----
// Definiton of objects' constructors (aka classes).

// This constructor defines of products the shop offers to sell.
struct Product
{
  char *name;   // * (asterix) indicates a pointer and will allow for dynamic memory allocation, because the length of the product name is not yet know.
  double price; // double float data type for the product price.
};

// This constructor defines the (!) product (because of cross reference to another constructor) available quantity in the shop.
struct ProductStock
{
  struct Product product; // cross reference to 'Product' constructor; struct type.
  int quantity;           // quantity of the product available in the shop.
};

// This constructor defines the shop entity. The constructor variable stock is predefined (and cross referred to another constructor).
struct Shop
{
  double cash;                   // The amount of maney in the shop.
  struct ProductStock stock[20]; // Cross-relationship to 'ProductStock' struct; predefined value is set. This variable will limit of purchased items.
};

// This constructor defines the customer blueprint.
struct Customer
{
  char *name;                           // Pointer is used here, so that the length of memor is dynamically allocated.
  double budget;                        // This variable will limit the customer buying capacity.
  struct ProductStock shoppingList[10]; // Relational to 'ProductStock' struck, predefined.
};

// ----- ----- -----
// Main program body

int main(void) // The 'main' function is of 'int' type, and does not return anything.
{
  // Initialisation of a customer. Note, only two of three variables are being defined here. 'shoppingList has already a value predefined in the moment of cration.
  struct Customer customer1 = {"Andrzej", 123.45}; // Andrzej with budget 123.45 has been assigned to instance 'customer1' of 'Customer' class.
  printf("\n");
  printf("Customer name is %s. His/her current budget is €%.2f.\n", customer1.name, customer1.budget); // This line is used as a check.

  // Initialisation of a prodct.
  struct Product prod1 = {"SoftDrink Can", 0.85}; // Product's name and price assigned to instance 'prod1' of 'Product' class.
  printf("\n");
  printf("This is %s. One item costs €%.2f.\n", prod1.name, prod1.price); // This line is used as a check.

  // Initialisation of a prodct stock available amount.
  struct ProductStock prod1Stock = {prod1, 134}; // Product's refernce to 'prod1' (of 'Product' struct) and available amount.
  printf("\n");
  printf("Available quantity of product %s is %d.\n", prod1Stock.product.name, prod1Stock.quantity); // This line is used as a check.

  return 0;
}