#include"jukebox.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void create_list(node **head, node **tail)
{
    *head=NULL;
    *tail=NULL;
}
void Insert(node **head,node **tail,char sng[],char art[],int newlike)//this will be used to insert songs in the playlist
 {                                                                    //insertion at beginning
    node *temp=(node*)malloc(sizeof(node));
    strcpy(temp->song,sng);
    strcpy(temp->artist,art);
    temp->like=newlike;
    temp->prev=NULL;
    temp->next=*head;
    if(*head!=NULL)
        (*head)->prev=temp;
        *head=temp;
    if(*tail==NULL)
    {
        *tail=temp;
    }
}
bool Is_Empty(node **h)//checks if the list is empty or not
{
    if(*h==NULL)
        return 1;
    else
        return 0;
}
void Delete(node **head,node **tail,char sng[])//this will delete song from the playlist.
{
    if(!Is_Empty(head))         //deletion at beginning
    {
        if(strcmp((*head)->song,sng)==0)
        {

        if(*head==*tail)
        {
            free(*head);
            *head=NULL;
            *tail=NULL;
            printf("\t\t\t\t\t\t\tSong Deleted Successfully\n");
            return;
        }
        *head=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
        printf("\t\t\t\t\t\t\tSong Deleted Successfully\n");
        return;
        }
        if(strcmp((*tail)->song,sng)==0) //deletion at end
        {
           if(*head==*tail)
        {
            free(*head);
            *head=NULL;
            *tail=NULL;
            printf("\t\t\t\t\t\t\tSong Deleted Successfully\n");
            return;
        }
        *tail=(*tail)->prev;
        free((*tail)->next);
        (*tail)->next=NULL;
        printf("\t\t\t\t\t\t\tSong Deleted Successfully\n");
        return;
        }
        node *crt=*head;
        while(crt->next!=NULL && strcmp(crt->next->song,sng)!=0)  //deletion after a particular song
            crt=crt->next;
        if(crt==*tail || crt->next==*tail)
        {
            printf("\t\t\t\t\t\t\tSong not present in the list\n");
            return;
        }
        node *temp=crt->next;
        temp->next->prev=crt;
        crt->next=temp->next;
        free(temp);
        printf("\t\t\t\t\t\t\tSong Deleted Successfully\n");
    }
    else
        printf("\t\t\t\t\t\t\tList is Empty\n");
}
void recently_played(node **head1,node **tail1,int newlike,char sng[],char art[])
//it will look for the songs user have been listening currently
{
    node *temp=(node*)malloc(sizeof(node));
    strcpy(temp->song,sng);
    strcpy(temp->artist,art);
    temp->like=newlike;
    temp->prev=NULL;
    temp->next=*head1;
    if(*head1!=NULL)
        (*head1)->prev=temp;
        *head1=temp;
    if(*tail1==NULL)
    {
        *tail1=temp;
    }
}
void recently_played_display(node *head1)//it will display the recently played songs
{
    node *tmp=head1;
    int n=5;
    if(head1==NULL)
    {
        printf("\t\t\t\t\t\t\t\t List is empty.\n");
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tRecently played songs are:\n");
        while(tmp!=NULL)
        {
            printf("\t\t\t\t\t\t\t\tNow Playing: ");
            printf("\t\t\t\t\t\tArtist:\n");
            if(n!=0)
            {
                printf("\t\t\t\t\t\t\t\t %s",tmp->song);
                printf("\t\t\t\t\t\t\t\t:%s\n",tmp->artist);
                tmp=tmp->next;
                n--;
            }
            else
                break;
        }
    }
    return;
}
void display(node *head)//this will display all the songs in the playlist
{
    node *crt=head;
    if(head==NULL)
        {
            printf("\t\t\t\t\t\t\t\tPlaylist is empty\n");
            return;
        }
        while(crt!=NULL)
            {
                printf("\t\t\t\t\t\t\tSong: %s \t\t  Artist: %s \n",crt->song,crt->artist);
                crt=crt->next;
            }
        return;
}
void shuffle(node *head,node **head1,node **tail1)//this will play the songs in the playlist randomly
{
 node *ptr=head;
 int length=0;
 int i;
 while(ptr!=NULL)
   {
       ptr=ptr->next;
       length++;
   }
    int n;
    node *tmp=head;
    if(tmp==NULL)
        printf("\t\t\t\t\t\t\tList is empty.\n");
    else
         {
             int h;
             int sum=length,j;
             printf("\t\t\t\t\t\t\t\tNow Playing:  ");
             printf("\t\t\t\t\t\tArtist:  \n");
	         for( i=0;i<length;i++)
                {
                    node *crt=head;
                    n=(rand()%length)+1;
                    j=n;
                    while(n!=1)
                        {
                            crt=crt->next;
                            n--;
                        }
                    if(j!=sum)
                        {
                            printf("\t\t\t\t\t\t\t\t  %s",crt->song);
                            printf("\t\t\t\t\t\t\t\t  %s\n",crt->artist);
                            recently_played(head1,tail1,crt->like,crt->song,crt->artist);
                            printf("\t\t\t\t\t\t\t\tPress 1 to continue and 2 to go back to the menu: ");
                            scanf("%d",&h);
                            printf("\n");
                            if(h!=1)
                            return;
                       }
                  sum=j;
                }
         }
return;
}
void Liked(node *head)//this will display the list of all the liked songs by the user
{
     printf("\t\t\t\t\t\t\t\tThe songs that you like are:\n\n");
    if(head==NULL)
       {
           printf("\t\t\t\t\t\t\t\tlist is empty\n");
           return;
       }
       node *crt=head;
       while(crt!=NULL)
        {
            if(crt->like==1)
                {
                    printf("\t\t\t\t\t\t\t\tSong:  %s",crt->song);
                    printf("\t\t\t\t\t\t\t\tArtist: %s\n\n",crt->artist);
                }
                crt=crt->next;
        }

return;
}
void previoussong(node **head,node **tail,char sng[],node **head1,node **tail1)//this will play the song before the song currently playing
{
    if((*head1)==NULL)
    {
        printf("\t\t\t\t\t\t\t\tNo song is played yet.\n");
        return;
    }
    if(!Is_Empty(head))
    {
        node *crt=*head;
        if((*head)->prev==NULL && strcmp(sng,(*head)->song)==0)
        {
            printf("\t\t\t\t\t\t\t\tThere is no previous song to this song\n");
            return;
        }
        crt=crt->next;
        while(crt)
            {
                if(strcmp(sng,crt->song)==0)
                {
                    crt=crt->prev;
                    printf("\t\t\t\t\t\t\t\tPrevious song is:\n");
                    printf("\t\t\t\t\t\t\t\tNow playing:    %s",crt->song);
                    printf("\t\t\t\t\t\t\t\tArtist:          %s\n",crt->artist);
                    recently_played(head1,tail1,crt->like,crt->song,crt->artist);
                    return;
                }
                crt=crt->next;
            }
    }
    else
        printf("\t\t\t\t\t\t\t\tList is Empty\n");

}
void nextsong(node **head,node **tail,char sng[],node **head1,node **tail1)//this will play the next sing to the currently playing song
{   if((*head1)==NULL)
    {
        printf("\t\t\t\t\t\t\t\tNo song is played yet.\n");
        return;
    }
    if(!Is_Empty(head))
    {
        node *crt=*head;
        while(crt->next)
            {
                if(strcmp(sng,crt->song)==0)
                {
                    crt=crt->next;
                    printf("\t\t\t\t\t\t\t\tNext song is:\n");
                    printf("\t\t\t\t\t\t\t\tNow playing:    %s",crt->song);
                    printf("\t\t\t\t\t\t\t\tArtist:          %s\n",crt->artist);
                    recently_played(head1,tail1,crt->like,crt->song,crt->artist);
                    return;
                }
                crt=crt->next;
            }
            if(crt->next==NULL && (strcmp(sng,crt->song)==0))
                printf("\t\t\t\t\t\t\t\tThis is the last song of the list\n");
    }
    else
        printf("\t\t\t\t\t\t\t\tList is Empty\n");
}
void loop(node **head,node **tail,char song1[],node **head1,node **tail1)//plays a song on repeat
 {
  int count=0;
  node *crt=*head;
  if(!Is_Empty(head))
  {
      while(crt)
        {
            if(strcmp(song1,crt->song)==0)
            break;
            crt=crt->next;
        }
        while(count!=1)
            {
                printf("\n\t\t\t\t\t\t\t\tNow playing:    %s\n",crt->song);
                printf("\t\t\t\t\t\t\t\tArtist:          %s\n",crt->artist);
                recently_played(head1,tail1,crt->like,crt->song,crt->artist);
                printf("\t\t\t\t\t\t\t\tdo you want to continue the loop?if NOT press 1 :");
                scanf("%d",&count);
            }
            return;
  }
  else
    printf("\t\t\t\t\t\t\t\tList is empty\n");
    return;
}
void particular(node **head,node **tail,char song1[],node **head1,node **tail1)//this will play the song the user will enter
{
  node *crt=*head;
  if(!Is_Empty(head))
  {
      while(crt)
        {
            if(strcmp(song1,crt->song)==0)
            {
                printf("\n\t\t\t\t\t\t\t\tNow playing:  %s\n",crt->song);
                printf("\t\t\t\t\t\t\t\tArtist:   %s\n",crt->artist);
                recently_played(head1,tail1,crt->like,crt->song,crt->artist);
                return;
            }
            crt=crt->next;
        }
            return;
  }
  else
    printf("\t\t\t\t\t\t\t\tList is empty\n");
    return;

}
void wholeplaylist(node **head,node **head1,node **tail1)//this will play the whole playlist in order
{   int w;
    node *crt=*head;
    if(*head==NULL)
        {
            printf("\t\t\t\t\t\t\tPlaylist is empty\n");
            return;
        }
    while(crt!=NULL)
        {
            printf("\t\t\t\t\t\t\t\tNOW\n");
            printf("\t\t\t\t\t\t\t\tSong:  %s\n",crt->song);
            printf("\t\t\t\t\t\t\t\tArtist: %s\n",crt->artist);
            recently_played(head1,tail1,crt->like,crt->song,crt->artist);
            printf("\t\t\t\t\t\t\tPress 1 to continue and press 2 to return to the menu.");
            scanf("%d",&w);
            printf("\n");
            if(w!=1)
                return;
            crt=crt->next;
        }
        printf("\t\t\t\t\t\t\tThe list has ended\n");
        return;
}
void tempqueue (node **head,node **tail,node **head1,node **tail1)//this creates a temporary queue for the user to play the songs as they wish
{
    node *h1=NULL;
    node *t1=NULL;
	char songname[50];
    int i=1;
    while(i==1)
    {
        printf("\t\t\t\t\t\t\t\tEnter song name:");
        getchar();
        gets(songname);
        if(!Is_Empty(head))
            {
                node *crt=*head;
                while(crt)
                {
                    if(strcmp(crt->song,songname)==0)
                    {
                        Insert(&h1,&t1,crt->song,crt->artist,crt->like);
                        printf("\t\t\t\t\t\t\t\tThe song is loaded.\n");
                    }
                        crt=crt->next;
                }
            }
				    printf("\t\t\t\t\t\tDo you want to insert more? if yes press 1 else press 2 :");
                    scanf("%d",&i);

        }
        int  queuechoice;
        char queuesong[50];
        do //the following options can be performed on a temporary queue
            {
            printf("\n\t\t\t\t\t\t\t\t1: Play a particular song from the queue ");
            printf("\n\t\t\t\t\t\t\t\t2: Play a song on loop ");
		    printf("\n\t\t\t\t\t\t\t\t3: Go to the next song ");
            printf("\n\t\t\t\t\t\t\t\t4: Go to previous song ");
            printf("\n\t\t\t\t\t\t\t\t5: Display the whole queue ");
			printf("\n\t\t\t\t\t\t\t\t6: Play the whole queue ");
            printf("\n\t\t\t\t\t\t\t\t7: Return to the main menu ");
            printf("\n\n\t\t\t\t\t\t\t\tEnter Choice From 1-7: ");
            scanf("%d", &queuechoice);
            switch(queuechoice)
                {

                    case 1 :
                             printf("\t\t\t\t\t\t\tEnter song name\n");
                             getchar();
                             gets(queuesong);
                             particular(&h1,&t1,queuesong,head1,tail1);
                             break;

					 case 2:    printf("\t\t\t\t\t\t\tEnter song name");
                                getchar();
                                gets(queuesong);
                                loop(&h1,&t1,queuesong,head1,tail1);
                                break;

                    case 3:
                            nextsong(&h1,&t1,(*head1)->song,head1,tail1);
                            break;
                    case 4:
                            previoussong(&h1,&t1,(*head1)->song,head1,tail1);
                            break;

                    case 5:
                    	    display(h1);
                            break;

					case 6:
                            wholeplaylist(&h1,head1,tail1);
                            break;

                  case 7:  return;
                    }
                 } while(queuechoice!=7);
}
void Romantic(node **head1,node **tail1) //mood playlist1 suggested by the program
{
    node *h1=NULL;
    node *t1=NULL;
    int a,b;
    Insert(&h1,&t1,"Photograph","Ed Sheeran",0);
    Insert(&h1,&t1,"All of me","John Legend",0);
    Insert(&h1,&t1,"I want it that way","Backstreet Boys",0);
    Insert(&h1,&t1,"Everything i do","Bryan Adams",0);
    Insert(&h1,&t1,"Can't help falling in love with you","Elvis Presley",0);

    printf("\n\t\t\t\t\t\t\t\tRomantic- Heart beats\n");
    printf("\t\t\t\t\t\t\t\t1.Can't help falling in love with you\n");
    printf("\t\t\t\t\t\t\t\t2.Everything i do\n");
    printf("\t\t\t\t\t\t\t\t3.I want it that way\n");
    printf("\t\t\t\t\t\t\t\t4.All of me\n");
    printf("\t\t\t\t\t\t\t\t5.Photograph\n\n");
    do
    {
        int ch;
    printf("\t\t\t\t\t\t\t\tCHOOSE FROM THE FOLLOWING:\n");
    printf("\t\t\t\t\t\t\t\t1 .Play the whole playlist \n");
    printf("\t\t\t\t\t\t\t\t2 Play a particular song\n");
    printf("\t\t\t\t\t\t\t\t3.Go back to the moods\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice:");
    scanf("%d",&ch);
    if(ch==1)
        {
            wholeplaylist(&h1,head1,tail1);
        }
    else if(ch==2)
        {
            int sno;
            printf("\t\t\t\t\t\t\t\t1.Can't help falling in love with you\n");
            printf("\t\t\t\t\t\t\t\t2.Everything i do\n");
            printf("\t\t\t\t\t\t\t\t3.I want it that way\n");
            printf("\t\t\t\t\t\t\t\t4.All of me\n");
            printf("\t\t\t\t\t\t\t\t5.Photograph\n\n");
            do{
            printf("\t\t\t\t\t\t\t\tEnter song number (indicated before the song name):  ");
            scanf("%d",&sno);
            if(sno==1)
                particular(&h1,&t1,"Can't help falling in love with you",head1,tail1);
            else if(sno==2)
                particular(&h1,&t1,"Everything i do",head1,tail1);
            else if(sno==3)
                particular(&h1,&t1,"I want it that way",head1,tail1);
            else if(sno==4)
                particular(&h1,&t1,"All of me",head1,tail1);
            else if(sno==5)
                particular(&h1,&t1,"Photograph",head1,tail1);
             printf("\t\t\t\t\t\t\t\tDo you:\n\t\t\t\t\t\t\t\t1.want to play the next song\n\t\t\t\t\t\t\t\t2.want to play the previous song\n\t\t\t\t\t\t\t\t3.want to play the same song on loop\n\t\t\t\t\t\t\t\t4.Go back to the menu\n");
            int c;
            printf("\t\t\t\t\t\t\t\tEnter your choice:");
            scanf("%d",&c);
            if(c==1)
                nextsong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==2)
                previoussong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==3)
                loop(&h1,&t1,(*head1)->song,head1,tail1);
            else
                break;

        printf("\t\t\t\t\t\t\t\tPress 1 to continue playing : ");
        scanf("%d",&b);
        }while(b==1);
        }
        else
            break;
             printf("\t\t\t\t\t\t\t\tEnter 1 to continue in this mood\n\t\t\t\t\t\t\t\tAny other number to exit:");
            scanf("%d",&a);
    }while(a==1);
    return;
}
void Happy(node **head1,node **tail1)//mood playlist 2 suggested by the program
{
    node *h1=NULL;
    node *t1=NULL;
    int a,b;
    Insert(&h1,&t1,"Hymn for the weekend","Coldplay",0);
    Insert(&h1,&t1,"Blinding lights","The Weeknd",0);
    Insert(&h1,&t1,"Counting stars","One Republic",0);
    Insert(&h1,&t1,"Stand by me","Ben E. King",0);
    Insert(&h1,&t1,"Uptown funk","Bruno Mars",0);

    printf("\n\t\t\t\t\t\t\t\tHappy- Feeling good\n");
    printf("\t\t\t\t\t\t\t\t1.Uptown funk\n");
    printf("\t\t\t\t\t\t\t\t2.Stand by me\n");
    printf("\t\t\t\t\t\t\t\t3.Counting stars\n");
    printf("\t\t\t\t\t\t\t\t4.Blinding lights\n");
    printf("\t\t\t\t\t\t\t\t5.Hymn for the weekend\n\n");
    do{
        int ch;
    printf("\t\t\t\t\t\t\t\tCHOOSE FROM THE FOLLOWING:\n");
    printf("\t\t\t\t\t\t\t\t 1 .Play the whole playlist \n");
    printf("\t\t\t\t\t\t\t\t2 Play a particular song\n");
    printf("\t\t\t\t\t\t\t\t3.Go back to the moods\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice:");
    scanf("%d",&ch);
    if(ch==1)
        {
            wholeplaylist(&h1,head1,tail1);
        }
    else if(ch==2)
        {
            printf("\t\t\t\t\t\t\t\t1.Uptown funk\n");
            printf("\t\t\t\t\t\t\t\t2.Stand by me\n");
            printf("\t\t\t\t\t\t\t\t3.Counting stars\n");
            printf("\t\t\t\t\t\t\t\t4.Blinding lights\n");
            printf("\t\t\t\t\t\t\t\t5.Hymn for the weekend\n\n");
            int sno;
            do{
            printf("\t\t\t\t\t\t\t\tEnter song number(indicated before the song name): ");
            scanf("%d",&sno);
            if(sno==1)
                particular(&h1,&t1,"Uptown funk",head1,tail1);
            else if(sno==2)
                particular(&h1,&t1,"Stand by me",head1,tail1);
            else if(sno==3)
                particular(&h1,&t1,"Counting stars",head1,tail1);
            else if(sno==4)
                particular(&h1,&t1,"Blinding lights",head1,tail1);
            else if(sno==5)
                particular(&h1,&t1,"Hymn for the weekend",head1,tail1);
            printf("\t\t\t\t\t\t\t\tDo you:\n\t\t\t\t\t\t\t\t1.want to play the next song\n\t\t\t\t\t\t\t\t2.want to play the previous song\n\t\t\t\t\t\t\t\t3.want to play the same song on loop\n\t\t\t\t\t\t\t\t4.Go bback to the menu");
            int c;
            printf("\t\t\t\t\t\t\t\tEnter your choice:");
            scanf("\t\t\t\t\t\t\t\t%d",&c);
            if(c==1)
                nextsong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==2)
                previoussong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==3)
                loop(&h1,&t1,(*head1)->song,head1,tail1);
            else
                break;
            printf("\t\t\t\t\t\t\t\tPress 1 to continue playing : ");
           scanf("%d",&b);
        }while(b==1);
        }
        else
            break;
             printf("\t\t\t\t\t\t\t\tEnter 1 to continue in this mood\n\t\t\t\t\t\t\t\tAny other number to exit:");
            scanf("%d",&a);
    }while(a==1);
    return;
}
void Mood_Booster(node **head1,node **tail1)//mood playlist 3 suggested by the program
{
    node *h1=NULL;
    node *t1=NULL;
    int a,b;
    Insert(&h1,&t1,"Memories","Maroon 5",0);
    Insert(&h1,&t1,"Hall of fame","The Script",0);
    Insert(&h1,&t1,"I found you","Calvin Harris",0);
    Insert(&h1,&t1,"Human","Rag'n'Bone Man",0);
    Insert(&h1,&t1,"Sunflower","Post Malone",0);

    printf("\n\t\t\t\t\t\t\t\tMood booster\n");
    printf("\t\t\t\t\t\t\t\t1.Memories\n");
    printf("\t\t\t\t\t\t\t\t2.Hall of fame\n");
    printf("\t\t\t\t\t\t\t\t3.I found you\n");
    printf("\t\t\t\t\t\t\t\t4.Human\n");
    printf("\t\t\t\t\t\t\t\t5.Sunflower\n\n");
    do{
        int ch;
    printf("\t\t\t\t\t\t\t\tCHOOSE FROM THE FOLLOWING:\n");
    printf(" \t\t\t\t\t\t\t\t1 .Play the whole playlist \n");
    printf("\t\t\t\t\t\t\t\t2.Play a particular song\n");
    printf("\t\t\t\t\t\t\t\t3.Go back to the moods\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice:");
    scanf("%d",&ch);
    if(ch==1)
        {
            wholeplaylist(&h1,head1,tail1);
        }
    else if(ch==2)
        {
            printf("\t\t\t\t\t\t\t\t1.Memories\n");
            printf("\t\t\t\t\t\t\t\t2.Hall of fame\n");
            printf("\t\t\t\t\t\t\t\t3.I found you\n");
            printf("\t\t\t\t\t\t\t\t4.Human\n");
            printf("\t\t\t\t\t\t\t\t5.Sunflower\n\n");
            int sno;
            do{
            printf("\t\t\t\t\t\t\t\tEnter song number(indicated before the song name):  ");
            scanf("%d",&sno);
            if(sno==1)
                particular(&h1,&t1,"Memories",head1,tail1);
            else if(sno==2)
                particular(&h1,&t1,"Hall of fame",head1,tail1);
            else if(sno==3)
                particular(&h1,&t1,"I found you",head1,tail1);
            else if(sno==4)
                particular(&h1,&t1,"Human",head1,tail1);
            else if(sno==5)
                particular(&h1,&t1,"Sunflower",head1,tail1);
            printf("\t\t\t\t\t\t\t\tDo you:\n\t\t\t\t\t\t\t\t1.want to play the next song\n\t\t\t\t\t\t\t\t2.want to play the previous song\n\t\t\t\t\t\t\t\t3.want to play the same song on loop\n\t\t\t\t\t\t\t\t4.Go back to the menu\n");
            int c;
            printf("\t\t\t\t\t\t\t\tEnter your choice:");
            scanf("%d",&c);
            if(c==1)
                nextsong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==2)
                previoussong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==3)
                loop(&h1,&t1,(*head1)->song,head1,tail1);
            else
                break;
        printf("\t\t\t\t\t\t\t\tPress 1 to continue playing:  ");
        scanf("%d",&b);
        }while(b==1);
        }
        else
            break;
             printf("\t\t\t\t\t\t\t\tEnter 1 to continue in this mood\n\t\t\t\t\t\t\t\tAny other number to exit:");
            scanf("%d",&a);
    }while(a==1);
    return;
}
void Sad(node **head1,node **tail1)//mood playlist 4 suggested by the program
{
    node *h1=NULL;
    node *t1=NULL;
    int a,b;
    Insert(&h1,&t1,"Good things fall apart","Illenium and John Bellon",0);
    Insert(&h1,&t1,"Hardest to love","The Weeknd",0);
    Insert(&h1,&t1,"Say something","A Great Big World",0);
    Insert(&h1,&t1,"Lovely","Billie Eilish",0);
    Insert(&h1,&t1,"Sad song","We the Kings",0);

    printf("\n\t\t\t\t\t\t\t\tSad- Sad vibes\n");
    printf("\t\t\t\t\t\t\t\t1.Sad song\n");
    printf("\t\t\t\t\t\t\t\t2.Lovely\n");
    printf("\t\t\t\t\t\t\t\t3.Say something\n");
    printf("\t\t\t\t\t\t\t\t4.Hardest to love\n");
    printf("\t\t\t\t\t\t\t\t5.Good things fall apart\n\n");
    do{
        int ch;
    printf("\t\t\t\t\t\t\t\tCHOOSE FROM THE FOLLOWING\n");
    printf("\t\t\t\t\t\t\t\t1 .Play the whole playlist \n");
    printf("\t\t\t\t\t\t\t\t2. Play a particular song\n");
    printf("\t\t\t\t\t\t\t\t3.Go back to the moods\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice:");
    scanf("%d",&ch);
    if(ch==1)
        {
            wholeplaylist(&h1,head1,tail1);
        }
    else if(ch==2)
        {
            printf("\t\t\t\t\t\t\t\t1.Sad song\n");
            printf("\t\t\t\t\t\t\t\t2.Lovely\n");
            printf("\t\t\t\t\t\t\t\t3.Say something\n");
            printf("\t\t\t\t\t\t\t\t4.Hardest to love\n");
            printf("\t\t\t\t\t\t\t\t5.Good things fall apart\n\n");
            int sno;
            do{
            printf("\t\t\t\t\t\t\t\tEnter song number(indicated before the song name):  ");
            scanf("%d",&sno);
            if(sno==1)
                particular(&h1,&t1,"Sad song",head1,tail1);
            else if(sno==2)
                particular(&h1,&t1,"Lovely",head1,tail1);
            else if(sno==3)
                particular(&h1,&t1,"Say something",head1,tail1);
            else if(sno==4)
                particular(&h1,&t1,"Hardest to love",head1,tail1);
            else if(sno==5)
                particular(&h1,&t1,"Good things fall apart",head1,tail1);
            printf("\t\t\t\t\t\t\t\tDo you:\n\t\t\t\t\t\t\t\t1.want to play the next song\n\t\t\t\t\t\t\t\t2.want to play the previous song\n\t\t\t\t\t\t\t\t3.want to play the same song on loop\n\t\t\t\t\t\t\t\t4.Go back to the menu\n");
            int c;
            printf("\t\t\t\t\t\t\t\tEnter your choice:");
            scanf("\t\t\t\t\t\t\t\t%d",&c);
            if(c==1)
                nextsong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==2)
                previoussong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==3)
                loop(&h1,&t1,(*head1)->song,head1,tail1);
            else
                break;
        printf("\t\t\t\t\t\t\t\tPress 1 to continue playing:  ");
        scanf("%d",&b);
        }while(b==1);
        }
        else
           break;
            printf("\t\t\t\t\t\t\t\tEnter 1 to continue in this mood\n\t\t\t\t\t\t\t\tAny other number to exit:");
            scanf("%d",&a);
    }while(a==1);
    return;
}
void Work_Out(node **head1,node **tail1) //mood playlist 5 suggested by the program
{
    node *h1=NULL;
    node *t1=NULL;
    int a,b;
    Insert(&h1,&t1,"Lights up","Harry Styles",0);
    Insert(&h1,&t1,"Rescue me","One Republic",0);
    Insert(&h1,&t1,"Black and white","Niall Horan",0);
    Insert(&h1,&t1,"Another place","Bastille",0);
    Insert(&h1,&t1,"I'm so tired","Lauv",0);

    printf("\n\t\t\t\t\t\t\t\tWork Out- Pumped up\n");
    printf("\t\t\t\t\t\t\t\t1.I'm so tired\n");
    printf("\t\t\t\t\t\t\t\t2.Another place\n");
    printf("\t\t\t\t\t\t\t\t3.Black and white\n");
    printf("\t\t\t\t\t\t\t\t4.Rescue me\n");
    printf("\t\t\t\t\t\t\t\t5.Lights up\n\n");
    do{
        int ch;
    printf("\t\t\t\t\t\t\t\tCHOOSE FROM THE FOLLOWING:\n");
    printf("\t\t\t\t\t\t\t\t 1.Play the whole playlist \n");
    printf("\t\t\t\t\t\t\t\t2.Play a particular song\n");
    printf("\t\t\t\t\t\t\t\t3.Go back to the moods\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice:");
    scanf("%d",&ch);
    if(ch==1)
        {
            wholeplaylist(&h1,head1,tail1);
        }
    else if(ch==2)
        {
            printf("\t\t\t\t\t\t\t\t1.I'm so tired\n");
            printf("\t\t\t\t\t\t\t\t2.Another place\n");
            printf("\t\t\t\t\t\t\t\t3.Black and white\n");
            printf("\t\t\t\t\t\t\t\t4.Rescue me\n");
            printf("\t\t\t\t\t\t\t\t5.Lights up\n\n");
            int sno;
            do{
            printf("\t\t\t\t\t\t\t\tEnter song number(indicated before the song name):  ");
            scanf("%d",&sno);
            if(sno==1)
                particular(&h1,&t1,"I'm so tired",head1,tail1);
            else if(sno==2)
                particular(&h1,&t1,"Another place",head1,tail1);
            else if(sno==3)
                particular(&h1,&t1,"Black and white",head1,tail1);
            else if(sno==4)
                particular(&h1,&t1,"Rescue me",head1,tail1);
            else if(sno==5)
                particular(&h1,&t1,"Lights up",head1,tail1);
            printf("\t\t\t\t\t\t\t\tDo you:\n\t\t\t\t\t\t\t\t1.want to play the next song\n\t\t\t\t\t\t\t\t2.want to play the previous song\n\t\t\t\t\t\t\t\t3.want to play the same song on loop\n\t\t\t\t\t\t\t\t4.Goback to the menu\n");
            int c;
            printf("\t\t\t\t\t\t\t\tEnter your choice:");
            scanf("\t\t\t\t\t\t\t\t%d",&c);
            if(c==1)
                nextsong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==2)
                previoussong(&h1,&t1,(*head1)->song,head1,tail1);
            else if(c==3)
                loop(&h1,&t1,(*head1)->song,head1,tail1);
            else
                break;
        printf("\t\t\t\t\t\t\t\tPress 1 to continue playing:");
        scanf("%d",&b);
        }while(b==1);
        }
        else
           break;
            printf("\t\t\t\t\t\t\t\tEnter 1 to continue in this mood\n\t\t\t\t\t\t\t\tAny other number to exit:");
            scanf("%d",&a);
    }while(a==1);
return;
}
void mood_songs(node **head1,node **tail1)//function to choose the mood and play the recommended playlist
{
    int choice;
    while(1)
    {
        printf("\t\t\t\t\t\t\t\t1. Romantic- Heart beats\n");
        printf("\t\t\t\t\t\t\t\t2. Happy- Feeling good\n");
        printf("\t\t\t\t\t\t\t\t3. Mood booster\n");
        printf("\t\t\t\t\t\t\t\t4. Sad- Sad vibes\n");
        printf("\t\t\t\t\t\t\t\t5. Work Out- Pumped up\n");
        printf("\t\t\t\t\t\t\t\t6. Exit moods\n\n");
        printf("\t\t\t\t\t\t\t\tSelect the mood you want to enter:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: Romantic(head1,tail1); break;
        case 2: Happy(head1,tail1); break;
        case 3: Mood_Booster(head1,tail1); break;
        case 4: Sad(head1,tail1); break;
        case 5: Work_Out(head1,tail1); break;
        case 6: return;
        default: printf("Invalid mood");
        }
    }
}


