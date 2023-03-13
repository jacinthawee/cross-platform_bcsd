
BIO * cms_SignedData_init_bio(ASN1_OBJECT **param_1)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  BIO *append;
  int *piVar5;
  BIO *a;
  
  iVar2 = OBJ_obj2nid(*param_1);
  if (iVar2 != 0x16) {
    ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
    return (BIO *)0x0;
  }
  pAVar1 = param_1[1];
  if (pAVar1 != (ASN1_OBJECT *)0x0) {
    iVar2 = 0;
    if (*(int *)(pAVar1->nid + 8) != 0) {
      for (; iVar3 = sk_num((_STACK *)pAVar1->length), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        piVar5 = (int *)sk_value((_STACK *)pAVar1->length,iVar2);
        iVar3 = *piVar5;
        if (iVar3 == 4) {
          if ((int)pAVar1->sn < 5) {
            pAVar1->sn = (char *)0x5;
          }
        }
        else if (iVar3 == 3) {
          if ((int)pAVar1->sn < 4) {
            pAVar1->sn = (char *)0x4;
          }
        }
        else if ((iVar3 == 2) && ((int)pAVar1->sn < 3)) {
          pAVar1->sn = (char *)0x3;
        }
      }
      for (iVar2 = 0; iVar3 = sk_num((_STACK *)pAVar1->data), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        piVar5 = (int *)sk_value((_STACK *)pAVar1->data,iVar2);
        if ((*piVar5 == 1) && ((int)pAVar1->sn < 5)) {
          pAVar1->sn = (char *)0x5;
        }
      }
      iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)pAVar1->nid);
      if ((iVar2 != 0x15) && ((int)pAVar1->sn < 3)) {
        pAVar1->sn = (char *)0x3;
      }
      for (iVar2 = 0; iVar3 = sk_num((_STACK *)pAVar1->flags), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        piVar5 = (int *)sk_value((_STACK *)pAVar1->flags,iVar2);
        if (*(int *)piVar5[1] == 1) {
          if (*piVar5 < 3) {
            *piVar5 = 3;
          }
          if ((int)pAVar1->sn < 3) {
            pAVar1->sn = (char *)0x3;
          }
        }
        else if (*piVar5 < 1) {
          *piVar5 = 1;
        }
      }
      if ((int)pAVar1->sn < 1) {
        pAVar1->sn = (char *)0x1;
      }
    }
    iVar2 = 0;
    a = (BIO *)0x0;
    while( true ) {
      iVar3 = sk_num((_STACK *)pAVar1->ln);
      if (iVar3 <= iVar2) {
        return a;
      }
      pvVar4 = sk_value((_STACK *)pAVar1->ln,iVar2);
      append = (BIO *)cms_DigestAlgorithm_init_bio(pvVar4);
      if (append == (BIO *)0x0) break;
      if (a != (BIO *)0x0) {
        BIO_push(a,append);
        append = a;
      }
      iVar2 = iVar2 + 1;
      a = append;
    }
    if (a != (BIO *)0x0) {
      BIO_free_all(a);
    }
  }
  return (BIO *)0x0;
}

