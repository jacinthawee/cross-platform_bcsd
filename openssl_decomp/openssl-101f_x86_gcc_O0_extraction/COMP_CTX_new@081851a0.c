
COMP_CTX * COMP_CTX_new(COMP_METHOD *meth)

{
  _func_569 *p_Var1;
  COMP_CTX *ctx;
  int iVar2;
  uint uVar3;
  uint uVar4;
  COMP_CTX *pCVar5;
  
  ctx = (COMP_CTX *)CRYPTO_malloc(0x1c,"comp_lib.c",0xb);
  if (ctx == (COMP_CTX *)0x0) {
    pCVar5 = (COMP_CTX *)0x0;
  }
  else {
    ctx->meth = (COMP_METHOD *)0x0;
    (ctx->ex_data).dummy = 0;
    uVar3 = 0;
    uVar4 = (uint)&ctx->compress_in & 0xfffffffc;
    do {
      *(undefined4 *)(uVar4 + uVar3) = 0;
      uVar3 = uVar3 + 4;
    } while (uVar3 < ((int)ctx + (0x1c - uVar4) & 0xfffffffc));
    p_Var1 = meth->init;
    ctx->meth = meth;
    pCVar5 = ctx;
    if (p_Var1 != (_func_569 *)0x0) {
      iVar2 = (*p_Var1)(ctx);
      if (iVar2 == 0) {
        pCVar5 = (COMP_CTX *)0x0;
        CRYPTO_free(ctx);
      }
    }
  }
  return pCVar5;
}

