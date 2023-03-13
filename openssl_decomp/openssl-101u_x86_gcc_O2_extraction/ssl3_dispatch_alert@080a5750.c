
int ssl3_dispatch_alert(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  COMP_CTX *ctx;
  EVP_MD *pEVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  int iVar9;
  undefined uVar10;
  uint uVar11;
  code *pcVar12;
  undefined *local_34;
  int local_2c;
  int local_28;
  
  iVar2 = param_1[0x16];
  *(undefined4 *)(iVar2 + 0x18c) = 0;
  iVar7 = iVar2 + 400;
  if (*(int *)(iVar2 + 0x108) == 0) {
    iVar9 = iVar2;
    if (*(int *)(iVar2 + 0xfc) == 0) {
      iVar9 = ssl3_setup_write_buffer(param_1);
      if (iVar9 != 0) {
        iVar9 = param_1[0x16];
        goto LAB_080a578c;
      }
    }
    else {
LAB_080a578c:
      if (param_1[0x30] == 0) {
LAB_080a5a60:
        if (param_1[0x23] != 0) {
          local_2c = 0;
          goto LAB_080a57e2;
        }
LAB_080a5800:
        local_2c = 0;
      }
      else {
        if (param_1[0x23] == 0) goto LAB_080a5800;
        pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        if (pEVar3 == (EVP_MD *)0x0) goto LAB_080a5a60;
        pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        local_2c = EVP_MD_size(pEVar3);
        if (local_2c < 0) goto LAB_080a5a9e;
LAB_080a57e2:
        if (*(int *)(param_1[0x16] + 0xe4) == 0) {
          *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
        }
      }
      uVar11 = -(*(int *)(iVar2 + 0xfc) + 5) & 7;
      puVar4 = (undefined *)(*(int *)(iVar2 + 0xfc) + uVar11);
      *(uint *)(iVar2 + 0x104) = uVar11;
      *puVar4 = 0x15;
      iVar6 = *param_1;
      *(undefined4 *)(iVar9 + 0x130) = 0x15;
      puVar4[1] = (char)((uint)iVar6 >> 8);
      if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
        iVar6 = *param_1;
        if ((iVar6 >> 8 != 3) || (iVar6 < 0x302)) goto LAB_080a5842;
        uVar10 = 1;
      }
      else {
        iVar6 = *param_1;
LAB_080a5842:
        uVar10 = (undefined)iVar6;
      }
      local_34 = puVar4 + 3;
      puVar4[2] = uVar10;
      puVar1 = puVar4 + 5;
      if (((EVP_CIPHER_CTX *)param_1[0x23] == (EVP_CIPHER_CTX *)0x0) || (*param_1 < 0x302)) {
LAB_080a5869:
        local_28 = 0;
      }
      else {
        uVar8 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
        if ((uVar8 & 0xf0007) == 2) {
          local_28 = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
          if (local_28 < 2) goto LAB_080a5869;
        }
        else {
          if ((uVar8 & 0xf0007) != 6) goto LAB_080a5869;
          local_28 = 8;
        }
      }
      ctx = (COMP_CTX *)param_1[0x25];
      *(undefined4 *)(iVar9 + 0x134) = 2;
      *(int *)(iVar9 + 0x140) = iVar7;
      *(undefined **)(iVar9 + 0x13c) = puVar1 + local_28;
      if (ctx == (COMP_CTX *)0x0) {
        *(undefined2 *)(puVar1 + local_28) = *(undefined2 *)(iVar2 + 400);
        *(undefined4 *)(iVar9 + 0x140) = *(undefined4 *)(iVar9 + 0x13c);
      }
      else {
        iVar6 = param_1[0x16];
        iVar5 = COMP_compress_block(ctx,*(uchar **)(iVar6 + 0x13c),0x4400,*(uchar **)(iVar6 + 0x140)
                                    ,*(int *)(iVar6 + 0x134));
        if (iVar5 < 0) {
          ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x348);
          goto LAB_080a5a9e;
        }
        *(int *)(iVar6 + 0x134) = iVar5;
        *(undefined4 *)(iVar6 + 0x140) = *(undefined4 *)(iVar6 + 0x13c);
      }
      if (local_2c != 0) {
        iVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                          (param_1,puVar1 + local_28 + *(int *)(iVar9 + 0x134),1);
        if (iVar6 < 0) goto LAB_080a5a9e;
        *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_2c;
      }
      *(undefined **)(iVar9 + 0x140) = puVar1;
      *(undefined **)(iVar9 + 0x13c) = puVar1;
      if (local_28 != 0) {
        *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_28;
      }
      iVar6 = (***(code ***)(param_1[2] + 100))(param_1,1);
      if (0 < iVar6) {
        *local_34 = (char)((uint)*(undefined4 *)(iVar9 + 0x134) >> 8);
        puVar4[4] = (char)*(undefined4 *)(iVar9 + 0x134);
        *(undefined4 *)(iVar9 + 0x130) = 0x15;
        iVar6 = *(int *)(iVar9 + 0x134) + 5;
        *(int *)(iVar9 + 0x134) = iVar6;
        *(int *)(iVar2 + 0x108) = iVar6;
        iVar2 = param_1[0x16];
        *(undefined4 *)(iVar2 + 0x168) = 2;
        *(int *)(iVar2 + 0x174) = iVar7;
        *(undefined4 *)(iVar2 + 0x16c) = 0x15;
        *(undefined4 *)(iVar2 + 0x170) = 2;
        goto LAB_080a5995;
      }
    }
LAB_080a5a9e:
    iVar7 = -1;
  }
  else {
LAB_080a5995:
    iVar7 = ssl3_write_pending(param_1,0x15,iVar7,2);
    if (0 < iVar7) {
      if (*(char *)(param_1[0x16] + 400) == '\x02') {
        BIO_ctrl((BIO *)param_1[4],0xb,0,(void *)0x0);
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
      }
      pcVar12 = (code *)param_1[0x34];
      if ((pcVar12 != (code *)0x0) ||
         (pcVar12 = *(code **)(param_1[0x39] + 0x9c), pcVar12 != (code *)0x0)) {
        (*pcVar12)(param_1,0x4008,
                   *(ushort *)(param_1[0x16] + 400) << 8 | *(ushort *)(param_1[0x16] + 400) >> 8);
      }
      return iVar7;
    }
  }
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
  return iVar7;
}

