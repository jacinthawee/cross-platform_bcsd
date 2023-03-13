
void DSA_free(DSA *r)

{
  int iVar1;
  _func_1739 *p_Var2;
  
  if ((r != (DSA *)0x0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(&r->references,0xffffffff,8,"dsa_lib.c",0xc4),
     iVar1 < 1)) {
    p_Var2 = r->meth->finish;
    if (p_Var2 != (_func_1739 *)0x0) {
      (*p_Var2)(r);
    }
    if (r->engine != (ENGINE *)0x0) {
      ENGINE_finish(r->engine);
    }
    (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(7,r,&r->ex_data);
    if (r->p != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    if (r->q != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    if (r->g != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    if (r->pub_key != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    if (r->priv_key != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    if (r->kinv != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    if (r->r != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
                    /* WARNING: Could not recover jumptable at 0x00513448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(r);
    return;
  }
  return;
}

