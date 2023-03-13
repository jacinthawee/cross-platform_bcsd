
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA * DSA_new(void)

{
  uint uVar1;
  _func_1738 *p_Var2;
  DSA *dsa;
  ENGINE *e;
  DSA_METHOD *e_00;
  int iVar3;
  
  dsa = (DSA *)CRYPTO_malloc(0x44,"dsa_lib.c",0x84);
  if (dsa == (DSA *)0x0) {
    ERR_put_error(10,0x67,0x41,"dsa_lib.c",0x86);
    dsa = (DSA *)0x0;
  }
  else {
    if (default_DSA_method == (DSA_METHOD *)0x0) {
      default_DSA_method = DSA_OpenSSL();
    }
    dsa->meth = default_DSA_method;
    e = ENGINE_get_default_DSA();
    dsa->engine = e;
    if (e == (ENGINE *)0x0) {
      e_00 = dsa->meth;
    }
    else {
      e_00 = ENGINE_get_DSA(e);
      dsa->meth = e_00;
      if (e_00 == (DSA_METHOD *)0x0) {
        ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x97);
        ENGINE_finish((ENGINE *)e_00);
        CRYPTO_free(dsa);
        return (DSA *)0x0;
      }
    }
    uVar1 = e_00->flags;
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
  }
  return dsa;
}

