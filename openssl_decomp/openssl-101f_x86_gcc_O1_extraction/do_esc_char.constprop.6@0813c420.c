
undefined4 __regparm3
do_esc_char_constprop_6(uint param_1_00,byte param_2,undefined *param_3,BIO *param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  int in_GS_OFFSET;
  char local_1c;
  char local_1b [11];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1_00 < 0x10000) {
    if (param_1_00 < 0x100) {
      local_1c = (char)param_1_00;
      bVar3 = param_2 & 4;
      if ((local_1c < '\0') || (bVar3 = char_type[param_1_00] & param_2, (bVar3 & 0x61) == 0)) {
        if ((bVar3 & 6) == 0) {
          if ((param_1_00 != 0x5c) || ((param_2 & 0xf) == 0)) goto LAB_0813c479;
          if ((param_1 == (BIO *)0x0) || (iVar1 = BIO_write(param_1,&DAT_08226cb5,2), iVar1 == 2))
          goto LAB_0813c4d0;
        }
        else {
          BIO_snprintf(local_1b,0xb,"\\%02X",param_1_00);
          if ((param_1 == (BIO *)0x0) || (iVar1 = BIO_write(param_1,local_1b,3), iVar1 == 3)) {
            uVar2 = 3;
            goto LAB_0813c512;
          }
        }
      }
      else if ((bVar3 & 8) == 0) {
        if ((param_1 == (BIO *)0x0) ||
           ((iVar1 = BIO_write(param_1,&DAT_08226cb6,1), iVar1 == 1 &&
            (iVar1 = BIO_write(param_1,&local_1c,1), iVar1 == 1)))) {
LAB_0813c4d0:
          uVar2 = 2;
          goto LAB_0813c512;
        }
      }
      else {
        if (param_3 != (undefined *)0x0) {
          *param_3 = 1;
        }
LAB_0813c479:
        if ((param_1 == (BIO *)0x0) || (iVar1 = BIO_write(param_1,&local_1c,1), iVar1 == 1)) {
          uVar2 = 1;
          goto LAB_0813c512;
        }
      }
    }
    else {
      BIO_snprintf(local_1b,0xb,"\\U%04lX",param_1_00);
      if ((param_1 == (BIO *)0x0) || (iVar1 = BIO_write(param_1,local_1b,6), iVar1 == 6)) {
        uVar2 = 6;
        goto LAB_0813c512;
      }
    }
  }
  else {
    BIO_snprintf(local_1b,0xb,"\\W%08lX",param_1_00);
    if ((param_1 == (BIO *)0x0) || (iVar1 = BIO_write(param_1,local_1b,10), iVar1 == 10)) {
      uVar2 = 10;
      goto LAB_0813c512;
    }
  }
  uVar2 = 0xffffffff;
LAB_0813c512:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

