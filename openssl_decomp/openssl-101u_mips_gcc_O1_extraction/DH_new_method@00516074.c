
DH * DH_new_method(ENGINE *engine)

{
  undefined *puVar1;
  DH *dh;
  int iVar2;
  DH_METHOD *pDVar3;
  uint uVar4;
  _func_1704 *p_Var5;
  
  dh = (DH *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x4c,"dh_lib.c",0x7e);
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,"dh_lib.c",0x80);
    return (DH *)0x0;
  }
  if (default_DH_method == (DH_METHOD *)0x0) {
    default_DH_method = DH_OpenSSL();
  }
  dh->meth = default_DH_method;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DH();
    dh->engine = engine;
    if (engine != (ENGINE *)0x0) goto LAB_005160f4;
    pDVar3 = dh->meth;
  }
  else {
    iVar2 = ENGINE_init(engine);
    if (iVar2 == 0) {
      ERR_put_error(5,0x69,0x26,"dh_lib.c",0x88);
      goto LAB_00516228;
    }
    dh->engine = engine;
LAB_005160f4:
    pDVar3 = ENGINE_get_DH(engine);
    dh->meth = pDVar3;
    if (pDVar3 == (DH_METHOD *)0x0) {
      ERR_put_error(5,0x69,0x26,"dh_lib.c",0x92);
      ENGINE_finish(dh->engine);
      goto LAB_00516228;
    }
  }
  puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
  uVar4 = pDVar3->flags;
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
  dh->flags = uVar4 & 0xfffffbff;
  (*(code *)puVar1)(8,dh,&dh->ex_data);
  p_Var5 = dh->meth->init;
  if (p_Var5 == (_func_1704 *)0x0) {
    return dh;
  }
  iVar2 = (*p_Var5)(dh);
  if (iVar2 != 0) {
    return dh;
  }
  if (dh->engine != (ENGINE *)0x0) {
    ENGINE_finish(dh->engine);
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(8,dh,&dh->ex_data);
LAB_00516228:
  (*(code *)PTR_CRYPTO_free_006a6e88)(dh);
  return (DH *)0x0;
}

