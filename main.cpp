/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Main function is used to choose the combatants. 
**    Battle function executes the fight until one combatant loses.
********************************************************************/
#include "Goblin.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Bluemen.hpp"
#include "Shadow.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

/*Fucntion prototypes*/
template <class T, class S>
void battle(T, S);

/********************************************************************
** Description: Has do..while loops for choosing the combatants
********************************************************************/	
int main()
{
	Goblin goblin_1;
	Goblin goblin_2;
	Barbarian barbarian_1;
	Barbarian barbarian_2;
	Reptile reptile_1;
	Reptile reptile_2;
	Bluemen bluemen_1;
	Bluemen bluemen_2;
	Shadow shadow_1;
	Shadow shadow_2;
	char first_opponent;
	char second_opponent;
	
	srand(time(NULL));
	
	std::cout << "Creature Combat" << std::endl;
	
	/*Fisrt Combatant*/
	do
	{
		std::cout << "Choose the first combatant." << std::endl;
		std::cout << "1) Goblin" << std::endl;
		std::cout << "2) Barbarian" << std::endl;
		std::cout << "3) Reptile People" << std::endl;
		std::cout << "4) Blue Men" << std::endl;
		std::cout << "5) The Shadow" << std::endl;
		std::cin >> first_opponent;
		std::cin.ignore();
		
		if(first_opponent != '1' && first_opponent != '2' && first_opponent != '3' 
		&& first_opponent != '4' && first_opponent != '5')
		{
			std::cout << "Invalid Choice. Choose 1 - 5" << std::endl;
		}
		
	}while(first_opponent != '1' && first_opponent != '2' && first_opponent != '3' 
		&& first_opponent != '4' && first_opponent != '5');
	
    /*Second Combatant*/	
	do
	{
		std::cout << "Choose the second combatant." << std::endl;
		std::cout << "1) Goblin" << std::endl;
		std::cout << "2) Barbarian" << std::endl;
		std::cout << "3) Reptile People" << std::endl;
		std::cout << "4) Blue Men" << std::endl;
		std::cout << "5) The Shadow" << std::endl;
		std::cin >> second_opponent;
		std::cin.ignore();
		
		if(second_opponent != '1' && second_opponent != '2' && second_opponent != '3' 
		&& second_opponent != '4' && second_opponent != '5')
		{
			std::cout << "Invalid Choice. Choose 1 - 5" << std::endl;
		}
		
	}while(second_opponent != '1' && second_opponent != '2' && second_opponent != '3' 
		&& second_opponent != '4' && second_opponent != '5');
	
	/*Call Battle function, passing the combatants*/
	if(first_opponent == '1')
	{
		if(second_opponent == '1')
		{
			battle(goblin_1, goblin_2);
		}
		else if(second_opponent == '2')
		{
			battle(goblin_1, barbarian_2);
		}
		else if(second_opponent == '3')
		{
			battle(goblin_1, reptile_2);
		}
		else if(second_opponent == '4')
		{
			battle(goblin_1, bluemen_2);
		}
		else if(second_opponent == '5')
		{
			battle(goblin_1, shadow_2);
		}
	}
	else if(first_opponent == '2')
	{
		if(second_opponent == '1')
		{
			battle(barbarian_1, goblin_2);
		}
		else if(second_opponent == '2')
		{
			battle(barbarian_1, barbarian_2);
		}
		else if(second_opponent == '3')
		{
			battle(barbarian_1, reptile_2);
		}
		else if(second_opponent == '4')
		{
			battle(barbarian_1, bluemen_2);
		}
		else if(second_opponent == '5')
		{
			battle(barbarian_1, shadow_2);
		}
	}
	else if(first_opponent == '3')
	{
		if(second_opponent == '1')
		{
			battle(reptile_1, goblin_2);
		}
		else if(second_opponent == '2')
		{
			battle(reptile_1, barbarian_2);
		}
		else if(second_opponent == '3')
		{
			battle(reptile_1, reptile_2);
		}
		else if(second_opponent == '4')
		{
			battle(reptile_1, bluemen_2);
		}
		else if(second_opponent == '5')
		{
			battle(reptile_1, shadow_2);
		}
	}
	else if(first_opponent == '4')
	{
		if(second_opponent == '1')
		{
			battle(bluemen_1, goblin_2);
		}
		else if(second_opponent == '2')
		{
			battle(bluemen_1, barbarian_2);
		}
		else if(second_opponent == '3')
		{
			battle(bluemen_1, reptile_2);
		}
		else if(second_opponent == '4')
		{
			battle(bluemen_1, bluemen_2);
		}
		else if(second_opponent == '5')
		{
			battle(bluemen_1, shadow_2);
		}
	}
	else if(first_opponent == '5')
	{
		if(second_opponent == '1')
		{
			battle(shadow_1, goblin_2);
		}
		else if(second_opponent == '2')
		{
			battle(shadow_1, barbarian_2);
		}
		else if(second_opponent == '3')
		{
			battle(shadow_1, reptile_2);
		}
		else if(second_opponent == '4')
		{
			battle(shadow_1, bluemen_2);
		}
		else if(second_opponent == '5')
		{
			battle(shadow_1, shadow_2);
		}
	}
	return 0;
}

/********************************************************************
** Description: Do..while loop is used to make the combatants fight.
**    The combatants take turns attacking 
********************************************************************/
template <class T, class S>
void battle(T combatant_1, S combatant_2)
{
	int attack;
	int defense;
	int round = 1;
	
	combatant_1.setOpponent(combatant_2.getName());
	combatant_2.setOpponent(combatant_1.getName());
	
	do
	{
		std::cout << "Round: " << round++ << std::endl;
		
		/*Combatant_1 attack, Combatant_2 defend*/
		std::cout << "Combatant 1: " << combatant_1.getName() << " Attacks" << std::endl;
		attack = combatant_1.attackRoll();
		defense = combatant_2.defenseRoll();
		combatant_2.calcDamage(attack);
		combatant_2.applyDamage();
		std::cout << "Attack Points: " << attack << std::endl;
		std::cout << "Defense Points: " << defense << std::endl;
		std::cout << "Combatant 2 " << combatant_2.getName() 
		          << " Strength: " << combatant_2.getStrengthPoints() << std::endl;
		
		/*Combatant_1 defend, Combatant_2 attack*/
		if(combatant_1.getStrengthPoints() > 0 && combatant_2.getStrengthPoints() > 0)
		{
			std::cout << "Combatant 2: " << combatant_2.getName() << " Attacks" << std::endl;
			attack = combatant_2.attackRoll();
			defense = combatant_1.defenseRoll();
			combatant_1.calcDamage(attack);
			combatant_1.applyDamage();
			std::cout << "Attack Points: " << attack << std::endl;
			std::cout << "Defense Points: " << defense << std::endl;
			std::cout << "Combatant 1 " << combatant_1.getName() 
					  << " Strength: " << combatant_1.getStrengthPoints() << std::endl;
		}
		
		std::cout << std::endl;
	}while(combatant_1.getStrengthPoints() > 0 && combatant_2.getStrengthPoints() > 0);
	
	if(combatant_1.getStrengthPoints() > 0)
	{
		std::cout << "Combatant 1:" << combatant_1.getName() << " Wins" << std::endl;
	}
	else
	{
		std::cout << "Combatant 2:" << combatant_2.getName() << " Wins" << std::endl;
	}
}