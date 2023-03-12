
undefined4 set_hex(byte *param_1,void *param_2,size_t param_3)

{
  byte *pbVar1;
  byte bVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  sVar3 = strlen((char *)param_1);
  if ((int)(param_3 * 2) < (int)sVar3) {
    BIO_printf(bio_err,"hex string is too long\n");
    return 0;
  }
  memset(param_2,0,param_3);
  if (0 < (int)sVar3) {
    bVar2 = *param_1;
    *param_1 = 0;
    if (bVar2 != 0) {
      uVar4 = 0;
      do {
        uVar5 = (uint)bVar2;
        iVar6 = uVar5 - 0x30;
        if (9 < (byte)iVar6) {
          if ((byte)(bVar2 + 0xbf) < 6) {
            iVar6 = uVar5 - 0x37;
          }
          else {
            if (5 < (byte)(bVar2 + 0x9f)) {
              BIO_printf(bio_err,"non-hex digit\n");
              return 0;
            }
            iVar6 = uVar5 - 0x57;
          }
        }
        if ((uVar4 & 1) == 0) {
          *(char *)((int)param_2 + ((int)uVar4 >> 1)) = (char)(iVar6 << 4);
        }
        else {
          pbVar1 = (byte *)((int)param_2 + ((int)uVar4 >> 1));
          *pbVar1 = *pbVar1 | (byte)iVar6;
        }
        if (sVar3 == uVar4 + 1) {
          return 1;
        }
        uVar4 = uVar4 + 1;
        bVar2 = param_1[uVar4];
        param_1[uVar4] = 0;
      } while (bVar2 != 0);
    }
  }
  return 1;
}

