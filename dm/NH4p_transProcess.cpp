#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( NH4p_transProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( NH4p_transProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	k  );
    }

  NH4p_transProcess()
    :
    k(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, k );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	S1 = getVariableReference( "S" ).getVariable();  
	P2 = getVariableReference( "P" ).getVariable(); 
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real S( S1->getMolarConc() );
 Real P( P2->getMolarConc() );
 //Real size(getSuperSystem()->getSize());

Real velocity = k * (S - P);

if(velocity>=0.0){
  velocity *= S1->getSuperSystem()->getSize();
// cout << velocity << "\n";

}
else{
  velocity *= P2->getSuperSystem()->getSize();
// cout << "aho\n";

}
 velocity*=N_A;
//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real	k ;
    Variable*	S1;  
    Variable*	P2; 
  private:

};

LIBECS_DM_INIT( NH4p_transProcess, Process );

