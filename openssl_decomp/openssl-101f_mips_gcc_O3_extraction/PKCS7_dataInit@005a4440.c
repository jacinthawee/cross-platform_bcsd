
BIO * PKCS7_dataInit(PKCS7 *p7,BIO *bio)

{
  X509_ALGOR *pXVar1;
  undefined *puVar2;
  undefined4 uVar3;
  BIO_METHOD *pBVar4;
  stack_st_X509 *psVar5;
  int iVar6;
  ASN1_OCTET_STRING *pAVar7;
  PKCS7_SIGN_ENVELOPE *pPVar8;
  undefined4 *puVar9;
  PKCS7_ENC_CONTENT *pPVar10;
  int iVar11;
  long lVar12;
  PKCS7 *p7_00;
  BIO *in_a2;
  undefined4 uVar13;
  char *in_a3;
  BIO *unaff_s0;
  BIO *pBVar14;
  pkcs7_st *ppVar15;
  BIO *unaff_s1;
  BIO *pBVar16;
  int iVar17;
  BIO *pBVar18;
  BIO *pBVar19;
  BIO *unaff_s3;
  stack_st_X509_ALGOR *psVar20;
  BIO *unaff_s4;
  stack_st_PKCS7_RECIP_INFO *psVar21;
  BIO *unaff_s7;
  code *pcVar22;
  X509_ALGOR *unaff_s8;
  BIO *pBStack_110;
  int iStack_10c;
  ASN1_OCTET_STRING *pAStack_108;
  X509_ALGOR *pXStack_104;
  undefined4 uStack_100;
  int iStack_fc;
  BIO *pBStack_f8;
  int iStack_f4;
  BIO *pBStack_f0;
  BIO *pBStack_ec;
  BIO *pBStack_e8;
  BIO *pBStack_e4;
  BIO *pBStack_e0;
  PKCS7 *pPStack_dc;
  undefined *puStack_d8;
  BIO *pBStack_d4;
  X509_ALGOR *pXStack_d0;
  code *pcStack_cc;
  BIO *local_b8;
  X509_ALGOR *local_b4;
  undefined *local_b0;
  stack_st_X509_ALGOR *local_a4;
  BIO *local_a0;
  BIO *local_9c;
  _union_444 local_98;
  BIO *local_94;
  BIO *local_90;
  char *local_8c;
  undefined local_84 [8];
  undefined auStack_7c [80];
  PKCS7 *local_2c;
  
  puStack_d8 = PTR___stack_chk_guard_006aabf0;
  local_b0 = &_gp;
  local_2c = *(PKCS7 **)PTR___stack_chk_guard_006aabf0;
  local_a0 = bio;
  uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  p7->state = 0;
  switch(uVar3) {
  case 0x15:
    unaff_s3 = (BIO *)0x0;
    local_98.ptr = (char *)0x0;
    unaff_s7 = (BIO *)0x0;
    local_9c = (BIO *)0x0;
    unaff_s8 = (X509_ALGOR *)0x0;
    local_a4 = (stack_st_X509_ALGOR *)0x0;
    break;
  case 0x16:
    ppVar15 = ((p7->d).sign)->contents;
    unaff_s3 = (BIO *)((p7->d).sign)->md_algs;
    iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar15->type);
    if (iVar6 == 0x15) {
      local_98 = ppVar15->d;
    }
    else {
      iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar15->type);
      if (((iVar6 - 0x15U < 6) || (pAVar7 = (ppVar15->d).data, pAVar7 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar7->length != 4)) {
        local_98.ptr = (char *)0x0;
        unaff_s7 = (BIO *)0x0;
        local_9c = (BIO *)0x0;
        unaff_s8 = (X509_ALGOR *)0x0;
        local_a4 = (stack_st_X509_ALGOR *)0x0;
        break;
      }
      local_98 = (_union_444)pAVar7->type;
    }
    unaff_s7 = (BIO *)0x0;
    local_9c = (BIO *)0x0;
    unaff_s8 = (X509_ALGOR *)0x0;
    local_a4 = (stack_st_X509_ALGOR *)0x0;
    break;
  case 0x17:
    psVar5 = ((p7->d).sign)->cert;
    local_a4 = ((p7->d).sign)->md_algs;
    unaff_s7 = (BIO *)(psVar5->stack).num_alloc;
    local_9c = (BIO *)(psVar5->stack).data;
    if (unaff_s7 == (BIO *)0x0) {
      pcVar22 = *(code **)(local_b0 + -0x6eb0);
      in_a2 = (BIO *)&DAT_00000074;
      local_b8 = (BIO *)0x12f;
      goto LAB_005a4bec;
    }
    local_98.ptr = (char *)0x0;
    unaff_s3 = (BIO *)0x0;
    unaff_s8 = (X509_ALGOR *)0x0;
    break;
  case 0x18:
    pPVar8 = (p7->d).signed_and_enveloped;
    local_a4 = (stack_st_X509_ALGOR *)pPVar8->recipientinfo;
    unaff_s3 = (BIO *)pPVar8->md_algs;
    local_9c = (BIO *)pPVar8->enc_data->algorithm;
    unaff_s7 = (BIO *)pPVar8->enc_data->cipher;
    if (unaff_s7 == (BIO *)0x0) {
      pcVar22 = *(code **)(local_b0 + -0x6eb0);
      in_a2 = (BIO *)&DAT_00000074;
      local_b8 = (BIO *)0x124;
      goto LAB_005a4bec;
    }
    local_98.ptr = (char *)0x0;
    unaff_s8 = (X509_ALGOR *)0x0;
    break;
  case 0x19:
    ppVar15 = ((p7->d).digest)->contents;
    unaff_s8 = ((p7->d).digest)->md;
    iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar15->type);
    if (iVar6 == 0x15) {
      local_98 = ppVar15->d;
    }
    else {
      iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar15->type);
      if (((iVar6 - 0x15U < 6) || (pAVar7 = (ppVar15->d).data, pAVar7 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar7->length != 4)) {
        local_98.ptr = (char *)0x0;
        unaff_s3 = (BIO *)0x0;
        local_9c = (BIO *)0x0;
        unaff_s7 = (BIO *)0x0;
        local_a4 = (stack_st_X509_ALGOR *)0x0;
        break;
      }
      local_98 = (_union_444)pAVar7->type;
    }
    unaff_s3 = (BIO *)0x0;
    local_9c = (BIO *)0x0;
    unaff_s7 = (BIO *)0x0;
    local_a4 = (stack_st_X509_ALGOR *)0x0;
    break;
  default:
    pcVar22 = *(code **)(local_b0 + -0x6eb0);
    in_a2 = (BIO *)&DAT_00000070;
    local_b8 = (BIO *)0x13a;
LAB_005a4bec:
    in_a3 = "pk7_doit.c";
    bio = (BIO *)&DAT_00000069;
    (*pcVar22)(0x21);
    pBStack_e8 = (BIO *)0x0;
    goto LAB_005a4998;
  }
  unaff_s0 = (BIO *)0x0;
  pBVar18 = (BIO *)0x0;
  iVar6 = (**(code **)(local_b0 + -0x7fb4))(unaff_s3);
  pBVar19 = pBVar18;
  if (0 < iVar6) {
    do {
      unaff_s4 = (BIO *)(**(code **)(local_b0 + -0x7fbc))(unaff_s3,unaff_s0);
      uVar3 = (**(code **)(local_b0 + -0x790c))();
      unaff_s1 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
      pBVar18 = pBVar19;
      if (unaff_s1 == (BIO *)0x0) goto LAB_005a49e4;
      uVar3 = (**(code **)(local_b0 + -0x7cb4))(unaff_s4->method);
      uVar3 = (**(code **)(local_b0 + -0x7d44))(uVar3);
      in_a3 = (char *)(**(code **)(local_b0 + -0x7eb4))(uVar3);
      if ((BIO *)in_a3 == (BIO *)0x0) {
        pcVar22 = *(code **)(local_b0 + -0x6eb0);
        in_a2 = (BIO *)&DAT_0000006d;
        local_b8 = (BIO *)&DAT_00000076;
LAB_005a4944:
        in_a3 = "pk7_doit.c";
        bio = (BIO *)0x7d;
        (*pcVar22)(0x21);
        (**(code **)(local_b0 + -0x7f70))(unaff_s1);
        goto joined_r0x005a4a0c;
      }
      in_a2 = (BIO *)0x0;
      bio = (BIO *)&DAT_0000006f;
      (**(code **)(local_b0 + -0x7fc8))(unaff_s1);
      pBVar18 = unaff_s1;
      if ((pBVar19 != (BIO *)0x0) &&
         (bio = unaff_s1, iVar6 = (**(code **)(local_b0 + -0x7920))(pBVar19), pBVar18 = pBVar19,
         iVar6 == 0)) {
        pcVar22 = *(code **)(local_b0 + -0x6eb0);
        in_a2 = (BIO *)&DAT_00000020;
        local_b8 = (BIO *)0x7f;
        goto LAB_005a4944;
      }
      unaff_s0 = (BIO *)((int)&unaff_s0->method + 1);
      iVar6 = (**(code **)(local_b0 + -0x7fb4))(unaff_s3);
      pBVar19 = pBVar18;
    } while ((int)unaff_s0 < iVar6);
  }
  pBVar19 = pBVar18;
  if (unaff_s8 == (X509_ALGOR *)0x0) {
LAB_005a4660:
    if (unaff_s7 == (BIO *)0x0) {
LAB_005a4b74:
      if (local_a0 == (BIO *)0x0) {
        iVar6 = (**(code **)(local_b0 + -0x7cb4))(p7->type);
        if (iVar6 == 0x16) {
          in_a3 = (char *)0x0;
          in_a2 = (BIO *)0x0;
          bio = (BIO *)&SUB_00000002;
          lVar12 = PKCS7_ctrl(p7,2,0,(char *)0x0);
          if (lVar12 == 0) goto LAB_005a4ce0;
          uVar3 = (**(code **)(local_b0 + -0x74f4))();
          local_a0 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
LAB_005a4d08:
          if (local_a0 != (BIO *)0x0) goto LAB_005a4b7c;
LAB_005a4d10:
          pcVar22 = *(code **)(local_b0 + -0x71dc);
        }
        else {
LAB_005a4ce0:
          pcVar22 = *(code **)(local_b0 + -0x71dc);
          if (local_98.ptr != (char *)0x0) {
            bio = (BIO *)(local_98.data)->length;
            if (0 < (int)bio) {
              local_a0 = (BIO *)(**(code **)(local_b0 + -0x5c7c))((local_98.data)->data);
              goto LAB_005a4d08;
            }
            goto LAB_005a4d10;
          }
        }
        uVar3 = (*pcVar22)();
        local_a0 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
        pBVar19 = pBVar18;
        if (local_a0 == (BIO *)0x0) goto joined_r0x005a4a0c;
        in_a3 = (char *)0x0;
        in_a2 = (BIO *)0x0;
        bio = (BIO *)0x82;
        (**(code **)(local_b0 + -0x7fc8))(local_a0);
      }
LAB_005a4b7c:
      pBStack_e8 = local_a0;
      if (pBVar18 != (BIO *)0x0) {
        bio = local_a0;
        (**(code **)(local_b0 + -0x7920))(pBVar18);
        pBStack_e8 = pBVar18;
      }
    }
    else {
LAB_005a4668:
      uVar3 = (**(code **)(local_b0 + -0x7898))();
      unaff_s4 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
      if (unaff_s4 != (BIO *)0x0) {
        in_a3 = local_84;
        in_a2 = (BIO *)0x0;
        (**(code **)(local_b0 + -0x7fc8))(unaff_s4,0x81);
        local_94 = (BIO *)(**(code **)(local_b0 + -0x6ea4))(unaff_s7);
        unaff_s0 = (BIO *)(**(code **)(local_b0 + -0x7884))(unaff_s7);
        uVar3 = (**(code **)(local_b0 + -0x6150))(unaff_s7);
        pBVar4 = (BIO_METHOD *)(**(code **)(local_b0 + -0x7ca0))(uVar3);
        local_9c->method = pBVar4;
        if (((int)unaff_s0 < 1) ||
           (bio = unaff_s0, iVar6 = (**(code **)(local_b0 + -0x787c))(auStack_7c), 0 < iVar6)) {
          unaff_s1 = (BIO *)0x1;
          in_a3 = (char *)0x0;
          in_a2 = (BIO *)0x0;
          local_b8 = (BIO *)0x0;
          local_b4 = (X509_ALGOR *)0x1;
          bio = unaff_s7;
          iVar6 = (**(code **)(local_b0 + -0x7894))(local_84._0_4_);
          if (iVar6 < 1) goto LAB_005a4bc8;
          unaff_s3 = (BIO *)(auStack_7c + 0x10);
          bio = unaff_s3;
          local_90 = unaff_s3;
          iVar6 = (**(code **)(local_b0 + -0x5c84))(local_84._0_4_);
          if (iVar6 < 1) goto LAB_005a4bc8;
          local_b8 = (BIO *)auStack_7c;
          in_a2 = (BIO *)0x0;
          bio = (BIO *)0x0;
          local_b4 = (X509_ALGOR *)0x1;
          in_a3 = (char *)unaff_s3;
          iVar6 = (**(code **)(local_b0 + -0x7894))(local_84._0_4_);
          if (iVar6 < 1) goto LAB_005a4bc8;
          if ((int)unaff_s0 < 1) {
LAB_005a47bc:
            unaff_s7 = (BIO *)(local_84 + 4);
            local_8c = "pk7_doit.c";
            for (unaff_s0 = (BIO *)0x0; iVar6 = (**(code **)(local_b0 + -0x7fb4))(local_a4),
                (int)unaff_s0 < iVar6; unaff_s0 = (BIO *)((int)&unaff_s0->method + 1)) {
              bio = unaff_s0;
              unaff_s8 = (X509_ALGOR *)(**(code **)(local_b0 + -0x7fbc))(local_a4);
              unaff_s1 = (BIO *)(**(code **)(local_b0 + -0x7ed8))(unaff_s8[2].algorithm);
              if (unaff_s1 == (BIO *)0x0) goto LAB_005a4bc8;
              bio = (BIO *)0x0;
              unaff_s3 = (BIO *)(**(code **)(local_b0 + -0x7e00))(unaff_s1);
              if (unaff_s3 == (BIO *)0x0) goto LAB_005a4bc8;
              iVar6 = (**(code **)(local_b0 + -0x7104))(unaff_s3);
              if (iVar6 < 1) {
LAB_005a4928:
                unaff_s8 = (X509_ALGOR *)0x0;
              }
              else {
                local_b8 = (BIO *)0x0;
                local_b4 = unaff_s8;
                iVar6 = (**(code **)(local_b0 + -0x7df4))(unaff_s3,0xffffffff,0x100,3);
                if (iVar6 < 1) {
                  pcVar22 = *(code **)(local_b0 + -0x6eb0);
                  in_a2 = (BIO *)&DAT_00000098;
                  local_b8 = (BIO *)0xa5;
LAB_005a4dbc:
                  bio = (BIO *)&DAT_00000084;
                  unaff_s8 = (X509_ALGOR *)0x0;
                  in_a3 = local_8c;
                  (*pcVar22)(0x21);
                }
                else {
                  bio = (BIO *)0x0;
                  local_b8 = local_94;
                  in_a2 = unaff_s7;
                  in_a3 = (char *)local_90;
                  iVar6 = (**(code **)(local_b0 + -0x70dc))(unaff_s3);
                  if (iVar6 < 1) goto LAB_005a4928;
                  bio = (BIO *)(**(code **)(local_b0 + -0x7dd8))(local_84._4_4_,local_8c,0xac);
                  local_9c = bio;
                  if (bio == (BIO *)0x0) {
                    pcVar22 = *(code **)(local_b0 + -0x6eb0);
                    in_a2 = (BIO *)&DAT_00000041;
                    local_b8 = (BIO *)&DAT_000000b0;
                    goto LAB_005a4dbc;
                  }
                  local_b8 = local_94;
                  in_a2 = unaff_s7;
                  in_a3 = (char *)local_90;
                  iVar6 = (**(code **)(local_b0 + -0x70dc))(unaff_s3);
                  if (iVar6 < 1) {
                    (**(code **)(local_b0 + -0x7f68))(unaff_s1);
                    (**(code **)(local_b0 + -0x7f64))(unaff_s3);
                    (**(code **)(local_b0 + -0x7f58))(local_9c);
                    goto LAB_005a4bc8;
                  }
                  pXVar1 = unaff_s8 + 1;
                  unaff_s8 = (X509_ALGOR *)0x1;
                  bio = local_9c;
                  in_a2 = local_84._4_4_;
                  (**(code **)(local_b0 + -0x5c80))(pXVar1->parameter);
                }
              }
              (**(code **)(local_b0 + -0x7f68))(unaff_s1);
              (**(code **)(local_b0 + -0x7f64))(unaff_s3);
              if (unaff_s8 == (X509_ALGOR *)0x0) goto LAB_005a4bc8;
            }
            bio = local_94;
            (**(code **)(local_b0 + -0x7d6c))(local_90);
            pBVar18 = unaff_s4;
            if (pBVar19 != (BIO *)0x0) {
              bio = unaff_s4;
              (**(code **)(local_b0 + -0x7920))(pBVar19);
              pBVar18 = pBVar19;
            }
            goto LAB_005a4b74;
          }
          bio = (BIO *)local_9c->callback;
          if (bio != (BIO *)0x0) {
LAB_005a47a8:
            iVar6 = (**(code **)(local_b0 + -0x5fc8))(local_84._0_4_);
            if (iVar6 < 0) goto LAB_005a4bc8;
            goto LAB_005a47bc;
          }
          bio = (BIO *)(**(code **)(local_b0 + -0x6f24))();
          local_9c->callback = (_func_603 *)bio;
          if (bio != (BIO *)0x0) goto LAB_005a47a8;
          pcVar22 = *(code **)(local_b0 + -0x7f6c);
        }
        else {
LAB_005a4bc8:
          pcVar22 = *(code **)(local_b0 + -0x7f6c);
        }
        if (pBVar19 != (BIO *)0x0) goto LAB_005a4970;
        goto LAB_005a498c;
      }
      in_a2 = (BIO *)&DAT_00000020;
      in_a3 = "pk7_doit.c";
      local_b8 = (BIO *)0x14e;
      bio = (BIO *)&DAT_00000069;
      (**(code **)(local_b0 + -0x6eb0))(0x21);
      if (pBVar19 != (BIO *)0x0) goto LAB_005a4970;
      pBStack_e8 = (BIO *)0x0;
    }
  }
  else {
    uVar3 = (**(code **)(local_b0 + -0x790c))();
    unaff_s0 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
    if (unaff_s0 == (BIO *)0x0) {
LAB_005a49e4:
      in_a2 = (BIO *)&DAT_00000020;
      in_a3 = "pk7_doit.c";
      local_b8 = (BIO *)&DAT_0000006f;
      bio = (BIO *)0x7d;
      (**(code **)(local_b0 + -0x6eb0))(0x21);
      pBVar19 = pBVar18;
    }
    else {
      uVar3 = (**(code **)(local_b0 + -0x7cb4))(unaff_s8->algorithm);
      uVar3 = (**(code **)(local_b0 + -0x7d44))(uVar3);
      in_a3 = (char *)(**(code **)(local_b0 + -0x7eb4))(uVar3);
      if ((BIO *)in_a3 == (BIO *)0x0) {
        pcVar22 = *(code **)(local_b0 + -0x6eb0);
        in_a2 = (BIO *)&DAT_0000006d;
        local_b8 = (BIO *)&DAT_00000076;
      }
      else {
        in_a2 = (BIO *)0x0;
        bio = (BIO *)&DAT_0000006f;
        (**(code **)(local_b0 + -0x7fc8))(unaff_s0);
        if (pBVar18 == (BIO *)0x0) {
          pBVar18 = unaff_s0;
          pBVar19 = unaff_s0;
          if (unaff_s7 != (BIO *)0x0) goto LAB_005a4668;
          goto LAB_005a4b74;
        }
        bio = unaff_s0;
        iVar6 = (**(code **)(local_b0 + -0x7920))(pBVar18);
        if (iVar6 != 0) goto LAB_005a4660;
        pcVar22 = *(code **)(local_b0 + -0x6eb0);
        in_a2 = (BIO *)&DAT_00000020;
        local_b8 = (BIO *)0x7f;
      }
      in_a3 = "pk7_doit.c";
      bio = (BIO *)0x7d;
      (*pcVar22)(0x21);
      (**(code **)(local_b0 + -0x7f70))(unaff_s0);
    }
joined_r0x005a4a0c:
    unaff_s4 = (BIO *)0x0;
    if (pBVar19 != (BIO *)0x0) {
LAB_005a4970:
      (**(code **)(local_b0 + -0x7f6c))(pBVar19);
      if (unaff_s4 != (BIO *)0x0) {
        pcVar22 = *(code **)(local_b0 + -0x7f6c);
LAB_005a498c:
        (*pcVar22)(unaff_s4);
        pBStack_e8 = (BIO *)0x0;
        goto LAB_005a4998;
      }
    }
    pBStack_e8 = (BIO *)0x0;
  }
LAB_005a4998:
  if (local_2c == *(PKCS7 **)puStack_d8) {
    return pBStack_e8;
  }
  pcStack_cc = PKCS7_dataDecode;
  p7_00 = local_2c;
  (**(code **)(local_b0 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  uStack_100 = 0;
  iStack_fc = 0;
  pBStack_f8 = (BIO *)0x0;
  iStack_f4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_f0 = unaff_s0;
  pBStack_ec = unaff_s1;
  pBStack_e4 = unaff_s3;
  pBStack_e0 = unaff_s4;
  pPStack_dc = p7;
  pBStack_d4 = unaff_s7;
  pXStack_d0 = unaff_s8;
  iVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7_00->type);
  p7_00->state = 0;
  pBStack_110 = in_a2;
  if (iVar6 == 0x17) {
    pBVar19 = (BIO *)0x0;
    pPVar10 = ((p7_00->d).enveloped)->enc_data;
    psVar21 = ((p7_00->d).enveloped)->recipientinfo;
    pXStack_104 = pPVar10->algorithm;
    pAStack_108 = pPVar10->enc_data;
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pXStack_104->algorithm);
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
    iStack_10c = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar3);
    if (iStack_10c == 0) {
      uVar13 = 0x6f;
      uVar3 = 0x1d0;
      goto LAB_005a4f48;
    }
  }
  else {
    if (iVar6 == 0x18) {
      pPVar8 = (p7_00->d).signed_and_enveloped;
      psVar21 = pPVar8->recipientinfo;
      psVar20 = pPVar8->md_algs;
      pXStack_104 = pPVar8->enc_data->algorithm;
      pAStack_108 = pPVar8->enc_data->enc_data;
      uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pXStack_104->algorithm);
      uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
      iStack_10c = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar3);
      if (iStack_10c == 0) {
        uVar13 = 0x6f;
        uVar3 = 0x1c5;
        goto LAB_005a4f48;
      }
      if (psVar20 == (stack_st_X509_ALGOR *)0x0) {
        pBVar19 = (BIO *)0x0;
        goto LAB_005a51cc;
      }
    }
    else {
      if (iVar6 != 0x16) {
        uVar13 = 0x70;
        uVar3 = 0x1d5;
LAB_005a4f48:
        (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,uVar13,"pk7_doit.c",uVar3);
        if (iStack_fc == 0) {
          pBVar18 = (BIO *)0x0;
          goto LAB_005a52e0;
        }
        unaff_s4 = (BIO *)0x0;
        iVar6 = 0;
        pBVar16 = (BIO *)0x0;
        pBVar14 = (BIO *)0x0;
        pBVar19 = (BIO *)0x0;
        goto LAB_005a5540;
      }
      ppVar15 = ((p7_00->d).sign)->contents;
      iVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar15->type);
      if (iVar6 == 0x15) {
        pAStack_108 = (ppVar15->d).data;
      }
      else {
        iVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar15->type);
        if (((iVar6 - 0x15U < 6) || (pAVar7 = (ppVar15->d).data, pAVar7 == (ASN1_OCTET_STRING *)0x0)
            ) || (pAVar7->length != 4)) {
          pAStack_108 = (ASN1_OCTET_STRING *)0x0;
        }
        else {
          pAStack_108 = (ASN1_OCTET_STRING *)pAVar7->type;
        }
      }
      psVar20 = (stack_st_X509_ALGOR *)((p7_00->d).data)->type;
      unaff_s4 = (BIO *)0x0;
      if (psVar20 == (stack_st_X509_ALGOR *)0x0) goto LAB_005a57e4;
      psVar21 = (stack_st_PKCS7_RECIP_INFO *)0x0;
      pXStack_104 = (X509_ALGOR *)0x0;
      iStack_10c = 0;
    }
    iVar17 = 0;
    pBVar19 = (BIO *)0x0;
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(psVar20);
    pBVar18 = pBVar19;
    if (0 < iVar6) {
      do {
        puVar9 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar20,iVar17);
        uVar3 = (*(code *)PTR_BIO_f_md_006a85d4)();
        pBVar19 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar3);
        pBVar14 = pBVar19;
        if (pBVar19 == (BIO *)0x0) {
          pBVar16 = (BIO *)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x20,"pk7_doit.c",0x1e1);
          unaff_s4 = (BIO *)0x0;
          pBVar19 = pBVar18;
          goto joined_r0x005a5298;
        }
        uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar9);
        uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
        iVar6 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar3);
        if (iVar6 == 0) {
          unaff_s4 = (BIO *)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x6d,"pk7_doit.c",0x1e9);
          pBVar16 = (BIO *)0x0;
          pBVar19 = pBVar18;
          goto joined_r0x005a5298;
        }
        (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar19,0x6f,0,iVar6);
        if (pBVar18 != (BIO *)0x0) {
          (*(code *)PTR_BIO_push_006a85c0)(pBVar18,pBVar19);
          pBVar19 = pBVar18;
        }
        iVar17 = iVar17 + 1;
        iVar6 = (*(code *)PTR_sk_num_006a7f2c)(psVar20);
        pBVar18 = pBVar19;
      } while (iVar17 < iVar6);
    }
    unaff_s4 = (BIO *)0x0;
    pBVar18 = pBVar19;
    if (iStack_10c == 0) goto LAB_005a5128;
  }
LAB_005a51cc:
  uVar3 = (*(code *)PTR_BIO_f_cipher_006a8648)();
  pBVar16 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar3);
  if (pBVar16 == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x20,"pk7_doit.c",0x203);
    unaff_s4 = (BIO *)0x0;
    pBVar14 = (BIO *)0x0;
  }
  else {
    iVar6 = 0;
    if ((BIO *)in_a3 == (BIO *)0x0) {
      for (; iVar17 = (*(code *)PTR_sk_num_006a7f2c)(psVar21), iVar6 < iVar17; iVar6 = iVar6 + 1) {
        uVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar21,iVar6);
        iVar17 = pkcs7_decrypt_rinfo(&iStack_fc,&pBStack_f8,uVar3,bio);
        if (iVar17 < 0) goto LAB_005a5624;
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
      }
LAB_005a536c:
      uStack_100 = 0;
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar16,0x81,0,&uStack_100);
      iVar6 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(uStack_100,iStack_10c,0,0,0,0);
      if ((iVar6 < 1) ||
         (iVar6 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a9dac)
                            (uStack_100,pXStack_104->parameter), iVar6 < 0)) {
LAB_005a5624:
        unaff_s4 = (BIO *)0x0;
      }
      else {
        unaff_s4 = (BIO *)(*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(uStack_100);
        iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(unaff_s4,"pk7_doit.c",0x240);
        if (iVar6 != 0) {
          iVar17 = (*(code *)PTR_EVP_CIPHER_CTX_rand_key_006aa25c)(uStack_100,iVar6);
          if (iVar17 < 1) {
            pBVar14 = (BIO *)0x0;
            if (iStack_fc != 0) goto LAB_005a5540;
            goto LAB_005a5568;
          }
          iVar17 = iVar6;
          if (iStack_fc == 0) {
            iVar17 = 0;
            iStack_fc = iVar6;
            pBStack_f8 = unaff_s4;
          }
          pBVar18 = (BIO *)(*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(uStack_100);
          iVar6 = iVar17;
          if ((pBVar18 != pBStack_f8) &&
             (iVar11 = (*(code *)PTR_EVP_CIPHER_CTX_set_key_length_006a9ba8)(uStack_100),
             iVar11 == 0)) {
            (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_fc,pBStack_f8);
            (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_fc);
            iVar6 = 0;
            iStack_fc = iVar17;
            pBStack_f8 = unaff_s4;
          }
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          iVar17 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(uStack_100,0,0,iStack_fc,0,0);
          if (0 < iVar17) {
            if (iStack_fc != 0) {
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_fc,pBStack_f8);
              (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_fc);
              iStack_fc = 0;
            }
            if (iVar6 != 0) {
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar6,unaff_s4);
              (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
            }
            pBVar18 = pBVar16;
            if (pBVar19 == (BIO *)0x0) goto LAB_005a5128;
            (*(code *)PTR_BIO_push_006a85c0)(pBVar19,pBVar16);
            pBVar18 = pBVar19;
            goto LAB_005a5128;
          }
          pBVar14 = (BIO *)0x0;
          if (iStack_fc != 0) goto LAB_005a5540;
          goto LAB_005a5560;
        }
      }
      pBVar14 = (BIO *)0x0;
    }
    else {
      iVar17 = (*(code *)PTR_sk_num_006a7f2c)(psVar21);
      if (0 < iVar17) {
        do {
          iVar17 = (*(code *)PTR_sk_value_006a7f24)(psVar21,iVar6);
          iVar11 = (*(code *)PTR_X509_NAME_cmp_006a918c)
                             (**(undefined4 **)(iVar17 + 4),(*(BIO_METHOD **)in_a3)->bread);
          if ((iVar11 == 0) &&
             (iVar11 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)
                                 ((*(BIO_METHOD **)in_a3)->name,
                                  *(undefined4 *)(*(int *)(iVar17 + 4) + 4)), iVar11 == 0)) {
            iVar6 = pkcs7_decrypt_rinfo(&iStack_fc,&pBStack_f8,iVar17,bio);
            if (iVar6 < 0) goto LAB_005a5624;
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
            goto LAB_005a536c;
          }
          iVar6 = iVar6 + 1;
          iVar17 = (*(code *)PTR_sk_num_006a7f2c)(psVar21);
        } while (iVar6 < iVar17);
      }
      unaff_s4 = (BIO *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x73,"pk7_doit.c",0x21a);
      pBVar14 = (BIO *)0x0;
    }
  }
joined_r0x005a5298:
  if (iStack_fc != 0) {
    iVar6 = 0;
LAB_005a5540:
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_fc,pBStack_f8);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_fc);
LAB_005a5560:
    if (iVar6 != 0) {
LAB_005a5568:
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar6,unaff_s4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
    }
  }
  if (pBVar19 != (BIO *)0x0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(pBVar19);
  }
  if (pBVar14 != (BIO *)0x0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(pBVar14);
  }
  pBVar18 = pBVar16;
  if (pBVar16 != (BIO *)0x0) {
    pBVar18 = (BIO *)0x0;
    (*(code *)PTR_BIO_free_all_006a7f74)(pBVar16);
  }
LAB_005a52e0:
  do {
    if (iStack_f4 == *(int *)puVar2) {
      return pBVar18;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005a57e4:
    pBVar18 = (BIO *)0x0;
LAB_005a5128:
    iVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7_00->type);
    if (((iVar6 != 0x16) || (lVar12 = PKCS7_ctrl(p7_00,2,0,(char *)0x0), lVar12 == 0)) &&
       (pBStack_110 == (BIO *)0x0)) {
      if (pAStack_108->length < 1) {
        uVar3 = (*(code *)PTR_BIO_s_mem_006a8d04)();
        pBStack_110 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar3);
        (*(code *)PTR_BIO_ctrl_006a7f18)(pBStack_110,0x82,0,0);
      }
      else {
        pBStack_110 = (BIO *)(*(code *)PTR_BIO_new_mem_buf_006aa264)(pAStack_108->data);
      }
      if (pBStack_110 == (BIO *)0x0) break;
    }
    (*(code *)PTR_BIO_push_006a85c0)(pBVar18,pBStack_110);
  } while( true );
  pBVar16 = (BIO *)0x0;
  pBVar14 = (BIO *)0x0;
  pBVar19 = pBVar18;
  goto joined_r0x005a5298;
}

