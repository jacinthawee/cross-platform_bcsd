
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cca_get_random_bytes(void *param_1,size_t param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int local_48;
  undefined auStack_44 [4];
  undefined auStack_40 [4];
  undefined auStack_3c [4];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined local_28;
  int local_24;
  
  local_30 = s_RANDOM_0016f6f0._0_4_;
  uStack_2c = s_RANDOM_0016f6f0._4_4_;
  local_24 = __TMC_END__;
  local_28 = (undefined)ram0x0016f6f8;
  if (7 < (int)param_2) {
    pvVar1 = (void *)((int)param_1 + 8);
    do {
      param_1 = pvVar1;
      (*randomNumberGenerate)(&local_48,auStack_44,auStack_40,auStack_3c,&local_30,&local_38);
      if (local_48 != 0) goto LAB_000ef058;
      param_2 = param_2 - 8;
      *(undefined4 *)((int)param_1 + -8) = local_38;
      *(undefined4 *)((int)param_1 + -4) = uStack_34;
      pvVar1 = (void *)((int)param_1 + 8);
    } while (7 < (int)param_2);
  }
  uVar2 = 1;
  if (param_2 != 0) {
    (*randomNumberGenerate)(&local_48,auStack_44,0,0,&local_30,&local_38);
    if (local_48 == 0) {
      memcpy(param_1,&local_38,param_2);
      uVar2 = 1;
    }
    else {
LAB_000ef058:
      uVar2 = 0;
    }
  }
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}

