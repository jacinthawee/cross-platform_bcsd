
void __regparm1 hwcrhk_log_message(BIO *param_1_00,BIO **param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x523;
  CRYPTO_lock((int)param_1_00,9,(char *)0x15,(int)"e_chil.c");
  if ((param_1 != (BIO **)0x0) && (param_1_00 = *param_1, param_1_00 != (BIO *)0x0)) {
    param_1_00 = (BIO *)BIO_printf(param_1_00,"%s\n",param_2,uVar1);
  }
  CRYPTO_lock((int)param_1_00,10,(char *)0x15,(int)"e_chil.c");
  return;
}

