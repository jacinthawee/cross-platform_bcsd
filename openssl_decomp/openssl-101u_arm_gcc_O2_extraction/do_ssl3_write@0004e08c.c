
int do_ssl3_write(int *param_1,int param_2,void *param_3,size_t param_4,uint param_5)

{
  EVP_MD *pEVar1;
  COMP_CTX *ctx;
  ulong uVar2;
  undefined uVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined *unaff_r11;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar8 = param_1[0x16];
  if (*(int *)(iVar8 + 0x108) != 0) goto LAB_0004e24c;
  if ((*(int *)(iVar8 + 0x18c) != 0) && (iVar4 = (**(code **)(param_1[2] + 0x3c))(), iVar4 < 1)) {
    return iVar4;
  }
  if ((*(int *)(iVar8 + 0xfc) == 0) && (iVar4 = ssl3_setup_write_buffer(param_1), iVar4 == 0)) {
    return -1;
  }
  if (param_4 == 0 && param_5 == 0) {
    return 0;
  }
  iVar7 = param_1[0x16];
  iVar4 = param_1[0x23];
  if ((param_1[0x30] == 0) || (iVar4 == 0)) {
LAB_0004e25a:
    uVar5 = count_leading_zeroes(iVar4);
    local_34 = 0;
    if ((param_5 | uVar5 >> 5) != 0) goto LAB_0004e118;
LAB_0004e26c:
    iVar4 = param_1[0x16];
    if (*(int *)(iVar4 + 0xe4) != 0) goto LAB_0004e2b2;
    local_2c = *(int *)(iVar4 + 0xe0);
    if ((*(int *)(iVar4 + 0xe0) != 0) && (local_2c = *(int *)(iVar4 + 0xe4), param_2 == 0x17)) {
      local_2c = do_ssl3_write(param_1,0x17,param_3,0,1);
      if (local_2c < 1) {
        return -1;
      }
      if (0x55 < local_2c) {
        ERR_put_error(0x14,0x68,0x44,"s3_pkt.c",0x2fa);
        return -1;
      }
      iVar4 = param_1[0x16];
    }
    *(undefined4 *)(iVar4 + 0xe4) = 1;
    if (local_2c == 0) goto LAB_0004e2b2;
    puVar6 = (undefined *)(local_2c + *(int *)(iVar8 + 0x104) + *(int *)(iVar8 + 0xfc));
  }
  else {
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    if (pEVar1 == (EVP_MD *)0x0) {
      iVar4 = param_1[0x23];
      goto LAB_0004e25a;
    }
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    local_34 = EVP_MD_size(pEVar1);
    if (local_34 < 0) {
      return -1;
    }
    if (param_5 == 0) goto LAB_0004e26c;
LAB_0004e118:
    if (param_5 == 0) {
LAB_0004e2b2:
      local_2c = 0;
      uVar5 = 3U - *(int *)(iVar8 + 0xfc) & 7;
      *(uint *)(iVar8 + 0x104) = uVar5;
      puVar6 = (undefined *)(uVar5 + *(int *)(iVar8 + 0xfc));
    }
    else {
      local_2c = 0;
      uVar5 = 6U - *(int *)(iVar8 + 0xfc) & 7;
      *(uint *)(iVar8 + 0x104) = uVar5;
      puVar6 = (undefined *)(uVar5 + *(int *)(iVar8 + 0xfc));
    }
  }
  *puVar6 = (char)param_2;
  iVar4 = *param_1;
  *(int *)(iVar7 + 0x130) = param_2;
  puVar6[1] = (char)((uint)iVar4 >> 8);
  if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
    iVar9 = *param_1;
    iVar4 = iVar9;
    if (iVar9 >> 8 != 3) goto LAB_0004e152;
    if (0x301 < iVar9) {
      unaff_r11 = puVar6 + 3;
      iVar4 = 1;
    }
    uVar3 = (undefined)iVar4;
    if (iVar9 < 0x302) goto LAB_0004e152;
  }
  else {
    iVar4 = *param_1;
LAB_0004e152:
    uVar3 = (undefined)iVar4;
    unaff_r11 = puVar6 + 3;
  }
  puVar6[2] = uVar3;
  puVar6 = unaff_r11 + 2;
  if (((EVP_CIPHER_CTX *)param_1[0x23] == (EVP_CIPHER_CTX *)0x0) || (*param_1 < 0x302)) {
LAB_0004e172:
    local_30 = 0;
  }
  else {
    uVar2 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
    if ((uVar2 & 0xf0007) == 2) {
      local_30 = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
      if (local_30 < 2) goto LAB_0004e172;
    }
    else {
      if ((uVar2 & 0xf0007) != 6) goto LAB_0004e172;
      local_30 = 8;
    }
  }
  ctx = (COMP_CTX *)param_1[0x25];
  *(size_t *)(iVar7 + 0x134) = param_4;
  *(void **)(iVar7 + 0x140) = param_3;
  *(undefined **)(iVar7 + 0x13c) = puVar6 + local_30;
  if (ctx == (COMP_CTX *)0x0) {
    memcpy(puVar6 + local_30,param_3,param_4);
    *(undefined4 *)(iVar7 + 0x140) = *(undefined4 *)(iVar7 + 0x13c);
  }
  else {
    iVar9 = param_1[0x16];
    iVar4 = COMP_compress_block(ctx,*(uchar **)(iVar9 + 0x13c),0x4400,*(uchar **)(iVar9 + 0x140),
                                *(int *)(iVar9 + 0x134));
    if (iVar4 < 0) {
      ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x348);
      return -1;
    }
    *(int *)(iVar9 + 0x134) = iVar4;
    *(undefined4 *)(iVar9 + 0x140) = *(undefined4 *)(iVar9 + 0x13c);
  }
  if (local_34 != 0) {
    iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                      (param_1,puVar6 + local_30 + *(int *)(iVar7 + 0x134),1);
    if (iVar4 < 0) {
      return -1;
    }
    *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + local_34;
  }
  *(undefined **)(iVar7 + 0x140) = puVar6;
  *(undefined **)(iVar7 + 0x13c) = puVar6;
  if (local_30 != 0) {
    *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + local_30;
  }
  iVar4 = (***(code ***)(param_1[2] + 100))(param_1,1);
  if (iVar4 < 1) {
    return -1;
  }
  *unaff_r11 = (char)((uint)*(undefined4 *)(iVar7 + 0x134) >> 8);
  unaff_r11[1] = (char)*(undefined4 *)(iVar7 + 0x134);
  *(int *)(iVar7 + 0x130) = param_2;
  iVar4 = *(int *)(iVar7 + 0x134) + 5;
  *(int *)(iVar7 + 0x134) = iVar4;
  if (param_5 != 0) {
    return iVar4;
  }
  iVar7 = param_1[0x16];
  *(int *)(iVar8 + 0x108) = iVar4 + local_2c;
  *(size_t *)(iVar7 + 0x168) = param_4;
  *(void **)(iVar7 + 0x174) = param_3;
  *(int *)(iVar7 + 0x16c) = param_2;
  *(size_t *)(iVar7 + 0x170) = param_4;
LAB_0004e24c:
  iVar8 = ssl3_write_pending(param_1,param_2,param_3,param_4);
  return iVar8;
}

