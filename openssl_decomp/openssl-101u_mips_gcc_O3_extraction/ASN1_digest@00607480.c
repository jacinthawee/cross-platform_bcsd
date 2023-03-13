
int ASN1_digest(undefined1 *i2d,EVP_MD *type,char *data,uchar *md,uint *len)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  uchar *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  char *pcVar12;
  int unaff_s0;
  code *pcVar13;
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
  EVP_MD *pEStack_10c;
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
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_2c = *(EVP_MD **)PTR___stack_chk_guard_006a9ae8;
  pcStack_5c = (char *)(*(code *)i2d)(data,0);
  iVar2 = (**(code **)(local_38 + -0x7dd8))(pcStack_5c,s_a_digest_c_00679750,0x52);
  if (iVar2 == 0) {
    pcStack_b0 = s_a_digest_c_00679750;
    puVar9 = &DAT_00000041;
    pcStack_b4 = (char *)0xb8;
    local_40 = (EVP_MD *)0x53;
    (**(code **)(local_38 + -0x6eac))(0xd,0xb8,0x41);
    iVar3 = 0;
  }
  else {
    local_30 = iVar2;
    (*(code *)i2d)(data,&local_30);
    local_3c = 0;
    pcStack_b4 = pcStack_5c;
    puVar9 = md;
    pcStack_b0 = (char *)len;
    local_40 = type;
    iVar3 = (**(code **)(local_38 + -0x73cc))(iVar2,pcStack_5c,md);
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
  pEStack_10c = local_2c;
  (**(code **)(local_38 + -0x5330))();
  pEStack_ac = local_40;
  puStack_b8 = PTR___stack_chk_guard_006a9ae8;
  piVar7 = &iStack_70;
  puStack_78 = &_gp;
  iStack_70 = 0;
  pcStack_6c = *(code **)PTR___stack_chk_guard_006a9ae8;
  pEStack_110 = (EVP_MD *)pcStack_b0;
  iStack_64 = unaff_s0;
  puStack_58 = i2d;
  piVar4 = (int *)(*(code *)PTR_ASN1_item_i2d_006a8678)(puVar9);
  if (iStack_70 == 0) {
LAB_0060766c:
    piVar4 = piVar7;
    iVar2 = 0;
  }
  else {
    uStack_7c = 0;
    pEStack_10c = (EVP_MD *)pcStack_b0;
    pEStack_110 = pEStack_ac;
    pcStack_80 = pcStack_b4;
    iVar2 = (**(code **)(puStack_78 + -0x73cc))();
    piVar7 = piVar4;
    if (iVar2 == 0) goto LAB_0060766c;
    (**(code **)(puStack_78 + -0x7f58))(iStack_70);
    iVar2 = 1;
  }
  if (pcStack_6c == *(code **)puStack_b8) {
    return iVar2;
  }
  uStack_94 = 0x6076bc;
  pcStack_114 = pcStack_6c;
  (**(code **)(puStack_78 + -0x5330))();
  puStack_11c = PTR___stack_chk_guard_006a9ae8;
  puStack_120 = auStack_d4;
  pcStack_dc = pcStack_80;
  uStack_a4 = 0x680000;
  puStack_e8 = &_gp;
  puStack_98 = len;
  piStack_bc = *(int **)PTR___stack_chk_guard_006a9ae8;
  pcStack_a8 = data;
  pEStack_a0 = type;
  puStack_9c = md;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_120);
  uVar5 = (**(code **)(puStack_e8 + -0x7cb4))(*piVar4);
  uVar5 = (**(code **)(puStack_e8 + -0x7d44))(uVar5);
  iVar2 = (**(code **)(puStack_e8 + -0x7eb4))(uVar5);
  if (iVar2 == 0) {
    pcVar13 = *(code **)(puStack_e8 + -0x6eac);
    puVar10 = (undefined4 *)0xa1;
    iStack_f0 = 0x59;
LAB_006078ec:
    pcVar12 = "a_verify.c";
    puVar8 = (undefined4 *)&DAT_00000089;
    iStack_118 = -1;
    (*pcVar13)(0xd,0x89,puVar10,"a_verify.c");
  }
  else {
    if ((pEStack_10c->pkey_type == 3) && ((pEStack_10c->flags & 7) != 0)) {
      pcVar13 = *(code **)(puStack_e8 + -0x6eac);
      puVar10 = (undefined4 *)&DAT_000000dc;
      iStack_f0 = 0x5e;
      goto LAB_006078ec;
    }
    type = (EVP_MD *)(*pcStack_114)(pEStack_110,0);
    iVar3 = (**(code **)(puStack_e8 + -0x7dd8))(type,"a_verify.c",99);
    if (iVar3 == 0) {
      pcVar12 = "a_verify.c";
      puVar10 = (undefined4 *)&DAT_00000041;
      puVar8 = (undefined4 *)&DAT_00000089;
      iStack_f0 = 0x65;
      iStack_118 = -1;
      (**(code **)(puStack_e8 + -0x6eac))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_d8 = iVar3;
      (*pcStack_114)(pEStack_110,&iStack_d8);
      iVar2 = (**(code **)(puStack_e8 + -0x7864))(puStack_120,iVar2,0);
      if ((iVar2 == 0) ||
         (iVar2 = (**(code **)(puStack_e8 + -0x7860))(puStack_120,iVar3,type), iVar2 == 0)) {
        pcVar13 = *(code **)(puStack_e8 + -0x6eac);
        iStack_f0 = 0x6d;
      }
      else {
        (**(code **)(puStack_e8 + -0x7d6c))(iVar3,type);
        (**(code **)(puStack_e8 + -0x7f58))(iVar3);
        puVar10 = (undefined4 *)pEStack_10c->type;
        puVar8 = (undefined4 *)pEStack_10c->md_size;
        pcVar12 = pcStack_dc;
        iVar2 = (**(code **)(puStack_e8 + -0x6e04))(puStack_120,puVar8,puVar10,pcStack_dc);
        if (0 < iVar2) {
          iStack_118 = 1;
          goto LAB_0060782c;
        }
        pcVar13 = *(code **)(puStack_e8 + -0x6eac);
        iStack_f0 = 0x77;
      }
      pcVar12 = "a_verify.c";
      puVar10 = (undefined4 *)&DAT_00000006;
      puVar8 = (undefined4 *)&DAT_00000089;
      iStack_118 = 0;
      (*pcVar13)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_0060782c:
  (**(code **)(puStack_e8 + -0x7fac))(puStack_120);
  if (piStack_bc == *(int **)puStack_11c) {
    return iStack_118;
  }
  pcStack_104 = ASN1_item_verify;
  piVar7 = piStack_bc;
  (**(code **)(puStack_e8 + -0x5330))();
  iVar2 = iStack_f0;
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_148 = 0;
  iStack_124 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEStack_108 = type;
  if (iStack_f0 == 0) {
    uVar11 = 0x43;
    uVar5 = 0x92;
  }
  else {
    if ((puVar10[1] != 3) || ((puVar10[3] & 7) == 0)) {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_13c);
      uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar8);
      iVar3 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(uVar5,&iStack_144,&uStack_140);
      if (iVar3 == 0) {
        uVar11 = 199;
        uVar5 = 0x9f;
LAB_00607b58:
        piVar4 = (int *)0xc5;
        iVar2 = -1;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar11,"a_verify.c",uVar5);
      }
      else {
        if (iStack_144 != 0) {
          uVar5 = (*(code *)PTR_OBJ_nid2sn_006a709c)();
          iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar5);
          if (iVar3 == 0) {
            uVar11 = 0xa1;
            uVar5 = 0xb6;
          }
          else {
            iVar6 = (*(code *)PTR_EVP_PKEY_type_006a97e0)(uStack_140);
            if (iVar6 == **(int **)(iVar2 + 0xc)) {
              iVar2 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)(auStack_13c,0,iVar3,0,iVar2);
              if (iVar2 != 0) goto LAB_00607b88;
              uVar5 = 0xc1;
              goto LAB_00607bd8;
            }
            uVar11 = 200;
            uVar5 = 0xbc;
          }
          goto LAB_00607b58;
        }
        if ((*(int *)(iVar2 + 0xc) == 0) ||
           (pcVar13 = *(code **)(*(int *)(iVar2 + 0xc) + 100), pcVar13 == (code *)0x0)) {
          uVar11 = 199;
          uVar5 = 0xa5;
          goto LAB_00607b58;
        }
        piVar4 = piVar7;
        iVar2 = (*pcVar13)(auStack_13c,piVar7,pcVar12,puVar8,puVar10,iVar2);
        if (iVar2 == 2) {
LAB_00607b88:
          uVar5 = (*(code *)PTR_ASN1_item_i2d_006a8678)(pcVar12,&iStack_148,piVar7);
          if (iStack_148 == 0) {
            uVar11 = 0x41;
            uVar5 = 0xcb;
            goto LAB_00607b58;
          }
          iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_13c,iStack_148,uVar5);
          if (iVar2 == 0) {
            uVar5 = 0xd0;
          }
          else {
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(iStack_148,uVar5);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_148);
            piVar4 = (int *)puVar10[2];
            iVar2 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)(auStack_13c,piVar4,*puVar10);
            if (0 < iVar2) {
              iVar2 = 1;
              goto LAB_00607a64;
            }
            uVar5 = 0xda;
          }
LAB_00607bd8:
          piVar4 = (int *)0xc5;
          iVar2 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,6,"a_verify.c",uVar5);
        }
      }
LAB_00607a64:
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_13c);
      goto LAB_00607a78;
    }
    uVar11 = 0xdc;
    uVar5 = 0x97;
  }
  piVar4 = (int *)0xc5;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar11,"a_verify.c",uVar5);
  iVar2 = -1;
LAB_00607a78:
  if (iStack_124 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    *piVar4 = *piVar4 + 1;
    return 1;
  }
  return iVar2;
}

