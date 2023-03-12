
/* WARNING: Removing unreachable block (ram,0x00526b50) */
/* WARNING: Removing unreachable block (ram,0x005266b4) */
/* WARNING: Removing unreachable block (ram,0x00526300) */
/* WARNING: Removing unreachable block (ram,0x00526308) */
/* WARNING: Removing unreachable block (ram,0x0052630c) */
/* WARNING: Removing unreachable block (ram,0x0052632c) */
/* WARNING: Removing unreachable block (ram,0x00526330) */
/* WARNING: Removing unreachable block (ram,0x00526340) */
/* WARNING: Removing unreachable block (ram,0x00526344) */
/* WARNING: Removing unreachable block (ram,0x00526354) */
/* WARNING: Removing unreachable block (ram,0x00526358) */
/* WARNING: Removing unreachable block (ram,0x00526fe4) */
/* WARNING: Removing unreachable block (ram,0x0052668c) */

int BIO_dump(BIO *b,char *bytes,int len)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  byte *pbVar5;
  byte ***pppbVar6;
  code *pcVar7;
  cb *cb;
  byte ***pppbVar8;
  uint uVar9;
  byte ***len_00;
  byte ***pppbVar10;
  byte ***pppbVar11;
  int iVar12;
  int iVar13;
  byte ***pppbVar14;
  byte ***pppbVar15;
  byte ***unaff_s2;
  byte *unaff_s4;
  undefined4 unaff_s5;
  byte ***unaff_s6;
  byte ***unaff_s7;
  char *unaff_s8;
  byte ***pppbStack_6b4;
  int iStack_6ac;
  int iStack_6a8;
  byte ***pppbStack_680;
  char acStack_678 [20];
  byte **appbStack_664 [33];
  char acStack_5e0 [292];
  cb *pcStack_4bc;
  byte ***pppbStack_4b8;
  byte ***pppbStack_4b4;
  byte ***pppbStack_4b0;
  int iStack_4ac;
  byte *pbStack_4a8;
  undefined4 uStack_4a4;
  byte ***pppbStack_4a0;
  byte ***pppbStack_49c;
  char *pcStack_498;
  code *pcStack_494;
  byte ***pppbStack_484;
  byte ***pppbStack_480;
  undefined *puStack_478;
  char *pcStack_46c;
  byte ***pppbStack_468;
  char *pcStack_464;
  int iStack_460;
  byte ***pppbStack_45c;
  byte ***pppbStack_458;
  byte ***pppbStack_454;
  char *pcStack_450;
  byte ***pppbStack_44c;
  int iStack_448;
  char *pcStack_444;
  byte ***pppbStack_440;
  char *pcStack_43c;
  byte ***pppbStack_438;
  code **ppcStack_434;
  char acStack_430 [20];
  byte **appbStack_41c [33];
  byte **appbStack_398 [73];
  code *pcStack_274;
  byte ***pppbStack_270;
  byte *pbStack_26c;
  byte ***pppbStack_268;
  undefined4 uStack_264;
  byte *pbStack_260;
  undefined4 uStack_25c;
  byte ***pppbStack_258;
  byte ***pppbStack_254;
  char *pcStack_250;
  code *pcStack_24c;
  byte ***pppbStack_240;
  byte *pbStack_238;
  undefined *puStack_230;
  char *pcStack_224;
  byte ***pppbStack_220;
  char *pcStack_21c;
  int iStack_218;
  byte ***pppbStack_214;
  char *pcStack_210;
  BIO *pBStack_20c;
  char *pcStack_208;
  byte ***pppbStack_204;
  int iStack_200;
  char *pcStack_1fc;
  byte ***pppbStack_1f8;
  char *pcStack_1f4;
  byte ***pppbStack_1f0;
  byte **ppbStack_1ec;
  char acStack_1e8 [20];
  undefined uStack_1d4;
  byte **appbStack_150 [73];
  byte ***pppbStack_2c;
  
  pppbVar10 = (byte ***)0x0;
  ppbStack_1ec = (byte **)PTR___stack_chk_guard_006a9ae8;
  puStack_230 = &_gp;
  pppbStack_2c = *(byte ****)PTR___stack_chk_guard_006a9ae8;
  pcVar4 = bytes + len;
  iVar2 = len;
  if (len < 1) {
    pppbStack_1f0 = (byte ***)0x0;
    pppbStack_458 = (byte ***)bytes;
  }
  else {
    pppbStack_458 = (byte ***)0x0;
    do {
      iVar13 = iVar2 + -1;
      pppbStack_1f0 = pppbStack_458;
      if ((pcVar4[-1] & 0xdfU) != 0) break;
      pppbStack_458 = (byte ***)((int)pppbStack_458 + 1);
      pcVar4 = pcVar4 + -1;
      iVar2 = iVar13;
      pppbStack_1f0 = pppbStack_458;
    } while (iVar13 != 0);
  }
  pppbStack_270 = (byte ***)&stack0xffffffd8;
  uStack_1d4 = 0;
  pppbStack_204 = (byte ***)(iVar2 / 0x10 + (uint)((iVar2 / 0x10) * 0x10 < iVar2));
  pcStack_210 = bytes;
  pBStack_20c = b;
  if ((int)pppbStack_204 < 1) {
    iStack_218 = 0;
  }
  else {
    iStack_218 = 0;
    unaff_s6 = (byte ***)&uStack_1d4;
    pppbStack_214 = (byte ***)0x0;
    unaff_s2 = (byte ***)0x0;
    iStack_200 = 0x660000;
    unaff_s7 = appbStack_150;
    unaff_s8 = acStack_1e8;
    pcStack_1fc = "-check_ss_sig";
    pcStack_208 = "-check_ss_sig";
    pcStack_224 = "%02x%c";
    pcStack_21c = "   ";
    pcStack_1f4 = "encrypt";
    pppbStack_220 = (byte ***)bytes;
    pppbStack_1f8 = unaff_s6;
    do {
      BUF_strlcpy((char *)unaff_s7,(char *)pppbStack_1f8,0x121);
      pppbVar10 = unaff_s2;
      BIO_snprintf(unaff_s8,0x14,(char *)(iStack_200 + 0x7810));
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      iVar13 = 0;
      pppbVar8 = pppbStack_220;
      do {
        while (pppbVar11 = pppbVar8, iVar2 <= (int)((int)unaff_s2 + iVar13)) {
          iVar13 = iVar13 + 1;
          BUF_strlcat((char *)unaff_s7,pcStack_21c,0x121);
          pppbVar8 = (byte ***)((int)pppbVar11 + 1);
          if (iVar13 == 0x10) goto LAB_005264bc;
        }
        pppbVar10 = (byte ***)(uint)*(byte *)pppbVar11;
        pbStack_238 = &DAT_0000002d;
        if (iVar13 != 7) {
          pbStack_238 = &DAT_00000020;
        }
        iVar13 = iVar13 + 1;
        BIO_snprintf(unaff_s8,0x14,pcStack_224);
        BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
        pppbVar8 = (byte ***)((int)pppbVar11 + 1);
      } while (iVar13 != 0x10);
LAB_005264bc:
      unaff_s4 = (byte *)((int)pppbVar11 + 1);
      BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x4da8,0x121);
      if ((int)unaff_s2 < iVar2) {
        unaff_s5 = 0x2e;
        unaff_s6 = (byte ***)(pcStack_210 + iVar2);
        pppbVar11 = (byte ***)(pcStack_210 + (int)((int)unaff_s2 + 0xf));
        unaff_s4 = (byte *)(pcStack_1f4 + -0x6680);
        pppbVar8 = pppbStack_220;
        do {
          pppbVar10 = (byte ***)(uint)*(byte *)pppbVar8;
          if ((byte ***)0x5e < pppbVar10 + -8) {
            pppbVar10 = (byte ***)0x2e;
          }
          BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4);
          BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
        } while ((pppbVar8 != pppbVar11) &&
                (pppbVar8 = (byte ***)((int)pppbVar8 + 1), unaff_s6 != pppbVar8));
      }
      unaff_s2 = unaff_s2 + 4;
      BUF_strlcat((char *)unaff_s7,pcStack_1fc + -0x4d1c,0x121);
      pppbStack_270 = (byte ***)((int)pppbStack_214 + 1);
      pppbStack_220 = pppbStack_220 + 4;
      pppbStack_214 = pppbStack_270;
      len = (**(code **)(puStack_230 + -0x53bc))(unaff_s7);
      pppbStack_458 = unaff_s7;
      iVar13 = BIO_write(pBStack_20c,unaff_s7,len);
      iStack_218 = iStack_218 + iVar13;
    } while (pppbStack_270 != pppbStack_204);
  }
  uStack_264 = 0x10;
  pbStack_26c = (byte *)((int)pppbStack_1f0 + iVar2);
  if (pppbStack_1f0 != (byte ***)0x0) {
    pppbStack_270 = appbStack_150;
    pppbVar10 = (byte ***)&uStack_1d4;
    pbStack_238 = pbStack_26c;
    BIO_snprintf((char *)pppbStack_270,0x121,"%s%04x - <SPACES/NULS>\n");
    len = (**(code **)(puStack_230 + -0x53bc))(pppbStack_270);
    pppbStack_458 = pppbStack_270;
    iVar2 = BIO_write(pBStack_20c,pppbStack_270,len);
    iStack_218 = iStack_218 + iVar2;
  }
  if (pppbStack_2c == (byte ***)*ppbStack_1ec) {
    return iStack_218;
  }
  pcStack_24c = BIO_dump_indent_cb_constprop_0;
  pppbStack_454 = pppbStack_2c;
  (**(code **)(puStack_230 + -0x5330))();
  ppcStack_434 = (code **)PTR___stack_chk_guard_006a9ae8;
  puStack_478 = &_gp;
  pcStack_274 = *(code **)PTR___stack_chk_guard_006a9ae8;
  pbVar5 = (byte *)((int)pppbStack_458 + len);
  pppbStack_4b4 = (byte ***)len;
  if (len < 1) {
    pppbStack_438 = (byte ***)0x0;
    pppbVar8 = pppbStack_458;
  }
  else {
    pppbVar8 = (byte ***)0x0;
    do {
      pppbVar11 = (byte ***)((int)pppbStack_4b4 + -1);
      pppbStack_438 = pppbVar8;
      if ((pbVar5[-1] & 0xdf) != 0) break;
      pppbVar8 = (byte ***)((int)pppbVar8 + 1);
      pbVar5 = pbVar5 + -1;
      pppbStack_4b4 = pppbVar11;
      pppbStack_438 = pppbVar8;
    } while (pppbVar11 != (byte ***)0x0);
  }
  pppbStack_268 = unaff_s2;
  pbStack_260 = unaff_s4;
  uStack_25c = unaff_s5;
  pppbStack_258 = unaff_s6;
  pppbStack_254 = unaff_s7;
  pcStack_250 = unaff_s8;
  if ((int)pppbVar10 < 1) {
    iStack_4ac = 0x10;
    pppbStack_4b8 = (byte ***)&pppbStack_270;
    appbStack_41c[0]._0_1_ = 0;
    pppbStack_44c =
         (byte ***)
         ((int)pppbStack_4b4 / 0x10 +
         (uint)(((int)pppbStack_4b4 / 0x10) * 0x10 < (int)pppbStack_4b4));
  }
  else {
    pppbVar11 = (byte ***)&DAT_00000080;
    if ((int)pppbVar10 < 0x81) {
      pppbVar11 = pppbVar10;
    }
    pppbVar10 = (byte ***)0x81;
    pppbVar8 = (byte ***)&DAT_00000020;
    len = (int)pppbVar11;
    (*(code *)PTR___memset_chk_006a998c)(appbStack_41c);
    pppbVar14 = (byte ***)&DAT_00000006;
    if ((int)pppbVar11 < 7) {
      pppbVar14 = pppbVar11;
    }
    pbVar5 = (byte *)((int)pppbVar11 + (3 - (int)pppbVar14));
    if ((int)pbVar5 < 0) {
      pbVar5 = (byte *)((int)pppbVar11 + (6 - (int)pppbVar14));
    }
    iStack_4ac = 0x10 - ((int)pbVar5 >> 2);
    if (iStack_4ac == 0) {
      trap(7);
    }
    pppbStack_4b8 = (byte ***)((int)&pppbStack_270 + (int)pppbVar11);
    *(byte *)((int)appbStack_41c + (int)pppbVar11) = 0;
    pppbStack_44c =
         (byte ***)
         ((int)pppbStack_4b4 / iStack_4ac +
         (uint)(((int)pppbStack_4b4 / iStack_4ac) * iStack_4ac < (int)pppbStack_4b4));
  }
  if ((int)pppbStack_44c < 1) {
    iStack_460 = 0;
  }
  else {
    iStack_460 = 0;
    unaff_s6 = appbStack_41c;
    pppbStack_45c = (byte ***)0x0;
    unaff_s2 = (byte ***)0x0;
    iStack_448 = 0x660000;
    unaff_s7 = appbStack_398;
    unaff_s8 = acStack_430;
    pcStack_444 = "-check_ss_sig";
    pcStack_450 = "-check_ss_sig";
    pcStack_46c = "%02x%c";
    pcStack_464 = "   ";
    pcStack_43c = "encrypt";
    pppbStack_468 = pppbStack_458;
    pppbStack_440 = unaff_s6;
    do {
      BUF_strlcpy((char *)unaff_s7,(char *)pppbStack_440,0x121);
      BIO_snprintf(unaff_s8,0x14,(char *)(iStack_448 + 0x7810),unaff_s2);
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      if (iStack_4ac < 1) {
        BUF_strlcat((char *)unaff_s7,pcStack_450 + -0x4da8,0x121);
      }
      else {
        iVar2 = 0;
        pppbVar10 = pppbStack_468;
        do {
          while (pppbVar8 = pppbVar10, (int)pppbStack_4b4 <= (int)((int)unaff_s2 + iVar2)) {
            iVar2 = iVar2 + 1;
            BUF_strlcat((char *)unaff_s7,pcStack_464,0x121);
            pppbVar10 = (byte ***)((int)pppbVar8 + 1);
            if (iVar2 == iStack_4ac) goto LAB_00526950;
          }
          pppbStack_480 = (byte ***)&DAT_0000002d;
          if (iVar2 != 7) {
            pppbStack_480 = (byte ***)&DAT_00000020;
          }
          iVar2 = iVar2 + 1;
          BIO_snprintf(unaff_s8,0x14,pcStack_46c,(uint)*(byte *)pppbVar8);
          BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
          pppbVar10 = (byte ***)((int)pppbVar8 + 1);
        } while (iVar2 != iStack_4ac);
LAB_00526950:
        unaff_s4 = (byte *)((int)pppbVar8 + 1);
        BUF_strlcat((char *)unaff_s7,pcStack_450 + -0x4da8,0x121);
        if ((int)unaff_s2 < (int)pppbStack_4b4) {
          unaff_s5 = 0x2e;
          unaff_s6 = (byte ***)((int)pppbStack_458 + (int)pppbStack_4b4);
          pppbVar8 = (byte ***)((int)pppbStack_458 + (int)((int)unaff_s2 + iStack_4ac + -1));
          unaff_s4 = (byte *)(pcStack_43c + -0x6680);
          pppbVar10 = pppbStack_468;
          pppbStack_240 = pppbStack_4b4;
          do {
            uVar9 = (uint)*(byte *)pppbVar10;
            if (0x5e < uVar9 - 0x20) {
              uVar9 = 0x2e;
            }
            BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4,uVar9);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            pppbStack_4b4 = pppbStack_240;
          } while ((pppbVar10 != pppbVar8) &&
                  (pppbVar10 = (byte ***)((int)pppbVar10 + 1), unaff_s6 != pppbVar10));
        }
      }
      unaff_s2 = (byte ***)((int)unaff_s2 + iStack_4ac);
      BUF_strlcat((char *)unaff_s7,pcStack_444 + -0x4d1c,0x121);
      pppbStack_4b8 = (byte ***)((int)pppbStack_45c + 1);
      pppbStack_468 = (byte ***)((int)pppbStack_468 + iStack_4ac);
      pppbStack_45c = pppbStack_4b8;
      pppbVar8 = (byte ***)(**(code **)(puStack_478 + -0x53bc))(unaff_s7);
      len = 1;
      pppbVar10 = pppbStack_454;
      iVar2 = (**(code **)(puStack_478 + -0x536c))(unaff_s7);
      iStack_460 = iStack_460 + iVar2;
    } while (pppbStack_4b8 != pppbStack_44c);
  }
  pppbStack_4b4 = (byte ***)((int)pppbStack_438 + (int)pppbStack_4b4);
  if (pppbStack_438 != (byte ***)0x0) {
    pppbStack_4b8 = appbStack_398;
    pppbStack_480 = pppbStack_4b4;
    BIO_snprintf((char *)pppbStack_4b8,0x121,"%s%04x - <SPACES/NULS>\n",appbStack_41c);
    pppbVar8 = (byte ***)(**(code **)(puStack_478 + -0x53bc))(pppbStack_4b8);
    len = 1;
    pppbVar10 = pppbStack_454;
    iVar2 = (**(code **)(puStack_478 + -0x536c))(pppbStack_4b8);
    iStack_460 = iStack_460 + iVar2;
  }
  if (pcStack_274 == *ppcStack_434) {
    return iStack_460;
  }
  pcStack_494 = BIO_dump_indent_cb;
  pcVar7 = pcStack_274;
  (**(code **)(puStack_478 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcStack_4bc = *(cb **)PTR___stack_chk_guard_006a9ae8;
  pbVar5 = (byte *)(len + (int)pppbVar10);
  if ((int)pppbVar10 < 1) {
    pppbStack_680 = (byte ***)0x0;
    pppbVar11 = pppbVar8;
  }
  else {
    pppbVar11 = (byte ***)0x0;
    do {
      pppbVar14 = (byte ***)((int)pppbVar10 + -1);
      pppbStack_680 = pppbVar11;
      if ((pbVar5[-1] & 0xdf) != 0) break;
      pppbVar11 = (byte ***)((int)pppbVar11 + 1);
      pbVar5 = pbVar5 + -1;
      pppbVar10 = pppbVar14;
      pppbStack_680 = pppbVar11;
    } while (pppbVar14 != (byte ***)0x0);
  }
  pppbStack_4b0 = unaff_s2;
  pbStack_4a8 = unaff_s4;
  uStack_4a4 = unaff_s5;
  pppbStack_4a0 = unaff_s6;
  pppbStack_49c = unaff_s7;
  pcStack_498 = unaff_s8;
  if ((int)pppbStack_480 < 1) {
    iVar2 = 0x10;
    appbStack_664[0]._0_1_ = 0;
    iVar13 = (int)pppbVar10 / 0x10 + (uint)(((int)pppbVar10 / 0x10) * 0x10 < (int)pppbVar10);
    pppbVar14 = (byte ***)len;
    len_00 = pppbStack_480;
  }
  else {
    pppbVar15 = (byte ***)&DAT_00000080;
    if ((int)pppbStack_480 < 0x81) {
      pppbVar15 = pppbStack_480;
    }
    len_00 = (byte ***)0x81;
    pppbVar11 = (byte ***)&DAT_00000020;
    pppbVar14 = pppbVar15;
    (*(code *)PTR___memset_chk_006a998c)(appbStack_664);
    pppbVar6 = (byte ***)&DAT_00000006;
    if ((int)pppbVar15 < 7) {
      pppbVar6 = pppbVar15;
    }
    pbVar5 = (byte *)((int)pppbVar15 + (3 - (int)pppbVar6));
    if ((int)pbVar5 < 0) {
      pbVar5 = (byte *)((int)pppbVar15 + (6 - (int)pppbVar6));
    }
    iVar2 = 0x10 - ((int)pbVar5 >> 2);
    if (iVar2 == 0) {
      trap(7);
    }
    *(byte *)((int)appbStack_664 + (int)pppbVar15) = 0;
    iVar13 = (int)pppbVar10 / iVar2 + (uint)(((int)pppbVar10 / iVar2) * iVar2 < (int)pppbVar10);
  }
  if (iVar13 < 1) {
    iStack_6ac = 0;
  }
  else {
    iStack_6a8 = 0;
    iStack_6ac = 0;
    pppbVar15 = (byte ***)0x0;
    pppbStack_6b4 = (byte ***)len;
    do {
      BUF_strlcpy(acStack_5e0,(char *)appbStack_664,0x121);
      len_00 = pppbVar15;
      BIO_snprintf(acStack_678,0x14,"%04x - ");
      BUF_strlcat(acStack_5e0,acStack_678,0x121);
      if (iVar2 < 1) {
        BUF_strlcat(acStack_5e0,"  ",0x121);
      }
      else {
        iVar12 = 0;
        pppbVar11 = pppbStack_6b4;
        do {
          while ((int)pppbVar10 <= (int)((int)pppbVar15 + iVar12)) {
            iVar12 = iVar12 + 1;
            pppbVar11 = (byte ***)((int)pppbVar11 + 1);
            BUF_strlcat(acStack_5e0,"   ",0x121);
            if (iVar12 == iVar2) goto LAB_00526df4;
          }
          len_00 = (byte ***)(uint)*(byte *)pppbVar11;
          uVar3 = 0x2d;
          if (iVar12 != 7) {
            uVar3 = 0x20;
          }
          iVar12 = iVar12 + 1;
          pppbVar11 = (byte ***)((int)pppbVar11 + 1);
          BIO_snprintf(acStack_678,0x14,"%02x%c",len_00,uVar3);
          BUF_strlcat(acStack_5e0,acStack_678,0x121);
        } while (iVar12 != iVar2);
LAB_00526df4:
        BUF_strlcat(acStack_5e0,"  ",0x121);
        if ((int)pppbVar15 < (int)pppbVar10) {
          pppbVar14 = (byte ***)(len + (int)pppbVar10);
          pppbVar11 = pppbStack_6b4;
          pppbStack_484 = pppbVar10;
          do {
            len_00 = (byte ***)(uint)*(byte *)pppbVar11;
            if ((byte ***)0x5e < len_00 + -8) {
              len_00 = (byte ***)0x2e;
            }
            BIO_snprintf(acStack_678,0x14,"%c");
            BUF_strlcat(acStack_5e0,acStack_678,0x121);
            pppbVar10 = pppbStack_484;
          } while ((pppbVar11 != (byte ***)(len + (int)((int)pppbVar15 + iVar2 + -1))) &&
                  (pppbVar11 = (byte ***)((int)pppbVar11 + 1), pppbVar14 != pppbVar11));
        }
      }
      pppbVar15 = (byte ***)((int)pppbVar15 + iVar2);
      BUF_strlcat(acStack_5e0,"\n",0x121);
      iStack_6a8 = iStack_6a8 + 1;
      pppbStack_6b4 = (byte ***)((int)pppbStack_6b4 + iVar2);
      pppbVar11 = (byte ***)(*(code *)PTR_strlen_006a9a24)(acStack_5e0);
      pppbVar14 = pppbVar8;
      iVar12 = (*pcVar7)(acStack_5e0);
      iStack_6ac = iStack_6ac + iVar12;
    } while (iVar13 != iStack_6a8);
  }
  if (pppbStack_680 != (byte ***)0x0) {
    len_00 = appbStack_664;
    BIO_snprintf(acStack_5e0,0x121,"%s%04x - <SPACES/NULS>\n",len_00,
                 (byte *)((int)pppbVar10 + (int)pppbStack_680));
    pppbVar11 = (byte ***)(*(code *)PTR_strlen_006a9a24)(acStack_5e0);
    iVar2 = (*pcVar7)(acStack_5e0);
    iStack_6ac = iStack_6ac + iVar2;
    pppbVar14 = pppbVar8;
  }
  if (pcStack_4bc == *(cb **)puVar1) {
    return iStack_6ac;
  }
  cb = pcStack_4bc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = BIO_dump_indent_cb(cb,pppbVar11,(char *)pppbVar14,(int)len_00,0);
  return iVar2;
}

