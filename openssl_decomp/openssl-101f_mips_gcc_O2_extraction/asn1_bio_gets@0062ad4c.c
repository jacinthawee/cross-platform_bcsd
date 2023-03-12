
undefined4 asn1_bio_gets(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x24) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0062ad60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_BIO_gets_006a85d0)();
    return uVar1;
  }
  return 0;
}

