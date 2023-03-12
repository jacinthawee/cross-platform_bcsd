
int ECDSA_verify(int type,uchar *dgst,int dgstlen,uchar *sig,int siglen,EC_KEY *eckey)

{
  undefined *puVar1;
  int iVar2;
  DH *pDVar3;
  int iVar4;
  DH *pDVar5;
  int local_30;
  DH *local_2c;
  DH *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_28 = (DH *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pDVar5 = (DH *)dgst;
  local_2c = (DH *)sig;
  local_30 = (*(code *)PTR_ECDSA_SIG_new_006a8778)();
  if (local_30 == 0) {
    iVar2 = -1;
    goto LAB_00515248;
  }
  pDVar5 = (DH *)&local_2c;
  iVar2 = (*(code *)PTR_d2i_ECDSA_SIG_006a877c)(&local_30,pDVar5,siglen);
  if (iVar2 == 0) {
    iVar2 = -1;
  }
  else {
    pDVar5 = (DH *)&local_28;
    pDVar3 = (DH *)(*(code *)PTR_i2d_ECDSA_SIG_006a8770)(local_30);
    if ((DH *)siglen == pDVar3) {
      pDVar5 = local_28;
      iVar4 = (*(code *)PTR_memcmp_006a9ad0)(sig,local_28,pDVar3);
      iVar2 = local_30;
      if (iVar4 != 0) goto LAB_0051520c;
      iVar4 = (*(code *)PTR_ecdsa_check_006a876c)(eckey);
      if (iVar4 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (**(code **)(*(int *)(iVar4 + 0xc) + 0xc))(dgst,dgstlen,iVar2,eckey);
        pDVar5 = (DH *)dgstlen;
      }
    }
    else {
LAB_0051520c:
      iVar2 = -1;
    }
    if (0 < (int)pDVar3) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_28);
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_28);
      pDVar5 = pDVar3;
    }
  }
  (*(code *)PTR_ECDSA_SIG_free_006a8774)(local_30);
LAB_00515248:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar2 != 0) {
    if (iVar2 != 2) {
      return 1;
    }
    DH_free((DH *)pDVar5->pad);
    pDVar5->pad = 0;
    return 2;
  }
  pDVar3 = DH_new();
  iVar2 = 2;
  if (pDVar3 == (DH *)0x0) {
    iVar2 = 0;
  }
  pDVar5->pad = (int)pDVar3;
  return iVar2;
}

