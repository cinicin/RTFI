#include "StdAfx.h"
#include "../../EterLib/Srcs/GrpExpandedImageInstance.h"
#include "../../EterLib/Srcs/GrpTextInstance.h"
#include "../../EterLib/Srcs/GrpMarkInstance.h"
#include "../../EterLib/Srcs/GrpSubImage.h"
#include "../../EterLib/Srcs/GrpText.h"
#include "../../EterLib/Srcs/AttributeData.h"
#include "../../EterGrnLib/Srcs/Thing.h"
#include "../../EterGrnLib/Srcs/ThingInstance.h"
#include "../../EffectLib/Srcs/EffectMesh.h"
#include "../../EffectLib/Srcs/EffectInstance.h"
#include "../../GameLib/Srcs/WeaponTrace.h"
#include "../../GameLib/Srcs/MapType.h"
#include "../../GameLib/Srcs/GameType.h"
#include "../../GameLib/Srcs/RaceData.h"
#include "../../GameLib/Srcs/RaceMotionData.h"
#include "../../GameLib/Srcs/ActorInstance.h"
#include "../../GameLib/Srcs/Area.h"
#include "../../GameLib/Srcs/ItemData.h"
#include "../../GameLib/Srcs/FlyingData.h"
#include "../../GameLib/Srcs/FlyTrace.h"
#include "../../GameLib/Srcs/FlyingInstance.h"
#include "../../GameLib/Srcs/FlyingData.h"

#include "Resource.h"

CResource * NewImage(const char* c_szFileName)
{
	return new CGraphicImage(c_szFileName);
}

CResource * NewSubImage(const char* c_szFileName)
{
	return new CGraphicSubImage(c_szFileName);
}

CResource * NewText(const char* c_szFileName)
{
	return new CGraphicText(c_szFileName);
}

CResource * NewThing(const char* c_szFileName)
{
	return new CGraphicThing(c_szFileName);
}

CResource * NewEffectMesh(const char* c_szFileName)
{
	return new CEffectMesh(c_szFileName);
}

CResource * NewAttributeData(const char* c_szFileName)
{
	return new CAttributeData(c_szFileName);
}

void CPythonResource::DumpFileList(const char * c_szFileName)
{
	m_resManager.DumpFileListToTextFile(c_szFileName);
}

void CPythonResource::Destroy()
{		
	CFlyingInstance::DestroySystem();
	CActorInstance::DestroySystem();
	CArea::DestroySystem();
	CGraphicExpandedImageInstance::DestroySystem();
	CGraphicImageInstance::DestroySystem();	
	CGraphicMarkInstance::DestroySystem();
	CGraphicThingInstance::DestroySystem();
	CGrannyModelInstance::DestroySystem();
	CGraphicTextInstance::DestroySystem();
	CEffectInstance::DestroySystem();
	CWeaponTrace::DestroySystem();	
	CFlyTrace::DestroySystem();
	
	m_resManager.DestroyDeletingList();

	CFlyingData::DestroySystem();
	CItemData::DestroySystem();
	CEffectData::DestroySystem();
	CEffectMesh::SEffectMeshData::DestroySystem();
	CRaceData::DestroySystem();
	NRaceData::DestroySystem();
	CRaceMotionData::DestroySystem();	

	m_resManager.Destroy();	
}

CPythonResource::CPythonResource()
{
	m_resManager.RegisterResourceNewFunctionPointer("sub", NewSubImage);
	m_resManager.RegisterResourceNewFunctionPointer("dds", NewImage);
	m_resManager.RegisterResourceNewFunctionPointer("jpg", NewImage);
	m_resManager.RegisterResourceNewFunctionPointer("tga", NewImage);
	m_resManager.RegisterResourceNewFunctionPointer("bmp", NewImage);
	m_resManager.RegisterResourceNewFunctionPointer("fnt", NewText);
	m_resManager.RegisterResourceNewFunctionPointer("gr2", NewThing);
	m_resManager.RegisterResourceNewFunctionPointer("mde", NewEffectMesh);
	m_resManager.RegisterResourceNewFunctionPointer("mdatr", NewAttributeData);
}

CPythonResource::~CPythonResource()
{	
}
