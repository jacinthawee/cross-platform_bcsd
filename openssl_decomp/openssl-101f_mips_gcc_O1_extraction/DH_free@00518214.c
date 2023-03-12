
void DH_free(DH *dh)

{
  int iVar1;
  _func_1705 *p_Var2;
  
  if ((dh != (DH *)0x0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)
                        (&dh->references,0xffffffff,0x1a,"dh_lib.c",0xbf), iVar1 < 1)) {
    p_Var2 = dh->meth->finish;
    if (p_Var2 != (_func_1705 *)0x0) {
      (*p_Var2)(dh);
    }
    if (dh->engine != (ENGINE *)0x0) {
      ENGINE_finish(dh->engine);
    }
    (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(8,dh,&dh->ex_data);
    if (dh->p != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    if (dh->g != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    if (dh->q != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    if (dh->j != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    if (dh->seed != (uchar *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (dh->counter != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    if (dh->pub_key != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    if (dh->priv_key != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
                    /* WARNING: Could not recover jumptable at 0x00518390. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(dh);
    return;
  }
  return;
}

