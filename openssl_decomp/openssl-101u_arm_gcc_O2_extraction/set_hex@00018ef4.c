
undefined4 set_hex(byte *param_1,void *param_2,size_t param_3)

{
  uint uVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  bool bVar7;
  
  sVar2 = strlen((char *)param_1);
  if (sVar2 != param_3 * 2 && (int)(sVar2 + param_3 * -2) < 0 == SBORROW4(sVar2,param_3 * 2)) {
    BIO_printf(bio_err,"hex string is too long\n");
    return 0;
  }
  memset(param_2,0,param_3);
  if (0 < (int)sVar2) {
    bVar5 = *param_1;
    uVar4 = 0;
    *param_1 = 0;
    while (uVar1 = (uint)bVar5, uVar1 != 0) {
      uVar6 = uVar1 - 0x30 & 0xff;
      if (9 < uVar6) {
        if (uVar1 - 0x41 < 6) {
          uVar6 = uVar1 - 0x37 & 0xff;
        }
        else {
          uVar6 = uVar1 - 0x57 & 0xff;
          if (5 < uVar1 - 0x61) {
            BIO_printf(bio_err,"non-hex digit\n");
            return 0;
          }
        }
      }
      bVar5 = (byte)uVar6;
      bVar7 = (uVar4 & 1) == 0;
      uVar1 = (int)uVar4 >> 1;
      uVar4 = uVar4 + 1;
      uVar3 = uVar1;
      if (!bVar7) {
        uVar3 = (uint)*(byte *)((int)param_2 + uVar1);
      }
      if (bVar7) {
        *(char *)((int)param_2 + uVar3) = (char)(uVar6 << 4);
      }
      else {
        bVar5 = bVar5 | (byte)uVar3;
      }
      if (!bVar7) {
        *(byte *)((int)param_2 + uVar1) = bVar5;
      }
      if (sVar2 == uVar4) {
        return 1;
      }
      bVar5 = param_1[1];
      param_1 = param_1 + 1;
      *param_1 = 0;
    }
  }
  return 1;
}

