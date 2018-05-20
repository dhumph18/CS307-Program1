//====================================================================
// Organism.h
// Interface file for the organism's information
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#ifndef ORGANISM_H
#define ORGANISM_H

#include "GeneInfo.h"
#include "GeneticsSimDataParser.h"
#include <vector>

class Organism
{
	private:
		char m_sScientificName[64];			//Scientific name (genus & species) of the organism
		char m_sCommonName[32];				//Common name of the organism
		char m_sGenoType[32];				//Genotype of the organism
		char m_sFileName[64];				//Name of the input file
		GeneInfo *m_gene;					//Represents one gene of the organism's genotype
		vector<GeneInfo> m_vGenes;			//Collection of the genes of the organism's genotype
		GeneticsSimDataParser *m_parser;	//Used to parse through data file

	public:
		Organism(char *fileName);			//Constructor
		~Organism();						//Destructor
		char *getSciName();					//Get the scientific name
		char *getCommonName();				//Get the common name
		char *getGenotype();				//Get the genotype
		Organism *getNextParent();			//Get the next parent organism
		void print();						//Print the organism's information
		void printGeneInfo();				//Print the organism's genetic information
};
#endif