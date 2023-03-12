
int ssl3_dispatch_alert(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  code *pcVar13;
  int local_2c;
  
  iVar9 = param_1[0x16];
  *(undefined4 *)(iVar9 + 0x18c) = 0;
  iVar10 = iVar9 + 400;
  if (*(int *)(iVar9 + 0xfc) == 0) {
    iVar5 = ssl3_setup_write_buffer();
    if (iVar5 == 0) goto LAB_0048ffa4;
    if (*(int *)(iVar9 + 0x108) == 0) {
      iVar5 = param_1[0x16];
      if (*(int *)(iVar5 + 0x18c) != 0) {
        iVar5 = (**(code **)(param_1[2] + 0x3c))(param_1);
        if (iVar5 < 1) goto LAB_0048fed0;
        iVar5 = param_1[0x16];
      }
      goto LAB_0048fc04;
    }
LAB_0048feb4:
    iVar5 = ssl3_write_pending(param_1,0x15,iVar10,2);
  }
  else {
    iVar5 = iVar9;
    if (*(int *)(iVar9 + 0x108) != 0) goto LAB_0048feb4;
LAB_0048fc04:
    if (param_1[0x30] == 0) {
LAB_0048fc6c:
      iVar1 = 0;
      if (param_1[0x23] != 0) goto LAB_0048fc54;
LAB_0048fc78:
      iVar1 = 0;
    }
    else {
      if (param_1[0x23] == 0) goto LAB_0048fc78;
      iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
      if (iVar1 == 0) goto LAB_0048fc6c;
      uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
      iVar1 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar2);
      if (iVar1 < 0) goto LAB_0048ffa4;
LAB_0048fc54:
      if (*(int *)(param_1[0x16] + 0xe4) == 0) {
        *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
      }
    }
    uVar6 = -(*(int *)(iVar9 + 0xfc) + 5) & 7;
    puVar3 = (undefined *)(*(int *)(iVar9 + 0xfc) + uVar6);
    *(uint *)(iVar9 + 0x104) = uVar6;
    *puVar3 = 0x15;
    iVar7 = *param_1;
    *(undefined4 *)(iVar5 + 0x130) = 0x15;
    puVar3[1] = (char)((uint)iVar7 >> 8);
    if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
      iVar7 = *param_1;
      if ((iVar7 >> 8 != 3) || (iVar7 < 0x302)) goto LAB_0048fcc8;
      uVar8 = 1;
    }
    else {
      iVar7 = *param_1;
LAB_0048fcc8:
      uVar8 = (undefined)iVar7;
    }
    puVar3[2] = uVar8;
    puVar12 = puVar3 + 5;
    if ((param_1[0x23] == 0) || (*param_1 < 0x302)) {
LAB_0048fcf0:
      local_2c = 0;
    }
    else {
      uVar6 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a9230)();
      if ((uVar6 & 0xf0007) == 2) {
        local_2c = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(param_1[0x23]);
        if (local_2c < 2) goto LAB_0048fcf0;
      }
      else {
        if ((uVar6 & 0xf0007) != 6) goto LAB_0048fcf0;
        local_2c = 8;
      }
    }
    iVar7 = param_1[0x25];
    puVar4 = puVar12 + local_2c;
    *(int *)(iVar5 + 0x140) = iVar10;
    *(undefined **)(iVar5 + 0x13c) = puVar4;
    *(undefined4 *)(iVar5 + 0x134) = 2;
    if (iVar7 == 0) {
      *puVar4 = *(undefined *)(iVar9 + 400);
      puVar4[1] = *(undefined *)(iVar9 + 0x191);
      *(undefined4 *)(iVar5 + 0x140) = *(undefined4 *)(iVar5 + 0x13c);
    }
    else {
      iVar11 = param_1[0x16];
      iVar7 = (*(code *)PTR_COMP_compress_block_006a9244)
                        (iVar7,*(undefined4 *)(iVar11 + 0x13c),0x4400,
                         *(undefined4 *)(iVar11 + 0x140),*(undefined4 *)(iVar11 + 0x134));
      if (iVar7 < 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x68,0x8d,"s3_pkt.c",0x318);
        goto LAB_0048ffa4;
      }
      *(int *)(iVar11 + 0x134) = iVar7;
      *(undefined4 *)(iVar11 + 0x140) = *(undefined4 *)(iVar11 + 0x13c);
    }
    if (iVar1 != 0) {
      iVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                        (param_1,puVar12 + local_2c + *(int *)(iVar5 + 0x134),1);
      if (iVar7 < 0) {
LAB_0048ffa4:
        *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
        return -1;
      }
      *(int *)(iVar5 + 0x134) = *(int *)(iVar5 + 0x134) + iVar1;
    }
    *(undefined **)(iVar5 + 0x140) = puVar12;
    *(undefined **)(iVar5 + 0x13c) = puVar12;
    if (local_2c != 0) {
      *(int *)(iVar5 + 0x134) = *(int *)(iVar5 + 0x134) + local_2c;
    }
    (***(code ***)(param_1[2] + 100))(param_1,1);
    puVar3[3] = (char)((uint)*(undefined4 *)(iVar5 + 0x134) >> 8);
    puVar3[4] = (char)*(undefined4 *)(iVar5 + 0x134);
    iVar1 = param_1[0x16];
    *(undefined4 *)(iVar5 + 0x130) = 0x15;
    iVar7 = *(int *)(iVar5 + 0x134) + 5;
    *(int *)(iVar5 + 0x134) = iVar7;
    *(int *)(iVar9 + 0x108) = iVar7;
    *(undefined4 *)(iVar1 + 0x168) = 2;
    *(int *)(iVar1 + 0x174) = iVar10;
    *(undefined4 *)(iVar1 + 0x16c) = 0x15;
    *(undefined4 *)(iVar1 + 0x170) = 2;
    iVar5 = ssl3_write_pending(param_1,0x15,iVar10,2);
  }
  if (0 < iVar5) {
    if (*(char *)(param_1[0x16] + 400) == '\x02') {
      (*(code *)PTR_BIO_ctrl_006a7f18)(param_1[4],0xb,0,0);
      pcVar13 = (code *)param_1[0x19];
    }
    else {
      pcVar13 = (code *)param_1[0x19];
    }
    if (pcVar13 != (code *)0x0) {
      (*pcVar13)(1,*param_1,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
    }
    pcVar13 = (code *)param_1[0x34];
    if ((pcVar13 != (code *)0x0) ||
       (pcVar13 = *(code **)(param_1[0x39] + 0x9c), pcVar13 != (code *)0x0)) {
      (*pcVar13)(param_1,0x4008,*(undefined2 *)(param_1[0x16] + 400));
    }
    return iVar5;
  }
LAB_0048fed0:
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
  return iVar5;
}

