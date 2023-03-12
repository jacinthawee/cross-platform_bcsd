
int do_ssl3_write(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  undefined uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  int local_3c;
  int local_2c;
  
  iVar10 = param_1[0x16];
  if ((*(int *)(iVar10 + 0xfc) == 0) && (iVar1 = ssl3_setup_write_buffer(), iVar1 == 0)) {
    return -1;
  }
  if (*(int *)(iVar10 + 0x108) != 0) {
    iVar10 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar10;
  }
  if (*(int *)(param_1[0x16] + 0x18c) == 0) {
    if (param_4 == 0) {
LAB_0048ddb8:
      if (param_5 == 0) {
        return 0;
      }
    }
    iVar1 = param_1[0x30];
  }
  else {
    iVar1 = (**(code **)(param_1[2] + 0x3c))(param_1);
    if (iVar1 < 1) {
      return iVar1;
    }
    if (param_4 == 0) goto LAB_0048ddb8;
    iVar1 = param_1[0x30];
  }
  iVar11 = param_1[0x16];
  if (iVar1 == 0) {
LAB_0048dfe8:
    if (param_1[0x23] == 0) {
LAB_0048de18:
      iVar1 = 0;
      if (param_5 == 0) goto LAB_0048df30;
      goto LAB_0048de20;
    }
    iVar1 = 0;
    if (param_5 != 0) goto LAB_0048de20;
    iVar3 = param_1[0x16];
LAB_0048dbec:
    if (*(int *)(iVar3 + 0xe4) != 0) {
LAB_0048df30:
      uVar5 = -(*(int *)(iVar10 + 0xfc) + 5) & 7;
      puVar4 = (undefined *)(*(int *)(iVar10 + 0xfc) + uVar5);
      *(uint *)(iVar10 + 0x104) = uVar5;
      goto LAB_0048de3c;
    }
    if ((*(int *)(iVar3 + 0xe0) == 0) || (param_2 != 0x17)) {
      *(undefined4 *)(iVar3 + 0xe4) = 1;
      goto LAB_0048df30;
    }
    local_2c = do_ssl3_write(param_1,0x17,param_3,0,1);
    if (local_2c < 1) {
      return -1;
    }
    if (0x55 < local_2c) {
      uVar7 = 0x44;
      uVar2 = 0x2c2;
      goto LAB_0048dfa0;
    }
    puVar4 = (undefined *)(*(int *)(iVar10 + 0xfc) + local_2c + *(int *)(iVar10 + 0x104));
    *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
    *puVar4 = (char)param_2;
    iVar3 = *param_1;
    *(undefined4 *)(iVar11 + 0x130) = 0x17;
    puVar4[1] = (char)((uint)iVar3 >> 8);
    if (param_1[0xd] == 0x1111) goto LAB_0048de60;
LAB_0048dc80:
    iVar3 = *param_1;
    puVar9 = puVar4 + 3;
LAB_0048dc88:
    uVar6 = (undefined)iVar3;
  }
  else {
    if (param_1[0x23] == 0) goto LAB_0048de18;
    iVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
    if (iVar1 == 0) goto LAB_0048dfe8;
    uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
    iVar1 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar2);
    if (iVar1 < 0) {
      return -1;
    }
    if (param_5 == 0) {
      iVar3 = param_1[0x16];
      goto LAB_0048dbec;
    }
LAB_0048de20:
    uVar5 = -(*(int *)(iVar10 + 0xfc) + 10) & 7;
    puVar4 = (undefined *)(*(int *)(iVar10 + 0xfc) + uVar5);
    *(uint *)(iVar10 + 0x104) = uVar5;
LAB_0048de3c:
    local_2c = 0;
    *puVar4 = (char)param_2;
    iVar3 = *param_1;
    *(int *)(iVar11 + 0x130) = param_2;
    puVar4[1] = (char)((uint)iVar3 >> 8);
    if (param_1[0xd] != 0x1111) goto LAB_0048dc80;
LAB_0048de60:
    if (param_1[100] != 0) goto LAB_0048dc80;
    iVar3 = *param_1;
    puVar9 = puVar4 + 3;
    if ((iVar3 >> 8 != 3) || (iVar3 < 0x302)) goto LAB_0048dc88;
    uVar6 = 1;
  }
  puVar4[2] = uVar6;
  puVar4 = puVar9 + 2;
  if ((param_1[0x23] == 0) || (*param_1 < 0x302)) {
LAB_0048dcb0:
    local_3c = 0;
  }
  else {
    uVar5 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a9230)();
    if ((uVar5 & 0xf0007) == 2) {
      local_3c = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(param_1[0x23]);
      if (local_3c < 2) goto LAB_0048dcb0;
    }
    else {
      if ((uVar5 & 0xf0007) != 6) goto LAB_0048dcb0;
      local_3c = 8;
    }
  }
  iVar3 = param_1[0x25];
  *(int *)(iVar11 + 0x134) = param_4;
  *(undefined4 *)(iVar11 + 0x140) = param_3;
  *(undefined **)(iVar11 + 0x13c) = puVar4 + local_3c;
  if (iVar3 == 0) {
    (*(code *)PTR_memcpy_006aabf4)(puVar4 + local_3c,param_3,param_4);
    *(undefined4 *)(iVar11 + 0x140) = *(undefined4 *)(iVar11 + 0x13c);
  }
  else {
    iVar8 = param_1[0x16];
    iVar3 = (*(code *)PTR_COMP_compress_block_006a9244)
                      (iVar3,*(undefined4 *)(iVar8 + 0x13c),0x4400,*(undefined4 *)(iVar8 + 0x140),
                       *(undefined4 *)(iVar8 + 0x134));
    if (iVar3 < 0) {
      uVar7 = 0x8d;
      uVar2 = 0x318;
LAB_0048dfa0:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x68,uVar7,"s3_pkt.c",uVar2);
      return -1;
    }
    *(int *)(iVar8 + 0x134) = iVar3;
    *(undefined4 *)(iVar8 + 0x140) = *(undefined4 *)(iVar8 + 0x13c);
  }
  if (iVar1 != 0) {
    iVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                      (param_1,puVar4 + local_3c + *(int *)(iVar11 + 0x134),1);
    if (iVar3 < 0) {
      return -1;
    }
    *(int *)(iVar11 + 0x134) = *(int *)(iVar11 + 0x134) + iVar1;
  }
  *(undefined **)(iVar11 + 0x140) = puVar4;
  *(undefined **)(iVar11 + 0x13c) = puVar4;
  if (local_3c != 0) {
    *(int *)(iVar11 + 0x134) = *(int *)(iVar11 + 0x134) + local_3c;
  }
  (***(code ***)(param_1[2] + 100))(param_1,1);
  *puVar9 = (char)((uint)*(undefined4 *)(iVar11 + 0x134) >> 8);
  puVar9[1] = (char)*(undefined4 *)(iVar11 + 0x134);
  *(int *)(iVar11 + 0x130) = param_2;
  iVar1 = *(int *)(iVar11 + 0x134) + 5;
  *(int *)(iVar11 + 0x134) = iVar1;
  if (param_5 != 0) {
    return iVar1;
  }
  iVar11 = param_1[0x16];
  *(int *)(iVar10 + 0x108) = iVar1 + local_2c;
  *(int *)(iVar11 + 0x168) = param_4;
  *(undefined4 *)(iVar11 + 0x174) = param_3;
  *(int *)(iVar11 + 0x16c) = param_2;
  *(int *)(iVar11 + 0x170) = param_4;
  iVar10 = ssl3_write_pending(param_1,param_2,param_3,param_4);
  return iVar10;
}

