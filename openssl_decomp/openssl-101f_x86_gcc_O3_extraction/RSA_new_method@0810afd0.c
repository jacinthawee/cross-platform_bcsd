
RSA * RSA_new_method(ENGINE *engine)

{
  uint uVar1;
  _func_1624 *p_Var2;
  RSA *rsa;
  int iVar3;
  RSA_METHOD *pRVar4;
  
  rsa = (RSA *)CRYPTO_malloc(0x58,"rsa_lib.c",0x8b);
  if (rsa == (RSA *)0x0) {
    ERR_put_error(4,0x6a,0x41,"rsa_lib.c",0x8e);
    return (RSA *)0x0;
  }
  if (default_RSA_meth == (RSA_METHOD *)0x0) {
    default_RSA_meth = RSA_PKCS1_SSLeay();
  }
  pRVar4 = default_RSA_meth;
  rsa->meth = default_RSA_meth;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_RSA();
    rsa->engine = engine;
    if (engine == (ENGINE *)0x0) {
      pRVar4 = rsa->meth;
      goto LAB_0810b03f;
    }
  }
  else {
    iVar3 = ENGINE_init((ENGINE *)pRVar4);
    if (iVar3 == 0) {
      ERR_put_error(4,0x6a,0x26,"rsa_lib.c",0x98);
      CRYPTO_free(rsa);
      return (RSA *)0x0;
    }
    rsa->engine = engine;
  }
  pRVar4 = ENGINE_get_RSA(engine);
  rsa->meth = pRVar4;
  if (pRVar4 == (RSA_METHOD *)0x0) {
    ERR_put_error(4,0x6a,0x26,"rsa_lib.c",0xa6);
    ENGINE_finish((ENGINE *)pRVar4);
    CRYPTO_free(rsa);
    return (RSA *)0x0;
  }
LAB_0810b03f:
  uVar1 = pRVar4->flags;
  rsa->pad = 0;
  rsa->version = 0;
  rsa->n = (BIGNUM *)0x0;
  rsa->e = (BIGNUM *)0x0;
  rsa->d = (BIGNUM *)0x0;
  rsa->p = (BIGNUM *)0x0;
  rsa->q = (BIGNUM *)0x0;
  rsa->dmp1 = (BIGNUM *)0x0;
  rsa->dmq1 = (BIGNUM *)0x0;
  rsa->iqmp = (BIGNUM *)0x0;
  rsa->references = 1;
  rsa->_method_mod_n = (BN_MONT_CTX *)0x0;
  rsa->_method_mod_p = (BN_MONT_CTX *)0x0;
  rsa->_method_mod_q = (BN_MONT_CTX *)0x0;
  rsa->blinding = (BN_BLINDING *)0x0;
  rsa->mt_blinding = (BN_BLINDING *)0x0;
  rsa->bignum_data = (char *)0x0;
  rsa->flags = uVar1 & 0xfffffbff;
  iVar3 = CRYPTO_new_ex_data(6,rsa,&rsa->ex_data);
  if (iVar3 == 0) {
    if (rsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(rsa->engine);
    }
    CRYPTO_free(rsa);
    rsa = (RSA *)0x0;
  }
  else {
    p_Var2 = rsa->meth->init;
    if ((p_Var2 != (_func_1624 *)0x0) && (iVar3 = (*p_Var2)(rsa), iVar3 == 0)) {
      if (rsa->engine != (ENGINE *)0x0) {
        ENGINE_finish(rsa->engine);
      }
      CRYPTO_free_ex_data(6,rsa,&rsa->ex_data);
      CRYPTO_free(rsa);
      rsa = (RSA *)0x0;
    }
  }
  return rsa;
}

