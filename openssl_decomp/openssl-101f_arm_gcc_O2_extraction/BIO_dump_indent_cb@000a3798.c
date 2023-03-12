
int BIO_dump_indent_cb(cb *cb,void *u,char *s,int len,int indent)

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
  int local_208;
  int local_200;
  uint local_1ec;
  char acStack_1e8 [20];
  char local_1d4 [132];
  char local_150 [292];
  int local_2c;
  byte *pbVar11;
  
  local_2c = __TMC_END__;
  iVar4 = len;
  if (len < 1) {
    local_1ec = 0;
  }
  else {
    local_1ec = (byte)s[len + -1] & 0xdf;
    if ((s[len + -1] & 0xdfU) == 0) {
      do {
        iVar4 = len + -1;
        local_1ec = local_1ec + 1;
        if (iVar4 == 0) break;
        iVar6 = len + -2;
        len = iVar4;
      } while ((s[iVar6] & 0xdfU) == 0);
    }
    else {
      local_1ec = 0;
    }
  }
  if (indent < 1) {
    iVar5 = 0x10;
    iVar6 = 0;
  }
  else {
    iVar6 = 0x80;
    if (indent < 0x81) {
      iVar6 = indent;
    }
    __memset_chk(local_1d4,0x20,iVar6,0x81);
    if (indent < 7) {
      iVar5 = iVar6 - indent;
    }
    else {
      iVar5 = iVar6 + -6;
    }
    iVar9 = iVar5 + 6;
    if (-1 < iVar5 + 3) {
      iVar9 = iVar5 + 3;
    }
    iVar5 = 0x10 - (iVar9 >> 2);
  }
  local_1d4[iVar6] = '\0';
  local_200 = __aeabi_idiv(iVar4,iVar5);
  if (iVar5 * local_200 < iVar4) {
    local_200 = local_200 + 1;
  }
  if (local_200 < 1) {
    local_208 = 0;
  }
  else {
    iVar6 = 0;
    iVar9 = 0;
    local_208 = 0;
    pbVar8 = (byte *)s;
    do {
      iVar7 = 0;
      local_150[0] = '\0';
      BUF_strlcpy(local_150,local_1d4,0x121);
      BIO_snprintf(acStack_1e8,0x14,"%04x - ",iVar6);
      BUF_strlcat(local_150,acStack_1e8,0x121);
      if (iVar5 < 1) {
        BUF_strlcat(local_150,"  ",0x121);
      }
      else {
        do {
          while (iVar4 <= iVar6 + iVar7) {
            iVar7 = iVar7 + 1;
            BUF_strlcat(local_150,"   ",0x121);
            if (iVar7 == iVar5) goto LAB_000a38ce;
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
        } while (iVar7 != iVar5);
LAB_000a38ce:
        BUF_strlcat(local_150,"  ",0x121);
        if (iVar6 < iVar4) {
          pbVar11 = pbVar8;
          do {
            pbVar10 = pbVar11 + 1;
            uVar3 = (uint)*pbVar11;
            if (0x5e < uVar3 - 0x20) {
              uVar3 = 0x2e;
            }
            BIO_snprintf(acStack_1e8,0x14,"%c",uVar3);
            BUF_strlcat(local_150,acStack_1e8,0x121);
          } while ((pbVar10 != (byte *)(s + iVar6 + iVar5)) &&
                  (pbVar11 = pbVar10, pbVar10 != (byte *)(s + iVar4)));
        }
      }
      BUF_strlcat(local_150,"\n",0x121);
      sVar1 = strlen(local_150);
      iVar9 = iVar9 + 1;
      iVar6 = iVar6 + iVar5;
      pbVar8 = pbVar8 + iVar5;
      iVar7 = (*cb)(local_150,sVar1,u);
      local_208 = local_208 + iVar7;
    } while (iVar9 != local_200);
  }
  if (local_1ec != 0) {
    BIO_snprintf(local_150,0x121,"%s%04x - <SPACES/NULS>\n",local_1d4,iVar4 + local_1ec);
    sVar1 = strlen(local_150);
    iVar4 = (*cb)(local_150,sVar1,u);
    local_208 = local_208 + iVar4;
  }
  if (local_2c == __TMC_END__) {
    return local_208;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

