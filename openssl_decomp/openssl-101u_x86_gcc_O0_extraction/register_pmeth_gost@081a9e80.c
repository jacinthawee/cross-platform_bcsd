
undefined4 register_pmeth_gost(int param_1,EVP_PKEY_METHOD **param_2,int param_3)

{
  EVP_PKEY_METHOD *pmeth;
  
  pmeth = EVP_PKEY_meth_new(param_1,param_3);
  *param_2 = pmeth;
  if (pmeth == (EVP_PKEY_METHOD *)0x0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    EVP_PKEY_meth_set_ctrl(pmeth,pkey_gost_ctrl,pkey_gost_ctrl94_str);
    EVP_PKEY_meth_set_keygen(*param_2,(keygen_init *)0x0,pkey_gost94cp_keygen);
    EVP_PKEY_meth_set_sign(*param_2,(sign_init *)0x0,pkey_gost94_cp_sign);
    EVP_PKEY_meth_set_verify(*param_2,(verify_init *)0x0,pkey_gost94_cp_verify);
    EVP_PKEY_meth_set_encrypt(*param_2,pkey_gost_encrypt_init,pkey_GOST94cp_encrypt);
    EVP_PKEY_meth_set_decrypt(*param_2,(decrypt_init *)0x0,pkey_GOST94cp_decrypt);
    EVP_PKEY_meth_set_derive(*param_2,pkey_gost_derive_init,pkey_gost94_derive);
    EVP_PKEY_meth_set_paramgen(*param_2,pkey_gost_paramgen_init,pkey_gost94_paramgen);
  }
  else {
    if (param_1 == 0x32f) {
      EVP_PKEY_meth_set_ctrl(pmeth,pkey_gost_mac_ctrl,pkey_gost_mac_ctrl_str);
      EVP_PKEY_meth_set_signctx(*param_2,pkey_gost_mac_signctx_init,pkey_gost_mac_signctx);
      EVP_PKEY_meth_set_keygen(*param_2,(keygen_init *)0x0,pkey_gost_mac_keygen);
      EVP_PKEY_meth_set_init(*param_2,pkey_gost_mac_init);
      EVP_PKEY_meth_set_cleanup(*param_2,pkey_gost_mac_cleanup);
      EVP_PKEY_meth_set_copy(*param_2,pkey_gost_mac_copy);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 0;
    }
    EVP_PKEY_meth_set_ctrl(pmeth,pkey_gost_ctrl,pkey_gost_ctrl01_str);
    EVP_PKEY_meth_set_sign(*param_2,(sign_init *)0x0,pkey_gost01_cp_sign);
    EVP_PKEY_meth_set_verify(*param_2,(verify_init *)0x0,pkey_gost01_cp_verify);
    EVP_PKEY_meth_set_keygen(*param_2,(keygen_init *)0x0,pkey_gost01cp_keygen);
    EVP_PKEY_meth_set_encrypt(*param_2,pkey_gost_encrypt_init,pkey_GOST01cp_encrypt);
    EVP_PKEY_meth_set_decrypt(*param_2,(decrypt_init *)0x0,pkey_GOST01cp_decrypt);
    EVP_PKEY_meth_set_derive(*param_2,pkey_gost_derive_init,pkey_gost2001_derive);
    EVP_PKEY_meth_set_paramgen(*param_2,pkey_gost_paramgen_init,pkey_gost01_paramgen);
  }
  EVP_PKEY_meth_set_init(*param_2,pkey_gost_init);
  EVP_PKEY_meth_set_cleanup(*param_2,pkey_gost_cleanup);
  EVP_PKEY_meth_set_copy(*param_2,pkey_gost_copy);
  return 1;
}

