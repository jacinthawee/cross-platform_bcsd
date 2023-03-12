
undefined4 dsa_pub_encode(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  code *pcVar8;
  undefined auStack_74 [4];
  undefined4 uStack_70;
  undefined4 uStack_6c;
  int iStack_68;
  undefined4 *puStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  int iStack_54;
  int *piStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  code *pcStack_44;
  int local_30;
  int local_2c;
  undefined *local_28;
  int local_20;
  int local_1c;
  
  puStack_4c = PTR___stack_chk_guard_006aabf0;
  puVar1 = PTR_i2d_DSAPublicKey_006aa860;
  local_28 = &_gp;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_54 = *(int *)(param_2 + 0x14);
  if ((((*(int *)(param_2 + 0x18) == 0) || (*(int *)(iStack_54 + 0xc) == 0)) ||
      (*(int *)(iStack_54 + 0x10) == 0)) || (*(int *)(iStack_54 + 0x14) == 0)) {
    *(undefined4 *)(iStack_54 + 8) = 0;
    uVar7 = 0xffffffff;
    iStack_54 = (*(code *)puVar1)(iStack_54,&local_20);
    piStack_50 = (int *)0x0;
    if (iStack_54 < 1) goto LAB_005ff0b8;
LAB_005ff168:
    uVar6 = (**(code **)(local_28 + -0x7ca0))(0x74);
    local_30 = local_20;
    local_2c = iStack_54;
    iVar2 = (**(code **)(local_28 + -0x6618))(param_1,uVar6,uVar7,piStack_50);
    if (iVar2 == 0) goto LAB_005ff0e0;
    uVar7 = 1;
  }
  else {
    piStack_50 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    iVar2 = (**(code **)(local_28 + -0x776c))(iStack_54,piStack_50 + 2);
    *piStack_50 = iVar2;
    if (iVar2 < 1) {
      local_30 = 0x9a;
      uVar6 = 0x76;
      (**(code **)(local_28 + -0x6eb0))(10,0x76,0x41,"dsa_ameth.c");
      if (local_20 != 0) {
        piStack_50 = (int *)0x0;
LAB_005ff0ec:
        (**(code **)(local_28 + -0x7f58))();
        goto LAB_005ff0fc;
      }
    }
    else {
      pcVar8 = *(code **)(local_28 + -0x5680);
      *(undefined4 *)(iStack_54 + 8) = 0;
      uVar7 = 0x10;
      iStack_54 = (*pcVar8)(iStack_54,&local_20);
      if (0 < iStack_54) goto LAB_005ff168;
LAB_005ff0b8:
      local_30 = 0xa9;
      uVar6 = 0x76;
      (**(code **)(local_28 + -0x6eb0))(10,0x76,0x41,"dsa_ameth.c");
LAB_005ff0e0:
      if (local_20 != 0) goto LAB_005ff0ec;
LAB_005ff0fc:
      if (piStack_50 != (int *)0x0) {
        (**(code **)(local_28 + -0x6624))(piStack_50);
      }
    }
    uVar7 = 0;
  }
  if (local_1c == *(int *)puStack_4c) {
    return uVar7;
  }
  pcStack_44 = dsa_pub_decode;
  iVar2 = local_1c;
  (**(code **)(local_28 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_48 = param_1;
  iVar3 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)(0,auStack_74,&uStack_6c,&uStack_60,uVar6);
  if (iVar3 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&iStack_68,&puStack_64,uStack_60);
    if (iStack_68 == 0x10) {
      uStack_70 = puStack_64[2];
      iVar3 = (*(code *)PTR_d2i_DSAparams_006a863c)(0,&uStack_70,*puStack_64);
      if (iVar3 != 0) {
LAB_005ff2f8:
        iVar4 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(0,auStack_74,uStack_6c);
        if (iVar4 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,0x68,"dsa_ameth.c",0x73);
        }
        else {
          iVar5 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar4,0);
          *(int *)(iVar3 + 0x18) = iVar5;
          if (iVar5 != 0) {
            (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar4);
            (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,0x74,iVar3);
            uVar7 = 1;
            goto LAB_005ff254;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,0x6c,"dsa_ameth.c",0x79);
          (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar4);
        }
        (*(code *)PTR_DSA_free_006a862c)(iVar3);
        uVar7 = 0;
        goto LAB_005ff254;
      }
      uVar6 = 0x68;
      uVar7 = 0x5e;
    }
    else if ((iStack_68 == 5) || (iStack_68 == -1)) {
      iVar3 = (*(code *)PTR_DSA_new_006a8624)();
      if (iVar3 != 0) goto LAB_005ff2f8;
      uVar6 = 0x41;
      uVar7 = 0x67;
    }
    else {
      uVar6 = 0x69;
      uVar7 = 0x6d;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,uVar6,"dsa_ameth.c",uVar7);
  }
  uVar7 = 0;
LAB_005ff254:
  if (iStack_5c == *(int *)puVar1) {
    return uVar7;
  }
  iVar2 = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_d2i_DSAPrivateKey_006a9f3c)(0);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x7a,10,"dsa_ameth.c",0x215);
    return 0;
  }
  (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,0x74,iVar3);
  return 1;
}

