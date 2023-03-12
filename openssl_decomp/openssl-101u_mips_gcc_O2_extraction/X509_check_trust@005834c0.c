
int X509_check_trust(X509 *x,int id,int flags)

{
  undefined *puVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  int local_34 [6];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = 1;
  if (id == -1) goto LAB_00583540;
  uVar4 = id - 1;
  if (uVar4 < 8) {
LAB_00583514:
    if (7 < (int)uVar4) goto LAB_005835b0;
    puVar3 = trstandard + uVar4 * 0x18;
  }
  else {
    local_34[0] = id;
    if (((trtable == 0) || (iVar2 = (*(code *)PTR_sk_find_006a8044)(trtable,local_34), iVar2 == -1))
       || (uVar4 = iVar2 + 8, uVar4 == 0xffffffff)) {
      iVar2 = (*(code *)default_trust)(id,x);
      goto LAB_00583540;
    }
    if (-1 < (int)uVar4) goto LAB_00583514;
    trap(0);
LAB_005835b0:
    puVar3 = (undefined1 *)(*(code *)PTR_sk_value_006a6e24)(trtable,uVar4 - 8);
  }
  iVar2 = (**(code **)(puVar3 + 8))(puVar3,x,flags);
LAB_00583540:
  if (local_1c == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (trtable != 0) {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)();
    return iVar2 + 8;
  }
  return 8;
}

