
void ssl3_cbc_copy_mac(int param_1,int param_2,uint param_3,uint param_4)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint extraout_r1;
  uint uVar4;
  uint uVar5;
  byte *__s;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  byte abStack_ac [128];
  int local_2c;
  
  iVar3 = *(int *)(param_2 + 4) - param_3;
  local_2c = __TMC_END__;
  if (param_4 < param_3) {
    OpenSSLDie("s3_cbc.c",0x113,"orig_len >= md_size");
  }
  if (0x40 < param_3) {
    OpenSSLDie("s3_cbc.c",0x114,"md_size <= EVP_MAX_MD_SIZE");
  }
  __s = abStack_ac + (-(int)abStack_ac & 0x3f);
  if (param_3 + 0x100 < param_4) {
    uVar6 = (param_4 - 0x100) - param_3;
  }
  else {
    uVar6 = 0;
  }
  __aeabi_uidivmod((iVar3 + (param_3 >> 1) * 0x1000000) - uVar6,param_3);
  pvVar1 = memset(__s,0,param_3);
  if (uVar6 < param_4) {
    uVar4 = 0;
    iVar2 = *(int *)(param_2 + 0xc);
    uVar5 = ~(uVar6 - iVar3);
    pbVar7 = (byte *)(uVar6 + iVar2);
    do {
      pbVar8 = pbVar7 + 1;
      pvVar1 = (void *)(uVar4 + 1);
      bVar9 = *pbVar7 & (byte)((int)uVar5 >> 0x1f);
      if ((int)(param_3 + uVar5) < 0 != SCARRY4(param_3,uVar5)) {
        bVar9 = 0;
      }
      uVar5 = uVar5 - 1;
      __s[uVar4] = bVar9 | __s[uVar4];
      uVar4 = (uint)pvVar1 & (int)((int)pvVar1 - param_3) >> 0x1f;
      pbVar7 = pbVar8;
    } while (pbVar8 != (byte *)(iVar2 + param_4));
  }
  uVar4 = 0;
  uVar6 = extraout_r1;
  if (param_3 != 0) {
    do {
      *(byte *)(param_1 + uVar4) = __s[uVar6];
      uVar4 = uVar4 + 1;
      pvVar1 = (void *)(uint)__s[uVar6 ^ 0x20];
      uVar6 = uVar6 + 1 & (int)((uVar6 + 1) - param_3) >> 0x1f;
    } while (uVar4 != param_3);
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pvVar1);
  }
  return;
}

