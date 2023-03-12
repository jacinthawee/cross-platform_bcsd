
/* WARNING: Removing unreachable block (ram,0x00529f78) */
/* WARNING: Removing unreachable block (ram,0x0052a410) */

int BIO_dump_indent_fp(byte *param_1,byte *param_2,byte *param_3,byte *param_4)

{
  undefined *puVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  code *pcVar7;
  cb *cb;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  int unaff_s2;
  byte *unaff_s4;
  undefined4 unaff_s5;
  byte *unaff_s6;
  byte *unaff_s7;
  char *unaff_s8;
  byte *pbStack_46c;
  int iStack_464;
  int iStack_460;
  byte *pbStack_438;
  char acStack_430 [20];
  byte abStack_41c [132];
  char acStack_398 [292];
  cb *pcStack_274;
  byte *pbStack_270;
  byte *pbStack_26c;
  int iStack_268;
  int iStack_264;
  byte *pbStack_260;
  undefined4 uStack_25c;
  byte *pbStack_258;
  byte *pbStack_254;
  char *pcStack_250;
  code *pcStack_24c;
  byte *pbStack_23c;
  byte *pbStack_238;
  undefined *puStack_230;
  char *pcStack_224;
  byte *pbStack_220;
  char *pcStack_21c;
  int iStack_218;
  byte *pbStack_214;
  byte *pbStack_210;
  byte *pbStack_20c;
  char *pcStack_208;
  byte *pbStack_204;
  char *pcStack_200;
  char *pcStack_1fc;
  byte *pbStack_1f8;
  char *pcStack_1f4;
  byte *pbStack_1f0;
  code **ppcStack_1ec;
  char acStack_1e8 [20];
  byte abStack_1d4 [132];
  byte abStack_150 [292];
  code *pcStack_2c;
  
  ppcStack_1ec = (code **)PTR___stack_chk_guard_006aabf0;
  puStack_230 = &_gp;
  pcStack_2c = *(code **)PTR___stack_chk_guard_006aabf0;
  pbVar5 = param_2 + (int)param_3;
  pbStack_26c = param_3;
  if ((int)param_3 < 1) {
    pbStack_1f0 = (byte *)0x0;
    pbVar8 = param_2;
  }
  else {
    pbVar8 = (byte *)0x0;
    do {
      pbVar12 = pbStack_26c + -1;
      pbStack_1f0 = pbVar8;
      if ((pbVar5[-1] & 0xdf) != 0) break;
      pbVar8 = pbVar8 + 1;
      pbVar5 = pbVar5 + -1;
      pbStack_26c = pbVar12;
      pbStack_1f0 = pbVar8;
    } while (pbVar12 != (byte *)0x0);
  }
  pbStack_210 = param_2;
  pbStack_20c = param_1;
  if ((int)param_4 < 1) {
    iStack_264 = 0x10;
    pbStack_270 = &stack0xffffffd8;
    abStack_1d4[0] = 0;
    pbStack_204 = (byte *)((int)pbStack_26c / 0x10 +
                          (uint)(((int)pbStack_26c / 0x10) * 0x10 < (int)pbStack_26c));
  }
  else {
    pbVar5 = &DAT_00000080;
    if ((int)param_4 < 0x81) {
      pbVar5 = param_4;
    }
    param_4 = (byte *)0x81;
    pbVar8 = &DAT_00000020;
    param_3 = pbVar5;
    (*(code *)PTR___memset_chk_006aaa98)(abStack_1d4);
    pbVar12 = &DAT_00000006;
    if ((int)pbVar5 < 7) {
      pbVar12 = pbVar5;
    }
    pbVar13 = pbVar5 + (3 - (int)pbVar12);
    if ((int)(pbVar5 + (3 - (int)pbVar12)) < 0) {
      pbVar13 = pbVar5 + (6 - (int)pbVar12);
    }
    iStack_264 = 0x10 - ((int)pbVar13 >> 2);
    if (iStack_264 == 0) {
      trap(7);
    }
    pbStack_270 = &stack0xffffffd8 + (int)pbVar5;
    abStack_1d4[(int)pbVar5] = 0;
    pbStack_204 = (byte *)((int)pbStack_26c / iStack_264 +
                          (uint)(((int)pbStack_26c / iStack_264) * iStack_264 < (int)pbStack_26c));
  }
  if ((int)pbStack_204 < 1) {
    iStack_218 = 0;
  }
  else {
    iStack_218 = 0;
    unaff_s6 = abStack_1d4;
    pbStack_214 = (byte *)0x0;
    unaff_s2 = 0;
    pcStack_200 = "r";
    unaff_s7 = abStack_150;
    unaff_s8 = acStack_1e8;
    pcStack_1fc = "s\n";
    pcStack_208 = "s\n";
    pcStack_224 = "%02x%c";
    pcStack_21c = "   ";
    pcStack_1f4 = "r";
    pbStack_220 = pbStack_210;
    pbStack_1f8 = unaff_s6;
    do {
      abStack_150[0] = 0;
      BUF_strlcpy((char *)unaff_s7,(char *)pbStack_1f8,0x121);
      BIO_snprintf(unaff_s8,0x14,pcStack_200 + -0x7d30,unaff_s2);
      BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
      if (iStack_264 < 1) {
        BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x45c4,0x121);
      }
      else {
        iVar10 = 0;
        pbVar5 = pbStack_220;
        do {
          while (pbVar8 = pbVar5, (int)pbStack_26c <= iVar10 + unaff_s2) {
            iVar10 = iVar10 + 1;
            BUF_strlcat((char *)unaff_s7,pcStack_21c,0x121);
            pbVar5 = pbVar8 + 1;
            if (iVar10 == iStack_264) goto LAB_00529d78;
          }
          pbStack_238 = &DAT_0000002d;
          if (iVar10 != 7) {
            pbStack_238 = &DAT_00000020;
          }
          iVar10 = iVar10 + 1;
          BIO_snprintf(unaff_s8,0x14,pcStack_224,(uint)*pbVar8);
          BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
          pbVar5 = pbVar8 + 1;
        } while (iVar10 != iStack_264);
LAB_00529d78:
        unaff_s4 = pbVar8 + 1;
        BUF_strlcat((char *)unaff_s7,pcStack_208 + -0x45c4,0x121);
        if (unaff_s2 < (int)pbStack_26c) {
          unaff_s5 = 0x2e;
          unaff_s6 = pbStack_210 + (int)pbStack_26c;
          pbVar8 = pbStack_210 + iStack_264 + -1 + unaff_s2;
          unaff_s4 = (byte *)(pcStack_1f4 + -0x5bd0);
          pbVar5 = pbStack_220;
          do {
            uVar9 = (uint)*pbVar5;
            if (0x5e < uVar9 - 0x20) {
              uVar9 = 0x2e;
            }
            BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4,uVar9);
            BUF_strlcat((char *)unaff_s7,unaff_s8,0x121);
          } while ((pbVar5 != pbVar8) && (pbVar5 = pbVar5 + 1, unaff_s6 != pbVar5));
        }
      }
      unaff_s2 = unaff_s2 + iStack_264;
      BUF_strlcat((char *)unaff_s7,pcStack_1fc + -0x4538,0x121);
      pbStack_270 = pbStack_214 + 1;
      pbStack_220 = pbStack_220 + iStack_264;
      pbStack_214 = pbStack_270;
      pbVar8 = (byte *)(**(code **)(puStack_230 + -0x53b0))(unaff_s7);
      param_3 = (byte *)0x1;
      param_4 = pbStack_20c;
      iVar10 = (**(code **)(puStack_230 + -0x5364))(unaff_s7);
      iStack_218 = iStack_218 + iVar10;
    } while (pbStack_270 != pbStack_204);
  }
  pbStack_26c = pbStack_1f0 + (int)pbStack_26c;
  if (pbStack_1f0 != (byte *)0x0) {
    pbStack_270 = abStack_150;
    pbStack_238 = pbStack_26c;
    BIO_snprintf((char *)pbStack_270,0x121,"%s%04x - <SPACES/NULS>\n",abStack_1d4);
    pbVar8 = (byte *)(**(code **)(puStack_230 + -0x53b0))(pbStack_270);
    param_3 = (byte *)0x1;
    param_4 = pbStack_20c;
    iVar10 = (**(code **)(puStack_230 + -0x5364))(pbStack_270);
    iStack_218 = iStack_218 + iVar10;
  }
  if (pcStack_2c == *ppcStack_1ec) {
    return iStack_218;
  }
  pcStack_24c = BIO_dump_indent_cb;
  pcVar7 = pcStack_2c;
  (**(code **)(puStack_230 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcStack_274 = *(cb **)PTR___stack_chk_guard_006aabf0;
  pbVar5 = param_3 + (int)param_4;
  if ((int)param_4 < 1) {
    pbStack_438 = (byte *)0x0;
    pbVar12 = pbVar8;
  }
  else {
    pbVar12 = (byte *)0x0;
    do {
      pbVar13 = param_4 + -1;
      pbStack_438 = pbVar12;
      if ((pbVar5[-1] & 0xdf) != 0) break;
      pbVar12 = pbVar12 + 1;
      pbVar5 = pbVar5 + -1;
      param_4 = pbVar13;
      pbStack_438 = pbVar12;
    } while (pbVar13 != (byte *)0x0);
  }
  iStack_268 = unaff_s2;
  pbStack_260 = unaff_s4;
  uStack_25c = unaff_s5;
  pbStack_258 = unaff_s6;
  pbStack_254 = unaff_s7;
  pcStack_250 = unaff_s8;
  if ((int)pbStack_238 < 1) {
    iVar10 = 0x10;
    abStack_41c[0] = 0;
    iVar3 = (int)param_4 / 0x10 + (uint)(((int)param_4 / 0x10) * 0x10 < (int)param_4);
    pbVar5 = param_3;
    pbVar13 = pbStack_238;
  }
  else {
    pbVar14 = &DAT_00000080;
    if ((int)pbStack_238 < 0x81) {
      pbVar14 = pbStack_238;
    }
    pbVar13 = (byte *)0x81;
    pbVar12 = &DAT_00000020;
    pbVar5 = pbVar14;
    (*(code *)PTR___memset_chk_006aaa98)(abStack_41c);
    pbVar6 = &DAT_00000006;
    if ((int)pbVar14 < 7) {
      pbVar6 = pbVar14;
    }
    pbVar2 = pbVar14 + (3 - (int)pbVar6);
    if ((int)(pbVar14 + (3 - (int)pbVar6)) < 0) {
      pbVar2 = pbVar14 + (6 - (int)pbVar6);
    }
    iVar10 = 0x10 - ((int)pbVar2 >> 2);
    if (iVar10 == 0) {
      trap(7);
    }
    abStack_41c[(int)pbVar14] = 0;
    iVar3 = (int)param_4 / iVar10 + (uint)(((int)param_4 / iVar10) * iVar10 < (int)param_4);
  }
  if (iVar3 < 1) {
    iStack_464 = 0;
  }
  else {
    iStack_460 = 0;
    iStack_464 = 0;
    pbVar14 = (byte *)0x0;
    pbStack_46c = param_3;
    do {
      acStack_398[0] = '\0';
      BUF_strlcpy(acStack_398,(char *)abStack_41c,0x121);
      pbVar13 = pbVar14;
      BIO_snprintf(acStack_430,0x14,"%04x - ");
      BUF_strlcat(acStack_398,acStack_430,0x121);
      if (iVar10 < 1) {
        BUF_strlcat(acStack_398,"  ",0x121);
      }
      else {
        iVar11 = 0;
        pbVar5 = pbStack_46c;
        do {
          while ((int)param_4 <= (int)(pbVar14 + iVar11)) {
            iVar11 = iVar11 + 1;
            pbVar5 = pbVar5 + 1;
            BUF_strlcat(acStack_398,"   ",0x121);
            if (iVar11 == iVar10) goto LAB_0052a220;
          }
          pbVar13 = (byte *)(uint)*pbVar5;
          uVar4 = 0x2d;
          if (iVar11 != 7) {
            uVar4 = 0x20;
          }
          iVar11 = iVar11 + 1;
          pbVar5 = pbVar5 + 1;
          BIO_snprintf(acStack_430,0x14,"%02x%c",pbVar13,uVar4);
          BUF_strlcat(acStack_398,acStack_430,0x121);
        } while (iVar11 != iVar10);
LAB_0052a220:
        BUF_strlcat(acStack_398,"  ",0x121);
        if ((int)pbVar14 < (int)param_4) {
          pbVar12 = param_3 + (int)param_4;
          pbVar5 = pbStack_46c;
          pbStack_23c = param_4;
          do {
            pbVar13 = (byte *)(uint)*pbVar5;
            if ((byte *)0x5e < pbVar13 + -0x20) {
              pbVar13 = (byte *)0x2e;
            }
            BIO_snprintf(acStack_430,0x14,"%c");
            BUF_strlcat(acStack_398,acStack_430,0x121);
            param_4 = pbStack_23c;
          } while ((pbVar5 != param_3 + (int)(pbVar14 + iVar10 + -1)) &&
                  (pbVar5 = pbVar5 + 1, pbVar12 != pbVar5));
        }
      }
      pbVar14 = pbVar14 + iVar10;
      BUF_strlcat(acStack_398,"\n",0x121);
      iStack_460 = iStack_460 + 1;
      pbStack_46c = pbStack_46c + iVar10;
      pbVar12 = (byte *)(*(code *)PTR_strlen_006aab30)(acStack_398);
      pbVar5 = pbVar8;
      iVar11 = (*pcVar7)(acStack_398);
      iStack_464 = iStack_464 + iVar11;
    } while (iVar3 != iStack_460);
  }
  if (pbStack_438 != (byte *)0x0) {
    pbVar13 = abStack_41c;
    BIO_snprintf(acStack_398,0x121,"%s%04x - <SPACES/NULS>\n",pbVar13,param_4 + (int)pbStack_438);
    pbVar12 = (byte *)(*(code *)PTR_strlen_006aab30)(acStack_398);
    iVar10 = (*pcVar7)(acStack_398);
    iStack_464 = iStack_464 + iVar10;
    pbVar5 = pbVar8;
  }
  if (pcStack_274 == *(cb **)puVar1) {
    return iStack_464;
  }
  cb = pcStack_274;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar10 = BIO_dump_indent_cb(cb,pbVar12,(char *)pbVar5,(int)pbVar13,0);
  return iVar10;
}

