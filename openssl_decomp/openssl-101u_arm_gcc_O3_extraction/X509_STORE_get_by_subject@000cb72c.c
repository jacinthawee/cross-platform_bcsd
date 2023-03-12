
int X509_STORE_get_by_subject(X509_STORE_CTX *vs,int type,X509_NAME *name,X509_OBJECT *ret)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  X509 *pXVar5;
  _STACK *p_Var6;
  int iVar7;
  code *pcVar8;
  X509_STORE *pXVar9;
  int local_30 [3];
  
  pXVar9 = vs->ctx;
  CRYPTO_lock(9,0xb,"x509_lu.c",0x124);
  p_Var6 = (_STACK *)pXVar9->objs;
  iVar1 = x509_object_idx_cnt(p_Var6,type,name,0);
  if (iVar1 == -1) {
    piVar2 = (int *)0x0;
    CRYPTO_lock(10,0xb,"x509_lu.c",0x126);
  }
  else {
    piVar2 = (int *)sk_value(p_Var6,iVar1);
    CRYPTO_lock(10,0xb,"x509_lu.c",0x126);
    if (type != 2 && piVar2 != (int *)0x0) goto LAB_000cb7ce;
  }
  iVar1 = vs->current_method;
  do {
    do {
      iVar3 = sk_num((_STACK *)pXVar9->get_cert_methods);
      iVar7 = iVar1 + 1;
      if (iVar3 <= iVar1) {
        vs->current_method = 0;
        if (piVar2 == (int *)0x0) {
          return 0;
        }
        goto LAB_000cb7ce;
      }
      pvVar4 = sk_value((_STACK *)pXVar9->get_cert_methods,iVar1);
      iVar1 = iVar7;
    } while (((*(int *)((int)pvVar4 + 8) == 0) ||
             (pcVar8 = *(code **)(*(int *)((int)pvVar4 + 8) + 0x18), pcVar8 == (code *)0x0)) ||
            (*(int *)((int)pvVar4 + 4) != 0));
    iVar3 = (*pcVar8)(pvVar4,type,name,local_30);
    if (iVar3 < 0) {
      vs->current_method = iVar3;
      return iVar3;
    }
  } while (iVar3 == 0);
  piVar2 = local_30;
  vs->current_method = 0;
LAB_000cb7ce:
  iVar1 = *piVar2;
  pXVar5 = (X509 *)piVar2[1];
  ret->type = iVar1;
  (ret->data).x509 = pXVar5;
  if (iVar1 == 1) {
    CRYPTO_add_lock(&pXVar5->references,1,3,"x509_lu.c",0x18a);
    return 1;
  }
  if (iVar1 == 2) {
    CRYPTO_add_lock(&pXVar5->valid,1,6,"x509_lu.c",0x18d);
    return 1;
  }
  return 1;
}

