
BIO * PKCS7_dataInit(PKCS7 *p7,BIO *bio)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  BIO_METHOD *pBVar4;
  stack_st_X509 *psVar5;
  int iVar6;
  BIO *pBVar7;
  PKCS7_SIGN_ENVELOPE *pPVar8;
  undefined4 *puVar9;
  PKCS7_ENC_CONTENT *pPVar10;
  long lVar11;
  ASN1_OCTET_STRING *pAVar12;
  _func_603 *p_Var13;
  PKCS7 *p7_00;
  BIO *in_a2;
  undefined4 uVar14;
  char *pcVar15;
  BIO *unaff_s0;
  BIO *pBVar16;
  BIO *unaff_s1;
  BIO *pBVar17;
  int iVar18;
  BIO *unaff_s2;
  BIO *pBVar19;
  pkcs7_st *ppVar20;
  BIO *unaff_s3;
  BIO *unaff_s4;
  _func_603 *p_Var21;
  PKCS7 *unaff_s5;
  BIO *unaff_s6;
  code *pcVar22;
  BIO *unaff_s8;
  ASN1_OCTET_STRING *pAStack_110;
  BIO *pBStack_10c;
  int iStack_108;
  X509_ALGOR *pXStack_104;
  undefined4 uStack_100;
  BIO BStack_fc;
  BIO *local_b8;
  BIO *local_b4;
  undefined *local_b0;
  stack_st_PKCS7_RECIP_INFO *local_a4;
  BIO *local_a0;
  BIO *local_9c;
  _union_444 local_98;
  BIO *local_94;
  BIO *local_90;
  char *local_8c;
  undefined local_84 [8];
  undefined auStack_7c [80];
  PKCS7 *local_2c;
  
  BStack_fc.prev_bio = (bio_st *)PTR___stack_chk_guard_006a9ae8;
  local_b0 = &_gp;
  local_2c = *(PKCS7 **)PTR___stack_chk_guard_006a9ae8;
  pcVar15 = "encrypt";
  pcVar22 = (code *)PTR_ERR_put_error_006a7f34;
  local_a0 = bio;
  if (p7 == (PKCS7 *)0x0) {
    in_a2 = (BIO *)0x8f;
    local_b8 = (BIO *)0x109;
    p7 = unaff_s5;
LAB_005a1e3c:
    pcVar15 = "pk7_doit.c";
    bio = (BIO *)&DAT_00000069;
    (*pcVar22)(0x21,0x69);
    pBVar19 = (BIO *)0x0;
  }
  else {
    if ((p7->d).ptr == (char *)0x0) {
      in_a2 = (BIO *)0x7a;
      local_b8 = (BIO *)0x117;
      goto LAB_005a1e3c;
    }
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
    p7->state = 0;
    switch(uVar3) {
    case 0x15:
      unaff_s2 = (BIO *)0x0;
      local_98.ptr = (char *)0x0;
      unaff_s8 = (BIO *)0x0;
      local_9c = (BIO *)0x0;
      unaff_s6 = (BIO *)0x0;
      local_a4 = (stack_st_PKCS7_RECIP_INFO *)0x0;
      break;
    case 0x16:
      ppVar20 = ((p7->d).sign)->contents;
      unaff_s2 = (BIO *)((p7->d).sign)->md_algs;
      iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar20->type);
      if (iVar6 == 0x15) {
        local_98 = ppVar20->d;
      }
      else {
        iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar20->type);
        if (((iVar6 - 0x15U < 6) ||
            (pAVar12 = (ppVar20->d).data, pAVar12 == (ASN1_OCTET_STRING *)0x0)) ||
           (pAVar12->length != 4)) {
          local_98.ptr = (char *)0x0;
          unaff_s8 = (BIO *)0x0;
          local_9c = (BIO *)0x0;
          unaff_s6 = (BIO *)0x0;
          local_a4 = (stack_st_PKCS7_RECIP_INFO *)0x0;
          break;
        }
        local_98 = (_union_444)pAVar12->type;
      }
      unaff_s8 = (BIO *)0x0;
      local_9c = (BIO *)0x0;
      unaff_s6 = (BIO *)0x0;
      local_a4 = (stack_st_PKCS7_RECIP_INFO *)0x0;
      break;
    case 0x17:
      psVar5 = ((p7->d).sign)->cert;
      local_a4 = (stack_st_PKCS7_RECIP_INFO *)((p7->d).sign)->md_algs;
      unaff_s8 = (BIO *)(psVar5->stack).num_alloc;
      local_9c = (BIO *)(psVar5->stack).data;
      if (unaff_s8 == (BIO *)0x0) {
        pcVar22 = *(code **)(local_b0 + -0x6eac);
        in_a2 = (BIO *)&DAT_00000074;
        local_b8 = (BIO *)0x132;
        goto LAB_005a1e3c;
      }
      local_98.ptr = (char *)0x0;
      unaff_s2 = (BIO *)0x0;
      unaff_s6 = (BIO *)0x0;
      break;
    case 0x18:
      pPVar8 = (p7->d).signed_and_enveloped;
      local_a4 = pPVar8->recipientinfo;
      unaff_s2 = (BIO *)pPVar8->md_algs;
      local_9c = (BIO *)pPVar8->enc_data->algorithm;
      unaff_s8 = (BIO *)pPVar8->enc_data->cipher;
      if (unaff_s8 == (BIO *)0x0) {
        pcVar22 = *(code **)(local_b0 + -0x6eac);
        in_a2 = (BIO *)&DAT_00000074;
        local_b8 = (BIO *)0x129;
        goto LAB_005a1e3c;
      }
      local_98.ptr = (char *)0x0;
      unaff_s6 = (BIO *)0x0;
      break;
    case 0x19:
      ppVar20 = ((p7->d).digest)->contents;
      unaff_s6 = (BIO *)((p7->d).digest)->md;
      iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar20->type);
      if (iVar6 == 0x15) {
        local_98 = ppVar20->d;
      }
      else {
        iVar6 = (**(code **)(local_b0 + -0x7cb4))(ppVar20->type);
        if (((iVar6 - 0x15U < 6) ||
            (pAVar12 = (ppVar20->d).data, pAVar12 == (ASN1_OCTET_STRING *)0x0)) ||
           (pAVar12->length != 4)) {
          local_98.ptr = (char *)0x0;
          unaff_s2 = (BIO *)0x0;
          local_9c = (BIO *)0x0;
          unaff_s8 = (BIO *)0x0;
          local_a4 = (stack_st_PKCS7_RECIP_INFO *)0x0;
          break;
        }
        local_98 = (_union_444)pAVar12->type;
      }
      unaff_s2 = (BIO *)0x0;
      local_9c = (BIO *)0x0;
      unaff_s8 = (BIO *)0x0;
      local_a4 = (stack_st_PKCS7_RECIP_INFO *)0x0;
      break;
    default:
      in_a2 = (BIO *)&DAT_00000070;
      local_b8 = (BIO *)&DAT_0000013d;
      pcVar22 = *(code **)(local_b0 + -0x6eac);
      goto LAB_005a1e3c;
    }
    unaff_s0 = (BIO *)0x0;
    pBVar19 = (BIO *)0x0;
    iVar6 = (**(code **)(local_b0 + -0x7fb4))(unaff_s2);
    pBVar16 = pBVar19;
    if (0 < iVar6) {
      do {
        unaff_s4 = (BIO *)(**(code **)(local_b0 + -0x7fbc))(unaff_s2,unaff_s0);
        uVar3 = (**(code **)(local_b0 + -0x7908))();
        unaff_s1 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
        pBVar19 = pBVar16;
        if (unaff_s1 == (BIO *)0x0) goto LAB_005a1d98;
        uVar3 = (**(code **)(local_b0 + -0x7cb4))(unaff_s4->method);
        uVar3 = (**(code **)(local_b0 + -0x7d44))(uVar3);
        pcVar15 = (char *)(**(code **)(local_b0 + -0x7eb4))(uVar3);
        if ((BIO *)pcVar15 == (BIO *)0x0) {
          pcVar22 = *(code **)(local_b0 + -0x6eac);
          in_a2 = (BIO *)&DAT_0000006d;
          local_b8 = (BIO *)&DAT_00000073;
LAB_005a1bec:
          pcVar15 = "pk7_doit.c";
          bio = (BIO *)0x7d;
          (*pcVar22)(0x21,0x7d);
          (**(code **)(local_b0 + -0x7f70))(unaff_s1);
          goto joined_r0x005a1dc0;
        }
        in_a2 = (BIO *)0x0;
        bio = (BIO *)&DAT_0000006f;
        (**(code **)(local_b0 + -0x7fc8))(unaff_s1,0x6f);
        pBVar19 = unaff_s1;
        if ((pBVar16 != (BIO *)0x0) &&
           (bio = unaff_s1, iVar6 = (**(code **)(local_b0 + -0x791c))(pBVar16,unaff_s1),
           pBVar19 = pBVar16, iVar6 == 0)) {
          pcVar22 = *(code **)(local_b0 + -0x6eac);
          in_a2 = (BIO *)&DAT_00000020;
          local_b8 = (BIO *)0x7b;
          goto LAB_005a1bec;
        }
        unaff_s0 = (BIO *)((int)&unaff_s0->method + 1);
        iVar6 = (**(code **)(local_b0 + -0x7fb4))(unaff_s2);
        pBVar16 = pBVar19;
      } while ((int)unaff_s0 < iVar6);
    }
    pBVar16 = pBVar19;
    if (unaff_s6 == (BIO *)0x0) {
LAB_005a190c:
      unaff_s3 = pBVar16;
      if (unaff_s8 == (BIO *)0x0) {
LAB_005a1eec:
        if (local_a0 == (BIO *)0x0) {
          iVar6 = (**(code **)(local_b0 + -0x7cb4))(p7->type);
          if (iVar6 == 0x16) {
            pcVar15 = (char *)0x0;
            in_a2 = (BIO *)0x0;
            bio = (BIO *)&SUB_00000002;
            lVar11 = PKCS7_ctrl(p7,2,0,(char *)0x0);
            if (lVar11 == 0) goto LAB_005a1f78;
            uVar3 = (**(code **)(local_b0 + -0x74d8))();
            local_a0 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
LAB_005a1fa0:
            if (local_a0 != (BIO *)0x0) goto LAB_005a1ef8;
LAB_005a1fa8:
            pcVar22 = *(code **)(local_b0 + -0x71c8);
          }
          else {
LAB_005a1f78:
            pcVar22 = *(code **)(local_b0 + -0x71c8);
            if (local_98.ptr != (char *)0x0) {
              bio = (BIO *)(local_98.data)->length;
              if (0 < (int)bio) {
                local_a0 = (BIO *)(**(code **)(local_b0 + -0x5c98))((local_98.data)->data);
                goto LAB_005a1fa0;
              }
              goto LAB_005a1fa8;
            }
          }
          uVar3 = (*pcVar22)();
          local_a0 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
          pBVar16 = unaff_s3;
          if (local_a0 == (BIO *)0x0) goto joined_r0x005a1dc0;
          pcVar15 = (char *)0x0;
          in_a2 = (BIO *)0x0;
          bio = (BIO *)0x82;
          (**(code **)(local_b0 + -0x7fc8))(local_a0,0x82);
        }
LAB_005a1ef8:
        pBVar19 = local_a0;
        if (unaff_s3 != (BIO *)0x0) {
          bio = local_a0;
          (**(code **)(local_b0 + -0x791c))(unaff_s3,local_a0);
          pBVar19 = unaff_s3;
        }
      }
      else {
        uVar3 = (**(code **)(local_b0 + -0x7888))();
        unaff_s4 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
        if (unaff_s4 != (BIO *)0x0) {
          pcVar15 = local_84;
          in_a2 = (BIO *)0x0;
          (**(code **)(local_b0 + -0x7fc8))(unaff_s4,0x81);
          local_94 = (BIO *)(**(code **)(local_b0 + -0x788c))(unaff_s8);
          unaff_s0 = (BIO *)(**(code **)(local_b0 + -0x7890))(unaff_s8);
          uVar3 = (**(code **)(local_b0 + -0x5fe8))(unaff_s8);
          pBVar4 = (BIO_METHOD *)(**(code **)(local_b0 + -0x7ca0))(uVar3);
          local_9c->method = pBVar4;
          if (((int)unaff_s0 < 1) ||
             (bio = unaff_s0, iVar6 = (**(code **)(local_b0 + -0x786c))(auStack_7c,unaff_s0),
             0 < iVar6)) {
            unaff_s1 = (BIO *)0x1;
            pcVar15 = (char *)0x0;
            in_a2 = (BIO *)0x0;
            local_b8 = (BIO *)0x0;
            local_b4 = (BIO *)0x1;
            bio = unaff_s8;
            iVar6 = (**(code **)(local_b0 + -0x7880))(local_84._0_4_,unaff_s8);
            if (iVar6 < 1) goto LAB_005a1e18;
            unaff_s2 = (BIO *)(auStack_7c + 0x10);
            bio = unaff_s2;
            local_90 = unaff_s2;
            iVar6 = (**(code **)(local_b0 + -0x5ca0))(local_84._0_4_,unaff_s2);
            if (iVar6 < 1) goto LAB_005a1e18;
            local_b8 = (BIO *)auStack_7c;
            in_a2 = (BIO *)0x0;
            bio = (BIO *)0x0;
            local_b4 = (BIO *)0x1;
            pcVar15 = (char *)unaff_s2;
            iVar6 = (**(code **)(local_b0 + -0x7880))(local_84._0_4_,0);
            if (iVar6 < 1) goto LAB_005a1e18;
            if ((int)unaff_s0 < 1) {
LAB_005a1a64:
              unaff_s8 = (BIO *)(local_84 + 4);
              local_8c = "pk7_doit.c";
              for (unaff_s0 = (BIO *)0x0; iVar6 = (**(code **)(local_b0 + -0x7fb4))(local_a4),
                  (int)unaff_s0 < iVar6; unaff_s0 = (BIO *)((int)&unaff_s0->method + 1)) {
                bio = unaff_s0;
                unaff_s6 = (BIO *)(**(code **)(local_b0 + -0x7fbc))(local_a4,unaff_s0);
                unaff_s1 = (BIO *)(**(code **)(local_b0 + -0x7ed8))(unaff_s6->shutdown);
                if (unaff_s1 == (BIO *)0x0) goto LAB_005a1e18;
                bio = (BIO *)0x0;
                unaff_s2 = (BIO *)(**(code **)(local_b0 + -0x7e00))(unaff_s1,0);
                if (unaff_s2 == (BIO *)0x0) goto LAB_005a1e18;
                iVar6 = (**(code **)(local_b0 + -0x70f4))(unaff_s2);
                if (iVar6 < 1) {
LAB_005a1bd0:
                  unaff_s6 = (BIO *)0x0;
                }
                else {
                  local_b8 = (BIO *)0x0;
                  local_b4 = unaff_s6;
                  iVar6 = (**(code **)(local_b0 + -0x7df4))(unaff_s2,0xffffffff,0x100,3);
                  if (iVar6 < 1) {
                    pcVar22 = *(code **)(local_b0 + -0x6eac);
                    in_a2 = (BIO *)&DAT_00000098;
                    local_b8 = (BIO *)&DAT_000000a0;
LAB_005a205c:
                    bio = (BIO *)&DAT_00000084;
                    unaff_s6 = (BIO *)0x0;
                    pcVar15 = local_8c;
                    (*pcVar22)(0x21,0x84);
                  }
                  else {
                    bio = (BIO *)0x0;
                    local_b8 = local_94;
                    in_a2 = unaff_s8;
                    pcVar15 = (char *)local_90;
                    iVar6 = (**(code **)(local_b0 + -0x70cc))(unaff_s2,0);
                    if (iVar6 < 1) goto LAB_005a1bd0;
                    bio = (BIO *)(**(code **)(local_b0 + -0x7dd8))(local_84._4_4_,local_8c,0xa7);
                    local_9c = bio;
                    if (bio == (BIO *)0x0) {
                      pcVar22 = *(code **)(local_b0 + -0x6eac);
                      in_a2 = (BIO *)&DAT_00000041;
                      local_b8 = (BIO *)0xaa;
                      goto LAB_005a205c;
                    }
                    local_b8 = local_94;
                    in_a2 = unaff_s8;
                    pcVar15 = (char *)local_90;
                    iVar6 = (**(code **)(local_b0 + -0x70cc))(unaff_s2,bio);
                    if (iVar6 < 1) {
                      (**(code **)(local_b0 + -0x7f68))(unaff_s1);
                      (**(code **)(local_b0 + -0x7f64))(unaff_s2);
                      (**(code **)(local_b0 + -0x7f58))(local_9c);
                      goto LAB_005a1e18;
                    }
                    piVar1 = &unaff_s6->init;
                    unaff_s6 = (BIO *)0x1;
                    bio = local_9c;
                    in_a2 = local_84._4_4_;
                    (**(code **)(local_b0 + -0x5c9c))(*piVar1,local_9c);
                  }
                }
                (**(code **)(local_b0 + -0x7f68))(unaff_s1);
                (**(code **)(local_b0 + -0x7f64))(unaff_s2);
                if (unaff_s6 == (BIO *)0x0) goto LAB_005a1e18;
              }
              bio = local_94;
              (**(code **)(local_b0 + -0x7d6c))(local_90,local_94);
              unaff_s3 = unaff_s4;
              if (pBVar16 != (BIO *)0x0) {
                bio = unaff_s4;
                (**(code **)(local_b0 + -0x791c))(pBVar16,unaff_s4);
                unaff_s3 = pBVar16;
              }
              goto LAB_005a1eec;
            }
            bio = (BIO *)local_9c->callback;
            if (bio != (BIO *)0x0) {
LAB_005a1a50:
              iVar6 = (**(code **)(local_b0 + -0x5fe4))(local_84._0_4_);
              if (iVar6 < 0) goto LAB_005a1e18;
              goto LAB_005a1a64;
            }
            bio = (BIO *)(**(code **)(local_b0 + -0x6f14))();
            local_9c->callback = (_func_603 *)bio;
            if (bio != (BIO *)0x0) goto LAB_005a1a50;
            pcVar22 = *(code **)(local_b0 + -0x7f6c);
          }
          else {
LAB_005a1e18:
            pcVar22 = *(code **)(local_b0 + -0x7f6c);
          }
          if (pBVar16 != (BIO *)0x0) goto LAB_005a1c18;
          goto LAB_005a1c30;
        }
        in_a2 = (BIO *)&DAT_00000020;
        pcVar15 = "pk7_doit.c";
        local_b8 = (BIO *)0x14f;
        bio = (BIO *)&DAT_00000069;
        (**(code **)(local_b0 + -0x6eac))(0x21,0x69);
        if (pBVar16 != (BIO *)0x0) goto LAB_005a1c18;
        pBVar19 = (BIO *)0x0;
      }
    }
    else {
      uVar3 = (**(code **)(local_b0 + -0x7908))();
      unaff_s0 = (BIO *)(**(code **)(local_b0 + -0x7f3c))(uVar3);
      if (unaff_s0 == (BIO *)0x0) {
LAB_005a1d98:
        in_a2 = (BIO *)&DAT_00000020;
        pcVar15 = "pk7_doit.c";
        local_b8 = (BIO *)&DAT_0000006d;
        bio = (BIO *)0x7d;
        (**(code **)(local_b0 + -0x6eac))(0x21,0x7d);
        pBVar16 = pBVar19;
      }
      else {
        uVar3 = (**(code **)(local_b0 + -0x7cb4))(unaff_s6->method);
        uVar3 = (**(code **)(local_b0 + -0x7d44))(uVar3);
        pcVar15 = (char *)(**(code **)(local_b0 + -0x7eb4))(uVar3);
        if ((BIO *)pcVar15 == (BIO *)0x0) {
          pcVar22 = *(code **)(local_b0 + -0x6eac);
          in_a2 = (BIO *)&DAT_0000006d;
          local_b8 = (BIO *)&DAT_00000073;
        }
        else {
          in_a2 = (BIO *)0x0;
          bio = (BIO *)&DAT_0000006f;
          (**(code **)(local_b0 + -0x7fc8))(unaff_s0,0x6f);
          pBVar16 = unaff_s0;
          if ((pBVar19 == (BIO *)0x0) ||
             (bio = unaff_s0, iVar6 = (**(code **)(local_b0 + -0x791c))(pBVar19,unaff_s0),
             pBVar16 = pBVar19, iVar6 != 0)) goto LAB_005a190c;
          pcVar22 = *(code **)(local_b0 + -0x6eac);
          in_a2 = (BIO *)&DAT_00000020;
          local_b8 = (BIO *)0x7b;
        }
        pcVar15 = "pk7_doit.c";
        bio = (BIO *)0x7d;
        (*pcVar22)(0x21,0x7d);
        (**(code **)(local_b0 + -0x7f70))(unaff_s0);
        pBVar16 = pBVar19;
      }
joined_r0x005a1dc0:
      unaff_s4 = (BIO *)0x0;
      if (pBVar16 != (BIO *)0x0) {
LAB_005a1c18:
        (**(code **)(local_b0 + -0x7f6c))(pBVar16);
        if (unaff_s4 != (BIO *)0x0) {
          pcVar22 = *(code **)(local_b0 + -0x7f6c);
LAB_005a1c30:
          (*pcVar22)(unaff_s4);
          pBVar19 = (BIO *)0x0;
          unaff_s3 = pBVar16;
          goto LAB_005a1c40;
        }
      }
      pBVar19 = (BIO *)0x0;
      unaff_s3 = pBVar16;
    }
  }
LAB_005a1c40:
  if (local_2c == *(PKCS7 **)BStack_fc.prev_bio) {
    return pBVar19;
  }
  BStack_fc.num_read = (ulong)PKCS7_dataDecode;
  p7_00 = local_2c;
  (**(code **)(local_b0 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uStack_100 = 0;
  BStack_fc.method = (BIO_METHOD *)0x0;
  BStack_fc.callback = (_func_603 *)0x0;
  BStack_fc.cb_arg = *(char **)PTR___stack_chk_guard_006a9ae8;
  pBStack_10c = in_a2;
  BStack_fc.init = (int)unaff_s0;
  BStack_fc.shutdown = (int)unaff_s1;
  BStack_fc.flags = (int)unaff_s2;
  BStack_fc.retry_reason = (int)unaff_s3;
  BStack_fc.num = (int)unaff_s4;
  BStack_fc.ptr = p7;
  BStack_fc.next_bio = unaff_s6;
  BStack_fc.references = (int)unaff_s8;
  if (p7_00 == (PKCS7 *)0x0) {
    uVar14 = 0x8f;
    uVar3 = 0x1b2;
LAB_005a24b8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,uVar14,"pk7_doit.c",uVar3);
    pcVar15 = (char *)unaff_s6;
    bio = unaff_s8;
    goto LAB_005a24cc;
  }
  if ((p7_00->d).ptr == (char *)0x0) {
    uVar14 = 0x7a;
    uVar3 = 0x1b7;
    goto LAB_005a24b8;
  }
  iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7_00->type);
  p7_00->state = 0;
  if (iVar6 == 0x17) {
    pPVar10 = ((p7_00->d).enveloped)->enc_data;
    p7 = (PKCS7 *)((p7_00->d).enveloped)->recipientinfo;
    pXStack_104 = pPVar10->algorithm;
    pAStack_110 = pPVar10->enc_data;
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pXStack_104->algorithm);
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
    iStack_108 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar3);
    if (iStack_108 != 0) {
      if ((pAStack_110 == (ASN1_OCTET_STRING *)0x0) && (in_a2 == (BIO *)0x0)) goto LAB_005a2540;
      pBVar19 = (BIO *)0x0;
      goto LAB_005a25d4;
    }
    uVar14 = 0x6f;
    uVar3 = 0x1e3;
    goto LAB_005a2220;
  }
  if (iVar6 == 0x18) {
    pPVar8 = (p7_00->d).signed_and_enveloped;
    p7 = (PKCS7 *)pPVar8->recipientinfo;
    unaff_s3 = (BIO *)pPVar8->md_algs;
    pXStack_104 = pPVar8->enc_data->algorithm;
    pAStack_110 = pPVar8->enc_data->enc_data;
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pXStack_104->algorithm);
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
    iStack_108 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar3);
    if (iStack_108 == 0) {
      uVar14 = 0x6f;
      uVar3 = 0x1d7;
      goto LAB_005a2220;
    }
    goto LAB_005a2370;
  }
  if (iVar6 != 0x16) {
    uVar14 = 0x70;
    uVar3 = 0x1e8;
    goto LAB_005a2220;
  }
  ppVar20 = ((p7_00->d).sign)->contents;
  iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar20->type);
  if (iVar6 == 0x15) {
    pAStack_110 = (ASN1_OCTET_STRING *)(ppVar20->d).ptr;
LAB_005a2840:
    iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7_00->type);
    if (iVar6 != 0x16) {
LAB_005a2858:
      if (pAStack_110 == (ASN1_OCTET_STRING *)0x0) {
LAB_005a2a58:
        uVar14 = 0x9b;
        uVar3 = 0x1c9;
        goto LAB_005a2220;
      }
      goto LAB_005a2864;
    }
LAB_005a25a4:
    lVar11 = PKCS7_ctrl(p7_00,2,0,(char *)0x0);
    if (lVar11 == 0) goto LAB_005a2858;
    pAVar12 = (p7_00->d).data;
  }
  else {
    iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar20->type);
    if (iVar6 - 0x15U < 6) {
      iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7_00->type);
      if (iVar6 != 0x16) goto LAB_005a2a58;
      pAStack_110 = (ASN1_OCTET_STRING *)0x0;
      goto LAB_005a25a4;
    }
    pAVar12 = (ppVar20->d).data;
    if ((pAVar12 != (ASN1_OCTET_STRING *)0x0) && (pAVar12->length == 4)) {
      pAStack_110 = (ASN1_OCTET_STRING *)pAVar12->type;
      goto LAB_005a2840;
    }
    iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7_00->type);
    if ((iVar6 != 0x16) || (lVar11 = PKCS7_ctrl(p7_00,2,0,(char *)0x0), lVar11 == 0))
    goto LAB_005a2a58;
    pAStack_110 = (ASN1_OCTET_STRING *)0x0;
LAB_005a2864:
    pAVar12 = (p7_00->d).data;
  }
  p7 = (PKCS7 *)0x0;
  pXStack_104 = (X509_ALGOR *)0x0;
  iStack_108 = 0;
  unaff_s3 = (BIO *)pAVar12->type;
LAB_005a2370:
  if (pAStack_110 == (ASN1_OCTET_STRING *)0x0) goto LAB_005a2b78;
LAB_005a237c:
  pBVar16 = (BIO *)0x0;
  if (unaff_s3 != (BIO *)0x0) {
    iVar18 = 0;
    iVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s3);
    pBVar19 = pBVar16;
    if (0 < iVar6) {
      do {
        puVar9 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(unaff_s3,iVar18);
        uVar3 = (*(code *)PTR_BIO_f_md_006a74d8)();
        pBVar16 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar3);
        if (pBVar16 == (BIO *)0x0) {
          pBVar17 = (BIO *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x20,"pk7_doit.c",0x1f7);
          p_Var21 = (_func_603 *)0x0;
          goto LAB_005a28e4;
        }
        uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar9);
        uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
        iVar6 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar3);
        if (iVar6 == 0) {
          p_Var21 = (_func_603 *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x6d,"pk7_doit.c",0x1ff);
          pBVar17 = (BIO *)0x0;
          goto LAB_005a28e4;
        }
        (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar16,0x6f,0,iVar6);
        if (pBVar19 != (BIO *)0x0) {
          (*(code *)PTR_BIO_push_006a74c4)(pBVar19,pBVar16);
          pBVar16 = pBVar19;
        }
        iVar18 = iVar18 + 1;
        iVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s3);
        pBVar19 = pBVar16;
      } while (iVar18 < iVar6);
    }
  }
  pBVar19 = pBVar16;
  if (iStack_108 == 0) {
    p_Var21 = (_func_603 *)0x0;
    pBVar7 = pBVar16;
LAB_005a2470:
    if (pBStack_10c != (BIO *)0x0) {
LAB_005a247c:
      (*(code *)PTR_BIO_push_006a74c4)(pBVar7,pBStack_10c);
      goto LAB_005a22dc;
    }
    if (pAStack_110->length < 1) {
      uVar3 = (*(code *)PTR_BIO_s_mem_006a7c18)();
      pBStack_10c = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar3);
      if (pBStack_10c != (BIO *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(pBStack_10c,0x82,0,0);
        goto LAB_005a247c;
      }
    }
    else {
      pBStack_10c = (BIO *)(*(code *)PTR_BIO_new_mem_buf_006a9148)(pAStack_110->data);
      if (pBStack_10c != (BIO *)0x0) goto LAB_005a247c;
    }
    pBVar17 = (BIO *)0x0;
    pBVar16 = (BIO *)0x0;
    pBVar19 = pBVar7;
  }
  else {
LAB_005a25d4:
    uVar3 = (*(code *)PTR_BIO_f_cipher_006a7558)();
    pBVar17 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar3);
    if (pBVar17 == (BIO *)0x0) {
      pBVar16 = (BIO *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x20,"pk7_doit.c",0x217);
      p_Var21 = (_func_603 *)0x0;
      goto LAB_005a28e4;
    }
    iVar6 = 0;
    if ((BIO *)pcVar15 != (BIO *)0x0) {
      for (; iVar18 = (*(code *)PTR_sk_num_006a6e2c)(p7), iVar6 < iVar18; iVar6 = iVar6 + 1) {
        unaff_s3 = (BIO *)(*(code *)PTR_sk_value_006a6e24)(p7,iVar6);
        iVar18 = (*(code *)PTR_X509_NAME_cmp_006a8030)
                           (*(undefined4 *)unaff_s3->callback,(*(BIO_METHOD **)pcVar15)->bread);
        if ((iVar18 == 0) &&
           (iVar18 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)
                               ((*(BIO_METHOD **)pcVar15)->name,
                                *(undefined4 *)(unaff_s3->callback + 4)), iVar18 == 0)) {
          iVar6 = pkcs7_decrypt_rinfo(&BStack_fc,&BStack_fc.callback,unaff_s3,bio);
          if (iVar6 < 0) goto LAB_005a28dc;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
          goto LAB_005a26a4;
        }
      }
      p_Var21 = (_func_603 *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x73,"pk7_doit.c",0x22e);
      pBVar16 = (BIO *)0x0;
      goto LAB_005a28e4;
    }
    unaff_s3 = &BStack_fc;
    for (; iVar18 = (*(code *)PTR_sk_num_006a6e2c)(p7), iVar6 < iVar18; iVar6 = iVar6 + 1) {
      uVar3 = (*(code *)PTR_sk_value_006a6e24)(p7,iVar6);
      iVar18 = pkcs7_decrypt_rinfo(unaff_s3,&BStack_fc.callback,uVar3,bio);
      if (iVar18 < 0) goto LAB_005a28dc;
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
LAB_005a26a4:
    uStack_100 = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar17,0x81,0,&uStack_100);
    iVar6 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(uStack_100,iStack_108,0,0,0,0);
    if ((iVar6 < 1) ||
       (iVar6 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a8c8c)(uStack_100,pXStack_104->parameter),
       iVar6 < 0)) {
LAB_005a28dc:
      p_Var21 = (_func_603 *)0x0;
    }
    else {
      p_Var21 = (_func_603 *)(*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)(uStack_100);
      unaff_s3 = (BIO *)(*(code *)PTR_CRYPTO_malloc_006a7008)(p_Var21,"pk7_doit.c",0x24f);
      if (unaff_s3 != (BIO *)0x0) {
        iVar6 = (*(code *)PTR_EVP_CIPHER_CTX_rand_key_006a9140)(uStack_100,unaff_s3);
        if (iVar6 < 1) {
          pBVar16 = (BIO *)0x0;
          if ((BIO *)BStack_fc.method == (BIO *)0x0) goto LAB_005a2278;
          goto LAB_005a2254;
        }
        pBVar16 = unaff_s3;
        if ((BIO *)BStack_fc.method == (BIO *)0x0) {
          pBVar16 = (BIO *)0x0;
          BStack_fc.method = (BIO_METHOD *)unaff_s3;
          BStack_fc.callback = p_Var21;
        }
        p_Var13 = (_func_603 *)(*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)(uStack_100);
        unaff_s3 = pBVar16;
        if ((p_Var13 != BStack_fc.callback) &&
           (iVar6 = (*(code *)PTR_EVP_CIPHER_CTX_set_key_length_006a8a8c)(uStack_100), iVar6 == 0))
        {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(BStack_fc.method,BStack_fc.callback);
          (*(code *)PTR_CRYPTO_free_006a6e88)(BStack_fc.method);
          unaff_s3 = (BIO *)0x0;
          BStack_fc.method = (BIO_METHOD *)pBVar16;
          BStack_fc.callback = p_Var21;
        }
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
        iVar6 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(uStack_100,0,0,BStack_fc.method,0,0);
        if (iVar6 < 1) {
          pBVar16 = (BIO *)0x0;
          if ((BIO *)BStack_fc.method != (BIO *)0x0) goto LAB_005a2254;
          goto LAB_005a2270;
        }
        if ((BIO *)BStack_fc.method != (BIO *)0x0) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(BStack_fc.method,BStack_fc.callback);
          (*(code *)PTR_CRYPTO_free_006a6e88)(BStack_fc.method);
          BStack_fc.method = (BIO_METHOD *)0x0;
        }
        if (unaff_s3 != (BIO *)0x0) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s3,p_Var21);
          (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s3);
        }
        pBVar7 = pBVar17;
        if (pBVar19 != (BIO *)0x0) {
          (*(code *)PTR_BIO_push_006a74c4)(pBVar19,pBVar17);
          pBVar7 = pBVar19;
        }
        goto LAB_005a2470;
      }
    }
    pBVar16 = (BIO *)0x0;
  }
LAB_005a28e4:
  if ((BIO *)BStack_fc.method != (BIO *)0x0) {
    unaff_s3 = (BIO *)0x0;
    goto LAB_005a2254;
  }
  do {
    if (pBVar19 != (BIO *)0x0) {
      (*(code *)PTR_BIO_free_all_006a6e74)(pBVar19);
    }
    if (pBVar16 != (BIO *)0x0) {
      (*(code *)PTR_BIO_free_all_006a6e74)(pBVar16);
    }
    if (pBVar17 == (BIO *)0x0) goto LAB_005a24cc;
    (*(code *)PTR_BIO_free_all_006a6e74)(pBVar17);
    pBVar7 = (BIO *)0x0;
LAB_005a22dc:
    while( true ) {
      if (BStack_fc.cb_arg == *(char **)puVar2) {
        return pBVar7;
      }
      in_a2 = (BIO *)(*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005a2b78:
      if (in_a2 != (BIO *)0x0) goto LAB_005a237c;
LAB_005a2540:
      uVar14 = 0x7a;
      uVar3 = 0x1ee;
LAB_005a2220:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,uVar14,"pk7_doit.c",uVar3);
      if ((BIO *)BStack_fc.method != (BIO *)0x0) break;
LAB_005a24cc:
      pBVar7 = (BIO *)0x0;
    }
    p_Var21 = (_func_603 *)0x0;
    unaff_s3 = (BIO *)0x0;
    pBVar17 = (BIO *)0x0;
    pBVar16 = (BIO *)0x0;
    pBVar19 = (BIO *)0x0;
LAB_005a2254:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(BStack_fc.method,BStack_fc.callback);
    (*(code *)PTR_CRYPTO_free_006a6e88)(BStack_fc.method);
LAB_005a2270:
    if (unaff_s3 != (BIO *)0x0) {
LAB_005a2278:
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s3,p_Var21);
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s3);
    }
  } while( true );
}

