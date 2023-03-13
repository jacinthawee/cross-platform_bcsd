
int __regparm3
do_ssl3_write(int *param_1_00,int param_2_00,void *param_3,size_t param_1,uint param_2)

{
  undefined *puVar1;
  undefined uVar2;
  EVP_MD *pEVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined *puVar8;
  int iVar9;
  undefined *local_34;
  int local_30;
  int local_2c;
  int local_20;
  
  iVar6 = param_1_00[0x16];
  if (*(int *)(iVar6 + 0x108) != 0) {
    iVar6 = ssl3_write_pending(param_1_00,param_2_00,param_3,param_1);
    return iVar6;
  }
  if ((*(int *)(iVar6 + 0x18c) != 0) &&
     (iVar9 = (**(code **)(param_1_00[2] + 0x3c))(param_1_00), iVar9 < 1)) {
    return iVar9;
  }
  if ((*(int *)(iVar6 + 0xfc) == 0) && (iVar9 = ssl3_setup_write_buffer(param_1_00), iVar9 == 0)) {
    return -1;
  }
  if ((param_1 == 0) && (param_2 == 0)) {
    return 0;
  }
  iVar9 = param_1_00[0x16];
  iVar5 = param_1_00[0x23];
  if ((param_1_00[0x30] == 0) || (iVar5 == 0)) {
LAB_080a3a46:
    local_30 = 0;
    if ((iVar5 == 0 | param_2) != 0) goto LAB_080a38b9;
LAB_080a3a60:
    iVar5 = param_1_00[0x16];
    if (*(int *)(iVar5 + 0xe4) != 0) goto LAB_080a3a8b;
    if ((*(int *)(iVar5 + 0xe0) == 0) || (param_2_00 != 0x17)) {
      *(undefined4 *)(iVar5 + 0xe4) = 1;
      goto LAB_080a3a8b;
    }
    local_20 = do_ssl3_write(0,1);
    if (local_20 < 1) {
      return -1;
    }
    if (local_20 < 0x56) {
      *(undefined4 *)(param_1_00[0x16] + 0xe4) = 1;
      puVar8 = (undefined *)(*(int *)(iVar6 + 0x104) + local_20 + *(int *)(iVar6 + 0xfc));
      goto LAB_080a38e3;
    }
    iVar9 = 0x2fa;
    iVar6 = 0x44;
LAB_080a3c12:
    ERR_put_error(0x14,0x68,iVar6,"s3_pkt.c",iVar9);
  }
  else {
    pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1_00[0x24]);
    if (pEVar3 == (EVP_MD *)0x0) {
      iVar5 = param_1_00[0x23];
      goto LAB_080a3a46;
    }
    pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1_00[0x24]);
    local_30 = EVP_MD_size(pEVar3);
    if (local_30 < 0) {
      return -1;
    }
    if (param_2 == 0) goto LAB_080a3a60;
LAB_080a38b9:
    if (param_2 == 0) {
LAB_080a3a8b:
      iVar4 = *(int *)(iVar6 + 0xfc);
      iVar5 = iVar4 + 5;
    }
    else {
      iVar4 = *(int *)(iVar6 + 0xfc);
      iVar5 = iVar4 + 10;
    }
    local_20 = 0;
    puVar8 = (undefined *)(iVar4 + (-iVar5 & 7U));
    *(uint *)(iVar6 + 0x104) = -iVar5 & 7U;
LAB_080a38e3:
    *puVar8 = (char)param_2_00;
    iVar5 = *param_1_00;
    *(int *)(iVar9 + 0x130) = param_2_00;
    puVar8[1] = (char)((uint)iVar5 >> 8);
    if ((param_1_00[0xd] == 0x1111) && (param_1_00[100] == 0)) {
      iVar5 = *param_1_00;
      if ((iVar5 >> 8 != 3) || (iVar5 < 0x302)) goto LAB_080a3905;
      uVar2 = 1;
    }
    else {
      iVar5 = *param_1_00;
LAB_080a3905:
      uVar2 = (undefined)iVar5;
    }
    local_34 = puVar8 + 3;
    puVar8[2] = uVar2;
    puVar1 = puVar8 + 5;
    if (((EVP_CIPHER_CTX *)param_1_00[0x23] == (EVP_CIPHER_CTX *)0x0) || (*param_1_00 < 0x302)) {
LAB_080a392c:
      local_2c = 0;
    }
    else {
      uVar7 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1_00[0x23]);
      if ((uVar7 & 0xf0007) == 2) {
        local_2c = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1_00[0x23]);
        if (local_2c < 2) goto LAB_080a392c;
      }
      else {
        if ((uVar7 & 0xf0007) != 6) goto LAB_080a392c;
        local_2c = 8;
      }
    }
    *(undefined **)(iVar9 + 0x13c) = puVar1 + local_2c;
    *(size_t *)(iVar9 + 0x134) = param_1;
    *(void **)(iVar9 + 0x140) = param_3;
    if ((COMP_CTX *)param_1_00[0x25] == (COMP_CTX *)0x0) {
      memcpy(puVar1 + local_2c,param_3,param_1);
      *(undefined4 *)(iVar9 + 0x140) = *(undefined4 *)(iVar9 + 0x13c);
    }
    else {
      iVar5 = param_1_00[0x16];
      iVar4 = COMP_compress_block((COMP_CTX *)param_1_00[0x25],*(uchar **)(iVar5 + 0x13c),0x4400,
                                  *(uchar **)(iVar5 + 0x140),*(int *)(iVar5 + 0x134));
      if (iVar4 < 0) {
        iVar9 = 0x348;
        iVar6 = 0x8d;
        goto LAB_080a3c12;
      }
      *(int *)(iVar5 + 0x134) = iVar4;
      *(undefined4 *)(iVar5 + 0x140) = *(undefined4 *)(iVar5 + 0x13c);
    }
    if (local_30 != 0) {
      iVar5 = (**(code **)(*(int *)(param_1_00[2] + 100) + 4))
                        (param_1_00,puVar1 + local_2c + *(int *)(iVar9 + 0x134),1);
      if (iVar5 < 0) {
        return -1;
      }
      *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_30;
    }
    *(undefined **)(iVar9 + 0x140) = puVar1;
    *(undefined **)(iVar9 + 0x13c) = puVar1;
    if (local_2c != 0) {
      *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_2c;
    }
    iVar5 = (***(code ***)(param_1_00[2] + 100))(param_1_00,1);
    if (0 < iVar5) {
      *local_34 = (char)((uint)*(undefined4 *)(iVar9 + 0x134) >> 8);
      puVar8[4] = (char)*(undefined4 *)(iVar9 + 0x134);
      *(int *)(iVar9 + 0x130) = param_2_00;
      iVar5 = *(int *)(iVar9 + 0x134) + 5;
      *(int *)(iVar9 + 0x134) = iVar5;
      if (param_2 == 0) {
        *(int *)(iVar6 + 0x108) = iVar5 + local_20;
        iVar6 = param_1_00[0x16];
        *(size_t *)(iVar6 + 0x168) = param_1;
        *(int *)(iVar6 + 0x16c) = param_2_00;
        *(size_t *)(iVar6 + 0x170) = param_1;
        *(void **)(iVar6 + 0x174) = param_3;
        iVar6 = ssl3_write_pending(param_1_00,param_2_00,param_3,param_1);
        return iVar6;
      }
      return iVar5;
    }
  }
  return -1;
}

