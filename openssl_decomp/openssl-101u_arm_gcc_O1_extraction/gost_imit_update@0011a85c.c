
void gost_imit_update(int param_1,undefined *param_2,uint param_3)

{
  uint uVar1;
  undefined *__src;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  uint __n;
  uint *puVar7;
  int iVar8;
  undefined auStack_34 [8];
  int local_2c;
  
  iVar8 = *(int *)(param_1 + 0xc);
  iVar5 = *(int *)(iVar8 + 0x103c);
  local_2c = __stack_chk_guard;
  if (iVar5 == 0) {
    ERR_GOST_error(0x73,0x74,"gost_crypt.c",0x21b);
    goto LAB_0011aa66;
  }
  uVar4 = *(uint *)(iVar8 + 0x1038);
  __n = param_3;
  __src = param_2;
  if (uVar4 != 0) {
    uVar1 = param_3;
    if (param_3 != 0) {
      uVar1 = 1;
    }
    if (7 < uVar4) {
      uVar1 = 0;
    }
    uVar3 = uVar4;
    if (uVar1 == 0) {
LAB_0011aa7c:
      if (uVar3 != 8) {
        *(uint *)(iVar8 + 0x1038) = uVar3;
        iVar5 = 1;
        goto LAB_0011aa66;
      }
    }
    else {
      iVar5 = param_3 - 1;
      uVar3 = uVar4 + 1;
      if (iVar5 != 0) {
        iVar5 = 1;
      }
      __src = param_2 + 1;
      __n = param_3 - 1;
      if (7 < uVar3) {
        iVar5 = 0;
      }
      *(undefined *)(iVar8 + uVar4 + 0x1028) = *param_2;
      if (iVar5 == 0) goto LAB_0011aa7c;
      iVar5 = param_3 - 2;
      uVar1 = uVar4 + 2;
      if (iVar5 != 0) {
        iVar5 = 1;
      }
      __src = param_2 + 2;
      if (7 < uVar1) {
        iVar5 = 0;
      }
      *(undefined *)(iVar8 + uVar3 + 0x1028) = param_2[1];
      __n = param_3 - 2;
      if (iVar5 == 0) {
LAB_0011aaa0:
        if (uVar1 != 8) {
          *(uint *)(iVar8 + 0x1038) = uVar1;
          iVar5 = 1;
          goto LAB_0011aa66;
        }
      }
      else {
        iVar2 = param_3 - 3;
        iVar5 = iVar8 + uVar1;
        uVar1 = uVar4 + 3;
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        __src = param_2 + 3;
        if (7 < uVar1) {
          iVar2 = 0;
        }
        *(undefined *)(iVar5 + 0x1028) = param_2[2];
        __n = param_3 - 3;
        if (iVar2 == 0) goto LAB_0011aaa0;
        iVar2 = param_3 - 4;
        iVar5 = iVar8 + uVar1;
        uVar1 = uVar4 + 4;
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        __src = param_2 + 4;
        if (7 < uVar1) {
          iVar2 = 0;
        }
        *(undefined *)(iVar5 + 0x1028) = param_2[3];
        __n = param_3 - 4;
        if (iVar2 == 0) goto LAB_0011aaa0;
        iVar2 = param_3 - 5;
        iVar5 = iVar8 + uVar1;
        uVar1 = uVar4 + 5;
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        __src = param_2 + 5;
        if (7 < uVar1) {
          iVar2 = 0;
        }
        *(undefined *)(iVar5 + 0x1028) = param_2[4];
        __n = param_3 - 5;
        if (iVar2 == 0) goto LAB_0011aaa0;
        uVar3 = uVar4 + 6;
        iVar5 = param_3 - 6;
        __src = param_2 + 6;
        if (iVar5 != 0) {
          iVar5 = 1;
        }
        __n = param_3 - 6;
        *(undefined *)(iVar8 + uVar1 + 0x1028) = param_2[5];
        if (7 < uVar3) {
          iVar5 = 0;
        }
        if (iVar5 == 0) goto LAB_0011aa7c;
        __n = param_3 - 7;
        __src = param_2 + 7;
        *(undefined *)(iVar8 + 0x102f) = param_2[6];
      }
    }
    if ((*(int *)(iVar8 + 0x1034) != 0) && (*(int *)(iVar8 + 0x1030) == 0x400)) {
      cryptopro_key_meshing(iVar8,auStack_34);
    }
    mac_block(iVar8,iVar8 + 0x1020,iVar8 + 0x1028);
    *(uint *)(iVar8 + 0x1030) = (*(uint *)(iVar8 + 0x1030) & 0x3ff) + 8;
  }
  if (8 < __n) {
    puVar7 = (uint *)(iVar8 + 0x1030);
    puVar6 = __src;
    uVar4 = __n;
    do {
      if ((*(int *)(iVar8 + 0x1034) != 0) && (*puVar7 == 0x400)) {
        cryptopro_key_meshing(iVar8,auStack_34);
      }
      uVar4 = uVar4 - 8;
      mac_block(iVar8,iVar8 + 0x1020,puVar6);
      puVar6 = puVar6 + 8;
      *puVar7 = (*puVar7 & 0x3ff) + 8;
    } while (8 < uVar4);
    uVar4 = __n - 9;
    __n = (__n - 8) - (uVar4 & 0xfffffff8);
    __src = __src + ((uVar4 >> 3) + 1) * 8;
  }
  if (__n != 0) {
    memcpy((void *)(iVar8 + 0x1028),__src,__n);
  }
  iVar5 = 1;
  *(uint *)(iVar8 + 0x1038) = __n;
LAB_0011aa66:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar5);
}

