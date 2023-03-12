
/* WARNING: Removing unreachable block (ram,0x00529f78) */
/* WARNING: Removing unreachable block (ram,0x00529ad8) */
/* WARNING: Removing unreachable block (ram,0x00529720) */
/* WARNING: Removing unreachable block (ram,0x00529728) */
/* WARNING: Removing unreachable block (ram,0x0052972c) */
/* WARNING: Removing unreachable block (ram,0x0052974c) */
/* WARNING: Removing unreachable block (ram,0x00529750) */
/* WARNING: Removing unreachable block (ram,0x00529760) */
/* WARNING: Removing unreachable block (ram,0x00529764) */
/* WARNING: Removing unreachable block (ram,0x00529774) */
/* WARNING: Removing unreachable block (ram,0x00529778) */
/* WARNING: Removing unreachable block (ram,0x0052a410) */
/* WARNING: Removing unreachable block (ram,0x00529ab0) */

int BIO_dump(BIO *b,char *bytes,int len)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  code *pcVar7;
  cb *cb;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *len_00;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *unaff_s2;
  byte *unaff_s4;
  undefined4 unaff_s5;
  undefined4 *unaff_s6;
  undefined4 *unaff_s7;
  char *unaff_s8;
  undefined4 *puStack_6b4;
  int iStack_6ac;
  int iStack_6a8;
  undefined4 *puStack_680;
  char acStack_678 [20];
  undefined4 auStack_664 [33];
  char acStack_5e0 [292];
  cb *pcStack_4bc;
  byte **ppbStack_4b8;
  undefined4 *puStack_4b4;
  undefined4 *puStack_4b0;
  int iStack_4ac;
  byte *pbStack_4a8;
  undefined4 uStack_4a4;
  undefined4 *puStack_4a0;
  undefined4 *puStack_49c;
  char *pcStack_498;
  code *pcStack_494;
  undefined4 *puStack_484;
  undefined4 *puStack_480;
  undefined *puStack_478;
  char *pcStack_46c;
  undefined4 *puStack_468;
  char *pcStack_464;
  int iStack_460;
  byte **ppbStack_45c;
  undefined4 *puStack_458;
  undefined4 *puStack_454;
  char *pcStack_450;
  byte **ppbStack_44c;
  char *pcStack_448;
  char *pcStack_444;
  undefined4 *puStack_440;
  char *pcStack_43c;
  undefined4 *puStack_438;
  code **ppcStack_434;
  char acStack_430 [20];
  undefined4 auStack_41c [33];
  undefined uStack_398;
  code *pcStack_274;
  byte *apbStack_270 [4];
  byte *pbStack_260;
  undefined4 uStack_25c;
  undefined4 *puStack_258;
  undefined4 *puStack_254;
  char *pcStack_250;
  code *pcStack_24c;
  undefined4 *puStack_240;
  byte *pbStack_238;
  undefined *puStack_230;
  char *pcStack_224;
  undefined4 *puStack_220;
  char *pcStack_21c;
  int iStack_218;
  undefined4 *puStack_214;
  char *pcStack_210;
  BIO *pBStack_20c;
  char *pcStack_208;
  undefined4 *puStack_204;
  char *pcStack_200;
  char *pcStack_1fc;
  undefined4 *puStack_1f8;
  char *pcStack_1f4;
  undefined4 *puStack_1f0;
  byte **ppbStack_1ec;
  char acStack_1e8 [20];
  undefined uStack_1d4;
  undefined uStack_150;
  undefined4 *puStack_2c;
  
  puVar10 = (undefined4 *)0x0;
  ppbStack_1ec = (byte **)PTR___stack_chk_guard_006aabf0;
  puStack_230 = &_gp;
  puStack_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pcVar4 = bytes + len;
  iVar2 = len;
  if (len < 1) {
    puStack_1f0 = (undefined4 *)0x0;
    puStack_458 = (undefined4 *)bytes;
  }
  else {
    puStack_458 = (undefined4 *)0x0;
    do {
      iVar13 = iVar2 + -1;
      puStack_1f0 = puStack_458;
      if ((pcVar4[-1] & 0xdfU) != 0) break;
      puStack_458 = (undefined4 *)((int)puStack_458 + 1);
      pcVar4 = pcVar4 + -1;
      iVar2 = iVar13;
      puStack_1f0 = puStack_458;
    } while (iVar13 != 0);
  }
  apbStack_270[0] = &stack0xffffffd8;
  uStack_1d4 = 0;
  puStack_204 = (undefined4 *)(iVar2 / 0x10 + (uint)((iVar2 / 0x10) * 0x10 < iVar2));
  pcStack_210 = bytes;
  pBStack_20c = b;
  if ((int)puStack_204 < 1) {
    iStack_218 = 0;
  }
  else {
    iStack_218 = 0;
    unaff_s6 = (undefined4 *)&uStack_1d4;
    puStack_214 = (undefined4 *)0x0;
    unaff_s2 = (undefined4 *)0x0;
    pcStack_200 = "r";
    unaff_s7 = (undefined4 *)&uStack_150;
    unaff_s8 = acStack_1e8;
    pcStack_1fc = "s\n";
    pcStack_208 = "s\n";
    pcStack_224 = "%02x%c";
    pcStack_21c = "   ";
    pcStack_1f4 = "r";
    puStack_220 = (undefined4 *)bytes;
    puStack_1f8 = unaff_s6;
    do {
      uStack_150 = 0;
      BUF_strlcpy((char *)unaff_s7,(char *)puStack_1f8,0x121);
      puVar10 = unaff_s2;
      BIO_snprintf(unaff_s8,0x14,pcStack_200 + -0x7d30);
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      iVar13 = 0;
      puVar8 = puStack_220;
      do {
        while (puVar11 = puVar8, iVar2 <= (int)((int)unaff_s2 + iVar13)) {
          iVar13 = iVar13 + 1;
          BUF_strlcat((char *)unaff_s7,pcStack_21c,0x121);
          puVar8 = (undefined4 *)((int)puVar11 + 1);
          if (iVar13 == 0x10) goto LAB_005298e0;
        }
        puVar10 = (undefined4 *)(uint)*(byte *)puVar11;
        pbStack_238 = &DAT_0000002d;
        if (iVar13 != 7) {
          pbStack_238 = &DAT_00000020;
        }
        iVar13 = iVar13 + 1;
        BIO_snprintf(unaff_s8,0x14,pcStack_224);
        BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
        puVar8 = (undefined4 *)((int)puVar11 + 1);
      } while (iVar13 != 0x10);
LAB_005298e0:
      unaff_s4 = (byte *)((int)puVar11 + 1);
      BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x45c4,0x121);
      if ((int)unaff_s2 < iVar2) {
        unaff_s5 = 0x2e;
        unaff_s6 = (undefined4 *)(pcStack_210 + iVar2);
        puVar11 = (undefined4 *)(pcStack_210 + (int)((int)unaff_s2 + 0xf));
        unaff_s4 = (byte *)(pcStack_1f4 + -0x5bd0);
        puVar8 = puStack_220;
        do {
          puVar10 = (undefined4 *)(uint)*(byte *)puVar8;
          if ((undefined4 *)0x5e < puVar10 + -8) {
            puVar10 = (undefined4 *)0x2e;
          }
          BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4);
          BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
        } while ((puVar8 != puVar11) &&
                (puVar8 = (undefined4 *)((int)puVar8 + 1), unaff_s6 != puVar8));
      }
      unaff_s2 = unaff_s2 + 4;
      BUF_strlcat((char *)unaff_s7,pcStack_1fc + -0x4538,0x121);
      apbStack_270[0] = (byte *)((int)puStack_214 + 1);
      puStack_220 = puStack_220 + 4;
      puStack_214 = (undefined4 *)apbStack_270[0];
      len = (**(code **)(puStack_230 + -0x53b0))(unaff_s7);
      puStack_458 = unaff_s7;
      iVar13 = BIO_write(pBStack_20c,unaff_s7,len);
      iStack_218 = iStack_218 + iVar13;
    } while ((undefined4 *)apbStack_270[0] != puStack_204);
  }
  apbStack_270[3] = (byte *)0x10;
  apbStack_270[1] = (byte *)((int)puStack_1f0 + iVar2);
  if (puStack_1f0 != (undefined4 *)0x0) {
    apbStack_270[0] = &uStack_150;
    puVar10 = (undefined4 *)&uStack_1d4;
    pbStack_238 = apbStack_270[1];
    BIO_snprintf((char *)apbStack_270[0],0x121,"%s%04x - <SPACES/NULS>\n");
    len = (**(code **)(puStack_230 + -0x53b0))(apbStack_270[0]);
    puStack_458 = (undefined4 *)apbStack_270[0];
    iVar2 = BIO_write(pBStack_20c,apbStack_270[0],len);
    iStack_218 = iStack_218 + iVar2;
  }
  if (puStack_2c == (undefined4 *)*ppbStack_1ec) {
    return iStack_218;
  }
  pcStack_24c = BIO_dump_indent_cb_constprop_0;
  puStack_454 = puStack_2c;
  (**(code **)(puStack_230 + -0x5328))();
  ppcStack_434 = (code **)PTR___stack_chk_guard_006aabf0;
  puStack_478 = &_gp;
  pcStack_274 = *(code **)PTR___stack_chk_guard_006aabf0;
  pbVar5 = (byte *)((int)puStack_458 + len);
  puStack_4b4 = (undefined4 *)len;
  if (len < 1) {
    puStack_438 = (undefined4 *)0x0;
    puVar8 = puStack_458;
  }
  else {
    puVar8 = (undefined4 *)0x0;
    do {
      puVar11 = (undefined4 *)((int)puStack_4b4 + -1);
      puStack_438 = puVar8;
      if ((pbVar5[-1] & 0xdf) != 0) break;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      pbVar5 = pbVar5 + -1;
      puStack_4b4 = puVar11;
      puStack_438 = puVar8;
    } while (puVar11 != (undefined4 *)0x0);
  }
  apbStack_270[2] = (byte *)unaff_s2;
  pbStack_260 = unaff_s4;
  uStack_25c = unaff_s5;
  puStack_258 = unaff_s6;
  puStack_254 = unaff_s7;
  pcStack_250 = unaff_s8;
  if ((int)puVar10 < 1) {
    iStack_4ac = 0x10;
    ppbStack_4b8 = apbStack_270;
    auStack_41c[0]._0_1_ = 0;
    ppbStack_44c = (byte **)((int)puStack_4b4 / 0x10 +
                            (uint)(((int)puStack_4b4 / 0x10) * 0x10 < (int)puStack_4b4));
  }
  else {
    puVar11 = (undefined4 *)&DAT_00000080;
    if ((int)puVar10 < 0x81) {
      puVar11 = puVar10;
    }
    puVar10 = (undefined4 *)0x81;
    puVar8 = (undefined4 *)&DAT_00000020;
    len = (int)puVar11;
    (*(code *)PTR___memset_chk_006aaa98)(auStack_41c);
    puVar14 = (undefined4 *)&DAT_00000006;
    if ((int)puVar11 < 7) {
      puVar14 = puVar11;
    }
    pbVar5 = (byte *)((int)puVar11 + (3 - (int)puVar14));
    if ((int)pbVar5 < 0) {
      pbVar5 = (byte *)((int)puVar11 + (6 - (int)puVar14));
    }
    iStack_4ac = 0x10 - ((int)pbVar5 >> 2);
    if (iStack_4ac == 0) {
      trap(7);
    }
    ppbStack_4b8 = (byte **)((int)apbStack_270 + (int)puVar11);
    *(byte *)((int)auStack_41c + (int)puVar11) = 0;
    ppbStack_44c = (byte **)((int)puStack_4b4 / iStack_4ac +
                            (uint)(((int)puStack_4b4 / iStack_4ac) * iStack_4ac < (int)puStack_4b4))
    ;
  }
  if ((int)ppbStack_44c < 1) {
    iStack_460 = 0;
  }
  else {
    iStack_460 = 0;
    unaff_s6 = auStack_41c;
    ppbStack_45c = (byte **)0x0;
    unaff_s2 = (undefined4 *)0x0;
    pcStack_448 = "r";
    unaff_s7 = (undefined4 *)&uStack_398;
    unaff_s8 = acStack_430;
    pcStack_444 = "s\n";
    pcStack_450 = "s\n";
    pcStack_46c = "%02x%c";
    pcStack_464 = "   ";
    pcStack_43c = "r";
    puStack_468 = puStack_458;
    puStack_440 = unaff_s6;
    do {
      uStack_398 = 0;
      BUF_strlcpy((char *)unaff_s7,(char *)puStack_440,0x121);
      BIO_snprintf(unaff_s8,0x14,pcStack_448 + -0x7d30,unaff_s2);
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      if (iStack_4ac < 1) {
        BUF_strlcat((char *)unaff_s7,pcStack_450 + -0x45c4,0x121);
      }
      else {
        iVar2 = 0;
        puVar10 = puStack_468;
        do {
          while (puVar8 = puVar10, (int)puStack_4b4 <= (int)((int)unaff_s2 + iVar2)) {
            iVar2 = iVar2 + 1;
            BUF_strlcat((char *)unaff_s7,pcStack_464,0x121);
            puVar10 = (undefined4 *)((int)puVar8 + 1);
            if (iVar2 == iStack_4ac) goto LAB_00529d78;
          }
          puStack_480 = (undefined4 *)&DAT_0000002d;
          if (iVar2 != 7) {
            puStack_480 = (undefined4 *)&DAT_00000020;
          }
          iVar2 = iVar2 + 1;
          BIO_snprintf(unaff_s8,0x14,pcStack_46c,(uint)*(byte *)puVar8);
          BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
          puVar10 = (undefined4 *)((int)puVar8 + 1);
        } while (iVar2 != iStack_4ac);
LAB_00529d78:
        unaff_s4 = (byte *)((int)puVar8 + 1);
        BUF_strlcat((char *)unaff_s7,pcStack_450 + -0x45c4,0x121);
        if ((int)unaff_s2 < (int)puStack_4b4) {
          unaff_s5 = 0x2e;
          unaff_s6 = (undefined4 *)((int)puStack_458 + (int)puStack_4b4);
          puVar8 = (undefined4 *)((int)puStack_458 + (int)((int)unaff_s2 + iStack_4ac + -1));
          unaff_s4 = (byte *)(pcStack_43c + -0x5bd0);
          puVar10 = puStack_468;
          puStack_240 = puStack_4b4;
          do {
            uVar9 = (uint)*(byte *)puVar10;
            if (0x5e < uVar9 - 0x20) {
              uVar9 = 0x2e;
            }
            BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4,uVar9);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            puStack_4b4 = puStack_240;
          } while ((puVar10 != puVar8) &&
                  (puVar10 = (undefined4 *)((int)puVar10 + 1), unaff_s6 != puVar10));
        }
      }
      unaff_s2 = (undefined4 *)((int)unaff_s2 + iStack_4ac);
      BUF_strlcat((char *)unaff_s7,pcStack_444 + -0x4538,0x121);
      ppbStack_4b8 = (byte **)((int)ppbStack_45c + 1);
      puStack_468 = (undefined4 *)((int)puStack_468 + iStack_4ac);
      ppbStack_45c = ppbStack_4b8;
      puVar8 = (undefined4 *)(**(code **)(puStack_478 + -0x53b0))(unaff_s7);
      len = 1;
      puVar10 = puStack_454;
      iVar2 = (**(code **)(puStack_478 + -0x5364))(unaff_s7);
      iStack_460 = iStack_460 + iVar2;
    } while (ppbStack_4b8 != ppbStack_44c);
  }
  puStack_4b4 = (undefined4 *)((int)puStack_438 + (int)puStack_4b4);
  if (puStack_438 != (undefined4 *)0x0) {
    ppbStack_4b8 = (byte **)&uStack_398;
    puStack_480 = puStack_4b4;
    BIO_snprintf((char *)ppbStack_4b8,0x121,"%s%04x - <SPACES/NULS>\n",auStack_41c);
    puVar8 = (undefined4 *)(**(code **)(puStack_478 + -0x53b0))(ppbStack_4b8);
    len = 1;
    puVar10 = puStack_454;
    iVar2 = (**(code **)(puStack_478 + -0x5364))(ppbStack_4b8);
    iStack_460 = iStack_460 + iVar2;
  }
  if (pcStack_274 == *ppcStack_434) {
    return iStack_460;
  }
  pcStack_494 = BIO_dump_indent_cb;
  pcVar7 = pcStack_274;
  (**(code **)(puStack_478 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcStack_4bc = *(cb **)PTR___stack_chk_guard_006aabf0;
  pbVar5 = (byte *)(len + (int)puVar10);
  if ((int)puVar10 < 1) {
    puStack_680 = (undefined4 *)0x0;
    puVar11 = puVar8;
  }
  else {
    puVar11 = (undefined4 *)0x0;
    do {
      puVar14 = (undefined4 *)((int)puVar10 + -1);
      puStack_680 = puVar11;
      if ((pbVar5[-1] & 0xdf) != 0) break;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      pbVar5 = pbVar5 + -1;
      puVar10 = puVar14;
      puStack_680 = puVar11;
    } while (puVar14 != (undefined4 *)0x0);
  }
  puStack_4b0 = unaff_s2;
  pbStack_4a8 = unaff_s4;
  uStack_4a4 = unaff_s5;
  puStack_4a0 = unaff_s6;
  puStack_49c = unaff_s7;
  pcStack_498 = unaff_s8;
  if ((int)puStack_480 < 1) {
    iVar2 = 0x10;
    auStack_664[0]._0_1_ = 0;
    iVar13 = (int)puVar10 / 0x10 + (uint)(((int)puVar10 / 0x10) * 0x10 < (int)puVar10);
    puVar14 = (undefined4 *)len;
    len_00 = puStack_480;
  }
  else {
    puVar15 = (undefined4 *)&DAT_00000080;
    if ((int)puStack_480 < 0x81) {
      puVar15 = puStack_480;
    }
    len_00 = (undefined4 *)0x81;
    puVar11 = (undefined4 *)&DAT_00000020;
    puVar14 = puVar15;
    (*(code *)PTR___memset_chk_006aaa98)(auStack_664);
    puVar6 = (undefined4 *)&DAT_00000006;
    if ((int)puVar15 < 7) {
      puVar6 = puVar15;
    }
    pbVar5 = (byte *)((int)puVar15 + (3 - (int)puVar6));
    if ((int)pbVar5 < 0) {
      pbVar5 = (byte *)((int)puVar15 + (6 - (int)puVar6));
    }
    iVar2 = 0x10 - ((int)pbVar5 >> 2);
    if (iVar2 == 0) {
      trap(7);
    }
    *(byte *)((int)auStack_664 + (int)puVar15) = 0;
    iVar13 = (int)puVar10 / iVar2 + (uint)(((int)puVar10 / iVar2) * iVar2 < (int)puVar10);
  }
  if (iVar13 < 1) {
    iStack_6ac = 0;
  }
  else {
    iStack_6a8 = 0;
    iStack_6ac = 0;
    puVar15 = (undefined4 *)0x0;
    puStack_6b4 = (undefined4 *)len;
    do {
      acStack_5e0[0] = '\0';
      BUF_strlcpy(acStack_5e0,(char *)auStack_664,0x121);
      len_00 = puVar15;
      BIO_snprintf(acStack_678,0x14,"%04x - ");
      BUF_strlcat(acStack_5e0,acStack_678,0x121);
      if (iVar2 < 1) {
        BUF_strlcat(acStack_5e0,"  ",0x121);
      }
      else {
        iVar12 = 0;
        puVar11 = puStack_6b4;
        do {
          while ((int)puVar10 <= (int)((int)puVar15 + iVar12)) {
            iVar12 = iVar12 + 1;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            BUF_strlcat(acStack_5e0,"   ",0x121);
            if (iVar12 == iVar2) goto LAB_0052a220;
          }
          len_00 = (undefined4 *)(uint)*(byte *)puVar11;
          uVar3 = 0x2d;
          if (iVar12 != 7) {
            uVar3 = 0x20;
          }
          iVar12 = iVar12 + 1;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          BIO_snprintf(acStack_678,0x14,"%02x%c",len_00,uVar3);
          BUF_strlcat(acStack_5e0,acStack_678,0x121);
        } while (iVar12 != iVar2);
LAB_0052a220:
        BUF_strlcat(acStack_5e0,"  ",0x121);
        if ((int)puVar15 < (int)puVar10) {
          puVar14 = (undefined4 *)(len + (int)puVar10);
          puVar11 = puStack_6b4;
          puStack_484 = puVar10;
          do {
            len_00 = (undefined4 *)(uint)*(byte *)puVar11;
            if ((undefined4 *)0x5e < len_00 + -8) {
              len_00 = (undefined4 *)0x2e;
            }
            BIO_snprintf(acStack_678,0x14,"%c");
            BUF_strlcat(acStack_5e0,acStack_678,0x121);
            puVar10 = puStack_484;
          } while ((puVar11 != (undefined4 *)(len + (int)((int)puVar15 + iVar2 + -1))) &&
                  (puVar11 = (undefined4 *)((int)puVar11 + 1), puVar14 != puVar11));
        }
      }
      puVar15 = (undefined4 *)((int)puVar15 + iVar2);
      BUF_strlcat(acStack_5e0,"\n",0x121);
      iStack_6a8 = iStack_6a8 + 1;
      puStack_6b4 = (undefined4 *)((int)puStack_6b4 + iVar2);
      puVar11 = (undefined4 *)(*(code *)PTR_strlen_006aab30)(acStack_5e0);
      puVar14 = puVar8;
      iVar12 = (*pcVar7)(acStack_5e0);
      iStack_6ac = iStack_6ac + iVar12;
    } while (iVar13 != iStack_6a8);
  }
  if (puStack_680 != (undefined4 *)0x0) {
    len_00 = auStack_664;
    BIO_snprintf(acStack_5e0,0x121,"%s%04x - <SPACES/NULS>\n",len_00,
                 (byte *)((int)puVar10 + (int)puStack_680));
    puVar11 = (undefined4 *)(*(code *)PTR_strlen_006aab30)(acStack_5e0);
    iVar2 = (*pcVar7)(acStack_5e0);
    iStack_6ac = iStack_6ac + iVar2;
    puVar14 = puVar8;
  }
  if (pcStack_4bc == *(cb **)puVar1) {
    return iStack_6ac;
  }
  cb = pcStack_4bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = BIO_dump_indent_cb(cb,puVar11,(char *)puVar14,(int)len_00,0);
  return iVar2;
}

