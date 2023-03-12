
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcVar6 = *(char **)(param_2 + 0x14);
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((pcVar6 == (char *)0x0) ||
     (unaff_s1 = (int *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(pcVar6), unaff_s4 = param_1,
     unaff_s1 == (int *)0x0)) {
    uVar5 = 0x7c;
    uVar3 = 0x4a;
  }
  else {
    iVar2 = (*(code *)PTR_EC_GROUP_get_asn1_flag_006a97a0)(unaff_s1);
    if ((iVar2 != 0) &&
       (iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(unaff_s1), iVar2 != 0)) {
      unaff_s1 = (int *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2);
      iVar2 = (*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar6,0);
      if (iVar2 < 1) {
        unaff_s3 = 0;
        goto LAB_005f8194;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"ec_ameth.c",0x77);
      if (unaff_s3 == 0) goto LAB_005f8194;
      local_28 = unaff_s3;
      pcVar6 = (char *)(*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar6,&local_28);
      if (0 < (int)pcVar6) goto LAB_005f8280;
      goto LAB_005f8194;
    }
    unaff_s1 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (unaff_s1 == (int *)0x0) goto LAB_005f80f0;
    iVar2 = (*(code *)PTR_i2d_ECParameters_006aa7d0)(pcVar6,unaff_s1 + 2);
    *unaff_s1 = iVar2;
    if (0 < iVar2) {
      iVar2 = (*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar6,0);
      if (iVar2 < 1) {
        unaff_s3 = 0;
        goto LAB_005f8074;
      }
      unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"ec_ameth.c",0x77);
      if (unaff_s3 == 0) goto LAB_005f8074;
      local_28 = unaff_s3;
      pcVar6 = (char *)(*(code *)PTR_i2o_ECPublicKey_006aa7e8)(pcVar6,&local_28);
      if ((int)pcVar6 < 1) goto LAB_005f8074;
      iVar2 = 0x10;
      goto LAB_005f81f8;
    }
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(unaff_s1);
    uVar5 = 0x10;
    uVar3 = 0x5e;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdf,uVar5,"ec_ameth.c",uVar3);
  param_1 = unaff_s4;
LAB_005f80f0:
  pcVar6 = "7 datafinal";
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd8,0x10,"ec_ameth.c",0x71);
  uVar3 = 0;
  do {
    while( true ) {
      while( true ) {
        if (local_24 == *(int *)puVar1) {
          return uVar3;
        }
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005f8280:
        iVar2 = 6;
LAB_005f81f8:
        uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x198);
        iVar4 = (*(code *)PTR_X509_PUBKEY_set0_param_006a98c8)
                          (param_1,uVar3,iVar2,unaff_s1,unaff_s3,pcVar6);
        if (iVar4 == 0) break;
        uVar3 = 1;
      }
      if (iVar2 == 6) break;
LAB_005f8074:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(unaff_s1);
      if (unaff_s3 != 0) goto LAB_005f8084;
LAB_005f81a8:
      uVar3 = 0;
    }
LAB_005f8194:
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(unaff_s1);
    if (unaff_s3 == 0) goto LAB_005f81a8;
LAB_005f8084:
    (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s3);
    uVar3 = 0;
  } while( true );
}

