
/* WARNING: Removing unreachable block (ram,0x00529bb8) */
/* WARNING: Removing unreachable block (ram,0x00529bc0) */
/* WARNING: Removing unreachable block (ram,0x00529bc4) */
/* WARNING: Removing unreachable block (ram,0x00529be4) */
/* WARNING: Removing unreachable block (ram,0x00529be8) */
/* WARNING: Removing unreachable block (ram,0x00529bf8) */
/* WARNING: Removing unreachable block (ram,0x00529bfc) */
/* WARNING: Removing unreachable block (ram,0x00529c0c) */
/* WARNING: Removing unreachable block (ram,0x00529c10) */
/* WARNING: Removing unreachable block (ram,0x00529f78) */
/* WARNING: Removing unreachable block (ram,0x0052a410) */
/* WARNING: Removing unreachable block (ram,0x00529f50) */

int BIO_dump_fp(FILE *fp,char *s,int len)

{
  undefined *puVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  char *pcVar5;
  byte *pbVar6;
  code *pcVar7;
  cb *cb;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  byte *len_00;
  FILE *pFVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  FILE *pFVar15;
  byte *pbVar16;
  int unaff_s2;
  byte *unaff_s4;
  undefined4 unaff_s5;
  byte *unaff_s6;
  char *unaff_s7;
  char *unaff_s8;
  byte *pbStack_46c;
  int iStack_464;
  int iStack_460;
  byte *pbStack_438;
  char acStack_430 [20];
  byte abStack_41c [132];
  char acStack_398 [292];
  cb *pcStack_274;
  char *pcStack_270;
  byte *pbStack_26c;
  int iStack_268;
  undefined4 uStack_264;
  byte *pbStack_260;
  undefined4 uStack_25c;
  byte *pbStack_258;
  char *pcStack_254;
  char *pcStack_250;
  code *pcStack_24c;
  FILE *pFStack_23c;
  byte *pbStack_238;
  undefined *puStack_230;
  char *pcStack_224;
  byte *pbStack_220;
  char *pcStack_21c;
  int iStack_218;
  char *pcStack_214;
  char *pcStack_210;
  FILE *pFStack_20c;
  char *pcStack_208;
  char *pcStack_204;
  char *pcStack_200;
  char *pcStack_1fc;
  byte *pbStack_1f8;
  char *pcStack_1f4;
  byte *pbStack_1f0;
  code **ppcStack_1ec;
  char acStack_1e8 [20];
  byte abStack_1d4 [132];
  char acStack_150 [292];
  code *pcStack_2c;
  
  pFVar11 = (FILE *)0x0;
  ppcStack_1ec = (code **)PTR___stack_chk_guard_006aabf0;
  puStack_230 = &_gp;
  pcStack_2c = *(code **)PTR___stack_chk_guard_006aabf0;
  pcVar5 = s + len;
  iVar2 = len;
  if (len < 1) {
    pbStack_1f0 = (byte *)0x0;
    pbVar8 = (byte *)s;
  }
  else {
    pbVar8 = (byte *)0x0;
    do {
      iVar14 = iVar2 + -1;
      pbStack_1f0 = pbVar8;
      if ((pcVar5[-1] & 0xdfU) != 0) break;
      pbVar8 = pbVar8 + 1;
      pcVar5 = pcVar5 + -1;
      iVar2 = iVar14;
      pbStack_1f0 = pbVar8;
    } while (iVar14 != 0);
  }
  pcStack_270 = &stack0xffffffd8;
  abStack_1d4[0] = 0;
  pcStack_204 = (char *)(iVar2 / 0x10 + (uint)((iVar2 / 0x10) * 0x10 < iVar2));
  pcStack_210 = s;
  pFStack_20c = fp;
  if ((int)pcStack_204 < 1) {
    iStack_218 = 0;
  }
  else {
    iStack_218 = 0;
    unaff_s6 = abStack_1d4;
    pcStack_214 = (char *)0x0;
    unaff_s2 = 0;
    pcStack_200 = "7 datafinal";
    unaff_s7 = acStack_150;
    unaff_s8 = acStack_1e8;
    pcStack_1fc = "s\n";
    pcStack_208 = "s\n";
    pcStack_224 = "%02x%c";
    pcStack_21c = "   ";
    pcStack_1f4 = "7 datafinal";
    pbStack_220 = (byte *)s;
    pbStack_1f8 = unaff_s6;
    do {
      acStack_150[0] = '\0';
      BUF_strlcpy(unaff_s7,(char *)pbStack_1f8,0x121);
      BIO_snprintf(unaff_s8,0x14,pcStack_200 + -0x7d10,unaff_s2);
      BUF_strlcat(unaff_s7,unaff_s8,0x121);
      iVar14 = 0;
      pbVar8 = pbStack_220;
      do {
        while (pbVar12 = pbVar8, iVar14 + unaff_s2 < iVar2) {
          pbStack_238 = &DAT_0000002d;
          if (iVar14 != 7) {
            pbStack_238 = &DAT_00000020;
          }
          iVar14 = iVar14 + 1;
          BIO_snprintf(unaff_s8,0x14,pcStack_224,(uint)*pbVar12);
          BUF_strlcat(unaff_s7,unaff_s8,0x121);
          pbVar8 = pbVar12 + 1;
          if (iVar14 == 0x10) goto LAB_00529d78;
        }
        iVar14 = iVar14 + 1;
        BUF_strlcat(unaff_s7,pcStack_21c,0x121);
        pbVar8 = pbVar12 + 1;
      } while (iVar14 != 0x10);
LAB_00529d78:
      unaff_s4 = pbVar12 + 1;
      BUF_strlcat(unaff_s7,pcStack_208 + -0x45c4,0x121);
      if (unaff_s2 < iVar2) {
        unaff_s5 = 0x2e;
        unaff_s6 = (byte *)(pcStack_210 + iVar2);
        pbVar12 = (byte *)(pcStack_210 + unaff_s2 + 0xf);
        unaff_s4 = (byte *)(pcStack_1f4 + -0x5bb0);
        pbVar8 = pbStack_220;
        do {
          uVar10 = (uint)*pbVar8;
          if (0x5e < uVar10 - 0x20) {
            uVar10 = 0x2e;
          }
          BIO_snprintf(unaff_s8,0x14,(char *)unaff_s4,uVar10);
          BUF_strlcat(unaff_s7,unaff_s8,0x121);
        } while ((pbVar8 != pbVar12) && (pbVar8 = pbVar8 + 1, unaff_s6 != pbVar8));
      }
      unaff_s2 = unaff_s2 + 0x10;
      BUF_strlcat(unaff_s7,pcStack_1fc + -0x4538,0x121);
      pcStack_270 = pcStack_214 + 1;
      pbStack_220 = pbStack_220 + 0x10;
      pcStack_214 = pcStack_270;
      pbVar8 = (byte *)(**(code **)(puStack_230 + -0x53b0))(unaff_s7);
      len = 1;
      pFVar11 = pFStack_20c;
      iVar14 = (**(code **)(puStack_230 + -0x5364))(unaff_s7);
      iStack_218 = iStack_218 + iVar14;
    } while (pcStack_270 != pcStack_204);
  }
  uStack_264 = 0x10;
  pbStack_26c = pbStack_1f0 + iVar2;
  if (pbStack_1f0 != (byte *)0x0) {
    pcStack_270 = acStack_150;
    pbStack_238 = pbStack_26c;
    BIO_snprintf(pcStack_270,0x121,"%s%04x - <SPACES/NULS>\n",abStack_1d4);
    pbVar8 = (byte *)(**(code **)(puStack_230 + -0x53b0))(pcStack_270);
    len = 1;
    pFVar11 = pFStack_20c;
    iVar2 = (**(code **)(puStack_230 + -0x5364))(pcStack_270);
    iStack_218 = iStack_218 + iVar2;
  }
  if (pcStack_2c == *ppcStack_1ec) {
    return iStack_218;
  }
  pcStack_24c = BIO_dump_indent_cb;
  pcVar7 = pcStack_2c;
  (**(code **)(puStack_230 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcStack_274 = *(cb **)PTR___stack_chk_guard_006aabf0;
  pbVar12 = (byte *)(len + (int)pFVar11);
  if ((int)pFVar11 < 1) {
    pbStack_438 = (byte *)0x0;
    pbVar9 = pbVar8;
  }
  else {
    pbVar9 = (byte *)0x0;
    do {
      pFVar15 = (FILE *)(pFVar11[-1]._unused2 + 0x27);
      pbStack_438 = pbVar9;
      if ((pbVar12[-1] & 0xdf) != 0) break;
      pbVar9 = pbVar9 + 1;
      pbVar12 = pbVar12 + -1;
      pFVar11 = pFVar15;
      pbStack_438 = pbVar9;
    } while (pFVar15 != (FILE *)0x0);
  }
  iStack_268 = unaff_s2;
  pbStack_260 = unaff_s4;
  uStack_25c = unaff_s5;
  pbStack_258 = unaff_s6;
  pcStack_254 = unaff_s7;
  pcStack_250 = unaff_s8;
  if ((int)pbStack_238 < 1) {
    iVar2 = 0x10;
    abStack_41c[0] = 0;
    iVar14 = (int)pFVar11 / 0x10 + (uint)(((int)pFVar11 / 0x10) * 0x10 < (int)pFVar11);
    pbVar12 = (byte *)len;
    len_00 = pbStack_238;
  }
  else {
    pbVar16 = &DAT_00000080;
    if ((int)pbStack_238 < 0x81) {
      pbVar16 = pbStack_238;
    }
    len_00 = (byte *)0x81;
    pbVar9 = &DAT_00000020;
    pbVar12 = pbVar16;
    (*(code *)PTR___memset_chk_006aaa98)(abStack_41c);
    pbVar6 = &DAT_00000006;
    if ((int)pbVar16 < 7) {
      pbVar6 = pbVar16;
    }
    pbVar3 = pbVar16 + (3 - (int)pbVar6);
    if ((int)(pbVar16 + (3 - (int)pbVar6)) < 0) {
      pbVar3 = pbVar16 + (6 - (int)pbVar6);
    }
    iVar2 = 0x10 - ((int)pbVar3 >> 2);
    if (iVar2 == 0) {
      trap(7);
    }
    abStack_41c[(int)pbVar16] = 0;
    iVar14 = (int)pFVar11 / iVar2 + (uint)(((int)pFVar11 / iVar2) * iVar2 < (int)pFVar11);
  }
  if (iVar14 < 1) {
    iStack_464 = 0;
  }
  else {
    iStack_460 = 0;
    iStack_464 = 0;
    pbVar16 = (byte *)0x0;
    pbStack_46c = (byte *)len;
    do {
      acStack_398[0] = '\0';
      BUF_strlcpy(acStack_398,(char *)abStack_41c,0x121);
      len_00 = pbVar16;
      BIO_snprintf(acStack_430,0x14,"%04x - ");
      BUF_strlcat(acStack_398,acStack_430,0x121);
      if (iVar2 < 1) {
        BUF_strlcat(acStack_398,"  ",0x121);
      }
      else {
        iVar13 = 0;
        pbVar12 = pbStack_46c;
        do {
          while ((int)(pbVar16 + iVar13) < (int)pFVar11) {
            len_00 = (byte *)(uint)*pbVar12;
            uVar4 = 0x2d;
            if (iVar13 != 7) {
              uVar4 = 0x20;
            }
            iVar13 = iVar13 + 1;
            pbVar12 = pbVar12 + 1;
            BIO_snprintf(acStack_430,0x14,"%02x%c",len_00,uVar4);
            BUF_strlcat(acStack_398,acStack_430,0x121);
            if (iVar13 == iVar2) goto LAB_0052a220;
          }
          iVar13 = iVar13 + 1;
          pbVar12 = pbVar12 + 1;
          BUF_strlcat(acStack_398,"   ",0x121);
        } while (iVar13 != iVar2);
LAB_0052a220:
        BUF_strlcat(acStack_398,"  ",0x121);
        if ((int)pbVar16 < (int)pFVar11) {
          pbVar9 = (byte *)(len + (int)pFVar11);
          pbVar12 = pbStack_46c;
          pFStack_23c = pFVar11;
          do {
            len_00 = (byte *)(uint)*pbVar12;
            if ((byte *)0x5e < len_00 + -0x20) {
              len_00 = (byte *)0x2e;
            }
            BIO_snprintf(acStack_430,0x14,"%c");
            BUF_strlcat(acStack_398,acStack_430,0x121);
            pFVar11 = pFStack_23c;
          } while ((pbVar12 != (byte *)(len + (int)(pbVar16 + iVar2 + -1))) &&
                  (pbVar12 = pbVar12 + 1, pbVar9 != pbVar12));
        }
      }
      pbVar16 = pbVar16 + iVar2;
      BUF_strlcat(acStack_398,"\n",0x121);
      iStack_460 = iStack_460 + 1;
      pbStack_46c = pbStack_46c + iVar2;
      pbVar9 = (byte *)(*(code *)PTR_strlen_006aab30)(acStack_398);
      pbVar12 = pbVar8;
      iVar13 = (*pcVar7)(acStack_398);
      iStack_464 = iStack_464 + iVar13;
    } while (iVar14 != iStack_460);
  }
  if (pbStack_438 != (byte *)0x0) {
    len_00 = abStack_41c;
    BIO_snprintf(acStack_398,0x121,"%s%04x - <SPACES/NULS>\n",len_00,
                 pbStack_438 + (int)(pFVar11->_shortbuf + -0x47));
    pbVar9 = (byte *)(*(code *)PTR_strlen_006aab30)(acStack_398);
    iVar2 = (*pcVar7)(acStack_398);
    iStack_464 = iStack_464 + iVar2;
    pbVar12 = pbVar8;
  }
  if (pcStack_274 != *(cb **)puVar1) {
    cb = pcStack_274;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar2 = BIO_dump_indent_cb(cb,pbVar9,(char *)pbVar12,(int)len_00,0);
    return iVar2;
  }
  return iStack_464;
}

