
undefined4 ssl_set_pkey(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (*(code *)PTR_ssl_cert_type_006a91a8)(0);
  if (iVar1 < 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc1,0xf7,&DAT_00649ed0,0xbd);
    uVar2 = 0;
  }
  else {
    if (param_1[iVar1 * 3 + 0xc] != 0) {
      uVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)();
      (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(uVar2,param_2);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar2);
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      if ((*param_2 != 6) ||
         (uVar4 = (*(code *)PTR_RSA_flags_006a94e0)(param_2[5]), (uVar4 & 1) == 0)) {
        iVar3 = (*(code *)PTR_X509_check_private_key_006a817c)(param_1[iVar1 * 3 + 0xc],param_2);
        if (iVar3 == 0) {
          (*(code *)PTR_X509_free_006a7f90)(param_1[iVar1 * 3 + 0xc]);
          param_1[iVar1 * 3 + 0xc] = 0;
          return 0;
        }
      }
    }
    if (param_1[iVar1 * 3 + 0xd] != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a7f78)();
    }
    CRYPTO_add_lock(param_2 + 2,1,10,"ssl_rsa.c",0xdb);
    uVar2 = 1;
    param_1[iVar1 * 3 + 0xd] = (int)param_2;
    param_1[1] = 0;
    *param_1 = (int)(param_1 + iVar1 * 3 + 0xc);
  }
  return uVar2;
}

