
stack_st_X509 * X509_STORE_CTX_get1_chain(X509_STORE_CTX *ctx)

{
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (((_STACK *)ctx->chain == (_STACK *)0x0) ||
     (p_Var1 = sk_dup((_STACK *)ctx->chain), p_Var1 == (_STACK *)0x0)) {
    p_Var1 = (_STACK *)0x0;
  }
  else {
    for (iVar4 = 0; iVar3 = sk_num(p_Var1), iVar4 < iVar3; iVar4 = iVar4 + 1) {
      pvVar2 = sk_value(p_Var1,iVar4);
      CRYPTO_add_lock((int *)((int)pvVar2 + 0x10),1,3,"x509_vfy.c",0x75d);
    }
  }
  return (stack_st_X509 *)p_Var1;
}

