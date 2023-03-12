
undefined4 dh_priv_encode(undefined4 param_1,int param_2)

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
    ERR_put_error(5,0x6f,0x41,"dh_ameth.c",0xf7);
    if (local_20 != 0) goto LAB_00518b1c;
  }
  else {
    iVar4 = i2d_DHparams(*(DH **)(param_2 + 0x14),(uchar **)(piVar3 + 2));
    *piVar3 = iVar4;
    puVar1 = PTR_BN_to_ASN1_INTEGER_006a81f4;
    if (iVar4 < 1) {
      iVar4 = 0;
      ERR_put_error(5,0x6f,0x41,"dh_ameth.c",0xfe);
    }
    else {
      piVar3[1] = 0x10;
      iVar4 = (*(code *)puVar1)(*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x18),0);
      if (iVar4 == 0) {
        ERR_put_error(5,0x6f,0x6a,"dh_ameth.c",0x108);
      }
      else {
        uVar5 = (*(code *)PTR_i2d_ASN1_INTEGER_006a94f4)(iVar4,&local_20);
        (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar4);
        uVar6 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x1c);
        iVar7 = (*(code *)PTR_PKCS8_pkey_set0_006a98b8)(param_1,uVar6,0,0x10,piVar3,local_20,uVar5);
        if (iVar7 != 0) {
          uVar5 = 1;
          goto LAB_00518a48;
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
      goto LAB_00518a48;
    }
  }
  uVar5 = 0;
LAB_00518a48:
  while (local_1c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00518b1c:
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    uVar5 = 0;
  }
  return uVar5;
}

