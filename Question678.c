//
// Created by Kimsay Kong on 2022-02-09.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum { ATOM, LIST } eltype;

typedef char atom;

struct _listnode;

typedef struct {
    eltype type;
    union {
        atom a;
        struct _listnode* l;
    };
} element;

typedef struct _listnode {
    element el;
    struct _listnode* next;
} * list;

const element NIL = { .type=LIST, .l=NULL };

/// Helpers ///

int isNil(element e) {
    return e.type == LIST && e.l == NULL;
}

list nil() {
    list l = (list) malloc(sizeof(element) + sizeof(list));
    l->el = NIL;
    l->next = NULL;
    return l;
}
/**
 * Question 6 functions
 */

/**
 * atom as element, that returns an element whose content is set to atom a.
 */
element aasel(atom a) {
    return (element) {
            .type = ATOM,
            .a = a
    };
}

/**
 * list as element, that returns an element whose content is set to the list, pointed by l.
 */
element lasel(list l) {
    return (element) {
            .type = LIST,
            .l = l
    };
}

/**
 * that returns the head of the list, represented by e; returns NIL, if e is not a list
 */
element car(element e) {
    if (e.type != LIST) {
        return NIL;
    }
    return e.l->el;
}

// that returns tail of the list, represented by e. The tail of a list
// with one or zero element is NIL. The tail of an element that is not a list is also NIL.
list cdr(element e) {
    if (e.type != LIST) {
        return nil();
    }

    list tail = e.l->next;

    return tail != NULL ? tail : nil();
}

/**
 * that returns the cdr of the cdr of the list, represented by e.
 */
list cddr(element e) {
    list tail = cdr(e);

    if (isNil(tail->el)) {
        return nil();
    }

    return cdr(tail->el);
}

/**
 * that creates a new list whose car and cdr are the element e and the list l.
 * The memory for the newly created list is to be allocated dynamically.
 */
list cons(element e, list l) {
    list newList = nil();
    newList->el = e;
    newList->next = l;
    return newList;
}

// `append` creates a new list whose elements are shallow copies of elements in l1 and l2, appended.
list append(list l1, list l2) {
    list newList = nil();
    newList->el = lasel(l1);
    newList->next = l2;
    return newList;
}

void _free(element e);

//that frees all the memory previously allocated by the whole list
void lfreer(list l) {
    if (l == NULL) {
        return;
    }
    _free(l->el);
    lfreer(l->next);
    free(l);
}

void _free(element e) {
    if (e.type == LIST) {
        lfreer(e.l);
    }
}

void _printList(list l);
/**
 * that prints the content of the element e.
 * If e is an atom, it prints the char symbol embraced in spaces, and if e it is a list, it (recursively) prints the elements of the list enclosed in parentheses (`(` and `)').
 * If e is NIL, the word "NIL" is printed
 */
void print(element e) {
    if (e.type == ATOM) {
        printf(" %c ", e.a);
    } else if (isNil(e)) {
        printf("NIL");
    } else {
        printf("(");
        print(e.l->el);
        _printList(e.l->next);
        printf(")");
    }
}

void _printList(list l) {
    if (l != NULL) {
        print(l->el);
        _printList(l->next);
    }
}

void printList(list l) {
    printf("(");
    _printList(l);
    printf(")");
}

/**
 * Helper function to create last node for question 7
 */
list atomNode(atom a) {
    list l = nil();
    l->el = aasel(a);
    return l;
}
int main(){
/**
   * Question 7
   */

    element motherOfAllList = lasel(
            cons(
                    aasel('a'), // a -> ...
                    cons(
                            lasel(cons(aasel('b'), atomNode('c'))), // b -> c
                            cons(aasel('d'), atomNode('e')) // d -> e
                    )
            )
    );

    print(motherOfAllList);
    printf("\n");

    /**
     * Question 8
     */
    print(car(motherOfAllList));
    printf("\n");
    printList(cdr(motherOfAllList));
    printf("\n");
    print(car(car(motherOfAllList)));

    lfreer(motherOfAllList.l);
    return 0;
}