
undefined4 set_hex(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  char *pcVar5;
  uint uVar6;
  byte *pbVar7;
  
  iVar1 = (*(code *)PTR_strlen_006aab30)();
  if (param_3 << 1 < iVar1) {
    pcVar5 = "hex string is too long\n";
LAB_0042b35c:
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar5);
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(param_2,0,param_3);
  if (0 < iVar1) {
    uVar3 = (uint)*param_1;
    *param_1 = 0;
    if (uVar3 != 0) {
      uVar6 = 0;
      pbVar7 = param_1 + 1;
      do {
        uVar2 = uVar3 - 0x30 & 0xff;
        if (9 < uVar2) {
          if (uVar3 - 0x41 < 6) {
            uVar2 = uVar3 - 0x37 & 0xff;
          }
          else {
            if (5 < uVar3 - 0x61) {
              pcVar5 = "non-hex digit\n";
              goto LAB_0042b35c;
            }
            uVar2 = uVar3 - 0x57 & 0xff;
          }
        }
        pbVar4 = (byte *)(param_2 + ((int)uVar6 >> 1));
        if ((uVar6 & 1) == 0) {
          *pbVar4 = (byte)(uVar2 << 4);
        }
        else {
          *pbVar4 = (byte)uVar2 | *pbVar4;
        }
        if (param_1 + iVar1 == pbVar7) {
          return 1;
        }
        uVar6 = uVar6 + 1;
        uVar3 = (uint)*pbVar7;
        *pbVar7 = 0;
        pbVar7 = pbVar7 + 1;
      } while (uVar3 != 0);
    }
  }
  return 1;
}

