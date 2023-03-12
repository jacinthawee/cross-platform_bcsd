
RSA * RSA_new_method(ENGINE *engine)

{
  undefined *puVar1;
  RSA *rsa;
  int iVar2;
  RSA_METHOD *pRVar3;
  uint uVar4;
  _func_1624 *p_Var5;
  
  rsa = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x58,"rsa_lib.c",0x8d);
  if (rsa == (RSA *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6a,0x41,"rsa_lib.c",0x8f);
    return (RSA *)0x0;
  }
  if (default_RSA_meth == (RSA_METHOD *)0x0) {
    default_RSA_meth = RSA_PKCS1_SSLeay();
  }
  rsa->meth = default_RSA_meth;
  if (engine == (ENGINE *)0x0) {
    engine = ENGINE_get_default_RSA();
    rsa->engine = engine;
    if (engine != (ENGINE *)0x0) goto LAB_0050de5c;
    pRVar3 = rsa->meth;
  }
  else {
    iVar2 = ENGINE_init(engine);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6a,0x26,"rsa_lib.c",0x97);
      goto LAB_0050dfd0;
    }
    rsa->engine = engine;
LAB_0050de5c:
    pRVar3 = ENGINE_get_RSA(engine);
    rsa->meth = pRVar3;
    if (pRVar3 == (RSA_METHOD *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6a,0x26,"rsa_lib.c",0xa1);
      ENGINE_finish(rsa->engine);
      goto LAB_0050dfd0;
    }
  }
  puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
  uVar4 = pRVar3->flags;
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
  rsa->flags = uVar4 & 0xfffffbff;
  iVar2 = (*(code *)puVar1)(6,rsa,&rsa->ex_data);
  if (iVar2 == 0) {
    if (rsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(rsa->engine);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(rsa);
    rsa = (RSA *)0x0;
  }
  else {
    p_Var5 = rsa->meth->init;
    if (p_Var5 == (_func_1624 *)0x0) {
      return rsa;
    }
    iVar2 = (*p_Var5)(rsa);
    if (iVar2 == 0) {
      if (rsa->engine != (ENGINE *)0x0) {
        ENGINE_finish(rsa->engine);
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(6,rsa,&rsa->ex_data);
LAB_0050dfd0:
      (*(code *)PTR_CRYPTO_free_006a6e88)(rsa);
      return (RSA *)0x0;
    }
  }
  return rsa;
}

