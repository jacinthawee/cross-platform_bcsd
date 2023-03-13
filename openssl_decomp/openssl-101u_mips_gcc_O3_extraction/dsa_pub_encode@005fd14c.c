
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
  
  puStack_4c = PTR___stack_chk_guard_006a9ae8;
  puVar1 = PTR_i2d_DSAPublicKey_006a9758;
  local_28 = &_gp;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_54 = *(int *)(param_2 + 0x14);
  if ((((*(int *)(param_2 + 0x18) == 0) || (*(int *)(iStack_54 + 0xc) == 0)) ||
      (*(int *)(iStack_54 + 0x10) == 0)) || (*(int *)(iStack_54 + 0x14) == 0)) {
    *(undefined4 *)(iStack_54 + 8) = 0;
    piStack_50 = (int *)0x0;
    iStack_54 = (*(code *)puVar1)(iStack_54,&local_20);
    uVar7 = 0xffffffff;
    if (iStack_54 < 1) {
LAB_005fd210:
      local_30 = 0x9e;
      uVar6 = 0x76;
      (**(code **)(local_28 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
LAB_005fd238:
      if (local_20 != 0) goto LAB_005fd244;
      goto LAB_005fd254;
    }
LAB_005fd2c0:
    uVar6 = (**(code **)(local_28 + -0x7ca0))(0x74);
    local_30 = local_20;
    local_2c = iStack_54;
    iVar2 = (**(code **)(local_28 + -0x6638))(param_1,uVar6,uVar7,piStack_50);
    if (iVar2 == 0) goto LAB_005fd238;
    uVar7 = 1;
  }
  else {
    piStack_50 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piStack_50 == (int *)0x0) {
      local_30 = 0x8d;
      uVar6 = 0x76;
      (**(code **)(local_28 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
      if (local_20 == 0) {
        uVar7 = 0;
        goto LAB_005fd26c;
      }
LAB_005fd244:
      (**(code **)(local_28 + -0x7f58))();
LAB_005fd254:
      pcVar8 = *(code **)(local_28 + -0x6644);
      if (piStack_50 != (int *)0x0) goto LAB_005fd25c;
    }
    else {
      iVar2 = (**(code **)(local_28 + -0x775c))(iStack_54,piStack_50 + 2);
      *piStack_50 = iVar2;
      if (0 < iVar2) {
        pcVar8 = *(code **)(local_28 + -0x5688);
        *(undefined4 *)(iStack_54 + 8) = 0;
        uVar7 = 0x10;
        iStack_54 = (*pcVar8)(iStack_54,&local_20);
        if (0 < iStack_54) goto LAB_005fd2c0;
        goto LAB_005fd210;
      }
      local_30 = 0x92;
      uVar6 = 0x76;
      (**(code **)(local_28 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
      if (local_20 != 0) goto LAB_005fd244;
      pcVar8 = *(code **)(local_28 + -0x6644);
LAB_005fd25c:
      (*pcVar8)(piStack_50);
    }
    uVar7 = 0;
  }
LAB_005fd26c:
  if (local_1c == *(int *)puStack_4c) {
    return uVar7;
  }
  pcStack_44 = dsa_pub_decode;
  iVar2 = local_1c;
  (**(code **)(local_28 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_48 = param_1;
  iVar3 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)(0,auStack_74,&uStack_6c,&uStack_60,uVar6);
  if (iVar3 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&iStack_68,&puStack_64,uStack_60);
    if (iStack_68 == 0x10) {
      uStack_70 = puStack_64[2];
      iVar3 = (*(code *)PTR_d2i_DSAparams_006a7540)(0,&uStack_70,*puStack_64);
      if (iVar3 != 0) {
LAB_005fd488:
        iVar4 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,auStack_74,uStack_6c);
        if (iVar4 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x68,"dsa_ameth.c",0x6b);
        }
        else {
          iVar5 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar4,0);
          *(int *)(iVar3 + 0x18) = iVar5;
          if (iVar5 != 0) {
            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar4);
            (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar2,0x74,iVar3);
            uVar7 = 1;
            goto LAB_005fd3e4;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x6c,"dsa_ameth.c",0x70);
          (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar4);
        }
        (*(code *)PTR_DSA_free_006a7530)(iVar3);
        uVar7 = 0;
        goto LAB_005fd3e4;
      }
      uVar6 = 0x68;
      uVar7 = 0x5c;
    }
    else if ((iStack_68 == 5) || (iStack_68 == -1)) {
      iVar3 = (*(code *)PTR_DSA_new_006a7528)();
      if (iVar3 != 0) goto LAB_005fd488;
      uVar6 = 0x41;
      uVar7 = 0x62;
    }
    else {
      uVar6 = 0x69;
      uVar7 = 0x66;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,uVar6,"dsa_ameth.c",uVar7);
  }
  uVar7 = 0;
LAB_005fd3e4:
  if (iStack_5c == *(int *)puVar1) {
    return uVar7;
  }
  iVar2 = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (*(code *)PTR_d2i_DSAPrivateKey_006a8e20)(0);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x7a,10,"dsa_ameth.c",0x205);
    return 0;
  }
  (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar2,0x74,iVar3);
  return 1;
}

