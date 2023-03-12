
int pkey_ec_paramgen(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x14);
  if (*piVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdb,0x8b,"ec_pmeth.c",0x113);
    return 0;
  }
  iVar1 = (*(code *)PTR_EC_KEY_new_006a82a8)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar1,*piVar3);
    if (iVar2 == 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)(iVar1);
      return 0;
    }
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_2,0x198,iVar1);
    return iVar2;
  }
  return 0;
}

