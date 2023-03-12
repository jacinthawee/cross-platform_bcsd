
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA * DSA_new(void)

{
  DSA *dsa;
  ENGINE *e;
  DSA_METHOD *pDVar1;
  int iVar2;
  uint uVar3;
  _func_1738 *p_Var4;
  
  dsa = (DSA *)CRYPTO_malloc(0x44,"dsa_lib.c",0x82);
  if (dsa == (DSA *)0x0) {
    ERR_put_error(10,0x67,0x41,"dsa_lib.c",0x85);
  }
  else {
    if (default_DSA_method == (DSA_METHOD *)0x0) {
      default_DSA_method = DSA_OpenSSL();
    }
    dsa->meth = default_DSA_method;
    e = ENGINE_get_default_DSA();
    dsa->engine = e;
    if (e == (ENGINE *)0x0) {
      pDVar1 = dsa->meth;
    }
    else {
      pDVar1 = ENGINE_get_DSA(e);
      dsa->meth = pDVar1;
      if (pDVar1 == (DSA_METHOD *)0x0) {
        ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x9c);
        ENGINE_finish(dsa->engine);
        CRYPTO_free(dsa);
        return (DSA *)0x0;
      }
    }
    uVar3 = pDVar1->flags;
    dsa->pad = 0;
    dsa->flags = uVar3 & 0xfffffbff;
    dsa->version = 0;
    dsa->p = (BIGNUM *)0x0;
    dsa->q = (BIGNUM *)0x0;
    dsa->g = (BIGNUM *)0x0;
    dsa->pub_key = (BIGNUM *)0x0;
    dsa->priv_key = (BIGNUM *)0x0;
    dsa->kinv = (BIGNUM *)0x0;
    dsa->r = (BIGNUM *)0x0;
    dsa->method_mont_p = (BN_MONT_CTX *)0x0;
    dsa->write_params = 1;
    dsa->references = 1;
    CRYPTO_new_ex_data(7,dsa,&dsa->ex_data);
    p_Var4 = dsa->meth->init;
    if (p_Var4 != (_func_1738 *)0x0) {
      iVar2 = (*p_Var4)(dsa);
      if (iVar2 != 0) {
        return dsa;
      }
      if (dsa->engine != (ENGINE *)0x0) {
        ENGINE_finish(dsa->engine);
      }
      CRYPTO_free_ex_data(7,dsa,&dsa->ex_data);
      CRYPTO_free(dsa);
      dsa = (DSA *)0x0;
    }
  }
  return dsa;
}

