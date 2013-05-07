Stepper ODEStepper( ODE ){}
@{k_blood=1.0}
@{Variable_cyto="""
  Variable Variable( SIZE ) 
	{
	  Value 1.176e-10; 
	} 
# Urea cycle enzymes Cyto
Variable Variable(ASS  ) {MolarConc 6.55090E-4;Fixed 0;} 
Variable Variable( ASL ) {MolarConc 3.03323E-6;Fixed 0;} 
Variable Variable(Aase) {MolarConc  6.772797962264151E-6; Fixed 0;} 
Variable Variable( GS ) { MolarConc  0.01E-3; }
# Transaminases and glutamate metabolism cyto
 Variable Variable( GOT_c ) {MolarConc  0.001E-3; Fixed 0;} 
# Creatine synthesis
 Variable Variable( GAT  ) {MolarConc 3.86578E-4;Fixed 0;} 
 Variable Variable(GAMT  ) {MolarConc 1.23114E-6; Fixed 0;} 

 Variable Variable( Arg ) {MolarConc 5.0E-5;Fixed 0;} 
 Variable Variable( ArgSucc ) {MolarConc 3.4E-5;Fixed 0;} 
 Variable Variable( Asp_c ) {MolarConc 1.2E-3;Fixed 0;} 
 Variable Variable(Cit_c  ){MolarConc 8.5E-5;Fixed 0;}
 Variable Variable(Gln_c) {MolarConc  2.96E-3; Fixed 0;} 
Variable Variable(Glu_c  ) {MolarConc 1.06E-2;Fixed 0;} 
 Variable Variable( GuaAc ) {MolarConc 1.4E-5;Fixed 0;} 
 Variable Variable( Orn_c ) {MolarConc 5.1E-4;Fixed 0;} 
 Variable Variable( Urea) {MolarConc  6.0E-3; } 
# Coenzymes
 Variable Variable( AMP_c ) {MolarConc 0.218E-3; Fixed 1;} 
 Variable Variable(MgATP_c) {MolarConc 4.54E-3;  Fixed 1;} 
# Inorganic chemicals
 Variable Variable( PI_c ) {MolarConc 7.4E-3; Fixed 1;} 
 Variable Variable(NH4p  ){MolarConc 0.089E-3; Fixed 0;} 



 

 Variable Variable(Gly) {MolarConc  6.0E-3; Fixed 1; }

# Carboxylic acids
Variable Variable(aKG_c  ) {MolarConc  2.0E-3; Fixed 1;} 
 Variable Variable( OAA_c ) {MolarConc  0.015E-3; Fixed 1;} 
 Variable Variable(Fum  ) {MolarConc  1E-3; Fixed 1;} 
# Production of sinks for nitrogen

Variable Variable( Cr ) {MolarConc  1E-3;Fixed 0; } 
Variable Variable( AdoMet ) {MolarConc 0.046E-3;  Fixed 1;} 


# SystemL, N (for glutamine transport)cyto
Variable Variable( Trp_c ) { MolarConc  0.20E-3; Fixed 1;} 
Variable Variable( Na_c ) {MolarConc  34.2E-3; Fixed 1;} 
Variable Variable( His_c ) {MolarConc  0.41E-3; Fixed 1;} 
 """
}

@{Variable_mito="""
  Variable Variable( SIZE ) 
	{
	  Value  2.94e-11;
	} 
## Carbamoyl phosphate synthesis
 Variable Variable( AGS ) {MolarConc  2E-5; Fixed 0;} 
## Urea cycle enzymes mito
Variable Variable( OCT ) {MolarConc 2.99568E-7;Fixed 0;} 
## Glutamine synthesis mito
 Variable Variable( Glnnase ) {MolarConc  0.1E-3; Fixed 0;} 
Variable Variable(CPS){MolarConc  0.00009070747167423004;} 
 Variable Variable( OAT  ){MolarConc 1.56090E-5;} 
 Variable Variable( GOT_m ) {MolarConc 2.16265E-6;Fixed 0;} 
 Variable Variable( GDH ) {MolarConc 5.48857E-7; Fixed 0;} 

## Mitochondrial membrane translocases mito
 Variable Variable( OTL ) {MolarConc 1.13036E-4;Fixed 0;} 
 Variable Variable( GTL ) {MolarConc  0.0001E-3; Fixed 0;} 
 Variable Variable( GATL ) {MolarConc 8.76519E-6; Fixed 0;} 


  # Coenzymes
Variable Variable(aKG_m) {MolarConc  3.1E-4;Fixed 0; } 
 Variable Variable(AcGlu  ) {MolarConc  6.8E-4;Fixed 0; } 
 Variable Variable(Cit_m  ) {MolarConc 1.5E-4;Fixed 0; } 
 Variable Variable(CP) {MolarConc 8.5E-5;Fixed 0;} 
 Variable Variable( Gln_m ) {MolarConc 2.0E-2 ;} 
 Variable Variable(Glu_m   ) {MolarConc  2.57E-3; } 
 Variable Variable(Orn_m  ) {MolarConc 4.2E-4;Fixed 0;} 
 Variable Variable(PI_m  ) {MolarConc 4.1E-3;Fixed 0; } 
 Variable Variable(NH4p) {MolarConc 8.9E-5; Fixed 0;} 

Variable Variable( CoA ) {MolarConc 0.38E-3;Fixed 0;} 
 Variable Variable( AcCoA ) {MolarConc 0.24E-3; Fixed 1;} 
Variable Variable(AMP_m) {MolarConc 2.6E-3; Fixed 1;} 
 Variable Variable(MgATP_m  ){MolarConc 1.8E-3; Fixed 1;} 
 Variable Variable(NAD) {MolarConc 1.58E-3; Fixed 1;} 
 Variable Variable(NADH) {MolarConc 0.36E-3; Fixed 1;} 
Variable Variable(  Mg2p) {MolarConc 0.83E-3; Fixed 1;} 
## Inorganic chemicals


 Variable Variable(HCO3m) {MolarConc 7.0E-3; Fixed 1;} 
# Amino acids and related compounds




 Variable Variable( Asp_m ) {MolarConc  0.40E-3; Fixed 0;} 


# Carboxylicacids
 
 Variable Variable(OAA_m) {MolarConc  0.07E-3; Fixed 1;} 
 Variable Variable( P5C ) {MolarConc  0.02E-3; Fixed 1;} 
Variable Variable(NAO) {MolarConc  1E-5;  Fixed 1;} 


"""
}

@{Variable_blood="""  
# Substances in Blood
 Variable Variable( Gln ) {MolarConc 5.0E-4;} 
 Variable Variable(Glu) {MolarConc 3.0E-4; } 
 Variable Variable(NH4p) {MolarConc 1.5E-4;} 
 Variable Variable(Urea) {MolarConc 6.0E-3;} 

## SystemL, N (for glutamine transport)
 Variable Variable(Trp  ) {MolarConc  0.25E-3;} 
Variable Variable( Na ) {MolarConc  143.5E-3; Fixed 1;} 
 Variable Variable(His  ){MolarConc  0.125E-3; } 
 Variable Variable( Insulin ) {Value 70820; } 
"""}

@{Variable_blood_fixed="""  
# Substances in Blood
 Variable Variable( Gln ) {MolarConc 0.5E-3; Fixed 1;} 
 Variable Variable(NH4p) {MolarConc 1.5E-4; Fixed 1;} 
 Variable Variable(Urea) {MolarConc 6.0E-3; Fixed 1;} 
 Variable Variable(Glu) {MolarConc 3.00E-4;  Fixed 1;} 
## SystemL, N (for glutamine transport)
 Variable Variable(Trp  ) {MolarConc  0.25E-3; Fixed 1;} 
Variable Variable( Na ) {MolarConc  143.5E-3; Fixed 1;} 
 Variable Variable(His  ){MolarConc  0.125E-3;  Fixed 1;} 
 Variable Variable( Insulin ) {Value 70820;  Fixed 1;} 
"""
}


@{size_blood="""
  Variable Variable( SIZE ) 
	{
	  Value 1.176e-10; 
	} 
"""}

@{Process_cyto="""
Process GSProcess( GS ) 
   {
   
 	VariableReferenceList
   		[Glu   :.:Glu_c -1 ]
		[ATPMg  :.:MgATP_c     -1 ]
		[ATP :/Performance:ATP 1]
		[NH4p   :.:NH4p     -1 ]
		[NH3 :/Performance:NH3 1]
		[Gln_c  :.:Gln_c     1 ]
		[PI_c   :.:PI_c     1 ]
		[AMP_c  :.:AMP_c     1 ]
   		[GS  :.:GS     0 ];
   	Km_Glu 3E-3;		       # M
	Km_NH4p 2E-4;		       # M
	Km_ATP 8E-4;		       # M
	kcat 4.587699044135982;
	#kcat 6.779244;
 } 
Process ASSProcess(ASS) 
   {
VariableReferenceList
   		[Ctrl   :.:Cit_c -1 ]
   		[ATP   :.:MgATP_c -1 ]
		[ATP2 :/Performance:ATP 1]
   		[Asp   :.:Asp_c -1 ]
   		[PP   :.:PI_c 1 ]
   		[AMP   :.:AMP_c 1 ]
   		[AS   :.:ArgSucc 1 ]
   		[ASS  :.:ASS     0 ];
   	k1 2.4E+5;
	k2 2.3;
	k3 3.5E+4;
	k4 1.0E+1;
	k5 4.8E+5;
	k6 1.0E+1;
	k7 2.0E+1;
	k8 8.9E+5;
	k9 5.0E+1;
	k10 6.4E+5;
	k11 5.0E+1;
	k12 1.7E+5;

 }
#reactor ASLReactor(/CELL/CYTOPLASM:ASL,"Arginosuccinate lyase")
Process ASLProcess( ASL ) 
   {

   
 	VariableReferenceList
   		[AS   :.:ArgSucc -1 ]
   		[Fum   :.:Fum  1 ]
   		[Arg   :.:Arg  1 ]
   		[ASL   :.:ASL 0 ];
   	k1 2.7E+6;
	k2 7E+1;
	k3 7.5E+1;
	k4 1.5E+6;
	k5 1.1E+3;
	k6 7E+5;		
#PARAMETER: k1, Float, 1/(M sec), Rate Constant
#PARAMETER: k2, Float, 1/sec, Rate Constant
#PARAMETER: k3, Float, 1/sec, Rate Constant
#PARAMETER: k4, Float, 1/(M sec), Rate Constant
#PARAMETER: k5, Float, 1/sec, Rate Constant
#PARAMETER: k6, Float, 1/(M sec), Rate Constant
 }
Process AaseProcess( Aase ) 
   {

   #reactor AaseReactor(/CELL/CYTOPLASM:Aase,"Arginase")
 	VariableReferenceList
   		[Arg   :.:Arg -1 ]
   		[Urea   :.:Urea 1 ]
		[_Urea_   :/Performance:Urea 1 ]
   		[Orn   :.:Orn_c 1 ]
   		[Aase   :.:Aase 0 ];
   	k1 1E+7;
	k2 5.4E+4;
	k3 5.3E+3;
	k4 3E+4;
	k5 1E+7;
 }
Process SystemLProcess( SystemL ) 
   {

   
 	VariableReferenceList
   		[Gln_o  :../../ENVIRONMENT:Gln -1 ]
		[Gln_i  :../CYTOPLASM:Gln_c 1 ]
		[Trp_o  :../../ENVIRONMENT:Trp 0 ]
		[Trp_i  :../CYTOPLASM:Trp_c 0 ];
	Km_Gln 4E-3;
	Ki_Trp 1.65E-3;
	Vmax 7.3391591648329236E-6;
 }

Process SystemNProcess(SystemN) 
   {

   
 	VariableReferenceList
   		[Gln_o  :../../ENVIRONMENT:Gln -1 ]
		[Na_o  :../../ENVIRONMENT:Na -1 ]
		[ Gln_i  :../CYTOPLASM:Gln_c 1 ]
   		[Na_i  :../CYTOPLASM:Na_c 1 ]
		[His_o   :../../ENVIRONMENT:His 0 ]
		[His_i   :../CYTOPLASM:His_c 0 ];
		Km_Gln 1.1E-3;
		Km_Na 17E-3;
		Ki_His 0.21E-3;
		Vmax 0.000022443329939865615;
		#.MolarConc
 }
	Process NH4p_transProcess( NH4p_trans ) 
	{
		Name  "Ammonia transport";

		VariableReferenceList
			[ S :../../ENVIRONMENT:NH4p -1 ]
			[ P :../MITOCHONDRIA:NH4p             1 ];

		k 0.11261261261261261;
	}
#REACTOR	GluTransReactor	/CELL/CYTOPLASM1:Glu-trans	Glutamate trasport	Substrate /ENVIRONMENT1:Glu 1	Product /CELL/CYTOPLASM1:Glu-c 1	Vmf 0.000236251916703273	VmR 5.69281726995838e-05	Km_Glu 0.53 ver6.2-n-3e-5-4.15-1.0-n3.zns.eri

#REACTOR	GluTransReactor	/CELL/CYTOPLASM1:Glu-trans	Glutamate trasport	Substrate /ENVIRONMENT1:Glu 1	Product /CELL/CYTOPLASM1:Glu-c 1	VmF 0.000614674301780196	VmR 0.000122934860356039	Km_Glu 0.53 ver5.0

#REACTOR	GluTransReactor	/CELL/CYTOPLASM:Glu-trans	Glutamate trasport	Substrate /ENVIRONMENT:Glu 1	Product /CELL/CYTOPLASM:Glu-c 1	VmF 0.0007528750839519955	VmR 0.0001505750167903991	Km_Glu 0.53E-3 ver single cell

#REACTOR	GluTransReactor	/CELL/CYTOPLASM1:Glu-trans	Glutamate trasport	Substrate /ENVIRONMENT1:Glu 1	Product /CELL/CYTOPLASM1:Glu-c 1	VmF 0.0106287431349491	VmR 0.00256114292408412	Km_Glu 0.53 ver4.15
Process Glu_transProcess( Glu_trans ) 
   {

   
 	VariableReferenceList
   		[Glu_o  :../../ENVIRONMENT:Glu -1 ]
		[Glu_i    :.:Glu_c 1 ];
		#VmF 0.000236251916703273;
		#VmR 5.69281726995838e-05;
#ch
VmF 0.000208102752159904;
VmR 4.62450560355343e-05;
		Km_Glu 0.53E-3;
 }

	Process UreaProcess( Urea ) 
	{
		Name  "Urea-Out from cytoplasm";

		VariableReferenceList
			[ S0 :.:Urea            -1 ]
			[ P0 :../../ENVIRONMENT:Urea  1 ];

		k 0.0011;
	}

    Process MetaNetProcess(GOT_c) 
  {	
  	VariableReferenceList
		[R0   :.:Asp_c -1]
  		[R1   :.:aKG_c -1 ]
  		[P0  :.:Glu_c 1 ]
  		[P1   :.:OAA_c 1 ]
  		[E   :.:GOT_c 0 ];
		#[   :../CYTOPLASM: 0 ]
		#[   :../MITOCHONDRIA: 0 ]
		RK0 3.12E-3; 
		RK1 0.31E-3; 
		RN 2;

		PK0 6.5E-3;
		PK1 0.048E-3;
		PN 2;
		Vf  16400;
		Vr  32180;

  }

    Process MetaNetProcess(GAMT) 
  {
	
  	VariableReferenceList
		[R0   :.:AdoMet -1]
  		[R1   :.:GuaAc -1 ]
  		[P0  :.:Cr 1 ]
  		[E   :.:GAMT 0 ];
		#[   :../CYTOPLASM: 0 ]
		#[   :../MITOCHONDRIA: 0 ]
		RK0 0.09E-3; 
		RK1 0.0014E-3; 
		RN 2;

		PK0 0E-3;
		PN 1;
		Vf  2120;
		Vr  0;

  }
    Process GATProcess(GAT) 
  {	
  	VariableReferenceList
		[R0   :.:Gly -1]
  		[R1   :.:Arg -1 ]
  		[P0  :.:Orn_c 1 ]
  		[P1   :.:GuaAc 1 ]
  		[E   :.:GAT 0 ]
		[I0   :.:Orn_c 0 ];
		#[   :../CYTOPLASM: 0 ]
		#[   :../MITOCHONDRIA: 0 ]
	KcF 2076;
        KcR 44.2;
        KS0 1.8;
        KS1 1.3;
	KP0 0.253;
        KP1 0.05;
	KE0 0.116;
	Mode0 2;
	Comp0 1;
	Object0 1;}
"""}


@{rapid='''
	Process RapidEQProcess( NH3rappidEQ ) 
	{
		Name  "Ammonia transport across mitochondrial membrane";


		VariableReferenceList
			[ Sc :../CYTOPLASM:NH4p -1 ]		
			[ Sm :../MITOCHONDRIA:NH4p             1 ];

			Keq 1.0;

	}

	Process RapidEQProcess( Arg_trans ) 
	{
		Name  "Arginine transport";


		VariableReferenceList
			[ Sc :../CYTOPLASM:Arg -1 ]
			[ Sm :.:Arg_m           1 ];

		Keq 1;
	}'''
}
@{Process_mito="""
Process AGSProcess( AGS ) 
   {	VariableReferenceList
   		[ Glu  :.:Glu_m -1]
   		[ acCoA :.:AcCoA  -1]
		[ CoA :.:CoA 1]
   		[ NAG :.:AcGlu     1]
   		[ Arg :../CYTOPLASM:Arg 0 ]
		#[ Arg :.:Arg_m      0]
   		[ AGS :.:AGS      0];
  	Km_acCoA 4.4E-3;			 #M
	Km_Glu 8.1E-3;			# M
	Ki_acCoA 4.7E-3;			# M 
	Ka_Arg 3.0E-5;			# M
	Ki_CoA 5.6E-3;			# M
	Ki_NAG 0.28E-3;			# M
	kcat 37.1666666666667;
 }

Process CPSProcess( CPS ) 
   {
   		Name "Carbamoyl phosphate synthetase";
 	
	VariableReferenceList
   		[ NH4p  :.:NH4p -1]
		[NH3 :/Performance:NH3 1]
   		[ HCO3 :.:HCO3m  -1]
		[ ATPMg :.:MgATP_m -2]
		[ATP :/Performance:ATP 2]
   		[ Mg2 :.:Mg2p     -1]
   		[ CP :.:CP 1]
   		[ AMP_m :.:AMP_m      2]
   		[PI_m  :.:PI_m      2]
   		[AG  :.:AcGlu      0]
   		[CPSI   :.:CPS      0];

	KmA1 0.05E-3;			# mM
	KmA2 1.0E-3;				# mM
	KmB  5.0E-3;			# mM
	KmN  2.0E-3;				# mM
	KmG  0.1E-3;			# mM
	KsA1 0.01E-3;			# mM
	KsA2 0.2E-3;			# mM
	KsB  0.8E-3;			# mM
	KsG  0.65E-6;			# uM
	KsM  0.17E-3;			# mM
	KmdA2 1.0E-3;			# mM
	KmdB  0.8E-3;			# mM
	KmdN  2.0E-3;			# mM
	kcat  25.8333333;			# min^-1	=>second^-1
	
}

Process GmsProcess( Gms ) 
   {
   
 	VariableReferenceList
		[Gln  :.:Gln_m     -1 ]
		[Glu  :.:Glu_m     1 ]
		[NH4p  :.:NH4p     1 ]
		[NH3 :/Performance:NH3 -1]
		[Pi  :.:PI_m     0 ]
   		[Gms  :.:Glnnase     0 ];
 	Kds 0.0005211518;
	nHs 1.8;			 # 
	KdA 1.248109E-5;
	nHa 2.6;			 #
	Kap 450E-6;			 # uM
	kcat 36.39776611601002;	 # sec^-1
 }

Process OCTProcess(OCT  ) 
   {

   
 	VariableReferenceList
   		[CP   :.:CP -1 ]
   		[Orn   :.:Orn_m -1 ]
   		[Ctrl   :.:Cit_m 1 ]
   		[Pi   :.:PI_m 1 ]
   		[OCT  :.:OCT      0 ];
   	
	k1 1.7E+7;
	k2 6.3E+1;
	k3 2.1E+6;
	k4 1E+3;
	k5 3E+3;
	k6 9E+4;
	k7 2.6E+3;
	k8 5E+5;	

 }

	Process MetaNetProcess( OAT ) 
	{
		Name "Ornithine aminotransferase";
		#reactor OATReactor(/CELL/MITOCHONDRIA:OAT,"Ornithine aminotransferase")

		VariableReferenceList
			[ R0 :.:Orn_m 0 ]
			[ R1 :.:aKG_m -1 ]
			[ P0 :.:P5C    1 ]
			[ P1 :.:Glu_m  1 ]
			[ E  :.:OAT    0 ];

		Vf 8450;
       		Vr 74;
		RK0 1.1E-3;   # mM
		RK1 1.1E-3;   # mM
		RN 2;
		PK0 0.1E-3;   # mM
		PK1 7.5E-3;   # mM
		PN 2;
	}


    Process ExpressionFluxProcess( Glntr ){

        VariableReferenceList
            [ Gc :../CYTOPLASM:Gln_c -1 ]
            [ Gm :.:Gln_m          1 ];

        Expression  "(( Keq * Gc.MolarConc - Gm.MolarConc )/( Keq + 1.0 )) * self.getSuperSystem().SizeN_A";

        Keq  6.75675675675675675675675676;
    }

    Process ExpressionFluxProcess( NH4ptr ){

        VariableReferenceList
            [ Nc :../CYTOPLASM:NH4p -1 ]
            [ Nm :.:NH4p          1 ];

        Expression  "(( Keq * Nc.MolarConc - Nm.MolarConc )/( Keq + 1.0 )) * self.getSuperSystem().SizeN_A";

        Keq 1.0;
    }




Process Glum_fluxProcess(Glum_flux) 
   {

   		VariableReferenceList
			[ Glum :.:Glu_m -1 ];

		Rate 6E-5;
#ch
		#k 0.08251861350482387;
k 0.0914253834283272;
	# ver6.2 Rate 3e-5	k 0.0797522316773544
	#ver7.1 Rate 3e-5 k 0.0708659043061413
#v6.2-gco-6e-5-4.5-1.0.zns.eri Rate 6e-5	k 0.0914253834283272
#Rate 8e-5	k 0.0992074845956424
#
}	
	# reactor NMassActionReactor(/CELL/MITOCHONDRIA:CoA-dec, "CoA decay")
	Process ExpressionFluxProcess( CoA_dec ) 
	{
		Name  "CoA decay";

		VariableReferenceList
			[ S0 :.:CoA -1 ];

		k 0.004750483106866752;

		Expression "k *  S0.MolarConc  * self.getSuperSystem().SizeN_A";
	}

	# reactor NMassActionReactor(/CELL/MITOCHONDRIA:NAG-dec, "NAG decay")
	Process decayProcess( NAG_dec ) 
	{
		Name  "NAG decay";

		VariableReferenceList
			[ S0 :.:AcGlu -1 ];

		k 0.0026546817361902436;

	
	}

		# reactor NMassActionReactor(/CELL/MITOCHONDRIA:PIm-dec, "Pi decay in MT")
	Process decayProcess( PIm_dec ) 
	{
		Name  "Pi decay in MT";

		VariableReferenceList
			[ S0 :.:PI_m -1 ];

		#k 0.044222635095070566;
	k 0.06097170731707317;		
	
	}


	#reactor KohnGeneralReactor(/CELL/MITOCHONDRIA:OTL,"Ornithine-citrulline translocase")
    Process MetaNetProcess(OTL) 
  {	
  	VariableReferenceList
		[R0  :../MITOCHONDRIA:Cit_m  -1]
  		[R1   :../CYTOPLASM:Orn_c -1 ]
  		[P0  :../MITOCHONDRIA:Orn_m 1 ]
  		[P1   :../CYTOPLASM:Cit_c 1 ]
  		[E   :.:OTL 0 ];
		RK0 3.6E-3; 
		RK1 0.16E-3; 
		RN 2;

		PK0 0.16E-3;
		PK1 3.6E-3;
		PN 2;
		Vf  7440;
		Vr  7440;

  }

#MetaGTL
#reactor KohnGeneralReactor(/CELL/MITOCHONDRIA:GTL,"Glutamate translocase")
    Process MetaNetProcess(GTL) 
  {	
  	VariableReferenceList
		[R0   :../CYTOPLASM:Glu_c -1]
  		[P0  :../MITOCHONDRIA:Glu_m 1 ]
  		[E   :.:GTL 0 ];
		RK0 4.0E-3; 
		RN 1;
		PK0 1.75E-3;
		PN 1;
		Vf  10200;
		Vr  10200;
  }



#reactor KohnGeneralReactor(/CELL/MITOCHONDRIA:GATL,"Glutamate-aspartate translocase for aspartate")
Process MetaNetProcess(GATL) 
  {
			
  	VariableReferenceList
		[R0   :../CYTOPLASM:Glu_c -1]
  		[R1   :../MITOCHONDRIA:Asp_m -1 ]
  		[P0  :../MITOCHONDRIA:Glu_m 1 ]
  		[P1   :../CYTOPLASM:Asp_c 1 ]
  		[E   :.:GATL 0 ];
		RK0 1.6E-3; 
		RK1 0.4E-3; 
		RN 2;

		PK0 1.6E-3;
		PK1 0.4E-3;
		PN 2;
		Vf  29000;
		Vr  29000;

  }












#reactor KohnGeneralReactor(/CELL/MITOCHONDRIA:GOT-m,"Glutamate-oxaloacetate transaminase")
Process MetaNetProcess(GOT_m) 
  {

  	VariableReferenceList
		[R0   :.:Glu_m -1]
  		[R1   :.:OAA_m -1 ]
  		[P0  :.:Asp_m 1 ]
  		[P1   :.:aKG_m 1 ]
  		[E   :.:GOT_m 0 ];
		#[   :../CYTOPLASM: 0 ]
		#[   :../MITOCHONDRIA: 0 ]
		RK0 7.5E-3; 
		RK1 0.0242E-3; 
		RN 2;

		PK0 1.12E-3;
		PK1 0.7E-3;
		PN 2;
		Vf  32180;
		Vr  16400;

  }

#reactor KohnGeneralReactor(/CELL/MITOCHONDRIA:GDH,"Glutamate dehydrogenase")
    Process MetaNetProcess(GDH) 
  {	
  	VariableReferenceList
		[R0   :.:Glu_m -1]
  		[R1   :.:NAD -1 ]
  		[P0  :.:aKG_m 1 ]
  		[P1   :.:NH4p 1 ]
		[NH3 :/Performance:NH3 -1]
		[P2   :.:NADH 1 ]
  		[E   :.:GDH 0 ];
		#[   :../CYTOPLASM: 0 ]
		#[   :../MITOCHONDRIA: 0 ]
		RK0 1.8E-3; 
		RK1 0.071E-3; 
		RN 2;

		PK0 0.7E-3;
		PK1 0.5E-3;
		PK2 0.03E-3;
		PN 3;
		Vf  64850;
		Vr  11240;

  }"""
}



#============================template kokomade===============================















System System( / ) 
{ 
	StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 

}
System System( /Performance ) 
{ 
	StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
 Variable Variable(ATP) {MolarConc 0.0;} 
Variable Variable(NH3) {MolarConc 0.0;} 
Variable Variable(Urea) {MolarConc 0.0;} 
}
@{zonenumber=0}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}

System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood_fixed
Process Flux1Process( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
 
 }
Process Flux1Process( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	

 }
Process Flux1Process( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	

 }

Process Flux1Process( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	

 }

} 


@{zonenumber=2}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}
@{zonenumber=1}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}

@{zonenumber=3}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}

@{zonenumber=4}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}
@{zonenumber=5}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}


@{zonenumber=6}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}
@{zonenumber=7}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}

@{zonenumber=8}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}
System System( /ZONE@zonenumber/CELL )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.176E-10; 
		Fixed 1;
		#it is fixd
	} 
}
System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood
Process ExpressionFluxProcess( NH4pbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:NH4p -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:NH4p 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glnbloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Gln -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Gln 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }
Process ExpressionFluxProcess( Glubloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Glu -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Glu 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

Process ExpressionFluxProcess( Ureabloodflux@(zonenumber)to@(zonenumber+1) ) 
   {

   
 	VariableReferenceList
   		[S :.:Urea -1 ]
		[P :/ZONE@(zonenumber+1)/ENVIRONMENT:Urea 1 ];
   	k @k_blood;	
   		Expression	''' k*S.MolarConc*self.getSuperSystem().SizeN_A''';
 }

} 


System System( /ZONE@zonenumber/CELL/CYTOPLASM)
{
   StepperID ODE; 

## Glutamine synthesis cyto


@Variable_cyto

@Process_cyto
}

System System( /ZONE@zonenumber/CELL/MITOCHONDRIA )
{
   StepperID ODE; 

@{
Arg='''
#substance /CELL/MITOCHONDRIA:Arg_m "Arginine" QTY(0.05E_3_/CELL/MITOCHONDRIA);
 Variable Variable( Arg_m ) 
	{
	  MolarConc 0.05E-3; 
	  #Fixed 1;
	  #it is not fixed
	} '''
} 


@Variable_mito
@Process_mito
}





@{zonenumber=9}
System System( /ZONE@zonenumber )
{
   StepperID ODE; 
Variable Variable( SIZE ) 
	{
		Value 1.0; 
	} 
}

System System( /ZONE@zonenumber/ENVIRONMENT )
{
	 StepperID ODE; 
@size_blood
@Variable_blood


} 
