
int OBJ_find_sigid_by_algs(int *psignid,int dig_nid,int pkey_nid)

{
  int iVar1;
  int **ppiVar2;
  int *local_20;
  int iStack_1c;
  int local_18;
  int local_14;
  
  local_20 = &iStack_1c;
  local_18 = dig_nid;
  local_14 = pkey_nid;
  if ((sigx_app == (_STACK *)0x0) || (iVar1 = sk_find(sigx_app,local_20), iVar1 < 0)) {
    ppiVar2 = (int **)OBJ_bsearch_(&local_20,PTR_sigoid_srt_xref_0006d5cc,0x1b,4,
                                   sigx_cmp_BSEARCH_CMP_FN + 1);
    if (ppiVar2 == (int **)0x0) {
      return 0;
    }
  }
  else {
    local_20 = (int *)sk_value(sigx_app,iVar1);
    ppiVar2 = &local_20;
  }
  if (psignid == (int *)0x0) {
    return 1;
  }
  *psignid = **ppiVar2;
  return 1;
}

