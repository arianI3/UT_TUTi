void signup(User* head, char* name, char* password)
{
    User* new_node = (User*)malloc(sizeof(User));
    new_node->name = (char*)malloc(sizeof(char)*size_string(name));
    strcpy(new_node->name, name);
    new_node->password = (char*)malloc(sizeof(char)*size_string(password));
    strcpy(new_node->password, password);
    new_node->next = NULL;
    new_node->post_num = 0;
    new_node->posts = (Post*)malloc(sizeof(Post));
    (new_node->posts)->next = NULL;
    while(head->next!=NULL)
    {
        head = head->next;
    }
    head->next = new_node;
}
