
int EVP_PBE_find(int type,int pbe_nid,int *pcnid,int *pmnid,undefined1 **pkeygen)

{
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  int local_34;
  int local_30;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (pbe_nid == 0) goto LAB_0813228c;
  local_30 = pbe_nid;
  local_34 = type;
  if (pbe_algs == (_STACK *)0x0) {
LAB_081322a8:
    pvVar2 = OBJ_bsearch_(&local_34,builtin_pbe,0x15,0x14,pbe2_cmp_BSEARCH_CMP_FN);
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0;
      goto LAB_0813228c;
    }
  }
  else {
    iVar1 = sk_find(pbe_algs,&local_34);
    if (iVar1 == -1) goto LAB_081322a8;
    pvVar2 = sk_value(pbe_algs,iVar1);
    if (pvVar2 == (void *)0x0) goto LAB_081322a8;
  }
  if (pcnid != (int *)0x0) {
    *pcnid = *(int *)((int)pvVar2 + 8);
  }
  if (pmnid != (int *)0x0) {
    *pmnid = *(int *)((int)pvVar2 + 0xc);
  }
  if (pkeygen == (undefined1 **)0x0) {
    iVar1 = 1;
  }
  else {
    *pkeygen = *(undefined1 **)((int)pvVar2 + 0x10);
    iVar1 = 1;
  }
LAB_0813228c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

