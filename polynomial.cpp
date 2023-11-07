#include <iostream>
using namespace std;

class Node {
public:
    int coef;
    int exp;
    Node* next;

    Node(int c, int e) {
        coef = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = NULL;
    }

    void insertTerm(int coef, int exp) {
        Node* y = new Node(coef, exp);

        if (head == NULL || exp > head->exp) {
            y->next = head;
            head = y;
        } else {
            Node* current = head;
            while (current->next != NULL && exp < current->next->exp) {
                current = current->next;
            }
            y->next = current->next;
            current->next = y;
        }
    }

    Polynomial addSubtractPolynomials(Polynomial& other, bool isAddition) {
        Polynomial result;
        Node* current1 = head;
        Node* current2 = other.head;

        while (current1 != NULL && current2 != NULL) {
            if (current1->exp == current2->exp) {
                int resultCoef = isAddition ? (current1->coef + current2->coef) : (current1->coef - current2->coef);
                result.insertTerm(resultCoef, current1->exp);
                current1 = current1->next;
                current2 = current2->next;
            } else if (current1->exp > current2->exp) {
                result.insertTerm(current1->coef, current1->exp);
                current1 = current1->next;
            } else {
                int resultCoef = isAddition ? current2->coef : -current2->coef;
                result.insertTerm(resultCoef, current2->exp);
                current2 = current2->next;
            }
        }

        while (current1 != NULL) {
            result.insertTerm(current1->coef, current1->exp);
            current1 = current1->next;
        }

        while (current2 != NULL) {
            int resultCoef = isAddition ? current2->coef : -current2->coef;
            result.insertTerm(resultCoef, current2->exp);
            current2 = current2->next;
        }

        return result;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->coef << "x^" << current->exp;
            if (current->next != NULL) {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1;
    Polynomial poly2;

    int n1, n2;
    int coef, exp;

    cout << "Enter the number of terms in Polynomial 1: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Enter coefficient and exponent for term " << (i + 1) << ": ";
        cin >> coef >> exp;
        poly1.insertTerm(coef, exp);
    }

    cout << "Enter the number of terms in Polynomial 2: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Enter coefficient and exponent for term " << (i + 1) << ": ";
        cin >> coef >> exp;
        poly2.insertTerm(coef, exp);
    }

    Polynomial additionResult = poly1.addSubtractPolynomials(poly2, true);
    Polynomial subtractionResult = poly1.addSubtractPolynomials(poly2, false);

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    cout << "Addition Result: ";
    additionResult.display();

    cout << "Subtraction Result: ";
    subtractionResult.display();

    return 0;
}
