
undefined4 trust_1oid(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)(param_2 + 100);
  if (piVar4 != (int *)0x0) {
    iVar2 = piVar4[1];
    iVar5 = *(int *)(param_1 + 0x10);
    if (iVar2 != 0) {
      iVar3 = 0;
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar2);
        if (iVar2 <= iVar3) break;
        uVar1 = (*(code *)PTR_sk_value_006a6e24)(piVar4[1],iVar3);
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar1);
        if (iVar5 == iVar2) {
          return 2;
        }
        iVar2 = piVar4[1];
        iVar3 = iVar3 + 1;
      }
    }
    iVar3 = *piVar4;
    iVar2 = 0;
    if (iVar3 != 0) {
      while( true ) {
        iVar3 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
        if (iVar3 <= iVar2) break;
        uVar1 = (*(code *)PTR_sk_value_006a6e24)(*piVar4,iVar2);
        iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar1);
        if (iVar5 == iVar3) {
          return 1;
        }
        iVar3 = *piVar4;
        iVar2 = iVar2 + 1;
      }
    }
  }
  return 3;
}
