#include "GitController.h"

GitController::GitController(Configuration* configuration)
{
    this->configuration = configuration;
}

GitController::~GitController()
{
}

void GitController::UpdateRepository(std::string message)
{
    system(("cd " +
        configuration->GetRepositoryPath() + " && "
        "git add . && "
        "git commit -m \"" + message + "\"").c_str());
}