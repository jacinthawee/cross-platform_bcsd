
undefined4 internal_verify(int param_1)

{
  int iVar1;
  X509 *x;
  int iVar2;
  X509 *pXVar3;
  EVP_PKEY *r;
  undefined4 uVar4;
  uint uVar5;
  X509 *a;
  int iVar6;
  time_t *t;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar7;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x20);
  iVar1 = sk_num(*(_STACK **)(param_1 + 0x54));
  iVar6 = iVar1 + -1;
  *(int *)(param_1 + 0x60) = iVar6;
  x = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar6);
  iVar2 = (**(code **)(param_1 + 0x28))(param_1,x,x);
  pXVar3 = x;
  if (iVar2 == 0) {
    if (iVar6 < 1) {
      *(X509 **)(param_1 + 0x68) = x;
      *(undefined4 *)(param_1 + 100) = 0x15;
                    /* WARNING: Could not recover jumptable at 0x000c805e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*UNRECOVERED_JUMPTABLE)(0,param_1);
      return uVar4;
    }
    iVar6 = iVar1 + -2;
    *(int *)(param_1 + 0x60) = iVar6;
    pXVar3 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar6);
  }
  if (iVar6 < 0) {
    return 1;
  }
  do {
    a = pXVar3;
    iVar1 = a->valid;
    *(int *)(param_1 + 0x60) = iVar6;
    if (iVar1 == 0) {
      if (a != x) {
        r = X509_get_pubkey(x);
joined_r0x000c7fee:
        if (r == (EVP_PKEY *)0x0) {
          *(undefined4 *)(param_1 + 100) = 6;
          *(X509 **)(param_1 + 0x68) = x;
          iVar1 = (*UNRECOVERED_JUMPTABLE)(0,param_1);
          if (iVar1 == 0) {
            return 0;
          }
        }
        else {
          iVar1 = X509_verify(a,r);
          if (iVar1 < 1) {
            *(undefined4 *)(param_1 + 100) = 7;
            *(X509 **)(param_1 + 0x68) = a;
            iVar1 = (*UNRECOVERED_JUMPTABLE)(0,param_1);
            if (iVar1 == 0) {
              EVP_PKEY_free(r);
              return 0;
            }
          }
        }
        EVP_PKEY_free(r);
        goto LAB_000c7fa0;
      }
      iVar1 = *(int *)(param_1 + 0x14);
      uVar5 = *(uint *)(iVar1 + 0xc);
      if ((int)(uVar5 << 0x11) < 0) {
        r = X509_get_pubkey(x);
        goto joined_r0x000c7fee;
      }
    }
    else {
LAB_000c7fa0:
      iVar1 = *(int *)(param_1 + 0x14);
      uVar5 = *(uint *)(iVar1 + 0xc);
    }
    t = (time_t *)(uVar5 & 2);
    a->valid = 1;
    if (t != (time_t *)0x0) {
      t = (time_t *)(iVar1 + 4);
    }
    iVar1 = X509_cmp_time(a->cert_info->validity->notBefore,t);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 100) = 0xd;
      *(X509 **)(param_1 + 0x68) = a;
      iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
joined_r0x000c7f44:
      if (iVar1 == 0) {
        return 0;
      }
    }
    else if (0 < iVar1) {
      *(undefined4 *)(param_1 + 100) = 9;
      *(X509 **)(param_1 + 0x68) = a;
      iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
      goto joined_r0x000c7f44;
    }
    iVar1 = X509_cmp_time(a->cert_info->validity->notAfter,t);
    if (iVar1 == 0) {
      *(X509 **)(param_1 + 0x68) = a;
      *(undefined4 *)(param_1 + 100) = 0xe;
      iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
joined_r0x000c800e:
      if (iVar1 == 0) {
        return 0;
      }
    }
    else if (iVar1 < 0) {
      *(X509 **)(param_1 + 0x68) = a;
      *(undefined4 *)(param_1 + 100) = 10;
      iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
      goto joined_r0x000c800e;
    }
    *(X509 **)(param_1 + 0x6c) = x;
    *(X509 **)(param_1 + 0x68) = a;
    iVar1 = (*UNRECOVERED_JUMPTABLE)(1,param_1);
    if (iVar1 == 0) {
      return 0;
    }
    bVar7 = iVar6 == 0;
    iVar6 = iVar6 + -1;
    if (bVar7) {
      return 1;
    }
    pXVar3 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar6);
    x = a;
  } while( true );
}

