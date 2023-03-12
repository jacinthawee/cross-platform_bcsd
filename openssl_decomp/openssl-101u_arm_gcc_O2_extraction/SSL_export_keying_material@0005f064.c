
undefined4 SSL_export_keying_material(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1 + -0x100;
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  if (0x300 < *param_1) {
    iVar2 = 0;
  }
  if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0005f08a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)(param_1[2] + 100) + 0x34))();
    return uVar1;
  }
  return 0xffffffff;
}

