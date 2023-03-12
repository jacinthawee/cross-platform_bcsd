
uint eckey_priv_encode(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  int *unaff_s2;
  uint unaff_s3;
  int unaff_s4;
  undefined4 unaff_s5;
  undefined4 uVar9;
  code *pcVar10;
  uint uStack_88;
  int iStack_84;
  char *pcStack_7c;
  undefined *puStack_78;
  int *piStack_74;
  uint uStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  code *pcStack_64;
  int *local_50;
  int local_4c;
  int local_48;
  undefined *local_40;
  uint local_34;
  int local_30;
  int local_2c;
  
  piVar5 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_40 = &_gp;
  pcStack_7c = *(char **)(param_2 + 0x14);
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pcStack_7c == (char *)0x0) ||
     (unaff_s2 = (int *)(*(code *)PTR_EC_KEY_get0_group_006a7690)(pcStack_7c), unaff_s5 = param_1,
     unaff_s2 == (int *)0x0)) {
    pcVar10 = *(code **)(local_40 + -0x6eac);
    uVar9 = 0x7c;
    local_50 = (int *)0x4a;
LAB_005f5e8c:
    (*pcVar10)(0x10,0xdf,uVar9,"ec_ameth.c");
    param_1 = unaff_s5;
LAB_005f5ea0:
    pcStack_7c = "encrypt";
    pcVar10 = *(code **)(local_40 + -0x6eac);
    uVar9 = 0x8e;
    local_50 = (int *)0x133;
LAB_005f5eb4:
    iVar4 = 0xd6;
    (*pcVar10)(0x10,0xd6,uVar9,"ec_ameth.c");
    uVar3 = 0;
  }
  else {
    iVar2 = (**(code **)(local_40 + -0x6764))(unaff_s2);
    if ((iVar2 == 0) || (iVar2 = (**(code **)(local_40 + -0x6e64))(unaff_s2), iVar2 == 0)) {
      unaff_s2 = (int *)(**(code **)(local_40 + -0x6650))();
      if (unaff_s2 == (int *)0x0) goto LAB_005f5ea0;
      uVar9 = 0x10;
      iVar2 = (**(code **)(local_40 + -0x5718))(pcStack_7c,unaff_s2 + 2);
      *unaff_s2 = iVar2;
      if (iVar2 < 1) {
        (**(code **)(local_40 + -0x6644))(unaff_s2);
        uVar9 = 0x10;
        local_50 = (int *)0x5c;
        pcVar10 = *(code **)(local_40 + -0x6eac);
        goto LAB_005f5e8c;
      }
    }
    else {
      uVar9 = 6;
      unaff_s2 = (int *)(**(code **)(local_40 + -0x7ca0))(iVar2);
    }
    unaff_s3 = (**(code **)(local_40 + -0x5708))(pcStack_7c);
    (**(code **)(local_40 + -0x5704))(pcStack_7c,unaff_s3 | 1);
    unaff_s4 = (**(code **)(local_40 + -0x5f68))(pcStack_7c,0);
    if (unaff_s4 == 0) {
      (**(code **)(local_40 + -0x5704))(pcStack_7c,unaff_s3);
      local_50 = (int *)0x143;
      iVar4 = 0xd6;
      (**(code **)(local_40 + -0x6eac))(0x10,0xd6,0x10,"ec_ameth.c");
      uVar3 = 0;
    }
    else {
      iVar2 = (**(code **)(local_40 + -0x7dd8))(unaff_s4,"ec_ameth.c",0x146);
      if (iVar2 == 0) {
        (**(code **)(local_40 + -0x5704))(pcStack_7c,unaff_s3);
        uVar9 = 0x41;
        local_50 = (int *)&DAT_00000149;
        pcVar10 = *(code **)(local_40 + -0x6eac);
        goto LAB_005f5eb4;
      }
      local_30 = iVar2;
      uVar3 = (**(code **)(local_40 + -0x5f68))(pcStack_7c,&local_30);
      if (uVar3 == 0) {
        local_34 = uVar3;
        (**(code **)(local_40 + -0x5704))(pcStack_7c,unaff_s3);
        (**(code **)(local_40 + -0x7f58))(iVar2);
        iVar4 = 0xd6;
        local_50 = (int *)0x150;
        (**(code **)(local_40 + -0x6eac))(0x10,0xd6,0x10,"ec_ameth.c");
        uVar3 = local_34;
      }
      else {
        (**(code **)(local_40 + -0x5704))(pcStack_7c,unaff_s3);
        iVar4 = (**(code **)(local_40 + -0x7ca0))(0x198);
        local_50 = unaff_s2;
        local_4c = iVar2;
        local_48 = unaff_s4;
        iVar2 = (**(code **)(local_40 + -0x6648))(param_1,iVar4,0,uVar9);
        uVar3 = (uint)(iVar2 != 0);
      }
    }
  }
  if (local_2c == *piVar5) {
    return uVar3;
  }
  pcStack_64 = eckey_pub_encode;
  iVar2 = local_2c;
  (**(code **)(local_40 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_78 = (undefined *)piVar5;
  pcVar8 = *(char **)(iVar4 + 0x14);
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_74 = unaff_s2;
  uStack_70 = unaff_s3;
  iStack_6c = unaff_s4;
  uStack_68 = param_1;
  if ((pcVar8 == (char *)0x0) ||
     (piVar5 = (int *)(*(code *)PTR_EC_KEY_get0_group_006a7690)(pcVar8), unaff_s4 = iVar2,
     piVar5 == (int *)0x0)) {
    uVar7 = 0x7c;
    uVar9 = 0x4a;
  }
  else {
    iVar4 = (*(code *)PTR_EC_GROUP_get_asn1_flag_006a867c)(piVar5);
    if ((iVar4 != 0) &&
       (iVar4 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(piVar5), iVar4 != 0)) {
      piVar5 = (int *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar4);
      iVar4 = (*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar8,0);
      if (iVar4 < 1) {
        unaff_s3 = 0;
        goto LAB_005f61e0;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4,"ec_ameth.c",0x74);
      if (unaff_s3 == 0) goto LAB_005f61e0;
      uStack_88 = unaff_s3;
      pcVar8 = (char *)(*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar8,&uStack_88);
      if (0 < (int)pcVar8) goto LAB_005f62cc;
      goto LAB_005f61e0;
    }
    piVar5 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar5 == (int *)0x0) goto LAB_005f613c;
    iVar4 = (*(code *)PTR_i2d_ECParameters_006a96c8)(pcVar8,piVar5 + 2);
    *piVar5 = iVar4;
    if (0 < iVar4) {
      iVar4 = (*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar8,0);
      if (iVar4 < 1) {
        unaff_s3 = 0;
        goto LAB_005f60c0;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4,"ec_ameth.c",0x74);
      if (unaff_s3 == 0) goto LAB_005f60c0;
      uStack_88 = unaff_s3;
      pcVar8 = (char *)(*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar8,&uStack_88);
      if ((int)pcVar8 < 1) goto LAB_005f60c0;
      iVar4 = 0x10;
      goto LAB_005f6244;
    }
    (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar5);
    uVar7 = 0x10;
    uVar9 = 0x5c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdf,uVar7,"ec_ameth.c",uVar9);
  iVar2 = unaff_s4;
LAB_005f613c:
  pcVar8 = "encrypt";
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd8,0x10,"ec_ameth.c",0x6e);
  uVar3 = 0;
  do {
    while( true ) {
      while( true ) {
        if (iStack_84 == *(int *)puVar1) {
          return uVar3;
        }
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005f62cc:
        iVar4 = 6;
LAB_005f6244:
        uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x198);
        iVar6 = (*(code *)PTR_X509_PUBKEY_set0_param_006a87a8)
                          (iVar2,uVar9,iVar4,piVar5,unaff_s3,pcVar8);
        if (iVar6 == 0) break;
        uVar3 = 1;
      }
      if (iVar4 == 6) break;
LAB_005f60c0:
      (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar5);
      if (unaff_s3 != 0) goto LAB_005f60d0;
LAB_005f61f4:
      uVar3 = 0;
    }
LAB_005f61e0:
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(piVar5);
    if (unaff_s3 == 0) goto LAB_005f61f4;
LAB_005f60d0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s3);
    uVar3 = 0;
  } while( true );
}

