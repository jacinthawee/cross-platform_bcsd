
void BIO_dump_indent_cb_constprop_0(FILE *param_1,byte *param_2,int param_3,int param_4)

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
  int local_204;
  int local_1fc;
  uint local_1ec;
  char acStack_1e8 [20];
  char local_1d4 [132];
  char local_150 [292];
  int local_2c;
  byte *pbVar11;
  
  local_2c = __TMC_END__;
  iVar4 = param_3;
  if (param_3 < 1) {
    local_1ec = 0;
  }
  else {
    local_1ec = param_2[param_3 + -1] & 0xdf;
    if ((param_2[param_3 + -1] & 0xdf) == 0) {
      do {
        iVar4 = param_3 + -1;
        local_1ec = local_1ec + 1;
        if (iVar4 == 0) break;
        iVar5 = param_3 + -2;
        param_3 = iVar4;
      } while ((param_2[iVar5] & 0xdf) == 0);
    }
    else {
      local_1ec = 0;
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
    __memset_chk(local_1d4,0x20,iVar5,0x81);
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
  local_1d4[iVar5] = '\0';
  local_1fc = __aeabi_idiv(iVar4,iVar6);
  if (iVar6 * local_1fc < iVar4) {
    local_1fc = local_1fc + 1;
  }
  if (local_1fc < 1) {
    local_204 = 0;
  }
  else {
    iVar5 = 0;
    iVar9 = 0;
    local_204 = 0;
    pbVar8 = param_2;
    do {
      iVar7 = 0;
      local_150[0] = '\0';
      BUF_strlcpy(local_150,local_1d4,0x121);
      BIO_snprintf(acStack_1e8,0x14,"%04x - ",iVar5);
      BUF_strlcat(local_150,acStack_1e8,0x121);
      if (iVar6 < 1) {
        BUF_strlcat(local_150,"  ",0x121);
      }
      else {
        do {
          while (iVar4 <= iVar5 + iVar7) {
            iVar7 = iVar7 + 1;
            BUF_strlcat(local_150,"   ",0x121);
            if (iVar7 == iVar6) goto LAB_000a3688;
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
          BUF_strlcat(local_150,acStack_1e8,0x121);
        } while (iVar7 != iVar6);
LAB_000a3688:
        BUF_strlcat(local_150,"  ",0x121);
        if (iVar5 < iVar4) {
          pbVar11 = pbVar8;
          do {
            pbVar10 = pbVar11 + 1;
            uVar3 = (uint)*pbVar11;
            if (0x5e < uVar3 - 0x20) {
              uVar3 = 0x2e;
            }
            BIO_snprintf(acStack_1e8,0x14,"%c",uVar3);
            BUF_strlcat(local_150,acStack_1e8,0x121);
          } while ((pbVar10 != param_2 + iVar5 + iVar6) &&
                  (pbVar11 = pbVar10, pbVar10 != param_2 + iVar4));
        }
      }
      BUF_strlcat(local_150,"\n",0x121);
      sVar1 = strlen(local_150);
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + iVar6;
      pbVar8 = pbVar8 + iVar6;
      sVar1 = fwrite(local_150,sVar1,1,param_1);
      local_204 = local_204 + sVar1;
    } while (iVar9 != local_1fc);
  }
  if (local_1ec != 0) {
    BIO_snprintf(local_150,0x121,"%s%04x - <SPACES/NULS>\n",local_1d4,iVar4 + local_1ec);
    sVar1 = strlen(local_150);
    sVar1 = fwrite(local_150,sVar1,1,param_1);
    local_204 = local_204 + sVar1;
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_204);
}

