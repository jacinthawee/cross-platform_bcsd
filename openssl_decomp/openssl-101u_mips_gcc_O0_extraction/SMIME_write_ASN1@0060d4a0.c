
/* WARNING: Type propagation algorithm not settling */

int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  undefined *puVar1;
  int iVar2;
  byte bVar15;
  code cVar16;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  BIO *pBVar6;
  uint uVar7;
  BIO **ppBVar8;
  uint uVar9;
  stack_st_void *psVar10;
  BIO **ppBVar11;
  stack_st_OPENSSL_BLOCK *psVar12;
  BIO_METHOD *pBVar13;
  int *piVar14;
  BIO *pBVar17;
  BIO_METHOD **pp;
  int *piVar18;
  BIO *pBVar19;
  int **ppiVar20;
  int **ppiVar21;
  undefined4 uVar22;
  char *pcVar23;
  BIO *pBVar24;
  BIO *pBVar25;
  int *piVar26;
  char *unaff_s2;
  char *pcVar27;
  BIO *unaff_s5;
  BIO *pBVar28;
  code *pcVar29;
  int iStack_1498;
  int iStack_1494;
  undefined *puStack_148c;
  BIO *pBStack_1488;
  undefined *puStack_1484;
  uchar **ppuStack_1480;
  char *pcStack_147c;
  char *pcStack_1478;
  code *pcStack_1474;
  undefined4 uStack_1460;
  undefined *puStack_1458;
  int iStack_144c;
  undefined4 uStack_1448;
  int iStack_1444;
  BIO_METHOD *pBStack_1440;
  code *pcStack_143c;
  BIO_METHOD *pBStack_1418;
  undefined4 *puStack_1414;
  undefined *puStack_140c;
  BIO *pBStack_1408;
  int **ppiStack_1404;
  BIO *pBStack_1400;
  BIO *pBStack_13fc;
  BIO *pBStack_13f8;
  BIO *pBStack_13f4;
  BIO *pBStack_13f0;
  code *pcStack_13ec;
  uchar *puStack_13b8;
  stack_st_OPENSSL_BLOCK *psStack_13b4;
  BIO **ppBStack_13b0;
  undefined4 uStack_13ac;
  BIO *pBStack_1398;
  undefined4 uStack_1394;
  BIO **ppBStack_1390;
  undefined *puStack_1388;
  BIO *pBStack_137c;
  BIO **ppBStack_1378;
  BIO *pBStack_1374;
  uchar **ppuStack_1370;
  BIO *pBStack_136c;
  BIO **ppBStack_1368;
  char *pcStack_1364;
  BIO *pBStack_1360;
  undefined auStack_135c [8];
  undefined auStack_1354 [4];
  BIO *pBStack_1350;
  undefined auStack_134c [8];
  undefined auStack_1344 [8];
  _func_603 *p_Stack_133c;
  BIO *pBStack_1338;
  bio_st *pbStack_1334;
  bio_st *pbStack_1330;
  BIO *pBStack_132c;
  ulong uStack_1328;
  undefined auStack_1324 [48];
  ulong uStack_12f4;
  BIO *pBStack_12f0;
  stack_st_void *psStack_12ec;
  BIO *pBStack_12e8;
  BIO *pBStack_12e4;
  BIO *pBStack_12e0;
  code *pcStack_12dc;
  BIO *pBStack_12d8;
  BIO *pBStack_12d4;
  uchar *puStack_12cc;
  BIO *pBStack_12c8;
  BIO **ppBStack_12c4;
  BIO *pBStack_12c0;
  char *pcStack_12bc;
  undefined *puStack_12b8;
  BIO *pBStack_12b4;
  BIO *pBStack_12b0;
  BIO *pBStack_12ac;
  BIO *pBStack_12a8;
  code *pcStack_12a4;
  BIO *pBStack_1290;
  undefined *puStack_1288;
  BIO_METHOD *pBStack_1280;
  int **ppiStack_127c;
  BIO *pBStack_1278;
  BIO **ppBStack_1274;
  undefined *puStack_1270;
  BIO *pBStack_126c;
  BIO *pBStack_1268;
  BIO *pBStack_1264;
  BIO *pBStack_1260;
  code *pcStack_125c;
  BIO *pBStack_1248;
  undefined *puStack_1240;
  BIO *pBStack_1234;
  BIO *pBStack_122c;
  undefined auStack_1228 [4];
  _func_603 *p_Stack_1224;
  BIO BStack_1220;
  undefined *puStack_11e0;
  BIO *pBStack_11d4;
  BIO *pBStack_11d0;
  BIO *pBStack_11cc;
  undefined4 *puStack_11c8;
  bio_st **ppbStack_11c4;
  BIO *pBStack_11c0;
  undefined *puStack_11bc;
  int iStack_11b8;
  char *pcStack_11b4;
  BIO *pBStack_11b0;
  undefined auStack_11ac [8];
  undefined auStack_11a4 [4];
  BIO *pBStack_11a0;
  undefined auStack_119c [8];
  undefined auStack_1194 [8];
  _func_603 *p_Stack_118c;
  bio_st *pbStack_1188;
  bio_st *pbStack_1184;
  undefined auStack_1180 [16];
  bio_st *pbStack_1170;
  bio_st *pbStack_116c;
  uint uStack_1168;
  BIO *pBStack_1164;
  BIO *pBStack_1160;
  BIO *pBStack_115c;
  bio_st *pbStack_1158;
  BIO *pBStack_1154;
  BIO *pBStack_1150;
  undefined auStack_1148 [8];
  bio_st *pbStack_1140;
  uint uStack_113c;
  BIO *pBStack_1138;
  BIO *pBStack_1134;
  BIO *pBStack_1130;
  _func_595 *p_Stack_112c;
  BIO *pBStack_1128;
  BIO *pBStack_1124;
  BIO **ppBStack_111c;
  BIO *pBStack_1118;
  BIO *pBStack_1114;
  char *pcStack_1110;
  undefined *puStack_110c;
  BIO *pBStack_1108;
  BIO *pBStack_1104;
  undefined *puStack_1100;
  BIO *pBStack_10fc;
  ASN1_ITEM *pAStack_10f8;
  undefined4 uStack_10f4;
  BIO *pBStack_10e0;
  int iStack_10dc;
  bio_st **ppbStack_10d8;
  char *apcStack_10d0 [3];
  BIO aBStack_10c4 [64];
  BIO **ppBStack_c4;
  BIO *pBStack_c0;
  ASN1_ITEM *pAStack_bc;
  BIO *pBStack_b8;
  BIO *pBStack_b4;
  int iStack_b0;
  code *pcStack_ac;
  ASN1_ITEM *local_98;
  ASN1_ITEM *local_94;
  undefined *local_90;
  char *local_84;
  BIO *local_80;
  BIO *local_7c;
  char *local_78;
  int local_74;
  char *local_70;
  char *local_6c;
  int local_68;
  char *local_64;
  BIO *local_60;
  BIO *local_5c;
  BIO *local_58;
  char *local_54;
  undefined local_30;
  BIO *local_2c;
  
  pBStack_13f4 = (BIO *)PTR___stack_chk_guard_006a9ae8;
  local_90 = &_gp;
  local_2c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  if ((flags & 0x400U) == 0) {
    local_84 = "application/pkcs7-";
  }
  else {
    local_84 = "application/x-pkcs7-";
  }
  if ((flags & 0x800U) == 0) {
    pAStack_bc = (ASN1_ITEM *)0x63b2e4;
  }
  else {
    pAStack_bc = (ASN1_ITEM *)0x63b2ac;
  }
  pcVar23 = (char *)flags;
  local_80 = (BIO *)val;
  if (((flags & 0x40U) != 0) && (data != (BIO *)0x0)) {
    local_7c = (BIO *)&stack0xffffffb0;
    pcStack_1110 = &DAT_00000020;
    iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(local_7c);
    if (0 < iVar2) {
      pBVar6 = local_7c;
      do {
        pBVar19 = (BIO *)((int)&pBVar6->method + 1);
        bVar15 = (byte)*(code *)&pBVar6->method & 0xf;
        cVar16 = (code)(bVar15 + 0x37);
        if (bVar15 < 10) {
          cVar16 = (code)(bVar15 + 0x30);
        }
        *(code *)&pBVar6->method = cVar16;
        pBVar6 = pBVar19;
      } while (pBVar19 != (BIO *)&local_30);
      local_30 = 0;
      (**(code **)(local_90 + -0x7fa8))(bio,"MIME-Version: 1.0%s",pAStack_bc);
      unaff_s5 = (BIO *)0x0;
      iVar2 = 0;
      (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: multipart/signed;");
      (**(code **)(local_90 + -0x7fa8))(bio," protocol=\"%ssignature\";",local_84);
      (**(code **)(local_90 + -0x7e88))(bio,&DAT_00679c08);
      local_74 = 0;
      local_78 = ",";
      local_70 = "sha-256";
      local_64 = "TBEX";
      local_6c = "sha-512";
      local_68 = 0x680000;
LAB_0060d63c:
      do {
        iVar3 = (**(code **)(local_90 + -0x7fb4))(mdalgs);
        if (iVar3 <= iVar2) goto LAB_0060d8a8;
        if (unaff_s5 != (BIO *)0x0) {
          (**(code **)(local_90 + -0x7fcc))(bio,local_78,1);
        }
        puVar4 = (undefined4 *)(**(code **)(local_90 + -0x7fbc))(mdalgs,iVar2);
        unaff_s5 = (BIO *)(**(code **)(local_90 + -0x7cb4))(*puVar4);
        uVar5 = (**(code **)(local_90 + -0x7d44))(unaff_s5);
        iVar3 = (**(code **)(local_90 + -0x7eb4))(uVar5);
        if (iVar3 == 0) {
LAB_0060d868:
          if (unaff_s5 == (BIO *)0x2a0) {
            unaff_s5 = (BIO *)0x1;
            iVar2 = iVar2 + 1;
            (**(code **)(local_90 + -0x7e88))(bio,local_70);
            goto LAB_0060d63c;
          }
          if ((int)unaff_s5 < 0x2a1) {
            if (unaff_s5 == (BIO *)&SUB_00000004) {
              unaff_s5 = (BIO *)0x1;
              (**(code **)(local_90 + -0x7e88))(bio,&DAT_00631ba0);
              iVar2 = iVar2 + 1;
              goto LAB_0060d63c;
            }
            if (unaff_s5 == (BIO *)&DAT_00000040) {
              unaff_s5 = (BIO *)0x1;
              (**(code **)(local_90 + -0x7e88))(bio,&DAT_0064d818);
              iVar2 = iVar2 + 1;
              goto LAB_0060d63c;
            }
          }
          else {
            if (unaff_s5 == (BIO *)0x2a2) {
              unaff_s5 = (BIO *)0x1;
              iVar2 = iVar2 + 1;
              (**(code **)(local_90 + -0x7e88))(bio,local_6c);
              goto LAB_0060d63c;
            }
            if ((int)unaff_s5 < 0x2a2) {
              unaff_s5 = (BIO *)0x1;
              iVar2 = iVar2 + 1;
              (**(code **)(local_90 + -0x7e88))(bio,local_68 + -0x63e4);
              goto LAB_0060d63c;
            }
            if (unaff_s5 == (BIO *)0x329) {
              (**(code **)(local_90 + -0x7e88))(bio,"gostr3411-94");
              goto LAB_0060d8a8;
            }
          }
          if (local_74 == 0) {
            unaff_s5 = (BIO *)0x1;
            iVar2 = iVar2 + 1;
            (**(code **)(local_90 + -0x7e88))(bio,local_64 + -0x51e4);
            local_74 = 1;
          }
          else {
            unaff_s5 = (BIO *)0x0;
            iVar2 = iVar2 + 1;
          }
          goto LAB_0060d63c;
        }
        if (*(code **)(iVar3 + 0x48) == (code *)0x0) goto LAB_0060d868;
        iVar3 = (**(code **)(iVar3 + 0x48))(0,2,0,&local_5c);
        if (iVar3 < 1) {
          if (iVar3 == -2) goto LAB_0060d868;
          goto LAB_0060d8a8;
        }
        unaff_s5 = (BIO *)0x1;
        iVar2 = iVar2 + 1;
        (**(code **)(local_90 + -0x7e88))(bio,local_5c);
        (**(code **)(local_90 + -0x7f58))(local_5c);
      } while( true );
    }
    goto LAB_0060d7e4;
  }
  if (ctype_nid == 0x17) {
    pcVar27 = "enveloped-data";
    unaff_s2 = &DAT_00679b58;
LAB_0060dadc:
    (**(code **)(local_90 + -0x7fa8))(bio,"MIME-Version: 1.0%s",pAStack_bc);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Disposition: attachment;");
    (**(code **)(local_90 + -0x7fa8))(bio," filename=\"%s\"%s",unaff_s2,pAStack_bc);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: %smime;",local_84);
    (**(code **)(local_90 + -0x7fa8))(bio," smime-type=%s;",pcVar27);
    mdalgs = (stack_st_X509_ALGOR *)pcVar27;
  }
  else {
    if (ctype_nid == 0x16) {
      if (econt_nid == 0xcc) {
        pcVar27 = "signed-receipt";
        unaff_s2 = &DAT_00679b58;
      }
      else {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(mdalgs);
        if (iVar2 < 0) {
          pcVar27 = "certs-only";
          unaff_s2 = &DAT_00679b58;
        }
        else {
          pcVar27 = "signed-data";
          unaff_s2 = &DAT_00679b58;
        }
      }
      goto LAB_0060dadc;
    }
    if (ctype_nid == 0x312) {
      pcVar27 = "compressed-data";
      unaff_s2 = "smime.p7z";
      goto LAB_0060dadc;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(bio,"MIME-Version: 1.0%s",pAStack_bc);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Disposition: attachment;");
    unaff_s2 = &DAT_00679b58;
    (**(code **)(local_90 + -0x7fa8))(bio," filename=\"%s\"%s",&DAT_00679b58,pAStack_bc);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: %smime;",local_84);
  }
  (**(code **)(local_90 + -0x7fa8))(bio," name=\"%s\"%s",unaff_s2,pAStack_bc);
  (**(code **)(local_90 + -0x7fa8))
            (bio,"Content-Transfer-Encoding: base64%s%s",pAStack_bc,pAStack_bc);
  local_98 = it;
  pcStack_1110 = (char *)local_80;
  iVar2 = B64_write_ASN1(bio,local_80,data);
  if (iVar2 == 0) goto LAB_0060d7e4;
  pcStack_1110 = "%s";
  (**(code **)(local_90 + -0x7fa8))(bio,"%s",pAStack_bc);
  iVar2 = 1;
LAB_0060d7e8:
  if (local_2c == *(BIO **)pBStack_13f4) {
    return iVar2;
  }
  pcStack_ac = SMIME_text;
  BStack_1220.init = (int)local_2c;
  (**(code **)(local_90 + -0x5330))();
  BStack_1220.flags = (int)PTR___stack_chk_guard_006a9ae8;
  ppbStack_10d8 = (bio_st **)&_gp;
  ppBStack_c4 = *(BIO ***)PTR___stack_chk_guard_006a9ae8;
  pBStack_c0 = bio;
  pBStack_b8 = (BIO *)unaff_s2;
  pBStack_b4 = (BIO *)mdalgs;
  iStack_b0 = flags;
  pBVar6 = (BIO *)mime_parse_hdr();
  if (pBVar6 == (BIO *)0x0) {
    pBVar19 = (BIO *)0xcf;
    pcVar23 = "asn_mime.c";
    pBStack_10e0 = (BIO *)0x238;
    pcStack_12bc = (char *)0xd5;
    (*(code *)ppbStack_10d8[-0x1bab])(0xd);
    uVar7 = 0;
  }
  else {
    apcStack_10d0[0] = "content-type";
    iVar2 = (*(code *)ppbStack_10d8[-0x1b67])(pBVar6,apcStack_10d0);
    if ((iVar2 < 0) ||
       (flags = (*(code *)ppbStack_10d8[-0x1fef])(pBVar6,iVar2), (BIO *)flags == (BIO *)0x0)) {
LAB_0060dee0:
      pBVar19 = (BIO *)0xce;
      pcVar23 = "asn_mime.c";
      pBStack_10e0 = (BIO *)0x23c;
      (*(code *)ppbStack_10d8[-0x1bab])(0xd,0xd5);
    }
    else {
      if (*(_func_603 **)(flags + 4) == (_func_603 *)0x0) goto LAB_0060dee0;
      iVar2 = (*(code *)ppbStack_10d8[-0x14b2])(*(_func_603 **)(flags + 4),"text/plain");
      if (iVar2 == 0) {
        (*(code *)ppbStack_10d8[-0x1f62])(pBVar6,mime_hdr_free);
        while( true ) {
          pBVar19 = (BIO *)0x1000;
          pcStack_12bc = (char *)aBStack_10c4;
          iVar2 = (*(code *)ppbStack_10d8[-0x1e48])(BStack_1220.init);
          if (iVar2 < 1) break;
          (*(code *)ppbStack_10d8[-0x1ff3])(pcStack_1110,aBStack_10c4,iVar2);
        }
        uVar7 = (uint)(iVar2 == 0);
        bio = aBStack_10c4;
        goto LAB_0060de50;
      }
      pcVar23 = "asn_mime.c";
      pBStack_10e0 = (BIO *)0x241;
      (*(code *)ppbStack_10d8[-0x1bab])(0xd,0xd5,0xcd);
      pBVar19 = *(BIO **)(flags + 4);
      (*(code *)ppbStack_10d8[-0x1b29])(2,"type: ");
    }
    pcVar29 = mime_hdr_free;
    (*(code *)ppbStack_10d8[-0x1f62])(pBVar6);
    uVar7 = 0;
    pcStack_12bc = (char *)pcVar29;
    bio = pBVar6;
  }
LAB_0060de50:
  if (ppBStack_c4 == *(BIO ***)BStack_1220.flags) {
    return uVar7;
  }
  uStack_10f4 = 0x60df48;
  BStack_1220.shutdown = (int)ppBStack_c4;
  (*(code *)ppbStack_10d8[-0x14cc])();
  pAStack_10f8 = it;
  ppbStack_11c4 = ppbStack_10d8;
  puStack_11c8 = (undefined4 *)PTR___stack_chk_guard_006a9ae8;
  puStack_1100 = (undefined *)pBStack_13f4;
  puStack_110c = (undefined *)BStack_1220.flags;
  puStack_11e0 = &_gp;
  ppBStack_111c = *(BIO ***)PTR___stack_chk_guard_006a9ae8;
  pBVar6 = (BIO *)(uint)(iStack_10dc < 0x15);
  pBStack_12c8 = pBVar19;
  pBStack_1268 = (BIO *)pcVar23;
  pBStack_11cc = (BIO *)pcStack_12bc;
  pBStack_1118 = bio;
  pBStack_1114 = (BIO *)BStack_1220.init;
  pBStack_1108 = (BIO *)flags;
  pBStack_1104 = unaff_s5;
  pBStack_10fc = data;
  if (pBVar6 == (BIO *)0x0) {
    *ppbStack_10d8 = (bio_st *)0xc5;
  }
  else if ((((BIO **)BStack_1220.shutdown == (BIO **)0x0) ||
           (pBVar25 = *(BIO **)BStack_1220.shutdown, pBVar25 == (BIO *)0x0)) &&
          (pBVar25 = (BIO *)(*(code *)PTR_ASN1_STRING_new_006a8790)(), pBVar25 == (BIO *)0x0)) {
    pBVar6 = (BIO *)0x0;
    bio = pBVar25;
    BStack_1220.init = (int)pBVar19;
    BStack_1220.flags = (int)pcVar23;
  }
  else {
    pBStack_1268 = (BIO *)auStack_11a4;
    pBStack_12c8 = (BIO *)(auStack_11ac + 4);
    pcStack_12bc = auStack_11ac;
    pBStack_11b0 = (BIO *)pBStack_11cc->method;
    BStack_1220.num_read = (ulong)pBVar19;
    uVar7 = (**(code **)(puStack_11e0 + -0x6e30))(&pBStack_11b0);
    bio = pBVar25;
    if ((uVar7 & 0x80) == 0) {
      flags = (int)auStack_11ac._4_4_;
      if (auStack_11ac._4_4_ == (BIO *)pcVar23) {
        if ((uVar7 & 0x20) != 0) {
          pbStack_116c = (bio_st *)0x0;
          pBStack_1150 = pBStack_11cc;
          auStack_1180._12_4_ = pBStack_11b0;
          pBStack_115c = auStack_11ac._0_4_;
          pBStack_1160 = pBStack_10e0;
          if (pBVar19 == (BIO *)0x0) {
            pbStack_1158 = (bio_st *)0x0;
          }
          else {
            pbStack_1158 = (bio_st *)((int)&pBVar19->method + (int)&pBStack_11b0->method);
          }
          auStack_11ac._4_4_ = (BIO *)0x0;
          pBStack_11d4 = (BIO *)0x0;
          p_Stack_118c = (_func_603 *)0x0;
          data = (BIO *)(auStack_1180 + 0xc);
          pbStack_1184 = (bio_st *)0x0;
          pBStack_13f4 = (BIO *)auStack_1194;
          pbStack_1188 = (bio_st *)0x0;
          it = (ASN1_ITEM *)(auStack_119c + 4);
          pcStack_11b4 = "a_bytes.c";
          uVar9 = uVar7 & 1;
          uStack_1168 = uVar7;
          pBStack_1164 = (BIO *)pcVar23;
          do {
            if (uVar9 != 0) {
              pcStack_12bc = (char *)((int)pbStack_1158 - (int)auStack_1180._12_4_);
              pbStack_1170 = (bio_st *)(**(code **)(puStack_11e0 + -0x69e0))(data);
              if (pbStack_1170 == (bio_st *)0x0) goto LAB_0060e128;
LAB_0060e2f0:
              pBVar19 = (BIO *)(auStack_1180 + 0xc);
              iVar2 = (**(code **)(puStack_11e0 + -0x69e4))(pBVar19);
              if (iVar2 != 0) {
                pBVar25->method = (BIO_METHOD *)auStack_11ac._4_4_;
                if (pBVar25->cb_arg != (char *)0x0) {
                  (**(code **)(puStack_11e0 + -0x7f58))();
                }
                pBVar25->cb_arg = (char *)pbStack_1188;
                pBVar6 = auStack_1180._12_4_;
                if (pBStack_11d4 != (BIO *)0x0) {
                  (**(code **)(puStack_11e0 + -0x6644))(pBStack_11d4);
                  pBVar6 = auStack_1180._12_4_;
                }
                goto LAB_0060e288;
              }
LAB_0060e1b0:
              if (pBStack_11d4 == (BIO *)0x0) goto LAB_0060e1cc;
              goto LAB_0060e1b8;
            }
            if ((int)pBStack_115c < 1) goto LAB_0060e2f0;
LAB_0060e128:
            unaff_s5 = pBStack_1160;
            pBVar19 = (BIO *)(auStack_1180 + 0xc);
            pBStack_11d0 = pBStack_1164;
            pBStack_1154 = auStack_1180._12_4_;
            pcVar23 = (char *)((int)pbStack_1158 - (int)auStack_1180._12_4_);
            if (iStack_10dc == 0x14) {
              pbStack_116c = (bio_st *)0xc5;
              goto LAB_0060e1b0;
            }
            pBVar19 = pBStack_11d4;
            if ((pBStack_11d4 == (BIO *)0x0) &&
               (pBVar19 = (BIO *)(**(code **)(puStack_11e0 + -0x6650))(), pBVar19 == (BIO *)0x0))
            goto LAB_0060e1cc;
            pcStack_12bc = auStack_11a4 + 8;
            pBStack_11a0 = auStack_1180._12_4_;
            pBStack_12c8 = (BIO *)it;
            pBStack_1268 = pBStack_13f4;
            BStack_1220.num_read = (ulong)pcVar23;
            uVar7 = (**(code **)(puStack_11e0 + -0x6e30))(auStack_11a4 + 4);
            if ((uVar7 & 0x80) != 0) {
              pbStack_116c = (bio_st *)0x66;
LAB_0060e194:
              if (pBVar19 != pBStack_11d4) {
                (**(code **)(puStack_11e0 + -0x6644))(pBVar19);
              }
              goto LAB_0060e1b0;
            }
            if (pBStack_11d0 != auStack_119c._4_4_) {
              pbStack_116c = (bio_st *)&DAT_000000a8;
              goto LAB_0060e194;
            }
            if ((uVar7 & 0x20) == 0) {
              if (auStack_119c._0_4_ == (BIO *)0x0) {
                if ((_func_595 *)pBVar19->cb_arg == (_func_595 *)0x0) {
                  pcVar23 = (char *)0x0;
                  auStack_1180._12_4_ = pBStack_11a0;
                }
                else {
                  pcVar23 = (char *)0x0;
                  (**(code **)(puStack_11e0 + -0x7f58))();
                  auStack_1180._12_4_ = pBStack_11a0;
                }
              }
              else {
                if (((int)pBVar19->method < (int)auStack_119c._0_4_) ||
                   (pcVar23 = pBVar19->cb_arg, (BIO *)pcVar23 == (BIO *)0x0)) {
                  pBStack_12c8 = (BIO *)&DAT_000000e9;
                  pcStack_12bc = pcStack_11b4;
                  pcVar23 = (char *)(**(code **)(puStack_11e0 + -0x7dd8))
                                              ((code *)((int)&(auStack_119c._0_4_)->method + 1));
                  if ((BIO *)pcVar23 == (BIO *)0x0) {
                    pbStack_116c = (bio_st *)&DAT_00000041;
                    goto LAB_0060e194;
                  }
                  if ((_func_595 *)pBVar19->cb_arg != (_func_595 *)0x0) {
                    (**(code **)(puStack_11e0 + -0x7f58))();
                  }
                }
                pBStack_12c8 = auStack_119c._0_4_;
                (**(code **)(puStack_11e0 + -0x52f4))(pcVar23,pBStack_11a0);
                *(code *)((int)&(auStack_119c._0_4_)->method + (int)(BIO_METHOD **)pcVar23) =
                     (code)0x0;
                auStack_1180._12_4_ =
                     (BIO *)((int)&(auStack_119c._0_4_)->method + (int)&pBStack_11a0->method);
              }
              pBVar19->method = (BIO_METHOD *)auStack_119c._0_4_;
              pBVar19->cb_arg = pcVar23;
              pBVar19->callback = (_func_603 *)pBStack_11d0;
              pBVar6 = auStack_119c._0_4_;
            }
            else {
              pbStack_1140 = (bio_st *)0x0;
              auStack_1148._0_4_ = pBStack_11a0;
              pBStack_1130 = auStack_119c._0_4_;
              pBStack_1138 = pBStack_11d0;
              pBStack_1134 = unaff_s5;
              if ((BIO *)pcVar23 == (BIO *)0x0) {
                p_Stack_112c = (_func_595 *)0x0;
              }
              else {
                p_Stack_112c = (_func_595 *)((int)pBStack_11a0 + (int)pcVar23);
              }
              pBStack_11c0 = (BIO *)auStack_1148;
              pBStack_11d0 = (BIO *)0x0;
              auStack_1194._4_4_ = (BIO **)0x0;
              unaff_s5 = (BIO *)(auStack_1194 + 4);
              puStack_11bc = auStack_1148 + 8;
              auStack_1180._0_4_ = (bio_st *)0x0;
              pcVar23 = auStack_1180;
              auStack_1180._8_4_ = (char *)0x0;
              auStack_1180._4_4_ = (bio_st *)0x0;
              iStack_11b8 = iStack_10dc + 2;
              pcStack_12bc = (char *)auStack_119c._0_4_;
              uStack_113c = uVar7;
              pBStack_1124 = data;
              if ((uVar7 & 1) != 0) goto LAB_0060e4a8;
              while (pcVar29 = *(code **)(puStack_11e0 + -0x69e4), 0 < (int)pBStack_1130) {
                while( true ) {
                  BStack_1220.ex_data.sk = (stack_st_void *)puStack_11bc;
                  BStack_1220.num_read = (ulong)pBStack_1134;
                  pBStack_12c8 = (BIO *)(p_Stack_112c + -(int)auStack_1148._0_4_);
                  pBStack_1128 = auStack_1148._0_4_;
                  BStack_1220.num_write = iStack_11b8;
                  pcStack_12bc = (char *)pBStack_11c0;
                  pBStack_1268 = pBStack_1138;
                  iVar2 = int_d2i_ASN1_bytes(unaff_s5);
                  if (iVar2 == 0) goto LAB_0060e610;
                  pcStack_12bc = (char *)((int)&(*auStack_1194._4_4_)->method +
                                         (int)&pBStack_11d0->method);
                  iVar2 = (**(code **)(puStack_11e0 + -0x72a0))(pcVar23);
                  if (iVar2 == 0) {
                    pbStack_1140 = (bio_st *)&DAT_00000007;
                    goto LAB_0060e610;
                  }
                  pBStack_12c8 = *auStack_1194._4_4_;
                  pcStack_12bc = (char *)auStack_1194._4_4_[2];
                  (**(code **)(puStack_11e0 + -0x52f4))
                            ((code *)((int)&pBStack_11d0->method +
                                     (int)&(auStack_1180._4_4_)->method));
                  if ((uStack_113c & 1) == 0) {
                    pcStack_12bc = (char *)((int)auStack_1148._0_4_ - (int)pBStack_1128);
                    pBStack_1130 = (BIO *)((int)pBStack_1130 - (int)pcStack_12bc);
                  }
                  pBStack_11d0 = (BIO *)((int)&(*auStack_1194._4_4_)->method +
                                        (int)&pBStack_11d0->method);
                  if ((uStack_113c & 1) == 0) break;
LAB_0060e4a8:
                  pcStack_12bc = (char *)(p_Stack_112c + -(int)auStack_1148._0_4_);
                  auStack_1148._4_4_ =
                       (_func_603 *)(**(code **)(puStack_11e0 + -0x69e0))(pBStack_11c0);
                  if (auStack_1148._4_4_ != (_func_603 *)0x0) {
                    pcVar29 = *(code **)(puStack_11e0 + -0x69e4);
                    goto LAB_0060e4d0;
                  }
                }
              }
LAB_0060e4d0:
              iVar2 = (*pcVar29)(pBStack_11c0);
              if (iVar2 == 0) {
LAB_0060e610:
                if (auStack_1194._4_4_ != (BIO **)0x0) {
                  (**(code **)(puStack_11e0 + -0x6644))();
                }
                if (auStack_1180._4_4_ != (bio_st *)0x0) {
                  (**(code **)(puStack_11e0 + -0x7f58))();
                }
                pbStack_116c = pbStack_1140;
                goto LAB_0060e194;
              }
              pBVar19->method = (BIO_METHOD *)pBStack_11d0;
              if ((_func_595 *)pBVar19->cb_arg != (_func_595 *)0x0) {
                (**(code **)(puStack_11e0 + -0x7f58))();
              }
              pBVar19->cb_arg = (char *)auStack_1180._4_4_;
              if (auStack_1194._4_4_ != (BIO **)0x0) {
                (**(code **)(puStack_11e0 + -0x6644))();
              }
              auStack_1180._12_4_ = auStack_1148._0_4_;
              pBVar6 = (BIO *)pBVar19->method;
            }
            pcStack_12bc = (char *)((int)&pBVar6->method + (int)&(auStack_11ac._4_4_)->method);
            iVar2 = (**(code **)(puStack_11e0 + -0x72a0))(&p_Stack_118c);
            if (iVar2 == 0) goto LAB_0060e67c;
            pBStack_12c8 = (BIO *)pBVar19->method;
            pcStack_12bc = pBVar19->cb_arg;
            (**(code **)(puStack_11e0 + -0x52f4))
                      ((code *)((int)&(auStack_11ac._4_4_)->method + (int)&pbStack_1188->method));
            uVar9 = uStack_1168 & 1;
            if (uVar9 == 0) {
              pcStack_12bc = (char *)((int)auStack_1180._12_4_ - (int)pBStack_1154);
              pBStack_115c = (BIO *)((int)pBStack_115c - (int)pcStack_12bc);
            }
            auStack_11ac._4_4_ =
                 (BIO *)((int)&pBVar19->method->type + (int)&(auStack_11ac._4_4_)->method);
            pBStack_11d4 = pBVar19;
          } while( true );
        }
        if (auStack_11ac._0_4_ == (BIO *)0x0) {
          if (pBVar25->cb_arg == (char *)0x0) {
            pBVar19 = (BIO *)0x0;
            pBVar6 = pBStack_11b0;
          }
          else {
            pBVar19 = (BIO *)0x0;
            (**(code **)(puStack_11e0 + -0x7f58))();
            pBVar6 = pBStack_11b0;
          }
        }
        else {
          if ((int)pBVar25->method < (int)auStack_11ac._0_4_) {
            pcVar29 = *(code **)(puStack_11e0 + -0x7dd8);
LAB_0060e690:
            pBStack_12c8 = (BIO *)&DAT_000000e9;
            pcStack_12bc = "a_bytes.c";
            pBVar19 = (BIO *)(*pcVar29)((char *)((int)&(auStack_11ac._0_4_)->method + 1));
            if (pBVar19 == (BIO *)0x0) {
              *ppbStack_11c4 = (bio_st *)&DAT_00000041;
              goto LAB_0060e014;
            }
            if (pBVar25->cb_arg != (char *)0x0) {
              (**(code **)(puStack_11e0 + -0x7f58))();
            }
          }
          else {
            pBVar19 = (BIO *)pBVar25->cb_arg;
            pcVar29 = *(code **)(puStack_11e0 + -0x7dd8);
            if (pBVar19 == (BIO *)0x0) goto LAB_0060e690;
          }
          pcStack_12bc = (char *)pBStack_11b0;
          pBStack_12c8 = auStack_11ac._0_4_;
          (**(code **)(puStack_11e0 + -0x52f4))(pBVar19);
          *(code *)((int)&(auStack_11ac._0_4_)->method + (int)&pBVar19->method) = (code)0x0;
          pBVar6 = (BIO *)((int)&(auStack_11ac._0_4_)->method + (int)&pBStack_11b0->method);
        }
        pBVar25->method = (BIO_METHOD *)auStack_11ac._0_4_;
        pBVar25->cb_arg = (char *)pBVar19;
        pBVar25->callback = (_func_603 *)auStack_11ac._4_4_;
LAB_0060e288:
        if ((BIO **)BStack_1220.shutdown != (BIO **)0x0) {
          *(BIO **)BStack_1220.shutdown = pBVar25;
        }
        pBStack_11cc->method = (BIO_METHOD *)pBVar6;
        pBVar6 = pBVar25;
        BStack_1220.init = (int)pBVar19;
        BStack_1220.flags = (int)pcVar23;
        flags = (int)auStack_11ac._4_4_;
        goto LAB_0060e038;
      }
      *ppbStack_11c4 = (bio_st *)&DAT_000000a8;
    }
    else {
      *ppbStack_11c4 = (bio_st *)0x66;
    }
LAB_0060e014:
    BStack_1220.flags = (int)pcVar23;
    BStack_1220.init = (int)pBVar19;
    if (((BIO **)BStack_1220.shutdown == (BIO **)0x0) ||
       (pBVar6 = (BIO *)0x0, pBVar25 != *(BIO **)BStack_1220.shutdown)) {
      (**(code **)(puStack_11e0 + -0x6644))(pBVar25);
      pBVar6 = (BIO *)0x0;
    }
  }
LAB_0060e038:
  if (ppBStack_111c == (BIO **)*puStack_11c8) {
    return (int)pBVar6;
  }
  BStack_1220.num = (int)d2i_ASN1_type_bytes;
  ppBStack_12c4 = ppBStack_111c;
  (**(code **)(puStack_11e0 + -0x5330))();
  puStack_1270 = PTR___stack_chk_guard_006a9ae8;
  pBStack_122c = (BIO *)*(BIO_METHOD **)pcStack_12bc;
  pcVar23 = auStack_1228 + 8;
  puStack_1240 = &_gp;
  pBVar6 = (BIO *)auStack_1228;
  BStack_1220.callback = *(_func_603 **)PTR___stack_chk_guard_006a9ae8;
  pBStack_1248 = pBStack_12c8;
  BStack_1220.cb_arg = (char *)bio;
  BStack_1220.retry_reason = flags;
  uVar7 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&pBStack_122c,pBVar6,auStack_1228 + 4);
  if ((uVar7 & 0x80) == 0) {
    pBVar19 = (BIO *)0x99;
    if (0x1f < (int)p_Stack_1224) goto LAB_0060e7d0;
    uVar7 = (**(code **)(puStack_1240 + -0x60f8))();
    if (((uint)pBStack_1268 & uVar7) == 0) {
      pBVar19 = (BIO *)0xa9;
      goto LAB_0060e7d0;
    }
    if (p_Stack_1224 != (_func_603 *)0x3) {
      if (((ppBStack_12c4 == (BIO **)0x0) ||
          (pBStack_12c8 = *ppBStack_12c4, pBStack_12c8 == (BIO *)0x0)) &&
         (pBStack_12c8 = (BIO *)(**(code **)(puStack_1240 + -0x6650))(), pBStack_12c8 == (BIO *)0x0)
         ) {
        pBVar25 = (BIO *)0x0;
        goto LAB_0060e7f8;
      }
      pBStack_1268 = (BIO *)0x0;
      if (auStack_1228 == (undefined  [4])0x0) {
LAB_0060e874:
        if ((_func_595 *)pBStack_12c8->cb_arg != (_func_595 *)0x0) {
          (**(code **)(puStack_1240 + -0x7f58))();
        }
        pBStack_12c8->cb_arg = (char *)pBStack_1268;
        pBStack_12c8->method = (BIO_METHOD *)auStack_1228;
        pBStack_12c8->callback = p_Stack_1224;
        if (ppBStack_12c4 != (BIO **)0x0) {
          *ppBStack_12c4 = pBStack_12c8;
        }
        *(BIO_METHOD **)pcStack_12bc = (BIO_METHOD *)pBStack_122c;
        pBVar25 = pBStack_12c8;
        goto LAB_0060e7f8;
      }
      pBStack_1234 = (BIO *)0x680000;
      pBStack_1268 = (BIO *)(**(code **)(puStack_1240 + -0x7dd8))
                                      ((code *)((int)(BIO_METHOD **)auStack_1228 + 1),"a_bytes.c",
                                       0x6b);
      if (pBStack_1268 != (BIO *)0x0) {
        pBVar6 = pBStack_122c;
        pBVar19 = (BIO *)auStack_1228;
        pcVar23 = (char *)pBStack_1234;
        (**(code **)(puStack_1240 + -0x52f4))(pBStack_1268);
        *(code *)((int)(BIO_METHOD **)auStack_1228 + (int)&pBStack_1268->method) = (code)0x0;
        pBStack_122c = (BIO *)((int)(BIO_METHOD **)auStack_1228 + (int)&pBStack_122c->method);
        goto LAB_0060e874;
      }
      pcVar23 = (char *)&pBStack_1234[-0x189].ptr;
      pBVar19 = (BIO *)&DAT_00000041;
      pBVar6 = (BIO *)&DAT_00000095;
      pBStack_1248 = (BIO *)&DAT_00000080;
      (**(code **)(puStack_1240 + -0x6eac))(0xd);
      if ((ppBStack_12c4 == (BIO **)0x0) || (pBStack_12c8 != *ppBStack_12c4)) {
        (**(code **)(puStack_1240 + -0x6644))(pBStack_12c8);
        pBVar25 = (BIO *)0x0;
        goto LAB_0060e7f8;
      }
      goto LAB_0060e7f4;
    }
    pBVar6 = (BIO *)pcStack_12bc;
    pBVar19 = pBStack_12c8;
    pBVar25 = (BIO *)(**(code **)(puStack_1240 + -0x55e8))(ppBStack_12c4);
  }
  else {
    pBVar19 = (BIO *)0x0;
LAB_0060e7d0:
    pBVar6 = (BIO *)&DAT_00000095;
    pcVar23 = "a_bytes.c";
    pBStack_1248 = (BIO *)&DAT_00000080;
    (**(code **)(puStack_1240 + -0x6eac))(0xd);
LAB_0060e7f4:
    pBVar25 = (BIO *)0x0;
  }
LAB_0060e7f8:
  if ((BIO *)BStack_1220.callback == *(BIO **)puStack_1270) {
    return (int)pBVar25;
  }
  pcStack_125c = i2d_ASN1_bytes;
  pBVar25 = (BIO *)BStack_1220.callback;
  (**(code **)(puStack_1240 + -0x5330))();
  pBStack_13fc = (BIO *)PTR___stack_chk_guard_006a9ae8;
  puStack_1288 = &_gp;
  ppiStack_127c = *(int ***)PTR___stack_chk_guard_006a9ae8;
  ppBVar8 = (BIO **)0x0;
  pBVar17 = pBVar6;
  pBStack_1488 = pBVar19;
  pBVar24 = (BIO *)pcVar23;
  pBStack_12c0 = (BIO *)puStack_1270;
  pBStack_1278 = pBStack_12c8;
  ppBStack_1274 = ppBStack_12c4;
  pBStack_126c = (BIO *)pcStack_12bc;
  pBStack_1264 = unaff_s5;
  pBStack_1260 = pBStack_13f4;
  if (pBVar25 != (BIO *)0x0) {
    pBStack_12c0 = pBVar19;
    if (pBVar19 == (BIO *)0x3) {
      ppBVar8 = (BIO **)(*(code *)PTR_i2d_ASN1_BIT_STRING_006a97fc)();
      pBVar17 = pBVar6;
      pBVar24 = (BIO *)pcVar23;
    }
    else {
      pBVar28 = (BIO *)pBVar25->method;
      pBVar17 = pBVar28;
      ppBVar8 = (BIO **)(*(code *)PTR_ASN1_object_size_006a83e4)(0);
      pBStack_12c8 = pBVar25;
      ppBStack_12c4 = ppBVar8;
      pcStack_12bc = (char *)pBVar6;
      unaff_s5 = pBVar28;
      pBStack_13f4 = (BIO *)pcVar23;
      if (pBVar6 != (BIO *)0x0) {
        pBStack_1280 = pBVar6->method;
        pBVar24 = pBVar19;
        pBStack_1290 = (BIO *)pcVar23;
        (**(code **)(puStack_1288 + -0x69f8))
                  (&pBStack_1280,&pBVar19[-1].num_read < &SUB_00000002,pBVar28);
        pBStack_1488 = (BIO *)pBVar25->method;
        pBVar17 = (BIO *)pBVar25->cb_arg;
        (**(code **)(puStack_1288 + -0x52f4))(pBStack_1280);
        pBVar6->method = (BIO_METHOD *)((int)&pBVar25->method->type + (int)&pBStack_1280->type);
      }
    }
  }
  if (ppiStack_127c == *(int ***)pBStack_13fc) {
    return (int)ppBVar8;
  }
  pcStack_12a4 = d2i_ASN1_bytes;
  ppiStack_1404 = ppiStack_127c;
  (**(code **)(puStack_1288 + -0x5330))();
  ppuStack_1370 = (uchar **)PTR___stack_chk_guard_006a9ae8;
  puStack_12b8 = (undefined *)pBStack_13fc;
  puStack_1388 = &_gp;
  puStack_12cc = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  pcVar23 = (char *)pBVar24;
  pBStack_1400 = pBVar24;
  pBStack_1374 = pBVar17;
  pBStack_12b4 = unaff_s5;
  pBStack_12b0 = pBStack_13f4;
  pBStack_12ac = data;
  pBStack_12a8 = (BIO *)it;
  if (ppiStack_1404 == (int **)0x0) {
LAB_0060ebd4:
    pcStack_1478 = (char *)pBStack_1488;
    ppBStack_13b0 = (BIO **)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    pcStack_147c = (char *)pBVar17;
    if (ppBStack_13b0 != (BIO **)0x0) {
      pcVar23 = auStack_1354;
      pcStack_1478 = auStack_135c + 4;
      pcStack_147c = auStack_135c;
      pBStack_1360 = (BIO *)pBStack_1374->method;
      pBStack_1398 = pBStack_1488;
      uVar7 = (**(code **)(puStack_1388 + -0x6e30))(&pBStack_1360);
      ppBVar8 = ppBStack_13b0;
      if ((uVar7 & 0x80) == 0) goto LAB_0060ec1c;
      pBStack_1488 = (BIO *)0x66;
LAB_0060ec2c:
      pcVar29 = *(code **)(puStack_1388 + -0x6644);
      if ((ppiStack_1404 == (int **)0x0) || ((BIO **)*ppiStack_1404 != ppBStack_13b0)) {
LAB_0060eb80:
        (*pcVar29)(ppBStack_13b0);
        if (pBStack_1488 != (BIO *)0x0) goto LAB_0060ec50;
      }
      else if (pBStack_1488 != (BIO *)0x0) {
        pcVar29 = *(code **)(puStack_1388 + -0x6eac);
        goto LAB_0060ec58;
      }
    }
    ppBVar8 = (BIO **)0x0;
  }
  else {
    ppBStack_13b0 = (BIO **)*ppiStack_1404;
    pcVar23 = auStack_1354;
    if (ppBStack_13b0 == (BIO **)0x0) goto LAB_0060ebd4;
    pBStack_1360 = (BIO *)pBVar17->method;
    pcStack_1478 = auStack_135c + 4;
    pcStack_147c = auStack_135c;
    pBStack_1398 = pBStack_1488;
    uVar7 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&pBStack_1360);
    ppBVar8 = ppBStack_13b0;
    if ((uVar7 & 0x80) == 0) {
LAB_0060ec1c:
      ppBStack_13b0 = ppBVar8;
      if (pBVar24 != auStack_135c._4_4_) {
        pBStack_1488 = (BIO *)&DAT_000000a8;
        goto LAB_0060ec2c;
      }
      if ((uVar7 & 0x20) != 0) {
        auStack_1324._8_4_ = (BIO *)0x0;
        auStack_1324._36_4_ = pBStack_1374;
        auStack_1324._0_4_ = pBStack_1360;
        auStack_1324._24_4_ = auStack_135c._0_4_;
        auStack_1324._20_4_ = pBStack_1290;
        if (pBStack_1488 == (BIO *)0x0) {
          auStack_1324._28_4_ = (code *)0x0;
        }
        else {
          auStack_1324._28_4_ = (code *)((int)&pBStack_1488->method + (int)&pBStack_1360->method);
        }
        pBStack_13fc = (BIO *)0x0;
        ppBStack_1378 = (BIO **)0x0;
        p_Stack_133c = (_func_603 *)0x0;
        data = (BIO *)auStack_1324;
        pbStack_1334 = (bio_st *)0x0;
        pBStack_13f4 = (BIO *)auStack_1344;
        pBStack_1338 = (BIO *)0x0;
        pBStack_1400 = (BIO *)(auStack_134c + 4);
        pcStack_1364 = "a_bytes.c";
        uVar9 = uVar7 & 1;
        auStack_1324._12_4_ = uVar7;
        auStack_1324._16_4_ = pBVar24;
        do {
          if (uVar9 != 0) {
            pcStack_147c = (char *)(auStack_1324._28_4_ + -(int)auStack_1324._0_4_);
            auStack_1324._4_4_ = (bio_st *)(**(code **)(puStack_1388 + -0x69e0))(data);
            if (auStack_1324._4_4_ == (bio_st *)0x0) goto LAB_0060ed04;
LAB_0060eea4:
            pBStack_1488 = (BIO *)auStack_1324;
            iVar2 = (**(code **)(puStack_1388 + -0x69e4))(pBStack_1488);
            if (iVar2 != 0) {
              *ppBVar8 = pBStack_13fc;
              if (ppBVar8[2] != (BIO *)0x0) {
                (**(code **)(puStack_1388 + -0x7f58))();
              }
              ppBVar8[2] = pBStack_1338;
              pBVar6 = auStack_1324._0_4_;
              if (ppBStack_1378 != (BIO **)0x0) {
                (**(code **)(puStack_1388 + -0x6644))(ppBStack_1378);
                pBVar6 = auStack_1324._0_4_;
              }
              goto LAB_0060ee40;
            }
LAB_0060ed80:
            if (ppBStack_1378 == (BIO **)0x0) goto LAB_0060ed9c;
            goto LAB_0060ed88;
          }
          if ((int)auStack_1324._24_4_ < 1) goto LAB_0060eea4;
LAB_0060ed04:
          pBVar6 = auStack_1324._16_4_;
          pBStack_137c = auStack_1324._20_4_;
          auStack_1324._32_4_ = auStack_1324._0_4_;
          unaff_s5 = (BIO *)(auStack_1324._28_4_ + -(int)auStack_1324._0_4_);
          ppBVar11 = ppBStack_1378;
          if ((ppBStack_1378 == (BIO **)0x0) &&
             (ppBVar11 = (BIO **)(**(code **)(puStack_1388 + -0x6650))(), ppBVar11 == (BIO **)0x0))
          goto LAB_0060ed9c;
          pcStack_147c = auStack_1354 + 8;
          pBStack_1350 = auStack_1324._0_4_;
          pcStack_1478 = (char *)pBStack_1400;
          pcVar23 = (char *)pBStack_13f4;
          pBStack_1398 = unaff_s5;
          psVar10 = (stack_st_void *)(**(code **)(puStack_1388 + -0x6e30))(auStack_1354 + 4);
          if (((uint)psVar10 & 0x80) != 0) {
            auStack_1324._8_4_ = (BIO *)0x66;
LAB_0060ed64:
            if (ppBVar11 != ppBStack_1378) {
              (**(code **)(puStack_1388 + -0x6644))(ppBVar11);
            }
            goto LAB_0060ed80;
          }
          if (pBVar6 != auStack_134c._4_4_) {
            auStack_1324._8_4_ = (BIO *)&DAT_000000a8;
            goto LAB_0060ed64;
          }
          if (((uint)psVar10 & 0x20) == 0) {
            if (auStack_134c._0_4_ == (BIO *)0x0) {
              if (ppBVar11[2] == (BIO *)0x0) {
                unaff_s5 = (BIO *)0x0;
                auStack_1324._0_4_ = pBStack_1350;
              }
              else {
                unaff_s5 = (BIO *)0x0;
                (**(code **)(puStack_1388 + -0x7f58))();
                auStack_1324._0_4_ = pBStack_1350;
              }
            }
            else {
              if (((int)*ppBVar11 < (int)auStack_134c._0_4_) ||
                 (unaff_s5 = ppBVar11[2], unaff_s5 == (BIO *)0x0)) {
                pcStack_1478 = &DAT_000000e9;
                pcStack_147c = pcStack_1364;
                unaff_s5 = (BIO *)(**(code **)(puStack_1388 + -0x7dd8))
                                            ((code *)((int)&(auStack_134c._0_4_)->method + 1));
                if (unaff_s5 == (BIO *)0x0) {
                  auStack_1324._8_4_ = (BIO *)&DAT_00000041;
                  goto LAB_0060ed64;
                }
                if (ppBVar11[2] != (BIO *)0x0) {
                  (**(code **)(puStack_1388 + -0x7f58))();
                }
              }
              pcStack_1478 = (char *)auStack_134c._0_4_;
              (**(code **)(puStack_1388 + -0x52f4))(unaff_s5,pBStack_1350);
              *(code *)((int)&(auStack_134c._0_4_)->method + (int)&unaff_s5->method) = (code)0x0;
              auStack_1324._0_4_ =
                   (BIO *)((int)&(auStack_134c._0_4_)->method + (int)&pBStack_1350->method);
            }
            *ppBVar11 = auStack_134c._0_4_;
            ppBVar11[2] = unaff_s5;
            ppBVar11[1] = pBVar6;
            pBVar6 = auStack_134c._0_4_;
          }
          else {
            pBStack_12f0 = (BIO *)0x0;
            auStack_1324._44_4_ = pBStack_1350;
            pBStack_12e0 = auStack_134c._0_4_;
            pBStack_12e8 = pBVar6;
            pBStack_12e4 = pBStack_137c;
            if (unaff_s5 == (BIO *)0x0) {
              pcStack_12dc = (code *)0x0;
            }
            else {
              pcStack_12dc = (code *)((int)&unaff_s5->method + (int)&pBStack_1350->method);
            }
            pBStack_136c = (BIO *)(auStack_1324 + 0x2c);
            pBStack_137c = (BIO *)0x0;
            auStack_1344._4_4_ = (BIO **)0x0;
            unaff_s5 = (BIO *)(auStack_1344 + 4);
            ppBStack_1368 = &pBStack_12f0;
            pbStack_1330 = (bio_st *)0x0;
            uStack_1328 = 0;
            pBStack_132c = (BIO *)0x0;
            pcStack_147c = (char *)auStack_134c._0_4_;
            psStack_12ec = psVar10;
            pBStack_12d4 = data;
            if (((uint)psVar10 & 1) != 0) goto LAB_0060f054;
            while (pcVar29 = *(code **)(puStack_1388 + -0x69e4), 0 < (int)pBStack_12e0) {
              while( true ) {
                ppBStack_1390 = ppBStack_1368;
                pBStack_1398 = pBStack_12e4;
                pcStack_1478 = (char *)(pcStack_12dc + -(int)auStack_1324._44_4_);
                pBStack_12d8 = auStack_1324._44_4_;
                uStack_1394 = 2;
                pcStack_147c = (char *)pBStack_136c;
                pcVar23 = (char *)pBStack_12e8;
                iVar2 = int_d2i_ASN1_bytes(unaff_s5);
                if (iVar2 == 0) goto LAB_0060f1ac;
                pcStack_147c = (char *)((int)&(*auStack_1344._4_4_)->method +
                                       (int)&pBStack_137c->method);
                iVar2 = (**(code **)(puStack_1388 + -0x72a0))(&pbStack_1330);
                if (iVar2 == 0) {
                  pBStack_12f0 = (BIO *)&DAT_00000007;
                  goto LAB_0060f1ac;
                }
                pcStack_1478 = (char *)*auStack_1344._4_4_;
                pcStack_147c = (char *)auStack_1344._4_4_[2];
                (**(code **)(puStack_1388 + -0x52f4))
                          ((code *)((int)&pBStack_137c->method + (int)&pBStack_132c->method));
                if (((uint)psStack_12ec & 1) == 0) {
                  pcStack_147c = (char *)((int)auStack_1324._44_4_ - (int)pBStack_12d8);
                  pBStack_12e0 = (BIO *)((int)pBStack_12e0 - (int)pcStack_147c);
                }
                pBStack_137c = (BIO *)((int)&(*auStack_1344._4_4_)->method +
                                      (int)&pBStack_137c->method);
                if (((uint)psStack_12ec & 1) == 0) break;
LAB_0060f054:
                pcStack_147c = (char *)(pcStack_12dc + -(int)auStack_1324._44_4_);
                uStack_12f4 = (**(code **)(puStack_1388 + -0x69e0))(pBStack_136c);
                if (uStack_12f4 != 0) {
                  pcVar29 = *(code **)(puStack_1388 + -0x69e4);
                  goto LAB_0060f07c;
                }
              }
            }
LAB_0060f07c:
            iVar2 = (*pcVar29)(pBStack_136c);
            if (iVar2 == 0) {
LAB_0060f1ac:
              if (auStack_1344._4_4_ != (BIO **)0x0) {
                (**(code **)(puStack_1388 + -0x6644))();
              }
              if (pBStack_132c != (BIO *)0x0) {
                (**(code **)(puStack_1388 + -0x7f58))();
              }
              auStack_1324._8_4_ = pBStack_12f0;
              goto LAB_0060ed64;
            }
            *ppBVar11 = pBStack_137c;
            if (ppBVar11[2] != (BIO *)0x0) {
              (**(code **)(puStack_1388 + -0x7f58))();
            }
            ppBVar11[2] = pBStack_132c;
            if (auStack_1344._4_4_ != (BIO **)0x0) {
              (**(code **)(puStack_1388 + -0x6644))();
            }
            auStack_1324._0_4_ = auStack_1324._44_4_;
            pBVar6 = *ppBVar11;
          }
          pcStack_147c = (char *)((int)&pBVar6->method + (int)&pBStack_13fc->method);
          iVar2 = (**(code **)(puStack_1388 + -0x72a0))(&p_Stack_133c);
          if (iVar2 == 0) goto LAB_0060f214;
          pcStack_1478 = (char *)*ppBVar11;
          pcStack_147c = (char *)ppBVar11[2];
          (**(code **)(puStack_1388 + -0x52f4))
                    ((code *)((int)&pBStack_13fc->method + (int)&pBStack_1338->method));
          uVar9 = auStack_1324._12_4_ & 1;
          if (uVar9 == 0) {
            pcStack_147c = (char *)((int)auStack_1324._0_4_ - (int)auStack_1324._32_4_);
            auStack_1324._24_4_ = (BIO *)((int)auStack_1324._24_4_ - (int)pcStack_147c);
          }
          pBStack_13fc = (BIO *)((int)&(*ppBVar11)->method + (int)&pBStack_13fc->method);
          ppBStack_1378 = ppBVar11;
        } while( true );
      }
      if (auStack_135c._0_4_ == (BIO *)0x0) {
        if (ppBVar8[2] == (BIO *)0x0) {
          pBStack_1488 = (BIO *)0x0;
          pBVar6 = pBStack_1360;
        }
        else {
          pBStack_1488 = (BIO *)0x0;
          (**(code **)(puStack_1388 + -0x7f58))();
          pBVar6 = pBStack_1360;
        }
      }
      else {
        if ((int)*ppBVar8 < (int)auStack_135c._0_4_) {
          pcVar29 = *(code **)(puStack_1388 + -0x7dd8);
LAB_0060f228:
          pcStack_1478 = &DAT_000000e9;
          pcStack_147c = "a_bytes.c";
          pBStack_1488 = (BIO *)(*pcVar29)((code *)((int)&(auStack_135c._0_4_)->method + 1));
          if (pBStack_1488 == (BIO *)0x0) {
            pBStack_1488 = (BIO *)&DAT_00000041;
            goto LAB_0060ec2c;
          }
          if (ppBVar8[2] != (BIO *)0x0) {
            (**(code **)(puStack_1388 + -0x7f58))();
          }
        }
        else {
          pBStack_1488 = ppBVar8[2];
          pcVar29 = *(code **)(puStack_1388 + -0x7dd8);
          if (pBStack_1488 == (BIO *)0x0) goto LAB_0060f228;
        }
        pcStack_147c = (char *)pBStack_1360;
        pcStack_1478 = (char *)auStack_135c._0_4_;
        (**(code **)(puStack_1388 + -0x52f4))(pBStack_1488);
        *(code *)((int)&(auStack_135c._0_4_)->method + (int)&pBStack_1488->method) = (code)0x0;
        pBVar6 = (BIO *)((int)&(auStack_135c._0_4_)->method + (int)&pBStack_1360->method);
      }
      *ppBVar8 = auStack_135c._0_4_;
      ppBVar8[2] = pBStack_1488;
      ppBVar8[1] = pBVar24;
LAB_0060ee40:
      if (ppiStack_1404 != (int **)0x0) {
        *ppiStack_1404 = (int *)ppBVar8;
      }
      pBStack_1374->method = (BIO_METHOD *)pBVar6;
    }
    else {
      pBStack_1488 = (BIO *)0x66;
      if (ppBStack_13b0 != (BIO **)*ppiStack_1404) {
        pcVar29 = *(code **)(puStack_1388 + -0x6644);
        goto LAB_0060eb80;
      }
LAB_0060ec50:
      pcVar29 = *(code **)(puStack_1388 + -0x6eac);
LAB_0060ec58:
      pcStack_147c = (char *)0x8f;
      pcVar23 = "a_bytes.c";
      pBStack_1398 = (BIO *)0xaf;
      pcStack_1478 = (char *)pBStack_1488;
      (*pcVar29)(0xd);
      ppBVar8 = (BIO **)0x0;
    }
  }
  if (puStack_12cc == *ppuStack_1370) {
    return (int)ppBVar8;
  }
  uStack_13ac = 0x60f2d8;
  puStack_13b8 = puStack_12cc;
  (**(code **)(puStack_1388 + -0x5330))();
  pBStack_1440 = (BIO_METHOD *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_1480 = &puStack_13b8;
  psStack_13b4 = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  psVar12 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_1480,(long)pcStack_147c,
                         pcStack_1478,(free_func *)pcVar23,0x10,0);
  if (psVar12 == (stack_st_OPENSSL_BLOCK *)0x0) {
    pcStack_147c = &DAT_0000006e;
    pcStack_1478 = "asn_pack.c";
    ppuStack_1480 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (psStack_13b4 == *(stack_st_OPENSSL_BLOCK **)pBStack_1440) {
    return (int)psVar12;
  }
  pcStack_13ec = ASN1_seq_pack;
  psVar12 = psStack_13b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1484 = PTR___stack_chk_guard_006a9ae8;
  puStack_140c = (undefined *)pBStack_1440;
  puStack_1414 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pBStack_1408 = pBStack_1488;
  pBStack_13f8 = unaff_s5;
  pBStack_13f0 = data;
  pBVar6 = (BIO *)i2d_ASN1_SET(psVar12,(uchar **)0x0,(undefined1 *)ppuStack_1480,0x10,0,0);
  if (pBVar6 == (BIO *)0x0) {
    pp = (BIO_METHOD **)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    pBVar13 = (BIO_METHOD *)0x0;
  }
  else {
    pBStack_1440 = (BIO_METHOD *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pBVar6,"asn_pack.c",0x62);
    pBStack_1488 = pBVar6;
    if (pBStack_1440 == (BIO_METHOD *)0x0) {
      pp = (BIO_METHOD **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
      pBVar13 = (BIO_METHOD *)0x0;
    }
    else {
      pp = &pBStack_1418;
      pBStack_1418 = pBStack_1440;
      i2d_ASN1_SET(psVar12,(uchar **)pp,(undefined1 *)ppuStack_1480,0x10,0,0);
      if ((BIO *)pcStack_1478 != (BIO *)0x0) {
        *(BIO_METHOD **)pcStack_1478 = (BIO_METHOD *)pBVar6;
      }
      pBVar13 = pBStack_1440;
      if ((BIO *)pcStack_147c != (BIO *)0x0) {
        *(BIO_METHOD **)pcStack_147c = pBStack_1440;
      }
    }
  }
  if (puStack_1414 == *(undefined4 **)puStack_1484) {
    return (int)pBVar13;
  }
  pcStack_143c = ASN1_unpack_string;
  puVar4 = puStack_1414;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_148c = PTR___stack_chk_guard_006a9ae8;
  uStack_1448 = puVar4[2];
  ppiVar20 = (int **)*puVar4;
  puVar4 = &uStack_1448;
  puStack_1458 = &_gp;
  iStack_1444 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)pp)(0);
  if (iVar2 == 0) {
    ppiVar20 = (int **)&DAT_0000006e;
    uStack_1460 = 0x79;
    puVar4 = (undefined4 *)&DAT_00000088;
    iStack_144c = iVar2;
    (**(code **)(puStack_1458 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    iVar2 = iStack_144c;
  }
  if (iStack_1444 == *(int *)puStack_148c) {
    return iVar2;
  }
  pcStack_1474 = ASN1_pack_string;
  iVar2 = iStack_1444;
  (**(code **)(puStack_1458 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_1494 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (ppiVar20 == (int **)0x0) {
    piVar26 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar26 != (int *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppiVar21 = (int **)&DAT_00000041;
    piVar18 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    piVar14 = (int *)0x0;
  }
  else {
    piVar26 = *ppiVar20;
    if (piVar26 == (int *)0x0) {
      piVar26 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar26 == (int *)0x0) goto LAB_0060f754;
      *ppiVar20 = piVar26;
    }
LAB_0060f614:
    iVar3 = (*(code *)puVar4)(iVar2,0);
    *piVar26 = iVar3;
    if (iVar3 == 0) {
      ppiVar21 = (int **)&DAT_00000070;
      piVar18 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppiVar21 = (int **)&DAT_00000092;
      iStack_1498 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"asn_pack.c");
      if (iStack_1498 != 0) {
        piVar18 = &iStack_1498;
        piVar26[2] = iStack_1498;
        (*(code *)puVar4)(iVar2,piVar18);
        piVar14 = piVar26;
        goto LAB_0060f670;
      }
      ppiVar21 = (int **)&DAT_00000041;
      piVar18 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppiVar20 == (int **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar26);
      piVar14 = (int *)0x0;
    }
    else {
      piVar14 = *ppiVar20;
      if (piVar14 == (int *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar26);
        *ppiVar20 = (int *)0x0;
      }
      else {
        piVar14 = (int *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_1494 == *(int *)puVar1) {
    return (int)piVar14;
  }
  iVar2 = iStack_1494;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppiVar21 == (int **)0x0) {
    piVar26 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar26 == (int *)0x0) {
LAB_0060f874:
      uVar22 = 0x41;
      uVar5 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    piVar26 = *ppiVar21;
    if (piVar26 == (int *)0x0) {
      piVar26 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar26 == (int *)0x0) goto LAB_0060f874;
      *ppiVar21 = piVar26;
    }
  }
  if (piVar26[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    piVar26[2] = 0;
  }
  iVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar2,piVar26 + 2,piVar18);
  *piVar26 = iVar2;
  if (iVar2 == 0) {
    uVar22 = 0x70;
    uVar5 = 0xba;
  }
  else {
    if (piVar26[2] != 0) {
      return (int)piVar26;
    }
    uVar22 = 0x41;
    uVar5 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar22,"asn_pack.c",uVar5);
  return 0;
LAB_0060d8a8:
  unaff_s2 = (char *)local_7c;
  local_98 = pAStack_bc;
  (**(code **)(local_90 + -0x7fa8))(bio,"\"; boundary=\"----%s\"%s%s",local_7c,pAStack_bc);
  (**(code **)(local_90 + -0x7fa8))
            (bio,"This is an S/MIME signed message%s%s",pAStack_bc,pAStack_bc);
  (**(code **)(local_90 + -0x7fa8))(bio,"------%s%s",unaff_s2,pAStack_bc);
  local_60 = local_80;
  if ((flags & 0x8040U) == 0x40) {
    unaff_s5 = (BIO *)it->funcs;
    if (unaff_s5 == (BIO *)0x0) {
LAB_0060dd00:
      pcVar23 = "asn_mime.c";
      local_98 = (ASN1_ITEM *)0x17e;
      pcStack_1110 = (char *)0xd6;
      (**(code **)(local_90 + -0x6eac))(0xd,0xd6,0xca);
    }
    else {
      unaff_s2 = (char *)&local_5c;
      if ((_func_597 *)unaff_s5->shutdown == (_func_597 *)0x0) goto LAB_0060dd00;
      mdalgs = (stack_st_X509_ALGOR *)&local_60;
      local_58 = (BIO *)0x0;
      local_54 = (char *)0x0;
      pcStack_1110 = (char *)mdalgs;
      pcVar23 = unaff_s2;
      local_5c = bio;
      iVar2 = (*(_func_597 *)unaff_s5->shutdown)((BIO *)0xc,(char *)mdalgs);
      if (0 < iVar2) {
        SMIME_crlf_copy(data,local_58,flags);
        pcStack_1110 = (char *)mdalgs;
        iVar2 = (*(_func_597 *)unaff_s5->shutdown)((BIO *)0xd,(char *)mdalgs);
        pcVar23 = unaff_s2;
        unaff_s2 = (char *)local_7c;
        while (local_7c = (BIO *)unaff_s2, bio != local_58) {
          mdalgs = (stack_st_X509_ALGOR *)(**(code **)(local_90 + -0x7418))(local_58);
          (**(code **)(local_90 + -0x7f70))(local_58);
          unaff_s2 = (char *)local_7c;
          local_58 = (BIO *)mdalgs;
        }
        if (0 < iVar2) goto LAB_0060db88;
      }
    }
LAB_0060d7e4:
    iVar2 = 0;
  }
  else {
    SMIME_crlf_copy(data,bio,flags);
LAB_0060db88:
    unaff_s2 = (char *)local_7c;
    local_98 = pAStack_bc;
    (**(code **)(local_90 + -0x7fa8))(bio,"%s------%s%s",pAStack_bc,local_7c);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Type: %ssignature;",local_84);
    (**(code **)(local_90 + -0x7fa8))(bio," name=\"smime.p7s\"%s",pAStack_bc);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Transfer-Encoding: base64%s",pAStack_bc);
    (**(code **)(local_90 + -0x7fa8))(bio,"Content-Disposition: attachment;");
    (**(code **)(local_90 + -0x7fa8))(bio," filename=\"smime.p7s\"%s%s",pAStack_bc,pAStack_bc);
    local_98 = it;
    B64_write_ASN1(bio,local_80,0,0);
    pcStack_1110 = "%s------%s--%s%s";
    pcVar23 = unaff_s2;
    local_98 = pAStack_bc;
    local_94 = pAStack_bc;
    (**(code **)(local_90 + -0x7fa8))(bio,"%s------%s--%s%s",pAStack_bc);
    iVar2 = 1;
  }
  goto LAB_0060d7e8;
LAB_0060e67c:
  pbStack_116c = (bio_st *)&DAT_00000007;
  pBStack_11d4 = pBVar19;
LAB_0060e1b8:
  (**(code **)(puStack_11e0 + -0x6644))(pBStack_11d4);
LAB_0060e1cc:
  if (pbStack_1188 != (bio_st *)0x0) {
    (**(code **)(puStack_11e0 + -0x7f58))();
  }
  *ppbStack_11c4 = pbStack_116c;
  flags = (int)auStack_11ac._4_4_;
  goto LAB_0060e014;
LAB_0060f214:
  auStack_1324._8_4_ = (BIO *)&DAT_00000007;
  ppBStack_1378 = ppBVar11;
LAB_0060ed88:
  (**(code **)(puStack_1388 + -0x6644))(ppBStack_1378);
LAB_0060ed9c:
  pBStack_1488 = auStack_1324._8_4_;
  if (pBStack_1338 != (BIO *)0x0) {
    (**(code **)(puStack_1388 + -0x7f58))();
    pBStack_1488 = auStack_1324._8_4_;
  }
  goto LAB_0060ec2c;
}

