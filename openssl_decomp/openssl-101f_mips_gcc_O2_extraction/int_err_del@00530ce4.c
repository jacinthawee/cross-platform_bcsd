
void int_err_del(void)

{
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x172);
  if (int_error_hash != (_LHASH *)0x0) {
    lh_free(int_error_hash);
    int_error_hash = (_LHASH *)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x00530d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x178);
  return;
}

