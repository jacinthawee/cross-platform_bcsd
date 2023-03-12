
undefined4 register_pmeth_gost(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_meth_new_006aa724)(param_1,param_3);
  *param_2 = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    (*(code *)PTR_EVP_PKEY_meth_set_ctrl_006aa728)(iVar1,pkey_gost_ctrl,pkey_gost_ctrl94_str);
    (*(code *)PTR_EVP_PKEY_meth_set_keygen_006aa730)(*param_2,0,pkey_gost94cp_keygen);
    (*(code *)PTR_EVP_PKEY_meth_set_sign_006aa740)(*param_2,0,pkey_gost94_cp_sign);
    (*(code *)PTR_EVP_PKEY_meth_set_verify_006aa744)(*param_2,0,pkey_gost94_cp_verify);
    (*(code *)PTR_EVP_PKEY_meth_set_encrypt_006aa748)
              (*param_2,pkey_gost_encrypt_init,PTR_pkey_GOST94cp_encrypt_006aa764);
    (*(code *)PTR_EVP_PKEY_meth_set_decrypt_006aa750)(*param_2,0,PTR_pkey_GOST94cp_decrypt_006aa768)
    ;
    (*(code *)PTR_EVP_PKEY_meth_set_derive_006aa758)
              (*param_2,pkey_gost_derive_init,PTR_pkey_gost94_derive_006aa76c);
    (*(code *)PTR_EVP_PKEY_meth_set_paramgen_006aa760)
              (*param_2,pkey_gost_paramgen_init,pkey_gost94_paramgen);
  }
  else {
    if (param_1 == 0x32f) {
      (*(code *)PTR_EVP_PKEY_meth_set_ctrl_006aa728)
                (iVar1,pkey_gost_mac_ctrl,pkey_gost_mac_ctrl_str);
      (*(code *)PTR_EVP_PKEY_meth_set_signctx_006aa72c)
                (*param_2,pkey_gost_mac_signctx_init,pkey_gost_mac_signctx);
      (*(code *)PTR_EVP_PKEY_meth_set_keygen_006aa730)(*param_2,0,pkey_gost_mac_keygen);
      (*(code *)PTR_EVP_PKEY_meth_set_init_006aa734)(*param_2,pkey_gost_mac_init);
      (*(code *)PTR_EVP_PKEY_meth_set_cleanup_006aa738)(*param_2,pkey_gost_mac_cleanup);
      (*(code *)PTR_EVP_PKEY_meth_set_copy_006aa73c)(*param_2,pkey_gost_mac_copy);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 0;
    }
    (*(code *)PTR_EVP_PKEY_meth_set_ctrl_006aa728)(iVar1,pkey_gost_ctrl,pkey_gost_ctrl01_str);
    (*(code *)PTR_EVP_PKEY_meth_set_sign_006aa740)(*param_2,0,pkey_gost01_cp_sign);
    (*(code *)PTR_EVP_PKEY_meth_set_verify_006aa744)(*param_2,0,pkey_gost01_cp_verify);
    (*(code *)PTR_EVP_PKEY_meth_set_keygen_006aa730)(*param_2,0,pkey_gost01cp_keygen);
    (*(code *)PTR_EVP_PKEY_meth_set_encrypt_006aa748)
              (*param_2,pkey_gost_encrypt_init,PTR_pkey_GOST01cp_encrypt_006aa74c);
    (*(code *)PTR_EVP_PKEY_meth_set_decrypt_006aa750)(*param_2,0,PTR_pkey_GOST01cp_decrypt_006aa754)
    ;
    (*(code *)PTR_EVP_PKEY_meth_set_derive_006aa758)
              (*param_2,pkey_gost_derive_init,PTR_pkey_gost2001_derive_006aa75c);
    (*(code *)PTR_EVP_PKEY_meth_set_paramgen_006aa760)
              (*param_2,pkey_gost_paramgen_init,pkey_gost01_paramgen);
  }
  (*(code *)PTR_EVP_PKEY_meth_set_init_006aa734)(*param_2,pkey_gost_init);
  (*(code *)PTR_EVP_PKEY_meth_set_cleanup_006aa738)(*param_2,pkey_gost_cleanup);
  (*(code *)PTR_EVP_PKEY_meth_set_copy_006aa73c)(*param_2,pkey_gost_copy);
  return 1;
}

