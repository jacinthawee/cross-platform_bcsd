
bool ec_GFp_mont_field_set_to_one(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xa4) != 0) {
    iVar1 = (*(code *)PTR_BN_copy_006a8450)(param_2,*(int *)(param_1 + 0xa4));
    return iVar1 != 0;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd1,0x6f,"ecp_mont.c",0x12d);
  return false;
}

