
#ifndef CAD_FACTORY_CREO_H
#define CAD_FACTORY_CREO_H

/**
This class provides factories for the
concrete Creo CAD system.
*/
#include "CadFactoryAbstract.h"
#include  <string>
#include <vector>
#include <ProSolid.h>

namespace isis {
namespace cad {
namespace creo {

class AssemblerCreo : public IAssembler {
private:
	ProSolid  assembly_model;

public:
	// provide the name of the concrete assembler
	std::string name() {
		return "Creo Assembler";
	}

	// std::vector<Joint> get_joints();

	/**
	For a particular component (specified by id) extract
	the set of joints which join that component to other
	components.
	*/
	std::vector< Joint::pair_t >  extract_joint_pair_vector
		(const std::string in_component_id,
		 std::vector<ConstraintPair> in_vector,
		 std::map<std::string, isis::CADComponentData> &	in_map);

	/**
	The void pointer is CAD system specific.
	It should be eliminated as the strategy is completed.
	*/
	void* get_assembly_component
		( const std::string in_working_directory,
		  const std::string &	in_id, 
		  std::map<std::string, isis::CADComponentData> &	in_map);

};


class  EnvironmentCreo : public IEnvironment {
	public:
		// provide the name of the concrete assembler
		std::string name() { return "EnvironmentCreo";}

		//std::string getCADExtensionsDir() throw (isis::application_exception);


		/***
		void setupCADEnvironment(	e_OpenMETAApplication	in_OpenMETAApplication,
									const std::string       &in_WorkingDirector,
									const std::string		&in_AuxiliaryCADDirectory,
									bool					in_GraphicsModeOn,      
									bool					in_CADExceptInputFromThisProgramAndCreoUI,
									std::string				&out_CADStartCommand,	
									std::string				&out_CADExtensionsDir,
									std::string				&out_TemplateFile_PathAndFileName ) throw (isis::application_exception);

		***/

		// This function does any setup that is necessary before invoking the CAD application
		//virtual void setupCADEnvirnoment ( const DataContainer &in_DataContainer) throw (isis::application_exception) = 0;


	void setupCADEnvironment(	
			const CreateAssemblyInputArguments &in_CreateAssemblyInputArguments,
			std::string		&out_CADStartCommand,	
			std::string		&out_CADExtensionsDir,
			std::string		&out_TemplateFile_PathAndFileName ) const throw (isis::application_exception);

	void setupCADEnvironment(	
			const MetaLinkInputArguments &in_MetaLinkInputArguments,
			std::string		&out_CADStartCommand,	
			std::string		&out_CADExtensionsDir,
			std::string		&out_TemplateFile_PathAndFileName ) const throw (isis::application_exception);


	void setupCADEnvironment(	
			const ExtractACMInputArguments &in_ExtractACMInputArguments,
			std::string		&out_CADStartCommand,	
			std::string		&out_CADExtensionsDir,
			std::string		&out_TemplateFile_PathAndFileName ) const throw (isis::application_exception);

};







class CadFactoryCreo : public CadFactoryAbstract
{
private:
	AssemblerCreo assembler;
	EnvironmentCreo environment;

public:
	// provide the name of the concrete factory
	std::string name() {
		return "Creo CAD Factory";
	}
	IAssembler& get_assembler() {
		return assembler;
	};

	IEnvironment& getEnvironment() {
		return environment;
	};

};

CadFactoryAbstract::ptr create();


} // creo
} // cad
} // isis

#endif // CAD_FACTORY_CREO_H