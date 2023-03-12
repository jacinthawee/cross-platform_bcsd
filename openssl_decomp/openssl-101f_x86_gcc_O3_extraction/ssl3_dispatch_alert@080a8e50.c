
int ssl3_dispatch_alert(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  COMP_CTX *ctx;
  EVP_MD *pEVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  ulong uVar10;
  undefined uVar11;
  uint uVar12;
  undefined *local_34;
  int local_2c;
  int local_28;
  
  iVar3 = param_1[0x16];
  *(undefined4 *)(iVar3 + 0x18c) = 0;
  iVar2 = iVar3 + 400;
  if (*(int *)(iVar3 + 0xfc) == 0) {
    iVar8 = ssl3_setup_write_buffer(param_1);
    if (iVar8 != 0) {
      if (*(int *)(iVar3 + 0x108) != 0) goto LAB_080a9110;
      iVar8 = param_1[0x16];
      if (*(int *)(iVar8 + 0x18c) != 0) {
        iVar8 = (**(code **)(param_1[2] + 0x3c))(param_1);
        if (iVar8 < 1) goto LAB_080a9128;
        iVar8 = param_1[0x16];
      }
      goto LAB_080a8e8c;
    }
LAB_080a927e:
    iVar8 = -1;
  }
  else {
    iVar8 = iVar3;
    if (*(int *)(iVar3 + 0x108) == 0) {
LAB_080a8e8c:
      if (param_1[0x30] == 0) {
LAB_080a9180:
        if (param_1[0x23] != 0) {
          local_2c = 0;
          goto LAB_080a8ee2;
        }
LAB_080a8f00:
        local_2c = 0;
      }
      else {
        if (param_1[0x23] == 0) goto LAB_080a8f00;
        pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        if (pEVar4 == (EVP_MD *)0x0) goto LAB_080a9180;
        pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
        local_2c = EVP_MD_size(pEVar4);
        if (local_2c < 0) goto LAB_080a927e;
LAB_080a8ee2:
        if (*(int *)(param_1[0x16] + 0xe4) == 0) {
          *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
        }
      }
      uVar12 = -(*(int *)(iVar3 + 0xfc) + 5) & 7;
      puVar5 = (undefined *)(*(int *)(iVar3 + 0xfc) + uVar12);
      *(uint *)(iVar3 + 0x104) = uVar12;
      *puVar5 = 0x15;
      iVar7 = *param_1;
      *(undefined4 *)(iVar8 + 0x130) = 0x15;
      puVar5[1] = (char)((uint)iVar7 >> 8);
      if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
        iVar7 = *param_1;
        if ((iVar7 >> 8 != 3) || (iVar7 < 0x302)) goto LAB_080a8f42;
        uVar11 = 1;
      }
      else {
        iVar7 = *param_1;
LAB_080a8f42:
        uVar11 = (undefined)iVar7;
      }
      local_34 = puVar5 + 3;
      puVar5[2] = uVar11;
      puVar1 = puVar5 + 5;
      if (((EVP_CIPHER_CTX *)param_1[0x23] == (EVP_CIPHER_CTX *)0x0) || (*param_1 < 0x302)) {
LAB_080a8f69:
        local_28 = 0;
      }
      else {
        uVar10 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
        if ((uVar10 & 0xf0007) == 2) {
          local_28 = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
          if (local_28 < 2) goto LAB_080a8f69;
        }
        else {
          if ((uVar10 & 0xf0007) != 6) goto LAB_080a8f69;
          local_28 = 8;
        }
      }
      ctx = (COMP_CTX *)param_1[0x25];
      *(undefined4 *)(iVar8 + 0x134) = 2;
      *(int *)(iVar8 + 0x140) = iVar2;
      *(undefined **)(iVar8 + 0x13c) = puVar1 + local_28;
      if (ctx == (COMP_CTX *)0x0) {
        *(undefined2 *)(puVar1 + local_28) = *(undefined2 *)(iVar3 + 400);
        *(undefined4 *)(iVar8 + 0x140) = *(undefined4 *)(iVar8 + 0x13c);
      }
      else {
        iVar7 = param_1[0x16];
        iVar6 = COMP_compress_block(ctx,*(uchar **)(iVar7 + 0x13c),0x4400,*(uchar **)(iVar7 + 0x140)
                                    ,*(int *)(iVar7 + 0x134));
        if (iVar6 < 0) {
          ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x318);
          goto LAB_080a927e;
        }
        *(int *)(iVar7 + 0x134) = iVar6;
        *(undefined4 *)(iVar7 + 0x140) = *(undefined4 *)(iVar7 + 0x13c);
      }
      if (local_2c != 0) {
        iVar7 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                          (param_1,puVar1 + local_28 + *(int *)(iVar8 + 0x134),1);
        if (iVar7 < 0) goto LAB_080a927e;
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + local_2c;
      }
      *(undefined **)(iVar8 + 0x140) = puVar1;
      *(undefined **)(iVar8 + 0x13c) = puVar1;
      if (local_28 != 0) {
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + local_28;
      }
      (***(code ***)(param_1[2] + 100))(param_1,1);
      *local_34 = (char)((uint)*(undefined4 *)(iVar8 + 0x134) >> 8);
      puVar5[4] = (char)*(undefined4 *)(iVar8 + 0x134);
      *(undefined4 *)(iVar8 + 0x130) = 0x15;
      iVar7 = *(int *)(iVar8 + 0x134) + 5;
      *(int *)(iVar8 + 0x134) = iVar7;
      *(int *)(iVar3 + 0x108) = iVar7;
      iVar3 = param_1[0x16];
      *(undefined4 *)(iVar3 + 0x168) = 2;
      *(int *)(iVar3 + 0x174) = iVar2;
      *(undefined4 *)(iVar3 + 0x16c) = 0x15;
      *(undefined4 *)(iVar3 + 0x170) = 2;
      iVar8 = ssl3_write_pending(param_1,0x15,iVar2,2);
    }
    else {
LAB_080a9110:
      iVar8 = ssl3_write_pending(param_1,0x15,iVar2,2);
    }
    if (0 < iVar8) {
      if (*(char *)(param_1[0x16] + 400) == '\x02') {
        BIO_ctrl((BIO *)param_1[4],0xb,0,(void *)0x0);
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
      }
      pcVar9 = (code *)param_1[0x34];
      if ((pcVar9 != (code *)0x0) ||
         (pcVar9 = *(code **)(param_1[0x39] + 0x9c), pcVar9 != (code *)0x0)) {
        (*pcVar9)(param_1,0x4008,
                  *(ushort *)(param_1[0x16] + 400) << 8 | *(ushort *)(param_1[0x16] + 400) >> 8);
      }
      return iVar8;
    }
  }
LAB_080a9128:
  *(undefined4 *)(param_1[0x16] + 0x18c) = 1;
  return iVar8;
}

