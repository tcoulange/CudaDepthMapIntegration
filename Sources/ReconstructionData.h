// Copyright(c) 2016, Kitware SAS
// www.kitware.fr
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met :
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation and
// / or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef _RECONSTRUCTIONDATA_H_
#define _RECONSTRUCTIONDATA_H_

// VTK includes
#include "vtkImageData.h"
#include "vtkMatrix3x3.h"
#include "vtkMatrix4x4.h"

class ReconstructionData
{
public:
  ReconstructionData();
  ReconstructionData(std::string depthPath, std::string matrixPath);
  ~ReconstructionData();

  vtkImageData* GetDepthMap();
  vtkMatrix3x3* Get3MatrixK();
  vtkMatrix4x4* Get4MatrixK();
  vtkMatrix4x4* GetMatrixTR();

  void SetDepthMap(vtkImageData* data);
  void SetMatrixK(vtkMatrix3x3* matrix);
  void SetMatrixTR(vtkMatrix4x4* matrix);

  void ApplyDepthThresholdFilter(double thresholdBestCost);

protected:
  // Functions
  void ReadDepthMap(std::string path);

  // Attributes
  vtkImageData* depthMap;
  vtkMatrix3x3* matrixK;
  vtkMatrix4x4* matrix4K;
  vtkMatrix4x4* matrixTR;
};

#endif