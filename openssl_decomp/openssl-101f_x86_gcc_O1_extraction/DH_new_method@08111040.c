
DH * DH_new_method(ENGINE *engine)

{
  uint uVar1;
  _func_1704 *p_Var2;
  DH *dh;
  int iVar3;
  DH_METHOD *pDVar4;
  
  dh = (DH *)CRYPTO_malloc(0x4c,"dh_lib.c",0x7c);
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,"dh_lib.c",0x7f);
    return (DH *)0x0;
  }
  if (default_DH_method == (DH_METHOD *)0x0) {
    default_DH_method = DH_OpenSSL();
  }
  pDVar4 = default_DH_method;
  dh->meth = default_DH_method;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DH();
    dh->engine = engine;
    if (engine == (ENGINE *)0x0) {
      pDVar4 = dh->meth;
      goto LAB_081110ac;
    }
  }
  else {
    iVar3 = ENGINE_init((ENGINE *)pDVar4);
    if (iVar3 == 0) {
      ERR_put_error(5,0x69,0x26,"dh_lib.c",0x89);
      CRYPTO_free(dh);
      return (DH *)0x0;
    }
    dh->engine = engine;
  }
  pDVar4 = ENGINE_get_DH(engine);
  dh->meth = pDVar4;
  if (pDVar4 == (DH_METHOD *)0x0) {
    ERR_put_error(5,0x69,0x26,"dh_lib.c",0x96);
    ENGINE_finish((ENGINE *)pDVar4);
    CRYPTO_free(dh);
    return (DH *)0x0;
  }
LAB_081110ac:
  uVar1 = pDVar4->flags;
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
  return dh;
}

