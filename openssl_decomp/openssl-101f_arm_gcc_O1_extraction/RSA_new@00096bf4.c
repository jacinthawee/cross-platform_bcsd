
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA * RSA_new(void)

{
  RSA *rsa;
  ENGINE *e;
  RSA_METHOD *pRVar1;
  int iVar2;
  _func_1624 *p_Var3;
  
  rsa = (RSA *)CRYPTO_malloc(0x58,"rsa_lib.c",0x8b);
  if (rsa == (RSA *)0x0) {
    ERR_put_error(4,0x6a,0x41,"rsa_lib.c",0x8e);
  }
  else {
    if (default_RSA_meth == (RSA_METHOD *)0x0) {
      default_RSA_meth = RSA_PKCS1_SSLeay();
    }
    rsa->meth = default_RSA_meth;
    e = ENGINE_get_default_RSA();
    rsa->engine = e;
    if (e == (ENGINE *)0x0) {
      pRVar1 = rsa->meth;
    }
    else {
      pRVar1 = ENGINE_get_RSA(e);
      rsa->meth = pRVar1;
      if (pRVar1 == (RSA_METHOD *)0x0) {
        ERR_put_error(4,0x6a,0x26,"rsa_lib.c",0xa6);
        ENGINE_finish(rsa->engine);
        CRYPTO_free(rsa);
        return (RSA *)0x0;
      }
    }
    rsa->flags = pRVar1->flags & 0xfffffbff;
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
    rsa->_method_mod_n = (BN_MONT_CTX *)0x0;
    rsa->_method_mod_p = (BN_MONT_CTX *)0x0;
    rsa->_method_mod_q = (BN_MONT_CTX *)0x0;
    rsa->blinding = (BN_BLINDING *)0x0;
    rsa->mt_blinding = (BN_BLINDING *)0x0;
    rsa->bignum_data = (char *)0x0;
    rsa->references = 1;
    iVar2 = CRYPTO_new_ex_data(6,rsa,&rsa->ex_data);
    if (iVar2 == 0) {
      if (rsa->engine != (ENGINE *)0x0) {
        ENGINE_finish(rsa->engine);
      }
    }
    else {
      p_Var3 = rsa->meth->init;
      if (p_Var3 == (_func_1624 *)0x0) {
        return rsa;
      }
      iVar2 = (*p_Var3)(rsa);
      if (iVar2 != 0) {
        return rsa;
      }
      if (rsa->engine != (ENGINE *)0x0) {
        ENGINE_finish(rsa->engine);
      }
      CRYPTO_free_ex_data(6,rsa,&rsa->ex_data);
    }
    CRYPTO_free(rsa);
    rsa = (RSA *)0x0;
  }
  return rsa;
}

