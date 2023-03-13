
void * X509V3_EXT_d2i(X509_EXTENSION *ext)

{
  ASN1_OCTET_STRING *pAVar1;
  uchar *puVar2;
  void **ppvVar3;
  ASN1_VALUE *pAVar4;
  int iVar5;
  void *pvVar6;
  int in_GS_OFFSET;
  uchar **local_4c;
  uchar *local_48 [14];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  puVar2 = (uchar *)OBJ_obj2nid(ext->object);
  if (puVar2 != (uchar *)0x0) {
    local_4c = local_48;
    if (-1 < (int)puVar2) {
      local_48[0] = puVar2;
      ppvVar3 = (void **)OBJ_bsearch_(&local_4c,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
      if (ppvVar3 == (void **)0x0) {
        if (ext_list != (_STACK *)0x0) {
          iVar5 = sk_find(ext_list,local_48);
          if (iVar5 != -1) {
            pvVar6 = sk_value(ext_list,iVar5);
            goto LAB_08168d96;
          }
        }
      }
      else {
        pvVar6 = *ppvVar3;
LAB_08168d96:
        if (pvVar6 != (void *)0x0) {
          pAVar1 = ext->value;
          local_48[0] = pAVar1->data;
          if (*(ASN1_ITEM **)((int)pvVar6 + 8) == (ASN1_ITEM *)0x0) {
            pAVar4 = (ASN1_VALUE *)(**(code **)((int)pvVar6 + 0x14))(0,local_48,pAVar1->length);
          }
          else {
            pAVar4 = ASN1_item_d2i((ASN1_VALUE **)0x0,local_48,pAVar1->length,
                                   *(ASN1_ITEM **)((int)pvVar6 + 8));
          }
          goto LAB_08168db9;
        }
      }
    }
  }
  pAVar4 = (ASN1_VALUE *)0x0;
LAB_08168db9:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

