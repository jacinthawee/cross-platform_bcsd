
void DH_free(DH *dh)

{
  _func_1705 *p_Var1;
  int iVar2;
  
  if (dh != (DH *)0x0) {
    iVar2 = CRYPTO_add_lock(&dh->references,-1,0x1a,"dh_lib.c",0xbf);
    if (iVar2 < 1) {
      p_Var1 = dh->meth->finish;
      if (p_Var1 != (_func_1705 *)0x0) {
        (*p_Var1)(dh);
      }
      if (dh->engine != (ENGINE *)0x0) {
        ENGINE_finish(dh->engine);
      }
      CRYPTO_free_ex_data(8,dh,&dh->ex_data);
      if (dh->p != (BIGNUM *)0x0) {
        BN_clear_free(dh->p);
      }
      if (dh->g != (BIGNUM *)0x0) {
        BN_clear_free(dh->g);
      }
      if (dh->q != (BIGNUM *)0x0) {
        BN_clear_free(dh->q);
      }
      if (dh->j != (BIGNUM *)0x0) {
        BN_clear_free(dh->j);
      }
      if (dh->seed != (uchar *)0x0) {
        CRYPTO_free(dh->seed);
      }
      if (dh->counter != (BIGNUM *)0x0) {
        BN_clear_free(dh->counter);
      }
      if (dh->pub_key != (BIGNUM *)0x0) {
        BN_clear_free(dh->pub_key);
      }
      if (dh->priv_key != (BIGNUM *)0x0) {
        BN_clear_free(dh->priv_key);
      }
      CRYPTO_free(dh);
      return;
    }
  }
  return;
}

