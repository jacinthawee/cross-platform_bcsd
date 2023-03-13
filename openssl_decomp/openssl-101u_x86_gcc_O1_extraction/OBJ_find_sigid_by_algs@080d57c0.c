
int OBJ_find_sigid_by_algs(int *psignid,int dig_nid,int pkey_nid)

{
  int iVar1;
  int **ppiVar2;
  int in_GS_OFFSET;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20 = &local_1c;
  local_18 = dig_nid;
  local_14 = pkey_nid;
  if (sigx_app == (_STACK *)0x0) {
LAB_080d5848:
    ppiVar2 = (int **)OBJ_bsearch_(&local_20,sigoid_srt_xref,0x1b,4,sigx_cmp_BSEARCH_CMP_FN);
    if (ppiVar2 == (int **)0x0) {
      iVar1 = 0;
      goto LAB_080d582f;
    }
  }
  else {
    iVar1 = sk_find(sigx_app,local_20);
    if (iVar1 < 0) goto LAB_080d5848;
    local_20 = (int *)sk_value(sigx_app,iVar1);
    ppiVar2 = &local_20;
  }
  if (psignid == (int *)0x0) {
    iVar1 = 1;
  }
  else {
    *psignid = **ppiVar2;
    iVar1 = 1;
  }
LAB_080d582f:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

