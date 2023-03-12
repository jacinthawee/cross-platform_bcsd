
int ssl3_write_pending(int *param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar8 = param_1[0x16];
  if ((param_4 < *(int *)(iVar8 + 0x168)) ||
     (((*(int *)(iVar8 + 0x174) != param_3 && ((param_1[0x41] & 2U) == 0)) ||
      (*(int *)(iVar8 + 0x16c) != param_2)))) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9f,0x7f,"s3_pkt.c",0x367);
    return -1;
  }
  puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  while( true ) {
    puVar1 = PTR_BIO_write_006a7f14;
    iVar3 = param_1[4];
    *puVar2 = 0;
    if (iVar3 == 0) break;
    iVar6 = *(int *)(iVar8 + 0xfc);
    iVar5 = *(int *)(iVar8 + 0x104);
    uVar7 = *(undefined4 *)(iVar8 + 0x108);
    param_1[6] = 2;
    iVar3 = (*(code *)puVar1)(iVar3,iVar6 + iVar5,uVar7);
    iVar5 = *(int *)(iVar8 + 0x108);
    if (iVar3 == iVar5) goto LAB_0048da0c;
    if (iVar3 < 1) goto LAB_0048da54;
    *(int *)(iVar8 + 0x108) = iVar5 - iVar3;
    *(int *)(iVar8 + 0x104) = *(int *)(iVar8 + 0x104) + iVar3;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9f,0x80,"s3_pkt.c",0x377);
  iVar3 = -1;
  if (*(int *)(iVar8 + 0x108) == -1) {
    iVar5 = -1;
LAB_0048da0c:
    uVar4 = param_1[0x41];
    *(undefined4 *)(iVar8 + 0x108) = 0;
    *(int *)(iVar8 + 0x104) = *(int *)(iVar8 + 0x104) + iVar5;
    if ((((uVar4 & 0x10) == 0) ||
        (iVar8 = (*(code *)PTR_SSL_version_006a88d8)(param_1), iVar8 == 0xfeff)) ||
       (iVar8 = (*(code *)PTR_SSL_version_006a88d8)(param_1), iVar8 == 0x100)) {
      iVar8 = param_1[0x16];
    }
    else {
      ssl3_release_write_buffer(param_1);
      iVar8 = param_1[0x16];
    }
    param_1[6] = 1;
    iVar3 = *(int *)(iVar8 + 0x170);
  }
  else {
LAB_0048da54:
    if ((*param_1 == 0xfeff) || (*param_1 == 0x100)) {
      *(undefined4 *)(iVar8 + 0x108) = 0;
      return iVar3;
    }
  }
  return iVar3;
}

