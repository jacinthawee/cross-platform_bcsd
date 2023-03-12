
int ASN1_digest(undefined1 *i2d,EVP_MD *type,char *data,uchar *md,uint *len)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  EVP_MD *pEVar7;
  int *piVar8;
  undefined4 *puVar9;
  uchar *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  char *pcVar13;
  int unaff_s0;
  code *pcVar14;
  int iStack_148;
  int iStack_144;
  undefined4 uStack_140;
  undefined auStack_13c [24];
  int iStack_124;
  undefined *puStack_120;
  undefined *puStack_11c;
  int iStack_118;
  code *pcStack_114;
  EVP_MD *pEStack_110;
  undefined4 uStack_10c;
  EVP_MD *pEStack_108;
  code *pcStack_104;
  int iStack_f0;
  undefined *puStack_e8;
  char *pcStack_dc;
  int iStack_d8;
  undefined auStack_d4 [24];
  int *piStack_bc;
  undefined *puStack_b8;
  char *pcStack_b4;
  char *pcStack_b0;
  EVP_MD *pEStack_ac;
  char *pcStack_a8;
  undefined4 uStack_a4;
  EVP_MD *pEStack_a0;
  uchar *puStack_9c;
  uint *puStack_98;
  undefined4 uStack_94;
  char *pcStack_80;
  undefined4 uStack_7c;
  undefined *puStack_78;
  int iStack_70;
  code *pcStack_6c;
  int iStack_64;
  undefined *puStack_60;
  char *pcStack_5c;
  undefined1 *puStack_58;
  code *pcStack_54;
  EVP_MD *local_40;
  undefined4 local_3c;
  undefined *local_38;
  int local_30;
  EVP_MD *local_2c;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  uStack_10c = 0x680000;
  local_38 = &_gp;
  local_2c = *(EVP_MD **)PTR___stack_chk_guard_006aabf0;
  pcStack_5c = (char *)(*(code *)i2d)(data,0);
  iVar2 = (**(code **)(local_38 + -0x7dd8))(pcStack_5c,s_a_digest_c_0067a020,0x52);
  if (iVar2 == 0) {
    pcStack_b0 = s_a_digest_c_0067a020;
    puVar10 = &DAT_00000041;
    pcStack_b4 = (char *)0xb8;
    local_40 = (EVP_MD *)0x54;
    (**(code **)(local_38 + -0x6eb0))(0xd,0xb8,0x41);
    iVar3 = 0;
  }
  else {
    local_30 = iVar2;
    (*(code *)i2d)(data,&local_30);
    local_3c = 0;
    pcStack_b4 = pcStack_5c;
    puVar10 = md;
    pcStack_b0 = (char *)len;
    local_40 = type;
    iVar3 = (**(code **)(local_38 + -0x73dc))(iVar2,pcStack_5c,md);
    unaff_s0 = iVar2;
    if (iVar3 != 0) {
      (**(code **)(local_38 + -0x7f58))(iVar2);
      iVar3 = 1;
    }
  }
  if (local_2c == *(EVP_MD **)puStack_60) {
    return iVar3;
  }
  pcStack_54 = ASN1_item_digest;
  pEVar7 = local_2c;
  (**(code **)(local_38 + -0x5328))();
  pEStack_ac = local_40;
  puStack_b8 = PTR___stack_chk_guard_006aabf0;
  piVar8 = &iStack_70;
  puStack_78 = &_gp;
  iStack_70 = 0;
  pcStack_6c = *(code **)PTR___stack_chk_guard_006aabf0;
  pEStack_110 = (EVP_MD *)pcStack_b0;
  iStack_64 = unaff_s0;
  puStack_58 = i2d;
  piVar4 = (int *)(*(code *)PTR_ASN1_item_i2d_006a979c)(puVar10);
  if (iStack_70 == 0) {
LAB_0060945c:
    piVar4 = piVar8;
    iVar2 = 0;
  }
  else {
    uStack_7c = 0;
    pEVar7 = (EVP_MD *)pcStack_b0;
    pEStack_110 = pEStack_ac;
    pcStack_80 = pcStack_b4;
    iVar2 = (**(code **)(puStack_78 + -0x73dc))();
    piVar8 = piVar4;
    if (iVar2 == 0) goto LAB_0060945c;
    (**(code **)(puStack_78 + -0x7f58))(iStack_70);
    iVar2 = 1;
  }
  if (pcStack_6c == *(code **)puStack_b8) {
    return iVar2;
  }
  uStack_94 = 0x6094ac;
  pcStack_114 = pcStack_6c;
  (**(code **)(puStack_78 + -0x5328))();
  puStack_11c = PTR___stack_chk_guard_006aabf0;
  puStack_120 = auStack_d4;
  pcStack_dc = pcStack_80;
  puStack_e8 = &_gp;
  puStack_98 = len;
  uStack_a4 = 0x680000;
  piStack_bc = *(int **)PTR___stack_chk_guard_006aabf0;
  pcStack_a8 = data;
  pEStack_a0 = type;
  puStack_9c = md;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_120);
  uVar5 = (**(code **)(puStack_e8 + -0x7cb4))(*piVar4);
  uVar5 = (**(code **)(puStack_e8 + -0x7d44))(uVar5);
  iVar2 = (**(code **)(puStack_e8 + -0x7eb4))(uVar5);
  if (iVar2 == 0) {
    puVar11 = (undefined4 *)0xa1;
    pcVar13 = "a_verify.c";
    iStack_f0 = 0x5a;
    puVar9 = (undefined4 *)&DAT_00000089;
    iStack_118 = -1;
    (**(code **)(puStack_e8 + -0x6eb0))(0xd,0x89,0xa1,"a_verify.c");
  }
  else {
    uStack_10c = (*pcStack_114)(pEStack_110,0);
    type = (EVP_MD *)0x680000;
    iVar3 = (**(code **)(puStack_e8 + -0x7dd8))(uStack_10c,"a_verify.c",0x5f);
    if (iVar3 == 0) {
      pcVar13 = "a_verify.c";
      puVar11 = (undefined4 *)&DAT_00000041;
      puVar9 = (undefined4 *)&DAT_00000089;
      iStack_f0 = 0x62;
      iStack_118 = -1;
      (**(code **)(puStack_e8 + -0x6eb0))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_d8 = iVar3;
      (*pcStack_114)(pEStack_110,&iStack_d8);
      iVar2 = (**(code **)(puStack_e8 + -0x7870))(puStack_120,iVar2,0);
      if (iVar2 == 0) {
LAB_006095e8:
        pcVar14 = *(code **)(puStack_e8 + -0x6eb0);
        iStack_f0 = 0x6b;
      }
      else {
        iVar2 = (**(code **)(puStack_e8 + -0x786c))(puStack_120,iVar3,uStack_10c);
        if (iVar2 == 0) goto LAB_006095e8;
        (**(code **)(puStack_e8 + -0x7d6c))(iVar3,uStack_10c);
        (**(code **)(puStack_e8 + -0x7f58))(iVar3);
        puVar11 = (undefined4 *)pEVar7->type;
        puVar9 = (undefined4 *)pEVar7->md_size;
        pcVar13 = pcStack_dc;
        iVar2 = (**(code **)(puStack_e8 + -0x6e64))(puStack_120,puVar9,puVar11,pcStack_dc);
        if (0 < iVar2) {
          iStack_118 = 1;
          goto LAB_00609610;
        }
        pcVar14 = *(code **)(puStack_e8 + -0x6eb0);
        iStack_f0 = 0x76;
      }
      pcVar13 = "a_verify.c";
      puVar11 = (undefined4 *)&DAT_00000006;
      puVar9 = (undefined4 *)&DAT_00000089;
      iStack_118 = 0;
      (*pcVar14)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_00609610:
  (**(code **)(puStack_e8 + -0x7fac))(puStack_120);
  if (piStack_bc == *(int **)puStack_11c) {
    return iStack_118;
  }
  pcStack_104 = ASN1_item_verify;
  piVar8 = piStack_bc;
  (**(code **)(puStack_e8 + -0x5328))();
  iVar2 = iStack_f0;
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_148 = 0;
  iStack_124 = *(int *)PTR___stack_chk_guard_006aabf0;
  pEStack_108 = type;
  if (iStack_f0 == 0) {
    piVar4 = (int *)0xc5;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,0x43,"a_verify.c",0x91);
    iVar2 = -1;
    goto LAB_00609824;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_13c);
  uVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar9);
  iVar3 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(uVar5,&iStack_144,&uStack_140);
  if (iVar3 == 0) {
    uVar12 = 199;
    uVar5 = 0x9a;
LAB_0060986c:
    piVar4 = (int *)0xc5;
    iVar2 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,uVar12,"a_verify.c",uVar5);
  }
  else {
    if (iStack_144 != 0) {
      uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)();
      iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar5);
      if (iVar3 == 0) {
        uVar12 = 0xa1;
        uVar5 = 0xb4;
      }
      else {
        iVar6 = (*(code *)PTR_EVP_PKEY_type_006aa8f0)(uStack_140);
        if (iVar6 == **(int **)(iVar2 + 0xc)) {
          iVar2 = (*(code *)PTR_EVP_DigestVerifyInit_006a85f0)(auStack_13c,0,iVar3,0,iVar2);
          if (iVar2 != 0) goto LAB_006098f4;
          uVar5 = 0xc1;
          goto LAB_00609944;
        }
        uVar12 = 200;
        uVar5 = 0xbb;
      }
      goto LAB_0060986c;
    }
    if ((*(int *)(iVar2 + 0xc) == 0) ||
       (pcVar14 = *(code **)(*(int *)(iVar2 + 0xc) + 100), pcVar14 == (code *)0x0)) {
      uVar12 = 199;
      uVar5 = 0xa1;
      goto LAB_0060986c;
    }
    piVar4 = piVar8;
    iVar2 = (*pcVar14)(auStack_13c,piVar8,pcVar13,puVar9,puVar11,iVar2);
    if (iVar2 == 2) {
LAB_006098f4:
      uVar5 = (*(code *)PTR_ASN1_item_i2d_006a979c)(pcVar13,&iStack_148,piVar8);
      if (iStack_148 == 0) {
        uVar12 = 0x41;
        uVar5 = 0xcc;
        goto LAB_0060986c;
      }
      iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_13c,iStack_148,uVar5);
      if (iVar2 == 0) {
        uVar5 = 0xd2;
      }
      else {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_148,uVar5);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_148);
        piVar4 = (int *)puVar11[2];
        iVar2 = (*(code *)PTR_EVP_DigestVerifyFinal_006a85c8)(auStack_13c,piVar4,*puVar11);
        if (0 < iVar2) {
          iVar2 = 1;
          goto LAB_00609810;
        }
        uVar5 = 0xdd;
      }
LAB_00609944:
      piVar4 = (int *)0xc5;
      iVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,6,"a_verify.c",uVar5);
    }
  }
LAB_00609810:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_13c);
LAB_00609824:
  if (iStack_124 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *piVar4 = *piVar4 + 1;
  return 1;
}

