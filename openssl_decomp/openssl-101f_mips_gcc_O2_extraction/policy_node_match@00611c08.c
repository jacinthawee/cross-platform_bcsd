
bool policy_node_match(int param_1,uint **param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  uint *puVar5;
  
  puVar5 = *param_2;
  if (((*(uint *)(param_1 + 0xc) & 0x400) == 0) && (iVar3 = 0, (*puVar5 & 3) != 0)) {
    while( true ) {
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(puVar5[3]);
      bVar4 = iVar3 < iVar1;
      if (!bVar4) break;
      uVar2 = (*(code *)PTR_sk_value_006a7f24)(puVar5[3],iVar3);
      iVar1 = (*(code *)PTR_OBJ_cmp_006a9de4)(uVar2,param_3);
      iVar3 = iVar3 + 1;
      if (iVar1 == 0) {
        return true;
      }
    }
  }
  else {
    iVar3 = (*(code *)PTR_OBJ_cmp_006a9de4)(puVar5[1],param_3);
    bVar4 = iVar3 == 0;
  }
  return bVar4;
}

