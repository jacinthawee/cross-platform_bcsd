
undefined4 ssl_set_cert(int *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  iVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)(param_2);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbf,0x10c,&DAT_00649ed0,0x192);
    return 0;
  }
  iVar3 = (*(code *)PTR_ssl_cert_type_006a91a8)(param_2,iVar2);
  if (iVar3 < 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbf,0xf7,&DAT_00649ed0,0x199);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
    return 0;
  }
  if (param_1[iVar3 * 3 + 0xd] != 0) {
    (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(iVar2);
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
    piVar6 = (int *)param_1[iVar3 * 3 + 0xd];
    if (*piVar6 == 6) {
      uVar5 = (*(code *)PTR_RSA_flags_006a94e0)(piVar6[5]);
      if ((uVar5 & 1) != 0) goto LAB_004b76f0;
      piVar6 = (int *)param_1[iVar3 * 3 + 0xd];
    }
    iVar4 = (*(code *)PTR_X509_check_private_key_006a817c)(param_2,piVar6);
    if (iVar4 == 0) {
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(param_1[iVar3 * 3 + 0xd]);
      puVar1 = PTR_ERR_clear_error_006a7fe0;
      param_1[iVar3 * 3 + 0xd] = 0;
      (*(code *)puVar1)();
    }
  }
LAB_004b76f0:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
  if (param_1[iVar3 * 3 + 0xc] != 0) {
    (*(code *)PTR_X509_free_006a7f90)();
  }
  CRYPTO_add_lock((int *)(param_2 + 0x10),1,3,"ssl_rsa.c",0x1bd);
  param_1[iVar3 * 3 + 0xc] = param_2;
  param_1[1] = 0;
  *param_1 = (int)(param_1 + iVar3 * 3 + 0xc);
  return 1;
}

