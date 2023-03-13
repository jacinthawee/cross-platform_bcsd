
undefined4 aes_gcm_ctrl(int *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar7;
  uint uVar6;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  int iVar13;
  
  iVar13 = param_1[0x18];
  switch(param_2) {
  case 0:
    iVar10 = *param_1;
    *(undefined4 *)(iVar13 + 0xf4) = 0;
    uVar4 = 1;
    *(undefined4 *)(iVar13 + 0xf8) = 0;
    uVar8 = *(undefined4 *)(iVar10 + 0xc);
    *(int **)(iVar13 + 0x278) = param_1 + 8;
    *(undefined4 *)(iVar13 + 0x280) = 0xffffffff;
    *(undefined4 *)(iVar13 + 0x284) = 0;
    *(undefined4 *)(iVar13 + 0x27c) = uVar8;
    *(undefined4 *)(iVar13 + 0x288) = 0xffffffff;
    break;
  default:
    uVar4 = 0xffffffff;
    break;
  case 8:
    uVar12 = param_4[0x18];
    if (*(int *)(iVar13 + 0x274) != 0) {
      if (*(int *)(iVar13 + 0x274) != iVar13) {
        return 0;
      }
      *(uint *)(uVar12 + 0x274) = uVar12;
    }
    if (*(int **)(iVar13 + 0x278) == param_1 + 8) {
      uVar4 = 1;
      *(uint **)(uVar12 + 0x278) = param_4 + 8;
    }
    else {
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)
                         (*(undefined4 *)(iVar13 + 0x27c),"e_aes.c",0x312);
      *(int *)(uVar12 + 0x278) = iVar10;
      if (iVar10 == 0) {
        return 0;
      }
      (*(code *)PTR_memcpy_006a9aec)
                (iVar10,*(undefined4 *)(iVar13 + 0x278),*(undefined4 *)(iVar13 + 0x27c));
      uVar4 = 1;
    }
    break;
  case 9:
    if (param_3 < 1) {
      return 0;
    }
    if ((0x10 < param_3) && (*(int *)(iVar13 + 0x27c) < param_3)) {
      if (*(int **)(iVar13 + 0x278) != param_1 + 8) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)(param_3,"e_aes.c",0x2b4);
      *(int *)(iVar13 + 0x278) = iVar10;
      if (iVar10 == 0) {
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
    (*(code *)PTR_memcpy_006a9aec)(param_4,param_1 + 0xc);
    uVar4 = 1;
    break;
  case 0x11:
    if (0xf < param_3 - 1U) {
      return 0;
    }
    if (param_1[2] != 0) {
      return 0;
    }
    (*(code *)PTR_memcpy_006a9aec)(param_1 + 0xc,param_4);
    uVar4 = 1;
    *(int *)(iVar13 + 0x280) = param_3;
    break;
  case 0x12:
    if (param_3 == -1) {
      (*(code *)PTR_memcpy_006a9aec)
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
      (*(code *)PTR_memcpy_006a9aec)(*(undefined4 *)(iVar13 + 0x278),param_4);
      if ((param_1[2] != 0) &&
         (iVar10 = RAND_bytes((uchar *)(*(int *)(iVar13 + 0x278) + param_3),
                              *(int *)(iVar13 + 0x27c) - param_3), iVar10 < 1)) {
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
    (*(code *)PTR_CRYPTO_gcm128_setiv_006a7ac4)
              (iVar13 + 0x100,*(undefined4 *)(iVar13 + 0x278),*(undefined4 *)(iVar13 + 0x27c));
    iVar10 = *(int *)(iVar13 + 0x27c);
    if (param_3 < 1) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      if (param_3 <= iVar10) {
        iVar3 = iVar10 - param_3;
        iVar10 = param_3;
      }
    }
    (*(code *)PTR_memcpy_006a9aec)(param_4,*(int *)(iVar13 + 0x278) + iVar3,iVar10);
    iVar10 = *(int *)(iVar13 + 0x27c);
    iVar3 = *(int *)(iVar13 + 0x278);
    pcVar11 = (char *)(iVar3 + iVar10 + -1);
    cVar7 = *pcVar11 + '\x01';
    *pcVar11 = cVar7;
    if (((((cVar7 == '\0') &&
          (pcVar11 = (char *)(iVar3 + iVar10 + -2), cVar7 = *pcVar11 + '\x01', *pcVar11 = cVar7,
          cVar7 == '\0')) &&
         (pcVar11 = (char *)(iVar3 + iVar10 + -3), cVar7 = *pcVar11 + '\x01', *pcVar11 = cVar7,
         cVar7 == '\0')) &&
        ((pcVar11 = (char *)(iVar3 + iVar10 + -4), cVar7 = *pcVar11 + '\x01', *pcVar11 = cVar7,
         cVar7 == '\0' &&
         (pcVar11 = (char *)(iVar3 + iVar10 + -5), cVar7 = *pcVar11 + '\x01', *pcVar11 = cVar7,
         cVar7 == '\0')))) &&
       ((pcVar11 = (char *)(iVar3 + iVar10 + -6), cVar7 = *pcVar11 + '\x01', *pcVar11 = cVar7,
        cVar7 == '\0' &&
        (pcVar11 = (char *)(iVar3 + iVar10 + -7), cVar7 = *pcVar11 + '\x01', *pcVar11 = cVar7,
        cVar7 == '\0')))) {
      pcVar11 = (char *)(iVar3 + iVar10 + -8);
      *pcVar11 = *pcVar11 + '\x01';
    }
    goto LAB_0053ac10;
  case 0x16:
    if (param_3 != 0xd) {
      return 0;
    }
    uVar9 = *param_4;
    uVar6 = param_4[1];
    uVar5 = param_4[2];
    uVar12 = (uint)(param_1 + 0xc) & 3;
    puVar1 = (uint *)((int)(param_1 + 0xc) - uVar12);
    *puVar1 = *puVar1 & -1 << (4 - uVar12) * 8 | uVar9 >> uVar12 * 8;
    uVar12 = (int)param_1 + 0x33U & 3;
    puVar1 = (uint *)(((int)param_1 + 0x33U) - uVar12);
    *puVar1 = *puVar1 & 0xffffffffU >> (uVar12 + 1) * 8 | uVar9 << (3 - uVar12) * 8;
    param_1[0xd] = uVar6;
    param_1[0xe] = uVar5;
    *(undefined *)(param_1 + 0xf) = *(undefined *)(param_4 + 3);
    *(undefined4 *)(iVar13 + 0x288) = 0xd;
    if (param_1[2] == 0) {
      sVar2 = -0x18;
    }
    else {
      sVar2 = -8;
    }
    uVar4 = 0x10;
    *(short *)((int)param_1 + 0x3b) = *(short *)((int)param_1 + 0x3b) + sVar2;
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
    (*(code *)PTR_memcpy_006a9aec)
              (*(int *)(iVar13 + 0x278) + (*(int *)(iVar13 + 0x27c) - param_3),param_4);
    (*(code *)PTR_CRYPTO_gcm128_setiv_006a7ac4)
              (iVar13 + 0x100,*(undefined4 *)(iVar13 + 0x278),*(undefined4 *)(iVar13 + 0x27c));
LAB_0053ac10:
    uVar4 = 1;
    *(undefined4 *)(iVar13 + 0xf8) = 1;
  }
  return uVar4;
}

