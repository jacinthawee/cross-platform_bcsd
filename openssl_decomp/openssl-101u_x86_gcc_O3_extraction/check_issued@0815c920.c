
undefined4 check_issued(int param_1,X509 *param_2,X509 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = X509_check_issued(param_3,param_2);
  if (iVar1 == 0) {
    return 1;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x14) + 0xc) & 1) == 0) {
    return 0;
  }
  *(int *)(param_1 + 100) = iVar1;
  *(X509 **)(param_1 + 0x68) = param_2;
  *(X509 **)(param_1 + 0x6c) = param_3;
                    /* WARNING: Could not recover jumptable at 0x0815c973. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(param_1 + 0x20))();
  return uVar2;
}
