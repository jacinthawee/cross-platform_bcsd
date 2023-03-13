
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA * RSA_new(void)

{
  uint uVar1;
  _func_1624 *p_Var2;
  RSA *rsa;
  ENGINE *e;
  RSA_METHOD *e_00;
  int iVar3;
  
  rsa = (RSA *)CRYPTO_malloc(0x58,"rsa_lib.c",0x8d);
  if (rsa == (RSA *)0x0) {
    ERR_put_error(4,0x6a,0x41,"rsa_lib.c",0x8f);
    rsa = (RSA *)0x0;
  }
  else {
    if (default_RSA_meth == (RSA_METHOD *)0x0) {
      default_RSA_meth = RSA_PKCS1_SSLeay();
    }
    rsa->meth = default_RSA_meth;
    e = ENGINE_get_default_RSA();
    rsa->engine = e;
    if (e == (ENGINE *)0x0) {
      e_00 = rsa->meth;
    }
    else {
      e_00 = ENGINE_get_RSA(e);
      rsa->meth = e_00;
      if (e_00 == (RSA_METHOD *)0x0) {
        ERR_put_error(4,0x6a,0x26,"rsa_lib.c",0xa1);
        ENGINE_finish((ENGINE *)e_00);
        CRYPTO_free(rsa);
        return (RSA *)0x0;
      }
    }
    uVar1 = e_00->flags;
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
  }
  return rsa;
}

