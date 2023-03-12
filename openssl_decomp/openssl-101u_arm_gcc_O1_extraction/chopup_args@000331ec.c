
undefined4 chopup_args(void **param_1,byte *param_2,uint *param_3,void **param_4)

{
  byte bVar1;
  byte bVar2;
  void *addr;
  void *pvVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  *param_3 = 0;
  pvVar3 = param_1[1];
  *param_4 = (void *)0x0;
  if (pvVar3 == (void *)0x0) {
    param_1[1] = &DAT_00000014;
    addr = CRYPTO_malloc(0x50,"apps.c",0x185);
    *param_1 = addr;
    if (addr == (void *)0x0) {
      return 0;
    }
    pvVar3 = param_1[1];
  }
  else {
    addr = *param_1;
  }
  if (0 < (int)pvVar3) {
    pvVar4 = (void *)0x0;
    do {
      *(undefined4 *)((int)addr + (int)pvVar4 * 4) = 0;
      pvVar4 = (void *)((int)pvVar4 + 1);
      addr = *param_1;
    } while (pvVar4 != pvVar3);
  }
  uVar5 = (uint)*param_2;
  uVar6 = 0;
  uVar7 = uVar5;
  do {
    if (uVar5 == 0) {
LAB_00033278:
      *param_3 = uVar7;
      *param_4 = addr;
      return 1;
    }
    while( true ) {
      bVar9 = 0x1f < uVar5;
      if (uVar5 != 0x20) {
        bVar9 = uVar5 != 9;
      }
      if (!bVar9 || (uVar5 == 0x20 || uVar5 == 10)) break;
      if ((int)param_1[1] <= (int)uVar6) {
        pvVar3 = (void *)((int)param_1[1] + 0x14);
        addr = CRYPTO_realloc(addr,(int)pvVar3 * 4,"apps.c",0x19c);
        if (addr == (void *)0x0) {
          return 0;
        }
        *param_1 = addr;
        param_1[1] = pvVar3;
        iVar8 = uVar6 << 2;
        if ((int)uVar6 < (int)pvVar3) {
          do {
            *(undefined4 *)((int)addr + iVar8) = 0;
            iVar8 = iVar8 + 4;
            addr = *param_1;
          } while (iVar8 != (int)pvVar3 * 4);
        }
      }
      iVar8 = uVar6 * 4;
      *(byte **)((int)addr + iVar8) = param_2;
      uVar6 = uVar6 + 1;
      bVar1 = *param_2;
      if (bVar1 != 0x27 && bVar1 != 0x22) {
        if (bVar1 != 0) {
          bVar9 = 0x1f < bVar1;
          if (bVar1 != 0x20) {
            bVar9 = bVar1 != 9;
          }
          if (bVar9 && (bVar1 != 0x20 && bVar1 != 10)) {
            do {
              param_2 = param_2 + 1;
              bVar1 = *param_2;
              if (bVar1 == 0) goto LAB_00033276;
              bVar9 = 0x1f < bVar1;
              if (bVar1 != 0x20) {
                bVar9 = bVar1 != 9;
              }
            } while (bVar9 && (bVar1 != 0x20 && bVar1 != 10));
          }
          *param_2 = 0;
          bVar1 = param_2[1];
          goto LAB_000332b4;
        }
LAB_00033276:
        addr = *param_1;
        uVar7 = uVar6;
        goto LAB_00033278;
      }
      *(int *)((int)*param_1 + iVar8) = *(int *)((int)*param_1 + iVar8) + 1;
      bVar2 = param_2[1];
      param_2 = param_2 + 1;
      while ((bVar2 != 0 && (bVar1 != bVar2))) {
        param_2 = param_2 + 1;
        bVar2 = *param_2;
      }
      bVar1 = param_2[1];
      *param_2 = 0;
LAB_000332b4:
      uVar5 = (uint)bVar1;
      param_2 = param_2 + 1;
      if (uVar5 == 0) goto LAB_00033276;
      addr = *param_1;
    }
    uVar5 = (uint)param_2[1];
    param_2 = param_2 + 1;
    uVar7 = uVar6;
  } while( true );
}

