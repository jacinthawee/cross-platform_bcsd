
int ASN1_verify(undefined1 *i2d,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,char *data,
               EVP_PKEY *pkey)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined4 unaff_s5;
  undefined4 unaff_s6;
  code *pcVar12;
  int iStack_b8;
  int iStack_b4;
  undefined4 uStack_b0;
  undefined auStack_ac [24];
  int iStack_94;
  undefined *puStack_90;
  undefined *puStack_8c;
  int iStack_88;
  undefined1 *puStack_84;
  char *pcStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  code *pcStack_74;
  int local_60;
  undefined *local_58;
  EVP_PKEY *local_4c;
  int local_48;
  undefined auStack_44 [24];
  int *local_2c;
  
  puStack_8c = PTR___stack_chk_guard_006aabf0;
  puStack_90 = auStack_44;
  local_4c = pkey;
  local_58 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_90);
  uVar2 = (**(code **)(local_58 + -0x7cb4))(algor1->algorithm);
  uVar2 = (**(code **)(local_58 + -0x7d44))(uVar2);
  iVar3 = (**(code **)(local_58 + -0x7eb4))(uVar2);
  if (iVar3 == 0) {
    puVar9 = (undefined4 *)0xa1;
    pcVar11 = "a_verify.c";
    local_60 = 0x5a;
    puVar7 = (undefined4 *)&DAT_00000089;
    iStack_88 = -1;
    (**(code **)(local_58 + -0x6eb0))(0xd,0x89,0xa1,"a_verify.c");
  }
  else {
    unaff_s5 = (*(code *)i2d)(data,0);
    unaff_s6 = 0x680000;
    iVar4 = (**(code **)(local_58 + -0x7dd8))(unaff_s5,"a_verify.c",0x5f);
    if (iVar4 == 0) {
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000041;
      puVar7 = (undefined4 *)&DAT_00000089;
      local_60 = 0x62;
      iStack_88 = -1;
      (**(code **)(local_58 + -0x6eb0))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      local_48 = iVar4;
      (*(code *)i2d)(data,&local_48);
      iVar3 = (**(code **)(local_58 + -0x7870))(puStack_90,iVar3,0);
      if (iVar3 == 0) {
LAB_006095e8:
        pcVar12 = *(code **)(local_58 + -0x6eb0);
        local_60 = 0x6b;
      }
      else {
        iVar3 = (**(code **)(local_58 + -0x786c))(puStack_90,iVar4,unaff_s5);
        if (iVar3 == 0) goto LAB_006095e8;
        (**(code **)(local_58 + -0x7d6c))(iVar4,unaff_s5);
        (**(code **)(local_58 + -0x7f58))(iVar4);
        puVar9 = (undefined4 *)signature->length;
        puVar7 = (undefined4 *)signature->data;
        pcVar11 = (char *)local_4c;
        iVar3 = (**(code **)(local_58 + -0x6e64))(puStack_90,puVar7,puVar9,local_4c);
        if (0 < iVar3) {
          iStack_88 = 1;
          goto LAB_00609610;
        }
        pcVar12 = *(code **)(local_58 + -0x6eb0);
        local_60 = 0x76;
      }
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000006;
      puVar7 = (undefined4 *)&DAT_00000089;
      iStack_88 = 0;
      (*pcVar12)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_00609610:
  (**(code **)(local_58 + -0x7fac))(puStack_90);
  if (local_2c == *(int **)puStack_8c) {
    return iStack_88;
  }
  pcStack_74 = ASN1_item_verify;
  piVar6 = local_2c;
  (**(code **)(local_58 + -0x5328))();
  iVar3 = local_60;
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_b8 = 0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_84 = i2d;
  pcStack_80 = data;
  uStack_7c = unaff_s5;
  uStack_78 = unaff_s6;
  if (local_60 == 0) {
    piVar8 = (int *)0xc5;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,0x43,"a_verify.c",0x91);
    iVar3 = -1;
    goto LAB_00609824;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_ac);
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar7);
  iVar4 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(uVar2,&iStack_b4,&uStack_b0);
  if (iVar4 == 0) {
    uVar10 = 199;
    uVar2 = 0x9a;
LAB_0060986c:
    piVar8 = (int *)0xc5;
    iVar3 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,uVar10,"a_verify.c",uVar2);
  }
  else {
    if (iStack_b4 != 0) {
      uVar2 = (*(code *)PTR_OBJ_nid2sn_006a819c)();
      iVar4 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar2);
      if (iVar4 == 0) {
        uVar10 = 0xa1;
        uVar2 = 0xb4;
      }
      else {
        iVar5 = (*(code *)PTR_EVP_PKEY_type_006aa8f0)(uStack_b0);
        if (iVar5 == **(int **)(iVar3 + 0xc)) {
          iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a85f0)(auStack_ac,0,iVar4,0,iVar3);
          if (iVar3 != 0) goto LAB_006098f4;
          uVar2 = 0xc1;
          goto LAB_00609944;
        }
        uVar10 = 200;
        uVar2 = 0xbb;
      }
      goto LAB_0060986c;
    }
    if ((*(int *)(iVar3 + 0xc) == 0) ||
       (pcVar12 = *(code **)(*(int *)(iVar3 + 0xc) + 100), pcVar12 == (code *)0x0)) {
      uVar10 = 199;
      uVar2 = 0xa1;
      goto LAB_0060986c;
    }
    piVar8 = piVar6;
    iVar3 = (*pcVar12)(auStack_ac,piVar6,pcVar11,puVar7,puVar9,iVar3);
    if (iVar3 == 2) {
LAB_006098f4:
      uVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)(pcVar11,&iStack_b8,piVar6);
      if (iStack_b8 == 0) {
        uVar10 = 0x41;
        uVar2 = 0xcc;
        goto LAB_0060986c;
      }
      iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_ac,iStack_b8,uVar2);
      if (iVar3 == 0) {
        uVar2 = 0xd2;
      }
      else {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_b8,uVar2);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_b8);
        piVar8 = (int *)puVar9[2];
        iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a85c8)(auStack_ac,piVar8,*puVar9);
        if (0 < iVar3) {
          iVar3 = 1;
          goto LAB_00609810;
        }
        uVar2 = 0xdd;
      }
LAB_00609944:
      piVar8 = (int *)0xc5;
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,6,"a_verify.c",uVar2);
    }
  }
LAB_00609810:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_ac);
LAB_00609824:
  if (iStack_94 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *piVar8 = *piVar8 + 1;
  return 1;
}

