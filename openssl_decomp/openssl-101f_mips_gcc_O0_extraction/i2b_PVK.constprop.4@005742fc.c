
int i2b_PVK_constprop_4(undefined4 *param_1,int *param_2,int *param_3,code *param_4,void *param_5)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  undefined uVar13;
  char *in_t0;
  int iVar14;
  uint unaff_s0;
  int iVar15;
  undefined4 *puVar16;
  int *unaff_s4;
  int *piVar17;
  int iVar18;
  char *pcVar19;
  char *pcVar20;
  int *local_508;
  int local_4fc;
  int local_4e4 [6];
  undefined auStack_4cc [140];
  undefined4 uStack_440;
  undefined local_43b;
  undefined local_43a;
  undefined local_439;
  undefined local_438;
  undefined local_437;
  undefined local_436;
  undefined local_435;
  undefined local_434;
  undefined local_433;
  undefined local_432;
  undefined local_431;
  undefined4 auStack_42c [256];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar15 = 0x28;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_4cc);
  local_4e4[0] = 0;
  if (param_3 == (int *)0x0) {
    iVar15 = 0x18;
  }
  if (*param_2 == 0x74) {
    unaff_s4 = (int *)param_2[5];
    unaff_s0 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s4[3]);
    if (((((unaff_s0 & 7) != 0) ||
         (iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s4[4]), iVar2 != 0xa0)) ||
        (iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s4[5]), (int)unaff_s0 < iVar2)) ||
       (iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s4[7]), 0xa0 < iVar2)) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce4c,0x23c);
LAB_00574d84:
      iVar2 = -1;
      goto LAB_00574c4c;
    }
    local_4e4[0] = 0x32535344;
    if (unaff_s0 == 0) goto LAB_00574d84;
    iVar2 = ((unaff_s0 + 7 >> 3) + 0x20) * 2;
  }
  else {
    iVar2 = -1;
    if (*param_2 != 6) goto LAB_00574c4c;
    iVar2 = check_bitlen_rsa(param_2[5],0,local_4e4);
    if (iVar2 == 0) goto LAB_00574d84;
    iVar2 = ((iVar2 + 7U >> 3) + 2) * 2 + (iVar2 + 0xfU >> 4) * 5;
  }
  unaff_s0 = iVar2 + 0x10;
  iVar2 = -1;
  if ((int)unaff_s0 < 0) goto LAB_00574c4c;
  iVar15 = iVar15 + unaff_s0;
  iVar2 = iVar15;
  if (param_1 == (undefined4 *)0x0) goto LAB_00574c4c;
  puVar3 = (undefined *)*param_1;
  unaff_s4 = (int *)0x670000;
  if (puVar3 == (undefined *)0x0) {
    puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar15,FUN_0066ce4c,0x362);
    if (puVar3 == (undefined *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x89,0x41,FUN_0066ce4c,0x365);
      iVar2 = -1;
      goto LAB_00574c4c;
    }
    *param_1 = puVar3;
  }
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  *puVar3 = 0x1e;
  puVar3[2] = 0xb5;
  puVar3[7] = 0;
  puVar3[1] = 0xf1;
  puVar3[3] = 0xb0;
  iVar11 = *param_2;
  puVar3[9] = 0;
  if (iVar11 == 0x74) {
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[8] = 2;
  }
  else {
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[8] = 1;
  }
  param_1 = (undefined4 *)(puVar3 + 0xc);
  uVar13 = 0x10;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  if (param_3 == (int *)0x0) {
    uVar13 = 0;
  }
  puVar3[0xf] = 0;
  puVar3[0x11] = 0;
  piVar17 = (int *)(puVar3 + 0x18);
  *(bool *)param_1 = param_3 != (int *)0x0;
  puVar3[0x10] = uVar13;
  puVar3[0x12] = 0;
  puVar3[0x13] = 0;
  puVar3[0x14] = (char)unaff_s0;
  puVar3[0x15] = (char)(unaff_s0 >> 8);
  puVar3[0x16] = (char)(unaff_s0 >> 0x10);
  puVar3[0x17] = (char)(unaff_s0 >> 0x18);
  if (param_3 == (int *)0x0) {
    iVar11 = *param_2;
    local_508 = (int *)0x0;
    unaff_s4 = piVar17;
    if (iVar11 == 0x74) goto LAB_00574cb8;
LAB_005744ac:
    local_4e4[0] = 0;
    if (iVar11 != 6) goto LAB_00574bb4;
    uVar4 = check_bitlen_rsa(param_2[5],0,local_4e4);
    if (uVar4 == 0) goto LAB_00574bb4;
    cVar12 = -0x5c;
    iVar2 = 0xa400;
  }
  else {
    iVar11 = (*(code *)PTR_RAND_bytes_006a8d44)(piVar17,0x10);
    if (iVar11 < 1) goto LAB_00574c38;
    iVar11 = *param_2;
    unaff_s4 = (int *)(puVar3 + 0x28);
    local_508 = piVar17;
    if (iVar11 != 0x74) goto LAB_005744ac;
LAB_00574cb8:
    local_4e4[0] = 0;
    param_1 = (undefined4 *)param_2[5];
    uVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(param_1[3]);
    if ((((uVar4 & 7) != 0) ||
        (iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(param_1[4]), iVar11 != 0xa0)) ||
       ((iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(param_1[5]), (int)uVar4 < iVar11 ||
        (iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(param_1[7]), 0xa0 < iVar11)))) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce4c,0x23c);
      if (param_3 != (int *)0x0) goto LAB_00574bbc;
      goto LAB_00574c4c;
    }
    local_4e4[0] = 0x32535344;
    if (uVar4 == 0) goto LAB_00574bb4;
    cVar12 = '\"';
    iVar2 = 0x2200;
  }
  *(char *)((int)unaff_s4 + 5) = cVar12;
  *(char *)((int)unaff_s4 + 2) = '\0';
  *(char *)((int)unaff_s4 + 3) = '\0';
  *(char *)unaff_s4 = '\a';
  *(char *)(unaff_s4 + 1) = '\0';
  *(char *)((int)unaff_s4 + 6) = '\0';
  *(char *)((int)unaff_s4 + 1) = '\x02';
  piVar17 = unaff_s4 + 4;
  *(char *)((int)unaff_s4 + 7) = '\0';
  *(char *)(unaff_s4 + 3) = (char)uVar4;
  *(char *)((int)unaff_s4 + 0xd) = (char)(uVar4 >> 8);
  *(char *)((int)unaff_s4 + 0xe) = (char)(uVar4 >> 0x10);
  *(char *)(unaff_s4 + 2) = (char)local_4e4[0];
  *(char *)((int)unaff_s4 + 0xf) = (char)(uVar4 >> 0x18);
  *(char *)((int)unaff_s4 + 10) = (char)((uint)local_4e4[0] >> 0x10);
  *(char *)((int)unaff_s4 + 9) = (char)((uint)local_4e4[0] >> 8);
  *(char *)((int)unaff_s4 + 0xb) = (char)((uint)local_4e4[0] >> 0x18);
  if (iVar2 == 0x2200) {
    iVar14 = param_2[5];
    iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar14 + 0xc));
    uVar9 = *(undefined4 *)(iVar14 + 0xc);
    iVar2 = iVar11 + 7;
    if (iVar11 + 7 < 0) {
      iVar2 = iVar11 + 0xe;
    }
    iVar2 = iVar2 >> 3;
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar9);
    iVar18 = iVar10 + 7;
    iVar11 = iVar10 + 0xe;
    if (iVar18 >= 0) {
      iVar11 = iVar18;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar9,piVar17);
    if (iVar18 < 0) {
      iVar18 = iVar10 + 0x16;
    }
    if (0 < iVar18 >> 4) {
      piVar8 = piVar17;
      pcVar20 = (char *)((int)piVar17 + iVar11 + -1);
      do {
        cVar12 = *(char *)piVar8;
        piVar5 = (int *)((int)piVar8 + 1);
        *(char *)piVar8 = *pcVar20;
        *pcVar20 = cVar12;
        piVar8 = piVar5;
        pcVar20 = pcVar20 + -1;
      } while ((int *)((int)piVar17 + (iVar18 >> 4)) != piVar5);
    }
    pcVar19 = (char *)((int)piVar17 + iVar11);
    pcVar20 = pcVar19;
    if ((0 < iVar2) && (0 < iVar2 - iVar11)) {
      pcVar20 = pcVar19 + (iVar2 - iVar11);
      (*(code *)PTR_memset_006aab00)(pcVar19,0);
    }
    uVar9 = *(undefined4 *)(iVar14 + 0x10);
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar9);
    iVar18 = iVar10 + 7;
    iVar11 = iVar10 + 0xe;
    if (iVar18 >= 0) {
      iVar11 = iVar18;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar9,pcVar20);
    if (iVar18 < 0) {
      iVar18 = iVar10 + 0x16;
    }
    if (0 < iVar18 >> 4) {
      pcVar19 = pcVar20;
      pcVar7 = pcVar20 + iVar11 + -1;
      do {
        cVar12 = *pcVar19;
        pcVar6 = pcVar19 + 1;
        *pcVar19 = *pcVar7;
        *pcVar7 = cVar12;
        pcVar19 = pcVar6;
        pcVar7 = pcVar7 + -1;
      } while (pcVar20 + (iVar18 >> 4) != pcVar6);
    }
    pcVar20 = pcVar20 + iVar11;
    pcVar19 = pcVar20;
    if (0 < 0x14 - iVar11) {
      pcVar19 = pcVar20 + (0x14 - iVar11);
      (*(code *)PTR_memset_006aab00)(pcVar20,0);
    }
    uVar9 = *(undefined4 *)(iVar14 + 0x14);
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar9);
    iVar18 = iVar10 + 7;
    iVar11 = iVar10 + 0xe;
    if (iVar18 >= 0) {
      iVar11 = iVar18;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar9,pcVar19);
    if (iVar18 < 0) {
      iVar18 = iVar10 + 0x16;
    }
    if (0 < iVar18 >> 4) {
      pcVar20 = pcVar19;
      pcVar7 = pcVar19 + iVar11 + -1;
      do {
        cVar12 = *pcVar20;
        pcVar6 = pcVar20 + 1;
        *pcVar20 = *pcVar7;
        *pcVar7 = cVar12;
        pcVar20 = pcVar6;
        pcVar7 = pcVar7 + -1;
      } while (pcVar6 != pcVar19 + (iVar18 >> 4));
    }
    pcVar19 = pcVar19 + iVar11;
    pcVar20 = pcVar19;
    if ((0 < iVar2) && (0 < iVar2 - iVar11)) {
      pcVar20 = pcVar19 + (iVar2 - iVar11);
      (*(code *)PTR_memset_006aab00)(pcVar19,0);
    }
    uVar9 = *(undefined4 *)(iVar14 + 0x1c);
    local_4fc = (*(code *)PTR_BN_num_bits_006a82f4)(uVar9);
    param_2 = (int *)(local_4fc + 7);
    piVar17 = (int *)(local_4fc + 0xe);
    if (-1 < (int)param_2) {
      piVar17 = param_2;
    }
    unaff_s4 = (int *)((int)piVar17 >> 3);
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar9,pcVar20);
    piVar17 = (int *)(local_4fc + 0x16);
    if (-1 < (int)param_2) {
      piVar17 = param_2;
    }
    in_t0 = (char *)((int)piVar17 >> 4);
    if (0 < (int)in_t0) {
      in_t0 = pcVar20 + (int)in_t0;
      pcVar19 = pcVar20;
      pcVar7 = pcVar20 + (int)((int)unaff_s4 + -1);
      do {
        cVar12 = *pcVar19;
        pcVar6 = pcVar19 + 1;
        *pcVar19 = *pcVar7;
        *pcVar7 = cVar12;
        pcVar19 = pcVar6;
        pcVar7 = pcVar7 + -1;
      } while (in_t0 != pcVar6);
    }
    puVar16 = (undefined4 *)(pcVar20 + (int)unaff_s4);
    param_1 = puVar16;
    if (0 < 0x14 - (int)unaff_s4) {
      param_1 = (undefined4 *)((int)puVar16 + (0x14 - (int)unaff_s4));
      (*(code *)PTR_memset_006aab00)(puVar16,0);
    }
    (*(code *)PTR_memset_006aab00)(param_1,0xff,0x18);
    goto LAB_00574bb4;
  }
  unaff_s4 = (int *)param_2[5];
  iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s4[4]);
  iVar2 = iVar11 + 7;
  if (iVar11 + 7 < 0) {
    iVar2 = iVar11 + 0xe;
  }
  local_4fc = iVar2 >> 3;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s4[4]);
  iVar14 = unaff_s4[5];
  param_1 = (undefined4 *)(iVar2 + 0xf >> 4);
  iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar14);
  iVar18 = iVar11 + 7;
  iVar2 = iVar11 + 0xe;
  if (-1 < iVar18) {
    iVar2 = iVar18;
  }
  iVar2 = iVar2 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(iVar14,piVar17);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar18) {
    iVar11 = iVar18;
  }
  if (0 < iVar11 >> 4) {
    piVar8 = piVar17;
    pcVar20 = (char *)((int)piVar17 + iVar2 + -1);
    do {
      cVar12 = *(char *)piVar8;
      piVar5 = (int *)((int)piVar8 + 1);
      *(char *)piVar8 = *pcVar20;
      *pcVar20 = cVar12;
      piVar8 = piVar5;
      pcVar20 = pcVar20 + -1;
    } while ((int *)((int)piVar17 + (iVar11 >> 4)) != piVar5);
  }
  pcVar19 = (char *)((int)piVar17 + iVar2);
  pcVar20 = pcVar19;
  if (0 < 4 - iVar2) {
    pcVar20 = pcVar19 + (4 - iVar2);
    (*(code *)PTR_memset_006aab00)(pcVar19,0);
  }
  iVar11 = unaff_s4[4];
  iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar11);
  iVar2 = iVar14 + 7;
  (*(code *)PTR_BN_bn2bin_006a8300)(iVar11,pcVar20);
  iVar11 = iVar14 + 0xe;
  if (-1 < iVar2) {
    iVar11 = iVar2;
  }
  if (-1 >= iVar2) {
    iVar2 = iVar14 + 0x16;
  }
  if (0 < iVar2 >> 4) {
    pcVar19 = pcVar20;
    pcVar7 = pcVar20 + (iVar11 >> 3) + -1;
    do {
      cVar12 = *pcVar19;
      pcVar6 = pcVar19 + 1;
      *pcVar19 = *pcVar7;
      *pcVar7 = cVar12;
      pcVar19 = pcVar6;
      pcVar7 = pcVar7 + -1;
    } while (pcVar6 != pcVar20 + (iVar2 >> 4));
  }
  iVar14 = unaff_s4[7];
  pcVar20 = pcVar20 + (iVar11 >> 3);
  iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar14);
  iVar18 = iVar11 + 7;
  iVar2 = iVar11 + 0xe;
  if (-1 < iVar18) {
    iVar2 = iVar18;
  }
  iVar2 = iVar2 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(iVar14,pcVar20);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar18) {
    iVar11 = iVar18;
  }
  if (0 < iVar11 >> 4) {
    pcVar19 = pcVar20;
    pcVar7 = pcVar20 + iVar2 + -1;
    do {
      cVar12 = *pcVar19;
      pcVar6 = pcVar19 + 1;
      *pcVar19 = *pcVar7;
      *pcVar7 = cVar12;
      pcVar19 = pcVar6;
      pcVar7 = pcVar7 + -1;
    } while (pcVar20 + (iVar11 >> 4) != pcVar6);
  }
  pcVar20 = pcVar20 + iVar2;
  if ((int)param_1 < 1) {
    iVar18 = unaff_s4[8];
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
    iVar2 = iVar14 + 7;
    iVar11 = iVar14 + 0xe;
    if (iVar2 >= 0) {
      iVar11 = iVar2;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,pcVar20);
    if (iVar2 < 0) {
      iVar2 = iVar14 + 0x16;
    }
    iVar2 = iVar2 >> 4;
    pcVar19 = pcVar20 + iVar11 + -1;
    if (0 < iVar2) goto LAB_00574830;
    param_2 = (int *)(pcVar20 + iVar11);
LAB_0057525c:
    iVar18 = unaff_s4[9];
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
    iVar2 = iVar14 + 7;
    iVar11 = iVar14 + 0xe;
    if (iVar2 >= 0) {
      iVar11 = iVar2;
    }
    in_t0 = (char *)(iVar11 >> 3);
    (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,param_2);
    if (iVar2 < 0) {
      iVar2 = iVar14 + 0x16;
    }
    iVar2 = iVar2 >> 4;
    pcVar20 = (char *)((int)param_2 + (int)(in_t0 + -1));
    if (iVar2 < 1) {
      pcVar20 = (char *)((int)param_2 + (int)in_t0);
      goto LAB_005752dc;
    }
  }
  else {
    iVar2 = (int)param_1 - iVar2;
    if (0 < iVar2) {
      (*(code *)PTR_memset_006aab00)(pcVar20,0,iVar2);
      pcVar20 = pcVar20 + iVar2;
    }
    iVar18 = unaff_s4[8];
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
    iVar2 = iVar14 + 7;
    iVar11 = iVar14 + 0xe;
    if (iVar2 >= 0) {
      iVar11 = iVar2;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,pcVar20);
    if (iVar2 < 0) {
      iVar2 = iVar14 + 0x16;
    }
    iVar2 = iVar2 >> 4;
    pcVar19 = pcVar20 + iVar11 + -1;
    if (iVar2 < 1) {
      param_2 = (int *)(pcVar20 + iVar11);
    }
    else {
LAB_00574830:
      pcVar7 = pcVar20;
      do {
        cVar12 = *pcVar7;
        pcVar6 = pcVar7 + 1;
        *pcVar7 = *pcVar19;
        *pcVar19 = cVar12;
        pcVar7 = pcVar6;
        pcVar19 = pcVar19 + -1;
      } while (pcVar20 + iVar2 != pcVar6);
      param_2 = (int *)(pcVar20 + iVar11);
      if ((int)param_1 < 1) goto LAB_0057525c;
    }
    iVar11 = (int)param_1 - iVar11;
    if (0 < iVar11) {
      (*(code *)PTR_memset_006aab00)(param_2,0,iVar11);
      param_2 = (int *)((int)param_2 + iVar11);
    }
    iVar18 = unaff_s4[9];
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
    iVar2 = iVar14 + 7;
    iVar11 = iVar14 + 0xe;
    if (iVar2 >= 0) {
      iVar11 = iVar2;
    }
    in_t0 = (char *)(iVar11 >> 3);
    (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,param_2);
    if (iVar2 < 0) {
      iVar2 = iVar14 + 0x16;
    }
    iVar2 = iVar2 >> 4;
    pcVar20 = (char *)((int)param_2 + (int)(in_t0 + -1));
    if (iVar2 < 1) goto LAB_00575550;
  }
  piVar17 = param_2;
  do {
    cVar12 = *(char *)piVar17;
    piVar8 = (int *)((int)piVar17 + 1);
    *(char *)piVar17 = *pcVar20;
    *pcVar20 = cVar12;
    piVar17 = piVar8;
    pcVar20 = pcVar20 + -1;
  } while ((int *)((int)param_2 + iVar2) != piVar8);
  pcVar20 = (char *)((int)param_2 + (int)in_t0);
  if (0 < (int)param_1) goto LAB_00574930;
LAB_005752dc:
  iVar18 = unaff_s4[10];
  iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
  iVar2 = iVar14 + 7;
  iVar11 = iVar14 + 0xe;
  if (iVar2 >= 0) {
    iVar11 = iVar2;
  }
  iVar11 = iVar11 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,pcVar20);
  if (iVar2 < 0) {
    iVar2 = iVar14 + 0x16;
  }
  iVar2 = iVar2 >> 4;
  pcVar19 = pcVar20 + iVar11 + -1;
  if (0 < iVar2) goto LAB_005749d8;
  do {
    pcVar20 = pcVar20 + iVar11;
    if (0 < (int)param_1) goto LAB_00574a04;
    iVar18 = unaff_s4[0xb];
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
    iVar11 = iVar14 + 7;
    iVar2 = iVar14 + 0xe;
    if (iVar11 >= 0) {
      iVar2 = iVar11;
    }
    iVar2 = iVar2 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,pcVar20);
    if (iVar11 < 0) {
      iVar11 = iVar14 + 0x16;
    }
    iVar11 = iVar11 >> 4;
    pcVar19 = pcVar20 + iVar2 + -1;
    if (0 < iVar11) break;
    param_2 = (int *)(pcVar20 + iVar2);
LAB_00574af8:
    in_t0 = (char *)unaff_s4[6];
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(in_t0);
    iVar2 = iVar14 + 7;
    param_1 = (undefined4 *)(uint)(iVar2 < 0);
    iVar11 = iVar14 + 0xe;
    if (param_1 == (undefined4 *)0x0) {
      iVar11 = iVar2;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(in_t0,param_2);
    unaff_s4 = (int *)(iVar11 >> 3);
    if (param_1 != (undefined4 *)0x0) {
      iVar2 = iVar14 + 0x16;
    }
    if (0 < iVar2 >> 4) {
      piVar17 = param_2;
      pcVar20 = (char *)((int)param_2 + (int)((int)unaff_s4 + -1));
      do {
        cVar12 = *(char *)piVar17;
        piVar8 = (int *)((int)piVar17 + 1);
        *(char *)piVar17 = *pcVar20;
        *pcVar20 = cVar12;
        piVar17 = piVar8;
        pcVar20 = pcVar20 + -1;
      } while ((int *)((int)param_2 + (iVar2 >> 4)) != piVar8);
    }
    if ((0 < local_4fc) && (0 < local_4fc - (int)unaff_s4)) {
      (*(code *)PTR_memset_006aab00)((char *)((int)param_2 + (int)unaff_s4),0);
    }
LAB_00574bb4:
    iVar2 = iVar15;
    if (param_3 != (int *)0x0) {
LAB_00574bbc:
      if (param_4 == (code *)0x0) {
        iVar2 = PEM_def_callback((char *)auStack_42c,0x400,1,param_5);
      }
      else {
        iVar2 = (*param_4)(auStack_42c,0x400,1);
      }
      param_1 = auStack_42c;
      if (iVar2 < 1) {
        (*(code *)PTR_ERR_put_error_006a9030)(9,0x89,0x68,FUN_0066ce4c,0x389);
        piVar17 = unaff_s4;
      }
      else {
        unaff_s4 = local_4e4;
        (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(unaff_s4);
        uVar9 = (*(code *)PTR_EVP_sha1_006a86c4)();
        iVar11 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(unaff_s4,uVar9,0);
        piVar17 = unaff_s4;
        if (((iVar11 != 0) &&
            (iVar11 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s4,local_508,0x10), iVar11 != 0
            )) && (iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s4,param_1,iVar2),
                  iVar2 != 0)) {
          param_1 = &uStack_440;
          iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(unaff_s4,param_1,0);
          if (iVar2 != 0) {
            (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s4);
            if (param_3 == (int *)0x1) {
              local_43b = 0;
              local_43a = 0;
              local_439 = 0;
              local_438 = 0;
              local_437 = 0;
              local_436 = 0;
              local_435 = 0;
              local_434 = 0;
              local_433 = 0;
              local_432 = 0;
              local_431 = 0;
            }
            param_3 = local_508 + 6;
            uVar9 = (*(code *)PTR_EVP_rc4_006a9528)();
            iVar2 = (*(code *)PTR_EVP_EncryptInit_ex_006a8b84)(auStack_4cc,uVar9,0,param_1,0);
            if (iVar2 != 0) {
              unaff_s0 = unaff_s0 - 8;
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(param_1,0x14);
              iVar2 = (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                                (auStack_4cc,param_3,unaff_s4,param_3,unaff_s0);
              if ((iVar2 != 0) &&
                 (iVar2 = (*(code *)PTR_EVP_DecryptFinal_ex_006a8b58)
                                    (auStack_4cc,(char *)((int)param_3 + local_4e4[0]),unaff_s4),
                 iVar2 != 0)) {
                (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_4cc);
                iVar2 = iVar15;
                goto LAB_00574c4c;
              }
            }
            goto LAB_00574c38;
          }
        }
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s4);
      }
LAB_00574c38:
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_4cc);
      iVar2 = -1;
      unaff_s4 = piVar17;
    }
LAB_00574c4c:
    if (local_2c == *(int *)puVar1) {
      return iVar2;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00575550:
    pcVar20 = (char *)((int)param_2 + (int)in_t0);
LAB_00574930:
    iVar2 = (int)param_1 - (int)in_t0;
    if (0 < iVar2) {
      (*(code *)PTR_memset_006aab00)(pcVar20,0,iVar2);
      pcVar20 = pcVar20 + iVar2;
    }
    iVar18 = unaff_s4[10];
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
    iVar2 = iVar14 + 7;
    iVar11 = iVar14 + 0xe;
    if (iVar2 >= 0) {
      iVar11 = iVar2;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,pcVar20);
    if (iVar2 < 0) {
      iVar2 = iVar14 + 0x16;
    }
    iVar2 = iVar2 >> 4;
    pcVar19 = pcVar20 + iVar11 + -1;
    if (iVar2 < 1) {
      pcVar20 = pcVar20 + iVar11;
LAB_00574a04:
      iVar11 = (int)param_1 - iVar11;
      if (0 < iVar11) {
        (*(code *)PTR_memset_006aab00)(pcVar20,0,iVar11);
        pcVar20 = pcVar20 + iVar11;
      }
      iVar18 = unaff_s4[0xb];
      iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar18);
      iVar11 = iVar14 + 7;
      iVar2 = iVar14 + 0xe;
      if (iVar11 >= 0) {
        iVar2 = iVar11;
      }
      iVar2 = iVar2 >> 3;
      (*(code *)PTR_BN_bn2bin_006a8300)(iVar18,pcVar20);
      if (iVar11 < 0) {
        iVar11 = iVar14 + 0x16;
      }
      iVar11 = iVar11 >> 4;
      pcVar19 = pcVar20 + iVar2 + -1;
      if (0 < iVar11) break;
      piVar17 = (int *)(pcVar20 + iVar2);
      goto LAB_00574ad8;
    }
LAB_005749d8:
    pcVar7 = pcVar20;
    do {
      cVar12 = *pcVar7;
      pcVar6 = pcVar7 + 1;
      *pcVar7 = *pcVar19;
      *pcVar19 = cVar12;
      pcVar7 = pcVar6;
      pcVar19 = pcVar19 + -1;
    } while (pcVar20 + iVar2 != pcVar6);
  } while( true );
  pcVar7 = pcVar20;
  do {
    cVar12 = *pcVar7;
    pcVar6 = pcVar7 + 1;
    *pcVar7 = *pcVar19;
    *pcVar19 = cVar12;
    pcVar7 = pcVar6;
    pcVar19 = pcVar19 + -1;
  } while (pcVar20 + iVar11 != pcVar6);
  piVar17 = (int *)(pcVar20 + iVar2);
  param_2 = piVar17;
  if (0 < (int)param_1) {
LAB_00574ad8:
    param_2 = piVar17;
    if (0 < (int)param_1 - iVar2) {
      param_2 = (int *)((int)piVar17 + ((int)param_1 - iVar2));
      (*(code *)PTR_memset_006aab00)(piVar17,0);
    }
  }
  goto LAB_00574af8;
}

