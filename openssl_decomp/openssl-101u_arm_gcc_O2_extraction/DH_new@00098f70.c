
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DH * DH_new(void)

{
  DH *dh;
  ENGINE *e;
  DH_METHOD *pDVar1;
  int iVar2;
  uint uVar3;
  _func_1704 *p_Var4;
  
  dh = (DH *)CRYPTO_malloc(0x4c,"dh_lib.c",0x7e);
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,"dh_lib.c",0x80);
  }
  else {
    if (default_DH_method == (DH_METHOD *)0x0) {
      default_DH_method = DH_OpenSSL();
    }
    dh->meth = default_DH_method;
    e = ENGINE_get_default_DH();
    dh->engine = e;
    if (e == (ENGINE *)0x0) {
      pDVar1 = dh->meth;
    }
    else {
      pDVar1 = ENGINE_get_DH(e);
      dh->meth = pDVar1;
      if (pDVar1 == (DH_METHOD *)0x0) {
        ERR_put_error(5,0x69,0x26,"dh_lib.c",0x92);
        ENGINE_finish(dh->engine);
        CRYPTO_free(dh);
        return (DH *)0x0;
      }
    }
    uVar3 = pDVar1->flags;
    dh->pad = 0;
    dh->flags = uVar3 & 0xfffffbff;
    dh->version = 0;
    dh->p = (BIGNUM *)0x0;
    dh->g = (BIGNUM *)0x0;
    dh->length = 0;
    dh->pub_key = (BIGNUM *)0x0;
    dh->priv_key = (BIGNUM *)0x0;
    dh->q = (BIGNUM *)0x0;
    dh->j = (BIGNUM *)0x0;
    dh->seed = (uchar *)0x0;
    dh->seedlen = 0;
    dh->counter = (BIGNUM *)0x0;
    dh->method_mont_p = (BN_MONT_CTX *)0x0;
    dh->references = 1;
    CRYPTO_new_ex_data(8,dh,&dh->ex_data);
    p_Var4 = dh->meth->init;
    if (p_Var4 != (_func_1704 *)0x0) {
      iVar2 = (*p_Var4)(dh);
      if (iVar2 != 0) {
        return dh;
      }
      if (dh->engine != (ENGINE *)0x0) {
        ENGINE_finish(dh->engine);
      }
      CRYPTO_free_ex_data(8,dh,&dh->ex_data);
      CRYPTO_free(dh);
      dh = (DH *)0x0;
    }
  }
  return dh;
}

