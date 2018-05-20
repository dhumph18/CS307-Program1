//====================================================================
// Breeder.h
// Interface file to breed the two organisms to produce offspring
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#ifndef BREEDER_H
#define BREEDER_H

#include "GeneInfo.h"
#include <string.h>
#include <vector>

class Breeder
{
	private:
		vector<string> m_vGenotypes;		//Collection of the child organisms' genotypes
		int m_iMax;							//Max value for random number generator
		int m_iRandom;						//Random number generated
		int m_iGeneCounters[3];				//Stores the three counters for the different types of gene results
		string m_sAllele1;					//Holds the first allele's character
		string m_sAllele2;					//Holds the second allele's character
		GeneInfo *m_gene;					//Gene info for the organisms


	public:
		Breeder(char *fileName);											//Constructor
		~Breeder();															//Destructor
		void breed(char *genotype1, char *genotype2, int numOffspring);		//Produces offspring genotypes and stores them in a vector
		void determineCounters(char domSymbol, int counter);				//Calculates the counters for the different types of gene results
		int getHomoDom();													//Get the number of homozygous dominant results for a gene
		int getHeteroDom();													//Get the number of heterozygous dominant results for a gene
		int getHomoRec();													//Get the number of homozygous recessive results for a gene
		void print();														//Output the offspring results
};
#endif 