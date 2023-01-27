
void Add(User* user, char* s)
{
    Post* new = (Post*)malloc(sizeof(Post));
    user->post_num++;
    new->name = user->name;
    new->post_ID = user->post_num;
    new->likes = 0;
    new->text= (char*)malloc(sizeof(char)*size_string(s));
    strcpy(new->text, s);
    new->next = NULL;
    Post *posts = user->posts;
    while((posts)->next!=NULL)
    {
        posts = posts->next;
    }
    posts->next = new;
}
void delete(User* user){
    int i=0, is_delete=0;
    scanf("%d", &i);
    Post *posts = user->posts;
    while(TRUE)
    {
        if(posts->next==NULL)
        {
            break;
        }
        if(posts->next->post_ID == i)
        {
            free(posts->next);
            posts->next = posts->next->next;
            is_delete=1;
            break;
        }
        posts = posts->next;
    }
    if(!is_delete)
    {
        printf("not found\n");
    }

}
