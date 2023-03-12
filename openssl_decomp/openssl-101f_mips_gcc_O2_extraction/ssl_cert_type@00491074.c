
undefined4 ssl_cert_type(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (param_2 == (int *)0x0) {
    piVar2 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)();
    if (piVar2 == (int *)0x0) {
      uVar1 = 0xffffffff;
      goto LAB_004910e8;
    }
    iVar3 = *piVar2;
    uVar1 = 0;
    if (iVar3 == 6) goto LAB_004910e8;
    if (iVar3 == 0x74) {
      uVar1 = 2;
      goto LAB_004910e8;
    }
  }
  else {
    iVar3 = *param_2;
    if (iVar3 == 6) {
      return 0;
    }
    piVar2 = param_2;
    if (iVar3 == 0x74) {
      return 2;
    }
  }
  if (iVar3 == 0x198) {
    uVar1 = 5;
  }
  else if ((iVar3 == 0x32c) || (iVar3 == 0x352)) {
    uVar1 = 6;
  }
  else if (iVar3 == 0x32b) {
    uVar1 = 7;
  }
  else {
    uVar1 = 0xffffffff;
    if (iVar3 == 0x353) {
      uVar1 = 7;
    }
  }
  if (param_2 != (int *)0x0) {
    return uVar1;
  }
LAB_004910e8:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar2);
  return uVar1;
}

