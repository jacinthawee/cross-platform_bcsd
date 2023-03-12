
undefined4
ec_GFp_mont_field_encode(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xa0);
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)(param_2,param_3,iVar1 + 4,iVar1,param_4);
    return uVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x86,0x6f,"ecp_mont.c",0x117);
  return 0;
}

