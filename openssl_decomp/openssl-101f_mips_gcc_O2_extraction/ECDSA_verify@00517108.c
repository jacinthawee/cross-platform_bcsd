
int ECDSA_verify(int type,uchar *dgst,int dgstlen,uchar *sig,int siglen,EC_KEY *eckey)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  DH *pDVar4;
  DH **ppDVar5;
  DH *local_24;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppDVar5 = (DH **)dgst;
  local_24 = (DH *)sig;
  local_20 = (*(code *)PTR_ECDSA_SIG_new_006a989c)();
  if (local_20 == 0) {
    iVar3 = -1;
  }
  else {
    ppDVar5 = &local_24;
    iVar2 = (*(code *)PTR_d2i_ECDSA_SIG_006a98a0)(&local_20,ppDVar5,siglen);
    iVar3 = local_20;
    if (iVar2 == 0) {
      iVar3 = -1;
    }
    else {
      iVar2 = (*(code *)PTR_ecdsa_check_006a9890)(eckey);
      if (iVar2 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(*(int *)(iVar2 + 0xc) + 0xc))(dgst,dgstlen,iVar3,eckey);
        ppDVar5 = (DH **)dgstlen;
      }
    }
    (*(code *)PTR_ECDSA_SIG_free_006a9898)(local_20);
  }
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar3 == 0) {
    pDVar4 = DH_new();
    iVar3 = 2;
    if (pDVar4 == (DH *)0x0) {
      iVar3 = 0;
    }
    *ppDVar5 = pDVar4;
    return iVar3;
  }
  if (iVar3 != 2) {
    return 1;
  }
  DH_free(*ppDVar5);
  *ppDVar5 = (DH *)0x0;
  return 2;
}

