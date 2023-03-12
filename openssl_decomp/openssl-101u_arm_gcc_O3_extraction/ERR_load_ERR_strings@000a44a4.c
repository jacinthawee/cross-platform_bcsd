
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_ERR_strings(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  undefined *puVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  char *__dest;
  
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  puVar7 = ERR_str_libraries;
  iVar6 = ERR_str_libraries._0_4_;
  while (piVar1 = (int *)PTR_ERR_str_reasons_000a4688, iVar8 = ERR_str_reasons._0_4_, iVar6 != 0) {
    (**(code **)(err_fns + 0xc))(puVar7);
    puVar7 = (undefined1 *)((int)puVar7 + 8);
    iVar6 = *(int *)puVar7;
  }
  while (puVar2 = (uint *)PTR_ERR_str_functs_000a468c, puVar7 = err_fns,
        uVar3 = ERR_str_functs._0_4_, iVar8 != 0) {
    (**(code **)(err_fns + 0xc))(piVar1);
    piVar1 = piVar1 + 2;
    iVar8 = *piVar1;
  }
  while (err_fns = puVar7, uVar3 != 0) {
    *puVar2 = uVar3 | 0x2000000;
    (**(code **)(puVar7 + 0xc))(puVar2);
    puVar2 = puVar2 + 2;
    puVar7 = err_fns;
    uVar3 = *puVar2;
  }
  CRYPTO_lock(5,1,"err.c",0x247);
  if (init_8046 == 0) {
    CRYPTO_lock(6,1,"err.c",0x249);
    puVar2 = (uint *)PTR_SYS_str_reasons_000a4694;
    puVar7 = err_fns;
    uVar3 = SYS_str_reasons._0_4_;
  }
  else {
    CRYPTO_lock(6,1,"err.c",0x24d);
    CRYPTO_lock(9,1,"err.c",0x24e);
    puVar4 = PTR_strerror_tab_8044_000a4690;
    if (init_8046 == 0) {
      CRYPTO_lock(10,1,"err.c",0x250);
      puVar2 = (uint *)PTR_SYS_str_reasons_000a4694;
      puVar7 = err_fns;
      uVar3 = SYS_str_reasons._0_4_;
    }
    else {
      iVar8 = 0;
      iVar6 = 1;
      __dest = PTR_strerror_tab_8044_000a4690;
      do {
        while( true ) {
          *(int *)(puVar4 + iVar8 + -0x400) = iVar6;
          if (*(int *)(puVar4 + iVar8 + -0x3fc) == 0) break;
LAB_000a4582:
          iVar6 = iVar6 + 1;
          iVar8 = iVar8 + 8;
          __dest = __dest + 0x20;
          if (iVar6 == 0x80) goto LAB_000a45d8;
        }
        pcVar5 = strerror(iVar6);
        if (pcVar5 == (char *)0x0) {
          pcVar5 = *(char **)(puVar4 + iVar8 + -0x3fc);
        }
        else {
          strncpy(__dest,pcVar5,0x20);
          *(char **)(puVar4 + iVar8 + -0x3fc) = __dest;
          __dest[0x1f] = '\0';
          pcVar5 = __dest;
        }
        if (pcVar5 != (char *)0x0) goto LAB_000a4582;
        iVar6 = iVar6 + 1;
        *(char **)(puVar4 + iVar8 + -0x3fc) = "unknown";
        iVar8 = iVar8 + 8;
        __dest = __dest + 0x20;
      } while (iVar6 != 0x80);
LAB_000a45d8:
      init_8046 = 0;
      CRYPTO_lock(10,1,"err.c",0x26c);
      puVar2 = (uint *)PTR_SYS_str_reasons_000a4694;
      puVar7 = err_fns;
      uVar3 = SYS_str_reasons._0_4_;
    }
  }
  while (uVar3 != 0) {
    err_fns = puVar7;
    *puVar2 = uVar3 | 0x2000000;
    (**(code **)(puVar7 + 0xc))(puVar2);
    puVar2 = puVar2 + 2;
    puVar7 = err_fns;
    uVar3 = *puVar2;
  }
  err_fns = puVar7;
  return;
}

