
uint rsa_priv_encode(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_18 = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_i2d_RSAPrivateKey_006a9ee0)(*(undefined4 *)(param_2 + 0x14),&local_18);
  if (iVar2 < 1) {
    iVar3 = 0x8a;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x8a,0x41,"rsa_ameth.c",0x87);
    uVar4 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(6);
    uVar4 = (*(code *)PTR_PKCS8_pkey_set0_006a98b8)(param_1,iVar3,0,5,0,local_18,iVar2);
    if (uVar4 == 0) {
      iVar3 = 0x8a;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x8a,0x41,"rsa_ameth.c",0x8e);
    }
    else {
      uVar4 = 1;
    }
  }
  if (local_14 == *(int *)puVar1) {
    return uVar4;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = (*(code *)PTR_BN_cmp_006a8a4c)
                    (*(undefined4 *)(*(int *)(iVar3 + 0x14) + 0x10),
                     *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x10));
  if (iVar5 != 0) {
    return 0;
  }
  iVar2 = (*(code *)PTR_BN_cmp_006a8a4c)
                    (*(undefined4 *)(*(int *)(iVar3 + 0x14) + 0x14),
                     *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x14));
  return (uint)(iVar2 == 0);
}
