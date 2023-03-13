
int ECDSA_size(EC_KEY *eckey)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int in_a1;
  undefined4 in_a2;
  undefined4 in_a3;
  int local_28;
  undefined4 local_24;
  undefined *local_20;
  undefined local_18 [4];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (eckey != (EC_KEY *)0x0) {
    iVar2 = (*(code *)PTR_EC_KEY_get0_group_006a7690)();
    if (iVar2 != 0) {
      iVar3 = (*(code *)PTR_BN_new_006a71b4)();
      if (iVar3 != 0) {
        in_a2 = 0;
        in_a1 = iVar3;
        iVar2 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar2,iVar3,0);
        if (iVar2 == 0) {
          (*(code *)PTR_BN_clear_free_006a7fa8)(iVar3);
        }
        else {
          iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar3);
          local_24 = 2;
          local_28 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            local_28 = iVar2 + 0xe;
          }
          local_18[0] = 0xff;
          local_20 = local_18;
          local_28 = local_28 >> 3;
          in_a1 = (*(code *)PTR_i2d_ASN1_INTEGER_006a83dc)(&local_28,0);
          in_a2 = 0x10;
          in_a1 = in_a1 << 1;
          iVar2 = (*(code *)PTR_ASN1_object_size_006a83e4)(1,in_a1,0x10);
          (*(code *)PTR_BN_clear_free_006a7fa8)(iVar3);
        }
        goto LAB_005febec;
      }
    }
  }
  iVar2 = 0;
LAB_005febec:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_CRYPTO_get_ex_new_index_006a835c)(0xc,iVar2,in_a1,in_a2,in_a3,&_gp,&_gp);
  return iVar2;
}

