/*
 * Copyright 2015 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef __TPM2_SETPRIMARYPOLICY_FP_H_
#define __TPM2_SETPRIMARYPOLICY_FP_H_

typedef struct {
        TPM_RH        authHandle;
        TPM2B_DIGEST  authPolicy;
        TPMI_ALG_HASH hashAlg;
} SetPrimaryPolicy_In;

TPM_RC TPM2_SetPrimaryPolicy(
        SetPrimaryPolicy_In    *in                 // IN: input parameter list
);

#endif // __TPM2_SETPRIMARYPOLICY_FP_H_
