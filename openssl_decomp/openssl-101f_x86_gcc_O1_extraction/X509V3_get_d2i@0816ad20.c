
void * X509V3_get_d2i(stack_st_X509_EXTENSION *x,int nid,int *crit,int *idx)

{
  ASN1_OCTET_STRING *pAVar1;
  int iVar2;
  X509_EXTENSION *pXVar3;
  uchar *puVar4;
  void **ppvVar5;
  ASN1_VALUE *pAVar6;
  void *pvVar7;
  int iVar8;
  X509_EXTENSION *ex;
  int in_GS_OFFSET;
  bool bVar9;
  uchar **local_5c;
  uchar *local_58 [14];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    if (idx != (int *)0x0) goto LAB_0816aea0;
LAB_0816aea6:
    if (crit != (int *)0x0) {
      *crit = -1;
    }
  }
  else {
    ex = (X509_EXTENSION *)0x0;
    iVar8 = 0;
    if (idx != (int *)0x0) {
      iVar8 = 0;
      if (0 < *idx + 1) {
        iVar8 = *idx + 1;
      }
      for (; iVar2 = sk_num(&x->stack), iVar8 < iVar2; iVar8 = iVar8 + 1) {
        ex = (X509_EXTENSION *)sk_value(&x->stack,iVar8);
        iVar2 = OBJ_obj2nid(ex->object);
        if (iVar2 == nid) {
          *idx = iVar8;
          goto LAB_0816adf8;
        }
      }
LAB_0816aea0:
      *idx = -1;
      goto LAB_0816aea6;
    }
    for (; iVar2 = sk_num(&x->stack), iVar8 < iVar2; iVar8 = iVar8 + 1) {
      pXVar3 = (X509_EXTENSION *)sk_value(&x->stack,iVar8);
      iVar2 = OBJ_obj2nid(pXVar3->object);
      if ((nid == iVar2) && (bVar9 = ex != (X509_EXTENSION *)0x0, ex = pXVar3, bVar9)) {
        if (crit == (int *)0x0) goto LAB_0816aeb8;
        *crit = -2;
        pAVar6 = (ASN1_VALUE *)0x0;
        goto LAB_0816ae83;
      }
    }
    if (ex == (X509_EXTENSION *)0x0) goto LAB_0816aea6;
LAB_0816adf8:
    if (crit != (int *)0x0) {
      iVar8 = X509_EXTENSION_get_critical(ex);
      *crit = iVar8;
    }
    puVar4 = (uchar *)OBJ_obj2nid(ex->object);
    if ((puVar4 != (uchar *)0x0) && (local_5c = local_58, -1 < (int)puVar4)) {
      local_58[0] = puVar4;
      ppvVar5 = (void **)OBJ_bsearch_(&local_5c,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
      if (ppvVar5 == (void **)0x0) {
        if ((ext_list == (_STACK *)0x0) || (iVar8 = sk_find(ext_list,local_58), iVar8 == -1))
        goto LAB_0816aeb8;
        pvVar7 = sk_value(ext_list,iVar8);
      }
      else {
        pvVar7 = *ppvVar5;
      }
      if (pvVar7 != (void *)0x0) {
        pAVar1 = ex->value;
        local_58[0] = pAVar1->data;
        if (*(ASN1_ITEM **)((int)pvVar7 + 8) == (ASN1_ITEM *)0x0) {
          pAVar6 = (ASN1_VALUE *)(**(code **)((int)pvVar7 + 0x14))(0,local_58,pAVar1->length);
        }
        else {
          pAVar6 = ASN1_item_d2i((ASN1_VALUE **)0x0,local_58,pAVar1->length,
                                 *(ASN1_ITEM **)((int)pvVar7 + 8));
        }
        goto LAB_0816ae83;
      }
    }
  }
LAB_0816aeb8:
  pAVar6 = (ASN1_VALUE *)0x0;
LAB_0816ae83:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar6;
}

