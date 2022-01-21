#include"jukebox.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void main()
{
    node *head,*tail,*head1,*tail1;
    create_list(&head1,&tail1);
    create_list(&head,&tail);
    int choice=0;
    printf("\n\n\n");
    printf("\t\t\t\t\t***************************WELCOME TO THE JUKEBOX*******************************");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t MAKE YOUR CHOICE");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t\tPress 1 to insert a song\n");//insert a song
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\tPress 2 to exit the app\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice:");//enter your choice
    scanf("%d",&choice);
    printf("\n\n");
    switch(choice)
    {
         case 1:   {
                    char sng[50], art[20];
                    int  newlike,i=1;
                    while(i==1)
                   {
                    printf("\t\t\t\t\t\t\t\tEnter song name:");
                    getchar();
                    gets(sng);
                    printf("\n");
                    printf("\t\t\t\t\t\t\t\tEnter artist name:");
                    gets(art);
                    printf("\n");
                    printf("\t\t\t\t\t\tIf you like this song press 1 otherwise press 0:");
                    scanf("%d",&newlike);
                    printf("\n");
                    Insert(&head,&tail,sng,art,newlike);
                    printf("\t\t\t\t\t\t\tThe song has been loaded.\n\n");
                    printf("\n");
                    printf("\t\t\t\t\t\tDo you want to insert more? if yes press 1 else press 2 :");
                    scanf("%d",&i);
                    }}
                    break;
        case 2: exit(0);
        break;
        default:
        printf("\nInvalid Choice");
    }
    system("cls");
    int menuchoice=0;
    do
    {

      printf("\n\n\n\t\t\t\t\t\t\t\t1: Add a song to playlist ");
      printf("\n\t\t\t\t\t\t\t\t2: Remove song from playlist ");
      printf("\n\t\t\t\t\t\t\t\t3: Shuffle playlist ");
      printf("\n\t\t\t\t\t\t\t\t4: Go to next song ");
      printf("\n\t\t\t\t\t\t\t\t5: Go to previous song ");
      printf("\n\t\t\t\t\t\t\t\t6: Play the whole playlist ");
      printf("\n\t\t\t\t\t\t\t\t7: Create a new temp queue ");
      printf("\n\t\t\t\t\t\t\t\t8: Recently played songs ");
      printf("\n\t\t\t\t\t\t\t\t9: Display playlist ");
      printf("\n\t\t\t\t\t\t\t\t10: Liked songs ");
      printf("\n\t\t\t\t\t\t\t\t11: Play a particular song ");
      printf("\n\t\t\t\t\t\t\t\t12: Play a song on loop ");
      printf("\n\t\t\t\t\t\t\t\t13: Play a playlist according to your mood ");
      printf("\n\t\t\t\t\t\t\t\t14: Exit application ");
      printf("\n\n\t\t\t\t\t\t\t\tEnter Choice From 1-14: ");
      scanf("%d", &menuchoice);
      printf("\n\n");
      char sng[50], art[20];
      int newlike;
      switch(menuchoice)
      {
             case 1:
                    printf("\t\t\t\t\t\t\tEnter song name:");
                    getchar();
                    gets(sng);
                    printf("\n");
                    printf("\t\t\t\t\t\t\tEnter artist name:");
                    gets(art);
                    printf("\n");
                    printf("\t\t\t\t\t\tIf you like this song press 1 otherwise press 0:");
                    scanf("%d",&newlike);
                    printf("\n");
                    printf("\t\t\t\t\t\t\tThe song has been loaded\n\n");
                    Insert(&head,&tail,sng,art,newlike);
                    break;

             case 2:
                    display(head);
                    printf("\n\n");
                    printf("\t\t\t\t\t\t\tEnter the name of the song you want to delete:");
                    getchar();
                    gets(sng);
                    printf("\n");
                    Delete(&head,&tail,sng);
                    break;
            case 3:
                    shuffle(head,&head1,&tail1);

                    break;

             case 4:
                    nextsong(&head,&tail,head1->song,&head1,&tail1);
                    break;

             case 5:
                    previoussong(&head,&tail,head1->song,&head1,&tail1);
                    break;

             case 6:
                    wholeplaylist(&head,&head1,&tail1);
                    break;

             case 7:
                     printf("The existing songs in the system are : \n");
	                 display(head);
	                 tempqueue(&head,&tail,&head1,&tail1);
	                 break;
            case 8:
                    recently_played_display(head1);
                    break;

            case 9:
                    display(head);
                    break;

            case 10:
                    Liked(head);
                    break;

            case 11:
                   {
                        printf("\t\t\t\t\t\t\tEnter song name: ");
                        getchar();
                        gets(sng);
                        particular(&head,&tail,sng,&head1,&tail1);
                        int  choice;

                             printf("\n\t\t\t\t\t\t\t\t1: Go to the next song ");
                             printf("\n\t\t\t\t\t\t\t\t2: Go to previous song ");
				             printf("\n\t\t\t\t\t\t\t\t3: Play this song on loop ");
				             printf("\n\t\t\t\t\t\t\t\t4: Go back to main menu ");
							 printf("\n\n\t\t\t\t\t\t\t\tEnter Choice From 1-4: ");
                            scanf("%d", &choice);
                                switch(choice)
                                        {
                                            case 1:
                                                    nextsong(&head,&tail,head1->song,&head1,&tail1);
                                                     break;
                                            case 2:
                                                    previoussong(&head,&tail,head1->song,&head1,&tail1);
                                                    break;
                                            case 3:
                                                    loop(&head,&tail,sng,&head1,&tail1);
                                                    break;
                                            case 4:
                                                    break;
                                       }
                      }
                      break;
            case 12:
                        printf("\t\t\t\t\t\t\tEnter song name:");
                        getchar();
                        gets(sng);
                        loop(&head,&tail,sng,&head1,&tail1);
                        break;

            case 13:
                        mood_songs(&head1,&tail1);
                        break;
            case 14:
                     exit(0);
             default:
                     printf("\nInvalid Choice: 1-14 Only Please");
                     }
        } while(menuchoice!=15);
        system("cls");
}
