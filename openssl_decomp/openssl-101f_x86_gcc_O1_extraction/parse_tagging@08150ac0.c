
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
LAB_08150b47:
    uVar3 = 0;
  }
  else {
    uVar2 = strtoul(param_1_00,&local_28,10);
    if (local_28 == (char *)0x0) {
      if ((int)uVar2 < 0) {
LAB_08150bf0:
        ERR_put_error(0xd,0xb6,0xbb,"asn1_gen.c",399);
        uVar3 = 0;
        goto LAB_08150b65;
      }
      *param_3 = uVar2;
    }
    else {
      if ((*local_28 != '\0') && (param_1_00 + param_2 < local_28)) goto LAB_08150b47;
      if ((int)uVar2 < 0) goto LAB_08150bf0;
      *param_3 = uVar2;
      if ((param_2 != (int)local_28 - (int)param_1_00) && (cVar1 = *local_28, cVar1 != 'C')) {
        if (cVar1 < 'D') {
          if (cVar1 == 'A') {
            *param_1 = 0x40;
            uVar3 = 1;
            goto LAB_08150b65;
          }
        }
        else {
          if (cVar1 == 'P') {
            *param_1 = 0xc0;
            uVar3 = 1;
            goto LAB_08150b65;
          }
          if (cVar1 == 'U') {
            *param_1 = 0;
            uVar3 = 1;
            goto LAB_08150b65;
          }
        }
        local_21 = 0;
        local_22 = cVar1;
        ERR_put_error(0xd,0xb6,0xba,"asn1_gen.c",0x1b0);
        ERR_add_error_data(2,"Char=",&local_22);
        uVar3 = 0;
        goto LAB_08150b65;
      }
    }
    *param_1 = 0x80;
    uVar3 = 1;
  }
LAB_08150b65:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

