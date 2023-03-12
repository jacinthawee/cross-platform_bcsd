
void ssl_puts(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
                    /* WARNING: Could not recover jumptable at 0x004bce2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_write_006a7f14)(param_1,param_2,uVar1);
  return;
}

