
X509V3_EXT_METHOD * X509V3_EXT_get_nid(int nid)

{
  X509V3_EXT_METHOD **ppXVar1;
  int iVar2;
  X509V3_EXT_METHOD *pXVar3;
  int *local_4c;
  int local_48 [15];
  
  if (-1 < nid) {
    local_4c = local_48;
    local_48[0] = nid;
    ppXVar1 = (X509V3_EXT_METHOD **)
              OBJ_bsearch_(&local_4c,&standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN + 1);
    if (ppXVar1 != (X509V3_EXT_METHOD **)0x0) {
      return *ppXVar1;
    }
    if ((ext_list != (_STACK *)0x0) && (iVar2 = sk_find(ext_list,local_48), iVar2 != -1)) {
      pXVar3 = (X509V3_EXT_METHOD *)sk_value(ext_list,iVar2);
      return pXVar3;
    }
  }
  return (X509V3_EXT_METHOD *)0x0;
}

