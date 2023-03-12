
stack_st_X509 * X509_STORE_CTX_get1_chain(X509_STORE_CTX *ctx)

{
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if ((_STACK *)ctx->chain != (_STACK *)0x0) {
    p_Var1 = sk_dup((_STACK *)ctx->chain);
    if (p_Var1 == (_STACK *)0x0) {
      p_Var1 = (_STACK *)0x0;
    }
    else {
      iVar4 = 0;
      while( true ) {
        iVar3 = sk_num(p_Var1);
        if (iVar3 <= iVar4) break;
        pvVar2 = sk_value(p_Var1,iVar4);
        CRYPTO_add_lock((int *)((int)pvVar2 + 0x10),1,3,"x509_vfy.c",0x7d4);
        iVar4 = iVar4 + 1;
      }
    }
    return (stack_st_X509 *)p_Var1;
  }
  return (stack_st_X509 *)0x0;
}

