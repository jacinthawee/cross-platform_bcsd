
void * X509V3_EXT_d2i(X509_EXTENSION *ext)

{
  void **ppvVar1;
  void *pvVar2;
  ASN1_VALUE *pAVar3;
  int iVar4;
  ASN1_OCTET_STRING *pAVar5;
  uchar **local_4c;
  uchar *local_48 [14];
  
  local_48[0] = (uchar *)OBJ_obj2nid(ext->object);
  if ((local_48[0] != (uchar *)0x0) && (-1 < (int)local_48[0])) {
    local_4c = local_48;
    ppvVar1 = (void **)OBJ_bsearch_(&local_4c,&standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN + 1);
    if (ppvVar1 == (void **)0x0) {
      if (ext_list == (_STACK *)0x0) {
        return (void *)0x0;
      }
      iVar4 = sk_find(ext_list,local_48);
      if (iVar4 == -1) {
        return (void *)0x0;
      }
      pvVar2 = sk_value(ext_list,iVar4);
    }
    else {
      pvVar2 = *ppvVar1;
    }
    if (pvVar2 != (void *)0x0) {
      pAVar5 = ext->value;
      local_48[0] = pAVar5->data;
      if (*(ASN1_ITEM **)((int)pvVar2 + 8) == (ASN1_ITEM *)0x0) {
        pvVar2 = (void *)(**(code **)((int)pvVar2 + 0x14))(0,local_48,pAVar5->length);
        return pvVar2;
      }
      pAVar3 = ASN1_item_d2i((ASN1_VALUE **)0x0,local_48,pAVar5->length,
                             *(ASN1_ITEM **)((int)pvVar2 + 8));
      return pAVar3;
    }
  }
  return (void *)0x0;
}

