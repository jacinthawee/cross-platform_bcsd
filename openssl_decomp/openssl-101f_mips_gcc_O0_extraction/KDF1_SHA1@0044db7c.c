
undefined4 KDF1_SHA1(void)

{
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  uint *in_a3;
  
  UNRECOVERED_JUMPTABLE = PTR_SHA1_006a8ad0;
  if (0x13 < *in_a3) {
                    /* WARNING: Could not recover jumptable at 0x0044db98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    *in_a3 = 0x14;
    uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0;
}

