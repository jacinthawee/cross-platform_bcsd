
stack_st_X509 * X509_STORE_get1_certs(X509_STORE_CTX *st,X509_NAME *nm)

{
  X509 *a;
  _STACK *st_00;
  int iVar1;
  void *pvVar2;
  int mode;
  int iVar3;
  int in_GS_OFFSET;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int local_2c;
  X509_OBJECT local_28;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st_00 = sk_new_null();
  uVar6 = 0x1e0;
  pcVar5 = "x509_lu.c";
  uVar4 = 0xb;
  CRYPTO_lock((int)st_00,9,(char *)0xb,(int)"x509_lu.c");
  iVar1 = x509_object_idx_cnt(&local_2c,uVar4,pcVar5,uVar6);
  if (iVar1 < 0) {
    CRYPTO_lock(iVar1,10,(char *)0xb,(int)"x509_lu.c");
    iVar1 = X509_STORE_get_by_subject(st,1,nm,&local_28);
    if (iVar1 == 0) {
      sk_free(st_00);
      st_00 = (_STACK *)0x0;
      goto LAB_081639da;
    }
    if (local_28.type == 1) {
      X509_free(local_28.data.x509);
    }
    else if (local_28.type == 2) {
      X509_CRL_free(local_28.data.crl);
    }
    uVar6 = 0x1ee;
    pcVar5 = "x509_lu.c";
    uVar4 = 0xb;
    CRYPTO_lock(local_28.type,9,(char *)0xb,(int)"x509_lu.c");
    iVar1 = x509_object_idx_cnt(&local_2c,uVar4,pcVar5,uVar6);
    if (iVar1 < 0) {
      CRYPTO_lock(iVar1,10,(char *)0xb,(int)"x509_lu.c");
      sk_free(st_00);
      st_00 = (_STACK *)0x0;
      goto LAB_081639da;
    }
  }
  iVar3 = 0;
  mode = iVar1;
  if (0 < local_2c) {
    do {
      pvVar2 = sk_value((_STACK *)st->ctx->objs,iVar3 + iVar1);
      a = *(X509 **)((int)pvVar2 + 4);
      CRYPTO_add_lock(&a->references,1,3,"x509_lu.c",0x1f9);
      mode = sk_push(st_00,a);
      if (mode == 0) {
        CRYPTO_lock(0,10,(char *)0xb,(int)"x509_lu.c");
        X509_free(a);
        sk_pop_free(st_00,X509_free);
        st_00 = (_STACK *)0x0;
        goto LAB_081639da;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < local_2c);
  }
  CRYPTO_lock(mode,10,(char *)0xb,(int)"x509_lu.c");
LAB_081639da:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (stack_st_X509 *)st_00;
}
