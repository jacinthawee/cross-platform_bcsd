
bool TS_CONF_set_default_engine(byte *param_1)

{
  ENGINE *e;
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  iVar1 = 8;
  bVar6 = true;
  bVar4 = &stack0xfffffff0 < &DAT_0000000c;
  bVar5 = &stack0x00000000 == (undefined *)0x1c;
  pbVar2 = param_1;
  pbVar3 = (byte *)"builtin";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if ((!bVar4 && !bVar5) != bVar4) {
    e = ENGINE_by_id((char *)0x1);
    bVar6 = e == (ENGINE *)0x0;
    if (!bVar6) {
      iVar1 = 5;
      pbVar2 = param_1;
      pbVar3 = &DAT_08233de9;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pbVar2 == *pbVar3;
        pbVar2 = pbVar2 + (uint)bVar7 * -2 + 1;
        pbVar3 = pbVar3 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if (bVar6) {
        ENGINE_ctrl(e,100,1,(void *)0x0,(f *)0x0);
      }
      iVar1 = ENGINE_set_default(e,0xffff);
      if (iVar1 == 0) {
        ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
        ERR_add_error_data(2,"engine:",param_1);
      }
      ENGINE_free(e);
      return iVar1 != 0;
    }
    ERR_put_error(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    ERR_add_error_data(2,"engine:",param_1);
    bVar6 = false;
  }
  return bVar6;
}

