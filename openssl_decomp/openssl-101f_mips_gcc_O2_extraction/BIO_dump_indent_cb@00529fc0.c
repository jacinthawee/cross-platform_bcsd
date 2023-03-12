
/* WARNING: Removing unreachable block (ram,0x0052a410) */

int BIO_dump_indent_cb(cb *cb,void *u,char *s,int len,int indent)

{
  undefined *puVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  cb *cb_00;
  undefined *u_00;
  int iVar7;
  int iVar8;
  char *pcVar9;
  byte *pbVar10;
  byte *local_224;
  int local_21c;
  int local_218;
  undefined *local_1f0;
  char acStack_1e8 [20];
  char local_1d4 [132];
  char local_150 [292];
  cb *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(cb **)PTR___stack_chk_guard_006aabf0;
  pcVar5 = s + len;
  if (len < 1) {
    local_1f0 = (undefined *)0x0;
    u_00 = (undefined *)u;
  }
  else {
    u_00 = (undefined *)0x0;
    do {
      iVar8 = len + -1;
      local_1f0 = u_00;
      if ((pcVar5[-1] & 0xdfU) != 0) break;
      u_00 = u_00 + 1;
      pcVar5 = pcVar5 + -1;
      len = iVar8;
      local_1f0 = u_00;
    } while (iVar8 != 0);
  }
  if (indent < 1) {
    iVar8 = 0x10;
    local_1d4[0] = '\0';
    iVar3 = len / 0x10 + (uint)((len / 0x10) * 0x10 < len);
    pcVar5 = s;
  }
  else {
    pcVar9 = &DAT_00000080;
    if (indent < 0x81) {
      pcVar9 = (char *)indent;
    }
    indent = 0x81;
    u_00 = &DAT_00000020;
    pcVar5 = pcVar9;
    (*(code *)PTR___memset_chk_006aaa98)(local_1d4);
    pcVar6 = &DAT_00000006;
    if ((int)pcVar9 < 7) {
      pcVar6 = pcVar9;
    }
    pcVar2 = pcVar9 + (3 - (int)pcVar6);
    if ((int)(pcVar9 + (3 - (int)pcVar6)) < 0) {
      pcVar2 = pcVar9 + (6 - (int)pcVar6);
    }
    iVar8 = 0x10 - ((int)pcVar2 >> 2);
    if (iVar8 == 0) {
      trap(7);
    }
    local_1d4[(int)pcVar9] = '\0';
    iVar3 = len / iVar8 + (uint)((len / iVar8) * iVar8 < len);
  }
  if (iVar3 < 1) {
    local_21c = 0;
  }
  else {
    local_218 = 0;
    local_21c = 0;
    pcVar9 = (char *)0x0;
    local_224 = (byte *)s;
    do {
      local_150[0] = '\0';
      BUF_strlcpy(local_150,local_1d4,0x121);
      indent = (int)pcVar9;
      BIO_snprintf(acStack_1e8,0x14,"%04x - ");
      BUF_strlcat(local_150,acStack_1e8,0x121);
      if (iVar8 < 1) {
        BUF_strlcat(local_150,"  ",0x121);
      }
      else {
        iVar7 = 0;
        pbVar10 = local_224;
        do {
          while ((int)(pcVar9 + iVar7) < len) {
            indent = (int)*pbVar10;
            uVar4 = 0x2d;
            if (iVar7 != 7) {
              uVar4 = 0x20;
            }
            iVar7 = iVar7 + 1;
            pbVar10 = pbVar10 + 1;
            BIO_snprintf(acStack_1e8,0x14,"%02x%c",indent,uVar4);
            BUF_strlcat(local_150,acStack_1e8,0x121);
            if (iVar7 == iVar8) goto LAB_0052a220;
          }
          iVar7 = iVar7 + 1;
          pbVar10 = pbVar10 + 1;
          BUF_strlcat(local_150,"   ",0x121);
        } while (iVar7 != iVar8);
LAB_0052a220:
        BUF_strlcat(local_150,"  ",0x121);
        if ((int)pcVar9 < len) {
          pbVar10 = local_224;
          do {
            indent = (int)*pbVar10;
            if ((char *)0x5e < (char *)(indent + -0x20)) {
              indent = 0x2e;
            }
            BIO_snprintf(acStack_1e8,0x14,"%c");
            BUF_strlcat(local_150,acStack_1e8,0x121);
          } while ((pbVar10 != (byte *)(s + (int)(pcVar9 + iVar8 + -1))) &&
                  (pbVar10 = pbVar10 + 1, (byte *)(s + len) != pbVar10));
        }
      }
      pcVar9 = pcVar9 + iVar8;
      BUF_strlcat(local_150,"\n",0x121);
      local_218 = local_218 + 1;
      local_224 = local_224 + iVar8;
      u_00 = (undefined *)(*(code *)PTR_strlen_006aab30)(local_150);
      pcVar5 = (char *)u;
      iVar7 = (*cb)(local_150,(size_t)u_00,u);
      local_21c = local_21c + iVar7;
    } while (iVar3 != local_218);
  }
  if (local_1f0 != (undefined *)0x0) {
    indent = (int)local_1d4;
    BIO_snprintf(local_150,0x121,"%s%04x - <SPACES/NULS>\n",indent,local_1f0 + len);
    u_00 = (undefined *)(*(code *)PTR_strlen_006aab30)(local_150);
    iVar8 = (*cb)(local_150,(size_t)u_00,u);
    local_21c = local_21c + iVar8;
    pcVar5 = (char *)u;
  }
  if (local_2c != *(cb **)puVar1) {
    cb_00 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar8 = BIO_dump_indent_cb(cb_00,u_00,pcVar5,indent,0);
    return iVar8;
  }
  return local_21c;
}

