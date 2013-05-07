#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( AaseProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( AaseProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, k1 );
      PROPERTYSLOT_SET_GET( Real, k2 );
      PROPERTYSLOT_SET_GET( Real, k3 );
      PROPERTYSLOT_SET_GET( Real, k4 );
      PROPERTYSLOT_SET_GET( Real, k5 );
    }

  AaseProcess()
    :
    k1(0.0),
    k2(0.0),
    k3(0.0),
    k4(0.0),
    k5(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, k1 );
      SIMPLE_SET_GET_METHOD( Real, k2 );
      SIMPLE_SET_GET_METHOD( Real, k3 );
      SIMPLE_SET_GET_METHOD( Real, k4 );
      SIMPLE_SET_GET_METHOD( Real, k5 );

   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	Arg1 = getVariableReference( "Arg" ).getVariable();  
	Orn2 = getVariableReference( "Orn" ).getVariable(); 
	Aase3 = getVariableReference( "Aase" ).getVariable(); 
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real Arg( Arg1->getMolarConc() );
Real Orn( Orn2->getMolarConc() );
Real Aase( Aase3->getMolarConc() );
Real size(Aase3->getSuperSystem()->getSize());
Real velocity = k1 * k3 * k4 * Arg * Aase; 

// -> M/s^3

Real DENOM = ( k4 * (k2 + k3) ) 
	    + ( k5 * (k2 + k3) * Orn )
	    + ( k1 * (k3 * k4) * Arg );
	      
// -> 1/s^2

velocity /= DENOM;

// -> M/sec

//cout << "aase velocity = " << velocity << "\n";

velocity*=size*N_A;
//std::cout <<"velocity="<<velocity<<"\n";
setFlux(velocity);

      }

 protected:
    Real k1;
    Real k2;
    Real k3;
    Real k4;
    Real k5;
    Variable*	Arg1;  
    Variable*	Orn2; 
    Variable*	Aase3; 
  private:

};

LIBECS_DM_INIT( AaseProcess, Process );

