
void do_esc_char_constprop_7(uint param_1,uint param_2,undefined *param_3,FILE *param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  undefined local_28 [8];
  char acStack_20 [12];
  int local_14;
  
  local_14 = __TMC_END__;
  if (param_1 < 0x10000) {
    if (param_1 < 0x100) {
      uVar3 = param_1 << 0x18;
      bVar4 = (int)uVar3 < 0;
      if (bVar4) {
        uVar3 = param_2 & 4;
      }
      local_28[0] = (undefined)(param_1 & 0xff);
      if (bVar4) {
        uVar3 = uVar3 & 0xff;
      }
      else {
        uVar3 = (byte)(&char_type)[param_1] & param_2;
      }
      if ((uVar3 & 0x61) == 0) {
        if ((uVar3 & 6) == 0) {
          if (((param_1 & 0xff) != 0x5c) || ((param_2 & 0xf) == 0)) goto LAB_000b56f0;
          if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(&DAT_001621b4,1,2,param_4), sVar1 == 2))
          goto LAB_000b572c;
        }
        else {
          BIO_snprintf(acStack_20,0xb,"\\%02X",param_1);
          if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(acStack_20,1,3,param_4), sVar1 == 3)) {
            uVar2 = 3;
            goto LAB_000b5758;
          }
        }
      }
      else if ((int)(uVar3 << 0x1c) < 0) {
        if (param_3 != (undefined *)0x0) {
          *param_3 = 1;
        }
LAB_000b56f0:
        if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(local_28,1,1,param_4), sVar1 == 1)) {
          uVar2 = 1;
          goto LAB_000b5758;
        }
      }
      else if ((param_4 == (FILE *)0x0) ||
              ((sVar1 = fwrite(&DAT_001621a8,1,1,param_4), sVar1 == 1 &&
               (sVar1 = fwrite(local_28,1,1,param_4), sVar1 == 1)))) {
LAB_000b572c:
        uVar2 = 2;
        goto LAB_000b5758;
      }
    }
    else {
      BIO_snprintf(acStack_20,0xb,"\\U%04lX",param_1);
      if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(acStack_20,1,6,param_4), sVar1 == 6)) {
        uVar2 = 6;
        goto LAB_000b5758;
      }
    }
  }
  else {
    BIO_snprintf(acStack_20,0xb,"\\W%08lX",param_1);
    if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(acStack_20,1,10,param_4), sVar1 == 10)) {
      uVar2 = 10;
      goto LAB_000b5758;
    }
  }
  uVar2 = 0xffffffff;
LAB_000b5758:
  if (local_14 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}

