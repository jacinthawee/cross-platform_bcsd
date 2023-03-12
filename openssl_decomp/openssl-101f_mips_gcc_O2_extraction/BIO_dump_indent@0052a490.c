
/* WARNING: Removing unreachable block (ram,0x00529f78) */
/* WARNING: Removing unreachable block (ram,0x00529ad8) */
/* WARNING: Removing unreachable block (ram,0x0052a410) */

int BIO_dump_indent(BIO *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  code *pcVar6;
  cb *cb;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *len;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
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
  byte *apbStack_270 [3];
  int iStack_264;
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
  undefined4 *puStack_210;
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
  undefined4 auStack_1d4 [33];
  undefined uStack_150;
  undefined4 *puStack_2c;
  
  ppbStack_1ec = (byte **)PTR___stack_chk_guard_006aabf0;
  puStack_230 = &_gp;
  puStack_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pbVar4 = (byte *)((int)param_2 + (int)param_3);
  puVar7 = param_3;
  if ((int)param_3 < 1) {
    puStack_1f0 = (undefined4 *)0x0;
    puStack_458 = param_2;
  }
  else {
    puStack_458 = (undefined4 *)0x0;
    do {
      puVar12 = (undefined4 *)((int)puVar7 + -1);
      puStack_1f0 = puStack_458;
      if ((pbVar4[-1] & 0xdf) != 0) break;
      puStack_458 = (undefined4 *)((int)puStack_458 + 1);
      pbVar4 = pbVar4 + -1;
      puVar7 = puVar12;
      puStack_1f0 = puStack_458;
    } while (puVar12 != (undefined4 *)0x0);
  }
  puStack_210 = param_2;
  pBStack_20c = param_1;
  if ((int)param_4 < 1) {
    iStack_264 = 0x10;
    apbStack_270[0] = &stack0xffffffd8;
    auStack_1d4[0]._0_1_ = 0;
    puStack_204 = (undefined4 *)
                  ((int)puVar7 / 0x10 + (uint)(((int)puVar7 / 0x10) * 0x10 < (int)puVar7));
  }
  else {
    puVar12 = (undefined4 *)&DAT_00000080;
    if ((int)param_4 < 0x81) {
      puVar12 = param_4;
    }
    param_4 = (undefined4 *)0x81;
    puStack_458 = (undefined4 *)&DAT_00000020;
    param_3 = puVar12;
    (*(code *)PTR___memset_chk_006aaa98)(auStack_1d4);
    puVar10 = (undefined4 *)&DAT_00000006;
    if ((int)puVar12 < 7) {
      puVar10 = puVar12;
    }
    pbVar4 = (byte *)((int)puVar12 + (3 - (int)puVar10));
    if ((int)pbVar4 < 0) {
      pbVar4 = (byte *)((int)puVar12 + (6 - (int)puVar10));
    }
    iStack_264 = 0x10 - ((int)pbVar4 >> 2);
    if (iStack_264 == 0) {
      trap(7);
    }
    apbStack_270[0] = &stack0xffffffd8 + (int)puVar12;
    *(byte *)((int)auStack_1d4 + (int)puVar12) = 0;
    puStack_204 = (undefined4 *)
                  ((int)puVar7 / iStack_264 +
                  (uint)(((int)puVar7 / iStack_264) * iStack_264 < (int)puVar7));
  }
  if ((int)puStack_204 < 1) {
    iStack_218 = 0;
  }
  else {
    iStack_218 = 0;
    unaff_s6 = auStack_1d4;
    puStack_214 = (undefined4 *)0x0;
    unaff_s2 = (undefined4 *)0x0;
    pcStack_200 = "7 datafinal";
    unaff_s7 = (undefined4 *)&uStack_150;
    unaff_s8 = acStack_1e8;
    pcStack_1fc = "s\n";
    pcStack_208 = "s\n";
    pcStack_224 = "%02x%c";
    pcStack_21c = "   ";
    pcStack_1f4 = "7 datafinal";
    puStack_220 = puStack_210;
    puStack_1f8 = unaff_s6;
    do {
      uStack_150 = 0;
      BUF_strlcpy((char *)unaff_s7,(char *)puStack_1f8,0x121);
      param_4 = unaff_s2;
      BIO_snprintf(unaff_s8,0x14,pcStack_200 + -0x7d10);
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      if (iStack_264 < 1) {
        BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x45c4,0x121);
      }
      else {
        iVar9 = 0;
        puVar12 = puStack_220;
        do {
          while (puVar10 = puVar12, (int)((int)unaff_s2 + iVar9) < (int)puVar7) {
            param_4 = (undefined4 *)(uint)*(byte *)puVar10;
            pbStack_238 = &DAT_0000002d;
            if (iVar9 != 7) {
              pbStack_238 = &DAT_00000020;
            }
            iVar9 = iVar9 + 1;
            BIO_snprintf(unaff_s8,0x14,pcStack_224);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            puVar12 = (undefined4 *)((int)puVar10 + 1);
            if (iVar9 == iStack_264) goto LAB_005298e0;
          }
          iVar9 = iVar9 + 1;
          BUF_strlcat((char *)unaff_s7,pcStack_21c,0x121);
          puVar12 = (undefined4 *)((int)puVar10 + 1);
        } while (iVar9 != iStack_264);
LAB_005298e0:
        unaff_s4 = (byte *)((int)puVar10 + 1);
        BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x45c4,0x121);
        if ((int)unaff_s2 < (int)puVar7) {
          unaff_s5 = 0x2e;
          unaff_s6 = (undefined4 *)((int)puStack_210 + (int)puVar7);
          puVar10 = (undefined4 *)((int)puStack_210 + (int)((int)unaff_s2 + iStack_264 + -1));
          unaff_s4 = (byte *)(pcStack_1f4 + -0x5bb0);
          puVar12 = puStack_220;
          do {
            param_4 = (undefined4 *)(uint)*(byte *)puVar12;
            if ((undefined4 *)0x5e < param_4 + -8) {
              param_4 = (undefined4 *)0x2e;
            }
            BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
          } while ((puVar12 != puVar10) &&
                  (puVar12 = (undefined4 *)((int)puVar12 + 1), unaff_s6 != puVar12));
        }
      }
      unaff_s2 = (undefined4 *)((int)unaff_s2 + iStack_264);
      BUF_strlcat((char *)unaff_s7,pcStack_1fc + -0x4538,0x121);
      apbStack_270[0] = (byte *)((int)puStack_214 + 1);
      puStack_220 = (undefined4 *)((int)puStack_220 + iStack_264);
      puStack_214 = (undefined4 *)apbStack_270[0];
      param_3 = (undefined4 *)(**(code **)(puStack_230 + -0x53b0))(unaff_s7);
      puStack_458 = unaff_s7;
      iVar9 = BIO_write(pBStack_20c,unaff_s7,(int)param_3);
      iStack_218 = iStack_218 + iVar9;
    } while ((undefined4 *)apbStack_270[0] != puStack_204);
  }
  apbStack_270[1] = (byte *)((int)puStack_1f0 + (int)puVar7);
  if (puStack_1f0 != (undefined4 *)0x0) {
    apbStack_270[0] = &uStack_150;
    param_4 = auStack_1d4;
    pbStack_238 = apbStack_270[1];
    BIO_snprintf((char *)apbStack_270[0],0x121,"%s%04x - <SPACES/NULS>\n");
    param_3 = (undefined4 *)(**(code **)(puStack_230 + -0x53b0))(apbStack_270[0]);
    puStack_458 = (undefined4 *)apbStack_270[0];
    iVar9 = BIO_write(pBStack_20c,apbStack_270[0],(int)param_3);
    iStack_218 = iStack_218 + iVar9;
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
  pbVar4 = (byte *)((int)puStack_458 + (int)param_3);
  puStack_4b4 = param_3;
  if ((int)param_3 < 1) {
    puStack_438 = (undefined4 *)0x0;
    puVar7 = puStack_458;
  }
  else {
    puVar7 = (undefined4 *)0x0;
    do {
      puVar12 = (undefined4 *)((int)puStack_4b4 + -1);
      puStack_438 = puVar7;
      if ((pbVar4[-1] & 0xdf) != 0) break;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      pbVar4 = pbVar4 + -1;
      puStack_4b4 = puVar12;
      puStack_438 = puVar7;
    } while (puVar12 != (undefined4 *)0x0);
  }
  apbStack_270[2] = (byte *)unaff_s2;
  pbStack_260 = unaff_s4;
  uStack_25c = unaff_s5;
  puStack_258 = unaff_s6;
  puStack_254 = unaff_s7;
  pcStack_250 = unaff_s8;
  if ((int)param_4 < 1) {
    iStack_4ac = 0x10;
    ppbStack_4b8 = apbStack_270;
    auStack_41c[0]._0_1_ = 0;
    ppbStack_44c = (byte **)((int)puStack_4b4 / 0x10 +
                            (uint)(((int)puStack_4b4 / 0x10) * 0x10 < (int)puStack_4b4));
  }
  else {
    puVar12 = (undefined4 *)&DAT_00000080;
    if ((int)param_4 < 0x81) {
      puVar12 = param_4;
    }
    param_4 = (undefined4 *)0x81;
    puVar7 = (undefined4 *)&DAT_00000020;
    param_3 = puVar12;
    (*(code *)PTR___memset_chk_006aaa98)(auStack_41c);
    puVar10 = (undefined4 *)&DAT_00000006;
    if ((int)puVar12 < 7) {
      puVar10 = puVar12;
    }
    pbVar4 = (byte *)((int)puVar12 + (3 - (int)puVar10));
    if ((int)pbVar4 < 0) {
      pbVar4 = (byte *)((int)puVar12 + (6 - (int)puVar10));
    }
    iStack_4ac = 0x10 - ((int)pbVar4 >> 2);
    if (iStack_4ac == 0) {
      trap(7);
    }
    ppbStack_4b8 = (byte **)((int)apbStack_270 + (int)puVar12);
    *(byte *)((int)auStack_41c + (int)puVar12) = 0;
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
    pcStack_448 = "7 datafinal";
    unaff_s7 = (undefined4 *)&uStack_398;
    unaff_s8 = acStack_430;
    pcStack_444 = "s\n";
    pcStack_450 = "s\n";
    pcStack_46c = "%02x%c";
    pcStack_464 = "   ";
    pcStack_43c = "7 datafinal";
    puStack_468 = puStack_458;
    puStack_440 = unaff_s6;
    do {
      uStack_398 = 0;
      BUF_strlcpy((char *)unaff_s7,(char *)puStack_440,0x121);
      BIO_snprintf(unaff_s8,0x14,pcStack_448 + -0x7d10,unaff_s2);
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      if (iStack_4ac < 1) {
        BUF_strlcat((char *)unaff_s7,pcStack_450 + -0x45c4,0x121);
      }
      else {
        iVar9 = 0;
        puVar7 = puStack_468;
        do {
          while (puVar12 = puVar7, (int)((int)unaff_s2 + iVar9) < (int)puStack_4b4) {
            puStack_480 = (undefined4 *)&DAT_0000002d;
            if (iVar9 != 7) {
              puStack_480 = (undefined4 *)&DAT_00000020;
            }
            iVar9 = iVar9 + 1;
            BIO_snprintf(unaff_s8,0x14,pcStack_46c,(uint)*(byte *)puVar12);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            puVar7 = (undefined4 *)((int)puVar12 + 1);
            if (iVar9 == iStack_4ac) goto LAB_00529d78;
          }
          iVar9 = iVar9 + 1;
          BUF_strlcat((char *)unaff_s7,pcStack_464,0x121);
          puVar7 = (undefined4 *)((int)puVar12 + 1);
        } while (iVar9 != iStack_4ac);
LAB_00529d78:
        unaff_s4 = (byte *)((int)puVar12 + 1);
        BUF_strlcat((char *)unaff_s7,pcStack_450 + -0x45c4,0x121);
        if ((int)unaff_s2 < (int)puStack_4b4) {
          unaff_s5 = 0x2e;
          unaff_s6 = (undefined4 *)((int)puStack_458 + (int)puStack_4b4);
          puVar12 = (undefined4 *)((int)puStack_458 + (int)((int)unaff_s2 + iStack_4ac + -1));
          unaff_s4 = (byte *)(pcStack_43c + -0x5bb0);
          puVar7 = puStack_468;
          puStack_240 = puStack_4b4;
          do {
            uVar8 = (uint)*(byte *)puVar7;
            if (0x5e < uVar8 - 0x20) {
              uVar8 = 0x2e;
            }
            BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4,uVar8);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            puStack_4b4 = puStack_240;
          } while ((puVar7 != puVar12) &&
                  (puVar7 = (undefined4 *)((int)puVar7 + 1), unaff_s6 != puVar7));
        }
      }
      unaff_s2 = (undefined4 *)((int)unaff_s2 + iStack_4ac);
      BUF_strlcat((char *)unaff_s7,pcStack_444 + -0x4538,0x121);
      ppbStack_4b8 = (byte **)((int)ppbStack_45c + 1);
      puStack_468 = (undefined4 *)((int)puStack_468 + iStack_4ac);
      ppbStack_45c = ppbStack_4b8;
      puVar7 = (undefined4 *)(**(code **)(puStack_478 + -0x53b0))(unaff_s7);
      param_3 = (undefined4 *)0x1;
      param_4 = puStack_454;
      iVar9 = (**(code **)(puStack_478 + -0x5364))(unaff_s7);
      iStack_460 = iStack_460 + iVar9;
    } while (ppbStack_4b8 != ppbStack_44c);
  }
  puStack_4b4 = (undefined4 *)((int)puStack_438 + (int)puStack_4b4);
  if (puStack_438 != (undefined4 *)0x0) {
    ppbStack_4b8 = (byte **)&uStack_398;
    puStack_480 = puStack_4b4;
    BIO_snprintf((char *)ppbStack_4b8,0x121,"%s%04x - <SPACES/NULS>\n",auStack_41c);
    puVar7 = (undefined4 *)(**(code **)(puStack_478 + -0x53b0))(ppbStack_4b8);
    param_3 = (undefined4 *)0x1;
    param_4 = puStack_454;
    iVar9 = (**(code **)(puStack_478 + -0x5364))(ppbStack_4b8);
    iStack_460 = iStack_460 + iVar9;
  }
  if (pcStack_274 == *ppcStack_434) {
    return iStack_460;
  }
  pcStack_494 = BIO_dump_indent_cb;
  pcVar6 = pcStack_274;
  (**(code **)(puStack_478 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcStack_4bc = *(cb **)PTR___stack_chk_guard_006aabf0;
  pbVar4 = (byte *)((int)param_3 + (int)param_4);
  if ((int)param_4 < 1) {
    puStack_680 = (undefined4 *)0x0;
    puVar12 = puVar7;
  }
  else {
    puVar12 = (undefined4 *)0x0;
    do {
      puVar10 = (undefined4 *)((int)param_4 + -1);
      puStack_680 = puVar12;
      if ((pbVar4[-1] & 0xdf) != 0) break;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      pbVar4 = pbVar4 + -1;
      param_4 = puVar10;
      puStack_680 = puVar12;
    } while (puVar10 != (undefined4 *)0x0);
  }
  puStack_4b0 = unaff_s2;
  pbStack_4a8 = unaff_s4;
  uStack_4a4 = unaff_s5;
  puStack_4a0 = unaff_s6;
  puStack_49c = unaff_s7;
  pcStack_498 = unaff_s8;
  if ((int)puStack_480 < 1) {
    iVar9 = 0x10;
    auStack_664[0]._0_1_ = 0;
    iVar2 = (int)param_4 / 0x10 + (uint)(((int)param_4 / 0x10) * 0x10 < (int)param_4);
    puVar10 = param_3;
    len = puStack_480;
  }
  else {
    puVar13 = (undefined4 *)&DAT_00000080;
    if ((int)puStack_480 < 0x81) {
      puVar13 = puStack_480;
    }
    len = (undefined4 *)0x81;
    puVar12 = (undefined4 *)&DAT_00000020;
    puVar10 = puVar13;
    (*(code *)PTR___memset_chk_006aaa98)(auStack_664);
    puVar5 = (undefined4 *)&DAT_00000006;
    if ((int)puVar13 < 7) {
      puVar5 = puVar13;
    }
    pbVar4 = (byte *)((int)puVar13 + (3 - (int)puVar5));
    if ((int)pbVar4 < 0) {
      pbVar4 = (byte *)((int)puVar13 + (6 - (int)puVar5));
    }
    iVar9 = 0x10 - ((int)pbVar4 >> 2);
    if (iVar9 == 0) {
      trap(7);
    }
    *(byte *)((int)auStack_664 + (int)puVar13) = 0;
    iVar2 = (int)param_4 / iVar9 + (uint)(((int)param_4 / iVar9) * iVar9 < (int)param_4);
  }
  if (iVar2 < 1) {
    iStack_6ac = 0;
  }
  else {
    iStack_6a8 = 0;
    iStack_6ac = 0;
    puVar13 = (undefined4 *)0x0;
    puStack_6b4 = param_3;
    do {
      acStack_5e0[0] = '\0';
      BUF_strlcpy(acStack_5e0,(char *)auStack_664,0x121);
      len = puVar13;
      BIO_snprintf(acStack_678,0x14,"%04x - ");
      BUF_strlcat(acStack_5e0,acStack_678,0x121);
      if (iVar9 < 1) {
        BUF_strlcat(acStack_5e0,"  ",0x121);
      }
      else {
        iVar11 = 0;
        puVar12 = puStack_6b4;
        do {
          while ((int)((int)puVar13 + iVar11) < (int)param_4) {
            len = (undefined4 *)(uint)*(byte *)puVar12;
            uVar3 = 0x2d;
            if (iVar11 != 7) {
              uVar3 = 0x20;
            }
            iVar11 = iVar11 + 1;
            puVar12 = (undefined4 *)((int)puVar12 + 1);
            BIO_snprintf(acStack_678,0x14,"%02x%c",len,uVar3);
            BUF_strlcat(acStack_5e0,acStack_678,0x121);
            if (iVar11 == iVar9) goto LAB_0052a220;
          }
          iVar11 = iVar11 + 1;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
          BUF_strlcat(acStack_5e0,"   ",0x121);
        } while (iVar11 != iVar9);
LAB_0052a220:
        BUF_strlcat(acStack_5e0,"  ",0x121);
        if ((int)puVar13 < (int)param_4) {
          puVar10 = (undefined4 *)((int)param_3 + (int)param_4);
          puVar12 = puStack_6b4;
          puStack_484 = param_4;
          do {
            len = (undefined4 *)(uint)*(byte *)puVar12;
            if ((undefined4 *)0x5e < len + -8) {
              len = (undefined4 *)0x2e;
            }
            BIO_snprintf(acStack_678,0x14,"%c");
            BUF_strlcat(acStack_5e0,acStack_678,0x121);
            param_4 = puStack_484;
          } while ((puVar12 != (undefined4 *)((int)param_3 + (int)((int)puVar13 + iVar9 + -1))) &&
                  (puVar12 = (undefined4 *)((int)puVar12 + 1), puVar10 != puVar12));
        }
      }
      puVar13 = (undefined4 *)((int)puVar13 + iVar9);
      BUF_strlcat(acStack_5e0,"\n",0x121);
      iStack_6a8 = iStack_6a8 + 1;
      puStack_6b4 = (undefined4 *)((int)puStack_6b4 + iVar9);
      puVar12 = (undefined4 *)(*(code *)PTR_strlen_006aab30)(acStack_5e0);
      puVar10 = puVar7;
      iVar11 = (*pcVar6)(acStack_5e0);
      iStack_6ac = iStack_6ac + iVar11;
    } while (iVar2 != iStack_6a8);
  }
  if (puStack_680 != (undefined4 *)0x0) {
    len = auStack_664;
    BIO_snprintf(acStack_5e0,0x121,"%s%04x - <SPACES/NULS>\n",len,
                 (byte *)((int)param_4 + (int)puStack_680));
    puVar12 = (undefined4 *)(*(code *)PTR_strlen_006aab30)(acStack_5e0);
    iVar9 = (*pcVar6)(acStack_5e0);
    iStack_6ac = iStack_6ac + iVar9;
    puVar10 = puVar7;
  }
  if (pcStack_4bc != *(cb **)puVar1) {
    cb = pcStack_4bc;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar9 = BIO_dump_indent_cb(cb,puVar12,(char *)puVar10,(int)len,0);
    return iVar9;
  }
  return iStack_6ac;
}

