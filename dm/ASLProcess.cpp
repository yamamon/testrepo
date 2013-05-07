#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( ASLProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( ASLProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, k1 );
      PROPERTYSLOT_SET_GET( Real, k2 );
      PROPERTYSLOT_SET_GET( Real, k3 );
      PROPERTYSLOT_SET_GET( Real, k4 );
      PROPERTYSLOT_SET_GET( Real, k5 );
      PROPERTYSLOT_SET_GET( Real, k6 );
    }

  ASLProcess()
    :
    k1(0.0),
    k2 (0.0),
    k3(0.0),
    k4(0.0),
    k5(0.0),
    k6(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, k1 );
      SIMPLE_SET_GET_METHOD( Real, k2 );
      SIMPLE_SET_GET_METHOD( Real, k3);
      SIMPLE_SET_GET_METHOD( Real, k4 );
      SIMPLE_SET_GET_METHOD( Real, k5);
      SIMPLE_SET_GET_METHOD( Real, k6 );
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	AS1 = getVariableReference( "AS" ).getVariable(); ;  
	Fum2 = getVariableReference( "Fum" ).getVariable(); ; 
       	Arg3 = getVariableReference( "Arg" ).getVariable(); ; 
	ASL4 = getVariableReference( "ASL" ).getVariable(); ; 
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real AS( AS1->getMolarConc() );
 Real Fum( Fum2->getMolarConc() );
Real Arg( Arg3->getMolarConc() );
Real ASL( ASL4->getMolarConc() );
Real size(ASL4->getSuperSystem()->getSize());
Real velocity = ( (k1 * k3 * k5 * AS) - (k2 * k4 * k6 * Fum * Arg) ) * ASL; 

// -> M/s^3

Real DENOM = ( k5 * (k2 + k3) ) + ( AS * k1 * (k3 + k5) )
	    + ( Fum * k2 * k4 ) + ( Arg * k6 * (k2 + k3) )
	    + ( Fum * Arg * k4 * k6 ) + ( AS * Fum * k1 * k4 );
	      
// -> 1/s^2

velocity /= DENOM;

velocity*=size*N_A;
//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
Real    k1 ;
Real    k2; 
Real    k3;
Real    k4;
 Real k5;
 Real k6;
    Variable*	AS1;  
    Variable*	Fum2; 
    Variable*	Arg3;
    Variable*	ASL4;
  private:

};

LIBECS_DM_INIT( ASLProcess, Process );

