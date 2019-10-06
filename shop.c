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
  struct ProductStock shoppingList[10]; // Relational to 'ProductStock' struck, predefined size of the array (amount of items a customer may hold).
  int index;                            // This variable keeps track of number of products the customer has.
};

// ----- ----- -----
// Methods

// Printing product info
void printProduct(struct Product prod) // This method requires a struct 'Product', named localy within the method as 'prod'. The method does not return anything.
{
  printf("Product Name: %s \nProduct Price: €%.2f \n", prod.name, prod.price); // Values of prod.name and prod.price are referring to product's properties defined the strut instance (within 'Main' method).
}

// Printing customer info
void printCustomer(struct Customer cust) // This method requires a struct 'Customer', named localy within the method as 'cust'. The method does not return anything.
{
  printf("-----\nCustomer Name: %s \nCustomer Budget: €%.2f \n\n-----\n", cust.name, cust.budget); // Values of cust.name and cust.budget are referring to customer's details defined the strut instance (within 'Main' method).
  // Below we are going to print all the items (for loop) the customer has.
  for (int i = 0; i < cust.index; i++) // Iteration of from i=0, increasing by 1, up to ...
  {
    printProduct(cust.shoppingList[i].product); // Uses previously defined method 'printProduct', and passes i-th product from the customer's shoppingList (?).
    printf("%s orders %d of above product.\n\n", cust.name, cust.shoppingList[i].quantity);
  }
}

// ----- ----- -----
// Main program body

int main(void) // The 'main' function is of 'int' type, and does not return anything.
{
  // Initialisation of a customer. Note, only two of three variables are being defined here. 'shoppingList has already a value predefined in the moment of cration.
  struct Customer customer1 = {"Andrzej", 123.45}; // Andrzej with budget 123.45 has been assigned to instance 'customer1' of 'Customer' class.
  printf("\n");
  // obsolete // printf("Customer name is %s. His/her current budget is €%.2f.\n", customer1.name, customer1.budget); // This line is used as a check.

  // Initialisation of products.
  struct Product prod1 = {"SoftDrink Can", 0.90}; // Product's name and price assigned to instance 'prod1' of 'Product' class.
  printf("\n");
  // obsolete // printf("This is %s. One item costs €%.2f.\n", prod1.name, prod1.price); // This line is used as a check.
  printProduct(prod1);

  struct Product prod2 = {"Bread", 1.30}; // Product's name and price assigned to instance 'prod1' of 'Product' class.
  printf("\n");
  printProduct(prod2);

  // Initialisation of prodcts quantity the customer desires.
  struct ProductStock prod1Stock = {prod1, 4}; // Product's refernce to 'prod1' (of 'Product' struct) and quantity the customer desires.
  struct ProductStock prod2Stock = {prod2, 2};
  printf("\n");
  // obsolete // printf("Available quantity of product %s is %d.\n", prod1Stock.product.name, prod1Stock.quantity); // This line is used as a check.
  customer1.shoppingList[customer1.index++] = prod1Stock; // Iterates through products the customer has. The index by default is zero, but increases each time it is accessed.
  customer1.shoppingList[customer1.index++] = prod2Stock;
  printCustomer(customer1);

  return 0;
}