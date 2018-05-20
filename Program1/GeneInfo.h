//====================================================================
// GeneInfo.h
// Interface file for the class that holds each gene's information
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#ifndef GENEINFO_H
#define GENEINFO_H

#include "GeneticsSimDataParser.h"

class GeneInfo
{
	private:
		char m_sTraitDesc[32];				//Description of what the specific trait is (phenotype)
		char m_sDomDesc[32];				//Description of the dominant trait
		char m_sDomSymbol[1];				//Character that represents the dominant trait
		char m_sRecDesc[32];				//Description of the recessive trait
		char m_sRecSymbol[1];				//Character that represents the recessive trait
		GeneticsSimDataParser *m_parser;	//Object that allows access to the data
		char m_sFileName[64];				//Genetics sim data definition file

	public:
		GeneInfo(char *fileName);		//Constructor
		~GeneInfo();					//Destructor
		char *getTraitDesc();			//Get the trait description
		char *getDomDesc();				//Get the dominant allele’s trait description
		char getDomSymbol();			//Get the dominant allele’s symbol
		char *getRecDesc();				//Get the recessive allele’s trait description
		char getRecSymbol();			//Get the recessive allele’s symbol
		GeneInfo *getNextGene();		//Returns the next gene from the data parser
		void printMaster();				//Output the gene info
		int getGeneCount();				//Get the number of genes in the genotype
};
#endif