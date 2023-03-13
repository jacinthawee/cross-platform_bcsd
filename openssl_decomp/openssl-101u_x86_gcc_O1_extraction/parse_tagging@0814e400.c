
undefined4 __regparm3 parse_tagging(char *param_1_00,int param_2,ulong *param_3,undefined4 *param_1)

{
  char cVar1;
  ulong uVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  char *local_28;
  char local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1_00 == (char *)0x0) {
LAB_0814e487:
    uVar3 = 0;
  }
  else {
    uVar2 = strtoul(param_1_00,&local_28,10);
    if (local_28 == (char *)0x0) {
      if ((int)uVar2 < 0) {
LAB_0814e530:
        ERR_put_error(0xd,0xb6,0xbb,"asn1_gen.c",0x19c);
        uVar3 = 0;
        goto LAB_0814e4a5;
      }
      *param_3 = uVar2;
    }
    else {
      if ((*local_28 != '\0') && (param_1_00 + param_2 < local_28)) goto LAB_0814e487;
      if ((int)uVar2 < 0) goto LAB_0814e530;
      *param_3 = uVar2;
      if ((param_2 != (int)local_28 - (int)param_1_00) && (cVar1 = *local_28, cVar1 != 'C')) {
        if (cVar1 < 'D') {
          if (cVar1 == 'A') {
            *param_1 = 0x40;
            uVar3 = 1;
            goto LAB_0814e4a5;
          }
        }
        else {
          if (cVar1 == 'P') {
            *param_1 = 0xc0;
            uVar3 = 1;
            goto LAB_0814e4a5;
          }
          if (cVar1 == 'U') {
            *param_1 = 0;
            uVar3 = 1;
            goto LAB_0814e4a5;
          }
        }
        local_21 = 0;
        local_22 = cVar1;
        ERR_put_error(0xd,0xb6,0xba,"asn1_gen.c",0x1bb);
        ERR_add_error_data(2,"Char=",&local_22);
        uVar3 = 0;
        goto LAB_0814e4a5;
      }
    }
    *param_1 = 0x80;
    uVar3 = 1;
  }
LAB_0814e4a5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

