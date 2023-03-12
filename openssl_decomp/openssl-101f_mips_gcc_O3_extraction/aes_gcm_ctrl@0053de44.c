
undefined4 aes_gcm_ctrl(int *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar7;
  uint uVar6;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  
  iVar13 = param_1[0x18];
  switch(param_2) {
  case 0:
    iVar11 = *param_1;
    *(undefined4 *)(iVar13 + 0xf4) = 0;
    uVar4 = 1;
    *(undefined4 *)(iVar13 + 0xf8) = 0;
    uVar8 = *(undefined4 *)(iVar11 + 0xc);
    *(int **)(iVar13 + 0x278) = param_1 + 8;
    *(undefined4 *)(iVar13 + 0x280) = 0xffffffff;
    *(undefined4 *)(iVar13 + 0x284) = 0;
    *(undefined4 *)(iVar13 + 0x27c) = uVar8;
    *(undefined4 *)(iVar13 + 0x288) = 0xffffffff;
    break;
  default:
    uVar4 = 0xffffffff;
    break;
  case 9:
    if (param_3 < 1) {
      return 0;
    }
    if ((0x10 < param_3) && (*(int *)(iVar13 + 0x27c) < param_3)) {
      if (*(int **)(iVar13 + 0x278) != param_1 + 8) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      iVar11 = (*(code *)PTR_CRYPTO_malloc_006a8108)(param_3,"e_aes.c",0x2d8);
      *(int *)(iVar13 + 0x278) = iVar11;
      if (iVar11 == 0) {
        return 0;
      }
    }
    *(int *)(iVar13 + 0x27c) = param_3;
    uVar4 = 1;
    break;
  case 0x10:
    if (0xf < param_3 - 1U) {
      return 0;
    }
    if (param_1[2] == 0) {
      return 0;
    }
    if (*(int *)(iVar13 + 0x280) < 0) {
      return 0;
    }
    (*(code *)PTR_memcpy_006aabf4)(param_4,param_1 + 0xc);
    uVar4 = 1;
    break;
  case 0x11:
    if (0xf < param_3 - 1U) {
      return 0;
    }
    if (param_1[2] != 0) {
      return 0;
    }
    (*(code *)PTR_memcpy_006aabf4)(param_1 + 0xc,param_4);
    uVar4 = 1;
    *(int *)(iVar13 + 0x280) = param_3;
    break;
  case 0x12:
    if (param_3 == -1) {
      (*(code *)PTR_memcpy_006aabf4)
                (*(undefined4 *)(iVar13 + 0x278),param_4,*(undefined4 *)(iVar13 + 0x27c));
      uVar4 = 1;
      *(undefined4 *)(iVar13 + 0x284) = 1;
    }
    else {
      if (param_3 < 4) {
        return 0;
      }
      if (*(int *)(iVar13 + 0x27c) - param_3 < 8) {
        return 0;
      }
      (*(code *)PTR_memcpy_006aabf4)(*(undefined4 *)(iVar13 + 0x278),param_4);
      if ((param_1[2] != 0) &&
         (iVar11 = RAND_bytes((uchar *)(*(int *)(iVar13 + 0x278) + param_3),
                              *(int *)(iVar13 + 0x27c) - param_3), iVar11 < 1)) {
        return 0;
      }
      uVar4 = 1;
      *(undefined4 *)(iVar13 + 0x284) = 1;
    }
    break;
  case 0x13:
    if (*(int *)(iVar13 + 0x284) == 0) {
      return 0;
    }
    if (*(int *)(iVar13 + 0xf4) == 0) {
      return 0;
    }
    (*(code *)PTR_CRYPTO_gcm128_setiv_006a8b94)
              (iVar13 + 0x100,*(undefined4 *)(iVar13 + 0x278),*(undefined4 *)(iVar13 + 0x27c));
    iVar11 = *(int *)(iVar13 + 0x27c);
    if ((param_3 < 1) || (iVar11 < param_3)) {
      iVar9 = 0;
    }
    else {
      iVar9 = iVar11 - param_3;
      iVar11 = param_3;
    }
    (*(code *)PTR_memcpy_006aabf4)(param_4,*(int *)(iVar13 + 0x278) + iVar9,iVar11);
    iVar11 = *(int *)(iVar13 + 0x27c);
    iVar9 = *(int *)(iVar13 + 0x278);
    pcVar12 = (char *)(iVar9 + iVar11 + -1);
    cVar7 = *pcVar12 + '\x01';
    *pcVar12 = cVar7;
    if (((((cVar7 == '\0') &&
          (pcVar12 = (char *)(iVar9 + iVar11 + -2), cVar7 = *pcVar12 + '\x01', *pcVar12 = cVar7,
          cVar7 == '\0')) &&
         (pcVar12 = (char *)(iVar9 + iVar11 + -3), cVar7 = *pcVar12 + '\x01', *pcVar12 = cVar7,
         cVar7 == '\0')) &&
        ((pcVar12 = (char *)(iVar9 + iVar11 + -4), cVar7 = *pcVar12 + '\x01', *pcVar12 = cVar7,
         cVar7 == '\0' &&
         (pcVar12 = (char *)(iVar9 + iVar11 + -5), cVar7 = *pcVar12 + '\x01', *pcVar12 = cVar7,
         cVar7 == '\0')))) &&
       ((pcVar12 = (char *)(iVar9 + iVar11 + -6), cVar7 = *pcVar12 + '\x01', *pcVar12 = cVar7,
        cVar7 == '\0' &&
        (pcVar12 = (char *)(iVar9 + iVar11 + -7), cVar7 = *pcVar12 + '\x01', *pcVar12 = cVar7,
        cVar7 == '\0')))) {
      pcVar12 = (char *)(iVar9 + iVar11 + -8);
      *pcVar12 = *pcVar12 + '\x01';
    }
    goto LAB_0053deec;
  case 0x16:
    if (param_3 != 0xd) {
      return 0;
    }
    uVar10 = *param_4;
    uVar6 = param_4[1];
    uVar5 = param_4[2];
    uVar1 = (uint)(param_1 + 0xc) & 3;
    puVar2 = (uint *)((int)(param_1 + 0xc) - uVar1);
    *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar10 >> uVar1 * 8;
    uVar1 = (int)param_1 + 0x33U & 3;
    puVar2 = (uint *)(((int)param_1 + 0x33U) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar10 << (3 - uVar1) * 8;
    param_1[0xd] = uVar6;
    param_1[0xe] = uVar5;
    *(undefined *)(param_1 + 0xf) = *(undefined *)(param_4 + 3);
    *(undefined4 *)(iVar13 + 0x288) = 0xd;
    if (param_1[2] == 0) {
      sVar3 = -0x18;
    }
    else {
      sVar3 = -8;
    }
    uVar4 = 0x10;
    *(short *)((int)param_1 + 0x3b) = *(short *)((int)param_1 + 0x3b) + sVar3;
    break;
  case 0x18:
    if (*(int *)(iVar13 + 0x284) == 0) {
      return 0;
    }
    if (*(int *)(iVar13 + 0xf4) == 0) {
      return 0;
    }
    if (param_1[2] != 0) {
      return 0;
    }
    (*(code *)PTR_memcpy_006aabf4)
              (*(int *)(iVar13 + 0x278) + (*(int *)(iVar13 + 0x27c) - param_3),param_4);
    (*(code *)PTR_CRYPTO_gcm128_setiv_006a8b94)
              (iVar13 + 0x100,*(undefined4 *)(iVar13 + 0x278),*(undefined4 *)(iVar13 + 0x27c));
LAB_0053deec:
    uVar4 = 1;
    *(undefined4 *)(iVar13 + 0xf8) = 1;
  }
  return uVar4;
}

