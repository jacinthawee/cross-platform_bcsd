
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_ERR_strings(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  char *pcVar5;
  char **ppcVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    puVar8 = err_fns;
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)puVar8,10,(char *)0x1,(int)"err.c");
  }
  piVar3 = (int *)ERR_str_libraries;
  iVar1 = ERR_str_libraries._0_4_;
  while (iVar1 != 0) {
    (**(code **)(err_fns + 0xc))(piVar3);
    iVar1 = piVar3[2];
    piVar3 = piVar3 + 2;
  }
  piVar3 = (int *)ERR_str_reasons;
  iVar1 = ERR_str_reasons._0_4_;
  while (iVar1 != 0) {
    (**(code **)(err_fns + 0xc))(piVar3);
    iVar1 = piVar3[2];
    piVar3 = piVar3 + 2;
  }
  ppcVar6 = (char **)ERR_str_functs;
  pcVar5 = ERR_str_functs._0_4_;
  while (pcVar5 != (char *)0x0) {
    *ppcVar6 = (char *)((uint)pcVar5 | 0x2000000);
    (**(code **)(err_fns + 0xc))(ppcVar6);
    pcVar5 = ppcVar6[2];
    ppcVar6 = ppcVar6 + 2;
  }
  CRYPTO_lock(0,5,(char *)0x1,(int)"err.c");
  if (init_5392 == 0) {
    uVar10 = 0x247;
    pcVar7 = "err.c";
    uVar9 = 1;
    CRYPTO_lock((int)pcVar5,6,(char *)0x1,(int)"err.c");
  }
  else {
    CRYPTO_lock((int)pcVar5,6,(char *)0x1,(int)"err.c");
    CRYPTO_lock((int)pcVar5,9,(char *)0x1,(int)"err.c");
    if (init_5392 == 0) {
      uVar10 = 0x24f;
    }
    else {
      ppcVar6 = (char **)(SYS_str_reasons + 4);
      puVar8 = strerror_tab_5390;
      pcVar7 = (char *)0x1;
      do {
        ppcVar6[-1] = pcVar7;
        if (*ppcVar6 == (char *)0x0) {
          pcVar5 = strerror((int)pcVar7);
          if (pcVar5 == (char *)0x0) {
            pcVar5 = *ppcVar6;
            if (pcVar5 == (char *)0x0) {
              *ppcVar6 = "unknown";
            }
          }
          else {
            pcVar5 = strncpy(puVar8,pcVar5,0x20);
            puVar8[0x1f] = '\0';
            *ppcVar6 = puVar8;
          }
        }
        pcVar7 = pcVar7 + 1;
        ppcVar6 = ppcVar6 + 2;
        puVar8 = puVar8 + 0x20;
      } while (pcVar7 != (char *)0x80);
      uVar10 = 0x26c;
      init_5392 = 0;
    }
    pcVar7 = "err.c";
    uVar9 = 1;
    CRYPTO_lock((int)pcVar5,10,(char *)0x1,(int)"err.c");
  }
  puVar4 = (uint *)SYS_str_reasons;
  uVar2 = SYS_str_reasons._0_4_;
  while (uVar2 != 0) {
    *puVar4 = uVar2 | 0x2000000;
    (**(code **)(err_fns + 0xc))(puVar4,uVar9,pcVar7,uVar10);
    uVar2 = puVar4[2];
    puVar4 = puVar4 + 2;
  }
  return;
}

