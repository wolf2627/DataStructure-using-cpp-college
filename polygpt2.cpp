#include <iostream>
using namespace std;

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    Term* next;

    Term(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = new Term(0, 0); // Initialize an empty result polynomial
    Term* y = result; // Initialize the y node of the result

    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            y->next = new Term(poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            y->next = new Term(poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                y->next = new Term(sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        y = y->next;
    }

    // Append any remaining terms
    while (poly1) {
        y->next = new Term(poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
        y = y->next;
    }

    while (poly2) {
        y->next = new Term(poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
        y = y->next;
    }

    return result->next;
}

// Function to subtract two polynomials
Term* subtractPolynomials(Term* poly1, Term* poly2) {
    // Create a copy of the second polynomial and negate its coefficients
    Term* negPoly2 = nullptr;
    Term* temp = poly2;
    while (temp) {
        negPoly2 = new Term(-temp->coefficient, temp->exponent);
        temp = temp->next;
    }

    // Add the first polynomial and the negated second polynomial
    return addPolynomials(poly1, negPoly2);
}

// Function to display a polynomial
void displayPolynomial(Term* poly, bool firstTerm = true) {
    if (!poly) {
        if (firstTerm) {
            cout << "0" << endl;
        }
        return;
    }

    if (!firstTerm) {
        if (poly->coefficient >= 0) {
            cout << " + ";
        } else {
            cout << " - ";
        }
    }

    cout << abs(poly->coefficient);
    if (poly->exponent > 0) {
        cout << "x^" << poly->exponent;
    }
    if (!poly->next) {
        cout << endl;
    }

    displayPolynomial(poly->next, false);
}

// Function to input a polynomial from the user
Term* inputPolynomial() {
    int coeff, exp;
    Term* poly = nullptr;
    Term* y = nullptr;

    cout << "Enter the terms of the polynomial (0 0 to end input):\n";
    while (true) {
        cin >> coeff >> exp;
        if (coeff == 0 && exp == 0) {
            break;
        }
        Term* newTerm = new Term(coeff, exp);
        if (y) {
            y->next = newTerm;
            y = y->next;
        } else {
            poly = newTerm;
            y = poly;
        }
    }

    return poly;
}

// Function to delete a polynomial
void deletePolynomial(Term* poly) {
    while (poly) {
        Term* temp = poly;
        poly = poly->next;
        delete temp;
    }
}

int main() {
    Term* poly1 = inputPolynomial();
    Term* poly2 = inputPolynomial();

    cout << "Polynomial 1: ";
    displayPolynomial(poly1);
    cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    Term* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    displayPolynomial(sum);

    Term* diff = subtractPolynomials(poly1, poly2);
    cout << "Difference: ";
    displayPolynomial(diff);

    // Clean up memory
    deletePolynomial(poly1);
    deletePolynomial(poly2);
    deletePolynomial(sum);
    deletePolynomial(diff);

    return 0;
}
