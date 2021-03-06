#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::DepthStencilState
    @ingroup Gfx
    @brief holds the complete depth and stencil render state
*/
#include "Gfx/Core/Enums.h"
#include "Gfx/Core/StencilState.h"

namespace Oryol {
    
class DepthStencilState {
public:
    /// front-side state
    StencilState StencilFront;
    /// back-side state
    StencilState StencilBack;
    /// depth state
    union {
        struct {
            /// depth compare-function
            CompareFunc::Code DepthCmpFunc:5;
            /// depth write enabled flag
            bool DepthWriteEnabled:1;
        };
        uint8 DepthStateHash;
    };

    /// constructor
    DepthStencilState() {
        this->DepthStateHash = 0;
        this->DepthCmpFunc = CompareFunc::Always;
        this->DepthWriteEnabled = false;
    };

    /// equality
    bool operator==(const DepthStencilState& rhs) const {
        return (this->DepthStateHash == rhs.DepthStateHash) &&
               (this->StencilFront == rhs.StencilFront) &&
               (this->StencilBack == rhs.StencilBack);
    };
    /// inequality
    bool operator!=(const DepthStencilState& rhs) const {
        return (this->DepthStateHash != rhs.DepthStateHash) ||
               (this->StencilFront != rhs.StencilFront) ||
               (this->StencilBack != rhs.StencilBack);
    }
};

} // namespace Oryol
