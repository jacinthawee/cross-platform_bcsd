
int OBJ_find_sigid_algs(int signid,int *pdig_nid,int *ppkey_nid)

{
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  int local_1c [3];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1c[0] = signid;
  if (sig_app == (_STACK *)0x0) {
LAB_080d5770:
    pvVar2 = OBJ_bsearch_(local_1c,sigoid_srt,0x1e,0xc,sig_cmp_BSEARCH_CMP_FN);
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0;
      goto LAB_080d5790;
    }
  }
  else {
    iVar1 = sk_find(sig_app,local_1c);
    if (iVar1 < 0) goto LAB_080d5770;
    pvVar2 = sk_value(sig_app,iVar1);
    if (pvVar2 == (void *)0x0) goto LAB_080d5770;
  }
  if (pdig_nid != (int *)0x0) {
    *pdig_nid = *(int *)((int)pvVar2 + 4);
  }
  if (ppkey_nid == (int *)0x0) {
    iVar1 = 1;
  }
  else {
    *ppkey_nid = *(int *)((int)pvVar2 + 8);
    iVar1 = 1;
  }
LAB_080d5790:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

