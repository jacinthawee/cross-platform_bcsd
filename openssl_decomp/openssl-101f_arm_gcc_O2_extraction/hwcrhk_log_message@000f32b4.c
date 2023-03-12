
void hwcrhk_log_message(BIO **param_1,undefined4 param_2)

{
  CRYPTO_lock(9,0x15,"e_chil.c",0x531);
  if ((param_1 != (BIO **)0x0) && (*param_1 != (BIO *)0x0)) {
    BIO_printf(*param_1,"%s\n",param_2);
  }
  CRYPTO_lock(10,0x15,"e_chil.c",0x538);
  return;
}

