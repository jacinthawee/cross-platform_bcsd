
undefined4 register_pmeth_gost(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_meth_new_006a9618)(param_1,param_3);
  *param_2 = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    (*(code *)PTR_EVP_PKEY_meth_set_ctrl_006a961c)(iVar1,pkey_gost_ctrl,pkey_gost_ctrl94_str);
    (*(code *)PTR_EVP_PKEY_meth_set_keygen_006a9624)(*param_2,0,pkey_gost94cp_keygen);
    (*(code *)PTR_EVP_PKEY_meth_set_sign_006a9634)(*param_2,0,pkey_gost94_cp_sign);
    (*(code *)PTR_EVP_PKEY_meth_set_verify_006a9638)(*param_2,0,pkey_gost94_cp_verify);
    (*(code *)PTR_EVP_PKEY_meth_set_encrypt_006a963c)
              (*param_2,pkey_gost_encrypt_init,PTR_pkey_GOST94cp_encrypt_006a9658);
    (*(code *)PTR_EVP_PKEY_meth_set_decrypt_006a9644)(*param_2,0,PTR_pkey_GOST94cp_decrypt_006a965c)
    ;
    (*(code *)PTR_EVP_PKEY_meth_set_derive_006a964c)
              (*param_2,pkey_gost_derive_init,PTR_pkey_gost94_derive_006a9660);
    (*(code *)PTR_EVP_PKEY_meth_set_paramgen_006a9654)
              (*param_2,pkey_gost_paramgen_init,pkey_gost94_paramgen);
  }
  else {
    if (param_1 == 0x32f) {
      (*(code *)PTR_EVP_PKEY_meth_set_ctrl_006a961c)
                (iVar1,pkey_gost_mac_ctrl,pkey_gost_mac_ctrl_str);
      (*(code *)PTR_EVP_PKEY_meth_set_signctx_006a9620)
                (*param_2,pkey_gost_mac_signctx_init,pkey_gost_mac_signctx);
      (*(code *)PTR_EVP_PKEY_meth_set_keygen_006a9624)(*param_2,0,pkey_gost_mac_keygen);
      (*(code *)PTR_EVP_PKEY_meth_set_init_006a9628)(*param_2,pkey_gost_mac_init);
      (*(code *)PTR_EVP_PKEY_meth_set_cleanup_006a962c)(*param_2,pkey_gost_mac_cleanup);
      (*(code *)PTR_EVP_PKEY_meth_set_copy_006a9630)(*param_2,pkey_gost_mac_copy);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 0;
    }
    (*(code *)PTR_EVP_PKEY_meth_set_ctrl_006a961c)(iVar1,pkey_gost_ctrl,pkey_gost_ctrl01_str);
    (*(code *)PTR_EVP_PKEY_meth_set_sign_006a9634)(*param_2,0,pkey_gost01_cp_sign);
    (*(code *)PTR_EVP_PKEY_meth_set_verify_006a9638)(*param_2,0,pkey_gost01_cp_verify);
    (*(code *)PTR_EVP_PKEY_meth_set_keygen_006a9624)(*param_2,0,pkey_gost01cp_keygen);
    (*(code *)PTR_EVP_PKEY_meth_set_encrypt_006a963c)
              (*param_2,pkey_gost_encrypt_init,PTR_pkey_GOST01cp_encrypt_006a9640);
    (*(code *)PTR_EVP_PKEY_meth_set_decrypt_006a9644)(*param_2,0,PTR_pkey_GOST01cp_decrypt_006a9648)
    ;
    (*(code *)PTR_EVP_PKEY_meth_set_derive_006a964c)
              (*param_2,pkey_gost_derive_init,PTR_pkey_gost2001_derive_006a9650);
    (*(code *)PTR_EVP_PKEY_meth_set_paramgen_006a9654)
              (*param_2,pkey_gost_paramgen_init,pkey_gost01_paramgen);
  }
  (*(code *)PTR_EVP_PKEY_meth_set_init_006a9628)(*param_2,pkey_gost_init);
  (*(code *)PTR_EVP_PKEY_meth_set_cleanup_006a962c)(*param_2,pkey_gost_cleanup);
  (*(code *)PTR_EVP_PKEY_meth_set_copy_006a9630)(*param_2,pkey_gost_copy);
  return 1;
}

