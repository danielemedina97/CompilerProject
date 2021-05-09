#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: 19 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Daniel Medina
// RE:   (vowel | vowel n | consonant vowel | consonant vowel n | consonant-pair vowel | consonant-pair vowel n)^+              

bool word (string s)
{
  //q0 = 0 final 
  //qt = 1 
  //qs = 2
  //qc = 3
  //q1q0 = 4 final 
  //qsa = 5
  //qy = 6
  //q0qy = 7 final 
  int state = 0;
  int charpos = 0;
  //replace the following todo the word dfa  
  while (s[charpos] != '\0') 
    {
      if (state == 0 && s[charpos] == 't')//from q0
	state = 1;//to qt
      else if (state == 0 && s[charpos] == 's')//from q0
	state = 2;//to q2
      else if (state == 0 && s[charpos] == 'c')//from q0
	state = 3;//to qc
      else if (state == 0 && (s[charpos] == 'a'||s[charpos] == 'i'||s[charpos] == 'u'
			      ||s[charpos] == 'e'||s[charpos] == 'o'||s[charpos] == 'I'||s[charpos] == 'E'))//from q0
        state = 4;//to q1q0
      else if (state == 0 && (s[charpos] == 'd'||s[charpos] == 'w'||s[charpos] == 'z'||s[charpos] == 'y'||s[charpos] == 'j'))//from q0
	state = 5;//to qsa
      else if (state == 0 && (s[charpos] == 'b'||s[charpos] == 'g'||s[charpos] == 'h'||s[charpos] == 'k'
			      ||s[charpos] == 'n'||s[charpos] == 'm'||s[charpos] == 'p'||s[charpos] == 'r'))//q0
	state = 6;//to qy
      else if (state == 1 && s[charpos] == 's')//from qt
	state = 5;//to qsa
      else if (state == 1 && (s[charpos] == 'a'||s[charpos] == 'i'||s[charpos] == 'u'
                              ||s[charpos] == 'e'||s[charpos] == 'o'||s[charpos] == 'I'||s[charpos] == 'E'))//from qt
	state = 4;//to q1q0
      else if (state == 2 && s[charpos] == 'h')//from qs
	state = 5;//to qsa
      else if (state == 2 && (s[charpos] == 'a'||s[charpos] == 'i'||s[charpos] == 'u'
                              ||s[charpos] == 'e'||s[charpos] == 'o'||s[charpos] == 'I'||s[charpos] == 'E'))//from qs
        state = 4;//to q1q0
      else if (state == 3 && s[charpos] == 'h')//from qc
        state = 5;//to qsa
      else if (state == 4 && s[charpos] == 'c')//from q1q0
	state = 3;//to qc
      else if (state == 4 && s[charpos] == 's')//from q1q0
        state = 2;//to qs
      else if (state == 4 && s[charpos] == 'n')//from q1q0
        state = 7;//to q0qy
      else if (state == 4 && s[charpos] == 't')//from q1q0
        state = 1;//to qt
      else if (state == 4 && (s[charpos] == 'b'||s[charpos] == 'g'||s[charpos] == 'h'||s[charpos] == 'k'
                              ||s[charpos] == 'm'||s[charpos] == 'p'||s[charpos] == 'r'))//from q1q0
	state = 6;//to qy
      else if (state == 4 && (s[charpos] == 'd'||s[charpos] == 'w'||s[charpos] == 'z'||s[charpos] == 'y'||s[charpos] == 'j'))//from q1q0
        state = 5;//to qsa
      else if (state == 4 && (s[charpos] == 'a'||s[charpos] == 'i'||s[charpos] == 'u'
                              ||s[charpos] == 'e'||s[charpos] == 'o'||s[charpos] == 'I'||s[charpos] == 'E'))//from q1q0
	state = 4;//to q1q0
      else if (state == 5 && (s[charpos] == 'a'||s[charpos] == 'i'||s[charpos] == 'u'
                              ||s[charpos] == 'e'||s[charpos] == 'o'||s[charpos] == 'I'||s[charpos] == 'E'))//from qsa
	state = 4;//to q1q0
      else if (state == 6 && s[charpos] == 'y')//from qy
	state = 5;//qsa
      else if (state == 6 && (s[charpos] == 'a'||s[charpos] == 'i'||s[charpos] == 'u'
                              ||s[charpos] == 'e'||s[charpos] == 'o'||s[charpos] == 'I'||s[charpos] == 'E'))//from qy
	state = 4;//to q1q0
      else if (state == 7 && s[charpos] == 't')//from q0qy
	state = 1;//to qt
      else if (state == 7 && s[charpos] == 's')//from q0qy
	state = 2;//to qs
      else if (state == 7 && s[charpos] == 'c')//from q0qy
	state = 3;//to qc
      else if (state == 7 && (s[charpos] == 'a'||s[charpos] == 'i'||s[charpos] == 'u'
                              ||s[charpos] == 'e'||s[charpos] == 'o'||s[charpos] == 'I'||s[charpos] == 'E'))//from q0qy
	state = 4;//to q1q0
      else if (state == 7 && (s[charpos] == 'd'||s[charpos] == 'w'||s[charpos] == 'z'||s[charpos] == 'y'||s[charpos] == 'j'))//from q0qy
	state = 5;//to qsa
      else if (state == 7 && (s[charpos] == 'b'||s[charpos] == 'g'||s[charpos] == 'h'||s[charpos] == 'k'
                              ||s[charpos] == 'n'||s[charpos] == 'm'||s[charpos] == 'p'||s[charpos] == 'r'))//from q0qy
	state = 6;//to qy
      else
	  return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 0||state == 4||state == 7) return(true);  // end in a final state
   else return(false);
 
}

// PERIOD DFA 
// Done by: Daniel Medina
bool period (string s)
{  // complete this **
  int state = 0;
  int charpos = 0;
  //replace the following todo the word dfa
  while (s[charpos] != '\0')
    {
      if (state == 0 && s[charpos] == '.')
	state = 1;//only one state for simple dfa
      else
	return(false);
      charpos++;
    }//end of while
  if (state == 1) return(true);  // end in a final state
  else return(false);
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: Daniel Medina

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {ERROR, EOFM, PERIOD, WORD1, WORD2, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"ERROR", "EOFM", "PERIOD", "WORD1", "WORD2", "VERB", "VERBNEG", "VERBPAST",
			"VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR"}; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
string reservedWords[18];//holds string for reserved word
tokentype resWordType[18];//hold type for corresponing index in reservedWords[]
void populateReservedWords()
{
  reservedWords[0]="masu";
  resWordType[0]=VERB;
  reservedWords[1]="masen";
  resWordType[1]=VERBNEG;
  reservedWords[2]="mashita";
  resWordType[2]=VERBPAST;
  reservedWords[3]="masendeshita";
  resWordType[3]=VERBPASTNEG;
  reservedWords[4]="desu";
  resWordType[4]=IS;
  reservedWords[5]="deshita";
  resWordType[5]=WAS;
  reservedWords[6]="o";
  resWordType[6]=OBJECT;
  reservedWords[7]="wa";
  resWordType[7]=SUBJECT;
  reservedWords[8]="ni";
  resWordType[8]=DESTINATION;
  reservedWords[9]="watashi";
  resWordType[9]=PRONOUN;
  reservedWords[10]="anata";
  resWordType[10]=PRONOUN;
  reservedWords[11]="kare";
  resWordType[11]=PRONOUN;
  reservedWords[12]="kanoja";
  resWordType[12]=PRONOUN;
  reservedWords[13]="sore";
  resWordType[13]=PRONOUN;
  reservedWords[14]="mata";
  resWordType[14]=CONNECTOR;
  reservedWords[15]="soshite";
  resWordType[15]=CONNECTOR;
  reservedWords[16]="shikashi";
  resWordType[16]=CONNECTOR;
  reservedWords[17]="dakara";
  resWordType[17]=CONNECTOR;
}
// ------------ Scaner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Daniel Medina
void scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.   
  fin>>w;
  if(w=="eofm")
    return;//end if eofm is found
  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.*/
  if(word(w))
    {
      if(w.back()=='I'||w.back()=='E')//if it ends in cap I or E then set to word 2
	tt = WORD2;
      else//otherwise set type to word1
	tt = WORD1;
    }
  else if(period(w))
    {
      tt = PERIOD;//if the word is a period, set type to period
    }
  else//otherwise its an error
    {
      tt = ERROR;
    }
  /*
  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.*/
  populateReservedWords();
  if(tt == WORD1 || tt == WORD2)
    {
      for(int i=0;i<18;i++)//check all reserved words
	{
	  if(reservedWords[i]==w)//if the word matches a reserved word
	    {
	      tt = resWordType[i];//change type to match reserved word type
	    }
	}
    }
  //4. Return the token type & string  (pass by reference)
  

}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Rika
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end

