
char * UI_construct_prompt(UI *ui_method,char *object_desc,char *object_name)

{
  undefined *puVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined2 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined local_1e;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (*(code **)(*(int *)ui_method + 0x18) == (code *)0x0) {
    local_1e = 0;
    local_24 = 0x456e7465;
    local_20 = 0x7220;
    local_2c = 0x20666f72;
    local_28 = 0x2000;
    local_30[0] = 0x3a00;
    pcVar2 = (char *)0x0;
    if (object_desc != (char *)0x0) {
      iVar3 = (*(code *)PTR_strlen_006a9a24)(object_desc);
      if (object_name == (char *)0x0) {
        iVar3 = iVar3 + 8;
        pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"ui_lib.c",0x19f);
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar2,&local_24,iVar3);
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar2,object_desc,iVar3);
      }
      else {
        iVar4 = (*(code *)PTR_strlen_006a9a24)(object_name);
        iVar3 = iVar4 + iVar3 + 0xd;
        pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"ui_lib.c",0x19f);
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar2,&local_24,iVar3);
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar2,object_desc,iVar3);
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar2,&local_2c,iVar3);
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar2,object_name,iVar3);
      }
      object_desc = (char *)local_30;
      (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar2,object_desc,iVar3);
    }
  }
  else {
    pcVar2 = (char *)(**(code **)(*(int *)ui_method + 0x18))();
  }
  if (local_1c == *(int *)puVar1) {
    return pcVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pcVar2 = *(char **)(local_1c + 8);
  *(char **)(local_1c + 8) = object_desc;
  return pcVar2;
}

