
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * UI_construct_prompt(UI *ui_method,char *object_desc,char *object_name)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined2 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined local_1e;
  int local_1c;
  
  local_1c = __TMC_END__;
  if (*(code **)(*(int *)ui_method + 0x18) == (code *)0x0) {
    local_24 = s_Enter_0016bf84._0_4_;
    local_30[0] = 0x3a;
    local_20 = (undefined2)ram0x0016bf88;
    local_2c = DAT_0016bf8c;
    local_1e = (undefined)((uint)ram0x0016bf88 >> 0x10);
    local_28 = (undefined2)DAT_0016bf90;
    if (object_desc != (char *)0x0) {
      sVar1 = strlen(object_desc);
      if (object_name == (char *)0x0) {
        sVar1 = sVar1 + 8;
        pcVar3 = (char *)CRYPTO_malloc(sVar1,"ui_lib.c",0x1b1);
        BUF_strlcpy(pcVar3,(char *)&local_24,sVar1);
        BUF_strlcat(pcVar3,object_desc,sVar1);
        object_desc = pcVar3;
      }
      else {
        sVar2 = strlen(object_name);
        sVar1 = sVar2 + sVar1 + 0xd;
        pcVar3 = (char *)CRYPTO_malloc(sVar1,"ui_lib.c",0x1b1);
        BUF_strlcpy(pcVar3,(char *)&local_24,sVar1);
        BUF_strlcat(pcVar3,object_desc,sVar1);
        BUF_strlcat(pcVar3,(char *)&local_2c,sVar1);
        BUF_strlcat(pcVar3,object_name,sVar1);
        object_desc = pcVar3;
      }
      BUF_strlcat(object_desc,(char *)local_30,sVar1);
    }
  }
  else {
    object_desc = (char *)(**(code **)(*(int *)ui_method + 0x18))();
  }
  if (local_1c == __TMC_END__) {
    return object_desc;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

