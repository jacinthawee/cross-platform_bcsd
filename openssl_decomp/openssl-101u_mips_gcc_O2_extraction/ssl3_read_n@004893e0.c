
int ssl3_read_n(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (param_2 < 1) {
    return param_2;
  }
  iVar9 = *(int *)(param_1 + 0x58);
  iVar2 = *(int *)(iVar9 + 0xec);
  if (iVar2 == 0) {
    iVar2 = ssl3_setup_read_buffer();
    if (iVar2 == 0) {
      return -1;
    }
    iVar2 = *(int *)(iVar9 + 0xec);
  }
  iVar10 = *(int *)(iVar9 + 0xf8);
  uVar7 = -(iVar2 + 5) & 7;
  if (param_4 == 0) {
    if (iVar10 == 0) {
LAB_00489760:
      *(uint *)(iVar9 + 0xf4) = uVar7;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(uint *)(param_1 + 0x4c) = iVar2 + uVar7;
    }
    else if (uVar7 == 0) {
      iVar5 = *(int *)(iVar9 + 0xf4);
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(int *)(param_1 + 0x4c) = iVar2 + iVar5;
    }
    else if (iVar10 < 5) {
      iVar5 = *(int *)(iVar9 + 0xf4);
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(int *)(param_1 + 0x4c) = iVar2 + iVar5;
    }
    else {
      pcVar6 = (char *)(iVar2 + *(int *)(iVar9 + 0xf4));
      if ((*pcVar6 == '\x17') && (0x7f < *(ushort *)(pcVar6 + 3))) {
        (*(code *)PTR_memmove_006a9af4)(iVar2 + uVar7,pcVar6,iVar10);
        iVar2 = *(int *)(iVar9 + 0xec);
        goto LAB_00489760;
      }
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(char **)(param_1 + 0x4c) = pcVar6;
    }
  }
  iVar2 = (*(code *)PTR_SSL_version_006a77ec)(param_1);
  if ((iVar2 == 0xfeff) || (iVar2 = (*(code *)PTR_SSL_version_006a77ec)(param_1), iVar2 == 0x100)) {
    if (iVar10 == 0) {
      if (param_4 != 0) {
        return 0;
      }
    }
    else if (0 < iVar10) {
      if (iVar10 < param_2) {
        param_2 = iVar10;
      }
      iVar2 = -param_2;
      goto LAB_00489638;
    }
  }
  else {
    iVar2 = -param_2;
    if (param_2 <= iVar10) {
LAB_00489638:
      iVar5 = *(int *)(iVar9 + 0xf4);
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + param_2;
      *(int *)(iVar9 + 0xf8) = iVar10 + iVar2;
      *(int *)(iVar9 + 0xf4) = iVar5 + param_2;
      return param_2;
    }
  }
  iVar2 = *(int *)(iVar9 + 0xec) + uVar7;
  iVar5 = *(int *)(param_1 + 0x50);
  if (iVar2 == *(int *)(param_1 + 0x4c)) {
    iVar3 = *(int *)(iVar9 + 0xf4);
  }
  else {
    (*(code *)PTR_memmove_006a9af4)(iVar2,*(int *)(param_1 + 0x4c),iVar10 + iVar5);
    iVar3 = uVar7 + iVar5;
    *(int *)(param_1 + 0x4c) = iVar2;
    *(int *)(iVar9 + 0xf4) = iVar3;
  }
  iVar3 = *(int *)(iVar9 + 0xf0) - iVar3;
  if (iVar3 < param_2) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x95,0x44,"s3_pkt.c",0xd8);
    iVar3 = -1;
  }
  else {
    iVar8 = param_2;
    if ((((*(int *)(param_1 + 0x60) != 0) || (**(int **)(param_1 + 8) == 0xfeff)) &&
        (param_2 <= param_3)) && (iVar8 = iVar3, param_3 <= iVar3)) {
      iVar8 = param_3;
    }
    puVar4 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
    while( true ) {
      puVar1 = PTR_BIO_read_006a74c0;
      iVar3 = *(int *)(param_1 + 0xc);
      *puVar4 = 0;
      if (iVar3 == 0) break;
      *(undefined4 *)(param_1 + 0x18) = 3;
      iVar3 = (*(code *)puVar1)(iVar3,iVar2 + iVar10 + iVar5,iVar8 - iVar10);
      if (iVar3 < 1) goto LAB_004896d4;
      iVar10 = iVar10 + iVar3;
      iVar3 = (*(code *)PTR_SSL_version_006a77ec)(param_1);
      if (((iVar3 == 0xfeff) ||
          (iVar3 = (*(code *)PTR_SSL_version_006a77ec)(param_1), iVar3 == 0x100)) &&
         (iVar10 < param_2)) {
        param_2 = iVar10;
      }
      if (param_2 <= iVar10) {
        iVar2 = *(int *)(param_1 + 0x50);
        *(int *)(iVar9 + 0xf8) = iVar10 - param_2;
        *(int *)(iVar9 + 0xf4) = *(int *)(iVar9 + 0xf4) + param_2;
        *(int *)(param_1 + 0x50) = iVar2 + param_2;
        *(undefined4 *)(param_1 + 0x18) = 1;
        return param_2;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x95,0xd3,"s3_pkt.c",0xf3);
    iVar3 = -1;
LAB_004896d4:
    uVar7 = *(uint *)(param_1 + 0x104);
    *(int *)(iVar9 + 0xf8) = iVar10;
    if ((((uVar7 & 0x10) == 0) ||
        (iVar2 = (*(code *)PTR_SSL_version_006a77ec)(param_1), iVar2 == 0xfeff)) ||
       ((iVar2 = (*(code *)PTR_SSL_version_006a77ec)(param_1), iVar2 == 0x100 ||
        (iVar5 + iVar10 != 0)))) {
      return iVar3;
    }
    ssl3_release_read_buffer(param_1);
  }
  return iVar3;
}

