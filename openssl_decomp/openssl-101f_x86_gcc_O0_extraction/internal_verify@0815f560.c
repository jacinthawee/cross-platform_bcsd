
undefined4 internal_verify(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  X509 *pXVar4;
  EVP_PKEY *r;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  X509 *a;
  time_t *t;
  X509 *local_24;
  
  pcVar1 = *(code **)(param_1 + 0x20);
  iVar2 = sk_num(*(_STACK **)(param_1 + 0x54));
  iVar7 = iVar2 + -1;
  *(int *)(param_1 + 0x60) = iVar7;
  local_24 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar7);
  iVar3 = (**(code **)(param_1 + 0x28))(param_1,local_24,local_24);
  pXVar4 = local_24;
  if (iVar3 == 0) {
    if (iVar7 < 1) {
      *(undefined4 *)(param_1 + 100) = 0x15;
      *(X509 **)(param_1 + 0x68) = local_24;
      uVar6 = (*pcVar1)(0,param_1);
      return uVar6;
    }
    iVar7 = iVar2 + -2;
    *(int *)(param_1 + 0x60) = iVar7;
    pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar7);
  }
  if (iVar7 < 0) {
    return 1;
  }
  do {
    a = pXVar4;
    iVar2 = a->valid;
    *(int *)(param_1 + 0x60) = iVar7;
    if (iVar2 == 0) {
      if (local_24 == a) {
        iVar2 = *(int *)(param_1 + 0x14);
        uVar5 = *(uint *)(iVar2 + 0xc);
        if ((uVar5 & 0x4000) == 0) goto LAB_0815f694;
      }
      r = X509_get_pubkey(local_24);
      if (r == (EVP_PKEY *)0x0) {
        *(undefined4 *)(param_1 + 100) = 6;
        *(X509 **)(param_1 + 0x68) = local_24;
        iVar2 = (*pcVar1)(0,param_1);
        if (iVar2 == 0) {
          return 0;
        }
      }
      else {
        iVar2 = X509_verify(a,r);
        if (iVar2 < 1) {
          *(undefined4 *)(param_1 + 100) = 7;
          *(X509 **)(param_1 + 0x68) = a;
          iVar2 = (*pcVar1)(0,param_1);
          if (iVar2 == 0) {
            EVP_PKEY_free(r);
            return 0;
          }
        }
      }
      EVP_PKEY_free(r);
      iVar2 = *(int *)(param_1 + 0x14);
      uVar5 = *(uint *)(iVar2 + 0xc);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x14);
      uVar5 = *(uint *)(iVar2 + 0xc);
    }
LAB_0815f694:
    t = (time_t *)(iVar2 + 4);
    if ((uVar5 & 2) == 0) {
      t = (time_t *)0x0;
    }
    a->valid = 1;
    iVar2 = X509_cmp_time(a->cert_info->validity->notBefore,t);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 100) = 0xd;
LAB_0815f6cd:
      *(X509 **)(param_1 + 0x68) = a;
      iVar2 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    else if (0 < iVar2) {
      *(undefined4 *)(param_1 + 100) = 9;
      goto LAB_0815f6cd;
    }
    iVar2 = X509_cmp_time(a->cert_info->validity->notAfter,t);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 100) = 0xe;
LAB_0815f72f:
      *(X509 **)(param_1 + 0x68) = a;
      iVar2 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    else if (iVar2 < 0) {
      *(undefined4 *)(param_1 + 100) = 10;
      goto LAB_0815f72f;
    }
    *(X509 **)(param_1 + 0x68) = a;
    *(X509 **)(param_1 + 0x6c) = local_24;
    iVar2 = (*pcVar1)(1,param_1);
    if (iVar2 == 0) {
      return 0;
    }
    iVar7 = iVar7 + -1;
    if (iVar7 == -1) {
      return 1;
    }
    pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar7);
    local_24 = a;
  } while( true );
}

