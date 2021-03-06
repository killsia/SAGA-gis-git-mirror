/**********************************************************
 * Version $Id: fast_representativeness.h 1921 2014-01-09 10:24:11Z oconrad $
 *********************************************************/

///////////////////////////////////////////////////////////
//                                                       //
//                         SAGA                          //
//                                                       //
//      System for Automated Geoscientific Analyses      //
//                                                       //
//                     Tool Library                      //
//                 imagery_segmentation                  //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//               fast_representativeness.h               //
//                                                       //
//                   Copyright (C) 2009                  //
//                     Andre Ringeler                    //
//                                                       //
//-------------------------------------------------------//
//                                                       //
// This file is part of 'SAGA - System for Automated     //
// Geoscientific Analyses'. SAGA is free software; you   //
// can redistribute it and/or modify it under the terms  //
// of the GNU General Public License as published by the //
// Free Software Foundation, either version 2 of the     //
// License, or (at your option) any later version.       //
//                                                       //
// SAGA is distributed in the hope that it will be       //
// useful, but WITHOUT ANY WARRANTY; without even the    //
// implied warranty of MERCHANTABILITY or FITNESS FOR A  //
// PARTICULAR PURPOSE. See the GNU General Public        //
// License for more details.                             //
//                                                       //
// You should have received a copy of the GNU General    //
// Public License along with this program; if not, see   //
// <http://www.gnu.org/licenses/>.                       //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//    e-mail:     aringel@saga-gis.org                   //
//                                                       //
//                                                       //
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#ifndef HEADER_INCLUDED__Fast_Representativeness_H
#define HEADER_INCLUDED__Fast_Representativeness_H

//---------------------------------------------------------
#include "MLB_Interface.h"


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
class CFast_Representativeness : public CSG_Tool_Grid
{
public:
	CFast_Representativeness(void);


protected:

	virtual bool		On_Execute(void);


private:

	void FastRep_Local_Sum(CSG_Grid *pInput, CSG_Grid **pOutput);
	void FastRep_Execute(void);
	void FastRep_Initialize(void);
	void FastRep_Init_Radius(void);
	void FastRep_Finalize(void);
	double FastRep_Get_Laenge(int x, int y);
	double FastRep_Get_Variance(int x, int y, int iRadius, int deep, int &Count);
	double FastRep_Get_Steigung();
	void smooth_rep(CSG_Grid * in, CSG_Grid * out);
	void Find_Local_Maxima_Minima(CSG_Grid * in, CSG_Grid * out);
	CSG_Grid				*pOrgInput, *Pow2Grid, *pOutput;
						
	int	*Z, *x_diff, *y_diff, *rLength;

	CSG_Grid		*Sum[16];
	CSG_Grid		*QSum[16];

	double	*V, *m, *g;
	int m_deep;
	int maxRadius;

};


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__Fast_Representativeness_H
