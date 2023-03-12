
int __regparm3
BIO_dump_indent_cb_constprop_0(FILE *param_1_00,byte *param_2,int param_3,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int in_GS_OFFSET;
  int local_214;
  int local_210;
  int local_20c;
  byte *local_200;
  int local_1fc;
  int local_1f8;
  int local_1e0;
  char local_1d6 [20];
  char local_1c2 [129];
  char local_141 [289];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((param_3 < 1) || ((param_2[param_3 + -1] & 0xdf) != 0)) {
    local_1e0 = 0;
    local_20c = param_3;
  }
  else {
    local_1e0 = 0;
    do {
      local_1e0 = local_1e0 + 1;
      local_20c = param_3 + -1;
      if (local_20c == 0) break;
      iVar1 = param_3 + -2;
      param_3 = local_20c;
    } while ((param_2[iVar1] & 0xdf) == 0);
  }
  if (param_1 < 1) {
    local_210 = 0x10;
    iVar1 = 0;
  }
  else {
    iVar1 = 0x80;
    if (param_1 < 0x81) {
      iVar1 = param_1;
    }
    __memset_chk(local_1c2,0x20,iVar1,0x81);
    iVar6 = 6;
    if (iVar1 < 7) {
      iVar6 = iVar1;
    }
    iVar5 = (iVar1 - iVar6) + 3;
    iVar6 = (iVar1 - iVar6) + 6;
    if (-1 < iVar5) {
      iVar6 = iVar5;
    }
    local_210 = 0x10 - (iVar6 >> 2);
  }
  local_1c2[iVar1] = '\0';
  iVar1 = local_20c / local_210;
  if (local_210 * iVar1 < local_20c) {
    iVar1 = iVar1 + 1;
  }
  if (iVar1 < 1) {
    local_1f8 = 0;
  }
  else {
    local_214 = 0;
    local_1f8 = 0;
    local_1fc = 0;
    local_200 = param_2;
    do {
      local_141[0] = '\0';
      BUF_strlcpy(local_141,local_1c2,0x121);
      BIO_snprintf(local_1d6,0x14,"%04x - ",local_214);
      BUF_strlcat(local_141,local_1d6,0x121);
      if (local_210 < 1) {
        BUF_strlcat(local_141,"  ",0x121);
      }
      else {
        iVar6 = 0;
        do {
          while (local_214 + iVar6 < local_20c) {
            uVar2 = 0x2d;
            if (iVar6 != 7) {
              uVar2 = 0x20;
            }
            pbVar7 = local_200 + iVar6;
            iVar6 = iVar6 + 1;
            BIO_snprintf(local_1d6,0x14,"%02x%c",(uint)*pbVar7,uVar2);
            BUF_strlcat(local_141,local_1d6,0x121);
            if (iVar6 == local_210) goto LAB_0811e8a3;
          }
          iVar6 = iVar6 + 1;
          BUF_strlcat(local_141,"   ",0x121);
        } while (iVar6 != local_210);
LAB_0811e8a3:
        BUF_strlcat(local_141,"  ",0x121);
        if (local_214 < local_20c) {
          pbVar7 = local_200;
          do {
            uVar3 = (uint)*pbVar7;
            if (0x5e < (byte)(*pbVar7 - 0x20)) {
              uVar3 = 0x2e;
            }
            BIO_snprintf(local_1d6,0x14,"%c",uVar3);
            BUF_strlcat(local_141,local_1d6,0x121);
          } while ((param_2 + local_210 + -1 + local_214 != pbVar7) &&
                  (pbVar7 = pbVar7 + 1, param_2 + local_20c != pbVar7));
        }
      }
      BUF_strlcat(local_141,"\n",0x121);
      sVar4 = strlen(local_141);
      sVar4 = fwrite(local_141,sVar4,1,param_1_00);
      local_1fc = local_1fc + 1;
      local_1f8 = local_1f8 + sVar4;
      local_214 = local_214 + local_210;
      local_200 = local_200 + local_210;
    } while (local_1fc != iVar1);
  }
  if (local_1e0 != 0) {
    BIO_snprintf(local_141,0x121,"%s%04x - <SPACES/NULS>\n",local_1c2,local_20c + local_1e0);
    sVar4 = strlen(local_141);
    sVar4 = fwrite(local_141,sVar4,1,param_1_00);
    local_1f8 = local_1f8 + sVar4;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1f8;
}

