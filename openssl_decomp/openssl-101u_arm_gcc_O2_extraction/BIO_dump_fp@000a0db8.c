
/* WARNING: Removing unreachable block (ram,0x000a0976) */
/* WARNING: Removing unreachable block (ram,0x000a0980) */
/* WARNING: Removing unreachable block (ram,0x000a0982) */
/* WARNING: Removing unreachable block (ram,0x000a0992) */
/* WARNING: Removing unreachable block (ram,0x000a0994) */
/* WARNING: Removing unreachable block (ram,0x000a0996) */
/* WARNING: Removing unreachable block (ram,0x000a099e) */
/* WARNING: Removing unreachable block (ram,0x000a09a0) */
/* WARNING: Removing unreachable block (ram,0x000a0b30) */

int BIO_dump_fp(FILE *fp,char *s,int len)

{
  size_t sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  int iStack_204;
  int iStack_1fc;
  uint uStack_1ec;
  char acStack_1e8 [20];
  char acStack_1d4 [132];
  char acStack_150 [292];
  int iStack_2c;
  byte *pbVar10;
  
  iStack_2c = __stack_chk_guard;
  iVar4 = len;
  if (len < 1) {
    uStack_1ec = 0;
  }
  else {
    uStack_1ec = (byte)s[len + -1] & 0xdf;
    if ((s[len + -1] & 0xdfU) == 0) {
      do {
        iVar4 = len + -1;
        uStack_1ec = uStack_1ec + 1;
        if (iVar4 == 0) break;
        iVar5 = len + -2;
        len = iVar4;
      } while ((s[iVar5] & 0xdfU) == 0);
    }
    else {
      uStack_1ec = 0;
    }
  }
  acStack_1d4[0] = '\0';
  iStack_1fc = __aeabi_idiv(iVar4,0x10);
  if (iStack_1fc * 0x10 < iVar4) {
    iStack_1fc = iStack_1fc + 1;
  }
  if (iStack_1fc < 1) {
    iStack_204 = 0;
  }
  else {
    iVar5 = 0;
    iVar8 = 0;
    iStack_204 = 0;
    pbVar7 = (byte *)s;
    do {
      BUF_strlcpy(acStack_150,acStack_1d4,0x121);
      BIO_snprintf(acStack_1e8,0x14,"%04x - ",iVar5);
      BUF_strlcat(acStack_150,acStack_1e8,0x121);
      iVar6 = 0;
      do {
        while (iVar5 + iVar6 < iVar4) {
          pbVar10 = pbVar7 + iVar6;
          if (iVar6 == 7) {
            uVar2 = 0x2d;
          }
          else {
            uVar2 = 0x20;
          }
          iVar6 = iVar6 + 1;
          BIO_snprintf(acStack_1e8,0x14,"%02x%c",(uint)*pbVar10,uVar2);
          BUF_strlcat(acStack_150,acStack_1e8,0x121);
          if (iVar6 == 0x10) goto LAB_000a0a56;
        }
        iVar6 = iVar6 + 1;
        BUF_strlcat(acStack_150,"   ",0x121);
      } while (iVar6 != 0x10);
LAB_000a0a56:
      BUF_strlcat(acStack_150,"  ",0x121);
      if (iVar5 < iVar4) {
        pbVar10 = pbVar7;
        do {
          pbVar9 = pbVar10 + 1;
          uVar3 = (uint)*pbVar10;
          if (0x5e < uVar3 - 0x20) {
            uVar3 = 0x2e;
          }
          BIO_snprintf(acStack_1e8,0x14,"%c",uVar3);
          BUF_strlcat(acStack_150,acStack_1e8,0x121);
        } while ((pbVar9 != (byte *)(s + iVar5 + 0x10)) &&
                (pbVar10 = pbVar9, pbVar9 != (byte *)(s + iVar4)));
      }
      BUF_strlcat(acStack_150,"\n",0x121);
      sVar1 = strlen(acStack_150);
      iVar8 = iVar8 + 1;
      iVar5 = iVar5 + 0x10;
      pbVar7 = pbVar7 + 0x10;
      sVar1 = fwrite(acStack_150,sVar1,1,fp);
      iStack_204 = iStack_204 + sVar1;
    } while (iVar8 != iStack_1fc);
  }
  if (uStack_1ec != 0) {
    BIO_snprintf(acStack_150,0x121,"%s%04x - <SPACES/NULS>\n",acStack_1d4,iVar4 + uStack_1ec);
    sVar1 = strlen(acStack_150);
    sVar1 = fwrite(acStack_150,sVar1,1,fp);
    iStack_204 = iStack_204 + sVar1;
  }
  if (iStack_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iStack_204;
}

