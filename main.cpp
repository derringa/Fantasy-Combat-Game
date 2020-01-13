/**************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Andrew Derringer
 * Last Modified: 2/28/2019
 * Description: Once user chooses to run program they may create team of
 * fighters of any size they like which are allocated into their respective
 * linked lists. Fighters compete against their counter part and winners
 * go to the back of their respective queue while losers are removed from
 * their queue and added to a loser stack. The game prints who won each round,
 * the total score of the game, offers to print the loser stack, and asks
 * the user if they want to play again.
**************************************************************************/

#include "inputValidation.hpp"
#include "helperFunctions.hpp"

#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include "Queue.hpp"
#include "Stack.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;



int main()
{
     string title = "Fantasy Combat Tournament";

     system("clear");

     bool executeProgram = runProgram("      Welcome to: " + title + "       ", "Would you like to play?");

     while(executeProgram)
     {
          // Program Introduction
          system("clear");

          cout << title << endl << endl
               << "The game pits two powerful teams against each\n"
               << "other in a battle to the death! Vampires have the\n"
               << "ability to charm others and stop their attacks.\n"
               << "Blue men have superior defense as a nimble swarm of\n"
               << "of small creatures. If Medusa catches you in her\n"
               << "glare she will kill you by turning you to stone.\n"
               << "Finally Harry Potter can be  resurrected once by\n"
               << "the power of the Deathly Hallows. The Barbarian\n"
               << "is alone among these fantastic creatures with\n"
               << "only hiss strength and bravery to preserve him"
               << endl << endl;


          // Request user to determine team sizes.
          // Input assigned to teamSize and used in loop to allocate proper number
          // of linked list nodes.
          cout << "Please select the number of fights per team:\n";
          const int teamSize = integerRangeValidate("Error - Please pick between 1 and 100 fighters", 1, 100);
          cout << endl << endl;



          Queue teamOne;
          Queue teamTwo;
          Stack loserPile;
          string fighterName;

          const int MENUSIZE = 5;
          string menuOptions[MENUSIZE] = {"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};

          system("clear");

          cout << "|--------------------------------------------------|\n"
               << "|              Team One Fighter Draft              |\n"
               << "|--------------------------------------------------|\n"
               << endl;

          // Loop includes switch board allowing user to pick a type of fighter, name
          // them, and assign to their team each iteration.
          for(int i = 0; i < teamSize; i++)
          {
               // Print menu of fighter types and validate response.
               int choice = writeMenu(("Pick fighter #" + std::to_string(i + 1)), menuOptions, MENUSIZE);


               // Get name of fighter and pass to instances of new fighters.
               cout << endl << endl
                    << "Please name your fighter:" << endl;
               cin.ignore();
               std::getline(cin, fighterName);
               cout << endl << endl;



               // fighter type for team one initiated according to previous choice in switch.
               switch(choice)
               {
                    case 1: teamOne.addBack(new Vampire(fighterName));
                            break;
                    case 2: teamOne.addBack(new Barbarian(fighterName));
                            break;
                    case 3: teamOne.addBack(new BlueMen(fighterName));
                            break;
                    case 4: teamOne.addBack(new Medusa(fighterName));
                            break;
                    case 5: teamOne.addBack(new HarryPotter(fighterName));
               }
          }



          system("clear");

          cout << "|--------------------------------------------------|\n"
               << "|              Team Two Fighter Draft              |\n"
               << "|--------------------------------------------------|\n"
               << endl;

          // Repeat of previous for loop but for team two rather than team one.
          for(int i = 0; i < teamSize; i++)
          {
               int choice = writeMenu(("Pick fighter #" + std::to_string(i + 1)), menuOptions, MENUSIZE);

               cout << endl << endl
                    << "Please name your fighter:" << endl;
               cin.ignore();
               std::getline(cin, fighterName);
               cout << endl << endl;

               switch(choice)
               {
                    case 1: teamTwo.addBack(new Vampire(fighterName));
                            break;
                    case 2: teamTwo.addBack(new Barbarian(fighterName));
                            break;
                    case 3: teamTwo.addBack(new BlueMen(fighterName));
                            break;
                    case 4: teamTwo.addBack(new Medusa(fighterName));
                            break;
                    case 5: teamTwo.addBack(new HarryPotter(fighterName));
               }
          }



          // round incremented each loop interation
          int round = 0;

          // variables reassigned each loop iteration
          int scoreOne = 0;
          int scoreTwo = 0;

          // reassigned each iteration and passed to Character::tallyDamage
          // to adjust character strength points
          int attack;
          int defense;

          // reassigned each loop iteration and used to dtermine amount of
          // strength point regeneration for winner
          int damageOne;
          int damageTwo;

          std::srand(std::time(0));
          system("clear");



          cout << "|--------------------------------------------------|\n"
               << "|                   Combat Phase                   |\n"
               << "|--------------------------------------------------|\n"
               << endl;

          // Team combat stops when either of the teams no longer has any fighters
          // left, of their roster/list is empty.
          while(!teamOne.isEmpty() && !teamTwo.isEmpty())
          {
               // address of character pulled out so member functions can be used
               // more easily.
               Character* fighterOne = teamOne.getFighter();
               Character* fighterTwo = teamTwo.getFighter();
               // round incremented
               round ++;



               // fighters at index 0 of both lists fight until one is not alive
               // or their strength points are <= 0.
               while((fighterOne->isAlive()) && (fighterTwo->isAlive()))
               {
                    attack = fighterOne->attack();
                    defense = fighterTwo->defend();
                    damageTwo = fighterTwo->tallyDamage(attack, defense);


                    // list two fighter won't have chance to call attack function
                    // if they are already dead going into the bottom of the round
                    if(fighterTwo->isAlive())
                    {
                         attack = fighterTwo->attack();
                         defense = fighterOne->defend();
                         damageOne = fighterOne->tallyDamage(attack, defense);
                    }
               }



               // Once a fighter has died and loop finished round infrmation is printed.
               cout << "Round " << round << ":" << endl
                    << "Team 1 - " << fighterOne->getName() << "(" << fighterOne->getType() << ") VS. "
                    << "Team 2 - " << fighterTwo->getName() << "(" << fighterTwo->getType() << ")" << endl;


               // if fighter two died and fighter one won.
               if(fighterTwo->getStrengthPoints() <= 0)
               {
                    // print that team one won.
                    cout << fighterOne->getName() << "(" << fighterOne->getType() << ") Won!";
                    // incrememt team one score.
                    scoreOne++;

                    // regenerate health for fighter one.
                    fighterOne->regenerate(damageOne / 2);
                    // rotate victor to back of their queue.
                    teamOne.moveToBack();
                    // feed pointer of loser to create new node at head of loser stack.
                    loserPile.addToHead(fighterTwo);
                    // changed Character pointer health by losing node to null so that 
                    // when the following removeFront function deletes the node, the
                    // character deconstructor isn't called to destroy the object at
                    // that memory address.
                    teamTwo.setFighter(nullptr);
                    teamTwo.removeFront();
               // the same process is set out in cases of fighter two winning below.
               }else if(fighterOne->getStrengthPoints() <= 0){
                    cout << fighterTwo->getName() << "(" << fighterTwo->getType() << ") Won!";
                    scoreTwo++;

                    fighterTwo->regenerate(damageTwo / 2);
                    teamTwo.moveToBack();
                    loserPile.addToHead(fighterOne);
                    teamOne.setFighter(nullptr);
                    teamOne.removeFront();

               }
            
               cout << endl << endl;
          }


          // Print the final scores of each team after the tournament is over.
          cout << endl << endl
               << "Tournament ended. Final score:" << endl
               << "Team One: " << scoreOne << "          Team Two: " << scoreTwo
               << endl << endl;


          // Offer to print the loser stack.
          cout << "Would you like to see the list of losers?" << endl;

          if(boolValidate())
          {
               cout << endl;
               loserPile.printList();
          }

          cout << endl << endl;
 

          // Invite the user to play again.
          executeProgram = runProgram(" Thank you for playing " + title + "  ", "Would you like to play again?");
     }


     // Say goodbye.
     cout << "Have a good day."
          << endl << endl;

     return 0;
}
