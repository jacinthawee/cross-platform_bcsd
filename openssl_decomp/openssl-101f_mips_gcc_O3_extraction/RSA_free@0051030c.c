
void RSA_free(RSA *r)

{
  int iVar1;
  _func_1625 *p_Var2;
  
  if ((r != (RSA *)0x0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(&r->references,0xffffffff,9,"rsa_lib.c",0xdd),
     iVar1 < 1)) {
    p_Var2 = r->meth->finish;
    if (p_Var2 != (_func_1625 *)0x0) {
      (*p_Var2)(r);
    }
    if (r->engine != (ENGINE *)0x0) {
      ENGINE_finish(r->engine);
    }
    (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(6,r,&r->ex_data);
    if (r->n != (BIGNUM *)0x0) {
      BN_clear_free(r->n);
    }
    if (r->e != (BIGNUM *)0x0) {
      BN_clear_free(r->e);
    }
    if (r->d != (BIGNUM *)0x0) {
      BN_clear_free(r->d);
    }
    if (r->p != (BIGNUM *)0x0) {
      BN_clear_free(r->p);
    }
    if (r->q != (BIGNUM *)0x0) {
      BN_clear_free(r->q);
    }
    if (r->dmp1 != (BIGNUM *)0x0) {
      BN_clear_free(r->dmp1);
    }
    if (r->dmq1 != (BIGNUM *)0x0) {
      BN_clear_free(r->dmq1);
    }
    if (r->iqmp != (BIGNUM *)0x0) {
      BN_clear_free(r->iqmp);
    }
    if (r->blinding != (BN_BLINDING *)0x0) {
      (*(code *)PTR_BN_BLINDING_free_006a984c)();
    }
    if (r->mt_blinding != (BN_BLINDING *)0x0) {
      (*(code *)PTR_BN_BLINDING_free_006a984c)();
    }
    if (r->bignum_data != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_locked_006a9850)();
    }
                    /* WARNING: Could not recover jumptable at 0x005104d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(r);
    return;
  }
  return;
}
