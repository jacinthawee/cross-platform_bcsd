
int ec_GF2m_simple_invert(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)();
  if ((iVar1 == 0) && (*(int *)(param_2 + 0x1c) != 0)) {
    iVar1 = (*(code *)PTR_EC_POINT_make_affine_006a96ac)(param_1,param_2,param_3);
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005f38bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_BN_GF2m_add_006a96a8)(param_2 + 0x18,param_2 + 4);
      return iVar1;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}
