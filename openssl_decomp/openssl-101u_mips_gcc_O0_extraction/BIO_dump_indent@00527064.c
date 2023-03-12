
/* WARNING: Removing unreachable block (ram,0x00526b50) */
/* WARNING: Removing unreachable block (ram,0x005266b4) */
/* WARNING: Removing unreachable block (ram,0x00526fe4) */

int BIO_dump_indent(BIO *param_1,byte ***param_2,byte ***param_3,byte ***param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte ***pppbVar5;
  code *pcVar6;
  cb *cb;
  byte ***pppbVar7;
  uint uVar8;
  byte ***len;
  int iVar9;
  byte ***pppbVar10;
  int iVar11;
  byte ***pppbVar12;
  byte ***pppbVar13;
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
  int iStack_264;
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
  byte ***pppbStack_210;
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
  byte **appbStack_1d4 [33];
  byte **appbStack_150 [73];
  byte ***pppbStack_2c;
  
  ppbStack_1ec = (byte **)PTR___stack_chk_guard_006a9ae8;
  puStack_230 = &_gp;
  pppbStack_2c = *(byte ****)PTR___stack_chk_guard_006a9ae8;
  pbVar4 = (byte *)((int)param_2 + (int)param_3);
  pppbVar7 = param_3;
  if ((int)param_3 < 1) {
    pppbStack_1f0 = (byte ***)0x0;
    pppbStack_458 = param_2;
  }
  else {
    pppbStack_458 = (byte ***)0x0;
    do {
      pppbVar12 = (byte ***)((int)pppbVar7 + -1);
      pppbStack_1f0 = pppbStack_458;
      if ((pbVar4[-1] & 0xdf) != 0) break;
      pppbStack_458 = (byte ***)((int)pppbStack_458 + 1);
      pbVar4 = pbVar4 + -1;
      pppbVar7 = pppbVar12;
      pppbStack_1f0 = pppbStack_458;
    } while (pppbVar12 != (byte ***)0x0);
  }
  pppbStack_210 = param_2;
  pBStack_20c = param_1;
  if ((int)param_4 < 1) {
    iStack_264 = 0x10;
    pppbStack_270 = (byte ***)&stack0xffffffd8;
    appbStack_1d4[0]._0_1_ = 0;
    pppbStack_204 =
         (byte ***)((int)pppbVar7 / 0x10 + (uint)(((int)pppbVar7 / 0x10) * 0x10 < (int)pppbVar7));
  }
  else {
    pppbVar12 = (byte ***)&DAT_00000080;
    if ((int)param_4 < 0x81) {
      pppbVar12 = param_4;
    }
    param_4 = (byte ***)0x81;
    pppbStack_458 = (byte ***)&DAT_00000020;
    param_3 = pppbVar12;
    (*(code *)PTR___memset_chk_006a998c)(appbStack_1d4);
    pppbVar10 = (byte ***)&DAT_00000006;
    if ((int)pppbVar12 < 7) {
      pppbVar10 = pppbVar12;
    }
    pbVar4 = (byte *)((int)pppbVar12 + (3 - (int)pppbVar10));
    if ((int)pbVar4 < 0) {
      pbVar4 = (byte *)((int)pppbVar12 + (6 - (int)pppbVar10));
    }
    iStack_264 = 0x10 - ((int)pbVar4 >> 2);
    if (iStack_264 == 0) {
      trap(7);
    }
    pppbStack_270 = (byte ***)(&stack0xffffffd8 + (int)pppbVar12);
    *(byte *)((int)appbStack_1d4 + (int)pppbVar12) = 0;
    pppbStack_204 =
         (byte ***)
         ((int)pppbVar7 / iStack_264 +
         (uint)(((int)pppbVar7 / iStack_264) * iStack_264 < (int)pppbVar7));
  }
  if ((int)pppbStack_204 < 1) {
    iStack_218 = 0;
  }
  else {
    iStack_218 = 0;
    unaff_s6 = appbStack_1d4;
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
    pppbStack_220 = pppbStack_210;
    pppbStack_1f8 = unaff_s6;
    do {
      BUF_strlcpy((char *)unaff_s7,(char *)pppbStack_1f8,0x121);
      param_4 = unaff_s2;
      BIO_snprintf(unaff_s8,0x14,(char *)(iStack_200 + 0x7810));
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      if (iStack_264 < 1) {
        BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x4da8,0x121);
      }
      else {
        iVar9 = 0;
        pppbVar12 = pppbStack_220;
        do {
          while (pppbVar10 = pppbVar12, (int)((int)unaff_s2 + iVar9) < (int)pppbVar7) {
            param_4 = (byte ***)(uint)*(byte *)pppbVar10;
            pbStack_238 = &DAT_0000002d;
            if (iVar9 != 7) {
              pbStack_238 = &DAT_00000020;
            }
            iVar9 = iVar9 + 1;
            BIO_snprintf(unaff_s8,0x14,pcStack_224);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            pppbVar12 = (byte ***)((int)pppbVar10 + 1);
            if (iVar9 == iStack_264) goto LAB_005264bc;
          }
          iVar9 = iVar9 + 1;
          BUF_strlcat((char *)unaff_s7,pcStack_21c,0x121);
          pppbVar12 = (byte ***)((int)pppbVar10 + 1);
        } while (iVar9 != iStack_264);
LAB_005264bc:
        unaff_s4 = (byte *)((int)pppbVar10 + 1);
        BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x4da8,0x121);
        if ((int)unaff_s2 < (int)pppbVar7) {
          unaff_s5 = 0x2e;
          unaff_s6 = (byte ***)((int)pppbStack_210 + (int)pppbVar7);
          pppbVar10 = (byte ***)((int)pppbStack_210 + (int)((int)unaff_s2 + iStack_264 + -1));
          unaff_s4 = (byte *)(pcStack_1f4 + -0x6680);
          pppbVar12 = pppbStack_220;
          do {
            param_4 = (byte ***)(uint)*(byte *)pppbVar12;
            if ((byte ***)0x5e < param_4 + -8) {
              param_4 = (byte ***)0x2e;
            }
            BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
          } while ((pppbVar12 != pppbVar10) &&
                  (pppbVar12 = (byte ***)((int)pppbVar12 + 1), unaff_s6 != pppbVar12));
        }
      }
      unaff_s2 = (byte ***)((int)unaff_s2 + iStack_264);
      BUF_strlcat((char *)unaff_s7,pcStack_1fc + -0x4d1c,0x121);
      pppbStack_270 = (byte ***)((int)pppbStack_214 + 1);
      pppbStack_220 = (byte ***)((int)pppbStack_220 + iStack_264);
      pppbStack_214 = pppbStack_270;
      param_3 = (byte ***)(**(code **)(puStack_230 + -0x53bc))(unaff_s7);
      pppbStack_458 = unaff_s7;
      iVar9 = BIO_write(pBStack_20c,unaff_s7,(int)param_3);
      iStack_218 = iStack_218 + iVar9;
    } while (pppbStack_270 != pppbStack_204);
  }
  pbStack_26c = (byte *)((int)pppbStack_1f0 + (int)pppbVar7);
  if (pppbStack_1f0 != (byte ***)0x0) {
    pppbStack_270 = appbStack_150;
    param_4 = appbStack_1d4;
    pbStack_238 = pbStack_26c;
    BIO_snprintf((char *)pppbStack_270,0x121,"%s%04x - <SPACES/NULS>\n");
    param_3 = (byte ***)(**(code **)(puStack_230 + -0x53bc))(pppbStack_270);
    pppbStack_458 = pppbStack_270;
    iVar9 = BIO_write(pBStack_20c,pppbStack_270,(int)param_3);
    iStack_218 = iStack_218 + iVar9;
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
  pbVar4 = (byte *)((int)pppbStack_458 + (int)param_3);
  pppbStack_4b4 = param_3;
  if ((int)param_3 < 1) {
    pppbStack_438 = (byte ***)0x0;
    pppbVar7 = pppbStack_458;
  }
  else {
    pppbVar7 = (byte ***)0x0;
    do {
      pppbVar12 = (byte ***)((int)pppbStack_4b4 + -1);
      pppbStack_438 = pppbVar7;
      if ((pbVar4[-1] & 0xdf) != 0) break;
      pppbVar7 = (byte ***)((int)pppbVar7 + 1);
      pbVar4 = pbVar4 + -1;
      pppbStack_4b4 = pppbVar12;
      pppbStack_438 = pppbVar7;
    } while (pppbVar12 != (byte ***)0x0);
  }
  pppbStack_268 = unaff_s2;
  pbStack_260 = unaff_s4;
  uStack_25c = unaff_s5;
  pppbStack_258 = unaff_s6;
  pppbStack_254 = unaff_s7;
  pcStack_250 = unaff_s8;
  if ((int)param_4 < 1) {
    iStack_4ac = 0x10;
    pppbStack_4b8 = (byte ***)&pppbStack_270;
    appbStack_41c[0]._0_1_ = 0;
    pppbStack_44c =
         (byte ***)
         ((int)pppbStack_4b4 / 0x10 +
         (uint)(((int)pppbStack_4b4 / 0x10) * 0x10 < (int)pppbStack_4b4));
  }
  else {
    pppbVar12 = (byte ***)&DAT_00000080;
    if ((int)param_4 < 0x81) {
      pppbVar12 = param_4;
    }
    param_4 = (byte ***)0x81;
    pppbVar7 = (byte ***)&DAT_00000020;
    param_3 = pppbVar12;
    (*(code *)PTR___memset_chk_006a998c)(appbStack_41c);
    pppbVar10 = (byte ***)&DAT_00000006;
    if ((int)pppbVar12 < 7) {
      pppbVar10 = pppbVar12;
    }
    pbVar4 = (byte *)((int)pppbVar12 + (3 - (int)pppbVar10));
    if ((int)pbVar4 < 0) {
      pbVar4 = (byte *)((int)pppbVar12 + (6 - (int)pppbVar10));
    }
    iStack_4ac = 0x10 - ((int)pbVar4 >> 2);
    if (iStack_4ac == 0) {
      trap(7);
    }
    pppbStack_4b8 = (byte ***)((int)&pppbStack_270 + (int)pppbVar12);
    *(byte *)((int)appbStack_41c + (int)pppbVar12) = 0;
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
        iVar9 = 0;
        pppbVar7 = pppbStack_468;
        do {
          while (pppbVar12 = pppbVar7, (int)((int)unaff_s2 + iVar9) < (int)pppbStack_4b4) {
            pppbStack_480 = (byte ***)&DAT_0000002d;
            if (iVar9 != 7) {
              pppbStack_480 = (byte ***)&DAT_00000020;
            }
            iVar9 = iVar9 + 1;
            BIO_snprintf(unaff_s8,0x14,pcStack_46c,(uint)*(byte *)pppbVar12);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            pppbVar7 = (byte ***)((int)pppbVar12 + 1);
            if (iVar9 == iStack_4ac) goto LAB_00526950;
          }
          iVar9 = iVar9 + 1;
          BUF_strlcat((char *)unaff_s7,pcStack_464,0x121);
          pppbVar7 = (byte ***)((int)pppbVar12 + 1);
        } while (iVar9 != iStack_4ac);
LAB_00526950:
        unaff_s4 = (byte *)((int)pppbVar12 + 1);
        BUF_strlcat((char *)unaff_s7,pcStack_450 + -0x4da8,0x121);
        if ((int)unaff_s2 < (int)pppbStack_4b4) {
          unaff_s5 = 0x2e;
          unaff_s6 = (byte ***)((int)pppbStack_458 + (int)pppbStack_4b4);
          pppbVar12 = (byte ***)((int)pppbStack_458 + (int)((int)unaff_s2 + iStack_4ac + -1));
          unaff_s4 = (byte *)(pcStack_43c + -0x6680);
          pppbVar7 = pppbStack_468;
          pppbStack_240 = pppbStack_4b4;
          do {
            uVar8 = (uint)*(byte *)pppbVar7;
            if (0x5e < uVar8 - 0x20) {
              uVar8 = 0x2e;
            }
            BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4,uVar8);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
            pppbStack_4b4 = pppbStack_240;
          } while ((pppbVar7 != pppbVar12) &&
                  (pppbVar7 = (byte ***)((int)pppbVar7 + 1), unaff_s6 != pppbVar7));
        }
      }
      unaff_s2 = (byte ***)((int)unaff_s2 + iStack_4ac);
      BUF_strlcat((char *)unaff_s7,pcStack_444 + -0x4d1c,0x121);
      pppbStack_4b8 = (byte ***)((int)pppbStack_45c + 1);
      pppbStack_468 = (byte ***)((int)pppbStack_468 + iStack_4ac);
      pppbStack_45c = pppbStack_4b8;
      pppbVar7 = (byte ***)(**(code **)(puStack_478 + -0x53bc))(unaff_s7);
      param_3 = (byte ***)0x1;
      param_4 = pppbStack_454;
      iVar9 = (**(code **)(puStack_478 + -0x536c))(unaff_s7);
      iStack_460 = iStack_460 + iVar9;
    } while (pppbStack_4b8 != pppbStack_44c);
  }
  pppbStack_4b4 = (byte ***)((int)pppbStack_438 + (int)pppbStack_4b4);
  if (pppbStack_438 != (byte ***)0x0) {
    pppbStack_4b8 = appbStack_398;
    pppbStack_480 = pppbStack_4b4;
    BIO_snprintf((char *)pppbStack_4b8,0x121,"%s%04x - <SPACES/NULS>\n",appbStack_41c);
    pppbVar7 = (byte ***)(**(code **)(puStack_478 + -0x53bc))(pppbStack_4b8);
    param_3 = (byte ***)0x1;
    param_4 = pppbStack_454;
    iVar9 = (**(code **)(puStack_478 + -0x536c))(pppbStack_4b8);
    iStack_460 = iStack_460 + iVar9;
  }
  if (pcStack_274 == *ppcStack_434) {
    return iStack_460;
  }
  pcStack_494 = BIO_dump_indent_cb;
  pcVar6 = pcStack_274;
  (**(code **)(puStack_478 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcStack_4bc = *(cb **)PTR___stack_chk_guard_006a9ae8;
  pbVar4 = (byte *)((int)param_3 + (int)param_4);
  if ((int)param_4 < 1) {
    pppbStack_680 = (byte ***)0x0;
    pppbVar12 = pppbVar7;
  }
  else {
    pppbVar12 = (byte ***)0x0;
    do {
      pppbVar10 = (byte ***)((int)param_4 + -1);
      pppbStack_680 = pppbVar12;
      if ((pbVar4[-1] & 0xdf) != 0) break;
      pppbVar12 = (byte ***)((int)pppbVar12 + 1);
      pbVar4 = pbVar4 + -1;
      param_4 = pppbVar10;
      pppbStack_680 = pppbVar12;
    } while (pppbVar10 != (byte ***)0x0);
  }
  pppbStack_4b0 = unaff_s2;
  pbStack_4a8 = unaff_s4;
  uStack_4a4 = unaff_s5;
  pppbStack_4a0 = unaff_s6;
  pppbStack_49c = unaff_s7;
  pcStack_498 = unaff_s8;
  if ((int)pppbStack_480 < 1) {
    iVar9 = 0x10;
    appbStack_664[0]._0_1_ = 0;
    iVar2 = (int)param_4 / 0x10 + (uint)(((int)param_4 / 0x10) * 0x10 < (int)param_4);
    pppbVar10 = param_3;
    len = pppbStack_480;
  }
  else {
    pppbVar13 = (byte ***)&DAT_00000080;
    if ((int)pppbStack_480 < 0x81) {
      pppbVar13 = pppbStack_480;
    }
    len = (byte ***)0x81;
    pppbVar12 = (byte ***)&DAT_00000020;
    pppbVar10 = pppbVar13;
    (*(code *)PTR___memset_chk_006a998c)(appbStack_664);
    pppbVar5 = (byte ***)&DAT_00000006;
    if ((int)pppbVar13 < 7) {
      pppbVar5 = pppbVar13;
    }
    pbVar4 = (byte *)((int)pppbVar13 + (3 - (int)pppbVar5));
    if ((int)pbVar4 < 0) {
      pbVar4 = (byte *)((int)pppbVar13 + (6 - (int)pppbVar5));
    }
    iVar9 = 0x10 - ((int)pbVar4 >> 2);
    if (iVar9 == 0) {
      trap(7);
    }
    *(byte *)((int)appbStack_664 + (int)pppbVar13) = 0;
    iVar2 = (int)param_4 / iVar9 + (uint)(((int)param_4 / iVar9) * iVar9 < (int)param_4);
  }
  if (iVar2 < 1) {
    iStack_6ac = 0;
  }
  else {
    iStack_6a8 = 0;
    iStack_6ac = 0;
    pppbVar13 = (byte ***)0x0;
    pppbStack_6b4 = param_3;
    do {
      BUF_strlcpy(acStack_5e0,(char *)appbStack_664,0x121);
      len = pppbVar13;
      BIO_snprintf(acStack_678,0x14,"%04x - ");
      BUF_strlcat(acStack_5e0,acStack_678,0x121);
      if (iVar9 < 1) {
        BUF_strlcat(acStack_5e0,"  ",0x121);
      }
      else {
        iVar11 = 0;
        pppbVar12 = pppbStack_6b4;
        do {
          while ((int)((int)pppbVar13 + iVar11) < (int)param_4) {
            len = (byte ***)(uint)*(byte *)pppbVar12;
            uVar3 = 0x2d;
            if (iVar11 != 7) {
              uVar3 = 0x20;
            }
            iVar11 = iVar11 + 1;
            pppbVar12 = (byte ***)((int)pppbVar12 + 1);
            BIO_snprintf(acStack_678,0x14,"%02x%c",len,uVar3);
            BUF_strlcat(acStack_5e0,acStack_678,0x121);
            if (iVar11 == iVar9) goto LAB_00526df4;
          }
          iVar11 = iVar11 + 1;
          pppbVar12 = (byte ***)((int)pppbVar12 + 1);
          BUF_strlcat(acStack_5e0,"   ",0x121);
        } while (iVar11 != iVar9);
LAB_00526df4:
        BUF_strlcat(acStack_5e0,"  ",0x121);
        if ((int)pppbVar13 < (int)param_4) {
          pppbVar10 = (byte ***)((int)param_3 + (int)param_4);
          pppbVar12 = pppbStack_6b4;
          pppbStack_484 = param_4;
          do {
            len = (byte ***)(uint)*(byte *)pppbVar12;
            if ((byte ***)0x5e < len + -8) {
              len = (byte ***)0x2e;
            }
            BIO_snprintf(acStack_678,0x14,"%c");
            BUF_strlcat(acStack_5e0,acStack_678,0x121);
            param_4 = pppbStack_484;
          } while ((pppbVar12 != (byte ***)((int)param_3 + (int)((int)pppbVar13 + iVar9 + -1))) &&
                  (pppbVar12 = (byte ***)((int)pppbVar12 + 1), pppbVar10 != pppbVar12));
        }
      }
      pppbVar13 = (byte ***)((int)pppbVar13 + iVar9);
      BUF_strlcat(acStack_5e0,"\n",0x121);
      iStack_6a8 = iStack_6a8 + 1;
      pppbStack_6b4 = (byte ***)((int)pppbStack_6b4 + iVar9);
      pppbVar12 = (byte ***)(*(code *)PTR_strlen_006a9a24)(acStack_5e0);
      pppbVar10 = pppbVar7;
      iVar11 = (*pcVar6)(acStack_5e0);
      iStack_6ac = iStack_6ac + iVar11;
    } while (iVar2 != iStack_6a8);
  }
  if (pppbStack_680 != (byte ***)0x0) {
    len = appbStack_664;
    BIO_snprintf(acStack_5e0,0x121,"%s%04x - <SPACES/NULS>\n",len,
                 (byte *)((int)param_4 + (int)pppbStack_680));
    pppbVar12 = (byte ***)(*(code *)PTR_strlen_006a9a24)(acStack_5e0);
    iVar9 = (*pcVar6)(acStack_5e0);
    iStack_6ac = iStack_6ac + iVar9;
    pppbVar10 = pppbVar7;
  }
  if (pcStack_4bc != *(cb **)puVar1) {
    cb = pcStack_4bc;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar9 = BIO_dump_indent_cb(cb,pppbVar12,(char *)pppbVar10,(int)len,0);
    return iVar9;
  }
  return iStack_6ac;
}

