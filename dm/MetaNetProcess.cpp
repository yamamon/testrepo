#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( MetaNetProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( MetaNetProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, Vr );
      PROPERTYSLOT_SET_GET( Real, Vf );
      PROPERTYSLOT_SET_GET( Real, PK0 );
      PROPERTYSLOT_SET_GET( Real, PK1 );
      PROPERTYSLOT_SET_GET( Real, PK2 );
      PROPERTYSLOT_SET_GET( Real, PK3 );
      PROPERTYSLOT_SET_GET( Real, RK0 );
      PROPERTYSLOT_SET_GET( Real, RK1 );
      PROPERTYSLOT_SET_GET( Real, RK2 );
      PROPERTYSLOT_SET_GET( Real, RK3 );
      PROPERTYSLOT_SET_GET( Integer, PN );
      PROPERTYSLOT_SET_GET( Integer, RN );
    }

  MetaNetProcess()
    :
    Vr(0.0),
    Vf(0.0),
    PK0(0.0),
    PK1(0.0),
    PK2(0.0),
    PK3(0.0),
    RK0(0.0),
    RK1(0.0),
    RK2(0.0),
    RK3(0.0),
    PN(0),
    RN(0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, Vr );
      SIMPLE_SET_GET_METHOD( Real, Vf );
      SIMPLE_SET_GET_METHOD( Real, PK0 );
      SIMPLE_SET_GET_METHOD( Real, PK1 );
      SIMPLE_SET_GET_METHOD( Real, PK2 );
      SIMPLE_SET_GET_METHOD( Real, PK3 );
      SIMPLE_SET_GET_METHOD( Real, RK0 );
      SIMPLE_SET_GET_METHOD( Real, RK1 );
      SIMPLE_SET_GET_METHOD( Real, RK2 );
      SIMPLE_SET_GET_METHOD( Real, RK3 );
      SIMPLE_SET_GET_METHOD( Integer, PN );
      SIMPLE_SET_GET_METHOD( Integer, RN );

   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	E = getVariableReference( "E" ).getVariable();  
	//velocity=N_A/60;
	//velocity1=N_A/60;
	if(RN>0){ R0= getVariableReference( "R0" ).getVariable();}
	if(RN>1){ R1= getVariableReference( "R1" ).getVariable();}
	if(RN>2){ R2= getVariableReference( "R2" ).getVariable();}
	if(RN>3){ R3= getVariableReference( "R3" ).getVariable();}
	if(PN>0){ P0= getVariableReference( "P0" ).getVariable();}
	if(PN>1){ P1= getVariableReference( "P1" ).getVariable();}
	if(PN>2){ P2= getVariableReference( "P2" ).getVariable();}
	if(PN>3){ P3= getVariableReference( "P3" ).getVariable();}
	//Vf/=60;
	//Vr/=60;
      }

    virtual void fire()
    {  //::stdcout <<"\n" << "start"<< "\n";
      std::vector<Real> R;
      std::vector<Real> RK;
      std::vector<Real> P;
      std::vector<Real> PK;
	Real E1( E->getMolarConc() );
	if(RN>0){R.push_back(R0->getMolarConc());
		RK.push_back(RK0);}
	if(RN>1){R.push_back(R1->getMolarConc());
		RK.push_back(RK1);}
	if(RN>2){R.push_back(R2->getMolarConc());
		RK.push_back(RK2);}
	if(RN>3){R.push_back(R3->getMolarConc());
	RK.push_back(RK3);}
	
	
	
	
	
	if(PN>0){P.push_back(P0->getMolarConc());
	PK.push_back(PK0);}
	if(PN>1){P.push_back(P1->getMolarConc());
	PK.push_back(PK1);}
	if(PN>2){P.push_back(P2->getMolarConc());
	PK.push_back(PK2);}
	if(PN>3){P.push_back(P3->getMolarConc());
	PK.push_back(PK3);}
	


	Real pyPk=1;
	Real pyP=1;
	Real pyRk=1;
	Real pyR=1;
	Real QKeq; 
	if(Vr==0){QKeq=0;}else{
for(int i=0;i<RN;i++){
  pyR*=R[i];
  pyRk*=RK[i];
}
for(int i=0;i<PN;i++){
  pyP*=P[i];
  pyPk*=PK[i];
}
 Real Q=pyP/pyR;
 Real Keq=Vf/Vr*pyPk/pyRk;
 QKeq=Q/Keq;
	}

  //::stdcout << "QKeq"<< QKeq<< "\n";
Real reactants=0;
for(int i=0;i<RN;i++){
  reactants+=RK[i]/R[i];
  //::stdcout << "RK["<< i<< "]="<< RK[i]<< "\n"<< "R["<< i<< "]="<< R[i]<< "\n"<< "react"<< RK[i]/R[i]<< "\n";
 }

Real products=0;
for(int i=0;i<PN;i++){
  if(PK[i]>0){products+=P[i]/PK[i];}
	  }
//::stdcout << "reactant="<< reactants<< "\n";
//::stdcout << "product="<< products << "\n";
Real Y=(1-QKeq)/(1+reactants*(1+products));
Real size(E->getSuperSystem()->getSize());
//Real velocity=1;
//::stdcout << "E1="<< E1<< "\n";
//std::cout << "Y="<< Y<< "\n";
 ////::stdcout << "size="<< size<< "\n";
//velocity *=Y;
 //::stdcout << "velocity="<<velocity<< "\n";
//velocity *=E1;
 //::stdcout << "velocity="<<velocity<<"\n";
//velocity *=N_A;
//::stdcout << "velocity=" << velocity<< "\n";
//velocity /=60;
//::stdcout << "velocity="<< velocity<< "\n";
//velocity *=size;
//::stdcout << "velocity="<< velocity << "\n";
//::stdcout << "end"<< "\n";
  Real velocity = E->getValue();
  //cout << "conc=" << v2 << "\n";
  if(Y >= 0)
    {
      velocity *= Y * Vf/60;
      //v2*=Y*_KcF;
     }
  else if(Y < 0)
    {
      velocity *= Y * Vr/60;
     }
  //std::cout << "velocity="<< velocity<< "\n";
     //cout << "OAT velocity = " << velocity << "\n";
setFlux(velocity);
      }

 protected:
    //Real velocity1;
    Real RK0;
    Real RK1;
    Real RK2;
    Real RK3;
    Real PK0;
    Real PK1;
    Real PK2;
    Real PK3;
    Real Vr;
    Real Vf;
    Integer PN;
    Integer RN;
    Variable* E;
    Variable* R;
    Variable* R0;
    Variable* R1;
    Variable* R2;
    Variable* R3;
    Variable* P0;
    Variable* P1;
    Variable* P2;
    Variable* P3;
  private:

};

LIBECS_DM_INIT( MetaNetProcess, Process );

