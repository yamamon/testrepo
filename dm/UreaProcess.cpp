#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( UreaProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( UreaProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	k  );
    }

  UreaProcess()
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
	S0 = getVariableReference( "S0" ).getVariable();  
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real S( S0->getMolarConc() );
 Real size(S0->getSuperSystem()->getSize());

Real velocity = k * S*size*N_A;

//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real	k ;
    Variable*	S0;  
  private:

};

LIBECS_DM_INIT( UreaProcess, Process );

