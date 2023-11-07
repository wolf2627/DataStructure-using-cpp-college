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
        Node* x = new Node(coef, exp);

        if (head == NULL || exp > head->exp) {
            x->next = head;
            head = x;
        } else {
            Node* y = head;
            while (y->next != NULL && exp < y->next->exp) {
                y = y->next;
            }
            x->next = y->next;
            y->next = x;
        }
    }

    Polynomial addSubtractPolynomials(Polynomial& other, bool isAddition) {
        Polynomial result;
        Node* y1 = head;
        Node* y2 = other.head;

        while (y1 != NULL && y2 != NULL) {
            if (y1->exp == y2->exp) {
                int resultCoef = isAddition ? (y1->coef + y2->coef) : (y1->coef - y2->coef);
                result.insertTerm(resultCoef, y1->exp);
                y1 = y1->next;
                y2 = y2->next;
            } else if (y1->exp > y2->exp) {
                result.insertTerm(y1->coef, y1->exp);
                y1 = y1->next;
            } else {
                int resultCoef = isAddition ? y2->coef : -y2->coef;
                result.insertTerm(resultCoef, y2->exp);
                y2 = y2->next;
            }
        }

        while (y1 != NULL) {
            result.insertTerm(y1->coef, y1->exp);
            y1 = y1->next;
        }

        while (y2 != NULL) {
            int resultCoef = isAddition ? y2->coef : -y2->coef;
            result.insertTerm(resultCoef, y2->exp);
            y2 = y2->next;
        }

        return result;
    }

    void display() {
        Node* y = head;
        while (y != NULL) {
            if(y->coef < 0){
                cout<<"("<<y->coef << "x^" << y->exp<<")";
            } else {
            cout << y->coef << "x^" << y->exp;
            }
            if (y->next != NULL) {
                cout << " + ";
            }
            y = y->next;
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
