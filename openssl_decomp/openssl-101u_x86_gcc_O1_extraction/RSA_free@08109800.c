
void RSA_free(RSA *r)

{
  _func_1625 *p_Var1;
  int iVar2;
  
  if (r != (RSA *)0x0) {
    iVar2 = CRYPTO_add_lock(&r->references,-1,9,"rsa_lib.c",0xd7);
    if (iVar2 < 1) {
      p_Var1 = r->meth->finish;
      if (p_Var1 != (_func_1625 *)0x0) {
        (*p_Var1)(r);
      }
      if (r->engine != (ENGINE *)0x0) {
        ENGINE_finish(r->engine);
      }
      CRYPTO_free_ex_data(6,r,&r->ex_data);
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
        BN_BLINDING_free(r->blinding);
      }
      if (r->mt_blinding != (BN_BLINDING *)0x0) {
        BN_BLINDING_free(r->mt_blinding);
      }
      if (r->bignum_data != (char *)0x0) {
        CRYPTO_free_locked(r->bignum_data);
      }
      CRYPTO_free(r);
      return;
    }
  }
  return;
}

