
char * UI_construct_prompt(UI *ui_method,char *object_desc,char *object_name)

{
  char *dst;
  size_t sVar1;
  size_t sVar2;
  int in_GS_OFFSET;
  undefined2 local_2f;
  undefined4 local_2d;
  undefined2 local_29;
  undefined4 local_27;
  undefined2 local_23;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(code **)(*(int *)ui_method + 0x18) == (code *)0x0) {
    local_27 = 0x65746e45;
    local_23 = 0x2072;
    local_21 = 0;
    local_2d = 0x726f6620;
    local_29 = 0x20;
    local_2f = 0x3a;
    if (object_desc == (char *)0x0) {
      dst = (char *)0x0;
    }
    else {
      sVar1 = strlen(object_desc);
      if (object_name == (char *)0x0) {
        sVar2 = sVar1 + 8;
        dst = (char *)CRYPTO_malloc(sVar2,"ui_lib.c",0x1b1);
        BUF_strlcpy(dst,(char *)&local_27,sVar2);
        BUF_strlcat(dst,object_desc,sVar2);
      }
      else {
        sVar2 = strlen(object_name);
        sVar2 = sVar1 + 0xd + sVar2;
        dst = (char *)CRYPTO_malloc(sVar2,"ui_lib.c",0x1b1);
        BUF_strlcpy(dst,(char *)&local_27,sVar2);
        BUF_strlcat(dst,object_desc,sVar2);
        BUF_strlcat(dst,(char *)&local_2d,sVar2);
        BUF_strlcat(dst,object_name,sVar2);
      }
      BUF_strlcat(dst,(char *)&local_2f,sVar2);
    }
  }
  else {
    dst = (char *)(**(code **)(*(int *)ui_method + 0x18))(ui_method,object_desc,object_name);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return dst;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

