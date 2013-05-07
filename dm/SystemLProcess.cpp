#include "libecs.hpp"

#include "ContinuousProcess.hpp"
#include<vector>
#include <iostream>
USE_LIBECS;

LIBECS_DM_CLASS( SystemLProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( SystemLProcess, Process )
    {
      INHERIT_PROPERTIES( ContinuousProcess );
      PROPERTYSLOT_SET_GET( Real, 	Km_Gln  );
      PROPERTYSLOT_SET_GET( Real,Ki_Trp );
      PROPERTYSLOT_SET_GET( Real, Vmax  );
    }

  SystemLProcess()
    :
    Km_Gln(0.0),
    Ki_Trp (0.0),
    Vmax(0.0)
     {
       ; // do nothing
     }
      SIMPLE_SET_GET_METHOD( Real, Km_Gln );
      SIMPLE_SET_GET_METHOD( Real, Ki_Trp );
      SIMPLE_SET_GET_METHOD( Real, Vmax);
   //void setvs( RealCref value ) { vs = value; }
   //const Real getvs() const { return vs; }
   //void setKI( RealCref value ) { KI = value; }
   //const Real getKI() const { return KI; }

    virtual void initialize()
      {
	Process::initialize();
	Gln_o1 = getVariableReference( "Gln_o" ).getVariable();  
	Gln_i2 = getVariableReference( "Gln_i" ).getVariable(); 
       	Trp_o3 = getVariableReference( "Trp_o" ).getVariable(); 
	Trp_i4 = getVariableReference( "Trp_i" ).getVariable(); 
	//velocity=N_A/60;
      }

    virtual void fire()
    {
Real Gln_o( Gln_o1->getMolarConc() );
 Real Gln_i( Gln_i2->getMolarConc() );
Real Trp_o( Trp_o3->getMolarConc() );
Real Trp_i( Trp_i4->getMolarConc() );
//Real size(getSuperSystem()->getSize());

Real velocityf = (Vmax * Gln_o) / 
			(Gln_o + Km_Gln * (Trp_o/Ki_Trp + 1) );
velocityf *= Gln_o1->getSuperSystem()->getSize();

Real velocityr = (Vmax * Gln_i) / 
			(Gln_i + Km_Gln * (Trp_i/Ki_Trp + 1) );
 velocityr *=  Gln_i2->getSuperSystem()->getSize();

Real velocity = velocityf - velocityr;
//std::cout <<"velocity="<<velocity<<"\n";
 velocity*=N_A;
setFlux(velocity);

      }

 protected:
 Real	Km_Gln ;
 Real	Ki_Trp ;
 Real	Vmax;
 Variable*	Gln_o1;  
 Variable*	Gln_i2; 
 Variable*	Trp_o3;
 Variable*	Trp_i4;
 private:

};

LIBECS_DM_INIT( SystemLProcess, Process );

