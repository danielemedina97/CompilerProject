#include<iostream>
#include<fstream>
#include<string>
#include <sstream>

using namespace std;

/* INSTRUCTION:  copy your parser.cpp here
      cp ../ParserFiles/parser.cpp .
   Then, insert or append its contents into this file and edit.
   Complete all ** parts.
*/

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: 19 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Adam Mikulics
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
// Done by: Adam Mikulics
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

// TABLES Done by: Adam Mikulics

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
// ** Done by: Adam
void scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.   
  fin>>w;

  cout<<"Scanner called using word: "<<w<<endl;//added after scanner written!

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
      cout<<"Lexical error: "<<w<<" is not a valid token."<<endl;//added for part B
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



//============================================================================================================================================

//============================================================================================================================================

//============================================================================================================================================


//=================================================
// File parser.cpp written by Group Number: 19
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------
string saved_lexeme;
tokentype saved_token;

bool token_available = false;

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: found token type different than expected; used when match() fails
// Done by: Adam
void syntaxerror1(tokentype expected,string str)
{
  cout<<"SYNTAX ERROR: expected "<<tokenName[expected]<<" but found "<<str<<endl;
  exit(1);
}
// Type of error: string found was not expected, used in switch default
// Done by: Adam
void syntaxerror2(string found,string location)
{
  cout<<"SYNTAX ERROR: Unexpected "<<found<<" found in "<<location<<endl;
  exit(1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: Look ahead for the next token, returns type of next token
// Done by: Daniel Medina
tokentype next_token()
{
  if (!token_available)   // if there is no saved token yet
    { 
      scanner(saved_token, saved_lexeme);  // call scanner to grab a new token
      token_available = true;              // mark that fact that you have saved it

      if (saved_token == ERROR)
	{ 
	  // syntaxerror1(saved_token, saved_lexeme);
	}
    }
  return saved_token;    // return the saved token

}

// Purpose: returns true if the next token matches what is expected
// Done by: Daniel Medina
bool match(tokentype expected)
{
  if (next_token() != expected)   // mismatch has occurred with the next token
    {
      // calls a syntax error function here to generate a syntax error message here and do recovery
      syntaxerror2(saved_lexeme,"match()");
    }
  else  // match has occurred
    {
      cout<<"Matched: "<<tokenName[expected]<<endl;
      token_available = false;   // eat up the token
      return true;                        // say there was a match
    }

}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

//prototypes:
void s();
void afterSubject();
void afterNoun();
void afterObject();
void noun();
void verb();
void be();
void tense();

void gen(string line_type);
void getEword();

// Grammar: <story> ::= <s> { <s> } 
// Done by: Adam
void story()
{
  cout<<"Processing <story>"<<endl<<endl;
  s();
  while(true)
    {
      switch(next_token())
	{
	case tokentype::CONNECTOR:
	case tokentype::WORD1:
	case tokentype::PRONOUN:
	  s();
	  break;
	default:
	  cout<<endl<<"Successfully parsed <story>."<<endl;
	  return;
	}
    }
}

// Grammar: <s> ::= [CONNECTOR] <noun> SUBJECT <after subject>
// Done by:Daniel Medina
void s()
{
  cout<<"Processing <s>"<<endl;
  if(next_token()==tokentype::CONNECTOR)
    {
      match(tokentype::CONNECTOR);
      getEword();
      gen("CONNECTOR");
    }
  noun();
  getEword();
  match(tokentype::SUBJECT);
  gen("SUBJECT");
  afterSubject();
}

// Grammar:<after subject> ::= <verb> <tense> PEROD | <noun> <after noun>
// Done by:Adam
void afterSubject()
{
  cout<<"Processing <afterSubject>"<<endl;
  switch(next_token())
    {
    case tokentype::WORD2://verb tense PERIOD
      verb();
      getEword();
      gen("verb");
      tense();
      gen("tense");
      match(tokentype::PERIOD);
      break;
    case tokentype::WORD1:
    case tokentype::PRONOUN://noun after_noun
      noun();
      getEword();
      afterNoun();
      break;
    default:
      syntaxerror2(saved_lexeme,"afterSubject");
      break;
    }
}

// Grammar:<be> PERIOD  | DESTINATION <verb> <tense> PERIOD | OBJECT <after object>
// Done by:Daniel Medina
void afterNoun()
{
  cout<<"Processing <afterNoun>"<<endl;
  switch(next_token())
    {
    case tokentype::IS:
    case tokentype::WAS:// be PERIOD
      be();
      gen("be");
      gen("tense");
      match(tokentype::PERIOD);
      break;
    case tokentype::DESTINATION://DESTINATION verb tense PERIOD
      match(tokentype::DESTINATION);
      verb();
      getEword();
      gen("verb");
      tense();
      gen("tense");
      match(tokentype::PERIOD);
      break;
    case tokentype::OBJECT: //OBJECT after_object
      match(tokentype::OBJECT);
      gen("OBJECT");
      afterObject();
      break;
    default:
      syntaxerror2(saved_lexeme,"afterNoun");
      break;
    }
}

// Grammar:<after object> ::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
// Done by:Connor
void afterObject()
{
  cout<<"Processing <afterObject>"<<endl;
  switch(next_token())
    {
    case tokentype::WORD2://verb tense PERIOD
      verb();
      getEword();
      gen("verb");
      tense();
      gen("tense");
      match(tokentype::PERIOD);
      break;
    case tokentype::WORD1:
    case tokentype::PRONOUN:// noun DESTINATION verb tense
      noun();
      getEword();
      match(tokentype::DESTINATION);
      gen("DESTINATION");
      verb();
      getEword();
      gen("verb");
      tense();
      gen("tense");
      match(tokentype::PERIOD);
      break;
    default:
      syntaxerror2(saved_lexeme,"afterObject");
      break;
    }
}

// Grammar:<noun> ::= WORD1 | PRONOUN
// Done by:Daniel Medina
void noun()
{
  cout<<"Processing <noun>"<<endl;
  switch(next_token())
    {
    case tokentype::WORD1://WORD1
      match(tokentype::WORD1);
      break;
    case tokentype::PRONOUN://PRONOUN
      match(tokentype::PRONOUN);
      break;
    default:
      syntaxerror2(saved_lexeme,"noun");
      break;
    }
}

// Grammar:<verb> ::= WORD2
// Done by:Adam
void verb()
{
  cout<<"Processing <verb>"<<endl;
  switch(next_token())
    {
    case tokentype::WORD2://WORD2
      match(tokentype::WORD2);
      break;
    default:
      syntaxerror2(saved_lexeme,"verb");
      break;
    }
}

// Grammar:<be> ::=   IS | WAS
// Done by:Connor
void be()
{
  cout<<"Processing <be>"<<endl;
  switch(next_token())
    {
    case tokentype::IS://IS
      match(tokentype::IS);
      break;
    case tokentype::WAS://WAS
      match(tokentype::WAS);
      break;
    default:
      syntaxerror2(saved_lexeme,"be");
      break;
    }
}

// Grammar: <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
// Done by: Connor
void tense()
{
  cout<<"Processing <tense>"<<endl;
  switch(next_token())
    {
    case tokentype::VERBPAST:
      match(tokentype::VERBPAST);
      break;
    case tokentype::VERBPASTNEG:
      match(tokentype::VERBPASTNEG);
      break;
    case tokentype::VERB:
      match(tokentype::VERB);
      break;
    case tokentype::VERBNEG:
      match(tokentype::VERBNEG);
      break;
    default:
      syntaxerror2(saved_lexeme,"tense");
      break;
    }
}

string filename;

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by: Connor
/*
int main()
{
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  story();//** calls the <story> to start parsing
  fin.close();//** closes the input file 

}// end

*///** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions

//===========================================================================================================================================================
//===========================================================================================================================================================
//===========================================================================================================================================================

//=================================================
// File translator.cpp written by Group Number: 19
//=================================================
string saved_E_word;

// ----- Additions to the parser.cpp ---------------------

// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt 
//  Done by: Daniel Medina
string lexicon[47][2];
void populateLexicon()
{
  ifstream fileLexicon;
  fileLexicon.open("lexicon.txt");
  
  int i=0;
  string line;

  while(fileLexicon>>line)
    {
      lexicon[i][0] = line;
      fileLexicon >> line;
      lexicon[i][1]=line;
      //cout<<"japanese: "<<lexicon[i][0]<<" english: "<<lexicon[i][1]<<endl;
      i++;
    }
  fileLexicon.close();
}

// ** Additions to parser.cpp here:
//    getEword() - using the current saved_lexeme, look up the English word
//                 in Lexicon if it is there -- save the result   
//                 in saved_E_word
void getEword()
{
  for(int i = 0; i < 47 ; i++)
    {
      //cout<<"comparing "<<saved_lexeme<<" to "<<lexicon[i][0]<<endl;
      if(saved_lexeme.compare(lexicon[i][0])==0)
	{
	  saved_E_word=lexicon[i][1];
	  return;
	}
    }
  saved_E_word = saved_lexeme;
}


//  Done by: ** 
//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
//  Done by: **
//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
//  Done by: Daniel Medina
ofstream translated;
void gen(string line_type){
  //std::ofstream translated;//output file var
  //translated.open("translated.txt", std::ios_base::app); // append instead of overwrite
    
  if(line_type.compare("CONNECTOR") == 0){
    translated << "CONNECTOR: " << saved_E_word << endl;
  } else if(line_type.compare("SUBJECT") == 0){
    translated << "ACTOR: " << saved_E_word << endl;
  } else if(line_type.compare("be") == 0){
    translated << "DESCRIPTION: " << saved_E_word << endl;
    translated << "TENSE: " << saved_token << endl;
  } else if(line_type.compare("OBJECT") == 0){
    translated << "OBJECT: " << saved_E_word << endl;
  } else if(line_type.compare("DESTINATION") == 0){
    translated << "TO: " << saved_E_word << endl;
  } else if(line_type.compare("verb") == 0){
    translated << "ACTION" << ": " << saved_E_word << endl;
  } else if(line_type.compare("tense") == 0){
    translated << "TENSE: "<< saved_token << endl;
  }
  //translated.close();
}
 

// ----- Changes to the parser.cpp content ---------------------

// ** Comment update: Be sure to put the corresponding grammar 
//    rule with semantic routine calls
//    above each non-terminal function 

// ** Each non-terminal function should be calling
//    getEword and/or gen now.


// ---------------- Driver ---------------------------

// The final test driver to start the translator
// Done by:  Daniel Medina



int main()
{
  //** opens the lexicon.txt file and reads it into Lexicon
  //** closes lexicon.txt 

  //** opens the output file translated.txt

  populateLexicon();
  translated.open("translated.txt", std::ios_base::out);

  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  story();  //** calls the <story> to start parsing

  //** closes the input file 
  fin.close();//** closes traslated.txt
  translated.close();
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions

