
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DH * DH_new(void)

{
  uint uVar1;
  _func_1704 *p_Var2;
  DH *dh;
  ENGINE *e;
  DH_METHOD *e_00;
  int iVar3;
  
  dh = (DH *)CRYPTO_malloc(0x4c,"dh_lib.c",0x7c);
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,"dh_lib.c",0x7f);
    dh = (DH *)0x0;
  }
  else {
    if (default_DH_method == (DH_METHOD *)0x0) {
      default_DH_method = DH_OpenSSL();
    }
    dh->meth = default_DH_method;
    e = ENGINE_get_default_DH();
    dh->engine = e;
    if (e == (ENGINE *)0x0) {
      e_00 = dh->meth;
    }
    else {
      e_00 = ENGINE_get_DH(e);
      dh->meth = e_00;
      if (e_00 == (DH_METHOD *)0x0) {
        ERR_put_error(5,0x69,0x26,"dh_lib.c",0x96);
        ENGINE_finish((ENGINE *)e_00);
        CRYPTO_free(dh);
        return (DH *)0x0;
      }
    }
    uVar1 = e_00->flags;
    dh->pad = 0;
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
    dh->flags = uVar1 & 0xfffffbff;
    CRYPTO_new_ex_data(8,dh,&dh->ex_data);
    p_Var2 = dh->meth->init;
    if ((p_Var2 != (_func_1704 *)0x0) && (iVar3 = (*p_Var2)(dh), iVar3 == 0)) {
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

