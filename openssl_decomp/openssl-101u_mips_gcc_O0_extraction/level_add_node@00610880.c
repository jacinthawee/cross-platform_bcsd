
int * level_add_node(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xc,"pcy_node.c",0x75);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = param_2;
    piVar1[1] = param_3;
    piVar1[2] = 0;
    if (param_1 != 0) {
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)(param_2 + 4));
      if (iVar2 == 0x2ea) {
        if (*(int *)(param_1 + 8) != 0) goto LAB_006109a0;
        *(int **)(param_1 + 8) = piVar1;
      }
      else {
        iVar2 = *(int *)(param_1 + 4);
        if (iVar2 == 0) {
          iVar2 = (*(code *)PTR_sk_new_006a806c)(node_cmp);
          *(int *)(param_1 + 4) = iVar2;
          if (iVar2 == 0) goto LAB_006109a0;
        }
        iVar2 = (*(code *)PTR_sk_push_006a6fa8)(iVar2,piVar1);
        if (iVar2 == 0) goto LAB_006109a0;
      }
    }
    if (param_4 != 0) {
      iVar2 = *(int *)(param_4 + 8);
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
        *(int *)(param_4 + 8) = iVar2;
        if (iVar2 == 0) goto LAB_006109a0;
      }
      iVar2 = (*(code *)PTR_sk_push_006a6fa8)(iVar2,param_2);
      if (iVar2 == 0) {
LAB_006109a0:
        (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
        return (int *)0x0;
      }
    }
    if (param_3 == 0) {
      return piVar1;
    }
    *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 1;
  }
  return piVar1;
}

