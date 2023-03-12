
DSA * DSA_new_method(ENGINE *engine)

{
  uint uVar1;
  _func_1738 *p_Var2;
  DSA *dsa;
  int iVar3;
  DSA_METHOD *pDVar4;
  
  dsa = (DSA *)CRYPTO_malloc(0x44,"dsa_lib.c",0x82);
  if (dsa == (DSA *)0x0) {
    ERR_put_error(10,0x67,0x41,"dsa_lib.c",0x85);
    return (DSA *)0x0;
  }
  if (default_DSA_method == (DSA_METHOD *)0x0) {
    default_DSA_method = DSA_OpenSSL();
  }
  pDVar4 = default_DSA_method;
  dsa->meth = default_DSA_method;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DSA();
    dsa->engine = engine;
    if (engine == (ENGINE *)0x0) {
      pDVar4 = dsa->meth;
      goto LAB_0810edbf;
    }
  }
  else {
    iVar3 = ENGINE_init((ENGINE *)pDVar4);
    if (iVar3 == 0) {
      ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x8e);
      CRYPTO_free(dsa);
      return (DSA *)0x0;
    }
    dsa->engine = engine;
  }
  pDVar4 = ENGINE_get_DSA(engine);
  dsa->meth = pDVar4;
  if (pDVar4 == (DSA_METHOD *)0x0) {
    ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x9c);
    ENGINE_finish((ENGINE *)pDVar4);
    CRYPTO_free(dsa);
    return (DSA *)0x0;
  }
LAB_0810edbf:
  uVar1 = pDVar4->flags;
  dsa->pad = 0;
  dsa->version = 0;
  dsa->write_params = 1;
  dsa->p = (BIGNUM *)0x0;
  dsa->q = (BIGNUM *)0x0;
  dsa->g = (BIGNUM *)0x0;
  dsa->pub_key = (BIGNUM *)0x0;
  dsa->priv_key = (BIGNUM *)0x0;
  dsa->kinv = (BIGNUM *)0x0;
  dsa->r = (BIGNUM *)0x0;
  dsa->method_mont_p = (BN_MONT_CTX *)0x0;
  dsa->references = 1;
  dsa->flags = uVar1 & 0xfffffbff;
  CRYPTO_new_ex_data(7,dsa,&dsa->ex_data);
  p_Var2 = dsa->meth->init;
  if ((p_Var2 != (_func_1738 *)0x0) && (iVar3 = (*p_Var2)(dsa), iVar3 == 0)) {
    if (dsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(dsa->engine);
    }
    CRYPTO_free_ex_data(7,dsa,&dsa->ex_data);
    CRYPTO_free(dsa);
    dsa = (DSA *)0x0;
  }
  return dsa;
}

