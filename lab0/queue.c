/*
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

 /*
  * This program implements a queue supporting both FIFO and LIFO
  * operations.
  *
  * It uses a singly-linked list to represent the set of queue elements
  */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

  /*
    Create empty queue.
    Return NULL if could not allocate space.
  */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (q == NULL) {
        return;
    }
    list_ele_t *cur = q->head;
    while (cur != NULL) {
        list_ele_t *next = cur->next;
        free(cur);
        cur = next;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    if (q == NULL) {
        return false;
    }
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) {
        return false;
    }
    newh->value = v;

    /* set the new head */
    newh->next = q->head;
    q->head = newh;
    q->size++;

    /* modify the tail accordingly */
    if (q->tail == NULL) {
        q->tail = newh;
    }
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL) {
        return false;
    }
    list_ele_t *ele = (list_ele_t *)malloc(sizeof(list_ele_t));
    if (ele == NULL) {
        return false;
    }
    ele->value = v;
    ele->next = NULL;

    /* link it to the tail */
    q->tail->next = ele;
    q->tail = ele;
    q->size++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if (q == NULL || q->head == NULL) {
        return false;
    }
    list_ele_t *ele = q->head;
    q->head = ele->next;
    q->size--;
    if (q->tail == ele) {
        q->tail = NULL;
    }
    if (vp != NULL) {
        *vp = ele->value;
    }
    free(ele);
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q == NULL) {
        return 0;
    }
    return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL || q->head == NULL) {
        return;
    }
    /* switch the head and the tail */
    q->tail = q->head;
    list_ele_t *cur = q->head->next;
    q->head->next = NULL;
    while (cur != NULL) {
        list_ele_t *next = cur->next;
        cur->next = q->head;
        q->head = cur;
        cur = next;
    }
}

