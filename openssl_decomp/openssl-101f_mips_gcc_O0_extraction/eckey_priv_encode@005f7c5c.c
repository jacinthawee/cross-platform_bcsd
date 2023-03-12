
bool eckey_priv_encode(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  bool bVar5;
  int *piVar4;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  int *unaff_s2;
  int unaff_s3;
  uint unaff_s4;
  undefined4 unaff_s5;
  undefined4 uVar9;
  code *pcVar10;
  int iStack_80;
  int iStack_7c;
  char *pcStack_74;
  undefined *puStack_70;
  int *piStack_6c;
  int iStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  code *pcStack_5c;
  int *local_48;
  int local_44;
  int local_40;
  undefined *local_38;
  int local_30;
  uint local_2c;
  
  piVar4 = (int *)PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  pcStack_74 = *(char **)(param_2 + 0x14);
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  if ((pcStack_74 == (char *)0x0) ||
     (unaff_s2 = (int *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(pcStack_74), unaff_s5 = param_1,
     unaff_s2 == (int *)0x0)) {
    pcVar10 = *(code **)(local_38 + -0x6eb0);
    uVar9 = 0x7c;
    local_48 = (int *)0x4a;
LAB_005f7e48:
    (*pcVar10)(0x10,0xdf,uVar9,"ec_ameth.c");
    param_1 = unaff_s5;
LAB_005f7e5c:
    pcStack_74 = "r";
    pcVar10 = *(code **)(local_38 + -0x6eb0);
    uVar9 = 0x8e;
    local_48 = (int *)0x144;
LAB_005f7e70:
    iVar3 = 0xd6;
    (*pcVar10)(0x10,0xd6,uVar9,"ec_ameth.c");
    bVar5 = false;
  }
  else {
    iVar2 = (**(code **)(local_38 + -0x6740))(unaff_s2);
    if ((iVar2 == 0) || (iVar2 = (**(code **)(local_38 + -0x6dd0))(unaff_s2), iVar2 == 0)) {
      unaff_s2 = (int *)(**(code **)(local_38 + -0x662c))();
      if (unaff_s2 == (int *)0x0) goto LAB_005f7e5c;
      uVar9 = 0x10;
      iVar2 = (**(code **)(local_38 + -0x5710))(pcStack_74,unaff_s2 + 2);
      *unaff_s2 = iVar2;
      if (iVar2 < 1) {
        (**(code **)(local_38 + -0x6624))(unaff_s2);
        uVar9 = 0x10;
        local_48 = (int *)0x5e;
        pcVar10 = *(code **)(local_38 + -0x6eb0);
        goto LAB_005f7e48;
      }
    }
    else {
      uVar9 = 6;
      unaff_s2 = (int *)(**(code **)(local_38 + -0x7ca0))(iVar2);
    }
    unaff_s4 = (**(code **)(local_38 + -0x5700))(pcStack_74);
    (**(code **)(local_38 + -0x56fc))(pcStack_74,unaff_s4 | 1);
    unaff_s3 = (**(code **)(local_38 + -0x5f4c))(pcStack_74,0);
    if (unaff_s3 == 0) {
      (**(code **)(local_38 + -0x56fc))(pcStack_74,unaff_s4);
      local_48 = (int *)0x153;
      iVar3 = 0xd6;
      (**(code **)(local_38 + -0x6eb0))(0x10,0xd6,0x10,"ec_ameth.c");
      bVar5 = false;
    }
    else {
      iVar2 = (**(code **)(local_38 + -0x7dd8))(unaff_s3,"ec_ameth.c",0x156);
      if (iVar2 == 0) {
        (**(code **)(local_38 + -0x56fc))(pcStack_74,unaff_s4);
        uVar9 = 0x41;
        local_48 = (int *)0x15a;
        pcVar10 = *(code **)(local_38 + -0x6eb0);
        goto LAB_005f7e70;
      }
      local_30 = iVar2;
      iVar3 = (**(code **)(local_38 + -0x5f4c))(pcStack_74,&local_30);
      if (iVar3 == 0) {
        (**(code **)(local_38 + -0x56fc))(pcStack_74,unaff_s4);
        (**(code **)(local_38 + -0x7f58))(iVar2);
        local_48 = (int *)0x162;
        (**(code **)(local_38 + -0x6eb0))(0x10,0xd6,0x10,"ec_ameth.c");
      }
      (**(code **)(local_38 + -0x56fc))(pcStack_74,unaff_s4);
      iVar3 = (**(code **)(local_38 + -0x7ca0))(0x198);
      local_48 = unaff_s2;
      local_44 = iVar2;
      local_40 = unaff_s3;
      iVar2 = (**(code **)(local_38 + -0x6628))(param_1,iVar3,0,uVar9);
      bVar5 = iVar2 != 0;
    }
  }
  if (local_2c == *piVar4) {
    return bVar5;
  }
  pcStack_5c = eckey_pub_encode;
  uVar6 = local_2c;
  (**(code **)(local_38 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puStack_70 = (undefined *)piVar4;
  pcVar8 = *(char **)(iVar3 + 0x14);
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_6c = unaff_s2;
  iStack_68 = unaff_s3;
  uStack_64 = unaff_s4;
  uStack_60 = param_1;
  if ((pcVar8 == (char *)0x0) ||
     (piVar4 = (int *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(pcVar8), unaff_s4 = uVar6,
     piVar4 == (int *)0x0)) {
    uVar7 = 0x7c;
    uVar9 = 0x4a;
  }
  else {
    iVar2 = (*(code *)PTR_EC_GROUP_get_asn1_flag_006a97a0)(piVar4);
    if ((iVar2 != 0) &&
       (iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(piVar4), iVar2 != 0)) {
      piVar4 = (int *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2);
      iVar2 = (*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar8,0);
      if (iVar2 < 1) {
        unaff_s3 = 0;
        goto LAB_005f8194;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"ec_ameth.c",0x77);
      if (unaff_s3 == 0) goto LAB_005f8194;
      iStack_80 = unaff_s3;
      pcVar8 = (char *)(*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar8,&iStack_80);
      if (0 < (int)pcVar8) goto LAB_005f8280;
      goto LAB_005f8194;
    }
    piVar4 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar4 == (int *)0x0) goto LAB_005f80f0;
    iVar2 = (*(code *)PTR_i2d_ECParameters_006aa7d0)(pcVar8,piVar4 + 2);
    *piVar4 = iVar2;
    if (0 < iVar2) {
      iVar2 = (*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar8,0);
      if (iVar2 < 1) {
        unaff_s3 = 0;
        goto LAB_005f8074;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"ec_ameth.c",0x77);
      if (unaff_s3 == 0) goto LAB_005f8074;
      iStack_80 = unaff_s3;
      pcVar8 = (char *)(*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar8,&iStack_80);
      if ((int)pcVar8 < 1) goto LAB_005f8074;
      iVar2 = 0x10;
      goto LAB_005f81f8;
    }
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar4);
    uVar7 = 0x10;
    uVar9 = 0x5e;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdf,uVar7,"ec_ameth.c",uVar9);
  uVar6 = unaff_s4;
LAB_005f80f0:
  pcVar8 = "r";
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd8,0x10,"ec_ameth.c",0x71);
  bVar5 = false;
  do {
    while( true ) {
      while( true ) {
        if (iStack_7c == *(int *)puVar1) {
          return bVar5;
        }
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005f8280:
        iVar2 = 6;
LAB_005f81f8:
        uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x198);
        iVar3 = (*(code *)PTR_X509_PUBKEY_set0_param_006a98c8)
                          (uVar6,uVar9,iVar2,piVar4,unaff_s3,pcVar8);
        if (iVar3 == 0) break;
        bVar5 = true;
      }
      if (iVar2 == 6) break;
LAB_005f8074:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar4);
      if (unaff_s3 != 0) goto LAB_005f8084;
LAB_005f81a8:
      bVar5 = false;
    }
LAB_005f8194:
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(piVar4);
    if (unaff_s3 == 0) goto LAB_005f81a8;
LAB_005f8084:
    (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s3);
    bVar5 = false;
  } while( true );
}

