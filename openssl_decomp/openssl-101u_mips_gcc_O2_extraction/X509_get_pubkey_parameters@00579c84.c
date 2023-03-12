
int X509_get_pubkey_parameters(EVP_PKEY *pkey,stack_st_X509 *chain)

{
  int iVar1;
  X509 *pXVar2;
  EVP_PKEY *pEVar3;
  int iVar4;
  undefined4 uVar5;
  EVP_PKEY *pEVar6;
  undefined4 uVar7;
  
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)();
    if (iVar1 == 0) {
      return 1;
    }
  }
  iVar1 = 0;
  do {
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(chain);
    if (iVar4 <= iVar1) {
      uVar7 = 0x6b;
      uVar5 = 0x78a;
LAB_00579d60:
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x6e,uVar7,"x509_vfy.c",uVar5);
      return 0;
    }
    pXVar2 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(chain,iVar1);
    pEVar3 = X509_get_pubkey(pXVar2);
    if (pEVar3 == (EVP_PKEY *)0x0) {
      uVar7 = 0x6c;
      uVar5 = 0x77e;
      goto LAB_00579d60;
    }
    iVar4 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(pEVar3);
    if (iVar4 == 0) {
      iVar4 = iVar1 + -1;
      if (-1 < iVar1 + -1) {
        do {
          iVar1 = iVar4 + -1;
          pXVar2 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(chain,iVar4);
          pEVar6 = X509_get_pubkey(pXVar2);
          (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(pEVar6,pEVar3);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar6);
          iVar4 = iVar1;
        } while (iVar1 != -1);
      }
      if (pkey != (EVP_PKEY *)0x0) {
        (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(pkey,pEVar3);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar3);
      return 1;
    }
    iVar1 = iVar1 + 1;
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar3);
  } while( true );
}

