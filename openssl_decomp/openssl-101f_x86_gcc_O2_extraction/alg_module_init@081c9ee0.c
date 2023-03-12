
int alg_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  char *section;
  int iVar1;
  int iVar2;
  CONF_VALUE *value;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int in_GS_OFFSET;
  undefined uVar6;
  undefined uVar7;
  byte bVar8;
  undefined auStack_3c [12];
  _STACK *local_30;
  int local_24;
  int local_20;
  
  bVar8 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  section = CONF_imodule_get_value(param_1);
  local_30 = (_STACK *)NCONF_get_section(param_2,section);
  if (local_30 == (_STACK *)0x0) {
    iVar2 = 0;
    ERR_put_error(6,0xb1,0xa5,"evp_cnf.c",0x53);
  }
  else {
    iVar3 = 0;
    while( true ) {
      iVar2 = sk_num(local_30);
      if (iVar2 <= iVar3) break;
      uVar6 = auStack_3c < &DAT_00000008;
      uVar7 = &stack0x00000000 == (undefined *)0x44;
      value = (CONF_VALUE *)sk_value(local_30,iVar3);
      iVar2 = 10;
      pbVar4 = (byte *)value->name;
      pbVar5 = (byte *)"fips_mode";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        uVar6 = *pbVar4 < *pbVar5;
        uVar7 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + (uint)bVar8 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar8 * -2 + 1;
      } while ((bool)uVar7);
      iVar2 = (int)(char)((!(bool)uVar6 && !(bool)uVar7) - uVar6);
      if (iVar2 == 0) {
        iVar1 = X509V3_get_value_bool(value,&local_24);
        if (iVar1 == 0) {
          ERR_put_error(6,0xb1,0xa8,"evp_cnf.c",0x5e);
          goto LAB_081c9fcd;
        }
        if (0 < local_24) {
          ERR_put_error(6,0xb1,0xa7,"evp_cnf.c",0x6a);
          goto LAB_081c9fcd;
        }
      }
      else {
        ERR_put_error(6,0xb1,0xa9,"evp_cnf.c",0x71);
        ERR_add_error_data(4,"name=",value->name,", value=",value->value);
      }
      iVar3 = iVar3 + 1;
    }
    iVar2 = 1;
  }
LAB_081c9fcd:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

