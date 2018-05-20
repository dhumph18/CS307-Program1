//====================================================================
// Breeder.cpp
// Implementation file to breed the two organisms to produce offspring
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#pragma warning(disable:4996)

#include "Breeder.h"
#include "GeneInfo.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>
#include <iostream>
#include <sstream>

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Breeder::Breeder(char *fileName)
{
	m_iMax = 2;
	srand((unsigned int)(time(NULL)));
	m_iRandom = rand() % m_iMax;
	m_sAllele1 = "";
	m_sAllele2 = "";
	m_gene = new GeneInfo(fileName);
}

//-----------------------------------
// Destructor
//-----------------------------------
Breeder::~Breeder()
{
	m_gene = NULL;
	delete m_gene;
}

//-----------------------------------
// Produces the offspring genotypes and stores them in a vector
//-----------------------------------
void Breeder::breed(char *genotype1, char *genotype2, int numOffspring)
{
	string gen1(genotype1);
	string gen2(genotype2);
	gen1 += "   ";

	for(int i = 0; i < numOffspring; i++)
	{
		string childGeno = "";
		int counter = 0;
		string nextGene = gen1.substr(counter, 2);
		int index = counter + m_iRandom;
		m_sAllele1;
		m_sAllele2;

		while(nextGene.compare("  ") != 0)
		{
			m_sAllele1 = gen1.substr(index, 1);
			m_iRandom = rand() % m_iMax;
			index = counter + m_iRandom;

			m_sAllele2 = gen2.substr(index, 1);
			m_iRandom = rand() % m_iMax;
			counter += 3;
			index = counter + m_iRandom;

			if(m_sAllele1.compare(m_sAllele2) > 0)
			{
				childGeno += m_sAllele2;
				childGeno += m_sAllele1;
			}
			else
			{
				childGeno += m_sAllele1;
				childGeno += m_sAllele2;
			}

			childGeno += " ";
			nextGene = gen1.substr(counter, 2);
		}
		childGeno += "  ";
		m_vGenotypes.push_back(childGeno);
	}
	cout << endl;
}

//-----------------------------------
//Calculates the counters for the different types of gene results
//-----------------------------------
void Breeder::determineCounters(char domSymbol, int counter)
{
	int homoDom = 0;
	int heteroDom = 0;
	int homoRec = 0;
	string domSym;
	stringstream ss;
	ss << domSymbol;
	ss >> domSym;

	for(int i = 0; i < 3; i++)
		m_iGeneCounters[i] = 0;

	for(string childGeno : m_vGenotypes)
	{
		m_sAllele1 = childGeno.substr(counter,1);
		m_sAllele2 = childGeno.substr(counter+1,1);

		if(m_sAllele1.compare(" ") != 0)
		{
			if(m_sAllele1.compare(m_sAllele2) != 0)
				heteroDom++;	
			else if(domSym.compare(m_sAllele2) == 0)
				homoDom++;
			else 
				homoRec++;
		}
	}
		m_iGeneCounters[0] = homoDom;
		m_iGeneCounters[1] = heteroDom;;
		m_iGeneCounters[2] = homoRec;
	
}

//-----------------------------------
//Get the number of homozygous dominant results for a gene
//-----------------------------------
int Breeder::getHomoDom()
{
	return m_iGeneCounters[0];
}
//-----------------------------------
//Get the number of heterozygous dominant results for a gene
//-----------------------------------
int Breeder::getHeteroDom()
{
	return m_iGeneCounters[1];
}

//-----------------------------------
//Get the number of homozygous recessive results for a gene
//-----------------------------------
int Breeder:: getHomoRec()
{
	return m_iGeneCounters[2];
}

//-----------------------------------
//Output the offspring results
//-----------------------------------
void Breeder::print()
{
	int counter = 0;
	
	for(int i = 0; i < m_gene->getGeneCount(); i++)
	{
		determineCounters(m_gene->getDomSymbol(), counter);
		
		cout << "Gene: " << m_gene->getTraitDesc() << "\n\t";
		cout << this->getHomoDom() << " homozygous dominant (" 
			<< m_gene->getDomDesc() << " " << m_gene->getDomSymbol() << m_gene->getDomSymbol() << ")" << endl;

		cout << "\t" << this->getHeteroDom() << " heterozygous dominant (" 
			<< m_gene->getDomDesc() << " " << m_gene->getDomSymbol() << m_gene->getRecSymbol() << ")" << endl;

		cout << "\t" << this->getHomoRec() << " homozygous recessive (" 
			<< m_gene->getRecDesc() << " " << m_gene->getRecSymbol() << m_gene->getRecSymbol() << ")\n" << endl;

		m_gene->getNextGene();
		counter += 3;
	}
}