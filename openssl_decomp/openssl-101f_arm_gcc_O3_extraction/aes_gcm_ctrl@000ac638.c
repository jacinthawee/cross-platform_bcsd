
undefined4 aes_gcm_ctrl(int *param_1,undefined4 param_2,size_t param_3,int *param_4)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  size_t __n;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = param_1[0x18];
  switch(param_2) {
  case 0:
    iVar4 = *param_1;
    uVar2 = 1;
    *(undefined4 *)(iVar8 + 0xf4) = 0;
    uVar5 = *(undefined4 *)(iVar4 + 0xc);
    *(undefined4 *)(iVar8 + 0xf8) = 0;
    *(int **)(iVar8 + 0x278) = param_1 + 8;
    *(undefined4 *)(iVar8 + 0x284) = 0;
    *(undefined4 *)(iVar8 + 0x27c) = uVar5;
    *(undefined4 *)(iVar8 + 0x280) = 0xffffffff;
    *(undefined4 *)(iVar8 + 0x288) = 0xffffffff;
    break;
  default:
    uVar2 = 0xffffffff;
    break;
  case 9:
    if ((int)param_3 < 1) {
      return 0;
    }
    if ((0x10 < (int)param_3) && (*(int *)(iVar8 + 0x27c) < (int)param_3)) {
      if (*(int **)(iVar8 + 0x278) != param_1 + 8) {
        CRYPTO_free(*(int **)(iVar8 + 0x278));
      }
      pvVar3 = CRYPTO_malloc(param_3,"e_aes.c",0x2d8);
      *(void **)(iVar8 + 0x278) = pvVar3;
      if (pvVar3 == (void *)0x0) {
        return 0;
      }
    }
    *(size_t *)(iVar8 + 0x27c) = param_3;
    uVar2 = 1;
    break;
  case 0x10:
    if (0xf < param_3 - 1) {
      return 0;
    }
    if (param_1[2] == 0) {
      return 0;
    }
    if (*(int *)(iVar8 + 0x280) < 0) {
      return 0;
    }
    memcpy(param_4,param_1 + 0xc,param_3);
    uVar2 = 1;
    break;
  case 0x11:
    if (0xf < param_3 - 1) {
      return 0;
    }
    if (param_1[2] != 0) {
      return 0;
    }
    memcpy(param_1 + 0xc,param_4,param_3);
    *(size_t *)(iVar8 + 0x280) = param_3;
    uVar2 = 1;
    break;
  case 0x12:
    if (param_3 == 0xffffffff) {
      memcpy(*(void **)(iVar8 + 0x278),param_4,*(size_t *)(iVar8 + 0x27c));
      uVar2 = 1;
      *(undefined4 *)(iVar8 + 0x284) = 1;
    }
    else {
      if ((int)param_3 < 4) {
        return 0;
      }
      if ((int)(*(int *)(iVar8 + 0x27c) - param_3) < 8) {
        return 0;
      }
      memcpy(*(void **)(iVar8 + 0x278),param_4,param_3);
      if ((param_1[2] != 0) &&
         (iVar4 = RAND_bytes((uchar *)(*(int *)(iVar8 + 0x278) + param_3),
                             *(int *)(iVar8 + 0x27c) - param_3), iVar4 < 1)) {
        return 0;
      }
      uVar2 = 1;
      *(undefined4 *)(iVar8 + 0x284) = 1;
    }
    break;
  case 0x13:
    if (*(int *)(iVar8 + 0x284) == 0) {
      return 0;
    }
    if (*(int *)(iVar8 + 0xf4) == 0) {
      return 0;
    }
    CRYPTO_gcm128_setiv(iVar8 + 0x100,*(undefined4 *)(iVar8 + 0x278),*(undefined4 *)(iVar8 + 0x27c))
    ;
    __n = *(size_t *)(iVar8 + 0x27c);
    if (((int)param_3 < 1) || ((int)__n < (int)param_3)) {
      iVar4 = 0;
    }
    else {
      iVar4 = __n - param_3;
      __n = param_3;
    }
    memcpy(param_4,(void *)(*(int *)(iVar8 + 0x278) + iVar4),__n);
    iVar4 = *(int *)(iVar8 + 0x278);
    iVar9 = *(int *)(iVar8 + 0x27c) + -8;
    iVar7 = iVar4 + iVar9;
    cVar1 = *(char *)(iVar7 + 7) + '\x01';
    *(char *)(iVar7 + 7) = cVar1;
    if (((((cVar1 == '\0') &&
          (cVar1 = *(char *)(iVar7 + 6) + '\x01', *(char *)(iVar7 + 6) = cVar1, cVar1 == '\0')) &&
         (cVar1 = *(char *)(iVar7 + 5) + '\x01', *(char *)(iVar7 + 5) = cVar1, cVar1 == '\0')) &&
        ((cVar1 = *(char *)(iVar7 + 4) + '\x01', *(char *)(iVar7 + 4) = cVar1, cVar1 == '\0' &&
         (cVar1 = *(char *)(iVar7 + 3) + '\x01', *(char *)(iVar7 + 3) = cVar1, cVar1 == '\0')))) &&
       ((cVar1 = *(char *)(iVar7 + 2) + '\x01', *(char *)(iVar7 + 2) = cVar1, cVar1 == '\0' &&
        (cVar1 = *(char *)(iVar7 + 1) + '\x01', *(char *)(iVar7 + 1) = cVar1, cVar1 == '\0')))) {
      *(char *)(iVar4 + iVar9) = *(char *)(iVar4 + iVar9) + '\x01';
    }
    uVar2 = 1;
    *(undefined4 *)(iVar8 + 0xf8) = 1;
    break;
  case 0x16:
    if (param_3 != 0xd) {
      return 0;
    }
    iVar9 = *param_4;
    iVar4 = param_4[1];
    param_1[0xe] = param_4[2];
    param_1[0xc] = iVar9;
    param_1[0xd] = iVar4;
    iVar4 = param_1[2];
    *(undefined *)(param_1 + 0xf) = *(undefined *)(param_4 + 3);
    *(undefined4 *)(iVar8 + 0x288) = 0xd;
    if (iVar4 == 0) {
      sVar6 = -0x18;
    }
    else {
      sVar6 = -8;
    }
    sVar6 = CONCAT11(*(undefined *)((int)param_1 + 0x3b),*(undefined *)(param_1 + 0xf)) + sVar6;
    *(char *)(param_1 + 0xf) = (char)sVar6;
    uVar2 = 0x10;
    *(char *)((int)param_1 + 0x3b) = (char)((ushort)sVar6 >> 8);
    break;
  case 0x18:
    if (*(int *)(iVar8 + 0x284) == 0) {
      return 0;
    }
    if (*(int *)(iVar8 + 0xf4) == 0) {
      return 0;
    }
    if (param_1[2] != 0) {
      return 0;
    }
    memcpy((void *)((*(int *)(iVar8 + 0x27c) - param_3) + *(int *)(iVar8 + 0x278)),param_4,param_3);
    CRYPTO_gcm128_setiv(iVar8 + 0x100,*(undefined4 *)(iVar8 + 0x278),*(undefined4 *)(iVar8 + 0x27c))
    ;
    uVar2 = 1;
    *(undefined4 *)(iVar8 + 0xf8) = 1;
  }
  return uVar2;
}

