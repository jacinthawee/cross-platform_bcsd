
undefined4 b64_callback_ctrl(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x24) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00542504. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_BIO_callback_ctrl_006a9548)();
    return uVar1;
  }
  return 0;
}

