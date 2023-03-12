
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  undefined *puVar1;
  byte bVar12;
  byte bVar13;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  BIO *pBVar5;
  uint uVar6;
  bio_st *pbVar7;
  bio_st **ppbVar8;
  ASN1_STRING *pAVar9;
  stack_st_OPENSSL_BLOCK *psVar10;
  BIO_METHOD *pBVar11;
  BIO **ppBVar14;
  BIO **ppBVar15;
  BIO_METHOD **pp;
  int *piVar16;
  bio_st *pbVar17;
  char *d2i;
  int **ppiVar18;
  undefined4 uVar19;
  char *pcVar20;
  _func_595 *p_Var21;
  int *piVar22;
  int iVar23;
  BIO *unaff_s5;
  BIO *pBVar24;
  int iStack_1310;
  int iStack_130c;
  undefined *puStack_1308;
  BIO_METHOD *pBStack_1304;
  undefined *puStack_1300;
  stack_st_void **ppsStack_12fc;
  BIO *pBStack_12f8;
  code *pcStack_12f4;
  undefined4 uStack_12e0;
  undefined *puStack_12d8;
  int iStack_12cc;
  undefined4 uStack_12c8;
  int iStack_12c4;
  BIO_METHOD *pBStack_12c0;
  code *pcStack_12bc;
  BIO_METHOD *pBStack_1298;
  undefined4 *puStack_1294;
  undefined *puStack_128c;
  BIO_METHOD *pBStack_1288;
  bio_st *pbStack_1284;
  BIO_METHOD **ppBStack_1280;
  BIO *pBStack_127c;
  undefined *puStack_1278;
  char *pcStack_1274;
  BIO *pBStack_1270;
  code *pcStack_126c;
  stack_st_void *psStack_1238;
  stack_st_OPENSSL_BLOCK *psStack_1234;
  bio_st *pbStack_1230;
  undefined4 uStack_122c;
  BIO *pBStack_1208;
  undefined auStack_1204 [8];
  undefined auStack_11fc [8];
  undefined auStack_11f4 [16];
  _func_599 *p_Stack_11e4;
  bio_st *pbStack_11e0;
  bio_st *pbStack_11dc;
  bio_st *pbStack_11d8;
  bio_st *pbStack_11d4;
  bio_st *pbStack_11d0;
  bio_st *pbStack_11cc;
  BIO *pBStack_11c8;
  BIO *pBStack_11c4;
  stack_st_void *psStack_11bc;
  bio_st *pbStack_11b4;
  bio_st **ppbStack_11b0;
  bio_st *pbStack_11ac;
  code *pcStack_11a8;
  undefined *puStack_11a4;
  BIO *pBStack_11a0;
  bio_st *pbStack_119c;
  BIO *pBStack_1198;
  code *pcStack_1194;
  bio_st *pbStack_1180;
  undefined *puStack_1178;
  BIO_METHOD *pBStack_1170;
  BIO_METHOD **ppBStack_116c;
  bio_st *pbStack_1168;
  bio_st **ppbStack_1164;
  undefined *puStack_1160;
  BIO *pBStack_115c;
  char *pcStack_1158;
  BIO *pBStack_1154;
  bio_st *pbStack_1150;
  code *pcStack_114c;
  bio_st *pbStack_1138;
  undefined *puStack_1130;
  bio_st *pbStack_1124;
  BIO *pBStack_111c;
  undefined auStack_1118 [4];
  _func_603 *p_Stack_1114;
  bio_st bStack_1110;
  char *apcStack_10d0 [3];
  BIO aBStack_10c4 [64];
  bio_st **ppbStack_c4;
  BIO *pBStack_c0;
  char *pcStack_bc;
  ASN1_ITEM *pAStack_b8;
  BIO *pBStack_b4;
  int iStack_b0;
  code *pcStack_ac;
  ASN1_ITEM *local_98;
  ASN1_ITEM *local_94;
  undefined *local_90;
  ASN1_ITEM *local_84;
  BIO *local_80;
  char *local_7c;
  BIO **local_78;
  int local_74;
  char *local_70;
  char *local_6c;
  int local_68;
  char *local_64;
  BIO *local_60;
  BIO *local_5c;
  BIO *local_58;
  int local_54;
  BIO *local_50 [8];
  undefined local_30;
  ulong local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_90 = &_gp;
  local_84 = it;
  local_2c = *(ulong *)PTR___stack_chk_guard_006aabf0;
  if ((flags & 0x400U) == 0) {
    pcStack_1274 = "application/pkcs7-";
  }
  else {
    pcStack_1274 = "application/x-pkcs7-";
  }
  if ((flags & 0x800U) == 0) {
    pAStack_b8 = (ASN1_ITEM *)0x63bac8;
  }
  else {
    pAStack_b8 = (ASN1_ITEM *)0x63ba90;
  }
  local_80 = (BIO *)val;
  if (((flags & 0x40U) != 0) && (data != (BIO *)0x0)) {
    local_78 = local_50;
    (*(code *)PTR_RAND_pseudo_bytes_006a8664)(local_50,0x20);
    ppBVar14 = local_50;
    do {
      ppBVar15 = (BIO **)((int)ppBVar14 + 1);
      bVar12 = *(byte *)ppBVar14 & 0xf;
      bVar13 = bVar12 + 0x37;
      if (bVar12 < 10) {
        bVar13 = bVar12 + 0x30;
      }
      *(byte *)ppBVar14 = bVar13;
      ppBVar14 = ppBVar15;
    } while (ppBVar15 != (BIO **)&local_30);
    local_30 = 0;
    (**(code **)(local_90 + -0x7fa8))(bio,"MIME-Version: 1.0%s",pAStack_b8);
    unaff_s5 = (BIO *)0x0;
    iVar23 = 0;
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: multipart/signed;");
    (**(code **)(local_90 + -0x7fa8))(bio," protocol=\"%ssignature\";",pcStack_1274);
    (**(code **)(local_90 + -0x7e88))(bio,&DAT_0067a4d8);
    local_74 = 0;
    local_7c = ",";
    local_70 = "sha-256";
    local_64 = "x";
    local_6c = "sha-512";
    local_68 = 0x680000;
LAB_0060f3b8:
    do {
      iVar2 = (**(code **)(local_90 + -0x7fb4))(mdalgs);
      if (iVar2 <= iVar23) goto LAB_0060f624;
      if (unaff_s5 != (BIO *)0x0) {
        (**(code **)(local_90 + -0x7fcc))(bio,local_7c,1);
      }
      puVar3 = (undefined4 *)(**(code **)(local_90 + -0x7fbc))(mdalgs,iVar23);
      unaff_s5 = (BIO *)(**(code **)(local_90 + -0x7cb4))(*puVar3);
      uVar4 = (**(code **)(local_90 + -0x7d44))(unaff_s5);
      iVar2 = (**(code **)(local_90 + -0x7eb4))(uVar4);
      if (iVar2 == 0) {
LAB_0060f5e4:
        if (unaff_s5 == (BIO *)0x2a0) {
          unaff_s5 = (BIO *)0x1;
          iVar23 = iVar23 + 1;
          (**(code **)(local_90 + -0x7e88))(bio,local_70);
          goto LAB_0060f3b8;
        }
        if ((int)unaff_s5 < 0x2a1) {
          if (unaff_s5 == (BIO *)&SUB_00000004) {
            unaff_s5 = (BIO *)0x1;
            (**(code **)(local_90 + -0x7e88))(bio,&DAT_00632570);
            iVar23 = iVar23 + 1;
            goto LAB_0060f3b8;
          }
          if (unaff_s5 == (BIO *)&DAT_00000040) {
            unaff_s5 = (BIO *)0x1;
            (**(code **)(local_90 + -0x7e88))(bio,&DAT_0064e1b4);
            iVar23 = iVar23 + 1;
            goto LAB_0060f3b8;
          }
        }
        else {
          if (unaff_s5 == (BIO *)0x2a2) {
            unaff_s5 = (BIO *)0x1;
            iVar23 = iVar23 + 1;
            (**(code **)(local_90 + -0x7e88))(bio,local_6c);
            goto LAB_0060f3b8;
          }
          if ((int)unaff_s5 < 0x2a2) {
            unaff_s5 = (BIO *)0x1;
            iVar23 = iVar23 + 1;
            (**(code **)(local_90 + -0x7e88))(bio,local_68 + -0x5b14);
            goto LAB_0060f3b8;
          }
          if (unaff_s5 == (BIO *)0x329) {
            (**(code **)(local_90 + -0x7e88))(bio,"gostr3411-94");
            goto LAB_0060f624;
          }
        }
        if (local_74 == 0) {
          unaff_s5 = (BIO *)0x1;
          iVar23 = iVar23 + 1;
          (**(code **)(local_90 + -0x7e88))(bio,local_64 + -0x47c4);
          local_74 = 1;
        }
        else {
          unaff_s5 = (BIO *)0x0;
          iVar23 = iVar23 + 1;
        }
        goto LAB_0060f3b8;
      }
      if (*(code **)(iVar2 + 0x48) == (code *)0x0) goto LAB_0060f5e4;
      iVar2 = (**(code **)(iVar2 + 0x48))(0,2,0,&local_5c);
      if (iVar2 < 1) {
        if (iVar2 == -2) goto LAB_0060f5e4;
        goto LAB_0060f624;
      }
      unaff_s5 = (BIO *)0x1;
      iVar23 = iVar23 + 1;
      (**(code **)(local_90 + -0x7e88))(bio,local_5c);
      (**(code **)(local_90 + -0x7f58))(local_5c);
    } while( true );
  }
  if (ctype_nid == 0x17) {
    pcVar20 = "enveloped-data";
    pcStack_bc = &DAT_0067a428;
LAB_0060f85c:
    (**(code **)(local_90 + -0x7fa8))(bio,"MIME-Version: 1.0%s",pAStack_b8);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Disposition: attachment;");
    (**(code **)(local_90 + -0x7fa8))(bio," filename=\"%s\"%s",pcStack_bc,pAStack_b8);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: %smime;",pcStack_1274);
    (**(code **)(local_90 + -0x7fa8))(bio," smime-type=%s;",pcVar20);
    mdalgs = (stack_st_X509_ALGOR *)pcVar20;
  }
  else {
    if (ctype_nid == 0x16) {
      if (econt_nid == 0xcc) {
        pcVar20 = "signed-receipt";
        pcStack_bc = &DAT_0067a428;
      }
      else {
        iVar23 = (*(code *)PTR_sk_num_006a7f2c)(mdalgs);
        if (iVar23 < 0) {
          pcVar20 = "certs-only";
          pcStack_bc = &DAT_0067a428;
        }
        else {
          pcVar20 = "signed-data";
          pcStack_bc = &DAT_0067a428;
        }
      }
      goto LAB_0060f85c;
    }
    if (ctype_nid == 0x312) {
      pcVar20 = "compressed-data";
      pcStack_bc = "smime.p7z";
      goto LAB_0060f85c;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(bio,"MIME-Version: 1.0%s",pAStack_b8);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Disposition: attachment;");
    pcStack_bc = &DAT_0067a428;
    (**(code **)(local_90 + -0x7fa8))(bio," filename=\"%s\"%s",&DAT_0067a428,pAStack_b8);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: %smime;",pcStack_1274);
  }
  (**(code **)(local_90 + -0x7fa8))(bio," name=\"%s\"%s",pcStack_bc,pAStack_b8);
  (**(code **)(local_90 + -0x7fa8))
            (bio,"Content-Transfer-Encoding: base64%s%s",pAStack_b8,pAStack_b8);
  local_98 = local_84;
  bStack_1110.shutdown = (int)local_80;
  pcStack_1158 = (char *)flags;
  iVar23 = B64_write_ASN1(bio,local_80,data);
  if (iVar23 == 0) {
LAB_0060f564:
    iVar23 = 0;
  }
  else {
    bStack_1110.shutdown = 0x6716dc;
    (**(code **)(local_90 + -0x7fa8))(bio,"%s",pAStack_b8);
    iVar23 = 1;
  }
LAB_0060f568:
  if (local_2c == *(ulong *)puVar1) {
    return iVar23;
  }
  pcStack_ac = SMIME_text;
  bStack_1110.init = local_2c;
  (**(code **)(local_90 + -0x5328))();
  bStack_1110.flags = (int)PTR___stack_chk_guard_006aabf0;
  bStack_1110.ex_data.sk = (stack_st_void *)&_gp;
  ppbStack_c4 = *(bio_st ***)PTR___stack_chk_guard_006aabf0;
  pBStack_c0 = bio;
  pBStack_b4 = (BIO *)mdalgs;
  iStack_b0 = flags;
  pBVar5 = (BIO *)mime_parse_hdr();
  if (pBVar5 == (BIO *)0x0) {
    pbStack_11b4 = (bio_st *)0xcf;
    pcStack_1158 = "asn_mime.c";
    bStack_1110.num_read = 0x246;
    pcStack_11a8 = (code *)0xd5;
    (**(code **)((int)bStack_1110.ex_data.sk + -0x6eb0))(0xd);
    uVar6 = 0;
  }
  else {
    apcStack_10d0[0] = "content-type";
    iVar23 = (**(code **)((int)bStack_1110.ex_data.sk + -0x6e74))(pBVar5,apcStack_10d0);
    if ((iVar23 < 0) ||
       (flags = (**(code **)((int)bStack_1110.ex_data.sk + -0x7fbc))(pBVar5,iVar23),
       (void *)flags == (void *)0x0)) {
LAB_0060fc68:
      pbStack_11b4 = (bio_st *)0xce;
      pcStack_1158 = "asn_mime.c";
      bStack_1110.num_read = 0x24a;
      (**(code **)((int)bStack_1110.ex_data.sk + -0x6eb0))(0xd,0xd5);
    }
    else {
      if (*(void **)(flags + 4) == (void *)0x0) goto LAB_0060fc68;
      iVar23 = (**(code **)((int)bStack_1110.ex_data.sk + -0x52c0))
                         (*(void **)(flags + 4),"text/plain");
      if (iVar23 == 0) {
        (**(code **)((int)bStack_1110.ex_data.sk + -0x7d88))(pBVar5,mime_hdr_free);
        while( true ) {
          pbStack_11b4 = (bio_st *)0x1000;
          pcStack_11a8 = (code *)aBStack_10c4;
          iVar23 = (**(code **)((int)bStack_1110.ex_data.sk + -0x7924))(bStack_1110.init);
          if (iVar23 < 1) break;
          (**(code **)((int)bStack_1110.ex_data.sk + -0x7fcc))
                    (bStack_1110.shutdown,aBStack_10c4,iVar23);
        }
        uVar6 = (uint)(iVar23 == 0);
        bio = aBStack_10c4;
        goto LAB_0060fbd8;
      }
      pcStack_1158 = "asn_mime.c";
      bStack_1110.num_read = 0x24f;
      (**(code **)((int)bStack_1110.ex_data.sk + -0x6eb0))(0xd,0xd5,0xcd);
      pbStack_11b4 = *(bio_st **)(flags + 4);
      (**(code **)((int)bStack_1110.ex_data.sk + -0x6c7c))(2,"type: ");
    }
    pcStack_11a8 = mime_hdr_free;
    (**(code **)((int)bStack_1110.ex_data.sk + -0x7d88))(pBVar5);
    uVar6 = 0;
    bio = pBVar5;
  }
LAB_0060fbd8:
  if (ppbStack_c4 == *(bio_st ***)bStack_1110.flags) {
    return uVar6;
  }
  bStack_1110.num = (int)d2i_ASN1_type_bytes;
  ppbStack_11b0 = ppbStack_c4;
  (**(code **)((int)bStack_1110.ex_data.sk + -0x5328))();
  puStack_1160 = PTR___stack_chk_guard_006aabf0;
  pBStack_111c = (BIO *)*(BIO_METHOD **)pcStack_11a8;
  pcVar20 = auStack_1118 + 8;
  puStack_1130 = &_gp;
  pBVar5 = (BIO *)auStack_1118;
  bStack_1110.callback = *(_func_603 **)PTR___stack_chk_guard_006aabf0;
  pbStack_1138 = pbStack_11b4;
  bStack_1110.cb_arg = (char *)bio;
  bStack_1110.retry_reason = flags;
  uVar6 = (*(code *)PTR_ASN1_get_object_006a9514)(&pBStack_111c,pBVar5,auStack_1118 + 4);
  if ((uVar6 & 0x80) == 0) {
    pbVar17 = (bio_st *)0x99;
    if (0x1f < (int)p_Stack_1114) goto LAB_0060fd58;
    uVar6 = (**(code **)(puStack_1130 + -0x60d8))();
    if (((uint)pcStack_1158 & uVar6) == 0) {
      pbVar17 = (bio_st *)0xa9;
      goto LAB_0060fd58;
    }
    if (p_Stack_1114 != (_func_603 *)0x3) {
      if (((ppbStack_11b0 == (bio_st **)0x0) ||
          (pbStack_11b4 = *ppbStack_11b0, pbStack_11b4 == (bio_st *)0x0)) &&
         (pbStack_11b4 = (bio_st *)(**(code **)(puStack_1130 + -0x662c))(),
         pbStack_11b4 == (bio_st *)0x0)) {
        pbVar7 = (bio_st *)0x0;
        goto LAB_0060fd80;
      }
      pcStack_1158 = (char *)0x0;
      if (auStack_1118 == (undefined  [4])0x0) {
LAB_0060fdfc:
        if ((_func_595 *)pbStack_11b4->cb_arg != (_func_595 *)0x0) {
          (**(code **)(puStack_1130 + -0x7f58))();
        }
        pbStack_11b4->cb_arg = pcStack_1158;
        pbStack_11b4->method = (BIO_METHOD *)auStack_1118;
        pbStack_11b4->callback = p_Stack_1114;
        if (ppbStack_11b0 != (bio_st **)0x0) {
          *ppbStack_11b0 = pbStack_11b4;
        }
        *(BIO_METHOD **)pcStack_11a8 = (BIO_METHOD *)pBStack_111c;
        pbVar7 = pbStack_11b4;
        goto LAB_0060fd80;
      }
      pbStack_1124 = (bio_st *)0x680000;
      pcStack_1158 = (char *)(**(code **)(puStack_1130 + -0x7dd8))
                                       ((code *)((int)(BIO_METHOD **)auStack_1118 + 1),"a_bytes.c",
                                        0x68);
      if ((BIO **)pcStack_1158 != (BIO **)0x0) {
        pBVar5 = pBStack_111c;
        pbVar17 = (bio_st *)auStack_1118;
        pcVar20 = (char *)pbStack_1124;
        (**(code **)(puStack_1130 + -0x52ec))(pcStack_1158);
        *(code *)((int)(BIO_METHOD **)auStack_1118 + (int)pcStack_1158) = (code)0x0;
        pBStack_111c = (BIO *)((int)(BIO_METHOD **)auStack_1118 + (int)&pBStack_111c->method);
        goto LAB_0060fdfc;
      }
      pcVar20 = (char *)&pbStack_1124[-0x166].num_read;
      pbVar17 = (bio_st *)&DAT_00000041;
      pBVar5 = (BIO *)&DAT_00000095;
      pbStack_1138 = (bio_st *)0x7d;
      (**(code **)(puStack_1130 + -0x6eb0))(0xd);
      if ((ppbStack_11b0 == (bio_st **)0x0) || (pbStack_11b4 != *ppbStack_11b0)) {
        (**(code **)(puStack_1130 + -0x6624))(pbStack_11b4);
        pbVar7 = (bio_st *)0x0;
        goto LAB_0060fd80;
      }
      goto LAB_0060fd7c;
    }
    pBVar5 = (BIO *)pcStack_11a8;
    pbVar17 = pbStack_11b4;
    pbVar7 = (bio_st *)(**(code **)(puStack_1130 + -0x55d8))(ppbStack_11b0);
  }
  else {
    pbVar17 = (bio_st *)0x0;
LAB_0060fd58:
    pBVar5 = (BIO *)&DAT_00000095;
    pcVar20 = "a_bytes.c";
    pbStack_1138 = (bio_st *)0x7d;
    (**(code **)(puStack_1130 + -0x6eb0))(0xd);
LAB_0060fd7c:
    pbVar7 = (bio_st *)0x0;
  }
LAB_0060fd80:
  if ((bio_st *)bStack_1110.callback == *(bio_st **)puStack_1160) {
    return (int)pbVar7;
  }
  pcStack_114c = i2d_ASN1_bytes;
  pbVar7 = (bio_st *)bStack_1110.callback;
  (**(code **)(puStack_1130 + -0x5328))();
  puStack_11a4 = PTR___stack_chk_guard_006aabf0;
  puStack_1178 = &_gp;
  ppBStack_116c = *(BIO_METHOD ***)PTR___stack_chk_guard_006aabf0;
  ppbVar8 = (bio_st **)0x0;
  pBStack_127c = pBVar5;
  pbStack_1230 = pbVar17;
  pbStack_1284 = (bio_st *)pcVar20;
  pbStack_11ac = (bio_st *)puStack_1160;
  pbStack_1168 = pbStack_11b4;
  ppbStack_1164 = ppbStack_11b0;
  pBStack_115c = (BIO *)pcStack_11a8;
  pBStack_1154 = unaff_s5;
  pbStack_1150 = (bio_st *)pcStack_1274;
  if (pbVar7 != (bio_st *)0x0) {
    pbStack_11ac = pbVar17;
    if (pbVar17 == (bio_st *)0x3) {
      ppbVar8 = (bio_st **)(*(code *)PTR_i2d_ASN1_BIT_STRING_006aa90c)();
      pBStack_127c = pBVar5;
      pbStack_1284 = (bio_st *)pcVar20;
    }
    else {
      pBVar24 = (BIO *)pbVar7->method;
      pBStack_127c = pBVar24;
      ppbVar8 = (bio_st **)(*(code *)PTR_ASN1_object_size_006a94fc)(0);
      pbStack_11b4 = pbVar7;
      ppbStack_11b0 = ppbVar8;
      pcStack_11a8 = (code *)pBVar5;
      unaff_s5 = pBVar24;
      pcStack_1274 = pcVar20;
      if (pBVar5 != (BIO *)0x0) {
        pBStack_1170 = pBVar5->method;
        pbStack_1284 = pbVar17;
        pbStack_1180 = (bio_st *)pcVar20;
        (**(code **)(puStack_1178 + -0x69e0))
                  (&pBStack_1170,&pbVar17[-1].num_read < &SUB_00000002,pBVar24);
        pbStack_1230 = (bio_st *)pbVar7->method;
        pBStack_127c = (BIO *)pbVar7->cb_arg;
        (**(code **)(puStack_1178 + -0x52ec))(pBStack_1170);
        pBVar5->method = (BIO_METHOD *)((int)&pbVar7->method->type + (int)&pBStack_1170->type);
      }
    }
  }
  if (ppBStack_116c == *(BIO_METHOD ***)puStack_11a4) {
    return (int)ppbVar8;
  }
  pcStack_1194 = d2i_ASN1_bytes;
  ppBStack_1280 = ppBStack_116c;
  (**(code **)(puStack_1178 + -0x5328))();
  puStack_1278 = PTR___stack_chk_guard_006aabf0;
  psStack_11bc = *(stack_st_void **)PTR___stack_chk_guard_006aabf0;
  pcVar20 = (char *)pbStack_1284;
  pBStack_11a0 = unaff_s5;
  pbStack_119c = (bio_st *)pcStack_1274;
  pBStack_1198 = data;
  if (ppBStack_1280 == (BIO_METHOD **)0x0) {
LAB_0061032c:
    pBStack_12f8 = pBStack_127c;
    d2i = (char *)pbStack_1230;
    pBStack_1304 = (BIO_METHOD *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pBStack_1304 != (BIO_METHOD *)0x0) {
      pBStack_1208 = (BIO *)pBStack_127c->method;
      pcVar20 = auStack_11fc;
      d2i = auStack_1204 + 4;
      pBStack_12f8 = (BIO *)auStack_1204;
      pbVar17 = (bio_st *)(*(code *)PTR_ASN1_get_object_006a9514)(&pBStack_1208);
      pBVar11 = pBStack_1304;
      if (((uint)pbVar17 & 0x80) == 0) goto LAB_006100f0;
      pbStack_1284 = (bio_st *)0x66;
      goto LAB_00610378;
    }
    pBVar11 = (BIO_METHOD *)0x0;
  }
  else {
    pBStack_1304 = *ppBStack_1280;
    pcVar20 = auStack_11fc;
    if (pBStack_1304 == (BIO_METHOD *)0x0) goto LAB_0061032c;
    pBStack_1208 = (BIO *)pBStack_127c->method;
    d2i = auStack_1204 + 4;
    pBStack_12f8 = (BIO *)auStack_1204;
    pbVar17 = (bio_st *)(*(code *)PTR_ASN1_get_object_006a9514)(&pBStack_1208);
    pBVar11 = pBStack_1304;
    if (((uint)pbVar17 & 0x80) == 0) {
LAB_006100f0:
      pBStack_1304 = pBVar11;
      pcStack_1274 = (char *)auStack_1204._4_4_;
      if (auStack_1204._4_4_ == pbStack_1284) {
        if (((uint)pbVar17 & 0x20) == 0) {
          if (auStack_1204._0_4_ == (bio_st *)0x0) {
            if (pBVar11->bwrite == (_func_595 *)0x0) {
              pcVar20 = (char *)0x0;
              pBVar5 = pBStack_1208;
            }
            else {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              pcVar20 = (char *)0x0;
              pBVar5 = pBStack_1208;
            }
          }
          else {
            if (pBVar11->type < (int)auStack_1204._0_4_) {
              if (pBVar11->bwrite != (_func_595 *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
              }
LAB_00610428:
              pbStack_1230 = (bio_st *)0x680000;
              p_Var21 = (_func_595 *)
                        (*(code *)PTR_CRYPTO_malloc_006a8108)
                                  ((code *)((int)&(auStack_1204._0_4_)->method + 1),"a_bytes.c",0xd5
                                  );
              if (p_Var21 == (_func_595 *)0x0) {
                pbStack_1284 = (bio_st *)&DAT_00000041;
                goto LAB_00610378;
              }
            }
            else {
              p_Var21 = pBVar11->bwrite;
              if (p_Var21 == (_func_595 *)0x0) goto LAB_00610428;
            }
            pBStack_12f8 = pBStack_1208;
            d2i = (char *)auStack_1204._0_4_;
            pcVar20 = (char *)(*(code *)PTR_memcpy_006aabf4)(p_Var21);
            *(code *)((int)&(auStack_1204._0_4_)->method + (int)(BIO_METHOD **)pcVar20) = (code)0x0;
            pBVar5 = (BIO *)((int)&(auStack_1204._0_4_)->method + (int)&pBStack_1208->method);
          }
          pBVar11->type = (int)auStack_1204._0_4_;
          pBVar11->bwrite = (_func_595 *)pcVar20;
          pBVar11->name = (char *)auStack_1204._4_4_;
          pbVar7 = pbStack_1284;
        }
        else {
          pbStack_11d0 = auStack_1204._0_4_;
          auStack_11f4._12_4_ = pBStack_1208;
          pbStack_11d4 = pbStack_1180;
          if (pbStack_1230 == (bio_st *)0x0) {
            pbStack_11cc = (bio_st *)0x0;
          }
          else {
            pbStack_11cc = (bio_st *)((int)&pbStack_1230->method + (int)&pBStack_1208->method);
          }
          pbStack_1230 = (bio_st *)0x0;
          auStack_11fc._4_4_ = (bio_st **)0x0;
          pbVar7 = (bio_st *)(auStack_11f4 + 0xc);
          auStack_11f4._0_4_ = (BIO_METHOD *)0x0;
          auStack_1204._4_4_ = (bio_st *)(auStack_11fc + 4);
          auStack_11f4._8_4_ = (_func_597 *)0x0;
          data = (BIO *)auStack_11f4;
          auStack_11f4._4_4_ = (_func_603 *)0x0;
          pbStack_11dc = pbVar17;
          pbStack_11d8 = pbStack_1284;
          pBStack_11c4 = pBStack_127c;
          if (((uint)pbVar17 & 1) != 0) goto LAB_00610208;
          while (0 < (int)pbStack_11d0) {
            while( true ) {
              pBStack_11c8 = auStack_11f4._12_4_;
              pcVar20 = (char *)pbStack_11d8;
              pAVar9 = d2i_ASN1_bytes((ASN1_STRING **)auStack_1204._4_4_,(uchar **)pbVar7,
                                      (int)pbStack_11cc - (int)auStack_11f4._12_4_,(int)pbStack_11d8
                                      ,(int)pbStack_11d4);
              if (pAVar9 == (ASN1_STRING *)0x0) {
                pbStack_11e0 = (bio_st *)&DAT_0000000d;
                goto LAB_00610460;
              }
              iVar23 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)
                                 (data,(code *)((int)&(*auStack_11fc._4_4_)->method +
                                               (int)&pbStack_1230->method));
              if (iVar23 == 0) {
                pbStack_11e0 = (bio_st *)&DAT_00000007;
                goto LAB_00610460;
              }
              d2i = (char *)*auStack_11fc._4_4_;
              pBStack_12f8 = auStack_11fc._4_4_[2];
              (*(code *)PTR_memcpy_006aabf4)
                        ((_func_603 *)((int)&pbStack_1230->method + (int)auStack_11f4._4_4_));
              if (((uint)pbStack_11dc & 1) == 0) {
                pbStack_11d0 = (bio_st *)
                               ((int)pbStack_11d0 - ((int)auStack_11f4._12_4_ - (int)pBStack_11c8));
              }
              pbStack_1230 = (bio_st *)
                             ((int)&(*auStack_11fc._4_4_)->method + (int)&pbStack_1230->method);
              if (((uint)pbStack_11dc & 1) == 0) break;
LAB_00610208:
              pBStack_12f8 = (BIO *)((int)pbStack_11cc - (int)auStack_11f4._12_4_);
              p_Stack_11e4 = (_func_599 *)
                             (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(pbVar7);
              if (p_Stack_11e4 != (_func_599 *)0x0) goto LAB_00610230;
            }
          }
LAB_00610230:
          iVar23 = (*(code *)PTR_asn1_const_Finish_006a9518)(pbVar7);
          if (iVar23 == 0) {
LAB_00610460:
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x69,pbStack_11e0,"a_bytes.c");
            if (auStack_11fc._4_4_ != (bio_st **)0x0) {
              (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            }
            if (auStack_11f4._4_4_ != (_func_603 *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
            }
            pbStack_1284 = (bio_st *)0x0;
            pcStack_1274 = (char *)auStack_1204._4_4_;
            goto LAB_00610378;
          }
          pBVar11->type = (int)pbStack_1230;
          if (pBVar11->bwrite != (_func_595 *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          pBVar11->bwrite = (_func_595 *)auStack_11f4._4_4_;
          pBVar5 = auStack_11f4._12_4_;
          if (auStack_11fc._4_4_ != (bio_st **)0x0) {
            (*(code *)PTR_ASN1_STRING_free_006a98bc)();
            pBVar5 = auStack_11f4._12_4_;
          }
        }
        if (ppBStack_1280 != (BIO_METHOD **)0x0) {
          *ppBStack_1280 = pBVar11;
        }
        pBStack_127c->method = (BIO_METHOD *)pBVar5;
        pbStack_1284 = pbVar7;
        pcStack_1274 = (char *)auStack_1204._4_4_;
        goto LAB_00610294;
      }
      pbStack_1284 = (bio_st *)&DAT_000000a8;
LAB_00610378:
      if (ppBStack_1280 != (BIO_METHOD **)0x0) goto LAB_00610380;
LAB_0061038c:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pBStack_1304);
    }
    else {
      pbStack_1284 = (bio_st *)0x66;
LAB_00610380:
      if (pBStack_1304 != *ppBStack_1280) goto LAB_0061038c;
    }
    pbStack_1230 = (bio_st *)0x680000;
    pcVar20 = "a_bytes.c";
    pBStack_12f8 = (BIO *)0x8f;
    d2i = (char *)pbStack_1284;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    pBVar11 = (BIO_METHOD *)0x0;
  }
LAB_00610294:
  if (psStack_11bc == *(stack_st_void **)puStack_1278) {
    return (int)pBVar11;
  }
  uStack_122c = 0x610508;
  psStack_1238 = psStack_11bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pBStack_12c0 = (BIO_METHOD *)PTR___stack_chk_guard_006aabf0;
  ppsStack_12fc = &psStack_1238;
  psStack_1234 = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006aabf0;
  psVar10 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,(uchar **)ppsStack_12fc,(long)pBStack_12f8,
                         d2i,(free_func *)pcVar20,0x10,0);
  if (psVar10 == (stack_st_OPENSSL_BLOCK *)0x0) {
    pBStack_12f8 = (BIO *)&DAT_0000006e;
    d2i = "asn_pack.c";
    ppsStack_12fc = (stack_st_void **)0x7f;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
  }
  if (psStack_1234 == *(stack_st_OPENSSL_BLOCK **)pBStack_12c0) {
    return (int)psVar10;
  }
  pcStack_126c = ASN1_seq_pack;
  psVar10 = psStack_1234;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1300 = PTR___stack_chk_guard_006aabf0;
  puStack_128c = (undefined *)pBStack_12c0;
  puStack_1294 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pBStack_1288 = pBStack_1304;
  pBStack_1270 = data;
  pBVar11 = (BIO_METHOD *)i2d_ASN1_SET(psVar10,(uchar **)0x0,(undefined1 *)ppsStack_12fc,0x10,0,0);
  if (pBVar11 == (BIO_METHOD *)0x0) {
    pp = (BIO_METHOD **)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x70,"asn_pack.c");
    pBVar11 = (BIO_METHOD *)0x0;
  }
  else {
    pBStack_12c0 = (BIO_METHOD *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pBVar11,"asn_pack.c",0x5f);
    pBStack_1304 = pBVar11;
    if (pBStack_12c0 == (BIO_METHOD *)0x0) {
      pp = (BIO_METHOD **)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x41,"asn_pack.c");
      pBVar11 = (BIO_METHOD *)0x0;
    }
    else {
      pp = &pBStack_1298;
      pBStack_1298 = pBStack_12c0;
      i2d_ASN1_SET(psVar10,(uchar **)pp,(undefined1 *)ppsStack_12fc,0x10,0,0);
      if ((bio_st *)d2i != (bio_st *)0x0) {
        *(BIO_METHOD **)d2i = pBVar11;
      }
      pBVar11 = pBStack_12c0;
      if (pBStack_12f8 != (BIO *)0x0) {
        pBStack_12f8->method = pBStack_12c0;
      }
    }
  }
  if (puStack_1294 == *(undefined4 **)puStack_1300) {
    return (int)pBVar11;
  }
  pcStack_12bc = ASN1_unpack_string;
  puVar3 = puStack_1294;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1308 = PTR___stack_chk_guard_006aabf0;
  uStack_12c8 = puVar3[2];
  ppiVar18 = (int **)*puVar3;
  puVar3 = &uStack_12c8;
  puStack_12d8 = &_gp;
  iStack_12c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar23 = (*(code *)pp)(0);
  if (iVar23 == 0) {
    ppiVar18 = (int **)&DAT_0000006e;
    uStack_12e0 = 0x74;
    puVar3 = (undefined4 *)&DAT_00000088;
    iStack_12cc = iVar23;
    (**(code **)(puStack_12d8 + -0x6eb0))(0xd,0x88,0x6e,"asn_pack.c");
    iVar23 = iStack_12cc;
  }
  if (iStack_12c4 == *(int *)puStack_1308) {
    return iVar23;
  }
  pcStack_12f4 = ASN1_pack_string;
  iVar23 = iStack_12c4;
  (**(code **)(puStack_12d8 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_130c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ppiVar18 == (int **)0x0) {
    piVar22 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar22 != (int *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppiVar18 = (int **)&DAT_00000041;
    uVar4 = 0x81;
LAB_006108f8:
    piVar16 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppiVar18,"asn_pack.c",uVar4);
    piVar22 = (int *)0x0;
  }
  else {
    piVar22 = *ppiVar18;
    if (piVar22 == (int *)0x0) {
      piVar22 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar22 == (int *)0x0) goto LAB_00610928;
      *ppiVar18 = piVar22;
    }
LAB_0061083c:
    iVar2 = (*(code *)puVar3)(iVar23,0);
    *piVar22 = iVar2;
    if (iVar2 == 0) {
      ppiVar18 = (int **)&DAT_00000070;
      uVar4 = 0x88;
      goto LAB_006108f8;
    }
    ppiVar18 = (int **)&DAT_0000008b;
    iStack_1310 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"asn_pack.c");
    if (iStack_1310 == 0) {
      ppiVar18 = (int **)&DAT_00000041;
      piVar16 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      piVar22 = (int *)0x0;
    }
    else {
      piVar16 = &iStack_1310;
      piVar22[2] = iStack_1310;
      (*(code *)puVar3)(iVar23,piVar16);
    }
  }
  if (iStack_130c == *(int *)puVar1) {
    return (int)piVar22;
  }
  iVar23 = iStack_130c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppiVar18 == (int **)0x0) {
    piVar22 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar22 == (int *)0x0) {
LAB_00610a48:
      uVar19 = 0x41;
      uVar4 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    piVar22 = *ppiVar18;
    if (piVar22 == (int *)0x0) {
      piVar22 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar22 == (int *)0x0) goto LAB_00610a48;
      *ppiVar18 = piVar22;
    }
  }
  if (piVar22[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    piVar22[2] = 0;
  }
  iVar23 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar23,piVar22 + 2,piVar16);
  *piVar22 = iVar23;
  if (iVar23 == 0) {
    uVar19 = 0x70;
    uVar4 = 0xaa;
  }
  else {
    if (piVar22[2] != 0) {
      return (int)piVar22;
    }
    uVar19 = 0x41;
    uVar4 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar19,"asn_pack.c",uVar4);
  return 0;
LAB_0060f624:
  pcStack_bc = (char *)local_78;
  local_98 = pAStack_b8;
  (**(code **)(local_90 + -0x7fa8))(bio,"\"; boundary=\"----%s\"%s%s",local_78,pAStack_b8);
  (**(code **)(local_90 + -0x7fa8))
            (bio,"This is an S/MIME signed message%s%s",pAStack_b8,pAStack_b8);
  (**(code **)(local_90 + -0x7fa8))(bio,"------%s%s",pcStack_bc,pAStack_b8);
  local_60 = local_80;
  if ((flags & 0x8040U) == 0x40) {
    unaff_s5 = (BIO *)local_84->funcs;
    if (unaff_s5 == (BIO *)0x0) {
LAB_0060f914:
      pcStack_1158 = "asn_mime.c";
      local_98 = (ASN1_ITEM *)&DAT_0000018a;
      bStack_1110.shutdown = 0xd6;
      (**(code **)(local_90 + -0x6eb0))(0xd,0xd6,0xca);
    }
    else {
      pcStack_bc = (char *)&local_5c;
      if ((code *)unaff_s5->shutdown == (code *)0x0) goto LAB_0060f914;
      mdalgs = (stack_st_X509_ALGOR *)&local_60;
      local_58 = (BIO *)0x0;
      local_54 = 0;
      bStack_1110.shutdown = (int)mdalgs;
      pcStack_1158 = pcStack_bc;
      local_5c = bio;
      iVar23 = (*(code *)unaff_s5->shutdown)(0xc,mdalgs,local_84);
      if (0 < iVar23) {
        SMIME_crlf_copy(data,local_58,flags);
        bStack_1110.shutdown = (int)mdalgs;
        iVar23 = (*(code *)unaff_s5->shutdown)(0xd,mdalgs,local_84);
        pcStack_1158 = pcStack_bc;
        pcStack_bc = (char *)local_78;
        while (local_78 = (BIO **)pcStack_bc, local_58 != bio) {
          mdalgs = (stack_st_X509_ALGOR *)(**(code **)(local_90 + -0x742c))(local_58);
          (**(code **)(local_90 + -0x7f70))(local_58);
          pcStack_bc = (char *)local_78;
          local_58 = (BIO *)mdalgs;
        }
        if (0 < iVar23) goto LAB_0060f95c;
      }
    }
    goto LAB_0060f564;
  }
  SMIME_crlf_copy(data,bio,flags);
LAB_0060f95c:
  pcStack_bc = (char *)local_78;
  local_98 = pAStack_b8;
  (**(code **)(local_90 + -0x7fa8))(bio,"%s------%s%s",pAStack_b8,local_78);
  (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: %ssignature;",pcStack_1274);
  (**(code **)(local_90 + -0x7fa8))(bio," name=\"smime.p7s\"%s",pAStack_b8);
  (**(code **)(local_90 + -0x7fa8))(bio,"Content-Transfer-Encoding: base64%s",pAStack_b8);
  (**(code **)(local_90 + -0x7fa8))(bio,"Content-Disposition: attachment;");
  (**(code **)(local_90 + -0x7fa8))(bio," filename=\"smime.p7s\"%s%s",pAStack_b8,pAStack_b8);
  local_98 = local_84;
  B64_write_ASN1(bio,local_80,0,0);
  bStack_1110.shutdown = 0x67a5f0;
  pcStack_1158 = pcStack_bc;
  local_98 = pAStack_b8;
  local_94 = pAStack_b8;
  (**(code **)(local_90 + -0x7fa8))(bio,"%s------%s--%s%s",pAStack_b8);
  iVar23 = 1;
  goto LAB_0060f568;
}

