#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( decayProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( decayProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	k  );
    }

  decayProcess()
    :
	k (0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, 	k  );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	S0_1= getVariableReference( "S0" ).getVariable();  
      }

    virtual void fire()
    {
Real S0( S0_1->getMolarConc() );
 Real size(S0_1->getSuperSystem()->getSize());
Real velocity=k * S0* N_A * size;
//cout << "cps velocity = " << velocity << "\n"; 

//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real	k ;			       					
    Variable*	S0_1; 
  private:

};

LIBECS_DM_INIT( decayProcess, Process );

