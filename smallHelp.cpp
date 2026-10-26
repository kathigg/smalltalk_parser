#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/*****************************************************************
 *                     DECLARATIONS                              *
 *****************************************************************/
typedef int NUMBER;
typedef int NAME;
const int  NAMELENG = 55;      /* Maximum length of a name */
const int  MAXNAMES = 1000;     /* Maximum number of different names */
const int  MAXINPUT = 10000;     /* Maximum length of an input */
const char*   PROMPT = "-> ";
const char*   PROMPT2 = "> ";
const char  COMMENTCHAR = ';';
const int   TABCODE = 9;        /* in ASCII */

struct EXPLISTREC;
typedef EXPLISTREC* EXPLIST;

enum EXPTYPE {VALEXP,VAREXP,APEXP};

struct STVALUEREC;
typedef STVALUEREC* STVALUE;

struct CLASSREC;
typedef CLASSREC* CLASS;


struct EXPREC
{
	  EXPTYPE etype; //what type of expression
	  STVALUE valu;
	  NAME varble;
	  NAME optr;
	  EXPLIST args;
};
typedef EXPREC* EXP;

struct EXPLISTREC
{
	  EXP head;
	  EXPLIST tail;
};


struct VALUELISTREC
{
	  STVALUE  head;
	  VALUELISTREC*  tail;
};

typedef VALUELISTREC* VALUELIST;

struct NAMELISTREC
{
	  NAME   head;
	  NAMELISTREC* tail;
};
typedef NAMELISTREC* NAMELIST;


struct  ENVREC
{
	   NAMELIST vars;
	   VALUELIST values;
};

typedef ENVREC* ENV;

enum STVALUETYPE  {INT,SYM,USER};

struct  STVALUEREC
{
      CLASS owner;
      STVALUETYPE vtype;
      int intval;  //if its INT
      NAME symval; //if its SYM
      ENV userval; //if its USER
};


struct  FUNDEFREC
{
	       NAME  funname;
	       NAMELIST  formals;
	       EXP  body;
	       FUNDEFREC*  nextfundef;
};
typedef FUNDEFREC* FUNDEF;

struct   CLASSREC
{
          NAME clname;
          CLASS clsuper;
          NAMELIST clrep;
          FUNDEF exported;
          CLASS nextclass;
};

FUNDEF  fundefs;         //pointer to global functions
ENV     globalEnv;       //pointer to global enviornment
EXP     currentExp;      //pointer to the expression to be eval
char userinput[MAXINPUT];//array to store the user input
int  inputleng, pos;
char*  printNames[MAXNAMES]; //symbol table
int   numNames, numBuiltins,numCtrlOps;
NAME  SELF;   //location of self in the symbol table
CLASS OBJECTCLASS; //pointer to the abstract object class
CLASS classes;     //pointer to all the classes
STVALUE objectInst;//pointer to the instance of object class
STVALUE trueValue, falseValue;
int   quittingtime;

/*****************************************************************
 *                     DATA STRUCTURE OP'S                       *
 *****************************************************************/

/* mkVALEXP - return an EXP of type VALEXP with num n            */

EXP mkVALEXP ( STVALUE v)
{
   EXP e;
  //do it again
   return e;
}/* mkVALEXP */


/* mkVAREXP - return an EXP of type VAREXP with varble nm  */

EXP mkVAREXP ( NAME nm)
{
   EXP e;
    //do it again
   return e;
}/* mkVAREXP */


/* mkAPEXP - return EXP of type APEXP w/ optr op and args el     */

EXP mkAPEXP (NAME op, EXPLIST el)
{
   EXP  e;
    //do it again
   return e;
}/* mkAPEXP */



/* mkINT - return an STVALUE with integer value n    */

STVALUE mkINT (int n )
{
   STVALUE newval;
   newval = new STVALUEREC;
   newval->owner = OBJECTCLASS;
   newval->vtype = INT;
   newval->intval = n;
   return (newval);
} /* mkINT */

/* mkSYM - return an STVALUE with symbol value s   */

STVALUE mkSYM ( NAME s)
{
   STVALUE newval;
    //do it
   return(newval);
} /* mkSYM */

/* mkUSER - return a USER-type STVALUE    */

STVALUE mkUSER (ENV rho, CLASS ownr)
{
   STVALUE newval;
    //do it
   return(newval);
} /* mkUSER */


/* mkExplist - return an EXPLIST with head e and tail el         */

EXPLIST mkExplist (EXP e, EXPLIST el)
{
    EXPLIST newel;
    //do it again
    return newel;
}/* mkExplist */

/* mkNamelist - return a NAMELIST with head n and tail nl        */

NAMELIST mkNamelist ( NAME nm, NAMELIST nl)
{
   NAMELIST newnl;
    //do it again
   return newnl;
}/* mkNamelist */

/* mkValuelist - return an VALUELIST with head n and tail vl     */

VALUELIST mkValuelist (STVALUE n,  VALUELIST vl)
{
   VALUELIST newvl;
    //do it again
   return newvl;
}/* mkValuelist */

/* mkEnv - return an ENV with vars nl and values vl              */

ENV mkEnv ( NAMELIST nl, VALUELIST vl)
{
    ENV rho;
    //do it again
    return rho;
}/* mkEnv */

/* lengthVL - return length of VALUELIST vl      */

int lengthVL ( VALUELIST vl)
{
   int i = 0;
   //do it again
   return i;
}/* lengthVL */

/* lengthNL - return length of NAMELIST nl    */

int lengthNL ( NAMELIST nl)
{
   int i = 0;
   //do it again
   return i;
}/* lengthNL */


/*****************************************************************
 *                     NAME MANAGEMENT                           *
 *****************************************************************/

// fetchFun - get function definition of NAME fname from fenv


FUNDEF fetchFun (NAME fname, FUNDEF fenv)
{
   while (fenv != 0)
   {
      if ( fenv->funname == fname )
         return fenv;
      fenv = fenv->nextfundef;
   }
   return 0;
} // fetchFun



// fetchClass - get class definition of NAME cname   

CLASS fetchClass (NAME cname)
{
    CLASS cl;
    cl = classes;
    //do it
    return 0;
}// fetchClass 



/* newClass - add new class cname to classes      */
CLASS newClass (NAME cname, CLASS super)
{
   CLASS cl = new CLASSREC;
 //do it
   return(classes);
}// newClass

//  newFunDef - add new function fname to fenv
FUNDEF newFunDef (NAME fname, FUNDEF& fenv)
{
   FUNDEF f;
 //do it
   return f;
} // newFunDef




// initNames - place all pre-defined names into printNames 

void initNames()
{
   int i =0;
   fundefs = 0;
   printNames[i] = (char* ) "if";    i++;    //0
   printNames[i] = (char* ) "while"; i++;    //1
   printNames[i] = (char* ) "set";   i++;    //2
   printNames[i] = (char* ) "begin"; i++;    //3
   printNames[i] = (char* ) "new";   i++;    //4
   numCtrlOps    = i - 1; 
   printNames[i] = (char* ) "+";     i++;    //5
   printNames[i] = (char* ) "-";     i++;    //6
   printNames[i] = (char* ) "*";     i++;    //7
   printNames[i] = (char* ) "/";     i++;    //8
   printNames[i] = (char* ) "=";     i++;    //9
   printNames[i] = (char* ) "<";     i++;   //10
   printNames[i] = (char* ) ">";     i++;   //11
   printNames[i] = (char* ) "print";  i++;  //12
   printNames[i] = (char* ) "self";         //13
   SELF = i;
   numNames = i;
   numBuiltins = i-1;
}//initNames

// install - insert new name into printNames  

NAME install ( char* nm)
{
   int i = 0;
   while (i <= numNames)
   { 
      if (strcmp( nm,printNames[i] ) == 0)
	     return i;
      i++;
   }
   numNames = i;
   printNames[i] = new char[strlen(nm) + 1];
  strcpy(printNames[i], nm);
  return i;
}// install

// prName - print name nm              

void prName ( NAME nm)
{
	 cout<< printNames[nm];
	 cout.flush();
} //prName

//****************************************************************
//                        INPUT                                  *
 //*****************************************************************

// isDelim - check if c is a delimiter   

int isDelim (char c)
{
   return ( ( c == '(') || ( c == ')') ||( c == ' ')||( c== COMMENTCHAR) );
}

// skipblanks - return next non-blank position in userinput 

int skipblanks (int p)
{
   while (userinput[p] == ' ')
   	++p;
   return p;
}


// matches - check if string nm matches userinput[s .. s+leng]   

int matches (int s, int leng,  char* nm)
{
   int i=0;
   while (i < leng )
   {
	 if( userinput[s] != nm[i] )
	    return 0;
	 ++i;
	 ++s;
    }
   if (!isDelim(userinput[s]) )
	  return 0;
   return 1;
}// matches 

// nextchar - read next char - filter tabs and comments 

void nextchar (char& c)
{
    scanf("%c", &c);
    if (c == COMMENTCHAR )
    {
	  while ( c != '\n' )
		scanf("%c",&c);
    }
}

// readParens - read char's, ignoring newlines, to matching ')'
void readParens()
{
   int parencnt; // current depth of parentheses 
   char c;
   parencnt = 1; // '(' just read
   do
   {
	  if (c == '\n')
	    cout <<PROMPT2;
	  cout.flush();
	  nextchar(c);
	  pos++;
	  if (pos == MAXINPUT )
	  {
		cout <<"User input too long\n";
		exit(1);
	  }
	  if (c == '\n' )
		userinput[pos] = ' ';
	  else
		userinput[pos] = c;
	  if (c == '(')
		++parencnt;
	  if (c == ')')
	    parencnt--;
	}
    while (parencnt != 0 );
} //readParens

// readInput - read char's into userinput 

void readInput()
{
    char  c;
    cout << PROMPT;
    cout.flush();
    pos = -1;
    do
	 {
	    ++pos ;
	    if (pos == MAXINPUT )
	    {
		    cout << "User input too long\n";
		    exit(1);
	    }
	    nextchar(c);
	    if (c == '\n' )
		   userinput[pos] = ' ';
	    else
		   userinput[pos] = c;
	    if (userinput[pos] == '(' )
		  readParens();
	 }
	while (c != '\n');
	inputleng = pos;
	userinput[pos+1] = COMMENTCHAR; // sentinel
}


// reader - read char's into userinput; be sure input not blank  

void reader ()
{
    do
    {
	  readInput();
	  pos = skipblanks(0);
    }
    while( pos > inputleng); // ignore blank lines
}

// parseName - return (installed) NAME starting at userinput[pos]


NAME parseName()
{
   char nm[35]; // array to accumulate characters
   int leng; // length of name
   leng = 0;
   while ( (pos <= inputleng) && !isDelim(userinput[pos]) )
   {
	    
	    nm[leng] = userinput[pos];
	   pos++;
	   leng++;
   }
   if (leng == 0)
   {
	   cout<<"Error: expected name, instead read: "<< userinput[pos]<<endl;
	   exit(1);
   }
   nm[leng] = '\0';
   pos = skipblanks(pos); // skip blanks after name
   return ( install(nm) );
}// parseName

/* isDigits - check if sequence of digits begins at pos   */

int isDigits (int pos)
{
   if ( ( userinput[pos] < '0' ) ||  ( userinput[pos] > '9' ) )
	  return 0;
   while ( ( userinput[pos] >='0') && ( userinput[pos] <= '9') )
	 ++pos;   
   if (!isDelim(userinput[pos] ))
	 return 0;
   return 1;
}// isDigits


/* isNumber - check if a number begins at pos  */

int isNumber (int pos)
{
  return ( isDigits(pos) || ((userinput[pos] == '-') &&
                                               isDigits(pos+1)));
}// isNumber


/* parseInt - return number starting at userinput[pos]   */

int parseInt()
{
    int n, sign;
    n = 0; sign = 1;
    pos = skipblanks(pos); 
    if ( userinput[pos] == '-' )
    {
          sign = -1;
          pos++;
    }
    while ( (userinput[pos] >= '0') && (userinput[pos] <= '9' ) )
    {
        n = 10*n + userinput[pos] - '0';
        pos++;
    }
    pos = skipblanks(pos); // skip blanks after number
    return (n*sign);
}// parseInt


int isValue (int pos)
{
   return ((userinput[pos] == '#') || isNumber(pos));
}// isValue

/* parseVal - return number starting at userinput[pos]   */

STVALUE parseVal()
{
    STVALUE s;    
    //do it two possibilities; SYM and INT
        
}

EXPLIST parseEL();

// parseExp - return EXP starting at userinput[pos]  

EXP parseExp()
{
   pos = skipblanks(pos);
   //do it again
}// parseExp

// parseEL - return EXPLIST starting at userinput[pos]
EXPLIST parseEL()
{
   pos = skipblanks(pos);
   //do it again
 
}// parseEL


// parseNL - return NAMELIST starting at userinput[pos] 

NAMELIST parseNL()
{
   NAME nm;
   NAMELIST nl, nlr;
   //do is again
   return nlr;
}// parseNL

NAME parseDef (FUNDEF& fenv)
{
   NAME fname;        // function name
   FUNDEF newfun;     // new FUNDEFREC
  //do this again (almost the same)
   return(fname);
} // parseDef

NAME parseClass()
{
   NAME cname, sname, fname;
   CLASS thisclass, superclass;
   NAMELIST rep;;
   FUNDEF cenv;
   //This is long please be very careful
   return cname;
}// parseClass


/*****************************************************************
 *                     ENVIRONMENTS                              *
 *****************************************************************/

/* emptyEnv - return an environment with no bindings */

ENV emptyEnv()
{
   return  mkEnv(0, 0);
}


// bindVar - bind variable nm to value n in environment rho

void bindVar ( NAME nm, STVALUE v, ENV rho)
{
   rho->vars = mkNamelist(nm, rho->vars);
   rho->values = mkValuelist(v, rho->values);
}// bindVar

// findVar - look up nm in rho   

VALUELIST findVar ( NAME nm, ENV rho)
{
   NAMELIST  nl;
   VALUELIST  vl;
   nl = rho->vars;
   vl = rho->values;
   while  (nl != 0)
	{
       if ( nl->head == nm )
           return  vl;
	
	    nl = nl->tail;
	    vl = vl->tail;
		};
   return 0;
}


// assign - assign value n to variable nm in rho 

void  assign (NAME nm,  STVALUE v, ENV rho)
{
   VALUELIST varloc;
   varloc = findVar(nm, rho);
   varloc->head = v;
}// assign

// fetch - return number bound to nm in rho 

STVALUE fetch ( NAME nm, ENV rho)
{
   VALUELIST  vl;
   vl = findVar(nm, rho);
   return (vl->head);
}

// isBound - check if nm is bound in rho  

int isBound ( NAME nm, ENV rho)
{
   return ( findVar(nm, rho) != 0 );
}



/*****************************************************************
 *                     VALUES                                    *
 *****************************************************************/

// prValue - print value v

void prValue ( STVALUE v)
{
   if (v->vtype == INT )
      cout <<(v->intval);
   else if( v->vtype == SYM )
       prName(v->symval);
   else
       cout << "<userval>";

} // prValue


// isTrueVal - return true if v is true (non-zero) value



int isTrueVal ( STVALUE v)
{
  if ((v->vtype == USER) || (v->vtype == SYM))
    return 1;
  return (v->intval != 0 );
} //isTrueVal


// arity - return number of arguments expected by op  

int arity ( int op)
{
	 if ( ( op > 4) && (op < 12) )
	    return 2;
	 return  1;
}// arity

/* applyValueOp - apply VALUEOP op to arguments in VALUELIST vl */

STVALUE applyValueOp ( int op,  VALUELIST vl)
{
   NUMBER  n, n1, n2;
   STVALUE s1, s2;
//next part
    
} // applyValueOp

/*****************************************************************
 *                     EVALUATION                                *
 *****************************************************************/



/* evalList - evaluate each expression in el */


STVALUE eval ( EXP e,  ENV rho, STVALUE rcvr);

VALUELIST evalList ( EXPLIST el, ENV rho, STVALUE rcvr)
{
    STVALUE h;
    VALUELIST t, vl;
    //next part;
    return vl;
}// evalList



// applyGlobalFun - apply function defined at top level

STVALUE applyGlobalFun (NAME optr, VALUELIST actuals, STVALUE rcvr)
{
    //next part
}// applyGlobalFun


// methodSearch - find class of optr, if any, starting at cl

FUNDEF methodSearch (NAME optr,  CLASS cl)
{
   FUNDEF f;
   f = 0;
    //next part
}// methodSearch

// applyMethod - apply method f to actuals

STVALUE applyMethod (FUNDEF f, VALUELIST actuals)
{
   ENV rho;
    //next part

}// applyMethod

// mkRepFor - make list of all zeros of same length as nl

VALUELIST mkRepFor ( NAMELIST nl)
{
    //next part
}// mkRepFor

// applyCtrlOp - apply CONTROLOP op to args in rho

STVALUE applyCtrlOp (int op, EXPLIST args, ENV rho, STVALUE rcvr)
{
    STVALUE v;
    CLASS cl;
    STVALUE newval;
    //next part
}// applyCtrlOp

// eval - return value of e in environment rho, receiver rcvr


STVALUE eval (EXP e, ENV rho, STVALUE rcvr)
{
   VALUELIST vl;
   FUNDEF f;
   switch( e->etype )
   {
    case VALEXP : return(e->valu);
    case VAREXP : if (isBound(e->varble, rho))
                   //do this
                  cout <<"Undefined variable: ";
                  prName(e->varble);
                  cout<<endl;;
                  exit(1);
                  //goto 99
                  break;
     case APEXP :  if (e->optr <= numCtrlOps )
                       return applyCtrlOp(e->optr, e->args, rho, rcvr);
                   vl = evalList(e->args, rho, rcvr);
				   if (vl == 0 )
                        return applyGlobalFun(e->optr, vl,  rcvr);
                   f = methodSearch(e->optr, vl->head->owner);
                   if (f != 0 )
                      return applyMethod(f, vl);
                   if (e->optr <= numBuiltins )
                      return applyValueOp(e->optr, vl);
                   return applyGlobalFun(e->optr, vl,  rcvr);

                 break;
    }//switch
} // eval




/*****************************************************************
 *                     READ-EVAL-PRINT LOOP                      *
 *****************************************************************/

// initHierarchy - allocate class Object and create an instance

void initHierarchy()
{
    fundefs = 0; 
     classes = 0;
    OBJECTCLASS = newClass(install((char* )"Object"), 0);
    OBJECTCLASS->exported = 0;
    OBJECTCLASS->clrep = mkNamelist(SELF, 0);
    objectInst = mkUSER(mkEnv(OBJECTCLASS->clrep, mkValuelist(mkINT(0), 0)),
                   OBJECTCLASS);
}// initHierarchy

int main()
{
   initNames();
   initHierarchy();
   globalEnv = emptyEnv();

   trueValue = mkINT(1);
   falseValue = mkINT(0);

   quittingtime = 0;

   while (!quittingtime)
   {
      reader();
      if (matches(pos, 4, (char* ) "quit"))
        quittingtime = 	1;
      else if ((userinput[pos] == '(') &&
                (matches(skipblanks(pos+1), 6,(char* )"define")) )
      {
           prName(parseDef(fundefs));
           cout <<endl;
      }
      else if ( (userinput[pos]=='(') &&
                    ( matches(skipblanks(pos+1),5, (char* )"class")))
      {
          prName(parseClass());
          cout << endl;
      }
      else
      {

         currentExp = parseExp();
       
         prValue(eval(currentExp, emptyEnv(), objectInst));
         cout <<endl;
      }
    }// while
    return 0;
} // smalltalk

