
undefined4 ec_GFp_simple_invert(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)();
  if ((iVar1 == 0) && (*(int *)(param_2 + 0x1c) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0062f7f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_BN_usub_006a85b0)(param_2 + 0x18,param_1 + 0x48);
    return uVar2;
  }
  return 1;
}

