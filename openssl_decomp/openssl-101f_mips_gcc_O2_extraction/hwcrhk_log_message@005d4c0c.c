
void hwcrhk_log_message(int *param_1,undefined4 param_2)

{
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x15,"e_chil.c",0x531);
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    (*(code *)PTR_BIO_printf_006a7f38)(*param_1,"%s\n",param_2);
  }
                    /* WARNING: Could not recover jumptable at 0x005d4c9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x15,"e_chil.c",0x538);
  return;
}

