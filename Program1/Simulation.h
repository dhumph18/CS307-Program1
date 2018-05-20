//====================================================================
// Simulation.h
// Interface file to run the simulation
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#ifndef SIMUTATION_H
#define SIMUTATION_H

#include "Organism.h"
#include "Breeder.h"

class Simulation
{
	private:
		int m_iNumOffspring;		//Number of offspring to be produced
		char m_sFileName[64];		//Name of input file
		char m_sGenotype1[32];		//Genotype of the first parent organism
		char m_sGenotype2[32];		//Genotype of the second parent organism
		Organism *m_parent1;		//First parent organism to be bred
		Organism *m_parent2;		//Second parent organism to be bred
		Breeder *m_breeder;			//Object used to breed the two parent organisms

	public:
		Simulation();				//Constructor
		~Simulation();				//Destructor
		void runSimulation();		//Runs the simulation
};
#endif