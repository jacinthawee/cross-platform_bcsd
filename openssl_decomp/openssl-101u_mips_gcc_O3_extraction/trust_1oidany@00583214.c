
undefined4 trust_1oidany(int param_1,X509 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)(param_2->sha1_hash + 0xc);
  if (piVar4 == (int *)0x0) {
LAB_0058334c:
    X509_check_purpose(param_2,-1,0);
    if ((param_2->ex_flags & 0x20) == 0) {
      return 3;
    }
    return 1;
  }
  iVar1 = *piVar4;
  iVar3 = piVar4[1];
  if (iVar1 == 0) {
    if (iVar3 == 0) goto LAB_0058334c;
    iVar5 = *(int *)(param_1 + 0x10);
  }
  else {
    iVar5 = *(int *)(param_1 + 0x10);
    if (iVar3 == 0) goto LAB_005832b4;
  }
  iVar1 = 0;
  while( true ) {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
    if (iVar3 <= iVar1) break;
    uVar2 = (*(code *)PTR_sk_value_006a6e24)(piVar4[1],iVar1);
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar2);
    if (iVar5 == iVar3) {
      return 2;
    }
    iVar3 = piVar4[1];
    iVar1 = iVar1 + 1;
  }
  iVar1 = *piVar4;
  if (iVar1 == 0) {
    return 3;
  }
LAB_005832b4:
  iVar3 = 0;
  while( true ) {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(iVar1);
    if (iVar1 <= iVar3) {
      return 3;
    }
    uVar2 = (*(code *)PTR_sk_value_006a6e24)(*piVar4,iVar3);
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar2);
    if (iVar1 == iVar5) break;
    iVar1 = *piVar4;
    iVar3 = iVar3 + 1;
  }
  return 1;
}

