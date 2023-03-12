
int X509_STORE_get_by_subject(X509_STORE_CTX *vs,int type,X509_NAME *name,X509_OBJECT *ret)

{
  X509_STORE *pXVar1;
  _STACK *p_Var2;
  code *pcVar3;
  X509 *pXVar4;
  int iVar5;
  int *mode;
  int iVar6;
  void *pvVar7;
  int in_GS_OFFSET;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  int local_28 [2];
  int local_20;
  
  pXVar1 = vs->ctx;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar10 = 0x129;
  pcVar9 = "x509_lu.c";
  uVar8 = 0xb;
  CRYPTO_lock(0,9,(char *)0xb,(int)"x509_lu.c");
  p_Var2 = (_STACK *)pXVar1->objs;
  iVar5 = x509_object_idx_cnt(0,uVar8,pcVar9,uVar10);
  if (iVar5 == -1) {
    mode = (int *)0x0;
    CRYPTO_lock(-1,10,(char *)0xb,(int)"x509_lu.c");
LAB_0816558f:
    iVar5 = vs->current_method;
    while( true ) {
      iVar6 = sk_num((_STACK *)pXVar1->get_cert_methods);
      if (iVar6 <= iVar5) break;
      pvVar7 = sk_value((_STACK *)pXVar1->get_cert_methods,iVar5);
      if (((*(int *)((int)pvVar7 + 8) != 0) &&
          (pcVar3 = *(code **)(*(int *)((int)pvVar7 + 8) + 0x18), pcVar3 != (code *)0x0)) &&
         (*(int *)((int)pvVar7 + 4) == 0)) {
        iVar6 = (*pcVar3)(pvVar7,type,name,local_28);
        if (iVar6 < 0) {
          vs->current_method = iVar6;
          goto LAB_0816563b;
        }
        if (iVar6 != 0) {
          mode = local_28;
          vs->current_method = 0;
          goto LAB_081655fd;
        }
      }
      iVar5 = iVar5 + 1;
    }
    vs->current_method = 0;
    if (mode == (int *)0x0) {
      iVar6 = 0;
      goto LAB_0816563b;
    }
  }
  else {
    mode = (int *)sk_value(p_Var2,iVar5);
    CRYPTO_lock((int)mode,10,(char *)0xb,(int)"x509_lu.c");
    if ((mode == (int *)0x0) || (type == 2)) goto LAB_0816558f;
  }
LAB_081655fd:
  iVar6 = *mode;
  ret->type = iVar6;
  pXVar4 = (X509 *)mode[1];
  (ret->data).x509 = pXVar4;
  if (iVar6 == 1) {
    CRYPTO_add_lock(&pXVar4->references,1,3,"x509_lu.c",0x195);
  }
  else if (iVar6 == 2) {
    CRYPTO_add_lock(&pXVar4->valid,1,6,"x509_lu.c",0x198);
    iVar6 = 1;
  }
  else {
    iVar6 = 1;
  }
LAB_0816563b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

