
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA * DSA_new(void)

{
  undefined *puVar1;
  DSA *dsa;
  ENGINE *e;
  DSA_METHOD *pDVar2;
  uint uVar3;
  int iVar4;
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
  e = ENGINE_get_default_DSA();
  dsa->engine = e;
  if (e == (ENGINE *)0x0) {
    pDVar2 = dsa->meth;
  }
  else {
    pDVar2 = ENGINE_get_DSA(e);
    dsa->meth = pDVar2;
    if (pDVar2 == (DSA_METHOD *)0x0) {
      ERR_put_error(10,0x67,0x26,"dsa_lib.c",0x97);
      ENGINE_finish(dsa->engine);
      goto LAB_00512f64;
    }
  }
  puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
  uVar3 = pDVar2->flags;
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
  dsa->flags = uVar3 & 0xfffffbff;
  (*(code *)puVar1)(7,dsa,&dsa->ex_data);
  p_Var5 = dsa->meth->init;
  if (p_Var5 == (_func_1738 *)0x0) {
    return dsa;
  }
  iVar4 = (*p_Var5)(dsa);
  if (iVar4 != 0) {
    return dsa;
  }
  if (dsa->engine != (ENGINE *)0x0) {
    ENGINE_finish(dsa->engine);
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(7,dsa,&dsa->ex_data);
LAB_00512f64:
  (*(code *)PTR_CRYPTO_free_006a6e88)(dsa);
  return (DSA *)0x0;
}

