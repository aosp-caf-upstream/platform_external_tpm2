// Copyright 2015 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// THIS CODE IS GENERATED - DO NOT MODIFY!

#include "MemoryLib_fp.h"
#include "NV_DefineSpace_fp.h"

TPM_RC NV_DefineSpace_In_Unmarshal(NV_DefineSpace_In* target,
                                   TPM_HANDLE request_handles[],
                                   BYTE** buffer,
                                   INT32* size) {
  TPM_RC result = TPM_RC_SUCCESS;
  // Get request handles from request_handles array.
  target->authHandle = request_handles[0];
  // Unmarshal request parameters.
  result = TPM2B_AUTH_Unmarshal(&target->auth, buffer, size);
  if (result != TPM_RC_SUCCESS) {
    return result;
  }
  result = TPM2B_NV_PUBLIC_Unmarshal(&target->publicInfo, buffer, size);
  if (result != TPM_RC_SUCCESS) {
    return result;
  }
  if ((result == TPM_RC_SUCCESS) && *size) {
    result = TPM_RC_SIZE;
  }
  return result;
}

TPM_RC Exec_NV_DefineSpace(TPMI_ST_COMMAND_TAG tag,
                           BYTE** request_parameter_buffer,
                           INT32* request_parameter_buffer_size,
                           TPM_HANDLE request_handles[],
                           UINT32* response_handle_buffer_size,
                           UINT32* response_parameter_buffer_size) {
  TPM_RC result = TPM_RC_SUCCESS;
  NV_DefineSpace_In in;
#ifdef TPM_CC_NV_DefineSpace
  BYTE* response_buffer;
  INT32 response_buffer_size;
#endif
  *response_handle_buffer_size = 0;
  *response_parameter_buffer_size = 0;
  // Unmarshal request parameters to input structure.
  result = NV_DefineSpace_In_Unmarshal(&in, request_handles,
                                       request_parameter_buffer,
                                       request_parameter_buffer_size);
  if (result != TPM_RC_SUCCESS) {
    return result;
  }
  // Execute command.
  result = TPM2_NV_DefineSpace(&in);
  if (result != TPM_RC_SUCCESS) {
    return result;
  }
#ifdef TPM_CC_NV_DefineSpace
  response_buffer = MemoryGetResponseBuffer(TPM_CC_NV_DefineSpace) + 10;
  response_buffer_size = MAX_RESPONSE_SIZE - 10;
  // Add parameter_size field, always equal to 0 here.
  if (tag == TPM_ST_SESSIONS) {
    UINT32_Marshal(response_parameter_buffer_size, &response_buffer,
                   &response_buffer_size);
  }
  return TPM_RC_SUCCESS;
#endif
  return TPM_RC_COMMAND_CODE;
}
