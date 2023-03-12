
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
  ASN1_BIT_STRING *pAStack_7c;
  undefined4 uStack_78;
  code *pcStack_74;
  int local_60;
  undefined *local_58;
  EVP_PKEY *local_4c;
  int local_48;
  undefined auStack_44 [24];
  int *local_2c;
  
  puStack_8c = PTR___stack_chk_guard_006a9ae8;
  puStack_90 = auStack_44;
  local_4c = pkey;
  local_58 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_90);
  uVar2 = (**(code **)(local_58 + -0x7cb4))(algor1->algorithm);
  uVar2 = (**(code **)(local_58 + -0x7d44))(uVar2);
  iVar3 = (**(code **)(local_58 + -0x7eb4))(uVar2);
  if (iVar3 == 0) {
    pcVar12 = *(code **)(local_58 + -0x6eac);
    puVar9 = (undefined4 *)0xa1;
    local_60 = 0x59;
LAB_006078ec:
    pcVar11 = "a_verify.c";
    puVar7 = (undefined4 *)&DAT_00000089;
    iStack_88 = -1;
    (*pcVar12)(0xd,0x89,puVar9,"a_verify.c");
  }
  else {
    if ((signature->type == 3) && ((signature->flags & 7U) != 0)) {
      pcVar12 = *(code **)(local_58 + -0x6eac);
      puVar9 = (undefined4 *)&DAT_000000dc;
      local_60 = 0x5e;
      goto LAB_006078ec;
    }
    unaff_s6 = (*(code *)i2d)(data,0);
    iVar4 = (**(code **)(local_58 + -0x7dd8))(unaff_s6,"a_verify.c",99);
    if (iVar4 == 0) {
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000041;
      puVar7 = (undefined4 *)&DAT_00000089;
      local_60 = 0x65;
      iStack_88 = -1;
      (**(code **)(local_58 + -0x6eac))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      local_48 = iVar4;
      (*(code *)i2d)(data,&local_48);
      iVar3 = (**(code **)(local_58 + -0x7864))(puStack_90,iVar3,0);
      if ((iVar3 == 0) ||
         (iVar3 = (**(code **)(local_58 + -0x7860))(puStack_90,iVar4,unaff_s6), iVar3 == 0)) {
        pcVar12 = *(code **)(local_58 + -0x6eac);
        local_60 = 0x6d;
      }
      else {
        (**(code **)(local_58 + -0x7d6c))(iVar4,unaff_s6);
        (**(code **)(local_58 + -0x7f58))(iVar4);
        puVar9 = (undefined4 *)signature->length;
        puVar7 = (undefined4 *)signature->data;
        pcVar11 = (char *)local_4c;
        iVar3 = (**(code **)(local_58 + -0x6e04))(puStack_90,puVar7,puVar9,local_4c);
        if (0 < iVar3) {
          iStack_88 = 1;
          goto LAB_0060782c;
        }
        pcVar12 = *(code **)(local_58 + -0x6eac);
        local_60 = 0x77;
      }
      pcVar11 = "a_verify.c";
      puVar9 = (undefined4 *)&DAT_00000006;
      puVar7 = (undefined4 *)&DAT_00000089;
      iStack_88 = 0;
      (*pcVar12)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_0060782c:
  (**(code **)(local_58 + -0x7fac))(puStack_90);
  if (local_2c == *(int **)puStack_8c) {
    return iStack_88;
  }
  pcStack_74 = ASN1_item_verify;
  piVar6 = local_2c;
  (**(code **)(local_58 + -0x5330))();
  iVar3 = local_60;
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_b8 = 0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_84 = i2d;
  pcStack_80 = data;
  pAStack_7c = signature;
  uStack_78 = unaff_s6;
  if (local_60 == 0) {
    uVar10 = 0x43;
    uVar2 = 0x92;
  }
  else {
    if ((puVar9[1] != 3) || ((puVar9[3] & 7) == 0)) {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_ac);
      uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar7);
      iVar4 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(uVar2,&iStack_b4,&uStack_b0);
      if (iVar4 == 0) {
        uVar10 = 199;
        uVar2 = 0x9f;
LAB_00607b58:
        piVar8 = (int *)0xc5;
        iVar3 = -1;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar10,"a_verify.c",uVar2);
      }
      else {
        if (iStack_b4 != 0) {
          uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)();
          iVar4 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
          if (iVar4 == 0) {
            uVar10 = 0xa1;
            uVar2 = 0xb6;
          }
          else {
            iVar5 = (*(code *)PTR_EVP_PKEY_type_006a97e0)(uStack_b0);
            if (iVar5 == **(int **)(iVar3 + 0xc)) {
              iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)(auStack_ac,0,iVar4,0,iVar3);
              if (iVar3 != 0) goto LAB_00607b88;
              uVar2 = 0xc1;
              goto LAB_00607bd8;
            }
            uVar10 = 200;
            uVar2 = 0xbc;
          }
          goto LAB_00607b58;
        }
        if ((*(int *)(iVar3 + 0xc) == 0) ||
           (pcVar12 = *(code **)(*(int *)(iVar3 + 0xc) + 100), pcVar12 == (code *)0x0)) {
          uVar10 = 199;
          uVar2 = 0xa5;
          goto LAB_00607b58;
        }
        piVar8 = piVar6;
        iVar3 = (*pcVar12)(auStack_ac,piVar6,pcVar11,puVar7,puVar9,iVar3);
        if (iVar3 == 2) {
LAB_00607b88:
          uVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)(pcVar11,&iStack_b8,piVar6);
          if (iStack_b8 == 0) {
            uVar10 = 0x41;
            uVar2 = 0xcb;
            goto LAB_00607b58;
          }
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_ac,iStack_b8,uVar2);
          if (iVar3 == 0) {
            uVar2 = 0xd0;
          }
          else {
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(iStack_b8,uVar2);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_b8);
            piVar8 = (int *)puVar9[2];
            iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)(auStack_ac,piVar8,*puVar9);
            if (0 < iVar3) {
              iVar3 = 1;
              goto LAB_00607a64;
            }
            uVar2 = 0xda;
          }
LAB_00607bd8:
          piVar8 = (int *)0xc5;
          iVar3 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,6,"a_verify.c",uVar2);
        }
      }
LAB_00607a64:
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_ac);
      goto LAB_00607a78;
    }
    uVar10 = 0xdc;
    uVar2 = 0x97;
  }
  piVar8 = (int *)0xc5;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar10,"a_verify.c",uVar2);
  iVar3 = -1;
LAB_00607a78:
  if (iStack_94 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    *piVar8 = *piVar8 + 1;
    return 1;
  }
  return iVar3;
}

