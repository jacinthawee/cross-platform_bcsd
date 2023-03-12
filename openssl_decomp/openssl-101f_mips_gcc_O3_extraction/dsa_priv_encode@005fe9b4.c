
undefined4 dsa_priv_encode(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int local_20;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar3 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  if (piVar3 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x74,0x41,"dsa_ameth.c",0x13a);
    if (local_20 != 0) goto LAB_005febcc;
  }
  else {
    iVar4 = (*(code *)PTR_i2d_DSAparams_006a8774)(*(undefined4 *)(param_2 + 0x14),piVar3 + 2);
    *piVar3 = iVar4;
    puVar1 = PTR_BN_to_ASN1_INTEGER_006a81f4;
    if (iVar4 < 1) {
      iVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(10,0x74,0x41,"dsa_ameth.c",0x141);
    }
    else {
      piVar3[1] = 0x10;
      iVar4 = (*(code *)puVar1)(*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x1c),0);
      if (iVar4 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(10,0x74,0x6d,"dsa_ameth.c",0x14b);
      }
      else {
        uVar5 = (*(code *)PTR_i2d_ASN1_INTEGER_006a94f4)(iVar4,&local_20);
        (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar4);
        uVar6 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x74);
        iVar7 = (*(code *)PTR_PKCS8_pkey_set0_006a98b8)(param_1,uVar6,0,0x10,piVar3,local_20,uVar5);
        if (iVar7 != 0) {
          uVar5 = 1;
          goto LAB_005feaf8;
        }
      }
    }
    if (local_20 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar3);
    if (iVar4 != 0) {
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar4);
      uVar5 = 0;
      goto LAB_005feaf8;
    }
  }
  uVar5 = 0;
LAB_005feaf8:
  while (local_1c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005febcc:
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    uVar5 = 0;
  }
  return uVar5;
}

