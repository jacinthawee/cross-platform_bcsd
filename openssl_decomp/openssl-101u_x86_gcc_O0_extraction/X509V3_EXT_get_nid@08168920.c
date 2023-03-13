
X509V3_EXT_METHOD * X509V3_EXT_get_nid(int nid)

{
  X509V3_EXT_METHOD **ppXVar1;
  int iVar2;
  X509V3_EXT_METHOD *pXVar3;
  int in_GS_OFFSET;
  int *local_4c;
  int local_48 [14];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_4c = local_48;
  if (-1 < nid) {
    local_48[0] = nid;
    ppXVar1 = (X509V3_EXT_METHOD **)
              OBJ_bsearch_(&local_4c,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
    if (ppXVar1 != (X509V3_EXT_METHOD **)0x0) {
      pXVar3 = *ppXVar1;
      goto LAB_08168968;
    }
    if (ext_list != (_STACK *)0x0) {
      iVar2 = sk_find(ext_list,local_48);
      if (iVar2 != -1) {
        pXVar3 = (X509V3_EXT_METHOD *)sk_value(ext_list,iVar2);
        goto LAB_08168968;
      }
    }
  }
  pXVar3 = (X509V3_EXT_METHOD *)0x0;
LAB_08168968:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pXVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

