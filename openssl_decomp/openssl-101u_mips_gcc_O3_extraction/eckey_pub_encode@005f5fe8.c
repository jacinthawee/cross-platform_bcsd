
undefined4 eckey_pub_encode(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int *unaff_s1;
  int unaff_s3;
  undefined4 unaff_s4;
  int local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcVar6 = *(char **)(param_2 + 0x14);
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pcVar6 == (char *)0x0) ||
     (unaff_s1 = (int *)(*(code *)PTR_EC_KEY_get0_group_006a7690)(pcVar6), unaff_s4 = param_1,
     unaff_s1 == (int *)0x0)) {
    uVar5 = 0x7c;
    uVar3 = 0x4a;
  }
  else {
    iVar2 = (*(code *)PTR_EC_GROUP_get_asn1_flag_006a867c)(unaff_s1);
    if ((iVar2 != 0) &&
       (iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(unaff_s1), iVar2 != 0)) {
      unaff_s1 = (int *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar2);
      iVar2 = (*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar6,0);
      if (iVar2 < 1) {
        unaff_s3 = 0;
        goto LAB_005f61e0;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"ec_ameth.c",0x74);
      if (unaff_s3 == 0) goto LAB_005f61e0;
      local_28 = unaff_s3;
      pcVar6 = (char *)(*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar6,&local_28);
      if (0 < (int)pcVar6) goto LAB_005f62cc;
      goto LAB_005f61e0;
    }
    unaff_s1 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (unaff_s1 == (int *)0x0) goto LAB_005f613c;
    iVar2 = (*(code *)PTR_i2d_ECParameters_006a96c8)(pcVar6,unaff_s1 + 2);
    *unaff_s1 = iVar2;
    if (0 < iVar2) {
      iVar2 = (*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar6,0);
      if (iVar2 < 1) {
        unaff_s3 = 0;
        goto LAB_005f60c0;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"ec_ameth.c",0x74);
      if (unaff_s3 == 0) goto LAB_005f60c0;
      local_28 = unaff_s3;
      pcVar6 = (char *)(*(code *)PTR_i2o_ECPublicKey_006a96e0)(pcVar6,&local_28);
      if ((int)pcVar6 < 1) goto LAB_005f60c0;
      iVar2 = 0x10;
      goto LAB_005f6244;
    }
    (*(code *)PTR_ASN1_STRING_free_006a879c)(unaff_s1);
    uVar5 = 0x10;
    uVar3 = 0x5c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdf,uVar5,"ec_ameth.c",uVar3);
  param_1 = unaff_s4;
LAB_005f613c:
  pcVar6 = "encrypt";
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd8,0x10,"ec_ameth.c",0x6e);
  uVar3 = 0;
  do {
    while( true ) {
      while( true ) {
        if (local_24 == *(int *)puVar1) {
          return uVar3;
        }
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005f62cc:
        iVar2 = 6;
LAB_005f6244:
        uVar3 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x198);
        iVar4 = (*(code *)PTR_X509_PUBKEY_set0_param_006a87a8)
                          (param_1,uVar3,iVar2,unaff_s1,unaff_s3,pcVar6);
        if (iVar4 == 0) break;
        uVar3 = 1;
      }
      if (iVar2 == 6) break;
LAB_005f60c0:
      (*(code *)PTR_ASN1_STRING_free_006a879c)(unaff_s1);
      if (unaff_s3 != 0) goto LAB_005f60d0;
LAB_005f61f4:
      uVar3 = 0;
    }
LAB_005f61e0:
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(unaff_s1);
    if (unaff_s3 == 0) goto LAB_005f61f4;
LAB_005f60d0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s3);
    uVar3 = 0;
  } while( true );
}

