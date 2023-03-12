
int ASN1_item_digest(ASN1_ITEM *it,EVP_MD *type,void *data,uchar *md,uint *len)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  ASN1_TEMPLATE *pAVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined4 unaff_s5;
  undefined4 unaff_s6;
  code *pcVar12;
  int iStack_f8;
  int iStack_f4;
  undefined4 uStack_f0;
  undefined auStack_ec [24];
  int iStack_d4;
  undefined *puStack_d0;
  undefined *puStack_cc;
  int iStack_c8;
  code *pcStack_c4;
  uint *puStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  code *pcStack_b4;
  int iStack_a0;
  undefined *puStack_98;
  EVP_MD *pEStack_8c;
  int iStack_88;
  undefined auStack_84 [24];
  int *piStack_6c;
  undefined *puStack_68;
  EVP_MD *pEStack_64;
  uchar *puStack_60;
  uint *puStack_5c;
  EVP_MD *local_30;
  int local_20;
  code *local_1c;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  piVar7 = &local_20;
  local_20 = 0;
  local_1c = *(code **)PTR___stack_chk_guard_006aabf0;
  puStack_c0 = (uint *)md;
  piVar2 = (int *)(*(code *)PTR_ASN1_item_i2d_006a979c)(data);
  if (local_20 == 0) {
LAB_0060945c:
    piVar2 = piVar7;
    iVar3 = 0;
  }
  else {
    it = (ASN1_ITEM *)md;
    puStack_c0 = len;
    iVar3 = (*(code *)PTR_EVP_Digest_006a8b04)();
    piVar7 = piVar2;
    local_30 = type;
    if (iVar3 == 0) goto LAB_0060945c;
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_20);
    iVar3 = 1;
  }
  if (local_1c == *(code **)puStack_68) {
    return iVar3;
  }
  pcStack_c4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_cc = PTR___stack_chk_guard_006aabf0;
  puStack_d0 = auStack_84;
  pEStack_8c = local_30;
  puStack_5c = len;
  puStack_98 = &_gp;
  piStack_6c = *(int **)PTR___stack_chk_guard_006aabf0;
  pEStack_64 = type;
  puStack_60 = md;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_d0);
  uVar4 = (**(code **)(puStack_98 + -0x7cb4))(*piVar2);
  uVar4 = (**(code **)(puStack_98 + -0x7d44))(uVar4);
  iVar3 = (**(code **)(puStack_98 + -0x7eb4))(uVar4);
  if (iVar3 == 0) {
    puVar9 = (undefined4 *)0xa1;
    pcVar11 = "a_verify.c";
    iStack_a0 = 0x5a;
    pAVar8 = (ASN1_TEMPLATE *)&DAT_00000089;
    iStack_c8 = -1;
    (**(code **)(puStack_98 + -0x6eb0))(0xd,0x89,0xa1,"a_verify.c");
  }
  else {
    unaff_s5 = (*pcStack_c4)(puStack_c0,0);
    unaff_s6 = 0x680000;
    iVar5 = (**(code **)(puStack_98 + -0x7dd8))(unaff_s5,"a_verify.c",0x5f);
    if (iVar5 == 0) {
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000041;
      pAVar8 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_a0 = 0x62;
      iStack_c8 = -1;
      (**(code **)(puStack_98 + -0x6eb0))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_88 = iVar5;
      (*pcStack_c4)(puStack_c0,&iStack_88);
      iVar3 = (**(code **)(puStack_98 + -0x7870))(puStack_d0,iVar3,0);
      if (iVar3 == 0) {
LAB_006095e8:
        pcVar12 = *(code **)(puStack_98 + -0x6eb0);
        iStack_a0 = 0x6b;
      }
      else {
        iVar3 = (**(code **)(puStack_98 + -0x786c))(puStack_d0,iVar5,unaff_s5);
        if (iVar3 == 0) goto LAB_006095e8;
        (**(code **)(puStack_98 + -0x7d6c))(iVar5,unaff_s5);
        (**(code **)(puStack_98 + -0x7f58))(iVar5);
        puVar9 = *(undefined4 **)it;
        pAVar8 = it->templates;
        pcVar11 = (char *)pEStack_8c;
        iVar3 = (**(code **)(puStack_98 + -0x6e64))(puStack_d0,pAVar8,puVar9,pEStack_8c);
        if (0 < iVar3) {
          iStack_c8 = 1;
          goto LAB_00609610;
        }
        pcVar12 = *(code **)(puStack_98 + -0x6eb0);
        iStack_a0 = 0x76;
      }
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000006;
      pAVar8 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_c8 = 0;
      (*pcVar12)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_00609610:
  (**(code **)(puStack_98 + -0x7fac))(puStack_d0);
  if (piStack_6c == *(int **)puStack_cc) {
    return iStack_c8;
  }
  pcStack_b4 = ASN1_item_verify;
  piVar7 = piStack_6c;
  (**(code **)(puStack_98 + -0x5328))();
  iVar3 = iStack_a0;
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_f8 = 0;
  iStack_d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_bc = unaff_s5;
  uStack_b8 = unaff_s6;
  if (iStack_a0 == 0) {
    piVar2 = (int *)0xc5;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,0x43,"a_verify.c",0x91);
    iVar3 = -1;
    goto LAB_00609824;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_ec);
  uVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pAVar8->flags);
  iVar5 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(uVar4,&iStack_f4,&uStack_f0);
  if (iVar5 == 0) {
    uVar10 = 199;
    uVar4 = 0x9a;
LAB_0060986c:
    piVar2 = (int *)0xc5;
    iVar3 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,uVar10,"a_verify.c",uVar4);
  }
  else {
    if (iStack_f4 != 0) {
      uVar4 = (*(code *)PTR_OBJ_nid2sn_006a819c)();
      iVar5 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar4);
      if (iVar5 == 0) {
        uVar10 = 0xa1;
        uVar4 = 0xb4;
      }
      else {
        iVar6 = (*(code *)PTR_EVP_PKEY_type_006aa8f0)(uStack_f0);
        if (iVar6 == **(int **)(iVar3 + 0xc)) {
          iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a85f0)(auStack_ec,0,iVar5,0,iVar3);
          if (iVar3 != 0) goto LAB_006098f4;
          uVar4 = 0xc1;
          goto LAB_00609944;
        }
        uVar10 = 200;
        uVar4 = 0xbb;
      }
      goto LAB_0060986c;
    }
    if ((*(int *)(iVar3 + 0xc) == 0) ||
       (pcVar12 = *(code **)(*(int *)(iVar3 + 0xc) + 100), pcVar12 == (code *)0x0)) {
      uVar10 = 199;
      uVar4 = 0xa1;
      goto LAB_0060986c;
    }
    piVar2 = piVar7;
    iVar3 = (*pcVar12)(auStack_ec,piVar7,pcVar11,pAVar8,puVar9,iVar3);
    if (iVar3 == 2) {
LAB_006098f4:
      uVar4 = (*(code *)PTR_ASN1_item_i2d_006a979c)(pcVar11,&iStack_f8,piVar7);
      if (iStack_f8 == 0) {
        uVar10 = 0x41;
        uVar4 = 0xcc;
        goto LAB_0060986c;
      }
      iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_ec,iStack_f8,uVar4);
      if (iVar3 == 0) {
        uVar4 = 0xd2;
      }
      else {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_f8,uVar4);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_f8);
        piVar2 = (int *)puVar9[2];
        iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a85c8)(auStack_ec,piVar2,*puVar9);
        if (0 < iVar3) {
          iVar3 = 1;
          goto LAB_00609810;
        }
        uVar4 = 0xdd;
      }
LAB_00609944:
      piVar2 = (int *)0xc5;
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,6,"a_verify.c",uVar4);
    }
  }
LAB_00609810:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_ec);
LAB_00609824:
  if (iStack_d4 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *piVar2 = *piVar2 + 1;
  return 1;
}

