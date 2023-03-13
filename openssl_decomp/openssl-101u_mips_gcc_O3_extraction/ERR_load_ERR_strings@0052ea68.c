
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_ERR_strings(void)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  char **ppcVar5;
  char *pcVar6;
  undefined1 *puVar7;
  
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  piVar2 = (int *)ERR_str_libraries;
  iVar3 = ERR_str_libraries._0_4_;
  while (iVar3 != 0) {
    (**(code **)(err_fns + 0xc))(piVar2);
    iVar3 = piVar2[2];
    piVar2 = piVar2 + 2;
  }
  piVar2 = (int *)ERR_str_reasons;
  iVar3 = ERR_str_reasons._0_4_;
  while (iVar3 != 0) {
    (**(code **)(err_fns + 0xc))(piVar2);
    iVar3 = piVar2[2];
    piVar2 = piVar2 + 2;
  }
  puVar1 = (uint *)ERR_str_functs;
  uVar4 = ERR_str_functs._0_4_;
  puVar7 = err_fns;
  while (err_fns = puVar7, uVar4 != 0) {
    *puVar1 = uVar4 | 0x2000000;
    (**(code **)(puVar7 + 0xc))(puVar1);
    uVar4 = puVar1[2];
    puVar1 = puVar1 + 2;
    puVar7 = err_fns;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(5,1,"err.c",0x247);
  if (init_5412 == 0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(6,1,"err.c",0x249);
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a8144)(6,1,"err.c",0x24d);
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x24e);
    if (init_5412 == 0) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x250);
    }
    else {
      puVar7 = strerror_tab_5410;
      pcVar6 = (char *)0x1;
      ppcVar5 = (char **)(SYS_str_reasons + 4);
      do {
        while (ppcVar5[-1] = pcVar6, *ppcVar5 != (char *)0x0) {
LAB_0052ebdc:
          pcVar6 = pcVar6 + 1;
          ppcVar5 = ppcVar5 + 2;
          puVar7 = puVar7 + 0x20;
          if (pcVar6 == (char *)0x80) goto LAB_0052ec3c;
        }
        iVar3 = (*(code *)PTR_strerror_006a9a4c)(pcVar6);
        if (iVar3 == 0) {
          if (*ppcVar5 == (char *)0x0) {
            *ppcVar5 = "unknown";
          }
          goto LAB_0052ebdc;
        }
        pcVar6 = pcVar6 + 1;
        (*(code *)PTR_strncpy_006a99e0)(puVar7,iVar3,0x20);
        puVar7[0x1f] = '\0';
        *ppcVar5 = puVar7;
        puVar7 = puVar7 + 0x20;
        ppcVar5 = ppcVar5 + 2;
      } while (pcVar6 != (char *)0x80);
LAB_0052ec3c:
      init_5412 = 0;
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x26c);
    }
  }
  puVar1 = (uint *)SYS_str_reasons;
  uVar4 = SYS_str_reasons._0_4_;
  puVar7 = err_fns;
  while (uVar4 != 0) {
    err_fns = puVar7;
    *puVar1 = uVar4 | 0x2000000;
    (**(code **)(puVar7 + 0xc))(puVar1);
    uVar4 = puVar1[2];
    puVar1 = puVar1 + 2;
    puVar7 = err_fns;
  }
  err_fns = puVar7;
  return;
}

