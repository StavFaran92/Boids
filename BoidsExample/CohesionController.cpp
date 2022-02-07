#include "CohesionController.h"

#include "TGUI/Widgets/Slider.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/Group.hpp"

CohesionController::CohesionController(const std::string& name, std::shared_ptr<Rule> rule, tgui::Group::Ptr layout)
	: BasicController(name, rule, layout)
{}
