//====================================================================
// Simulation.cpp
// Implementation file to run the simulation
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#pragma warning(disable:4996)

#include "Simulation.h"
#include "Organism.h"
#include "Breeder.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Simulation::Simulation()
{
	cout << "Enter the name of the input file: ";
	cin >> m_sFileName;
	
	m_iNumOffspring = 0;

	m_parent1 = new Organism(m_sFileName);
	m_breeder = new Breeder(m_sFileName);
}

//-----------------------------------
// Destructor
//-----------------------------------
Simulation::~Simulation()
{
	m_parent1 = NULL;
	m_parent2 = NULL;
	m_breeder = NULL;

	delete m_parent1;
	delete m_parent2;
	delete m_breeder;
}

//-----------------------------------
// Runs the simulation
//-----------------------------------
void Simulation::runSimulation()
{
	m_parent1->printGeneInfo();

	m_parent1->print();
	strcpy(m_sGenotype1, m_parent1->getGenotype());

	m_parent2 = m_parent1->getNextParent();
	m_parent2->print();
	strcpy(m_sGenotype2, m_parent2->getGenotype());

	cout << "How many offspring do you want to generate? (Type the number then press Enter)\n==> ";
	cin >> m_iNumOffspring;

	cout << "\n==================== Results of this Run ====================\n" << endl;

	m_breeder->breed(m_sGenotype1, m_sGenotype2, m_iNumOffspring);
	m_breeder->print();

	m_parent1->~Organism();
	m_parent2->~Organism();
	m_breeder->~Breeder();
}