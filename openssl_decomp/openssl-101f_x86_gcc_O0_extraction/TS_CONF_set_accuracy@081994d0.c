
bool TS_CONF_set_accuracy(CONF *param_1,char *param_2,undefined4 param_3)

{
  char *line;
  _STACK *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined uVar6;
  undefined uVar7;
  bool bVar8;
  byte bVar9;
  byte *local_2c;
  long local_28;
  long local_24;
  long local_20;
  
  bVar9 = 0;
  line = NCONF_get_string(param_1,param_2,"accuracy");
  if (line == (char *)0x0) {
    st = (_STACK *)0x0;
  }
  else {
    st = (_STACK *)X509V3_parse_list(line);
    if (st == (_STACK *)0x0) {
LAB_08199650:
      bVar8 = false;
      __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"accuracy");
      goto LAB_0819961f;
    }
  }
  local_20 = 0;
  local_24 = 0;
  iVar3 = 0;
  local_28 = 0;
  while( true ) {
    iVar1 = sk_num(st);
    if (iVar1 <= iVar3) break;
    uVar6 = &local_2c < &DAT_00000008;
    uVar7 = &stack0x00000000 == (undefined *)0x34;
    pvVar2 = sk_value(st,iVar3);
    local_2c = *(byte **)((int)pvVar2 + 4);
    iVar1 = 5;
    pbVar4 = local_2c;
    pbVar5 = (byte *)0x8233e36;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      uVar6 = *pbVar4 < *pbVar5;
      uVar7 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + (uint)bVar9 * -2 + 1;
      pbVar5 = pbVar5 + (uint)bVar9 * -2 + 1;
    } while ((bool)uVar7);
    bVar8 = (!(bool)uVar6 && !(bool)uVar7) == (bool)uVar6;
    if (bVar8) {
      if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
        local_28 = strtol(*(char **)((int)pvVar2 + 8),(char **)0x0,10);
      }
    }
    else {
      iVar1 = 10;
      pbVar4 = local_2c;
      pbVar5 = (byte *)"millisecs";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar8 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + (uint)bVar9 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar9 * -2 + 1;
      } while (bVar8);
      if (bVar8) {
        if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
          local_24 = strtol(*(char **)((int)pvVar2 + 8),(char **)0x0,10);
        }
      }
      else {
        iVar1 = 10;
        pbVar4 = local_2c;
        pbVar5 = (byte *)"microsecs";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar8 = *pbVar4 == *pbVar5;
          pbVar4 = pbVar4 + (uint)bVar9 * -2 + 1;
          pbVar5 = pbVar5 + (uint)bVar9 * -2 + 1;
        } while (bVar8);
        if (!bVar8) goto LAB_08199650;
        if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
          local_20 = strtol(*(char **)((int)pvVar2 + 8),(char **)0x0,10);
        }
      }
    }
    iVar3 = iVar3 + 1;
  }
  iVar3 = TS_RESP_CTX_set_accuracy(param_3,local_28,local_24,local_20);
  bVar8 = iVar3 != 0;
LAB_0819961f:
  sk_pop_free(st,X509V3_conf_free);
  return bVar8;
}

