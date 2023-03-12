
undefined4 aes_gcm_ctrl(int *param_1,undefined4 param_2,size_t param_3,int *param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  char cVar8;
  ushort uVar9;
  size_t __n;
  
  iVar2 = param_1[0x18];
  switch(param_2) {
  case 0:
    iVar5 = *param_1;
    *(undefined4 *)(iVar2 + 0xf4) = 0;
    *(undefined4 *)(iVar2 + 0xf8) = 0;
    uVar7 = *(undefined4 *)(iVar5 + 0xc);
    *(int **)(iVar2 + 0x274) = param_1 + 8;
    *(undefined4 *)(iVar2 + 0x27c) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x280) = 0;
    *(undefined4 *)(iVar2 + 0x284) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x278) = uVar7;
    uVar7 = 1;
    break;
  default:
    uVar7 = 0xffffffff;
    break;
  case 9:
    if ((int)param_3 < 1) {
      return 0;
    }
    if ((0x10 < (int)param_3) && (*(int *)(iVar2 + 0x278) < (int)param_3)) {
      if (*(int **)(iVar2 + 0x274) != param_1 + 8) {
        CRYPTO_free(*(int **)(iVar2 + 0x274));
      }
      pvVar6 = CRYPTO_malloc(param_3,"e_aes.c",0x2d8);
      *(void **)(iVar2 + 0x274) = pvVar6;
      if (pvVar6 == (void *)0x0) {
        return 0;
      }
    }
    *(size_t *)(iVar2 + 0x278) = param_3;
    uVar7 = 1;
    break;
  case 0x10:
    if (0xf < param_3 - 1) {
      return 0;
    }
    if (param_1[2] == 0) {
      return 0;
    }
    if (*(int *)(iVar2 + 0x27c) < 0) {
      return 0;
    }
    memcpy(param_4,param_1 + 0xc,param_3);
    uVar7 = 1;
    break;
  case 0x11:
    if (0xf < param_3 - 1) {
      return 0;
    }
    if (param_1[2] != 0) {
      return 0;
    }
    memcpy(param_1 + 0xc,param_4,param_3);
    *(size_t *)(iVar2 + 0x27c) = param_3;
    uVar7 = 1;
    break;
  case 0x12:
    if (param_3 == 0xffffffff) {
      memcpy(*(void **)(iVar2 + 0x274),param_4,*(size_t *)(iVar2 + 0x278));
      *(undefined4 *)(iVar2 + 0x280) = 1;
      uVar7 = 1;
    }
    else {
      if ((int)param_3 < 4) {
        return 0;
      }
      if ((int)(*(int *)(iVar2 + 0x278) - param_3) < 8) {
        return 0;
      }
      memcpy(*(void **)(iVar2 + 0x274),param_4,param_3);
      if ((param_1[2] != 0) &&
         (iVar5 = RAND_bytes((uchar *)(param_3 + *(int *)(iVar2 + 0x274)),
                             *(int *)(iVar2 + 0x278) - param_3), iVar5 < 1)) {
        return 0;
      }
      *(undefined4 *)(iVar2 + 0x280) = 1;
      uVar7 = 1;
    }
    break;
  case 0x13:
    if (*(int *)(iVar2 + 0x280) == 0) {
      return 0;
    }
    if (*(int *)(iVar2 + 0xf4) == 0) {
      return 0;
    }
    CRYPTO_gcm128_setiv(iVar2 + 0xfc,*(undefined4 *)(iVar2 + 0x274),*(undefined4 *)(iVar2 + 0x278));
    __n = *(size_t *)(iVar2 + 0x278);
    if (((int)param_3 < 1) || ((int)__n < (int)param_3)) {
      iVar5 = 0;
    }
    else {
      iVar5 = __n - param_3;
      __n = param_3;
    }
    memcpy(param_4,(void *)(iVar5 + *(int *)(iVar2 + 0x274)),__n);
    iVar5 = *(int *)(iVar2 + 0x278);
    iVar3 = *(int *)(iVar2 + 0x274);
    pcVar1 = (char *)(iVar3 + -1 + iVar5);
    cVar8 = *pcVar1 + '\x01';
    *pcVar1 = cVar8;
    if (cVar8 == '\0') {
      pcVar1 = (char *)(iVar3 + -2 + iVar5);
      *pcVar1 = *pcVar1 + '\x01';
      if (*pcVar1 == '\0') {
        pcVar1 = (char *)(iVar3 + -3 + iVar5);
        *pcVar1 = *pcVar1 + '\x01';
        if (*pcVar1 == '\0') {
          pcVar1 = (char *)(iVar3 + -4 + iVar5);
          *pcVar1 = *pcVar1 + '\x01';
          if (*pcVar1 == '\0') {
            pcVar1 = (char *)(iVar3 + -5 + iVar5);
            *pcVar1 = *pcVar1 + '\x01';
            if (*pcVar1 == '\0') {
              pcVar1 = (char *)(iVar3 + -6 + iVar5);
              *pcVar1 = *pcVar1 + '\x01';
              if (*pcVar1 == '\0') {
                pcVar1 = (char *)(iVar3 + -7 + iVar5);
                *pcVar1 = *pcVar1 + '\x01';
                if (*pcVar1 == '\0') {
                  pcVar1 = (char *)(iVar3 + iVar5 + -8);
                  *pcVar1 = *pcVar1 + '\x01';
                }
              }
            }
          }
        }
      }
    }
    *(undefined4 *)(iVar2 + 0xf8) = 1;
    uVar7 = 1;
    break;
  case 0x16:
    if (param_3 != 0xd) {
      return 0;
    }
    param_1[0xc] = *param_4;
    param_1[0xd] = param_4[1];
    param_1[0xe] = param_4[2];
    iVar5 = param_1[2];
    *(undefined *)(param_1 + 0xf) = *(undefined *)(param_4 + 3);
    *(undefined4 *)(iVar2 + 0x284) = 0xd;
    uVar9 = *(ushort *)((int)param_1 + 0x3b) << 8 | *(ushort *)((int)param_1 + 0x3b) >> 8;
    sVar4 = uVar9 - 8;
    if (iVar5 == 0) {
      sVar4 = uVar9 - 0x18;
    }
    *(char *)(param_1 + 0xf) = (char)sVar4;
    uVar7 = 0x10;
    *(char *)((int)param_1 + 0x3b) = (char)((ushort)sVar4 >> 8);
    break;
  case 0x18:
    if (*(int *)(iVar2 + 0x280) == 0) {
      return 0;
    }
    if (*(int *)(iVar2 + 0xf4) == 0) {
      return 0;
    }
    if (param_1[2] != 0) {
      return 0;
    }
    memcpy((void *)((*(int *)(iVar2 + 0x278) - param_3) + *(int *)(iVar2 + 0x274)),param_4,param_3);
    CRYPTO_gcm128_setiv(iVar2 + 0xfc,*(undefined4 *)(iVar2 + 0x274),*(undefined4 *)(iVar2 + 0x278));
    *(undefined4 *)(iVar2 + 0xf8) = 1;
    uVar7 = 1;
  }
  return uVar7;
}

