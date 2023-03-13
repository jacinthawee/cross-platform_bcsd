
undefined cert_crl(int param_1,X509_CRL *param_2,X509 *param_3)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined uVar2;
  X509_REVOKED *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (((*(byte *)(*(int *)(param_1 + 0x14) + 0xc) & 0x10) == 0) &&
     ((*(byte *)((int)&param_2->flags + 1) & 2) != 0)) {
    *(undefined4 *)(param_1 + 100) = 0x24;
    iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
    uVar2 = 0;
    if (iVar1 == 0) goto LAB_0815cb02;
  }
  iVar1 = X509_CRL_get0_by_cert(param_2,&local_14,param_3);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
    if (local_14->reason != 8) {
      *(undefined4 *)(param_1 + 100) = 0x17;
      iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
      uVar2 = iVar1 != 0;
    }
  }
LAB_0815cb02:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

