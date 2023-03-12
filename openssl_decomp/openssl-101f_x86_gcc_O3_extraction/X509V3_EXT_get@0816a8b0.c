
X509V3_EXT_METHOD * X509V3_EXT_get(X509_EXTENSION *ext)

{
  int iVar1;
  X509V3_EXT_METHOD *pXVar2;
  X509V3_EXT_METHOD **ppXVar3;
  int in_GS_OFFSET;
  int *local_4c;
  int local_48 [14];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = OBJ_obj2nid(ext->object);
  pXVar2 = (X509V3_EXT_METHOD *)0x0;
  if (iVar1 != 0) {
    local_4c = local_48;
    if (-1 < iVar1) {
      local_48[0] = iVar1;
      ppXVar3 = (X509V3_EXT_METHOD **)
                OBJ_bsearch_(&local_4c,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
      if (ppXVar3 != (X509V3_EXT_METHOD **)0x0) {
        pXVar2 = *ppXVar3;
        goto LAB_0816a909;
      }
      if (ext_list != (_STACK *)0x0) {
        iVar1 = sk_find(ext_list,local_48);
        if (iVar1 != -1) {
          pXVar2 = (X509V3_EXT_METHOD *)sk_value(ext_list,iVar1);
          goto LAB_0816a909;
        }
      }
    }
    pXVar2 = (X509V3_EXT_METHOD *)0x0;
  }
LAB_0816a909:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pXVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

