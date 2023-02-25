#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

// create a node with data as x
struct Node *create_node(int x)
{
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node(struct Node *ptr)
{
    free(ptr);
}

// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node *PythonListHead = NULL;

// prints the list in space seperated format
void print_list(struct Node *head)
{
    struct Node *cur = head;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// Add an item to the end of the list
void append(int x)
{
    if (PythonListHead == NULL)
    {
        PythonListHead = create_node(x);
    }
    else
    {
        struct Node *curr = PythonListHead;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = create_node(x);
    }
}

// Insert an item at a given position.
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x)
{
    if (PythonListHead == NULL)
    {
        return;
    }
    if (position == 0)
    {
        struct Node *head = PythonListHead;
        PythonListHead = create_node(x);
        PythonListHead->next = head;
        return;
    }
    int result = 0;
    if (PythonListHead != NULL)
    {
        struct Node *curr = PythonListHead;
        while (curr)
        {
            result++;
            curr = curr->next;
        }
    }
    if (position >= result)
    {
        return;
    }
    struct Node *curr = PythonListHead;
    int idx = 1;
    while (idx < position)
    {
        curr = curr->next;
        idx++;
    }
    struct Node *temp = curr->next;
    curr->next = create_node(x);
    curr->next->next = temp;
}

// Remove the item at the end of the list
void pop()
{
    if (PythonListHead == NULL)
    {
        return;
    }
    struct Node *curr = PythonListHead;
    if (curr->next == NULL)
    {
        delete_node(curr);
        PythonListHead = NULL;
        return;
    }
    while (curr->next->next)
    {
        curr = curr->next;
    }
    delete_node(curr->next);
    curr->next = NULL;
}

// Remove all items from the list
void clear()
{
    while (PythonListHead != NULL)
    {
        pop();
    }
}

// Return the number of times x appears in the list.
int count(int x)
{
    int result = 0;
    if (PythonListHead != NULL)
    {
        struct Node *curr = PythonListHead;
        while (curr)
        {
            if (curr->data == x)
            {
                result++;
            }
            curr = curr->next;
        }
    }
    return result;
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse()
{
    if (PythonListHead != NULL)
    {
        struct Node *before = PythonListHead;
        struct Node *curr = before->next;
        before->next = NULL;
        struct Node *temp = NULL;
        while (curr)
        {
            temp = curr->next;
            curr->next = before;
            before = curr;
            curr = temp;
        }
        PythonListHead = before;
    }
}

// Return the number of elements in the list
int len()
{
    int result = 0;
    if (PythonListHead != NULL)
    {
        struct Node *curr = PythonListHead;
        while (curr)
        {
            result++;
            curr = curr->next;
        }
    }
    return result;
}

// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x)
{
    if (position < len())
    {
        int idx = 0;
        struct Node *curr = PythonListHead;
        while (idx < position)
        {
            curr = curr->next;
            idx++;
        }
        curr->data = x;
    }
}

// Return the data of the node at `position`
// if no such position, return -1
int getitem(int position)
{
    // your code goes here
    int result = -1;
    if (position < len())
    {
        int idx = 0;
        struct Node *curr = PythonListHead;
        while (idx < position)
        {
            curr = curr->next;
            idx++;
        }
        result = curr->data;
    }
    return result;
}

// erase the node at position
// if no such position, do nothing
void erase(int position)
{
    if (position < len())
    {
        if (position == 0)
        {
            struct Node *temp = PythonListHead->next;
            delete_node(PythonListHead);
            PythonListHead = temp;
        }
        else
        {
            struct Node *curr = PythonListHead;
            int idx = 1;
            while (idx < position)
            {
                curr = curr->next;
                idx++;
            }
            struct Node *temp = curr->next->next;
            delete_node(curr->next);
            curr->next = temp;
        }
    }
}

// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node *index_into(int *positions, int n)
{
    struct Node *head = NULL;
    struct Node *curr = NULL;
    int length = len();
    for (int i = 0; i < n; i++)
    {
        if (positions[i] < length)
        {
            if (head == NULL)
            {
                head = create_node(getitem(positions[i]));
                curr = head;
            }
            else
            {
                curr->next = create_node(getitem(positions[i]));
                curr = curr->next;
            }
        }
    }
    return head;
}

// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position)
{
    if (position + 1 < len())
    {
        if (position == 0)
        {
            struct Node *temp = PythonListHead;
            PythonListHead = PythonListHead->next;
            temp->next = PythonListHead->next;
            PythonListHead->next = temp;
        }
        else
        {
            int idx = 1;
            struct Node *curr = PythonListHead;
            while (idx < position)
            {
                idx++;
                curr = curr->next;
            }
            struct Node *temp = curr->next;
            curr->next = curr->next->next;
            temp->next = curr->next->next;
            curr->next->next = temp;
        }
    }
}

// sort the Python list
// you may use the above defined swap function to
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort()
{
    if (PythonListHead == NULL)
    {
        return;
    }
    int length = len(), flag = 1, idx = 0;
    struct Node *curr = PythonListHead;
    while (flag)
    {
        flag = 0;
        idx = 0;
        curr = PythonListHead;
        while (curr->next)
        {
            if (curr->data > curr->next->data)
            {
                swap(idx);
                flag = 1;
            }
            else
            {
                curr = curr->next;
            }
            idx++;
        }
    }
}

// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while (T--)
    {
        scanf("%s", operation_type);

        if (strcmp(operation_type, "append") == 0)
        {
            int x;
            scanf("%d", &x);
            append(x);
        }

        if (strcmp(operation_type, "insert") == 0)
        {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if (strcmp(operation_type, "pop") == 0)
        {
            pop();
        }

        if (strcmp(operation_type, "clear") == 0)
        {
            clear();
        }

        if (strcmp(operation_type, "count") == 0)
        {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if (strcmp(operation_type, "reverse") == 0)
        {
            reverse();
        }

        if (strcmp(operation_type, "len") == 0)
        {
            int length = len();
            printf("%d\n", length);
        }

        if (strcmp(operation_type, "setitem") == 0)
        {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if (strcmp(operation_type, "getitem") == 0)
        {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if (strcmp(operation_type, "print") == 0)
        {
            print_list(PythonListHead);
        }

        if (strcmp(operation_type, "erase") == 0)
        {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if (strcmp(operation_type, "swap") == 0)
        {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if (strcmp(operation_type, "index_into") == 0)
        {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
                scanf("%d", &indices[i]);
            struct Node *new_head = index_into(indices, n);
            print_list(new_head);
        }

        if (strcmp(operation_type, "sort") == 0)
        {
            sort();
        }
    }
}

// int main()
// {
//     append(2);
//     append(3);
//     append(4);
//     append(5);
//     print_list(PythonListHead);
//     clear();
//     print_list(PythonListHead);
//     append(3);
//     append(2);
//     append(3);
//     append(4);
//     append(5);
//     print_list(PythonListHead);
//     printf("%d\n", count(3));
//     clear();
//     printf("%d\n", count(3));
//     append(1);
//     append(2);
//     append(3);
//     append(4);
//     print_list(PythonListHead);
//     reverse();
//     print_list(PythonListHead);
//     clear();
//     append(1);
//     print_list(PythonListHead);
//     reverse();
//     print_list(PythonListHead);
//     append(2);
//     print_list(PythonListHead);
//     append(4);
//     print_list(PythonListHead);
//     reverse();
//     print_list(PythonListHead);
//     pop();
//     print_list(PythonListHead);
//     printf("%d\n", len());
//     setitem(0, 3);
//     print_list(PythonListHead);
//     setitem(1, 4);
//     print_list(PythonListHead);
//     erase(0);
//     print_list(PythonListHead);
//     erase(0);
//     print_list(PythonListHead);
//     append(1);
//     append(4);
//     append(6);
//     append(8);
//     print_list(PythonListHead);
//     reverse();
//     print_list(PythonListHead);
//     erase(3);
//     print_list(PythonListHead);
//     erase(1);
//     print_list(PythonListHead);
//     append(6);
//     append(5);
//     swap(0);
//     print_list(PythonListHead);
//     swap(1);
//     print_list(PythonListHead);
//     swap(2);
//     print_list(PythonListHead);
//     swap(3);
//     print_list(PythonListHead);
//     append(78);
//     swap(3);
//     print_list(PythonListHead);
//     swap(0);
//     print_list(PythonListHead);
//     int arr[] = {0, 2, 3, 4, 5, 6};
//     struct Node *head = index_into(arr, 6);
//     print_list(head);
//     sort();
//     print_list(PythonListHead);
// }