
undefined4 ec_GFp_mont_field_decode(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00627de4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_BN_from_montgomery_006a9684)(param_2,param_3,*(int *)(param_1 + 0xa0));
    return uVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x85,0x6f,"ecp_mont.c",0x130);
  return 0;
}
