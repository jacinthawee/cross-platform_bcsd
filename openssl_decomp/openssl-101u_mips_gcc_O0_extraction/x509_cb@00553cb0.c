
undefined4 x509_cb(int param_1,int **param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
  piVar3 = *param_2;
  if (param_1 == 3) {
    (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(10,piVar3,piVar3 + 6);
    X509_CERT_AUX_free((X509_CERT_AUX *)piVar3[0x19]);
    ASN1_OCTET_STRING_free((ASN1_OCTET_STRING *)piVar3[0xe]);
    (*(code *)PTR_AUTHORITY_KEYID_free_006a8d00)(piVar3[0xf]);
    (*(code *)PTR_CRL_DIST_POINTS_free_006a8d04)(piVar3[0x11]);
    (*(code *)PTR_policy_cache_free_006a8d08)(piVar3[0x10]);
    (*(code *)PTR_GENERAL_NAMES_free_006a73a0)(piVar3[0x12]);
    (*(code *)PTR_NAME_CONSTRAINTS_free_006a8d0c)(piVar3[0x13]);
    if (piVar3[5] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      return 1;
    }
  }
  else {
    if (param_1 == 5) {
      if (piVar3[5] != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      iVar2 = (*(code *)PTR_X509_NAME_oneline_006a7010)(*(undefined4 *)(*piVar3 + 0x14),0,0);
      piVar3[5] = iVar2;
      return 1;
    }
    if (param_1 == 1) {
      piVar3[3] = 0;
      piVar3[5] = 0;
      piVar3[10] = 0;
      piVar3[8] = -1;
      piVar3[0xe] = 0;
      piVar3[0xf] = 0;
      piVar3[0x19] = 0;
      piVar3[0x11] = 0;
      (*(code *)puVar1)(10,piVar3,piVar3 + 6);
      return 1;
    }
  }
  return 1;
}

