
int * level_find_node(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1 + 4));
    if (iVar1 <= iVar3) {
      return (int *)0x0;
    }
    iVar1 = iVar3 + 1;
    piVar2 = (int *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(param_1 + 4),iVar3);
    iVar3 = iVar1;
  } while ((piVar2[1] != param_2) ||
          (iVar1 = (*(code *)PTR_OBJ_cmp_006a9de4)(*(undefined4 *)(*piVar2 + 4),param_3), iVar1 != 0
          ));
  return piVar2;
}

