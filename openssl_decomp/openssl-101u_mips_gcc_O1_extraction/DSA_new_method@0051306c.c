
DSA * DSA_new_method(ENGINE *engine)

{
  undefined *puVar1;
  DSA *dsa;
  int iVar2;
  DSA_METHOD *pDVar3;
  uint uVar4;
  _func_1738 *p_Var5;
  
  dsa = (DSA *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x44,"dsa_lib.c",0x84);
  if (dsa == (DSA *)0x0) {
    ERR_put_error(10,0x67,0x41,"dsa_lib.c",0x86);
    return (DSA *)0x0;
  }
  if (default_DSA_method == (DSA_METHOD *)0x0) {
    default_DSA_method = DSA_OpenSSL();
  }
  dsa->meth = default_DSA_method;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_DSA();
    dsa->engine = engine;
    if (engine != (ENGINE *)0x0) goto LAB_005130ec;
    pDVar3 = dsa->meth;
  }
  else {
    iVar2 = ENGINE_init(engine);
    if (iVar2 == 0) {
      ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x8d);
      goto LAB_00513218;
    }
    dsa->engine = engine;
LAB_005130ec:
    pDVar3 = ENGINE_get_DSA(engine);
    dsa->meth = pDVar3;
    if (pDVar3 == (DSA_METHOD *)0x0) {
      ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x97);
      ENGINE_finish(dsa->engine);
      goto LAB_00513218;
    }
  }
  puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
  uVar4 = pDVar3->flags;
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
  dsa->flags = uVar4 & 0xfffffbff;
  (*(code *)puVar1)(7,dsa,&dsa->ex_data);
  p_Var5 = dsa->meth->init;
  if (p_Var5 == (_func_1738 *)0x0) {
    return dsa;
  }
  iVar2 = (*p_Var5)(dsa);
  if (iVar2 != 0) {
    return dsa;
  }
  if (dsa->engine != (ENGINE *)0x0) {
    ENGINE_finish(dsa->engine);
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(7,dsa,&dsa->ex_data);
LAB_00513218:
  (*(code *)PTR_CRYPTO_free_006a6e88)(dsa);
  return (DSA *)0x0;
}

