void deleteNodes(struct Node **head, int pos) {
    // Check if the position is valid
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    // Check if the linked list is empty
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    // If the node to be deleted is the head
    if (pos == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *t = *head;
    int cnt = 1;
    while (cnt < pos - 1) {
        if (t->next == NULL) {
            printf("Position is out of range\n");
            return;
        }
        t = t->next;
        cnt += 1;
    }

    if (t->next != NULL) {
        struct Node *temp = t->next;
        t->next = t->next->next;
        free(temp);
    } else {
        printf("Position is out of range\n");
    }
}