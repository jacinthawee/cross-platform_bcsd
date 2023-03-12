
void BIO_dump_indent(BIO *param_1,byte *param_2,int param_3,int param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  int iStack_204;
  int iStack_1fc;
  uint uStack_1ec;
  char acStack_1e8 [20];
  char acStack_1d4 [132];
  char acStack_150 [292];
  int iStack_2c;
  byte *pbVar11;
  
  iStack_2c = __stack_chk_guard;
  iVar4 = param_3;
  if (param_3 < 1) {
    uStack_1ec = 0;
  }
  else {
    uStack_1ec = param_2[param_3 + -1] & 0xdf;
    if ((param_2[param_3 + -1] & 0xdf) == 0) {
      do {
        iVar4 = param_3 + -1;
        uStack_1ec = uStack_1ec + 1;
        if (iVar4 == 0) break;
        iVar5 = param_3 + -2;
        param_3 = iVar4;
      } while ((param_2[iVar5] & 0xdf) == 0);
    }
    else {
      uStack_1ec = 0;
    }
  }
  if (param_4 < 1) {
    iVar6 = 0x10;
    iVar5 = 0;
  }
  else {
    iVar5 = 0x80;
    if (param_4 < 0x81) {
      iVar5 = param_4;
    }
    __memset_chk(acStack_1d4,0x20,iVar5,0x81);
    if (param_4 < 7) {
      param_4 = iVar5 - param_4;
    }
    else {
      param_4 = iVar5 + -6;
    }
    iVar6 = param_4 + 6;
    if (-1 < param_4 + 3) {
      iVar6 = param_4 + 3;
    }
    iVar6 = 0x10 - (iVar6 >> 2);
  }
  acStack_1d4[iVar5] = '\0';
  iStack_1fc = __aeabi_idiv(iVar4,iVar6);
  if (iVar6 * iStack_1fc < iVar4) {
    iStack_1fc = iStack_1fc + 1;
  }
  if (iStack_1fc < 1) {
    iStack_204 = 0;
  }
  else {
    iVar5 = 0;
    iVar9 = 0;
    iStack_204 = 0;
    pbVar8 = param_2;
    do {
      BUF_strlcpy(acStack_150,acStack_1d4,0x121);
      BIO_snprintf(acStack_1e8,0x14,"%04x - ",iVar5);
      BUF_strlcat(acStack_150,acStack_1e8,0x121);
      if (iVar6 < 1) {
        BUF_strlcat(acStack_150,"  ",0x121);
      }
      else {
        iVar7 = 0;
        do {
          while (iVar4 <= iVar5 + iVar7) {
            iVar7 = iVar7 + 1;
            BUF_strlcat(acStack_150,"   ",0x121);
            if (iVar7 == iVar6) goto LAB_000a0816;
          }
          pbVar11 = pbVar8 + iVar7;
          if (iVar7 == 7) {
            uVar2 = 0x2d;
          }
          else {
            uVar2 = 0x20;
          }
          iVar7 = iVar7 + 1;
          BIO_snprintf(acStack_1e8,0x14,"%02x%c",(uint)*pbVar11,uVar2);
          BUF_strlcat(acStack_150,acStack_1e8,0x121);
        } while (iVar7 != iVar6);
LAB_000a0816:
        BUF_strlcat(acStack_150,"  ",0x121);
        if (iVar5 < iVar4) {
          pbVar11 = pbVar8;
          do {
            pbVar10 = pbVar11 + 1;
            uVar3 = (uint)*pbVar11;
            if (0x5e < uVar3 - 0x20) {
              uVar3 = 0x2e;
            }
            BIO_snprintf(acStack_1e8,0x14,"%c",uVar3);
            BUF_strlcat(acStack_150,acStack_1e8,0x121);
          } while ((pbVar10 != param_2 + iVar5 + iVar6) &&
                  (pbVar11 = pbVar10, pbVar10 != param_2 + iVar4));
        }
      }
      BUF_strlcat(acStack_150,"\n",0x121);
      sVar1 = strlen(acStack_150);
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + iVar6;
      pbVar8 = pbVar8 + iVar6;
      iVar7 = BIO_write(param_1,acStack_150,sVar1);
      iStack_204 = iStack_204 + iVar7;
    } while (iVar9 != iStack_1fc);
  }
  if (uStack_1ec != 0) {
    BIO_snprintf(acStack_150,0x121,"%s%04x - <SPACES/NULS>\n",acStack_1d4,iVar4 + uStack_1ec);
    sVar1 = strlen(acStack_150);
    iVar4 = BIO_write(param_1,acStack_150,sVar1);
    iStack_204 = iStack_204 + iVar4;
  }
  if (iStack_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iStack_204);
}

