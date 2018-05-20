//====================================================================
// GeneInfo.cpp
// Implementation file for the class that holds each gene's information
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================
#pragma warning(disable:4996)

#include "GeneInfo.h"
#include "GeneticsSimDataParser.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
GeneInfo::GeneInfo(char *fileName)
{
	m_parser = new GeneticsSimDataParser(fileName);
	m_parser->getGeneData(m_sTraitDesc, m_sDomDesc, m_sDomSymbol, m_sRecDesc, m_sRecSymbol);
}

//-----------------------------------
// Destructor
//-----------------------------------
GeneInfo::~GeneInfo()
{
	m_parser = NULL;
	delete m_parser;
}

//-----------------------------------
// Get the trait description
//-----------------------------------
char *GeneInfo::getTraitDesc()
{
	return m_sTraitDesc;
}

//-----------------------------------
// Get the dominant trait description
//-----------------------------------
char *GeneInfo::getDomDesc()
{
	return m_sDomDesc;
}

//-----------------------------------
// Get the dominant trait symbol
//-----------------------------------
char GeneInfo::getDomSymbol()
{
	return m_sDomSymbol[0];
}

//-----------------------------------
// Get the recessive trait description
//-----------------------------------
char *GeneInfo::getRecDesc()
{
	return m_sRecDesc;
}

//-----------------------------------
// Get the recessive trait symbol
//-----------------------------------
char GeneInfo::getRecSymbol()
{
	return m_sRecSymbol[0];
}

//-----------------------------------
// Get the next gene in the data file
//-----------------------------------
GeneInfo *GeneInfo::getNextGene()
{
	//Make it possible to return false
	m_parser->getGeneData(m_sTraitDesc, m_sDomDesc, m_sDomSymbol, m_sRecDesc, m_sRecSymbol);
	return this;
}

//-----------------------------------
//Get the number of genes in the genotype
//-----------------------------------
int GeneInfo::getGeneCount()
{
	return m_parser->getGeneCount();
}

//-----------------------------------
// Prints info on each gene
//-----------------------------------
void GeneInfo::printMaster()
{
	cout << "\nGenes: " << endl;
	for(int i = 0; i < m_parser->getGeneCount(); i++)
	{
		cout << "\tTrait Name: " << this->getTraitDesc() << endl;
		cout << "\t\t Dominant Name: " << this->getDomDesc() << "(" << this->getDomSymbol() << ")" << endl;
		cout << "\t\t Recessive Name: " << this->getRecDesc() << "(" << this->getRecSymbol() << ")" << endl;
		m_parser->getGeneData(m_sTraitDesc, m_sDomDesc, m_sDomSymbol, m_sRecDesc, m_sRecSymbol);
	}
	cout << endl;
}