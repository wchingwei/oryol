#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::Render::drawState
    @brief bundles pre-compiled state for drawing operations
*/
#include "Resource/resourceBase.h"
#include "Render/Setup/DrawStateSetup.h"

namespace Oryol {
namespace Render {

class depthStencilState;
class mesh;
class programBundle;

class drawState : public Resource::resourceBase<DrawStateSetup> {
public:
    /// constructor
    drawState();
    /// destructor
    ~drawState();
    
    /// clear the object
    void clear();
    
    /// set depthStencilState pointer
    void setDepthStencilState(depthStencilState* dss);
    /// get depthStencilState pointer
    depthStencilState* getDepthStencilState() const;
    /// set mesh pointer
    void setMesh(mesh* msh);
    /// get mesh pointer
    mesh* getMesh() const;
    /// set program bundle pointer
    void setProgramBundle(programBundle* pb);
    /// get program bundle pointer
    programBundle* getProgramBundle() const;
    
private:
    depthStencilState* depthStencilState_;
    mesh* mesh_;
    programBundle* programBundle_;
};

//------------------------------------------------------------------------------
inline depthStencilState*
drawState::getDepthStencilState() const {
    return this->depthStencilState_;
}

//------------------------------------------------------------------------------
inline mesh*
drawState::getMesh() const {
    return this->mesh_;
}

//------------------------------------------------------------------------------
inline programBundle*
drawState::getProgramBundle() const {
    return this->programBundle_;
}

} // namespace Render
} // namespace Oryol