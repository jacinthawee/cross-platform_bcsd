
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA * RSA_new(void)

{
  undefined *puVar1;
  RSA *rsa;
  ENGINE *e;
  RSA_METHOD *pRVar2;
  uint uVar3;
  int iVar4;
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
  e = ENGINE_get_default_RSA();
  rsa->engine = e;
  if (e == (ENGINE *)0x0) {
    pRVar2 = rsa->meth;
  }
  else {
    pRVar2 = ENGINE_get_RSA(e);
    rsa->meth = pRVar2;
    if (pRVar2 == (RSA_METHOD *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6a,0x26,"rsa_lib.c",0xa1);
      ENGINE_finish(rsa->engine);
      goto LAB_0050dc6c;
    }
  }
  puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
  uVar3 = pRVar2->flags;
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
  rsa->flags = uVar3 & 0xfffffbff;
  iVar4 = (*(code *)puVar1)(6,rsa,&rsa->ex_data);
  if (iVar4 == 0) {
    if (rsa->engine != (ENGINE *)0x0) {
      ENGINE_finish(rsa->engine);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(rsa);
    return (RSA *)0x0;
  }
  p_Var5 = rsa->meth->init;
  if (p_Var5 == (_func_1624 *)0x0) {
    return rsa;
  }
  iVar4 = (*p_Var5)(rsa);
  if (iVar4 != 0) {
    return rsa;
  }
  if (rsa->engine != (ENGINE *)0x0) {
    ENGINE_finish(rsa->engine);
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(6,rsa,&rsa->ex_data);
LAB_0050dc6c:
  (*(code *)PTR_CRYPTO_free_006a6e88)(rsa);
  return (RSA *)0x0;
}

