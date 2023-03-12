
undefined4 internal_verify(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  X509 *x;
  int iVar4;
  X509 *pXVar5;
  EVP_PKEY *r;
  uint uVar6;
  undefined4 uVar7;
  X509 *a;
  time_t *t;
  int iVar8;
  code *UNRECOVERED_JUMPTABLE;
  code *pcVar9;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x20);
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1 + 0x54));
  puVar2 = PTR_sk_value_006a7f24;
  iVar8 = iVar3 + -1;
  *(int *)(param_1 + 0x60) = iVar8;
  x = (X509 *)(*(code *)puVar2)(*(undefined4 *)(param_1 + 0x54),iVar8);
  iVar4 = (**(code **)(param_1 + 0x28))(param_1,x,x);
  puVar2 = PTR_sk_value_006a7f24;
  pXVar5 = x;
  if (iVar4 == 0) {
    bVar1 = iVar8 < 1;
    iVar8 = iVar3 + -2;
    if (bVar1) {
      *(X509 **)(param_1 + 0x68) = x;
      *(undefined4 *)(param_1 + 100) = 0x15;
                    /* WARNING: Could not recover jumptable at 0x0057bddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar7 = (*UNRECOVERED_JUMPTABLE)(0,param_1);
      return uVar7;
    }
    *(int *)(param_1 + 0x60) = iVar8;
    pXVar5 = (X509 *)(*(code *)puVar2)(*(undefined4 *)(param_1 + 0x54),iVar8);
  }
  if (iVar8 < 0) {
    return 1;
  }
  do {
    a = pXVar5;
    iVar3 = a->valid;
    *(int *)(param_1 + 0x60) = iVar8;
    if (iVar3 == 0) {
      if (x != a) {
        r = X509_get_pubkey(x);
joined_r0x0057bcd0:
        if (r == (EVP_PKEY *)0x0) {
          *(X509 **)(param_1 + 0x68) = x;
          *(undefined4 *)(param_1 + 100) = 6;
          iVar3 = (*UNRECOVERED_JUMPTABLE)(0,param_1);
          if (iVar3 == 0) {
            return 0;
          }
        }
        else {
          iVar3 = X509_verify(a,r);
          if (iVar3 < 1) {
            *(X509 **)(param_1 + 0x68) = a;
            *(undefined4 *)(param_1 + 100) = 7;
            iVar3 = (*UNRECOVERED_JUMPTABLE)(0,param_1);
            if (iVar3 == 0) {
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(r);
              return 0;
            }
          }
        }
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(r);
        goto LAB_0057bb58;
      }
      iVar3 = *(int *)(param_1 + 0x14);
      uVar6 = *(uint *)(iVar3 + 0xc);
      if ((uVar6 & 0x4000) != 0) {
        r = X509_get_pubkey(x);
        goto joined_r0x0057bcd0;
      }
    }
    else {
LAB_0057bb58:
      iVar3 = *(int *)(param_1 + 0x14);
      uVar6 = *(uint *)(iVar3 + 0xc);
    }
    a->valid = 1;
    if ((uVar6 & 2) == 0) {
      t = (time_t *)0x0;
      iVar3 = X509_cmp_time(a->cert_info->validity->notBefore,(time_t *)0x0);
      if (iVar3 == 0) goto LAB_0057bc9c;
LAB_0057bb8c:
      if (0 < iVar3) {
        pcVar9 = *(code **)(param_1 + 0x20);
        *(undefined4 *)(param_1 + 100) = 9;
        goto LAB_0057bb9c;
      }
    }
    else {
      t = (time_t *)(iVar3 + 4);
      iVar3 = X509_cmp_time(a->cert_info->validity->notBefore,t);
      if (iVar3 != 0) goto LAB_0057bb8c;
LAB_0057bc9c:
      pcVar9 = *(code **)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 100) = 0xd;
LAB_0057bb9c:
      *(X509 **)(param_1 + 0x68) = a;
      iVar3 = (*pcVar9)(0,param_1);
      if (iVar3 == 0) {
        return 0;
      }
    }
    iVar3 = X509_cmp_time(a->cert_info->validity->notAfter,t);
    if (iVar3 == 0) {
      *(X509 **)(param_1 + 0x68) = a;
      *(undefined4 *)(param_1 + 100) = 0xe;
      iVar3 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar3 == 0) {
        return 0;
      }
    }
    else if (iVar3 < 0) {
      *(X509 **)(param_1 + 0x68) = a;
      *(undefined4 *)(param_1 + 100) = 10;
      iVar3 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar3 == 0) {
        return 0;
      }
    }
    *(X509 **)(param_1 + 0x6c) = x;
    *(X509 **)(param_1 + 0x68) = a;
    iVar3 = (*UNRECOVERED_JUMPTABLE)(1,param_1);
    if (iVar3 == 0) {
      return 0;
    }
    iVar8 = iVar8 + -1;
    if (iVar8 == -1) {
      return 1;
    }
    pXVar5 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(param_1 + 0x54),iVar8);
    x = a;
  } while( true );
}

