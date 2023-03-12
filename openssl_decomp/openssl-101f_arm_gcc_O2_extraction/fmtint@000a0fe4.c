
void fmtint(void **param_1,void **param_2,uint *param_3,uint *param_4,int param_5,int param_6,
           int param_7,int param_8,uint param_9,uint param_10)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  void *pvVar4;
  uint num;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 uVar9;
  bool bVar10;
  longlong lVar11;
  uint local_74;
  char *local_6c;
  uint local_5c;
  uint local_4c;
  char acStack_48 [28];
  int local_2c;
  
  local_2c = __TMC_END__;
  param_9 = param_9 & ~((int)param_9 >> 0x1f);
  if ((int)(param_10 << 0x19) < 0) {
    local_5c = 0;
    local_4c = 0;
  }
  else if (param_6 < 0) {
    bVar10 = param_5 != 0;
    param_5 = -param_5;
    param_6 = -param_6 - (uint)bVar10;
    local_5c = 1;
    local_4c = 0x2d;
  }
  else if ((int)(param_10 << 0x1e) < 0) {
    local_4c = 0x2b;
    local_5c = 1;
  }
  else {
    local_5c = param_10 & 4;
    local_4c = local_5c;
    if (local_5c != 0) {
      local_5c = 1;
      local_4c = 0x20;
    }
  }
  if ((int)(param_10 << 0x1c) < 0) {
    if (param_7 == 8) {
      local_6c = "0";
    }
    else {
      local_6c = "0x";
      if (param_7 != 0x10) {
        local_6c = "";
      }
    }
  }
  else {
    local_6c = "";
  }
  if ((param_10 & 0x20) == 0) {
    lVar11 = CONCAT44(param_6,param_5);
    uVar6 = param_10 & 0x20;
    do {
      uVar3 = uVar6;
      uVar9 = (undefined4)((ulonglong)lVar11 >> 0x20);
      iVar5 = param_7;
      __aeabi_uldivmod((int)lVar11,uVar9,param_7,0);
      uVar6 = uVar3 + 1;
      acStack_48[uVar3] = "0123456789abcdef"[iVar5];
      lVar11 = __aeabi_uldivmod((int)lVar11,uVar9,param_7,0);
    } while ((int)uVar6 < 0x1a && lVar11 != 0);
  }
  else {
    lVar11 = CONCAT44(param_6,param_5);
    uVar6 = 0;
    do {
      uVar3 = uVar6;
      uVar9 = (undefined4)((ulonglong)lVar11 >> 0x20);
      iVar5 = param_7;
      __aeabi_uldivmod((int)lVar11,uVar9,param_7,0);
      uVar6 = uVar3 + 1;
      acStack_48[uVar3] = "0123456789ABCDEF"[iVar5];
      lVar11 = __aeabi_uldivmod((int)lVar11,uVar9,param_7);
    } while ((int)uVar6 < 0x1a && lVar11 != 0);
  }
  if (uVar6 == 0x1a) {
    uVar6 = uVar3;
  }
  acStack_48[uVar6] = '\0';
  sVar2 = strlen(local_6c);
  uVar3 = uVar6;
  if ((int)uVar6 < (int)param_9) {
    uVar3 = param_9;
  }
  uVar7 = param_9 - uVar6 & ~((int)(param_9 - uVar6) >> 0x1f);
  uVar3 = ((param_8 - uVar3) - local_5c) - sVar2;
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  local_74 = uVar3;
  if (((int)(param_10 << 0x1b) < 0) && (local_74 = 0, (int)uVar7 < (int)uVar3)) {
    uVar7 = uVar3;
  }
  if ((param_10 & 1) == 0) {
    if (0 < (int)local_74) {
      do {
        uVar3 = *param_3;
        if (param_2 == (void **)0x0) {
          if (uVar3 < *param_4) goto LAB_000a13b0;
        }
        else {
          while (num = *param_4, num <= uVar3) {
            while (pvVar4 = *param_2, pvVar4 != (void *)0x0) {
              *param_4 = num + 0x400;
              pvVar4 = CRYPTO_realloc(pvVar4,num + 0x400,"b_print.c",0x2ed);
              uVar3 = *param_3;
              num = *param_4;
              *param_2 = pvVar4;
              if (uVar3 < num) goto LAB_000a13b0;
            }
            if (num == 0) {
              num = 0x400;
              *param_4 = 0x400;
            }
            pvVar4 = CRYPTO_malloc(num,"b_print.c",0x2e5);
            uVar3 = *param_3;
            *param_2 = pvVar4;
            if (uVar3 != 0) {
              memcpy(pvVar4,*param_1,uVar3);
              uVar3 = *param_3;
            }
            *param_1 = (void *)0x0;
          }
LAB_000a13b0:
          pvVar4 = *param_1;
          if (pvVar4 == (void *)0x0) {
            pvVar4 = *param_2;
          }
          *param_3 = uVar3 + 1;
          *(undefined *)((int)pvVar4 + uVar3) = 0x20;
        }
        local_74 = local_74 - 1;
      } while (local_74 != 0);
    }
  }
  else {
    local_74 = -local_74;
  }
  if (local_5c != 0) {
    doapr_outch(param_1,param_2,param_3,param_4,local_4c);
  }
  cVar1 = *local_6c;
  while (cVar1 != '\0') {
    doapr_outch(param_1,param_2,param_3,param_4,cVar1);
    local_6c = local_6c + 1;
    cVar1 = *local_6c;
  }
  for (; uVar7 != 0; uVar7 = uVar7 - 1) {
    doapr_outch(param_1,param_2,param_3,param_4,0x30);
  }
  if (uVar6 != 0) {
    pcVar8 = acStack_48 + uVar6;
    do {
      while( true ) {
        uVar6 = uVar6 - 1;
        pcVar8 = pcVar8 + -1;
        cVar1 = *pcVar8;
        uVar3 = *param_3;
        if (param_2 == (void **)0x0) break;
        while (uVar7 = *param_4, uVar7 <= uVar3) {
          while (pvVar4 = *param_2, pvVar4 != (void *)0x0) {
            *param_4 = uVar7 + 0x400;
            pvVar4 = CRYPTO_realloc(pvVar4,uVar7 + 0x400,"b_print.c",0x2ed);
            uVar3 = *param_3;
            uVar7 = *param_4;
            *param_2 = pvVar4;
            if (uVar3 < uVar7) goto LAB_000a11ba;
          }
          if (uVar7 == 0) {
            uVar7 = 0x400;
            *param_4 = 0x400;
          }
          pvVar4 = CRYPTO_malloc(uVar7,"b_print.c",0x2e5);
          uVar3 = *param_3;
          *param_2 = pvVar4;
          if (uVar3 != 0) {
            memcpy(pvVar4,*param_1,uVar3);
            uVar3 = *param_3;
          }
          *param_1 = (void *)0x0;
        }
LAB_000a11ba:
        pvVar4 = *param_1;
        if (pvVar4 == (void *)0x0) {
          pvVar4 = *param_2;
        }
        *param_3 = uVar3 + 1;
        *(char *)((int)pvVar4 + uVar3) = cVar1;
        if (uVar6 == 0) goto joined_r0x000a11de;
      }
      if (uVar3 < *param_4) goto LAB_000a11ba;
    } while (uVar6 != 0);
  }
joined_r0x000a11de:
  do {
    if (local_74 == 0) {
      if (local_2c == __TMC_END__) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    uVar6 = *param_3;
    if (param_2 == (void **)0x0) {
      if (uVar6 < *param_4) goto LAB_000a1216;
    }
    else {
      while (uVar3 = *param_4, uVar3 <= uVar6) {
        while (pvVar4 = *param_2, pvVar4 != (void *)0x0) {
          *param_4 = uVar3 + 0x400;
          pvVar4 = CRYPTO_realloc(pvVar4,uVar3 + 0x400,"b_print.c",0x2ed);
          uVar6 = *param_3;
          uVar3 = *param_4;
          *param_2 = pvVar4;
          if (uVar6 < uVar3) goto LAB_000a1216;
        }
        if (uVar3 == 0) {
          uVar3 = 0x400;
          *param_4 = 0x400;
        }
        pvVar4 = CRYPTO_malloc(uVar3,"b_print.c",0x2e5);
        uVar6 = *param_3;
        *param_2 = pvVar4;
        if (uVar6 != 0) {
          memcpy(pvVar4,*param_1,uVar6);
          uVar6 = *param_3;
        }
        *param_1 = (void *)0x0;
      }
LAB_000a1216:
      pvVar4 = *param_1;
      if (pvVar4 == (void *)0x0) {
        pvVar4 = *param_2;
      }
      *param_3 = uVar6 + 1;
      *(undefined *)((int)pvVar4 + uVar6) = 0x20;
    }
    local_74 = local_74 + 1;
  } while( true );
}

