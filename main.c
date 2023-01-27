#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define  TRUE   1
#define  FALSE  0

typedef struct Post Post;
typedef struct User User;
/*
sakhtar dade post ha va karbar ha hamrah ba option ha
*/
struct Post
{
    char* name;
    int post_ID;
    int likes;
    char* text;
    struct Post *next;
};

struct User
{
    char* name;
    char* password;
    Post* posts;
    int post_num;
    struct User *next;
};
/*
tabe compare do reshte ra cheak mikonad ke mosavi hastand ya khayr
*/
int compare(char* first_arr, char* second_arr)
{
    int i=0;
    while(first_arr[i]!='\0' && second_arr[i]!='\0')
    {
        if(first_arr[i]!=second_arr[i])return 0;
        i++;
    }
    if(first_arr[i]!=second_arr[i])return 0;
    return 1;
}
/*
tabe size_string size reshte vorodi ra hesab karde va khoroji midahad
*/
int size_string(char* arr)
{
    int i=0;
    while(arr[i]!='\0')
    {
        i++;
    }
    return i;
}

#include "signup.h"
#include "post.h"

/*
tabe logout
ebteda cheak mikonad login kardi ya na
aghar karde bood logout mikonad
*/

User* logout(User* user)
{
    if(user==NULL)
    {
        printf("login first\n");
        return NULL;
    }
    printf("logout successfull\n");
    return NULL;
}

/*
tabe like
ebteda da user ha donbal user morad nazar mighardad
aghar peyda kard dar post haye user peyda shode donbal on post mighardad va on ra like mikonad
aghar ham moshkeli pish ayad payam monaseb ra chap mikonad
*/

void like(User* users, char* name, int post_ID)
{
    User* find=NULL;
    while(users->next!=NULL)
    {
        if(compare(users->next->name, name))
        {
            find = users->next;
            break;
        }
        users = users->next;
    }
    if(find == NULL)printf("user not found\n");
    else{
        Post* posts = find->posts;
        while(posts->next!=NULL)
        {
            if(posts->post_ID == post_ID)
            {
                posts->likes++;
            }
            posts = posts->next;
        }
        if(posts->post_ID == post_ID)
        {
            posts->likes++;
        }
        printf("post liked\n");
    }
}

/*
tabe find_user
ebteda dar liked list users mighardad va karbar mored nazar ra peyda mikonad
sepas name password va post haye on karbar ra neshan midahad
*/
int find_user(User* users, char* name)
{
    User* user_head = users->next;
    while(user_head->next!=NULL)
    {
        if(compare(name, user_head->name))
        {
            User* login = user_head;
            printf("name:%s\n", login->name);
            //printf("password:%s\n", login->password);
            Post* posts = (login->posts);
            while(posts->next!=NULL)
            {
                printf("text:%s\n", posts->next->text);
                printf("post_ID:%d\n", posts->next->post_ID);
                printf("likes:%d\n\n", posts->next->likes);
                posts = posts->next;
            }
            return 0;
        }
        user_head = user_head->next;
    }
    if(compare(name, user_head->name)){
        User* login = user_head;
        printf("name:%s\n", login->name);
        //printf("password:%s\n", login->password);
        Post* posts = (login->posts);
        while(posts->next!=NULL)
        {
            printf("text:%s\n", posts->next->text);
            printf("post_ID:%d\n", posts->next->post_ID);
            printf("likes:%d\n\n", posts->next->likes);
            posts = posts->next;
        }
        return 0;
    }
    printf("not found\n");
}

/*
tabe show
yek tabe komaki baraye debug ast ke matn post haye yek karbar ra neshan midahad
*/

void show(User* login)
{
    Post* post = (login->posts)->next;
    while(post->next!=NULL)
    {
        printf("%s ",post->text);
        post=post->next;
    }
    printf("%s ",post->text);
}
int main(){
    User* users = (User*)malloc(sizeof(User));
    User* login = NULL;
    users->next = NULL;
    char s[50];
    /*
    dar tabe main yek loop binahayat darim
    motanaseb ba dastor vared shode kar mad nazar ra anjam midahad
    aghar dastor eshtebah dad matn monaseb ra chap mikonad
    */

    while(TRUE){
        scanf("%s", s);
        if(compare(s, "signup"))
        {
            char name[50], password[50];
            scanf("%s %s", name, password);
            //printf("%s %s", name, password);
            signup(users, name, password);
        }
        else if(compare(s, "login"))
        {
            /*
            dar linked list users mighardad va user mad nazar ra peyda mikonad
            aghar password eshtebah bood payam password incorrect ra chap mikonad
            */

            char name[50], password[50];
            int is_login = 0;
            scanf("%s %s", name, password);
            User* user_head = users->next;
            while(user_head->next!=NULL)
            {
                if(compare(name, user_head->name)&& !compare(password, user_head->password))
                {
                    printf("password incorrect\n");
                    is_login=-1;
                }
                if(compare(name, user_head->name)&& compare(password, user_head->password))
                {
                    login = user_head;
                    is_login=1;
                    break;
                }
                user_head = user_head->next;
            }
            if(compare(name, user_head->name)&& compare(password, user_head->password))
            {
                login = user_head;
                is_login=1;
            }
            if(!is_login)
            {
                printf("user not found\n");
            }
        }
        else if(compare(s, "post"))
        {
            char s[1000];
            int i=0;
            while(TRUE)
            {
                scanf("%c", &s[i]);
                if(s[i]=='\n')break;
                i++;
            }
            s[i]='\0';
            if(login!=NULL)
            {
                Add(login, s);
            }
            else
            {
                printf("login first\n");
            }
        }
        else if(compare(s, "delete"))
        {
            delete(login);
        }
        else if(compare(s,"logout"))
        {
            login = logout(login);
        }
        else if(compare(s,"like"))
        {
            char name[50];
            int post_ID;
            scanf("%s %d", name, &post_ID);
            like(users, name, post_ID);
        }
        else if(compare(s,"info")&& login!=NULL)
        {
            /*
            name va password login user ra chap konad sepas post haye on ra chap kkonad
            */
            printf("name:%s\n", login->name);
            printf("password:%s\n", login->password);
            Post* posts = (login->posts)->next;
            while(posts->next!=NULL)
            {
                printf("text:%s\n", posts->text);
                printf("post_ID:%d\n", posts->post_ID);
                printf("likes:%d\n\n", posts->likes);
                posts = posts->next;
            }
            printf("text:%s\n", posts->text);
            printf("post_ID:%d\n", posts->post_ID);
            printf("likes:%d\n\n", posts->likes);
        }
        else if(compare(s,"info")&& login==NULL)
        {
            printf("please login\n");
        }
        else if(compare(s,"find_user"))
        {
            char name[50];
            scanf("%s", name);
            find_user(users,name);
        }
        else
        {
            printf("command dorost bede!!!!!!\n");
        }
        /*
        save in files
        ebteda do file ra baraye zakhire etelaat baz mikonim
        sepas ba tavajoh be linked list users info ha va post haye har user ra zakhire mikonim
        */
        FILE* ufile = fopen("accounts.txt", "w");
        FILE* pfile = fopen("posts.txt", "w");
        User* save_user = users;
        while(save_user->next!=NULL)
        {
            fwrite(save_user->next->name, 1, size_string(save_user->next->name),ufile);
            fwrite(save_user->next->password, 1, size_string(save_user->next->password),ufile);
            fwrite("\n",1,1,ufile);

            Post* posts = save_user->next->posts;
            while((posts)->next!=NULL)
            {
                fwrite(posts->next->text, 1, size_string(posts->next->text), pfile);
                fwrite(save_user->next->name, 1, size_string(save_user->next->name),pfile);
                fwrite("\n",1,1,pfile);
                posts=posts->next;
            }
            save_user = save_user->next;
        }
        fclose(pfile);
        fclose(ufile);

    }
}
