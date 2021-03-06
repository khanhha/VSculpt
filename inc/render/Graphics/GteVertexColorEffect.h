// David Eberly, Geometric Tools, Redmond WA 98052
// Copyright (c) 1998-2016
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// File Version: 2.1.0 (2016/01/25)

#pragma once

#include <Graphics/GteVisualEffect.h>
#include <GTEngineDEF.h>

namespace gte
{

class GTE_IMPEXP VertexColorEffect : public VisualEffect
{
public:
    // Construction.
    VertexColorEffect(ProgramFactory& factory);

    // Member access.
	inline void SetPVWMatrix(EMatrix4x4  const& pvwMatrix);
    inline EMatrix4x4  const& GetPVWMatrix() const;

    // Required to bind and update resources.
    inline std::shared_ptr<ConstantBuffer> const& GetPVWMatrixConstant() const;

private:
    // Vertex shader parameters.
    std::shared_ptr<ConstantBuffer> mPVWMatrixConstant;

    // Convenience pointers.
	EMatrix4x4 * mPVWMatrix;

    // Shader source code as strings.
    static std::string const msGLSLVSSource;
    static std::string const msGLSLPSSource;
    static std::string const msHLSLSource;
    static std::string const* msVSSource[ProgramFactory::PF_NUM_API];
    static std::string const* msPSSource[ProgramFactory::PF_NUM_API];
};


inline void VertexColorEffect::SetPVWMatrix(EMatrix4x4  const& pvwMatrix)
{
    *mPVWMatrix = pvwMatrix;
}

inline EMatrix4x4  const& VertexColorEffect::GetPVWMatrix() const
{
    return *mPVWMatrix;
}

inline std::shared_ptr<ConstantBuffer> const&
VertexColorEffect::GetPVWMatrixConstant() const
{
    return mPVWMatrixConstant;
}


}
