#include<stdbool.h>
typedef struct node
{
    char song[50];
    char artist[20];
    int like;
    struct node *prev;
    struct node *next;
}node;
void create_list(node **head, node **tail);
void Insert(node **head,node **tail,char sng[],char art[],int newlike);
bool Is_Empty(node **h);
void Delete(node **head,node **tail,char sng[]);
void recently_played(node **head1,node **tail1,int newlike,char sng[],char art[]);
void recently_played_display(node *head1);
void display(node *head);
void shuffle(node *head,node **head1,node **tail1);
void Liked(node *head);
void previoussong(node **head,node **tail,char sng[],node **head1,node **tail1);
void nextsong(node **head,node **tail,char sng[],node **head1,node **tail1);
void loop(node **head,node **tail,char song1[] ,node **head1,node **tail1);
void particular(node **head,node **tail,char song1[],node **head1,node **tail1);
void wholeplaylist(node **head,node **head1,node **tail1);
void tempqueue (node **head,node **tail,node **head1,node **tail1);
void Romantic(node **head1,node **tail1);
void Happy(node **head1,node **tail1);
void Mood_Booster(node **head1,node **tail1);
void Sad(node **head1,node **tail1);
void Work_Out(node **head1,node **tail1);
void mood_songs(node **head1,node **tail1);
