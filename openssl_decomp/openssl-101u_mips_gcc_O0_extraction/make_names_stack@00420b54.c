
int make_names_stack(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = (*(code *)PTR_sk_new_null_006a6fa4)();
  if (iVar1 != 0) {
    iVar6 = 0;
    do {
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(param_1);
      if (iVar2 <= iVar6) {
        return iVar1;
      }
      uVar3 = (*(code *)PTR_sk_value_006a6e24)(param_1,iVar6);
      iVar2 = (*(code *)PTR_a2i_GENERAL_NAME_006a7398)(0,0,0,1,uVar3,0);
      if (iVar2 == 0) {
        iVar4 = 0;
        goto LAB_00420c64;
      }
      iVar4 = (*(code *)PTR_GENERAL_NAMES_new_006a739c)();
      if ((iVar4 == 0) || (iVar5 = (*(code *)PTR_sk_push_006a6fa8)(iVar4,iVar2), iVar5 == 0))
      goto LAB_00420c64;
      iVar2 = (*(code *)PTR_sk_push_006a6fa8)(iVar1,iVar4);
      iVar6 = iVar6 + 1;
    } while (iVar2 != 0);
    iVar2 = 0;
LAB_00420c64:
    (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_GENERAL_NAMES_free_006a73a0);
    if (iVar4 != 0) {
      (*(code *)PTR_GENERAL_NAMES_free_006a73a0)(iVar4);
    }
    if (iVar2 != 0) {
      (*(code *)PTR_GENERAL_NAME_free_006a73a4)(iVar2);
      return 0;
    }
  }
  return 0;
}

