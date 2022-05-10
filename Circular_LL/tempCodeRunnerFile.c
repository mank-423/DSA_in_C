do
    {
        printf("Element: %d \n",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);