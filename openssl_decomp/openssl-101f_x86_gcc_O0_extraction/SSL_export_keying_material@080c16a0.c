
undefined4 SSL_export_keying_material(int *param_1)

{
  undefined4 uVar1;
  
  if (0x300 < *param_1) {
                    /* WARNING: Could not recover jumptable at 0x080c16d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)(param_1[2] + 100) + 0x34))();
    return uVar1;
  }
  return 0xffffffff;
}
