//====================================================================
// Organism.cpp
// Implementation file for the organism's information
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#pragma warning(disable:4996)

#include "Organism.h"
#include "GeneInfo.h"
#include "GeneticsSimDataParser.h"
#include <vector>

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Organism::Organism(char *fileName)
{
	strcpy(m_sFileName, fileName);
	m_parser = new GeneticsSimDataParser(m_sFileName);
	m_gene = new GeneInfo(m_sFileName);

	for(int i = 0; i < m_parser->getGeneCount(); i++)
	{
		m_vGenes.push_back(*m_gene);
		m_gene->getNextGene();
	}

	strcpy(m_sCommonName, m_parser->getCommonName());
	strcpy(m_sScientificName, m_parser->getScientificName());
	m_parser->getParentGenotype(m_sGenoType);
}

//-----------------------------------
// Destructor
//-----------------------------------
Organism::~Organism()
{
	m_parser = NULL;
	m_gene = NULL;
	delete m_parser;
	delete m_gene;
}

//-----------------------------------
// Get the organism's scientific name
//-----------------------------------
char *Organism::getSciName()
{
	return m_sScientificName;
}

//-----------------------------------
// Get the organism's common name
//-----------------------------------
char *Organism::getCommonName()
{
	return m_sCommonName;
}

//-----------------------------------
// Get the organism's genotype
//-----------------------------------
char *Organism::getGenotype()
{
	return m_sGenoType;
}

//-----------------------------------
// Get the next organism
//-----------------------------------
Organism *Organism::getNextParent()
{
	m_parser->getParentGenotype(m_sGenoType);
	return this;
}

//-----------------------------------
// Print the organism's information
//-----------------------------------
void Organism::print()
{
	int counter = 0;
	cout << "Parent:" << endl;
	cout << "\tOrganism genus-species: " << this->getSciName() << endl;
	cout << "\tCommon name: " << this->getCommonName() << endl;
	cout << "\tGenes:" << endl;

	for(vector<GeneInfo>::iterator itr = m_vGenes.begin(); itr != m_vGenes.end(); itr++)
	{
		cout << "\t\tGene type = " << itr->getTraitDesc() << endl;
		cout << "\t\t\tGenotype = " << m_sGenoType[counter] << m_sGenoType[counter+1] << endl;
		counter += 3;
	}
	cout << endl;
}

//-----------------------------------
// Print the organism's genetic information
//-----------------------------------
void Organism::printGeneInfo()
{
	m_gene = new GeneInfo(m_sFileName);
	m_gene->printMaster();
}