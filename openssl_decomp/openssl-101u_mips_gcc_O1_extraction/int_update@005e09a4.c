
bool int_update(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_HMAC_Update_006a7ad0)(*(int *)(*(int *)(param_1 + 0x10) + 0x14) + 0x14);
  return iVar1 != 0;
}

