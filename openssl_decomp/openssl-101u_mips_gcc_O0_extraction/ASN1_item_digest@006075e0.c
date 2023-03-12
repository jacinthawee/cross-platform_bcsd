
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
  ASN1_ITEM *pAStack_bc;
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
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  piVar7 = &local_20;
  local_20 = 0;
  local_1c = *(code **)PTR___stack_chk_guard_006a9ae8;
  puStack_c0 = (uint *)md;
  piVar2 = (int *)(*(code *)PTR_ASN1_item_i2d_006a8678)(data);
  if ((local_20 == 0) ||
     (it = (ASN1_ITEM *)md, puStack_c0 = len, iVar3 = (*(code *)PTR_EVP_Digest_006a7a14)(),
     piVar7 = piVar2, local_30 = type, iVar3 == 0)) {
    piVar2 = piVar7;
    iVar3 = 0;
  }
  else {
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_20);
    iVar3 = 1;
  }
  if (local_1c == *(code **)puStack_68) {
    return iVar3;
  }
  pcStack_c4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_cc = PTR___stack_chk_guard_006a9ae8;
  puStack_d0 = auStack_84;
  pEStack_8c = local_30;
  puStack_5c = len;
  puStack_98 = &_gp;
  piStack_6c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pEStack_64 = type;
  puStack_60 = md;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_d0);
  uVar4 = (**(code **)(puStack_98 + -0x7cb4))(*piVar2);
  uVar4 = (**(code **)(puStack_98 + -0x7d44))(uVar4);
  iVar3 = (**(code **)(puStack_98 + -0x7eb4))(uVar4);
  if (iVar3 == 0) {
    pcVar12 = *(code **)(puStack_98 + -0x6eac);
    puVar9 = (undefined4 *)0xa1;
    iStack_a0 = 0x59;
LAB_006078ec:
    pcVar11 = "a_verify.c";
    pAVar8 = (ASN1_TEMPLATE *)&DAT_00000089;
    iStack_c8 = -1;
    (*pcVar12)(0xd,0x89,puVar9,"a_verify.c");
  }
  else {
    if ((it->utype == 3) && ((it->tcount & 7U) != 0)) {
      pcVar12 = *(code **)(puStack_98 + -0x6eac);
      puVar9 = (undefined4 *)&DAT_000000dc;
      iStack_a0 = 0x5e;
      goto LAB_006078ec;
    }
    unaff_s6 = (*pcStack_c4)(puStack_c0,0);
    iVar5 = (**(code **)(puStack_98 + -0x7dd8))(unaff_s6,"a_verify.c",99);
    if (iVar5 == 0) {
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000041;
      pAVar8 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_a0 = 0x65;
      iStack_c8 = -1;
      (**(code **)(puStack_98 + -0x6eac))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_88 = iVar5;
      (*pcStack_c4)(puStack_c0,&iStack_88);
      iVar3 = (**(code **)(puStack_98 + -0x7864))(puStack_d0,iVar3,0);
      if ((iVar3 == 0) ||
         (iVar3 = (**(code **)(puStack_98 + -0x7860))(puStack_d0,iVar5,unaff_s6), iVar3 == 0)) {
        pcVar12 = *(code **)(puStack_98 + -0x6eac);
        iStack_a0 = 0x6d;
      }
      else {
        (**(code **)(puStack_98 + -0x7d6c))(iVar5,unaff_s6);
        (**(code **)(puStack_98 + -0x7f58))(iVar5);
        puVar9 = *(undefined4 **)it;
        pAVar8 = it->templates;
        pcVar11 = (char *)pEStack_8c;
        iVar3 = (**(code **)(puStack_98 + -0x6e04))(puStack_d0,pAVar8,puVar9,pEStack_8c);
        if (0 < iVar3) {
          iStack_c8 = 1;
          goto LAB_0060782c;
        }
        pcVar12 = *(code **)(puStack_98 + -0x6eac);
        iStack_a0 = 0x77;
      }
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000006;
      pAVar8 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_c8 = 0;
      (*pcVar12)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_0060782c:
  (**(code **)(puStack_98 + -0x7fac))(puStack_d0);
  if (piStack_6c == *(int **)puStack_cc) {
    return iStack_c8;
  }
  pcStack_b4 = ASN1_item_verify;
  piVar7 = piStack_6c;
  (**(code **)(puStack_98 + -0x5330))();
  iVar3 = iStack_a0;
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_f8 = 0;
  iStack_d4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_bc = it;
  uStack_b8 = unaff_s6;
  if (iStack_a0 == 0) {
    uVar10 = 0x43;
    uVar4 = 0x92;
  }
  else {
    if ((puVar9[1] != 3) || ((puVar9[3] & 7) == 0)) {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_ec);
      uVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar8->flags);
      iVar5 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(uVar4,&iStack_f4,&uStack_f0);
      if (iVar5 == 0) {
        uVar10 = 199;
        uVar4 = 0x9f;
LAB_00607b58:
        piVar2 = (int *)0xc5;
        iVar3 = -1;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar10,"a_verify.c",uVar4);
      }
      else {
        if (iStack_f4 != 0) {
          uVar4 = (*(code *)PTR_OBJ_nid2sn_006a709c)();
          iVar5 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar4);
          if (iVar5 == 0) {
            uVar10 = 0xa1;
            uVar4 = 0xb6;
          }
          else {
            iVar6 = (*(code *)PTR_EVP_PKEY_type_006a97e0)(uStack_f0);
            if (iVar6 == **(int **)(iVar3 + 0xc)) {
              iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)(auStack_ec,0,iVar5,0,iVar3);
              if (iVar3 != 0) goto LAB_00607b88;
              uVar4 = 0xc1;
              goto LAB_00607bd8;
            }
            uVar10 = 200;
            uVar4 = 0xbc;
          }
          goto LAB_00607b58;
        }
        if ((*(int *)(iVar3 + 0xc) == 0) ||
           (pcVar12 = *(code **)(*(int *)(iVar3 + 0xc) + 100), pcVar12 == (code *)0x0)) {
          uVar10 = 199;
          uVar4 = 0xa5;
          goto LAB_00607b58;
        }
        piVar2 = piVar7;
        iVar3 = (*pcVar12)(auStack_ec,piVar7,pcVar11,pAVar8,puVar9,iVar3);
        if (iVar3 == 2) {
LAB_00607b88:
          uVar4 = (*(code *)PTR_ASN1_item_i2d_006a8678)(pcVar11,&iStack_f8,piVar7);
          if (iStack_f8 == 0) {
            uVar10 = 0x41;
            uVar4 = 0xcb;
            goto LAB_00607b58;
          }
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_ec,iStack_f8,uVar4);
          if (iVar3 == 0) {
            uVar4 = 0xd0;
          }
          else {
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(iStack_f8,uVar4);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_f8);
            piVar2 = (int *)puVar9[2];
            iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)(auStack_ec,piVar2,*puVar9);
            if (0 < iVar3) {
              iVar3 = 1;
              goto LAB_00607a64;
            }
            uVar4 = 0xda;
          }
LAB_00607bd8:
          piVar2 = (int *)0xc5;
          iVar3 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,6,"a_verify.c",uVar4);
        }
      }
LAB_00607a64:
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_ec);
      goto LAB_00607a78;
    }
    uVar10 = 0xdc;
    uVar4 = 0x97;
  }
  piVar2 = (int *)0xc5;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar10,"a_verify.c",uVar4);
  iVar3 = -1;
LAB_00607a78:
  if (iStack_d4 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    *piVar2 = *piVar2 + 1;
    return 1;
  }
  return iVar3;
}

