
undefined4 cert_crl(int param_1,X509_CRL *param_2,X509 *param_3)

{
  int iVar1;
  X509_REVOKED *local_14;
  
  if (param_2->flags << 0x16 < 0) {
    if ((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x10) != 0) {
      return 1;
    }
    *(undefined4 *)(param_1 + 100) = 0x24;
    iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = X509_CRL_get0_by_cert(param_2,&local_14,param_3);
  if (iVar1 == 0) {
    return 1;
  }
  if (local_14->reason != 8) {
    *(undefined4 *)(param_1 + 100) = 0x17;
    iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  return 2;
}

