
RSA * tmp_rsa_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  BIGNUM *a;
  int iVar1;
  
  if (rsa_tmp_19414 != (RSA *)0x0) {
    return rsa_tmp_19414;
  }
  a = BN_new();
  if (a == (BIGNUM *)0x0) {
    BIO_printf(bio_err,"Allocation error in generating RSA key\n");
    return rsa_tmp_19414;
  }
  if (rsa_tmp_19414 != (RSA *)0x0) {
    return rsa_tmp_19414;
  }
  if (s_quiet == 0) {
    BIO_printf(bio_err,"Generating temp (%d bit) RSA key...",param_3);
    BIO_ctrl(bio_err,0xb,0,(void *)0x0);
  }
  iVar1 = BN_set_word(a,0x10001);
  if (iVar1 == 0) {
LAB_08069aa0:
    if (rsa_tmp_19414 != (RSA *)0x0) {
      RSA_free(rsa_tmp_19414);
    }
  }
  else {
    rsa_tmp_19414 = RSA_new();
    if (rsa_tmp_19414 != (RSA *)0x0) {
      iVar1 = RSA_generate_key_ex(rsa_tmp_19414,param_3,a,(BN_GENCB *)0x0);
      if (iVar1 != 0) goto LAB_08069abf;
      goto LAB_08069aa0;
    }
  }
  rsa_tmp_19414 = (RSA *)0x0;
LAB_08069abf:
  if (s_quiet == 0) {
    BIO_printf(bio_err,"\n");
    BIO_ctrl(bio_err,0xb,0,(void *)0x0);
  }
  BN_free(a);
  return rsa_tmp_19414;
}
