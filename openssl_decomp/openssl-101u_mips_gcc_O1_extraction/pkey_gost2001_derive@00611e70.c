
undefined4 pkey_gost2001_derive(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  uVar2 = (*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006a9824)(param_1);
  iVar3 = (*(code *)PTR_EVP_PKEY_CTX_get_data_006a95d0)(param_1);
  if (*(int *)(iVar3 + 8) == 0) {
    ERR_GOST_error(0x79,0x80,"gost2001_keyx.c",0x55);
    uVar1 = 0;
  }
  else {
    if (param_2 == 0) {
      *param_3 = 0x20;
      return 0x20;
    }
    uVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar2);
    uVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar2);
    uVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar1);
    uVar2 = VKO_compute_key_isra_0(param_2,uVar2,uVar1,*(undefined4 *)(iVar3 + 8));
    uVar1 = 1;
    *param_3 = uVar2;
  }
  return uVar1;
}

