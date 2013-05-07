#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( GATProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( GATProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, KcF );
      PROPERTYSLOT_SET_GET( Real, KcR );
      PROPERTYSLOT_SET_GET( Real, KS0 );
      PROPERTYSLOT_SET_GET( Real, KS1 );
      PROPERTYSLOT_SET_GET( Real, KP0 );
      PROPERTYSLOT_SET_GET( Real, KP1 );
      PROPERTYSLOT_SET_GET( Real, KE0 );
      PROPERTYSLOT_SET_GET( Real, Mode0 );
      PROPERTYSLOT_SET_GET( Real, Comp0 );
      PROPERTYSLOT_SET_GET( Real, Object0 );
    }

  GATProcess()
    :
    KcF (0.0),
    KcR (0.0),
    KS0 (0.0),
    KS1 (0.0),
    KP0 (0.0),
    KP1 (0.0),
    KE0 (0.0),
    Mode0 (0.0),
    Comp0 (0.0),
    Object0 (0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, KcF );
      SIMPLE_SET_GET_METHOD( Real, KcR );
      SIMPLE_SET_GET_METHOD( Real, KS0 );
      SIMPLE_SET_GET_METHOD( Real, KS1 );
      SIMPLE_SET_GET_METHOD( Real, KP0 );
      SIMPLE_SET_GET_METHOD( Real, KP1 );
      SIMPLE_SET_GET_METHOD( Real, KE0 );
      SIMPLE_SET_GET_METHOD( Real, Mode0 );
      SIMPLE_SET_GET_METHOD( Real, Comp0 );
      SIMPLE_SET_GET_METHOD( Real, Object0 );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setIK( RealCref value ) { IK = value; }
   //const Real getIK() const { return IK; }

    virtual void initialize()
      {
	Process::initialize();
	E = getVariableReference( "E" ).getVariable();  
	//velocity=N_A/60;
	//velocity1=N_A/60;
	 R0= getVariableReference( "R0" ).getVariable();
	 R1= getVariableReference( "R1" ).getVariable();
	 P0= getVariableReference( "P0" ).getVariable();
	 P1= getVariableReference( "P1" ).getVariable();
        I0= getVariableReference( "I0" ).getVariable();

      }

    virtual void fire()
    {  //::stdcout <<"\n" << "start"<< "\n";
      Real _KS[10];
      Real _KP[10];
      Real _KE[10];
      Real _Mode[10];
      Real _Comp[10];
      Real _Object[10];
      _Mode[0] = Mode0;
      _Object[0] = Object0;
      _Comp[0] = Comp0;
  _KS[0] = KS0/1000;
  _KS[1] = KS1/1000;
  _KP[0] = KP0/1000;
  _KP[1] = KP1/1000;
  _KE[0] = KE0/1000;
Real  effector[10];
 effector[0]=I0->getMolarConc();
 Real substrate[2];
 substrate[0]=R0->getMolarConc();
substrate[1]=R1->getMolarConc();
 Real product[2];
 product[0]=P0->getMolarConc();
 product[1]=P1->getMolarConc();

	Real _KcF = KcF/60;
Real  _KcR = KcR/60;
  // (reflecting Competitive modifiers) 
  // calculate apparent K for Substrate

  TotalSA = 0;
  TotalSI = 0;
  Q_Denom = 1;
  TotalPA = 0;
  TotalPI = 0;
  Q_Num = 1;

  for(i=0; i<2; i++)
    {
      for(j=0; j<1; j++)
        {
          if(_Object[j]==i && _Comp[j] == 1)
            {
	     if(_Mode[j]==2)
	        {
		  TotalSI += ((effector[j]) / _KE[j]);
                }
            }
        }

       	_KS[i] *= (1 + TotalSA + TotalSI);
      Q_Denom *=((substrate[i]) * 1000);

    }

  // calculate apparent K for Product

  for(i=0; i<2; i++)
    { 
      for(j=0; j<1; j++)
        {
          if(_Object[j]==i+10 && _Comp[j] == 1)
            {
               if(_Mode[j]==2)
	        {
		  TotalPI += ((effector[j]) / _KE[j]);
                }
            }

        }

    	_KP[i] *= (1 + TotalPA + TotalPI);

      Q_Num *= ((product[i]) * 1000 ); 

    }

  if( _KcR == 0 )
    {
      S = 1;
    }
  else
    {
      Keq = _KcF / _KcR;
      for(i=0; i<2; i++)
      {
        Keq /= (_KS[i]*1000); // hosei ga hitsuyou
      }
      for(i=0; i<2; i++)
      {
        Keq *= (_KP[i]*1000); // 
      }

      Q = Q_Num/Q_Denom;

      S = 1 - Q/Keq;
     }


  TermS = 0;
  TermP = 0;
  for(i=0; i<2; i++)
    {
      TermS += (_KS[i]/(substrate[i]));

    }
  for(i=0; i<2; i++)
    { 
      if(_KP[i] > 0)
        {      
          TermP += (product[i]/_KP[i]);

        }
    }
  Y = S / ( 1 + TermS * (1 + TermP) );
  //std::cout << " Y = " << Y << "\n"; 
  TermNA = 0;
  TermNI = 0;
  for(j=0; j<1; j++)
    {      
      if(_Comp[j] == 2)
        {
          if(_Mode[j] == 1)
            {
              TermNA += (_KE[j]/effector[j]);
            }
          else if(_Mode[j] == 2)
            {
              TermNI += (_KE[j]/effector[j]);
            }       
	}
    }


  Yd = Y / ( 1 + TermNA + TermNI );


  Real velocity = E->getValue();

  if(Yd >= 0)
    {
      velocity *= Yd * _KcF;
     }
  else if(Yd < 0)
    {
      velocity *= Yd * _KcR;
     }
setFlux(velocity);
      }

 protected:
    //Real velocity1;
 Real	KcF ;
 Real       KcR ;
  Real      KS0 ;
  Real      KS1 ;
Real	KP0 ;
  Real      KP1 ;
Real	KE0 ;
Real	Mode0 ;
Real	Comp0 ;
Real	Object0 ;
    Variable* E;
    Variable* R0;
    Variable* R1;
    Variable* P0;
    Variable* P1;
    Variable* P2;
    Variable* I0;

Real Keq;
Real Q;
Real Q_Denom;
Real Q_Num;
Real S; // 1-Q/Keq
Real TotalSA;
Real TotalPA;
Real TotalSI;
Real TotalPI;
Real TermS;
Real TermP;
Real TermNA;
Real TermNI;
Real Y;
Real Yd;
Integer i;
Integer j;
  private:

};

LIBECS_DM_INIT( GATProcess, Process );

