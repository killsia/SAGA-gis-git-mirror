/**********************************************************
 * Version $Id: TLB_Interface.cpp 1921 2014-01-09 10:24:11Z oconrad $
 *********************************************************/

///////////////////////////////////////////////////////////
//                                                       //
//                         SAGA                          //
//                                                       //
//      System for Automated Geoscientific Analyses      //
//                                                       //
//                     Tool Library                      //
//                    ta_morphometry                     //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//                   TLB_Interface.cpp                   //
//                                                       //
//                 Copyright (C) 2003 by                 //
//                      Olaf Conrad                      //
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
//    e-mail:     oconrad@saga-gis.org                   //
//                                                       //
//    contact:    Olaf Conrad                            //
//                Institute of Geography                 //
//                University of Goettingen               //
//                Goldschmidtstr. 5                      //
//                37077 Goettingen                       //
//                Germany                                //
//                                                       //
///////////////////////////////////////////////////////////

//---------------------------------------------------------


///////////////////////////////////////////////////////////
//														 //
//           The Tool Link Library Interface             //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include "MLB_Interface.h"


//---------------------------------------------------------
CSG_String Get_Info(int i)
{
	switch( i )
	{
	case TLB_INFO_Name:	default:
		return( _TL("Morphometry") );

	case TLB_INFO_Category:
		return( _TL("Terrain Analysis") );

	case TLB_INFO_Author:
		return( SG_T("Various Authors") );

	case TLB_INFO_Description:
		return( _TL("Tools for (grid based) digital terrain analysis.") );

	case TLB_INFO_Version:
		return( SG_T("1.0") );

	case TLB_INFO_Menu_Path:
		return( _TL("Terrain Analysis|Morphometry") );
	}
}


//---------------------------------------------------------
#include "Morphometry.h"
#include "Convergence.h"
#include "Convergence_Radius.h"
#include "SurfaceSpecificPoints.h"
#include "Curvature_Classification.h"
#include "Hypsometry.h"
#include "RealArea.h"
#include "ProtectionIndex.h"
#include "mrvbf.h"
#include "distance_gradient.h"
#include "mass_balance_index.h"
#include "air_flow_height.h"
#include "anisotropic_heating.h"
#include "land_surface_temperature.h"
#include "relative_heights.h"
#include "wind_effect.h"
#include "ruggedness.h"
#include "tpi.h"
#include "tc_iwahashi_pike.h"
#include "param_scale.h"
#include "top_hat.h"
#include "fuzzy_landform_elements.h"
#include "Curvature_UpDownSlope.h"


//---------------------------------------------------------
CSG_Tool *		Create_Tool(int i)
{
	switch( i )
	{
	case  0:	return( new CMorphometry );
	case  1:	return( new CConvergence );
	case  2:	return( new CConvergence_Radius );
	case  3:	return( new CSurfaceSpecificPoints );
	case  4:	return( new CCurvature_Classification );
	case  5:	return( new CHypsometry );
	case  6:	return( new CRealArea );
	case  7:	return( new CProtectionIndex );
	case  8:	return( new CMRVBF );
	case  9:	return( new CDistance_Gradient );
	case 10:	return( new CMass_Balance_Index );
	case 11:	return( new CAir_Flow_Height );
	case 12:	return( new CAnisotropic_Heating );
	case 13:	return( new CLand_Surface_Temperature );
	case 14:	return( new CRelative_Heights );
	case 15:	return( new CWind_Effect );
	case 16:	return( new CRuggedness_TRI );
	case 17:	return( new CRuggedness_VRM );
	case 18:	return( new CTPI );
	case 19:	return( new CTPI_Classification );
	case 20:	return( new CTC_Texture );
	case 21:	return( new CTC_Convexity );
	case 22:	return( new CTC_Classification );
	case 23:	return( new CParam_Scale );
	case 24:	return( new CTop_Hat );
	case 25:	return( new CFuzzy_Landform_Elements );
	case 26:	return( new CCurvature_UpDownSlope );
	case 27:	return( new CWind_Exposition );
	case 28:	return( new CTPI_MultiScale );

	case 30:	return( NULL );
	default:	return( TLB_INTERFACE_SKIP_TOOL );
	}

	return( NULL );
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
//{{AFX_SAGA

	TLB_INTERFACE

//}}AFX_SAGA
