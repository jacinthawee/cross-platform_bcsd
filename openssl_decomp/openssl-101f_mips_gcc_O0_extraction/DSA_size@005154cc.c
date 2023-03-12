
int DSA_size(DSA *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_a3;
  int local_20;
  undefined4 local_1c;
  undefined *local_18;
  undefined local_10 [4];
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = BN_num_bits(param_1->q);
  local_1c = 2;
  local_20 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    local_20 = iVar2 + 0xe;
  }
  local_10[0] = 0xff;
  local_18 = local_10;
  local_20 = local_20 >> 3;
  iVar2 = (*(code *)PTR_i2d_ASN1_INTEGER_006a94f4)(&local_20,0);
  uVar4 = 0x10;
  iVar2 = iVar2 << 1;
  iVar3 = (*(code *)PTR_ASN1_object_size_006a94fc)(1,iVar2,0x10);
  if (local_c == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_CRYPTO_get_ex_new_index_006a947c)(7,iVar3,iVar2,uVar4,in_a3,&_gp,&_gp);
  return iVar2;
}

