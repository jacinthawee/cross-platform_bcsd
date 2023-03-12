
undefined4 ssl_fill_hello_random(int param_1,int param_2,undefined *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_4 < 4) {
    return 0;
  }
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x104) << 0x1a;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x104) << 0x19;
  }
  if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x00490d7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_RAND_bytes_006a7574)(param_3,param_4);
    return uVar2;
  }
  uVar2 = (*(code *)PTR_time_006a9adc)(0);
  param_3[3] = (char)uVar2;
  *param_3 = (char)((uint)uVar2 >> 0x18);
  param_3[1] = (char)((uint)uVar2 >> 0x10);
  param_3[2] = (char)((uint)uVar2 >> 8);
                    /* WARNING: Could not recover jumptable at 0x00490dd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)PTR_RAND_bytes_006a7574)(param_3 + 4,param_4 + -4);
  return uVar2;
}

