
X509V3_EXT_METHOD * X509V3_EXT_get(X509_EXTENSION *ext)

{
  X509V3_EXT_METHOD **ppXVar1;
  int iVar2;
  X509V3_EXT_METHOD *pXVar3;
  X509V3_EXT_METHOD **local_4c;
  X509V3_EXT_METHOD *local_48 [15];
  
  local_48[0] = (X509V3_EXT_METHOD *)OBJ_obj2nid(ext->object);
  if (local_48[0] != (X509V3_EXT_METHOD *)0x0) {
    if (-1 < (int)local_48[0]) {
      local_4c = local_48;
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
    local_48[0] = (X509V3_EXT_METHOD *)0x0;
  }
  return local_48[0];
}

