
void DSA_free(DSA *r)

{
  _func_1739 *p_Var1;
  int iVar2;
  
  if (r != (DSA *)0x0) {
    iVar2 = CRYPTO_add_lock(&r->references,-1,8,"dsa_lib.c",0xc9);
    if (iVar2 < 1) {
      p_Var1 = r->meth->finish;
      if (p_Var1 != (_func_1739 *)0x0) {
        (*p_Var1)(r);
      }
      if (r->engine != (ENGINE *)0x0) {
        ENGINE_finish(r->engine);
      }
      CRYPTO_free_ex_data(7,r,&r->ex_data);
      if (r->p != (BIGNUM *)0x0) {
        BN_clear_free(r->p);
      }
      if (r->q != (BIGNUM *)0x0) {
        BN_clear_free(r->q);
      }
      if (r->g != (BIGNUM *)0x0) {
        BN_clear_free(r->g);
      }
      if (r->pub_key != (BIGNUM *)0x0) {
        BN_clear_free(r->pub_key);
      }
      if (r->priv_key != (BIGNUM *)0x0) {
        BN_clear_free(r->priv_key);
      }
      if (r->kinv != (BIGNUM *)0x0) {
        BN_clear_free(r->kinv);
      }
      if (r->r != (BIGNUM *)0x0) {
        BN_clear_free(r->r);
      }
      CRYPTO_free(r);
      return;
    }
  }
  return;
}

