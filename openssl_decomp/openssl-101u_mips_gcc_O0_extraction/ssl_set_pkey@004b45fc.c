
undefined4 ssl_set_pkey(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = (*(code *)PTR_ssl_cert_type_006a8058)(0);
  if (iVar1 < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc1,0xf7,&DAT_00649450,0xb4);
    uVar3 = 0;
  }
  else {
    if (param_1[iVar1 * 3 + 0xc] != 0) {
      iVar2 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc1,0x41,&DAT_00649450,0xbc);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(0);
        return 0;
      }
      (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(iVar2,param_2);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar2);
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      if (((*param_2 != 6) ||
          (uVar4 = (*(code *)PTR_RSA_flags_006a83c8)(param_2[5]), (uVar4 & 1) == 0)) &&
         (iVar2 = (*(code *)PTR_X509_check_private_key_006a707c)(param_1[iVar1 * 3 + 0xc],param_2),
         iVar2 == 0)) {
        (*(code *)PTR_X509_free_006a6e90)(param_1[iVar1 * 3 + 0xc]);
        param_1[iVar1 * 3 + 0xc] = 0;
        return 0;
      }
    }
    if (param_1[iVar1 * 3 + 0xd] != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)();
    }
    CRYPTO_add_lock(param_2 + 2,1,10,"ssl_rsa.c",0xda);
    uVar3 = 1;
    param_1[iVar1 * 3 + 0xd] = (int)param_2;
    param_1[1] = 0;
    *param_1 = (int)(param_1 + iVar1 * 3 + 0xc);
  }
  return uVar3;
}

